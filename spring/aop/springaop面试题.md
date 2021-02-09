1. 什么是java动态代理?

2. 什么是cglib?

3. spring aop使用的是java动态代理还是cglib代理?
   答:这取决于被代理的类是否实现了接口,如果实现了接口,spring aop使用的是java动态代理;如果没有实现接口,那么spring aop使用的是cglib代理.
   查看源码:org.springframework.aop.framework.DefaultAopProxyFactory#createAopProxy

4. sping aop在什么时候将原生类替换成代理类的?
   查看源码:org.springframework.aop.framework.DefaultAopProxyFactory#createAopProxy
5. 为什么java动态代理必须是接口?
   因为是java是单继承多实现的,被代理的对象默认实现了java的proxy类

参考连接:https://www.bilibili.com/video/av81268629?p=1
