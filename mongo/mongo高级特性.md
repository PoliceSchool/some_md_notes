### Mongo的索引 -- Index

* 跟mysql的索引一样,Mongo的索引是为了提升查询的效率
* 索引的使用需要占用空间
* 不合适的索引会降低效率
* mongo默认会给主键(_id)创建一个唯一索引
* Mongo使用的是B-Tree结构,  而Mysql使用的是B+Tree结构

### 单字段索引

```shell
# 查询集合中所有的索引
db.student.getIndexes()
#返回结果
[
	{
		"v" : 1,     # version, 表示当前的索引引擎版本号是第一个版本
		"key" : {  # 表明在哪个字段上面加了索引
			"_id" : 1   # 1代表升序排列
		},
		"name" : "_id_",  # 索引的名称, 默认是字段名加上下划线
		"ns" : "test.student"  #namespace, 表明当前这个索引属于那个数据库的集合
	}
]
```

```shell
# 创建索引
# db.student.createIndex(keys, options)  
#  keys表示你想要在哪些字段上加索引, 可以指定多个,多个的话表示是复合索引
#  options表示是可选项, 比如name,索引名称;unique, 是否为唯一索引; 其他的参考官方文档
db.student.createIndex({age:1})  
```

```shell
# 删除索引
db.student.dropIndex({age:1})
db.student.dropIndexes()  # 删除除了_id索引外的其他所有索引
```

### 复合索引

```shell
# 创建索引
db.student.createIndex({age:1,name:-1})
```

```shell
# 删除索引
db.student.dropIndex("age_1_name_-1")
db.student.dropIndexes()  # 删除除了_id索引外的其他所有索引
```

### 其他索引

* 地理空间索引
* 文本索引
* 哈希索引(用于支持散列的分片)

### 索引的使用(执行计划)

```shell
#使用下面这个命令查询是否使用了索引
db.student.find({name:"小明3"}).explain()
#返回结果
{
	"queryPlanner" : {
		"plannerVersion" : 1,
		"namespace" : "test.student",
		"indexFilterSet" : false,
		"parsedQuery" : {
			"name" : {
				"$eq" : "小明3"
			}
		},
		"winningPlan" : {
			"stage" : "COLLSCAN",   # 这里表明是全集合扫描,没有用到索引,因为没有设置索引
			"filter" : {
				"name" : {
					"$eq" : "小明3"
				}
			},
			"direction" : "forward"
		},
		"rejectedPlans" : [ ]
	},
	"serverInfo" : {
		"host" : "54613a49b631",
		"port" : 27017,
		"version" : "3.2.21",
		"gitVersion" : "1ab1010737145ba3761318508ff65ba74dfe8155"
	},
	"ok" : 1
}

#创建索引
db.student.createIndex({name:1})
#再次使用下面这个命令查询是否使用了索引
db.student.find({name:"小明3"}).explain()
#返回结果
{
	"queryPlanner" : {
		"plannerVersion" : 1,
		"namespace" : "test.student",
		"indexFilterSet" : false,
		"parsedQuery" : {
			"name" : {
				"$eq" : "小明3"
			}
		},
		"winningPlan" : {
			"stage" : "FETCH",
			"inputStage" : {
				"stage" : "IXSCAN",   # 这里表明是索引扫描,用到了索引
				"keyPattern" : {
					"name" : 1
				},
				"indexName" : "name_1",
				"isMultiKey" : false,
				"isUnique" : false,
				"isSparse" : false,
				"isPartial" : false,
				"indexVersion" : 1,
				"direction" : "forward",
				"indexBounds" : {
					"name" : [
						"[\"小明3\", \"小明3\"]"
					]
				}
			}
		},
		"rejectedPlans" : [ ]
	},
	"serverInfo" : {
		"host" : "54613a49b631",
		"port" : 27017,
		"version" : "3.2.21",
		"gitVersion" : "1ab1010737145ba3761318508ff65ba74dfe8155"
	},
	"ok" : 1
}

```

### 涵盖查询

* 查询官方文档