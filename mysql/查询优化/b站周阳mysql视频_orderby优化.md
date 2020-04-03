CREATE TABLE `tblA` (
  #id  INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
  age  int,
  birth  TIMESTAMP NOT NULL
) ;



INSERT INTO tblA(age, birth) VALUES(22, NOW());

INSERT INTO tblA(age, birth) VALUES(23, NOW());

INSERT INTO tblA(age, birth) VALUES(24, NOW());



CREATE INDEX idx_A_ageBirth ON tblA(age, birth);

select * from tblA;



EXPLAIN SELECT * FROM tblA WHERE age = 20 ORDER BY birth;

EXPLAIN SELECT * FROM tblA WHERE age > 20 ORDER BY age;

EXPLAIN SELECT * FROM tblA WHERE age > 20 ORDER BY age,birth;

EXPLAIN SELECT * FROM tblA WHERE age > 20 ORDER BY birth;

EXPLAIN SELECT * FROM tblA WHERE age > 20 ORDER BY birth, age;



EXPLAIN SELECT * FROM tblA ORDER BY birth;

EXPLAIN SELECT * FROM tblA WHERE birth > '2016-01-28 00:00:00' ORDER BY birth;

EXPLAIN SELECT * FROM tblA WHERE birth > '2016-01-28 00:00:00' ORDER BY age;

EXPLAIN SELECT * FROM tblA ORDER BY age ASC, birth DESC;

EXPLAIN SELECT * FROM tblA ORDER BY age DESC, birth DESC;

EXPLAIN SELECT * FROM tblA ORDER BY age ASC, birth ASC;



MySQL支持两种方式的排序，FileSort和Index排序，Index效率高，它指MySQL扫描索引本身完成排序。FileSort方式效率低下。

ORDER BY 满足两种情况，会使用Index方式排序：

1. ORDER BY 语句使用索引最左前列（最佳左匹配原则）
2. 使用Where子句与Order By子句条件列组合满足索引最左前列

尽可能在索引列上完成排序操作，遵照索引建的最佳左前缀

如果不在