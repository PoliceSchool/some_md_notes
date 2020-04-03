CREATE TABLE  `test03` (
  `id` INT PRIMARY KEY NOT NULL  AUTO_INCREMENT,
  `c1` char(10),
  `c2` char(10),
  `c3` char(10),
  `c4` char(10),
  `c5` char(10)
);

INSERT INTO test03(c1,c2,c3,c4,c5)  VALUES('a1','a2','a3','a4','a5');

INSERT INTO test03(c1,c2,c3,c4,c5)  VALUES('b1','b2','b3','b4','b5');

INSERT INTO test03(c1,c2,c3,c4,c5)  VALUES('c1','c2','c3','c4','c5');

INSERT INTO test03(c1,c2,c3,c4,c5)  VALUES('d1','d2','d3','d4','d5');

INSERT INTO test03(c1,c2,c3,c4,c5)  VALUES('e1','e2','e3','e4','e5');

select * from test03;

create index idx_test03_c1234 on test03(c1,c2,c3,c4);

show index from test03;



## 问题

我们创建了复合索引idx_test03_c1234，根据以下SQL分析下索引使用情况？

explain select * from test03 where c1='a1';

explain select * from test03 where c1='a1' and c2='a2';

explain select * from test03 where c1='a1' and c2='a2' and c3='a3';

explain select * from test03 where c1='a1' and c2='a2' and c3='a3' and c4='a4';

explain select * from test03 where c1='a1' and c2='a2' and c4='a4' and c3='a3';

explain select * from test03 where c1='a1' and c2='a2' and c3>'a3' and c4='a4';

explain select * from test03 where c1='a1' and c2='a2' and c4>'a4' and c3='a3';

explain select * from test03 where c1='a1' and c2='a2' and c4='a4' order by c3;

explain select * from test03 where c1='a1' and c2='a2' order by c3;

explain select * from test03 where c1='a1' and c2='a2' order by c4;

explain select * from test03 where c1='a1' and c5='a5' order by c2,c3;

explain select * from test03 where c1='a1' and c5='a5' order by c3,c2;

explain select * from test03 where c1='a1' and c2='a2' order by c2,c3;

explain select * from test03 where c1='a1' and c2='a2' and c5='a5' order by c2,c3;

explain select * from test03 where c1='a1' and c4='a4' group by c2,c3;

group by基本上需要进行排序，需要产生临时表，性能较慢