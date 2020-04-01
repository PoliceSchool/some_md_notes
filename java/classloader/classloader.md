# 类加载过程

## 一. 类加载子系统作用

![类加载子系统](/home/jimson/Documents/github/policeschool/some_md_notes/java/classloader/类加载子系统.jpeg)

* ClassLoader(类加载子系统)负责从文件系统或者网络中加载Class文件,class文件在开头有特定的文件标识.
  1. 这个特定的文件标识是魔数,这个魔数固定为0xCAFEBABE;所以只要开头是0xCAFEBABE就可以被类加载子系统识别
  2. 将编译好的class文件使用vim打开,然后在命令行模式下敲入":%!xxd",也就是以16进制打开class文件,就可以看到文件的最开始位置写着 "cafe babe"这两个单词.
* ClassLoader只负责class文件的加载,至于它是否可以运行,则由Execution Engine决定.
* 加载的类信息存放于一块称为方法区的内存空间.除了类的信息外,方法区中还会有存放运行时常量池信息,可能还包括字符串字面量和数字常量(这部分常量信息是Class文件中常量池部分的内存映射)
  1. 使用"javap  -v   class文件名"可以得到反编译的字节码文件,里面有一个"Constant Pool",这里存放类的常量信息,在运行时会被加载到内存里,被称为运行时常量池.
     ![](/home/jimson/Documents/github/policeschool/some_md_notes/java/classloader/反编译的字节码文件.png)

## 二. 类加载器的角色

![](/home/jimson/Documents/github/policeschool/some_md_notes/java/classloader/类加载器的角色.png)

1. class文件存在本地硬盘上,最终这个文件要加载到JVM中,然后根据这个文件实例化出n个一模一样的实例
2. class文件被加载到JVM中,被称为DNA元数据模板,放在方法区.
3. 类加载器负责加载class文件到JVM中

## 三. 类的加载全过程

![](/home/jimson/Documents/github/policeschool/some_md_notes/java/classloader/类的加载全过程.jpg)

![](/home/jimson/Documents/github/policeschool/some_md_notes/java/classloader/jvm类装载过程.png)

**注:上图中的HelloLoader是自定义的一个类,只是简单的输出"Hello World"而已.**

### 类的加载全过程第一步: 加载

#### * 加载过程

1. 通过一个类的权限定类名获取定义此类的二进制字节流
2. 将这个字节流所代表的静态存储结构转化为方法区的运行时数据结构
3. 在内存中生成一个代表这个类的java.lang.Class对象,作为方法区这个类的各种数据的访问入口.

#### * 加载方式

1. 从本地系统中直接加载
2. 运行时计算生成,比如使用的最多的:动态代理技术
3. 等等

### 类的加载全过程第二步: 链接

#### *验证(Verify)

* 目的在于确保Class文件的字节流中包含信息符合当前虚拟机要求,保证被加载类的正确性不会危害虚拟机自身安全.(关于前面说的魔数"CAFEBABE"的验证就在这里)
* 主要包括四中验证, 文件格式验证,元数据验证,字节码验证,符号引用验证

#### *准备(Prepare)

* 为类变量(比如静态变量)分配内存并且设置类变量的默认初始值,即零值.
* **这里不包含用final修饰的static,因为final在编译的时候就会被分配了,准备阶段会显示初始化.**
* **这里不会为实例变量分配初始化**,类变量会分配在方法区中,而实例变量是会随着对象一起分配到Java堆中.

#### *解析(Resolve)

