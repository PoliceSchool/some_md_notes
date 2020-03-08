## 初级面试题:

1. JDK8的HashMap有哪些改动?

   HashMap的数据结构从数组+链表升级为数组+链表+红黑树
   JDK7使用头插法将数据插入数组中,而JDK8是放在链表的尾部或者树的里面
   JDK8解决了JDK7中的"死锁"问题,也即是多线程插入数据,因为是"头插法"引起数组扩容时会导致链表的死循环

2. JDK8中为什么要使用红黑树?
   为了插入和查询的效率,如果只使用链表的话当链表过长查询效率会变慢,使用树的话查询效率快一点.

3. 为什么重写对象的equals方法时,要重写hashcode方法,跟HashMap有关系吗?为什么?
   有关系,因为往HashMap里面get,put数据的时候,会通过hashcode方法定位数组的下标,再通过equals比较是否为同一个元素.

4. HashMap是线程安全的吗?遇到过ConcurrentModificationException异常吗?为什么出现?如何解决?
   不是线程安全的.在迭代的时候如果同时对其进行修改就会抛出java.util.ConcurrentModificationException异常。所以要避免迭代时修改数据,如果需要修改数据那就使用Iterator去修改;如果是多线程下修改数据,要使用并发安全的集合.
   参考:https://www.cnblogs.com/dolphin0520/p/3933551.html

5. 在使用HashMap的过程中我们应该注意哪些问题?

## 高级面试题

1. 笔试中要求你手写HashMap?
2. 你知道HashMap的工作原理吗?
3. HashMap中"死锁"是怎么回事?
   这是JDK7中的问题了,JDK8已经解决了.也即是多线程插入数据,因为是"头插法"引起数组扩容时会导致链表的死循环.而JDK8将节点插在链表的尾部解决这个问题
4. HashMap中能put两个相同的key吗?为什么能或为什么不能?
   可以啊,只不过原来的value值会被新的value值覆盖
5. HashMap中的键值可以为NULL吗?能简单说一下原理吗?
   可以为NULL,并且为NULL的key值的节点放在数组的第一个节点
6. HashMap扩容机制是怎么样的,JDK7与JDK8有什么不同吗?
7. 为什么HashMap的大小始终是2的n次方,即使你传15进来,HashMap依然会创建16个大小的数组?这跟计算hash值有关,用2的n次方计算hash值可以更加快速,如果不是以2的n次方为数组的长度,计算hash值就不能与操作了,从而需要用普通的运算符,降低HashMap的性能.