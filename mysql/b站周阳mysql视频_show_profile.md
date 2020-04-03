## 什么是 show profile

是mysql提供可以用来分析当前会话中语句执行的资源消耗情况，可以用于SQL的调优的测量

官网：http://dev.mysql.com/doc/refman/5.5/en/show-profile.html

默认情况下，参数处于关闭状态，并保存最近15次的运行结果



## 分析步骤

```mysql
show variables like 'profiling';
set profiling=on;
show profiles;
show profile cpu,block io for query 13;  // 可以查看一条sql执行的完整生命周期
```

## sql执行需要注意的点

```mysql
converting HEAP to MyISAM: 查询结果太大，内存都不够用了完磁盘上搬了

Creating  tmp  table： 创建临时表

Copying  to  tmp  table  on  disk：把内存中的临时表复制到磁盘，危险！！！

locked
```

