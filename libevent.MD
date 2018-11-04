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


[libevent文档](http://www.wangafu.net/~nickm/libevent-book/)
libevent是一个事件触发的网络库，适用于windows、Linux、bsd等多种平台，内部使用select、epoll、kqueue等系统调用管理事件机制。著名分布式缓存软件memcached也是libevent based，而且libevent在使用上可以做到跨平台


基本的socket编程是阻塞/同步的，每个操作除非已经完成或者出错才会返回，这样对于每一个请求，要使用一个线程或者单独的进程去处理，系统资源没法支撑大量的请求（所谓c10k problem?），例如内存：默认情况下每个线程需要占用2～8M的栈空间。posix定义了可以使用异步的select系统调用，但是因为其采用了轮询的方式来判断某个fd是否变成active，效率不高[O(n)]，连接数一多，也还是撑不住。于是各系统分别提出了基于异步/callback的系统调用，例如Linux的epoll，BSD的kqueue，Windows的IOCP。由于在内核层面做了支持，所以可以用O(1)的效率查找到active的fd。基本上，libevent就是对这些高效IO的封装，提供统一的API，简化开发。
libevent大概是这样的：

    默认情况下是单线程的（可以配置成多线程，如果有需要的话），每个线程有且只有一个event_base，对应一个struct event_base结构体（以及附于其上的事件管理器），用来schedule托管给它的一系列event，可以和操作系统的进程管理类比，当然，要更简单一点。当一个事件发生后，event_base会在合适的时间（不一定是立即）去调用绑定在这个事件上的函数（传入一些预定义的参数，以及在绑定时指定的一个参数），直到这个函数执行完，再返回schedule其他事件。


//创建一个event_base 
struct event_base *base = event_base_new(); 
assert(base != NULL); 

//创建并绑定一个event 
struct event *listen_event; 
//参数：event_base, 监听的fd，事件类型及属性，绑定的回调函数，给回调函数的参数 
listen_event = event_new(base, listener, EV_READ|EV_PERSIST, callback_func, (void*)base); 
//参数：event，超时时间(struct timeval *类型的，NULL表示无超时设置) 
event_add(listen_event, NULL); 

//启动事件循环 
event_base_dispatch(base); 


