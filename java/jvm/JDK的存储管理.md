JDK的存储管理：翻译自[这里](http://openjdk.java.net/groups/hotspot/docs/StorageManagement.html)

### storage manager(存储管理)

在众多java虚拟机必须提供的功能中，有个就是storage manager(存储管理)。这个storage manager的职责是负责java对象的生命周期：**新对象的创建，不可达对象的回收，对象不可达的通知（如果需要的话）**。 A virtual machine can distinguish itself in the qualities of service the storage manager provides(这句话不懂什么意思，暂不翻译). HotSpot虚拟机提供了几种storage manager以适应不同应用的需求。两种主要的storage manager分别是使得应用短暂暂停的storage manager，另一个是提供了high throughput(高吞吐量)的storage manager。

### The Klass Hierarchy(类的层级结构)

HotSpot虚拟机中心数据结构是“**Klass hierarchy(类的层级结构)**”：这个数据结构描绘出位于虚拟机storage manager里面的对象，并且提供了这些对象的所有操作。(我们使用"klass"是因为"class"是c++的一个关键字，所以我们不能使用它)。这个Klass Hierarchy是可以自我引用的，因此这也包含了对象的descriptions 的descriptions ，以此类推（这句话不懂什么意思）。java对象不是c++对象，所以我们不能在它们上面调用方法（这里的调用方法是什么意思？java对象可以调用方法的啊；还是说不能像c++一样直接delete内存，释放内存，将对象的地址直接用delete释放掉？）但是我们喜欢面向对象编程，所以Klass Hierarchy为对象上的方法(和虚拟机方法)提供了一种机制。

也许一个简单的例子足够解释清楚了。现有一个java对象的实例。这个实例的由java程序员所定义的字段组成，除了这些，我们还加了header，这个header是很重要的，因为header是一个指向**representation of the Java class that defined this instance（定义这个实例的java class）**的指针。**The representation of the Java class**本身也是一个对象（但不是一个java对象，而是一个“instanceKlass”），它包含了一些重要的东西比如这个类的静态变量。另外，它还包含了**a description of the types of the fields of every instance of this Java class（这个java类的所有实例的字段的类型的description ）**,所以storage manager 能够找到并调整这些引用的字段，例如它移动了内存中对象的位置。因为 **the representation of the Java class**包含了其他对象的引用，它本身必须有一个header，header里面的指针指向something (another object, also not a Java object; an “instanceKlassKlass”) that describes its fields.This chain of classes would continue indefinitely if not for the fact that instanceKlassKlass's are described by klassKlass, which can describe itself. Perhaps a simple example won't suffice. There are subclasses of klass for each of the types of object managed by the storage manager.

不太懂，查了一下这些资料也不太懂：

<http://domain.yqjdcyy.com/post/java.jvm.%E5%AF%B9%E8%B1%A1%E6%A8%A1%E5%9E%8B/>

<http://yizhanggou.top/untitled-2/>

### Allocation（分配内存）

