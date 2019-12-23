http与https的不同点?节选自[这里](https://www.keycdn.com/blog/difference-between-http-and-https)

1. HTTP URL in your browser’s address bar is `http://` and the HTTPS URL is `https://`.
2. HTTP is unsecured while HTTPS is secured.
3. HTTP sends data over port 80 while HTTPS uses port 443.
4. HTTP operates at application layer, while HTTPS operates at transport layer.(这一点有点问题,为什么说https在传输层工作呢?)
5. No SSL certificates are required for HTTP, with HTTPS it is required that you have an SSL certificate and it is signed by a CA.
6. HTTP doesn’t require domain validation, where as HTTPS requires at least domain validation and certain certificates even require legal document validation.
7. No encryption in HTTP, with HTTPS the data is encrypted before sending.