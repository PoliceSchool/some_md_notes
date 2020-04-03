CREATE TABLE `article` (
  `id` INT(10) UNSIGNED NOT NULL PRIMARY KEY AUTO_INCREMENT,
  `author_id` INT(10) UNSIGNED NOT NULL,
  `category_id` INT(10) UNSIGNED NOT NULL,
  `views` INT(10) UNSIGNED NOT NULL,
  `comments` INT(10) UNSIGNED NOT NULL,
  `title` VARBINARY(255)  NOT NULL,
  `content` TEXT NOT NULL
);

INSERT INTO `article`(`author_id`,`category_id`,`views` ,`comments`,`title` ,`content`) VALUES

(1,1,1,1,'1','1'),

(2,2,2,2,'2','2'),

(1,1,3,3,'3','3');

SELECT * FROM article;

### 查询category_id为1且comments大于1的情况下，views最多的article_id.

EXPLAIN SELECT id, author_id FROM article WHERE category_id=1 AND comments > 1 ORDER BY views DESC LIMIT 1;

### 查询表索引

show index from article;

### 新建表索引

CREATE INDEX idx_article_ccv on article(category_id,comments,views);

### 删除表索引

DROP INDEX idx_article_ccv ON article;

### 重新新建表索引

CREATE INDEX idx_article_cv on article(category_id,views);