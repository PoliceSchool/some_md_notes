1. == 既可以比较基本类型也可以比较引用类型。对于基本类型就是比较值，对于引用类型就是比较内存地址。
2. equals的话，它是属于java.lang.Object类里面的方法，如果该方法没有被重写过，默认也是==；我们可以看到String等类的equals方法也是被重写过的，而且String类型在日常开发中用的比较多，久而久之，形成了equals是比较值的错误观点。
3. 具体要看自定义类有没有重写object的equals方法来判断
4. 通常情况下，重写equals方法，会比较类中的相应属性是否都相等。

```java
		int it = 65;
        float fl = 65.0f;
        System.out.println(it == fl);   // true，因为基本类型会自动提升

        char ch1 = 'A';
        char ch2 = 12;
        System.out.println(it == ch1);  // true，因为基本类型会自动提升
        System.out.println(12==ch2);   // true，因为基本类型会自动提升

        String str1 = new String("hello");  
        String str2 = new String("hello");  
        System.out.println(str1 == str2);  // false，比较的是地址，所以是false
        System.out.println(str1.equals(str2));// true，比较的是值，所以是true

        System.out.println("hello" == new Date());   // 编译不通过，不同类型不能比较
```

