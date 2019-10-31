docker安装下面这些软件的[教程](https://github.com/macrozheng/mall-learning/blob/master/docs/deploy/mall_deploy_docker.md):

# 一. docker启动mysql

+ docker启动mysql命令

```shell
sudo docker run -p 3306:3306 --name mysql   -v /home/jimson/Documents/developer/docker_data/mysql/log:/var/log/mysql   -v /home/jimson/Documents/developer/docker_data/mysql/data:/var/lib/mysql   -v /home/jimson/Documents/developer/docker_data/mysql/conf:/etc/mysql   -e MYSQL_ROOT_PASSWORD=root    -d mysql:5.7
```

+ 进入运行mysql的docker容器:

```shell
docker exec -it mysql /bin/bash
```

+ 使用mysql命令打开客户端

```shell
mysql -uroot -proot --default-character-set=utf8
```

# 二. docker启动rabbitmq

+ docker启动rabbitmq命令

```shell
sudo docker run -d --name rabbit -p 5672:5672 -p 15672:15672 rabbitmq:3.7.15
```

+ 进入运行rabbitmq的docker容器并开启管理功能
```shell
sudo docker exec -it rabbit /bin/bash
rabbitmq-plugins enable rabbitmq_management
```

# 三. docker启动redis

+ docker启动redis命令
```shell
sudo docker run -p 6379:6379 --name redis   -v /home/jimson/Documents/developer/docker_data/redis/data:/data   -d redis:3.2 redis-server --appendonly yes
```
+ 进入容器管理redis
```shell
sudo docker exec -it redis redis-cli
```

# 四. docker启动nginx

+ docker启动nginx命令
```shell
sudo docker run -p 80:80 --name nginx   -v /home/jimson/Documents/developer/docker_data/nginx/html:/usr/share/nginx/html   -v /home/jimson/Documents/developer/docker_data/nginx/logs:/var/log/nginx    -d nginx:1.10
```

# 五. docker启动elasticsearch

+ docker启动elasticsearch命令
```shell
sudo docker run -p 9200:9200 -p 9300:9300 --name elasticsearch   -e "discovery.type=single-node"   -e "cluster.name=elasticsearch"   -v /home/jimson/Documents/developer/docker_data/elasticsearch/plugins:/usr/share/elasticsearch/plugins   -v /home/jimson/Documents/developer/docker_data/elasticsearch/data:/usr/share/elasticsearch/data   -d elasticsearch:6.4.0
```

# 六.docker启动kibana
+ docker启动kibana命令
```shell
sudo docker run --name kibana -p 5601:5601 \
  --link elasticsearch:es \
  -e "elasticsearch.hosts=http://es:9200" \
  -d kibana:6.4.0
```

# 七.docker启动mongodb
+ docker启动mongodb命令
```shell
sudo docker run -p 27017:27017 --name mongo \
  -v /home/jimson/Documents/developer/docker_data/mongo/db:/data/db \
  -d mongo:3.2
```

# 八.docker启动java8
+ docker启动java8命令
```shell
sudo docker run --name java8 -d java:8
```
