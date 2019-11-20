翻译自[这里](https://www.tutorialspoint.com/http/http_messages.htm):

http是基于client-server架构的无状态request/response协议,通过可靠的TCP/IP连接来交换message.

http客户端是一个程序(可能是网络浏览器或者其他客户端),用来向服务端建立连接以发送http request messages.

http服务端是一个程序(通常来说是像Apache Web Server或者Internet Information Services IIS这样的web服务),用来接收并处理http request然后对其返回response messages.

http使用**Uniform Resource Identifier (URI)**表示一个资源并且使用URI建立一个连接.一旦连接建立,http messages就会被传送出去,此时**http messages**的格式跟Internet mail [RFC5322] 和Multipurpose Internet Mail Extensions (MIME) [RFC2045]这两种协议使用的格式类似.这些从客户端发往服务端或者从服务端发送客户端的http messages的格式如下:

```http
HTTP-message   = <Request> | <Response> ; HTTP/1.1 messages
```

http requests和http responses使用RFC 822中定义的message格式去传输或者请求数据.这种通用 message 格式由以下四个部分组成:

- A Start-line(起始行)
- Zero or more header fields followed by CRLF (0个或者多个头部字段,其后跟着换行符)
- An empty line (i.e., a line with nothing preceding the CRLF)  indicating the end of the header fields
  (空行(即在CRLF之前没有任何内容的行), 表明header字段的结束)
- Optionally a message-body(消息体,这是可选的)

下面我们将会讲解http message中使用到的四个部分

**Message Start-Line**

开始行遵循以下的语法

```http
start-line = Request-Line | Status-Line
```

我们将在讨论http request和http response的时候讨论Request-Line和Status-Line.现在让我们看看request和response中起始行的例子

```http
GET /hello.htm HTTP/1.1     (This is Request-Line sent by the client)

HTTP/1.1 200 OK             (This is Status-Line sent by the server)
```

**Header 字段**

http header字段提供有关于request,response或者message body里面消息对象的必要信息.以下展示了四中http message header:

* General-header: 这种header字段在request message和response message中都可以使用
* Request-header:这种header字段只能在request message中使用
* Response-header:这种header字段只能在response message中使用
* Entity-header:这种header字段用来给出entity-body的元数据信息,如果没有entity-body,则给出由URI所标识的资源的元信息.

上述提及到的headers都遵循一个通用的格式,每一个header字段由"名称+:+值"组成,如下所示:

```http
message-header = field-name ":" [ field-value ]
```

下面是一些各种类型的header字段

```http
User-Agent: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3
Host: www.example.com
Accept-Language: en, mi
Date: Mon, 27 Jul 2009 12:28:53 GMT
Server: Apache
Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT
ETag: "34aa387-d-1568eb00"
Accept-Ranges: bytes
Content-Length: 51
Vary: Accept-Encoding
Content-Type: text/plain
```

**Message Body(消息体)**

消息体这一部分对于http message来说是可选的,但如果消息体被使用了的话,它是用来承载与request或者response有关的entity-body(消息实体).如果有设置entity body的话,通常也会将entity body相关的值赋值给Content-Type和Content-Length这两个header字段.

message body才是真正承载http request数据(包括form表达数据和上传数据等)和来自服务端http response数据(包括文件,图像等).下面展示的是简单的message body的简单文本.

```html
<html>
   <body>
   
      <h1>Hello, World!</h1>
   
   </body>
</html>
```

下面两个章节我们将会讨论http request和http response.



headers参考资料:https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Headers

* General-header参考资料:https://developer.mozilla.org/en-US/docs/Glossary/General_header

* Request-header参考资料:https://developer.mozilla.org/en-US/docs/Glossary/Request_header

* Response-header参考资料:https://developer.mozilla.org/en-US/docs/Glossary/Response_header

* Entity-header参考资料:https://developer.mozilla.org/en-US/docs/Glossary/Entity_header

* 总结:
  1. request-header指的是客户端向服务端发送的http message中的headers,这个headers由多个header组成,header其实就是类似于*accept: /*,*accept-encoding: gzip, deflate,*这样的键值对.
  2. response-header指的是服务端向客户端发送的http message中的headers,这个headers由多个header组成,header其实就是类似于*Server: Apache*这样的键值对.
  3. General header类似于*cache-control: max-age=0, no-cache, no-store, must-revalidate*这样的键值对.
  4. Entity header类似于*Content-Length: 128*这样的键值对
  5. headers其实主要分为request header和response header这两大块
  6. 至于General header和Entity header都可以和Request-header&Response-header搭配使用.如果在Request的headers中使用了Entity header,那么在这样的情况下Entity header也被称为request headers.如果在Response的headers中使用了Entity header,那么在这样的情况下Entity header也被称为response headers.
  7. 之所以会有Entity header和General header这两个名词估计是因为在request和response中都使用到了相同的header,所以可能就单独抽出来作为一个专门的Entity header和General header吧.