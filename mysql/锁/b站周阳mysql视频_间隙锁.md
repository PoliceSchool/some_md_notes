## 间隙锁

```mysql
CREATE TABLE  `test_innodb_lock` (
  `a` INT(11),
  `b` varchar(16)
) engine=innodb;

INSERT INTO test_innodb_lock  VALUES(1, 'b2');
INSERT INTO test_innodb_lock  VALUES(3, '3');
INSERT INTO test_innodb_lock  VALUES(4, '4000');
INSERT INTO test_innodb_lock  VALUES(5, '5000');
INSERT INTO test_innodb_lock  VALUES(6, '6000');
INSERT INTO test_innodb_lock  VALUES(7, '7000');
INSERT INTO test_innodb_lock  VALUES(8, '8000');
INSERT INTO test_innodb_lock  VALUES(9, '9000');
INSERT INTO test_innodb_lock  VALUES(1, 'b1');

create index test_innodb_a_ind on test_innodb_lock(a);
create index test_innodb_lock_b_ind on test_innodb_lock(b);
select * from test_innodb_lock;


##1 mysql客户端session1执行下面的语句
set autocommit=0;
update test_innodb_lock set b = '0629' where a > 1 and a<6;
##1
##2 mysql客户端session2执行下面的语句
set autocommit=0;
insert into test_innodb_lock values(2, '2000');  //这条语句会被阻塞住
##2
```

## 什么是间隙锁？

当我们用范围条件而不是相等条件检索数据，并请求共享或排他锁时，InnoDB会给符合条件的已有数据记录的索引项加锁；对于键值在条件范围内但并不存在的记录，叫做“间隙（GAP）”

InnoDB也会对这个“间隙”加锁，这种锁机制就是所谓的间隙锁（Next-Key锁）

## 危害

因为Query执行过程中通过范围查找的话，它会锁定整个范围内所有的索引键值，即使这个键值并不存在。

间隙锁有一个比较致命的弱点，就是当锁定一个范围键值之后，即使某些不存在的键值也会被无辜的锁定，而造成锁定的时候无法插入锁定范围内的任何数据。在某些场景下这可能会对性能造成很大的伤害。