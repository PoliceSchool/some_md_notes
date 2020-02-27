redis 参考视频:https://www.bilibili.com/video/av75104725?p=5

==================================================================

string常用操作

get/set

mget/mset

redis的keys关键字搭配通配符可以找到多个符合条件的key值的value值

redis分布式锁: 用来解决商品超卖问题;

1. redis可以使用setnx来实现分布式锁, 
2. setnx的使用方式:setnx key value;作用:只有key值不存在时才存入value,否则不存入;这是最简单的分布式锁的实现方式.

incr命令:对某个key值进行原子加操作

redis内部实现方式是单线程的,所以不过外部有多少个线程都会被redis放进一个队列中排队;一次只执行一个线程的命令,防止并发问题

可以用redis存储session信息,实现session共享,比如一个用户登录的时候是在A服务器,下次访问的时候如果是在另一个B服务器那可能就需要重新登录了,这时候如果将session存放在redis上就可以避免这种情况.spring session + redis实现session共享

分布式系统全局序列号:INCRBY   orderId   1000

1. mysql分库分表的情况下主键自增可能会导致主键重复,这时候就可以使用redis生成全局序列号
2. 但是这样有个瓶颈问题,因为redis并发只有几万次,如果每次生成订单都要找redis生成id,那么一秒最多只能生成几万个id;所以解决方案是每台服务器每次向redis生成id时,一次拿1000个,然后放在自己的内存里慢慢消耗,不够了再向redis申请,这样就可以提高并发量了.

==================================================================

Redis的Hash常用操作:

hash相当于java里面的Map<Map<String,String>>结构

hash应用场景:使用redis实现购物车场景

* 以用户id为key,商品id为field,商品数量为value
* 添加商品:hset  cart:1001  10088  5,例如使用hset操作将productId为10088的商品加5件到用户id为1001的用户的购物车上
* 增加数量:hincrby cart:1001 10088 1  ,为哈希表key为cart:1001中field键为1008的值加上增量1
* 商品总数:hlen  cart:1001
* 删除商品:hdel cart:1001 10088
* 获取商品购物车所有商品:hgetall cart:1001

问题:hash这种数据结构如果使用在redis集群中会有什么问题?提示:数据分片,redis槽位,数据量过大时数据过于集中

==================================================================

list常用操作

lpush key value   //将一个或多个值value插入到key列表的表头(最左边)

rpush key value   //将一个或多个值value插入到key列表的表尾(最右边)

lrange key start stop

通过list实现常用的数据结构

* 栈 = LPUSH + LPOP -> FILO
* 队列  =   LPUSH + RPOP
* 阻塞队列  =  LPUSH + BRPOP;  如果队列中有元素,那么BRPOP和RPOP的作用一样,拿到值就返回,如果队列中没有元素,那么RPOP会立即返回儿BRPOP还会继续阻塞直到有新的元素进来.

list应用场景:

* 微博消息和微信公众号消息

==================================================================

set常用操作

sadd key value  // 放入集合

smembers key   //获取集合中所有元素

srandmember key count

spop key count

set应用场景

* 微信微博点赞,收藏,标签
* 求集合的并集交集差集: SINTER   set1  set2  set3  ;  SUNION  set1  set2  set3  ;   SDIFF  set1  set2  set3
* 集合操作实现微博微信关注模型