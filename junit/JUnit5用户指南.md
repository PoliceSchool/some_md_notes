# JUnit 用户指南

## 1.概述

(翻译自[这里](https://junit.org/junit5/docs/current/user-guide/),英文不好,仅为自己记录使用)

这份文件旨在与为程序员编写测试用例提供全面的参考文档.

这份文件同样可作为[PDF文件](https://junit.org/junit5/docs/current/user-guide/index.pdf)下载.

### 1.1 什么是JUnit5?

与之前的JUnit版本不同的是,JUnit5现在由三个不同的子模块组成.

***JUnit5 = JUnit Platform + JUnit Jupiter + JUnit Vintage***

**JUnit Platform**是一个支撑平台,用来在JVM平台上启动测试框架([launching testing frameworks](https://junit.org/junit5/docs/current/user-guide/#launcher-api)).为了开发能够运行在支撑平台上面的测试框架,它定义了[TestEngine API](https://junit.org/junit5/docs/current/api/org/junit/platform/engine/TestEngine.html).支撑平台提供了 [Console Launcher](https://junit.org/junit5/docs/current/user-guide/#running-tests-console-launcher)用来在命令行中启动支撑平台.同时,支撑平台也提供了**基于JUnit4的运行器**( [JUnit 4 based Runner](https://junit.org/junit5/docs/current/user-guide/#running-tests-junit-platform-runner) ),用来运行所有基于JUnit4的TestEngine.对JUnit Platform支持最好的包括IntelliJ IDEA,Eclipse,NetBeans和VS Code等IDE,还包括Gradle,Maven,Ant等构建工具.

JUnit Jupiter由新的 [programming model](https://junit.org/junit5/docs/current/user-guide/#writing-tests) 和 [extension model](https://junit.org/junit5/docs/current/user-guide/#extensions) 组成,用来编写测试用例以及JUnit5的拓展.Jupiter的子项目提供了**TestEngine,**用来在支撑平台上运行基于Jupiter的测试用例.

JUnit Vintage提供了TestEngine,用来在支撑平台上运行基于JUnit3和JUnit4的测试用例.