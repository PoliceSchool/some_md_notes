翻译自[这里](https://www.inetdaemon.com/tutorials/internet/tcp/index.shtml)

传输控制协议是传输层主机之间的协议,能让IP网络中任意两个节点建立可靠的和面向连接的通信.TCP使用虚拟的端口建立虚拟的端到端的连接,也能重用两台电脑之间的物理连接.TCP被封装在IP数据报中的data字段里,而TCP则封装诸如HTTP,SMTP等更高层级的协议数据.

1. 传输控制协议特征
   1. TCP 数据传输
   2. TCP 的可靠性
   3. TCP 的流量控制
   4. TCP 的多路复用
   5. 面向TCP连接的通讯
   6. TCP 的优先级和安全性
2. 传输控制协议操作
   1. TCP 分段和重组
   2. TCP  的连接建立 --- 三次握手协议
3. 传输控制协议包接口
   1. TCP 包头部结构