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
<td><b>OPTIONS</b><p>Describe the communication options for the target resource.</p><p>OPTIONS请求方法的主要用途有两个：</p>
<p>1、获取服务器支持的HTTP请求方法；也是黑客经常使用的方法。</p>
<p>2、用来检查服务器的性能。例如：AJAX进行跨域请求时的预检，需要向另外一个域名的资源发送一个HTTP OPTIONS请求头，用以判断实际发送的请求是否安全。</p>
<p>3、参考自https://cloud.tencent.com/developer/article/1046663</p></td>
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



<table class="table table-bordered">
<tr>
<th>S.N.</th>
<th>Method and Description</th>
</tr>
<tr>
<td>1</td>
<td>The asterisk <b>*</b> is used when an HTTP request does not apply to a particular resource, but to the server itself, and is only allowed when the method used does not necessarily apply to a resource. For example:
<p><b>OPTIONS * HTTP/1.1</b></p></td>
</tr>
<tr>
<td>2</td>
<td>The <b>absoluteURI</b> is used when an HTTP request is being made to a proxy. The proxy is requested to forward the request or service from a valid cache, and return the response. For example:
<p><b>GET http://www.w3.org/pub/WWW/TheProject.html HTTP/1.1</b></p></td>
</tr>
<tr>
<td>3</td>
<td>The most common form of Request-URI is that used to identify a resource on an origin server or gateway. For example, a client wishing to retrieve a resource directly from the origin server would create a TCP connection to port 80 of the host "www.w3.org" and send the following lines:
<p><b>GET /pub/WWW/TheProject.html HTTP/1.1</b></p>
<p><b>Host: www.w3.org</b></p>
<p>Note that the absolute path cannot be empty; if none is present in the original URI, it MUST be given as "/" (the server root).</p>
</td>
</tr>
</table>

