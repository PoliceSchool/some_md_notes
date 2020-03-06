* sort用来指定文档间的排序

  ``` shell
  { "_id" : ObjectId("5e60ed52c550aede6deae33e"), "name" : "aa", "age" : 10, "gender" : "男" }
  { "_id" : ObjectId("5e60edf5c550aede6deae33f"), "name" : "李a", "age" : 18, "gender" : "男" }
  { "_id" : ObjectId("5e60ed52c550aede6deae33c"), "name" : "李四", "age" : 18, "gender" : "男" }
  { "_id" : ObjectId("5e60edf5c550aede6deae340"), "name" : "小p", "age" : 19, "gender" : "女" }
  { "_id" : ObjectId("5e60ed52c550aede6deae33d"), "name" : "小红", "age" : 19, "gender" : "女" }
  
  #1代表正序排列, -1代表倒序排列
  db.student.find({}).sort({age:1})
  # 可以多加几个参数代表多个字段排序
  db.student.find({}).sort({age:1, name:1})
  ```


* 投影(筛选字段, 只显示自己要的字段)

  ```shell
  db.student.find({}, {name:1})
  ```

* 批量插入数据时,容易出现失败,因此可以使用try catch进行异常捕捉处理(仅作了解)

  ```
  try{
  	db.student.insert([
  		{name: "小红1", age:18, gender:"男"},
  		{name: "小红2", age:19, gender:"女"},
  		{name: "小红3", age:20, gender:"女"},
  		{name: "小明1", age:21, gender:"男"},
  		{name: "小明2", age:22, gender:"女"},
  		{name: "小明3", age:23, gender:"女"},
  	]);
  } catch(e){
  	print (e);
  }
  ```

* 统计与分页

  ```shell
  # 统计
  db.student.find().count()
  db.student.count()
  db.student.count({gender: "女"})
  
  #分页
  db.student.find().limit(3)
  db.student.find().skip(3).limit(3) 与 db.student.find().limit(2).skip(2) 效果一致
  ```

* 正则表达式

  ```shell
  db.student.find({name: /小明/})
  ```

* 比较查询

  ```shell
  db.student.find({age:{$gt: 21}})
  ```

* 包含查询

  ```shell
  db.student.find({name:{$in:["小明1", "小红1"]}})
  db.student.find({name:{$nin:["小明1", "小红1"]}})
  ```

* 条件连接查询

  ```shell
  # "且"查询, 即"and"查询
  db.student.find({$and:[{name:/明/}  ,   {gender:"女"},  {age:{$gt:22}}]})
  
  # "或"查询, 即"or"查询
  db.student.find({$or:[{age:{$gt:22}}, {age:{$lt:20}}]})
  ```

  