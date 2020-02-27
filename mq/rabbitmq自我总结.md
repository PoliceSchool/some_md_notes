rabbitmq自我总结:

rabbitmq的组件:virtual hosts(虚拟主机), exchange,queue,routing key

一台服务器上可以部署多个rabbitmq,一个rabbitmq可以创建多个virtual hosts,一个virtual hosts可以有多个exchange,一个exchange可以有queue,当然一个queue也可以有多个exchange;

exchange与queue之间的绑定是通过routing key绑定在一起的.

应用服务器如何发送消息到rabbitmq呢?

1. 应用服务选择rabbitmq的某个exchange,再通过发送一个key和消息到rabbitmq上;rabbitmq会找到对应的exchange,由这个exchange决定将应用服务的消息分发到不同的队列.具体分发原则由direct,topic,fanout这3种.direct会根据key值一一对应到队列,topic会根据匹配规则分发到相对应的队列,fanout是全部分发.这是发布订阅模式
2. 应用服务直接选择对应的队列然后发送消息即可;





采用rabbitmq的好处:解耦,异步,销峰

采用rabbitmq的坏处:降低系统的可用性,如果rabbitmq挂了,那所有的接口都接受不到mq的消息;增加开发的复杂度,要考虑消息的重复,消息丢失,消息积压,消息顺序,消息幂等,消息事务,集群等等