* 将常量池内的符号引用转换为直接引用的过程(前面说过类文件里面有个"Constant Pool","Constant Pool"里面会有#1, #2之类的符号引用,就是把这些符号引用转成直接引用)
* 在编译时,java类并不知道所引用类的实际地址,只能使用符号引用来代替.
* 直接引用是直接指向目标的指针.

#### 类的加载全过程第三步: 初始化

* **初始化阶段就是执行类构造器方法<clinit>()的过程.**
* 此方法不需要定义,是javac编译器自动收集类中的所有类变量的赋值动作和静态代码块中的语句合并而来
* 构造器方法中指令按语句在源文件中出现的顺序执行
* **<clinit>()不同于类的构造器**.(关联:构造器是虚拟机视角下的<init>())
* 若该类具有父类,JVM会保证子类的<clinit>()执行前,父类的<clinit>()以及执行完毕

```java
public class Test {
    static class Father {
        {
            ordinaryVariableOfFather = "在父类的前置普通代码块中给父类的普通变量赋值";
            // 前置代码块中无法引用在后面定义的变量,只可以赋值;所以下面这句代码是会报错的
            // System.out.println(ordinaryVariableOfFather);
        }

        static {
            staticVariableOfFather = "在父类的前置静态代码块中给父类的静态变量赋值";
            // 前置代码块中无法引用在后面定义的变量,只可以赋值;所以下面这句代码是会报错的;
            // System.out.println(staticVariableOfFather);
        }

        // 父类的普通变量
        public String ordinaryVariableOfFather = "父类的普通变量赋值";
        // 父类的静态变量（题外话：类的静态变量存放于方法区中）
        public static String staticVariableOfFather = "父类的静态变量赋值";

        {
            ordinaryVariableOfFather = "在父类的后置普通代码块中给父类的普通变量赋值";
            System.out.println(ordinaryVariableOfFather);
        }

        static {
            staticVariableOfFather = "在父类的后置静态代码块中给父类的静态变量赋值";
            System.out.println(staticVariableOfFather);
        }

        public Father() {
            ordinaryVariableOfFather = "在父类的构造方法中给父类的普通变量赋值";
            staticVariableOfFather = "在父类的构造方法中给父类的静态变量赋值";
            System.out.println("父类构造器");
        }

        @Override
        public String toString() {
            return ordinaryVariableOfFather + "  " +
                    staticVariableOfFather;
        }
    }

    static class Son extends Father {
        {
            ordinaryVariableOfSon = "在子类的前置普通代码块中给子类的普通变量赋值";
            // 前置代码块中无法引用在后面定义的变量,只可以赋值;所以下面这句代码是会报错的
            // System.out.println(ordinaryVariableOfSon);
        }

        static {
            staticVariableOfSon = "在子类的前置静态代码块中给子类的静态变量赋值";
            // 前置代码块中无法引用在后面定义的变量,只可以赋值;所以下面这句代码是会报错的
            // System.out.println(staticVariableOfSon);
        }

        // 子类的普通变量
        public String ordinaryVariableOfSon = "子类的普通变量赋值";
        // 子类的静态变量（题外话：类的静态变量存放于方法区中）
        public static String staticVariableOfSon = "子类的静态变量赋值";

        {
            ordinaryVariableOfSon = "在子类的后置普通代码块中给子类的普通变量赋值";
            System.out.println(ordinaryVariableOfSon);
        }

        static {
            staticVariableOfSon = "在子类的后置静态代码块中给子类的静态变量赋值";
            System.out.println(staticVariableOfSon);
        }

        public Son() {
            ordinaryVariableOfSon = "在子类的构造方法中给父类的普通变量赋值";
            staticVariableOfSon = "在子类的构造方法中给父类的静态变量赋值";
            System.out.println("子类构造器");
        }

        @Override
        public String toString() {
            return super.toString() + "  " +
                    ordinaryVariableOfSon + "  " +
                    staticVariableOfSon;
        }
    }

    /**
     * 在没有继承关系下, 类数据的实例化顺序
     * 1. 类的前置静态代码块
     * 2. 类的静态变量
     * 3. 类的后置静态代码块
     * 4. 类的前置代码块
     * 5. 类的普通变量
     * 6. 类的后置代码块
     * 7. 类的构造方法
     * <p>
     * 有继承关系下, 类数据的实例化顺序
     * 1. 父类的前置静态代码块
     * 2. 父类的静态变量
     * 3. 父类的后置静态代码块
     * 4. 子类的前置静态代码块
     * 5. 子类的静态变量
     * 6. 子类的后置静态代码块
     * 7. 父类的前置普通代码块
     * 8. 父类的普通变量
     * 9. 父类的后置普通代码块
     * 10.父类的构造方法
     * 11.子类的前置普通代码块
     * 12.子类的普通变量
     * 13.子类的后置普通代码块
     * 14.子类的构造方法
     */
    public static void main(String[] args) {
//        分别断点每一行看看
//        Father father = new Father();
        Son son = new Son();
    }
}

这里还要补充一点，就是子类重写了父类方法时的加载顺序，具体看当前路径下extendstest目录下的案例
```

* 虚拟机必须保证一个类的<clinit>()方法在多线程下被同步加锁.保证每个类只会被加载一次

  ```java
  public class Test {
  
      public static void main(String[] args) {
          Runnable r = () -> {
              System.out.println(Thread.currentThread().getName() + "开始");
              DeadThread dead = new DeadThread();
              System.out.println(Thread.currentThread().getName() + "结束");
          };
  
          Thread t1 = new Thread(r, "线程1");
          Thread t2 = new Thread(r, "线程2");
          t1.start();
          t2.start();
      }
  
      static class DeadThread {
          static {
              if (true) {
                  System.out.println(Thread.currentThread().getName() + "初始化当前类");
                  while (true) {
  
                  }
              }
          }
      }
  }
  ```

  

参考链接:B站中宋红康视频教程,27到30集

https://www.bilibili.com/video/av83638407?p=30