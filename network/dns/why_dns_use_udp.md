为什么DNS使用UDP而不使用TCP?翻译自[这里](https://www.geeksforgeeks.org/why-does-dns-use-udp-and-not-tcp/)

DNS是一个应用层协议.所有的应用层协议使用UDP或者TCP中的一种.TCP是可靠的而UDP是不可靠的.DNS按照常理来说应该是可靠的,但为什么使用UDP呢?

下面有一些关于传输层的TCP和UDP有趣的事实来解释上面的问题.

1. UDP更快.TCP因为需要使用3次握手协议所以会慢一点.DNS服务器的负载也是一个很重要的因素.DNS服务器不需要保持连接(因为它使用UDP).
2. DNS请求通常很小并且可以很好的放置在UDP段中.
3. UDP是不可靠的,但是可靠性可以在应用层实现.一个应用可以使用UDP并且可以通过应用层的超时和重发以获得可靠性

事实上,DNS主要在53号端口上使用User Datagram Protocol(UDP)来处理请求.DNS查询由来自客户端的单个UDP请求和服务端回应的单个UDP请求组成.当应答的数据长度超过512bytes时,客户端和服务端都会使用EDNS,更大的UDP包.否则会使用TCP重新发送请求.TCP也用于区域传输等任务.一些解析器通过TCP来处理所有的请求

