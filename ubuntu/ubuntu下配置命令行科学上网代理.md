参考教程:https://github.com/naseeihity/LearnToLearn/issues/7

## 全局翻墙

实际上linux中更多的操作是在终端中进行，很多程序和服务的下载都需要通过 npm,gem,nvm,git等命令进行，而在前内起下载速度十分感人，而且很容易快下载完了又直接失败，都要重新开始，通过全局翻墙可以改善这种情况。

## 安装配置proxychains

全局翻墙通过proxychains实现，即将任何程序和ss的proxy建立链接，原理和浏览器的代理相似。

## 下载

```shell
sudo apt-get install proxychains
```
## 配置

```shell
# socks4    127.0.0.1 9050 将这一行注释掉
socks5    127.0.0.1    1080
```

## 使用

使用之前记得打开sslocal，在需要翻墙的命令前打上proxychains即可,如下
```shell
proxychains   curl    www.google.com
```

