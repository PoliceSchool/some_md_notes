```mysql
CREATE TABLE  `mylock` (
  `id` INT PRIMARY KEY NOT NULL  AUTO_INCREMENT,
  `name` varchar(20)
) engine myisam;

INSERT INTO mylock(name)  VALUES('a');

INSERT INTO mylock(name)  VALUES('b');

INSERT INTO mylock(name)  VALUES('c');

INSERT INTO mylock(name)  VALUES('d');

INSERT INTO mylock(name)  VALUES('e');

select * from mylock;
```

```mysql
手动添加表的读锁
lock table mylock read, book write;
查看表上加过的锁
show open tables;
释放表锁
unlock tables;

假设现在数据库有mylock表和book表，有两个mysql客户端session1，session2
session1 客户端对mylock表加了读锁，
此时session1和session2均可以对mylock进行读操作
此时session1不能对mylock进行写操作，若session2对mylock进行写操作时会进入阻塞直到session1释放mylock的读锁
此时session1不对其他表（如book）进行读写操作，但是session2可以对其他表（如book）进行读写操作
```

```mysql
手动添加表的写锁
lock table mylock write;

假设现在数据库有mylock表和book表，有两个mysql客户端session1，session2
session1 客户端对mylock表加了写锁，
此时session1可以对mylock进行读写操作
此时session1不对其他表（如book）进行读写操作
若session2对mylock进行读写操作时会进入阻塞直到session1释放mylock的写锁（值得注意的是如果session2查询时是从缓存中读取的话是不会被阻塞的）
session2可以对其他表（book）进行读写操作
```

```mysql
总结：
读锁会阻塞写，但是不会阻塞读，而写锁则会把读和写都阻塞。
MyISAM的读写锁调度是写优先，这也是MyISAM不适合做写为主表的引擎。因为写锁后，其他线程不能做任何操作，大量的更新会使查询河南得到锁，从而造成永久阻塞。
```

```mysql
分析加锁情况
看看哪些表被锁了： show open tables;
如何分析表锁定?
可以通过table_locks_waited和table_locks_immediate状态变量来分析系统上的表锁定： show status like 'table%';
```

