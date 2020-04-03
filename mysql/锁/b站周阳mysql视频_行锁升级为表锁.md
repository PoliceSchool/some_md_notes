## 索引失效导致行锁变表锁

```mysql
##1 mysql客户端session1执行下面的语句
update test_innodb_lock set a = 41 where b = 4000;  //此条语句执行完不会阻塞
##1
##2 mysql客户端session2执行下面的语句
// 此条语句执行完会阻塞，因为session1的更新语句有问题；b字段是varchar类型，而更新语句赋值的是整型
// 虽然mysql在底层会对session1的更新语句中的b字段进行类型转换，也就是将int类型转成varchar类型，
// 但是这样做使得表的索引失效（对索引进行额外的改动会造成索引失效，而类型转换也是一种额外的改动），索引失效后
// 就会导致行锁升级为表锁，所以下面这条语句会阻塞。
update test_innodb_lock set b = '9001' where a = 9;  
##2
```

