应用层的域名服务器(Domain Name Server,DNS),翻译自[这里](https://www.geeksforgeeks.org/domain-name-server-dns-in-application-layer/)

DNS是一个将主机名翻译成IP地址(host name to IP address translation)的服务.DNS是在一个具有层次结构的name servers中实现的分布式数据库.DNS是一个用于客户端和服务端信息交换的应用层协议.

**必要条件**:

每一个主机都由一个IP地址标识,另外由于这些数字难以记住并且不是静态的,因此用域名代替IP地址是十分有必要的.所以DNS是用来将网站的域名转换成IP地址的.

![DNS](../images/dns/dns_1.png)

要找到一个网站所对应的ip地址是非常困难的,因为域名有上百万个并且我们要在这上百万个域名中快速解析出对应的ip地址.不出现非常大的延迟是非常必要的.

**DNS Record** --  域名,ip地址,有效性,生存时间等所有关于对应的域名的信息全部存在类树结构中.

**Namespace** --  可能的名称集合或者层次结构.Naming system(命名系统)维护一个name to value的集合,给定一个名称,经过对应的解析机制就会返回一个对应的值.

**Name server**  --  这是解析机制(resolution mechanism)的实现,