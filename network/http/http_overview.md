http预览,翻译自[这里](https://www.tutorialspoint.com/http/http_overview.htm)

http是用于 distributed, collaborative, hypermedia 信息系统的应用层协议.自从1990年以来http就一直是万维网(比如互联网)数据通信的基础.http是一个通用且无状态的协议,另外也能够将http的request methods,error codes和headers用来做其他用途的拓展.

基本上,http是一个基于TCP/IP的通信协议,用来在万维网上传输数据(比如html文件,图像文件,查询结果等).默认端口是80,但其他端口也是可以使用的.它为计算机之间的通讯提供了标准化的方法.http规范指明了客户端如何构建请求并且发送给服务端,服务端如何对这些请求进行回应.

**基本特征**
使得http简洁而又强大的3个特征:

* **http无连接的**:http客户端,比如浏览器,会先初始化一个http request,在http request制作好了之后客户端会等待response.服务器处理request并且返回一个response,随后客户端会销毁连接.所以客户端和服务端只有在当前的request和response里面意识到对方的存在.如果需要发送更多的request就需要建立新的连接,此时客户端和服务端就像是第一次见面一样.(备注:TCP是面向连接的是因为每次传输数据都会将当时的状态一起传给对方,比如ip,port,synnumber,acknumber等,而http不像tcp那样会将一些变量传给对方,所以从这一方面来说http是无连接的,如果http将socket这些信息也一起传给对方,也可以有连接.这也是下面会提及的无状态)
* **HTTP is media independent**:这也就意味着http能够传输各种类型的数据只要对方知道如何处理这些数据.但是这需要客户端和服务端用MIME-type字段指定当前文本的类型
* **http是无状态的**:正如上面提及的,http是无连接的,所以这直接导致了http同时也是一个无状态协议.服务端和客户端只有在当前的request中才能意识到对方的存在.随后,客户端和服务端都会忘记彼此.由于协议本身的条件,不论是客户端还是服务端都不会保存不同网页的请求信息.

HTTP/1.0 uses a new connection for each request/response exchange, where as HTTP/1.1 connection may be used for one or more request/response exchanges.

**基础架构**:

下图展示了web应用的架构并且指明了http在其中的位置

![HTTP Architecture](../images/http/cgiarch.gif)



为什么http是无连接是协议?参考[这里](https://www.learnpick.in/questions/details/35782/why-http-is-a-connectionless-protocol),[这里](https://www.quora.com/How-is-HTTP-is-connectionless-when-TCP-IP-is-connection-oriented),注意这里的http无连接是面向应用层的(http连接是无连接的,也就是说在一个http链接里没有一些变量来维护客户端和服务端之间的状态,而TCP连接有ip,port,syn号等变量来维护客户端和服务端之间的状态),而TCP的连接面向传输层的,这就是为什么http明明使用了面向连接的TCP却仍然是无连接协议.