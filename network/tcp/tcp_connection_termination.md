TCP连接终止,翻译自[这里](https://www.geeksforgeeks.org/tcp-connection-termination/)

在TCP的3次握手过程中我们知道了客户端与服务端是通过一个设置了SYN字段的报文段建立TCP连接的.

在这篇文章中我们将会学习如何在客户端和服务端之间关闭TCP连接.这里我们也需要发送一个FIN字段设置为1的报文段给服务端.连接的销毁需要TCP双方发送成对的FIN和ACK报文.

![img](../../images/network/tcp_connection_termination_1.png)

TCP四次挥手运行机制:

1. 第一步(来自客户端的FIN) -- 假设客户端应用程序决定想要关掉连接(注意服务端也能选择关掉连接).这将会使得客户端发送一个FIN报文给服务端并且进入**FIN_WAIT_1**状态.当处于**FIN_WAIT_1**时,客户端会等待服务端的一个确认报文(ACK).
2. 第二部(来自服务端的ACK) -- 当服务端接收到了客户端的带有FIN比特位的报文时,服务端会立刻发送一个确认报文(ACK)给客户端.
3. 第三步(客户端等待) -- 当处于**FIN_WAIT_1**时,客户端会等待服务端的一个确认报文(ACK).当接收到了这个确认报文时,客户端会进入**FIN_WAIT_2**状态.当处于**FIN_WAIT_2**状态时,客户端会等待服务端的另一个报文,而这个报文的FIN比特位设置为1.
4. 第四步(来自服务端的FIN) -- 服务端会在发送了确认报文(ACK)后的某个时间点再发送一个FIN报文给客户端(因为服务端需要处理关闭流程).
5. 第五步(来自客户端的ACK) -- 当接收到了来自服务端的FIN报文,客户端会发送一个确认报文给服务端,并且进入TIME_WAIT状态.在TIME_WAIT状态下,为了防止ACK丢失,客户端会重发确认报文.客户端花费在TIME_WAIT的时间取决于他们的实现,一般来说是30秒,1分钟和2分钟.经过等待之后,连接会被正式地关闭,并且客户端的所有资源(包括端口号和数据缓冲)都会被释放.

下图展示了客户端和服务端的一系列状态变化.在下面两张状态转换图中,我们仅展示了TCP如何正常建立并销毁连接的.

客户端的TCP状态图:

![img](../../images/network/tcp_state_in_client.png)

服务端的TCP状态图:

![img](../../images/network/tcp_state_in_server.png)

这里我们不讲述当连接的双方同时想要初始化或者销毁连接的场景,如果你有兴趣学习关于这些的更多内容和其他TCP的进阶问题,你可以看看 Stevens的书.

个人总结(部分总结来自[这里](https://en.wikipedia.org/wiki/Transmission_Control_Protocol#Connection_termination)):

在[这里](./tcp_flag.md)说过TCP连接是全双工通信的,TCP连接的两端都要各自向对方发起建立连接请求并建立两条单向的连接.在TCP销毁的时候也是一样的,连接的两端都要各自向对方发起销毁连接的请求.客户端首先发起销毁client->server连接请求,服务端接收到FIN报文立刻给客户端发送一个确认报文以同意客户端的销毁连接请求,随后服务端关闭client->server连接,关闭完了再给客户端发起一个销毁server->client连接请求.客户端收到来自服务端销毁连接请求后,会对这个请求进行确认随后等一段时间再关闭server->client的连接,在这段时间内,本地端口号是不能被新连接使用的,因为连接虽然关闭了,但是有可能有一些旧报文由于某些原因延迟到达,这时候如果本地端口已经被新的连接使用,那可能造成歧义.

虽然销毁连接需要四次握手,但也能将其缩减至三次握手,当A发送一个FIN给B时,B回给A一个FIN&ACK报文(仅仅是将两步合成一步),然后A再回给B一个ACK即可.