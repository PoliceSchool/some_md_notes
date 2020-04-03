## 分析

1. 观察，至少跑一天，看看生成的慢SQL情况
2. 开启慢查询日志，设置阙值，比如超过5秒钟的就是慢SQL，并将它抓取出来
3. explain + 慢SQL分析
4. show profile
5. 运维经理或者DBA进行SQL数据库服务器的参数调优

## 总结

1. 慢查询的开启并捕获
2. explain + 慢SQL分析
3. show profile查询SQL在mysql服务器里面的执行细节和生命周期情况
4. SQL数据库服务器的参数调优



### 优化原则：小表驱动大表，即小的数据集驱动大的数据集

#### 当At表的数据集小于B的数据集时，用in优于exists

select * from A where id in (select id from B)

等价于：

for select id from B

for select * fro A where A.id = B.id

#### 当B表的数据集大于A的数据集时，用exists优于in

select * from A where exists (select 1 from B where B.id = A.id)

等价于

for select * from A

for select * from B where B.id = A.id

### exists作用

* 作用：将主查询的数据放到子查询中做条件验证，根据验证结果（TRUE 或 FALSE）来决定主查询的数据结果是否得以保留。
* 





### 执行以下命令

explain select * from tbl_emp e  where e.deptId in (select id from tbl_dept d);

explain select * from tbl_emp e  where exists (select 1 from tbl_dept d where d.id = e.deptId);