http-home, 翻译自[这里](https://www.tutorialspoint.com/http/index.htm)

http是用于 distributed, collaborative, hypermedia 信息系统的应用层协议.自从1990年以来http就一直是万维网(比如互联网)数据通信的基础.http是一个通用且无状态的协议,另外也能够将http的request methods,error codes和headers用来做其他用途的拓展.

这篇教程基于RFC-2616规范,也就是被人所熟知的http1.1协议.http1.1是原始http1.0的修订版.http1.0与http1.1最主要的区别就是http1.0的一个连接只会对应一个request/response exchange,而http1.1的一个连接可能对应一个或者多个request/response exchange.(备注:就是所谓的长连接,http1.0每次请求都要新建一个连接,服务器处理完请求就断开连接,再请求再新建连接;而http1.1会保持长连接,每次请求会新建一个连接,这个连接会一直保持着,可以传输多个请求;参考[这里](https://www.jianshu.com/p/95a521b006a8))

