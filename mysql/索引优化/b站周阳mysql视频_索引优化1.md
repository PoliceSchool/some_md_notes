## 索引失效（应该避免）

CREATE TABLE staffs(
    id INT PRIMARY KEY AUTO_INCREMENT,
    NAME VARCHAR(24) NOT NULL DEFAULT '' COMMENT '姓名',
    age INT NOT NULL DEFAULT 0 COMMENT '年龄',
    pos VARCHAR(20) NOT NULL DEFAULT '' COMMENT '职位',
    add_time  TIMESTAMP  NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '入职时间'
) CHARSET utf8 COMMENT '员工记录表';

INSERT INTO staffs(NAME, age, pos,add_time) VALUES('z3',22,'manager',NOW());

INSERT INTO staffs(NAME, age, pos,add_time) VALUES('July',23,'dev',NOW());

INSERT INTO staffs(NAME, age, pos,add_time) VALUES('2000',23,'dev',NOW());

SELECT * FROM staffs;



ALTER TABLE staffs ADD INDEX idx_staffs_nameAgePos(name,age,pos);



### 演示索引失效

EXPLAIN SELECT * FROM staffs WHERE NAME='July';

EXPLAIN SELECT * FROM staffs WHERE NAME='July' AND age = 23;

EXPLAIN SELECT * FROM staffs WHERE NAME='July' AND age = 23 AND pos='dev';

**前三条语句都有使用到索引，但是下面三条语句就没有使用到索引，因为没有遵守最佳左前缀法则**

EXPLAIN SELECT * FROM staffs WHERE age = 23;

EXPLAIN SELECT * FROM staffs WHERE pos='dev';

EXPLAIN SELECT * FROM staffs WHERE age = 23 AND pos='dev';

### 下面这一条语句虽然有用到索引，但是是部分索引，只是对name进行索引而已，没有对pos索引

EXPLAIN SELECT * FROM staffs WHERE NAME='July' AND pos  = 'dev';





explain select * from staffs where name like '%July%';

explain select * from staffs where name like '%July';

explain select * from staffs where name like 'July%';





CREATE TABLE `tbl_user`(
    `id` INT(11) NOT NULL AUTO_INCREMENT,
    NAME VARCHAR(20)  DEFAULT NULL,
    age INT(11)  DEFAULT NULL,
    email VARCHAR(20) DEFAULT NULL,
    PRIMARY KEY(`id`)
) ENGINE=INNODB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

INSERT INTO tbl_user(NAME, age, email) VALUES('1aa1', 21, 'b@163.com');

INSERT INTO tbl_user(NAME, age, email) VALUES('2aa2', 222, 'a@163.com');

INSERT INTO tbl_user(NAME, age, email) VALUES('3aa3', 265, 'c@163.com');

INSERT INTO tbl_user(NAME, age, email) VALUES('4aa4', 21, 'd@163.com');



SELECT * FROM tbl_user WHERE NAME LIKE '%aa%';

SELECT * FROM tbl_user WHERE NAME LIKE 'aa%';