TCP的可靠性,翻译自[这里](https://www.inetdaemon.com/tutorials/internet/tcp/reliability.shtml)

TCP会对遗失的,损坏的,重复的或者乱序的segment进行修复.之所以TCP被称为可靠的协议就是因为它会试着去修复这些错误.

TCP会用sequence number(序列号)标记每一个segment，并以此来保证每个segment的顺序．这些序列号使得TCP能够检测出那些segment遗失了．TCP同时也要求在传输完数据之后要返回一个acknowledge message（确认信息）．

为了保证segments没有被损坏，在每一个segment发送或者接收的时候都要经过CRC(循环冗余检验)校验．因为每一个packet有一个time to live（生存时间）字段，并且在转发的过程中这个字段会递减，TCP必须在每一个hop（每一跳）重新计算这个CRC．如果重新计算的 CRC跟segment的不一致的话，这个segment会被丢弃．