JDK的存储管理：翻译自[这里](http://openjdk.java.net/groups/hotspot/docs/StorageManagement.html)

### storage manager(存储管理)

在众多java虚拟机必须提供的功能中，有个就是storage manager(存储管理)。这个storage manager的职责是负责java对象的生命周期：**新对象的创建，不可达对象的回收，对象不可达的通知（如果需要的话）**。 A virtual machine can distinguish itself in the qualities of service the storage manager provides(这句话不懂什么意思，暂不翻译). HotSpot虚拟机提供了几种storage manager以适应不同应用的需求。两种主要的storage manager分别是使得应用短暂暂停的storage manager，另一个是提供了high throughput(高吞吐量)的storage manager。

### The Klass Hierarchy(类的层级结构)

HotSpot虚拟机中心数据结构是“**Klass hierarchy(类的层级结构)**”：这个数据结构描绘出位于虚拟机storage manager里面的对象，并且提供了这些对象的所有操作。(我们使用"klass"是因为"class"是c++的一个关键字，所以我们不能使用它)。这个Klass Hierarchy是可以自我引用的，因此这也包含了对象的descriptions 的descriptions ，以此类推（这句话不懂什么意思）。java对象不是c++对象，所以我们不能在它们上面调用方法（这里的调用方法是什么意思？java对象可以调用方法的啊；还是说不能像c++一样直接delete内存，释放内存，将对象的地址直接用delete释放掉？）但是我们喜欢面向对象编程，所以Klass Hierarchy为对象上的方法(和虚拟机方法)提供了一种机制。

也许一个简单的例子足够解释清楚了。现有一个java对象的实例。这个实例的由java程序员所定义的字段组成，除了这些，我们还加了header，这个header是很重要的，因为header是一个指向**representation of the Java class that defined this instance（定义这个实例的java class）**的指针。**The representation of the Java class**本身也是一个对象（但不是一个java对象，而是一个“instanceKlass”），它包含了一些重要的东西比如这个类的静态变量。另外，它还包含了**a description of the types of the fields of every instance of this Java class（这个java类的所有实例的字段的类型的description ）**,所以storage manager 能够找到并调整这些引用的字段，例如它移动了内存中对象的位置。因为 **the representation of the Java class**包含了其他对象的引用，它本身必须有一个header，header里面的指针指向something (another object, also not a Java object; an “instanceKlassKlass”) that describes its fields.This chain of classes would continue indefinitely if not for the fact that instanceKlassKlass's are described by klassKlass, which can describe itself. Perhaps a simple example won't suffice. There are subclasses of klass for each of the types of object managed by the storage manager.

不太懂，查了以下这些资料也不太懂：

<http://domain.yqjdcyy.com/post/java.jvm.%E5%AF%B9%E8%B1%A1%E6%A8%A1%E5%9E%8B/>

<http://yizhanggou.top/untitled-2/>

### Allocation（分配内存）

大多数java应用频繁的创建对象，并且又频繁的遗弃它们。所以一个高性能的java虚拟机应该要能够支持对象的快速创建，并且做好大多数对象很快就变得不可达的准备。如果你有查看源码的话你会看到分配内存和初始化对象的的代码。但是有些代码是以“slow-path”方式创建对象的，也就是说一个运行的程序调用正在运行的虚拟机去创建一个对象。大多数对象却是以“fast-path”方式创建的，也即是说被编译进应用，所以不会有虚拟机的调用产生。事实上，“fast-path”只不过是指针碰撞然后检查是否使用完已分配的内存空间而已。为了防止指针成为可伸缩性的瓶颈，每一个线程都有它自己的内存分配区域，并且这是自己的指针。这就是我们所说的“thread local allocatoin buffers”（TLABS）。每一个线程都能够通过它自己的TLAB分配内存而不需要与其他线程合作，除非线程需要创建一个新的TLAB。针对于TLABs的大小有很多工作需要做，要根据应用线程性能调整大小，掌握好所需要TLABs的数量，由于线程不活动之后，线程的TLABs会造成内存的碎片化，等等。

关于“fast path”和“slow path”的含义，参考[这里](http://mail.openjdk.java.net/pipermail/hotspot-dev/2009-February/001335.html)，下面是答案的截取

```
Fast path is basically lock free allocation.
This is mostly related to TLAB allocation where the allocating thread 
(is allocating in large contiguous free memory) need not worry about 
synchronisation. It can just allocate by incrementing the pointer.
Slow path is mainly synchronised allocation.
This mostly happens in the old generation, for eg in cases like a large 
object being allocated directly in the Old gen due to lack of space in 
the young gen.
```

### Collection（内存收集）

对象变为不可饮用之后，它们所占用的空间可以被其他对象使用。最基本的垃圾收集器的操作时遍历整个对象图，找到所有可达对象并且保存它们，当检测出所有不可达对象时就需要回收他们的存储空间。但是对于每一个垃圾收集器来说遍历整个对象图将会耗费昂贵的成本，所以一系列技术会被使用到垃圾收集器上使得垃圾收集器变得更加有效。

### Generations（分代）

我们观察到大多数java程序遵循 **“weak generational hypothesis（weak generational假说）”**:对象会被频繁的创建，但是其中的大多数对象不会被引用太长时间，并且老对象和年轻的对象之间很少有相互引用。为了利用这些特点，我们将java对象分代所以我们能够利用不同的算法去管理新创建的对象和已经被引用了一段时间的对象。在young generation，我们预测会有大量的对象被创建，但同时也会有大量的不可达对象。在old generation，我们预测不会有大量的对象创建（事实上能够在old generation创建对象的场景只有两种：第一种是young generation的对象通过storage manager从而promotion到old generation；另一种场景就是有时候会因为某些特殊的原因将对象直接分配在old generation，比如大对象在young generation分配不下只能分配在old generation）。但是一旦对象创建在old generation，我们预测它们会保持被引用的状态一阵子，所以我们使用不同的算法去管理它们。

### The Young Generation（年轻代）

年轻代必须支持快速分配对象，但是我们预测其中大多数对象很快就会变得不可达。我们不想在不可达对象上花费任何精力，因为它们的数量太多了。所以但我们的young generation需要被清理时，我们会标记出其中可达的对象并且将它们拷贝出young generation。一旦我们将可达对象拷贝出来，young generation剩下的对象都是不可达对象，而且这些不可达对象所占用的空间都能够被回收。这种将可达对象拷贝出来的技术我呢称之为**“scavenging”**，所以我们经常将我们的young generation 垃圾收集器称为**“scavengers”**。scavenging的优势之一就是快速。而缺点之一就是在拷贝对象的时候需要额外的空间。

### Some Ancillary Data Structures（一些辅助数据结构）

但是我们如何在不遍历整个对象图的情况下辨别出young generation中的可达对象呢？因为遍历整个对象图的开销会很昂贵。为了做到这一点，我们利用**“weak generational hypothesis（weak generational假说）”**的第二点：“老对象和年轻的对象之间很少有相互引用”。我们会保存一个所谓的**“remembered set”**，这个“remembered set”会记录old generation到young generation的引用。（回想一下，对象只有在storage manager的控制下才能进入old generation。我估计将young generation的对象迁移到old generation之后就回去填写这个“remembered set”了）。现在的HotSpot虚拟机使用一个叫做“card marking”的“remembered set”，在垃圾收集的时候会做一些额外的工作去限制这个“remembered set”的大小。That extra work comes from the fact that the remember set is imprecise, so we need to be able to walk backwards through the old generation looking for the start of objects. To facilitate that we have a “block start” table (also bounded in size) which you will see if you look in the code. In addition, the different collectors have some collector-specific ancillary data structures that will be explained in more detail later.

### The Old Generation（年老代）

一旦对象从young generation被scavenged出来，我们预测它们能够保持可达状态至少一阵子，并且会引用其他其他可达对象和被其他可达对象引用。对old generation进行垃圾回收的算法我们不能依赖于大量不可达对象。特别是我们不能指望有足够的空间去scavenge对象。old generation里面的对象拷贝是非常昂贵的，不仅需要移动很多对象，还因为需要更新所有对象的引用。另一方面，复制对象意味着可以将恢复的空间累积到一个大区域中，从这个区域分配更快(这加快了对年轻代的清除)，并允许我们将多余的存储返回到操作系统，这是礼貌的做法。

### The Permanent Generation（永久代）

除了java应用创建的对象，还有HotSpot虚拟机创建并使用的对象。针对于HotSpot创建的对象，这些对象的存储也可以由storage manager便利的去分配并回收。为了避免令人疑惑，这些对象被创建在独立的generation，这就是所谓的“permanent generation”。事实上，这些对象并非永久，但是会这么成为是有历史原因的。例如，关于已加载的类的信息会被存放在permanent generation，并且当这些类不再被应用所需要的时候就会被回收。