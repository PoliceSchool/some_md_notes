什么是CORS?翻译自[这里](https://www.codecademy.com/articles/what-is-cors?__cf_chl_captcha_tk__=34564ec71b2c2ccbc757c778b5aeded8bee5decb-1575186832-0-AXRY4rjzoXEA32k0Et3ZpUHVcv7Ttve8Ac1449X6VNHJnNn6L2tQBYd-JeWNAvDhW9KdQb82Iu2vo4jOq3js81qmnaAkIXJspPfarmZqgtMIwxsTkBqWCXn65M-6ruWimI7PGK2L92ZzCyc9Ks9E2CE8klL-iaqNWjCisPpZk2hMoeKC-7TWX1liRIwMrviFuauAIeQQ9A-o4J_txVWCrGuT0hEAaYxkIXM1yvXhEPOgQwPZpmvk_gn0KiT1v4Gi_y7rqVlI4dSSJUXIPxVT_fgXBs5NlyDo60DUdn5Vvfnx9wWMLsKpW0UooSWiYxaskTRGK2EsHReOC-uQtGvqBzTSJu60fm9R1VA-qCTF8PW9LjpM90q2H1JIplE_i_Je03Z3d_Ahaj3jLucen_nvdbE)

<font size=6>什么是CORS?</font>

服务器上的资源(比如页面)经常需要发送请求到其他服务器上以加载某些资源.在这片文章,你将会学到这些请求如何用CORS管理.

虽然你可能没有注意到,但是你浏览的网络页面正在频繁的通过网络从不同的地方请求加载图片,样式等诸如此类的配置信息.如果这些加载配置的请求没有经过检查,那你的浏览器可能就危险了.比如的你的浏览器可能会被劫持,或者你的浏览器可能会盲目的下载恶意代码.为了应对这种情况,许多现代的浏览器都采用了*security policies*去减轻这种风险.

<font size=6>什么是security policies?</font>

服务器用于托管网络页面,应用,图像,样式等东西.当你使用web浏览器的时候,你可能会进入某个网站(托管在一台服务器上面).网站经常会请求那些托管在网路上不同位置(服务器)的资源.服务器上的*security policies*减轻了向不同服务器上请求配置的相关风险.让我们看看*security policies*的一个栗子:same-origin(同源,同域).

*same-origin policy*非常严格.在这个政策的标准下,托管在服务器A的文件(比如一个web页面)只能跟其他也托管在服务器A下的文件进行交互.简而言之,*same-origin policy*强制文件只能跟具有一样的origin的文件进行交互.

那origin是什么呢?origin由以下3个部分组成:protocol(协议),host(域名),port number(端口号).这3个部分的细节现在不需要了解,但是了解*same-origin policy*如何使用这些部分确实很重要的.

看下列的URL
```
http://www.example.com/foo-bar.html
```

让我们把它简短的称为**URL1**.

如果你使用浏览器从URL1导航至<u>http://www.example.com/hello-world.html</u>的话,这样做是合法的.因为协议(HTTP),域名(example.com)和端口号(80)都是一样的.*same-origin policy*要求origin的每一个部分都要一样.

然而,如果从URL1导航至<u>https://www.en.example.com/hello.html</u>的话,这样做是不合法的,因为协议(HTTPS)和域名(en.example.com)都不一样.

正如你所见,没有*security policies*可能会有风险,但是*same-origin policy*又非常严格.所以就出现了另一种*security policies*.这种*security policies*将所有的问题都考虑到了,那就是*cross-origin*(跨源,跨域).*cross-origin*已经演变成*cross-origin resource sharing* 标准,经常被缩写为CORS.

![img](../images/http/same-origin.svg)

<font size=6>什么是CORS?</font>

请求不同origin资源的request被称为*cross-origin* request(跨域请求).CORS (cross-origin resource sharing)管理这些跨域请求.

再一次看下列的URL:
```
http://www.example.com/foo-bar.html
```

让我们把它简短的称为URL1

不像 *same-origin*,在CORS下从URL1是可以导航至*https://www.ejemplo.com/hola.html*的.允许这些跨域请求是有用的,因为现在许多网站通过网络从不同的地方加载资源(样式,脚本,图像等等).

然而,允许跨域请求就意味着服务器要实现某种方式以处理这些外部域请求.CORS允许服务器指定谁(也即是origin)能够访问本服务器上的配置以及其他东西.