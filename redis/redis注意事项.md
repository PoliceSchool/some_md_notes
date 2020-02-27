B站redis学习视频:https://www.bilibili.com/video/av51139549?p=22



### redis持久化RDB方式

redis中保存rdb文件时禁止外部数据继续灌入redis的操作:第一个是配置文件的"stop-writes-on-bgsave-error yes"这个配置项,这个配置项是说在后台保存数据值rdb文件时如果报错了需不需要停止数据继续写入redis,如果是yes则停止,否则继续写入redis.第二个是redis-cli中可以敲入save命令,与之对应的是bgsave命令,save命令是说在保存时需要阻塞,也即是在保存rdb文件时数据不允许写入redis;bgsave则是异步的,允许数据写入redis;



docker查看redis实例ip:https://www.cnblogs.com/kofsony/p/11101356.html

docker映射redis配置文件:https://www.jianshu.com/p/ff599cddc869

使用docker配置redis主从节点:https://www.cnblogs.com/vipzhou/p/8580495.html



redis缓存穿透,缓存雪崩,缓存击穿现象以及解决方案:

https://www.bilibili.com/video/av82831890?from=search&seid=7908825880662935030