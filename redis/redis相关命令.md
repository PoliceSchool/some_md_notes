```shell
## 对key的相关操作
keys *    ##查询当前库的所有键
exists <key>   ##判断某个键是否存在
type <key>     ##查看键的类型
del <key>       ##删除某个键
expire  <key>  <seconds>  ##为键值设置过期时间，单位秒
ttl  <key>   ##查看还有多少秒过期，-1表示永不过期，-2表示已过期
dbsize  ##查询当前库的key的数量
flushdb ##清空当前库
flushall  ##清空全部库
```

```shell
## string类型的操作
get <key>    ## 查询对应键值
set <key> <value>   ## 添加键值对
append <key> <value>  ## 将给定的<value>追加到原值的末尾
strlen <key>  ## 获得值的长度
setnx <key> <value>  ## 只有在key不存在时设置key的值
incr <key>  ##将key中存储的数字值增1，只能对数值类型操作，如果为空，新增值为1
decr <key>  ##  将key中存储的数字值减1，只能对数值类型操作，如果为空，新增值为-1
incrby/decrby <key> <步长>  ##  将key中存储的数字值增减，只能对数值类型操作，自定义步长
```

```shell
## list类型的操作
## 单键多值，redis列表是简单的字符串列表，按照插入顺序排序，你可以添加一个元素到列表的头部，或者尾部
## 它的底层实际是个双向链表，对两端的操作性能很高，通过索引下标的操作中间节点性能会较差
lpush/rpush  <key>  <value>  <value2>  <value3>   ## 从左边或者右边插入一个或者多个值
lpop/rpop  <key>  ## 从左边或者右边吐出一个值
rpoplpush  <key1> <key2>  ## 从key1列表右边吐出一个值，插到key2列表左边
lrange <key>  <start>  <end>  ## 按照索引下标获得元素（从左到右）
lindex <key> <index>  ## 按照索引下标获得元素（从左到右）
llen <key>  ## 获得列表长度
linsert <key>  before <value> <newvalue>  ## 在value的前面插入newvalue
lrem  <key> <n> <value>  ## 从左边删除n个value
```

```shell
## set类型的操作
## redis set对外提供的功能与list类似是一个列表的功能，特殊之处在于set是可以自动排重的，当你需要存储一个列表数据，又不希望出现重复数据时，set是一个很好的选择，并且set提供了判断某个成员是否在一个set集合内的重要接口，这个也是list所不能提供的
## set是string类型的无序集合。它底层其实是一个value为null的hash表，所以添加，删除，查找的复杂度都是o(1)
sadd <key>  <value1>  <value2> ....  ## 将一个或多个value加入到集合key当中，已经存在于集合的value将被忽略
smembers <key>  ## 取出集合的所有值
sismember <key> <value>  ## 判断集合<key> 是否含有该<value>值，有返回1，没有返回0
scard <key>  ## 返回该集合的元素个数
srem <key>  <value1>  <value2>...  ## 删除集合中的某个元素
spop  <key>   ##  随机从集合中吐出一个值
srandmember  <key>  <n>   ##随机从集合中突出n个值，不会从集合中删除
sinter <key1>  <key2>  ## 返回两个集合的交集元素
sunion <key1> <key2> ## 返回两个集合的并集元素
sdiff   <key1>  <key2>  ##返回两个集合的差集元素
```

```shell
## hash类型的操作
## hash是一个键值对集合，hash是一个string类型的field 和value的映射表，hash特别适合用于存储对象。类似于Java中的Map<String, Object>
hset  <key>  <field>  <value>  ## 设置hash表key中的field字段所对应的value
hget <key>  <field>   ## 从hash表key中取出field字段所对应的value
hmset  <key>  <field1>  <value1>  <field2>  <value2>...   ## 批量设置hash表key的值
hexists  key  <field>  ## 查看hash表key中，是否存在给定的field
hkeys  <key> ## 列出hash表key的所有field
hvals  <key> ## 列出hash表key的所有value
hincrby  <key>  <field>  <increment>  ## 为hash表key中的field字段加上增量increment
hsetnx  <key>  <field>  <value>  ## 将hash表key中的field字段设置为value，当且仅当field不存在
```

```shell
## zset类型的操作
## zset与set非常相似，是一个没有重复元素的字符串集合。不同之处是有序集合的所有成员都关联了一个评分(score)，这个评分被用来按照从最低分到最高分的方式排序集合中的成员。集合的成员是唯一的， 但是评分可以是重复的
zadd  <key>  <score1>  <value1>  <score2>  <value2>...  ## 将一个或多个member元素及其score值加入到有序集key当中
zrange  <key>  <start>  <stop>  [WITHSCORES]  ##  返回有序集key中，下表在<start><stop>之间的元素。带WITHSCORES可以让分数一起和值返回到结果集
zrangebyscore key min  max  [withscores] [limit offset count]  ##返回有序集key中，所有score值介于min和max之间（包括等于min或max）的成员。有序集成员按score值递增次序排列。
zrevrangebyscore key max min  [withscores] [limit offset count]  ## 同上，改为从大到小排列。
zincrby <key> <increment> <value>  ## 为元素的score加上增量
zrem <key> <value> ## 删除该集合下，指定值的元素
zcount <key> <min> <max>  ## 统计该集合，分数区间内的元素个数
zrank <key> <value> ## 返回该值在集合中的排名，从0开始
```

