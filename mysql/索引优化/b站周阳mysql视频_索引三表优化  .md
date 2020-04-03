CREATE TABLE IF NOT EXISTS `phone` (
  `phoneid` INT(10) UNSIGNED NOT NULL  AUTO_INCREMENT,
  `card` INT(10) UNSIGNED NOT NULL,
PRIMARY KEY(`phoneid`)
) ENGINE = INNODB;

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO phone(card)  VALUES(FLOOR(1+(RAND() * 20)));





EXPLAIN SELECT * FROM class INNER JOIN book ON class.card=book.card INNER JOIN phone ON book.card=phone.card;

EXPLAIN SELECT * FROM class LEFT JOIN book ON class.card=book.card LEFT JOIN phone ON book.card=phone.card;



ALTER TABLE `phone` ADD INDEX z (`card`);

ALTER TABLE `book` ADD INDEX Y (`card`);

EXPLAIN SELECT * FROM class LEFT JOIN book ON class.card=book.card LEFT JOIN phone ON book.card=phone.card;



【结论】

Join语句的优化

尽可能减少Join语句中的NestedLoop的循环总次数：“永远用小结果集驱动大的结果集”（小表驱动大表）

优先优化NestedLoop的内存循环

**保证Join语句中被驱动表上Join条件字段已经被索引。**

当无法保证被驱动表的Join条件字段被索引且内存资源充足的前提下，不要太吝啬JoinBuffer的设置。



