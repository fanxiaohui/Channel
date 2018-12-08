- [c language api index](http://www.cplusplus.com/reference/cstdio/sprintf/)

- [c_stand_library](https://www.tutorialspoint.com/c_standard_library/index.htm)


- [string相关的函数](https://github.com/Haldir65/Channel/blob/master/String.MD)


- [make file怎么写](https://github.com/Haldir65/Channel/blob/master/HowTowriteMakeFile.MD)


- [结构体的使用方式](https://github.com/Haldir65/Channel/blob/master/Struct.MD)

- [文件I/O操作](https://github.com/Haldir65/Channel/blob/master/FileIo.MD)

- [但是实际应用中都有很成熟的argument parser了，用Getopt就好了](https://stackoverflow.com/questions/9642732/parsing-command-line-arguments) 


c/c++是编译语言，做不到“一次编译到处运行”，这里的“到处”指的是不同编译器或不同系统
因为程序的大多数功能都需要调用编译器提供的库函数，使用操作系统提供的系统资源和API等，这些在不同编译器或不同系统上都是不同的
所以一般的方法是通过预编译宏来处理这一类需求，在不同的系统上使用不同的宏来编译同一个文件里不同版本的代码，来做到“一次编写到处编译”

看到有人在segmentfault说了这样一段总结，很以为然
对于编程语言，基本上是这样进化的：

1. 先用机器语言写出汇编器，然后就可以用汇编语言编程了，然后再用汇编语言编写汇编器。

2. 先用汇编语言写出 C 编译器，然后就可以用 C 语言编程了，然后再用 C 语言来写 C 编译器。

3. 有了 C 编译器与 C 语言，就可以在这个基础上再编写高级语言的编译器或解释器或虚拟机了。

4. 非 C 系语言，进化过程同上。

至于操作系统，先用汇编语言写一个操作系统。Ken Thompson 干过这样的事，他用汇编语言以及他自创的一种解释性语言——B 语言写出来 unix 第一版，是在一台内存只有 8KB 的废弃的计算机上写出来的。然后 Dennis Ritchie 发明了 C 语言，然后 Ken 与 Dennis 又用 C 语言在一台更好的计算机——16 位机器上将 unix 重写了一遍。

至于 Windows 系统，MS 先是买了 QDOS，然后又在 QDOS 里引入了一些 Unix 的元素，然后比尔·盖茨靠着这个买来的系统赚了一大笔钱，然后就在 DOS 系统上开发了 windows 3.1，windows 95 ……