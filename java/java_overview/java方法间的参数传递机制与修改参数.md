## 方法间的参数传递机制与修改参数

```java
public class ParamPastTest {
    public static void main(String[] args) {
        int i = 1;
        String str = "hello";
        Integer num = 200;
        int[] arr = {1, 2, 3, 4, 5};
        MyData my = new MyData();

        change(i, str, num, arr, my);

        System.out.println("i = " + i);
        System.out.println("str = " + str);
        System.out.println("num = " + num);
        System.out.println("arr = " + Arrays.toString(arr));
        System.out.println("my.a = " + my.a);
    }

    // 这里需要注意String和包装类的不可变性，也就是String和包装类是被final修饰的类。
    // 对于String和包装类的"+="操作会重新创建一个引用类型然后赋值给变量
    public static void change(int i, String str, Integer num, int[] arr, MyData my) {
        i += 1;
        str += "world";
        num += 1;
        arr[0] += 1;
        my.a += 1;
    }

    static class MyData {
        int a = 10;
    }
}

##########OUTPUT#############
 i = 1
str = hello
num = 200
arr = [2, 2, 3, 4, 5]
my.a = 11
```



参考教程：https://www.bilibili.com/video/BV1Eb411P7bP?p=4