## sleep和wait的异同？

1. 相同点：一旦执行方法，都可以使得当前线程进入阻塞状态
2. 不同点：
   * 两个方法声明的位置不同，Thread类中声明的sleep(),Object类中声明wit()
   * 调用的要求不同：sleep()可以再任何需要的场景下调用。wait()必须使用在同步代码块或者同步方法中
   * 关于是否释放同步监视器：如果两个方法都是用在同步代码块或同步方法中，sleep()不释放锁，wait释放锁。

```java
// 生产者消费者模型
public class Demo {
    public static void main(String[] args) {
        Clerk clerk = new Clerk();
        Thread producer = new Thread(new Producer(clerk), "生产者");
        Thread consumer1 = new Thread(new Consumer(clerk), "消费者1");
        Thread consumer2 = new Thread(new Consumer(clerk), "消费者2");

        producer.start();
        consumer1.start();
        consumer2.start();
    }
}

class Clerk {
    private int productCount;

    public synchronized void produceProduct() {
        if (productCount < 20) {
            productCount++;
            System.out.println(Thread.currentThread().getName() + "开始生产第" + productCount + "个产品");
            notify();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public synchronized void consumeProduct() {
        if (productCount > 0) {
            productCount--;
            System.out.println(Thread.currentThread().getName() + "开始消费第" + productCount + "个产品");
            notify();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Producer implements Runnable {
    private Clerk clerk;

    public Producer(Clerk clerk) {
        this.clerk = clerk;
    }

    @Override
    public void run() {
        System.out.println("开始生产产品...");
        while (true) {
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            clerk.produceProduct();
        }
    }
}


class Consumer implements Runnable {
    private Clerk clerk;

    public Consumer(Clerk clerk) {
        this.clerk = clerk;
    }

    @Override
    public void run() {
        System.out.println("开始消费产品...");
        while (true) {
            try {
                Thread.sleep(1500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            clerk.consumeProduct();
        }
    }
}
```

