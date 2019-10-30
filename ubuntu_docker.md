ubuntu docker

docker技术基于linux底层的容器来实现:https://www.redhat.com/zh/topics/containers/whats-a-linux-container



入门教程:http://www.ruanyifeng.com/blog/2018/02/docker-tutorial.html

安装过程:

Ubuntu官网安装教程:https://docs.docker.com/install/linux/docker-ce/ubuntu/#install-docker-engine---community-1

#### 安装前的准备:

1. ```shell
    sudo apt-get update
   ```

2. ```shell
   sudo apt-get install \
       apt-transport-https \
       ca-certificates \
       curl \
       gnupg-agent \
       software-properties-common
   ```

3. ```shell
   curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
   ```

4. ```shell
   sudo apt-key fingerprint 0EBFCD88
       
   pub   rsa4096 2017-02-22 [SCEA]
         9DC8 5822 9FC7 DD38 854A  E2D8 8D81 803C 0EBF CD88
   uid           [ unknown] Docker Release (CE deb) <docker@docker.com>
   sub   rsa4096 2017-02-22 [S]
   ```

5. ```shell
   sudo add-apt-repository \
      "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
      $(lsb_release -cs) \
      stable"
   ```

#### 开始安装

1. ```shell
   sudo apt-get update
   ```

2. ```shell
   sudo apt-get install docker-ce docker-ce-cli containerd.io
   ```

3. ```shell
   // 有可能国外源很慢,所以需要换源
   sudo docker image pull library/hello-world
   ```

4. ```shell
   sudo docker run hello-world
   ```

5. ```shell
   // 执行结果
   Hello from Docker!
   This message shows that your installation appears to be working correctly.
   
   To generate this message, Docker took the following steps:
   
     1. The Docker client contacted the Docker daemon.
     2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
        (amd64)
     3. The Docker daemon created a new container from that image which runs the
        executable that produces the output you are currently reading.
     4. The Docker daemon streamed that output to the Docker client, which sent it
        to your terminal.
   
   To try something more ambitious, you can run an Ubuntu container with:
    $ docker run -it ubuntu bash
   
   Share images, automate workflows, and more with a free Docker ID:
    https://hub.docker.com/
   
   For more examples and ideas, visit:
    https://docs.docker.com/get-started/
   ```

#### docker换源

参考教程:http://www.ruanyifeng.com/blog/2018/02/docker-wordpress-tutorial.html

1. 最好先备份一份/etc/default/docker, 然后打开 /etc/default/docker 文件,在文件最后加上一句
   DOCKER_OPTS="--registry-mirror=https://registry.docker-cn.com"
2. 重启Docker服务
   sudo service docker restart