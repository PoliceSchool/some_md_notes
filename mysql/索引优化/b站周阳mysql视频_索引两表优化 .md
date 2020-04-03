CREATE TABLE IF NOT EXISTS `class` (
  `id` INT(10) UNSIGNED NOT NULL  AUTO_INCREMENT,
  `card` INT(10) UNSIGNED NOT NULL,
PRIMARY KEY(`id`)
);

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO class(card)  VALUES(FLOOR(1+(RAND() * 20)));





CREATE TABLE IF NOT EXISTS `book` (
  `bookid` INT(10) UNSIGNED NOT NULL  AUTO_INCREMENT,
  `card` INT(10) UNSIGNED NOT NULL,
PRIMARY KEY(`bookid`)
);

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));

INSERT INTO book(card)  VALUES(FLOOR(1+(RAND() * 20)));



EXPLAIN SELECT * FROM class LEFT JOIN book ON class.card = book.card;

ALTER TABLE `book` ADD INDEX Y(`card`);

drop index Y on book;

ALTER TABLE `class` ADD INDEX Y(`card`);

EXPLAIN SELECT * FROM class LEFT JOIN book ON class.card = book.card;

左连接的索引加在右表，右连接的索引加在左表



先清除掉之前建立的所有索引

alter table class add index Y (card);

EXPLAIN SELECT * FROM class RIGHT JOIN book ON class.card = book.card;