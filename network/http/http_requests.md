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

request-line以一个method开始，随后跟着request-uri和协议版本，以CRLF结束。每个元素用空格隔开。

```shell
Request-Line = Method SP Request-URI SP HTTP-Version CRLF
```

让我们看看上面提及到的request-line中的每个部分

<font size=6>Request-Method</font>

request方法表明以什么方法去执行被**Request-URI**指定的资源。这个method不区分大小写并且应该总是大写的。下面这张表列举出了HTTP/1.1中支持的methods。

<table  border="1" cellspacing="0">
<tr>
<th></th>
<th></th>
</tr>
<tr>
<td><b>GET</b><p>The GET method is used to retrieve  information from the given server using a given URI.  Requests using GET should only retrieve data and should have no other effect on the data.</p></td>
</tr>
<tr>
<td><b>HEAD</b><p>Same as GET, but it transfers the status line and the header section only.</p></td>
</tr>
<tr>
<td><b>POST</b><p>A POST request is used to send data to the server, for example, customer information, file upload, etc. using HTML forms.</td></tr>
<tr>
<td><b>PUT</b><p>Replaces all the current representations of the target resource with the uploaded content.</p></td>
</tr>
<tr>
<td><b>DELETE</b><p>Removes all the current representations of the target resource given by URI.</p></td>
</tr>
<tr>
<td><b>CONNECT</b><p>Establishes a tunnel to the server identified by a given URI.</p></td>
</tr>
<tr>
<td><b>OPTIONS</b><p>Describe the communication options for the target resource.</p></td>
</tr>
<tr>
<td><b>TRACE</b><p>Performs a message loop back test along with the path to the target resource.</p></td>
</tr>
</table>

<font size=6>Request-URI</font>

Request-URI是统一资源标识符,用来标识请求的资源.下面是最常用的URI形式:

```
Request-URI = "*" | absoluteURI | abs_path | authority
```

