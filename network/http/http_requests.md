http request,翻译自[这里](https://www.tutorialspoint.com/http/http_requests.htm)

http客户端会发送request给http服务端,这个request会遵循一定的格式,这种格式如下所示:
```shell
* A Request-line

* Zero or more header (General|Request|Entity) fields followed by CRLF

* An empty line (i.e., a line with nothing preceding the CRLF) 
indicating the end of the header fields

* Optionally a message-body
```

下面的部分将会讲解http request message的每一个部分

<font size=6>Request-Line</font>

