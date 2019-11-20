http 参数,翻译自[这里](https://www.tutorialspoint.com/http/http_parameters.htm)

这一章将要展示一些http重要的参数和在通讯过程中怎么使用这些参数的语法.例如,日期的格式,URL的格式等待.在编写客户端或者服务端程序的时候这将有益于你构建你的request和response信息.你将会在接下来的章节中看到这些参数的完整用法.

**HTTP Version**

http使用<major>.<minor>编码方案来指明协议的版本.一个http 消息的版本由第一行的HTTP-Version字段给出.下面是指明http版本号的通用语法

```http
HTTP-Version   = "HTTP" "/" 1*DIGIT "." 1*DIGIT
```

**例子:**

```http
HTTP/1.0

or

HTTP/1.1
```

**Uniform Resource Identifiers**(统一资源标识符)

Uniform Resource Identifiers(URI)是简单格式化的,不区分大小写的字符串,包含名称,位置等信息.一个http的语法如下所示:

```http
URI = "http:" "//" host [ ":" port ] [ abs_path [ "?" query ]]
```

这里如果端口号是空的或者没有给出来,http将使用默认的80端口.如果**abs_path**为空,那么默认使用"/"为**abs_path**.**abs_path**中的字符与其想对应的十六进制编码等价.

**例如:**

```http
http://abc.com:80/~smith/home.html
http://ABC.com/%7Esmith/home.html
http://ABC.com:/%7esmith/home.html
```

**时间格式**

所有的http时间戳必须用Greenwich时间表示.http应用允许使用以下三种时间戳的表示方法:

```http
Sun, 06 Nov 1994 08:49:37 GMT  ; RFC 822, updated by RFC 1123
Sunday, 06-Nov-94 08:49:37 GMT ; RFC 850, obsoleted by RFC 1036
Sun Nov  6 08:49:37 1994       ; ANSI C's asctime() format
```

**字符集**

我们使用character sets指定客户端想要的字符集.多个字符集能够用逗号隔开.如果没有设置值那么默认值为US-ASCLL.

例如:

```http
US-ASCII

or

ISO-8859-1

or 

ISO-8859-7
```

**Content Encondings(文本编码**)

在把文本传输到网络前,http会将文本按照某种编码方式进行编码,而content encoding的值表示使用什么编码算法对文本进行编码.content coding主要用来压缩文档或者其他有用的用途.

所有content-coding的值不区分大小写,http/1.1在Accept-Encoding和Content-Encoding这两个header字段中设置编码方式.这两个字段我们在后续的章节中会看到

例如:

```http
Accept-encoding: gzip

or

Accept-encoding: compress

or 

Accept-encoding: deflate
```

**Media 类型**

http使用**Content-Type**和**Accept**这两个header字段中的Media类型以提供可拓展的数据类型和类型协议.所有的Media类型都已在Internet Assigned Number Authority (IANA)登记过了.指定media类型的通用语法如下:

```http
media-type     = type "/" subtype *( ";" parameter )
```

例如:

```http
Accept: image/gif
```

**语言标签**

http通过**Accept-Language**和**Content-Language**这两个字段使用语言标签.一个语言标签由一个或多个部分组成:一个主标签和一个子标签(子标签可为空):

```http
language-tag  = primary-tag *( "-" subtag )
```

在这个标签内不允许出现空格,并且所有的标签都是不区分大小写的.

例如:

```http
en, en-US, en-cockney, i-cherokee, x-pig-latin
```

