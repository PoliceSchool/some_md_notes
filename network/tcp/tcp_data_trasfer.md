TCP数据传输,翻译自[这里](https://www.inetdaemon.com/tutorials/internet/tcp/data_transfer.shtml)

一旦3次握手完成,连接建立之后,TCP会通知应用层开始数据传输和通讯.TCP用以下方法处理数据:

1. 使用HTTP,SMTP,POP3,FTP等协议的应用会将信息传到TCP层,TCP将应用层传来的message(信息)拆分成多个segment(段)
2. 随后TCP将这些segment(message pieces)传到其他主机上
3. 其他主机上的TCP层将接收到的segments重组,另外,这些segments在接收的时候是乱序的.

总结:TCP将应用层的数据分成多个segment,并且给应用层的数据打上标签,然后在协议栈里向下传输到网络层,数据链路层和物理层.

因为主机接收TCP segments的时候总是会发送ACKnowledgements(确认消息)给发送端,所以TCP总是知道连接的状态.