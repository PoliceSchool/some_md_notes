查看某张表的占用磁盘大小：

* 参考链接：https://blog.csdn.net/l1394049664/article/details/81285809
* ```mysql
  select concat(round(sum(data_length/1024/1024/1024),2),'G') as data_length_MB, concat(round(sum(index_length/1024/1024/1024),2),'G') as index_length_MB from information_schema.tables where table_schema='数据库名称' AND table_name='表名称';
  ```

```mysql
select table_name,
DATA_LENGTH/1024/1024 as tablesData,
INDEX_LENGTH/1024/1024 as indexData 
from information_schema.tables
where table_schema='数据库名称'
ORDER BY  tablesData desc;
原文链接：https://blog.csdn.net/qq_39455116/article/details/96480845
```
建立某张表的索引：

* ```mysql
  ALTER TABLE yun_cashflow ADD INDEX index_userid (userid);
  ```

查询mysql物理文件所在位置：

* ```mysql
  show global variables like "%datadir%";
  ```

