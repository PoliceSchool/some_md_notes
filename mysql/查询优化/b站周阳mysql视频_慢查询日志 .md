查看是否开启慢日志查询：show variables like '%slow_query_log%';

开启慢日志查询（重启数据库后失效）：set global slow_query_log=1;

慢日志查询一般不开启，只有需要调优时才需要开启

如果需要永久生效，需要修改配置文件my.cnf

查看耗时多久才被归类为慢查询时所耗费的秒数：show variables like '%long_query_time%';

设置耗时时间：set global long_query_time=3;

修改完之后需要重新开一个会话才能看到修改后的时间，或者使用  show global variables like '%long_query_time%'; 查看



模拟执行SQL语句超过3秒：select sleep(4);

随后新开一个操作系统命令行窗口查看/var/lib/mysql/76f124609e26-slow.log日志



在mysql客户端中查询：show global status like '%Slow_queries%';



## 日志分析工具 -- mysqldumpslow

mysql提供了日志分析工具

在操作系统命令行窗口中执行：mysqldumpslow --help

mysqldumpslow -s r -t 10 /var/lib/mysql/76f124609e26-slow.log