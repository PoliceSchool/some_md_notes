package com.java_practice_code.interview.practice.extendstest;

public class Father {
    private int i = test();
    private static int j = method();  // （题外话：类的静态变量存放于方法区中）

    static {
        System.out.println("(1)");
    }

    Father() {
        System.out.println("(2)");
    }

    {
        System.out.println("(3)");
    }

    public int test() {
        System.out.println("(4)");
        return 1;
    }

    public static int method() {
        System.out.println("(5)");
        return 1;
    }
}
