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
