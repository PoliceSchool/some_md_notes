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
select * from test_innodb_lock;

create index test_innodb_a_ind on test_innodb_lock(a);
create index test_innodb_lock_b_ind on test_innodb_lock(b);
```

```mysql
由于mysql5.5以后的版本使用innodb引擎，在每一个语句之后会自动commit，所以需要将自动commit设置为不自动commit
set autocommit=0;
##1 mysql 客户端session1执行下面的命令
select * from test_innodb_lock;
update test_innodb_lock set b='4001' where a = 4;
select * from test_innodb_lock;
##1 

##2 mysql 客户端session2执行下面的命令
select * from test_innodb_lock;  // 由于test_innodb_lock使用的是innodb引擎，默认隔离级别是RR，所以不会出现脏读
##2 

```

```mysql
展示行锁情况，其中有一个“Innodb_row_lock_waits”，表示系统启动后到现在总共等待的次数；另外有一个Innodb_row_lock_current_waits，表示当前正在等待锁定的数量。
show status like 'innodb_row_lock%';
```

```mysql
优化建议：
尽可能让所有数据检索都通过所有来完成，避免无所有行锁升级为表锁
合理设计索引，尽量缩小锁的范围
尽可能较少检索条件，避免间隙锁
尽量控制事务大小，减少锁定资源量和时间长度
尽可能低级别事务隔离
```

