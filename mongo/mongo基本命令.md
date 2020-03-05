* 显示当前mongo中有多少个数据库,默认会有一个local库,这是mongo自带的.

  ``` shell
  show  dbs 
  或者
  show databases
  ```

* 进入某个数据库(如果mongodb中没有某个数据库,使用use进入该数据库也不会报错;该数据库会在第一次使用时自动创建)

  ``` shell
  use  数据库名
  ```

* 显示当前所在数据库

  ```shell
  db  
  ```

* 显示数据库中所有的集合

  ```shell
  show   collections
  ```

* 数据库的增删改查的操作

  ```shell
  # 向数据库中插入文档
  # db.<collection>.insert(doc) , 这里的db指的是当前所在的数据库,后面是集合名称,最后面是操作
  # 插入单个文档, 比如向test数据库中的student集合插入一个新的学生对象
  db.student.insert({name: "张三", age:18, gender:"男"})   
  # 插入多个文档
  db.student.insert([
  	{name: "李四", age:18, gender:"男"},
  	{name: "小红", age:18, gender:"女"}
  ])   
  # 其他插入命令
  db.student.insertOne()  #只能插入一个
  db.student.insertMany() #只能插入多个
  # 在往mongodb里面插入文档时, 会自动为每条文档生成一个_id字段,是一个ObjectId
  # 这个ObjectId是唯一的,根据时间戳来生成,每毫秒一个,再加上机器的机器码,确保id不重复,确保数据的唯一
  # 在mongo命令行中输入以下命令,可以返回mongo自动生成的ObjectId
  ObjectId()
  # 这个_id可以手动指定
  db.student.insert({_id:"aaabbb",  name: "张三", age:18, gender:"男"})   
  ```

  ```shell
  # 查询当前集合中的文档
  # db.<collection>.find(),这里的db指的是当前所在的数据库,后面是集合名称,最后面是操作
  # find()中可以接受一个对象作为查询条件, 空对象表示查询所有
  db.student.find()
  
  # find()的查询条件
  db.student.find({_id:"aaabbb"})  # 查找_id为"aaabbb"的文档,返回的是数组
  db.student.findOne()  # 查找符合条件的第一个文档,返回的是对象 
  db.student.find().count()  # 返回查询结果的文档的个数
  ```

  ```shell
  # 修改集合中的文档
  db.student.update({name:"张三"},  {age:100})  #这种方法会将{age:100}作为一个对象去替换原来的对象,谨慎使用
  db.student.update({name:"张三"},  {$set: {age: 100}})  #使用通配符修改某个字段
  db.student.update({name:"张三"},  {$unset: {age: 100}})  #使用unset清除文档的某个字段,其后面跟着的值随意写
  # update()默认只改一个符合条件的文档, 可以通过修改update()的multi参数为true以达到修改多条文档的目的
  # 其他修改命令
  db.student.updateOne()  #只能修改一个
  db.student.updateMany() #只能修改多个
  ```

  ```shell
  # 删除集合中的文档
  # remove根据条件删除文档;remove默认删除所有符合条件的文档;修改remove的justOne参数为true可以只删除一个文档
  db.student.remove({_id:"aaabbb"})
  
  # 其他修改命令
  db.student.removeOne()  #只能删除一个
  db.student.removeMany() #只能删除多个
  ```

  

