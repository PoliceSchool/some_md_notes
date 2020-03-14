## 1.7 以及 1.8的ConcurrentHashMap介绍

### 1.7 的ConcurrentHashMap

* 1.7实际上是两种数据结构来实现分段锁,分别是Segment和HashEntry
* 在ConcurrentHashMap中有一个Segment数组
* 其中Segment嵌套一个HashEntry数组,又因为Segment又继承**ReentrantLock**以得到锁的能力,从而使得ConcurrentHashMap获得了分段锁的能力;即一个Segment管理一组HashEntry,要想访问这一组HashEntry,必须通过Segment这一关,如果Segment没有被锁住那就可以继续访问这个Segment底下的HashEntry数组,如果被锁住的就需要等待.
* put的整体流程是,先通过key算出hash值,通过hash值算出这个key位于Segment数组中的那个位置,如果这个位置上的值为null,那么**UNSAFE**类将使用**compareAndSwapObject**创建一个新的Segment对象放于此位置上;到这里为止所有线程都可以并发执行.一旦得到了Segment数组中的Segment对象,往这个Segment对象put数据的时候会调用**tryLock()**锁住,然后接着使用key值算出这个key应该位于HashEntry数组中的那个位置,使用头插法插入,跟1.7的hashmap一样.
* 总结:  使用**Segment** + **HashEntry** + **Unsafe** + **CAS** + **ReentrantLock**获得分段锁的能力
* 值得注意的是:1.7中还是使用的数组+链表的形式存储数据,1.8中才加入了红黑树的数据结构

### 1.8的ConcurrentHashMap

* 1.8的ConcurrentHashMap去掉了Segment数据结构,只使用了Node数据结构
* 其实现分段锁的原理在于"对Node数组的中的每一个元素加锁",因为对Node数组中的每一个元素加锁,从而使得锁的细粒度更小了.
* Node数组中的每一个元素要么是链表要么是红黑树,都需要通过头结点遍历,所以在1.8中索性对头结点加锁,不过不像1.7那样用ReentrantLock,而是使用synchronized对Node数组中的每个元素加锁.然后才进行下一步的操作
* 如果获取到Node数组中的某个元素为空,也跟1.7一样,使用**UNSAFE**类用**compareAndSwapObject**区添加一个新元素
* 总结:  使用**synchronized** + **CAS** + **Unsafe** + **Node**获得分段锁的能力
* ConcurrentHashMap使用数组+链表+红黑树的数据结构存储数据

### 1.7和1.8的ConcurrentHashMap不一样的地方

* 

参考资料:https://www.bilibili.com/video/av50426066?from=search&seid=1302605682258638476