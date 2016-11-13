# menu
A universal command line subsystem for menu

#声明：
此项目时来源于中科大软件学院孟宁老师的高级软件工程的课程项目。

项目的最终目标是：生成一个通用的命令行菜单子系统，以便于在不同的项目中使用。

#version1.0:
使用最简单直观的方式实现菜单系统，即通过调用不同的函数来实现对命令的执行。代码如menu.c所示。

#version2.0:
用模块化的思想实现菜单程序，把实现代码的业务逻辑和数据存储之间的分离，即将系统抽象为两个层级：菜单业务逻辑和菜单数据存储。基于这个目标，我们定义了一个Datanode的数据结构，用来定义菜单中每个子项的格式。在业务逻辑层，定义FindCmd（）ShowAllCmd（）两个函数，分别用于对菜单中子项的查找和显示所有的可以实现的命令。我们把Datanode的定义和这两个函数的声明放在linklist.h头文件中，而把这两个函数的具体实现过程放在linklist.c中。

#version3.0:
将通用的linktable模块集成到menu程序中。使用linktable模块相当于将内容装进盒子里，利用C中指针，通过定义对盒子的操作来实现对具体的操作，并具有通用性。

#version4.0:
在linktable中增加seach功能，使得linktable变得更加通用，在这里我们使用callback方式的接口，即search的判断条件condition（）函数定义在menu.c中，
当condition返回为success时，表示成功搜索到。而condition（）的输入由search提供。一个形象的比喻就是卧底。即condition（）是linktable放在menu.c中的卧底，卧底对linktable中的信息在menu.c中进行验证，并把结果返回linktable中。此外，我们在linktable.h中只保留对链表和链表节点的数据结构的声明，具体的实现放在linktable.c中。以实现对接口信息的隐藏。

#version5.0:
在之前的版本中，我们直接在menu.c中向menu中添加功能，并初始化。为了使menu子程序变的更加通用，可以只在menu.c中添加一个MenuConfig()函数，用来实现向menu中添加项目的功能，具体要添加的项目，可以通过第三方程序调用这个函数来实现。因为menu是要用做一个可以被嵌入到其他程序中的可通用的模块，因此，将原来的main()函数重命名为ExcuteMenu()。通过调用ExcuteMenu()来调用menu模块。
在编译含有多个源文件的程序时，使用make来对源文件编译和管理是一种很高效的做法。我们这里创建一个MakeFile文件来使用make编译源文件，并可以用make clean命令清除生成的中间文件。
为使menu中的命令支持带参数，需要对函数采用类似main(int argc,char * argv[])的方式，使用getopt()函数来分析命令行参数。然后对不同的参数情况分别定义不同的处理。
至此，一个通用的命令行菜单子系统已经完成。
