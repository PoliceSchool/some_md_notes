```mysql
create database bigData;

use bigData;
```

```mysql
CREATE TABLE `dept` (
  `id` INT UNSIGNED PRIMARY KEY  AUTO_INCREMENT,
  `deptno` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
  `dname`  VARCHAR(40)  NOT NULL DEFAULT "",
   `loc` VARCHAR(13) NOT NULL DEFAULT ""
) ENGINE=InnoDB   DEFAULT CHARSET=GBK;
```

```mysql
CREATE TABLE `emp` (
  `id` INT UNSIGNED PRIMARY KEY  AUTO_INCREMENT,
  `empno` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
  `ename`  VARCHAR(20)  NOT NULL DEFAULT "",
   `job` VARCHAR(9) NOT NULL DEFAULT "",
  `mgr` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
  `hiredate` DATE NOT NULL,
  `sal` DECIMAL(7,2) NOT NULL,
  `comm` DECIMAL(7,2) NOT NULL,
  `deptno` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0

) ENGINE=InnoDB   DEFAULT CHARSET=GBK;
```

```mysql
show variables like 'log_bin_trust_function_creators';

set global log_bin_trust_function_creators=1;
```

```mysql
DELIMITER $$
CREATE FUNCTION rand_string(n INT) RETURNS VARCHAR(255)
BEGIN
	DECLARE chars_str VARCHAR(100) DEFAULT '';
    DECLARE return_str VARCHAR(255) DEFAULT '';
    DECLARE i INT DEFAULT 0;
    WHILE i < n DO
	SET return_str = CONCAT(return_str, SUBSTRING(chars_str, FLOOR(1+RAND()*52), 1));
    SET i = i + 1;
    END WHILE;
    RETURN return_str;
END $$
```

```mysql
DELIMITER $$
CREATE FUNCTION rand_num() RETURNS INT(5)
BEGIN
	DECLARE i INT DEFAULT 0;
    SET i = FLOOR(100+RAND()*10);
RETURN i;
END $$
```

```mysql
DELIMITER $$
CREATE PROCEDURE insert_emp(IN START INT(10), IN max_num INT(10))
BEGIN
	DECLARE i INT DEFAULT 0;
    SET autocommit = 0;
    REPEAT
    SET i = i + 1;
    INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno) VALUES ((START+i), rand_string(6), 'SALESMAN', 0001, CURDATE(), 2000,400,rand_num());
    UNTIL i = max_num
    END REPEAT;
    COMMIT;
END $$
```

```mysql
DELIMITER $$
CREATE PROCEDURE insert_dept(IN START INT(10), IN max_num INT(10))
BEGIN
	DECLARE i INT DEFAULT 0;
    SET autocommit = 0;
    REPEAT
    SET i = i + 1;
    INSERT INTO dept (deptno, dname, loc) VALUES ((START+i), rand_string(10), rand_string(8));
    UNTIL i = max_num
    END REPEAT;
    COMMIT;
END $$
DELIMITER ;
```

```mysql
CALL insert_dept(100,10);
CALL insert_emp(100001,500000);
```

