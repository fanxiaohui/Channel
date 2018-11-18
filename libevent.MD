[参考](https://yq.aliyun.com/articles/413601)

[libevent官网](http://libevent.org/)
The libevent API provides a mechanism to execute a callback function when a specific event occurs on a file descriptor or after a timeout has been reached. Furthermore, libevent also support callbacks due to signals or regular timeouts.
libevent is meant to replace the event loop found in event driven network servers. An application just needs to call event_dispatch() and then add or remove events dynamically without having to change the event loop.

Currently, libevent supports /dev/poll, kqueue(2), event ports, POSIX select(2), Windows select(), poll(2), and epoll(4). The internal event mechanism is completely independent of the exposed event API, and a simple update of libevent can provide new functionality without having to redesign the applications. As a result, Libevent allows for portable application development and provides the most scalable event notification mechanism available on an operating system. Libevent can also be used for multi-threaded applications, either by isolating each event_base so that only a single thread accesses it, or by locked access to a single shared event_base. Libevent should compile on Linux, *BSD, Mac OS X, Solaris, Windows, and more.

Libevent additionally provides a sophisticated framework for buffered network IO, with support for sockets, filters, rate-limiting, SSL, zero-copy file transmission, and IOCP. Libevent includes support for several useful protocols, including DNS, HTTP, and a minimal RPC framework.

More information about event notification mechanisms for network servers can be found on Dan Kegel's "The C10K problem" web page.

在mac上安装libevent
先去[官网下载stable版本](http://libevent.org/)
libevent-2.0.22-stable.tar.gz
tar -xvf libevent-2.0.22-stable.tar.gz
cd libevent-2.0.22-stable

./configure && make  
sudo make install

//假如上面两步出错了
export CPPFLAGS=-I/usr/local/opt/openssl/include
export LDFLAGS=-L/usr/local/opt/openssl/lib
./configure
./make

[ibm的一篇文章中介绍了应对大量连接的常用解决方案](https://www.ibm.com/developerworks/aix/library/au-libev/index.html)
Round-robin: The early systems use a simple solution of round-robin selection, simply iterating over a list of open network connections and determining whether there is any data to read. This is both slow (especially as the number of connections increases) and inefficient (since other connections may be sending requests and expecting responses while you are servicing the current one). The other connections have to wait while you iterate through each one. If you have 100 connections and only one has data, you still have to work through the other 99 to get to the one that needs servicing.

poll, epoll, and variations: This uses a modification of the round-robin approach, using a structure to hold an array of each of the connections to be monitored, with a callback mechanism so that when data is identified on a network socket, the handling function is called. The problem with poll is that the size of the structure can be quite large, and modifying the structure as you add new network connections to the list can increase the load and affect performance.

select: The select() function call uses a static structure, which had previously been hard-coded to a relatively small number (1024 connections), which makes it impractical for very large deployments.


[libevent文档](http://www.wangafu.net/~nickm/libevent-book/)
libevent是一个事件触发的网络库，适用于windows、Linux、bsd等多种平台，内部使用select、epoll、kqueue等系统调用管理事件机制。著名分布式缓存软件memcached也是libevent based，而且libevent在使用上可以做到跨平台

Libevent 中，事件循环是围绕着event_base结构体进行的

基本的socket编程是阻塞/同步的，每个操作除非已经完成或者出错才会返回，这样对于每一个请求，要使用一个线程或者单独的进程去处理，系统资源没法支撑大量的请求（所谓c10k problem?），例如内存：默认情况下每个线程需要占用2～8M的栈空间。posix定义了可以使用异步的select系统调用，但是因为其采用了轮询的方式来判断某个fd是否变成active，效率不高[O(n)]，连接数一多，也还是撑不住。于是各系统分别提出了基于异步/callback的系统调用，例如Linux的epoll，BSD的kqueue，Windows的IOCP。由于在内核层面做了支持，所以可以用O(1)的效率查找到active的fd。基本上，libevent就是对这些高效IO的封装，提供统一的API，简化开发。
libevent大概是这样的：

    默认情况下是单线程的（可以配置成多线程，如果有需要的话），每个线程有且只有一个event_base，对应一个struct event_base结构体（以及附于其上的事件管理器），用来schedule托管给它的一系列event，可以和操作系统的进程管理类比，当然，要更简单一点。当一个事件发生后，event_base会在合适的时间（不一定是立即）去调用绑定在这个事件上的函数（传入一些预定义的参数，以及在绑定时指定的一个参数），直到这个函数执行完，再返回schedule其他事件。


//创建一个event_base 
struct event *event_new(struct event_base *base, // 事件循环
                        evutil_socket_t fd,      // 文件描述符
                        short what,              // 事件类型
                        event_callback_fn cb,    // 回调函数
                        void *arg);              // 传递给回调函数的参数

//创建一个event并把它加入到事件循环中
int event_add(struct event *ev,             // 事件
              const struct timeval *tv);    // 超时时间


//启动事件循环 
event_base_dispatch(base); 

默认情况下，当一个事件变得活跃时，Libevent 会执行这个事件的回调函数，但同时也会将这个事件从事件循环中移除。那要怎么样才能让事件不被移除呢？当创建事件时，在事件类型加上EV_PERSIST就可以
event_new(base, -1, EV_TIMEOUT|EV_PERSIST, timer_cb, (void *)&str);



[libevent内置了http功能，还有dns这类](http://www.voidcn.com/article/p-tvsexrgk-pz.html)