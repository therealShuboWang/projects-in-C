## 图书管理系统


### 需求分析

**按照软件工程的要求，对要实现的图书管理系统进行详细的分析**：确定要让计算机做什么以及要达到什么样的效果。

根据需求分析的结果，可以将图书管理系统的主要功能归纳如下：

* 对于用户来说，其主要的需求是**根据自己掌握的有限的资料，来查询所有可能匹配的图书信息**。同时图书管理系统**应将查询到的结果对用户进行展示**。

* 对管理员来说，其主要的需求是**创建并维护整个图书管理系统**，常见的具体操作有：**录入图书信息**，**修改图书信息**，以及**删除不必要的图书信息**。


***


### 系统设计

**按照程序模块化设计的思想，将整个图书管理系统分成多个小的功能模块**：每个小的模块可以由不同的开发人员分别开发，之后再整合起来形成一个大的完整的系统。

根据系统设计的结果，可以将图书管理系统划分为6个功能模块：

* **录入图书模块(insert_item)**：录入图书模块的功能是**提示用户输入图书的相关信息，系统将这些信息整合在一起进行存储**。用户在录入图书信息时可以选择一次只录入一本图书，也可以选择一次录入多本图书的信息。

* **删除图书模块(delete_item)**：删除图书模块的功能是**根据用户输入的图书编号，将对应该编号的图书从管理系统中删除**。用户提供的图书编号信息可能有误，程序需要自行判断；同时程序要根据管理系统当前的具体情况，妥善地完成删除操作而不影响到其他书籍和整体系统的运作。

* **修改图书模块(modify_item)**：修改图书模块的功能是**根据用户输入的图书编号，在图书管理系统中检索到对应的图书；然后进一步提示用户修改相关的信息**。用户可以一次只修改该图书的一种信息，也可以一次修改该图书的多种信息，程序提供相应的询问机制来作出判断。

* **查询图书模块(search_item)**：查询图书模块的功能是**向用户提供可供选择的查询列表，用户选择其中一项并按要求输入查询信息，系统根据提供的信息检索并显示所有符合条件的图书**。该模块的功能又可以按照图书所包含的不同种类的信息再次细化为多个查询子模块，因此源文件`search_item.c`用来确定查询的整体逻辑架构，我们再创建一个与之对应的、包含子查询函数的源文件`separate_search.c`和包含函数原型的头文件`search.h`

* **显示图书模块(print_item)**：显示图书模块的功能是**如果系统为空，则输出提示信息；否则将存储在图书管理系统中的所有图书信息按存储顺序依次列出**。


***

### 还需改进的地方

**使用更为灵活和通用的方式接收用户的输入信息**：目前用户的每个输入信息都不能包含空白字符，改进后可以允许用户将用空格隔开的多个字符串当作一条信息录入，同时保证不影响其它信息的录入和程序整体的运行效果。

**优化搜索方式**：

* **按图书类别搜索时**：用户可以输入多个图书标签，程序将包含任意一个该标签的图书信息检索到并输出，同时按照符合标签数的多少对输出进行排序
* **按出版时间搜索时**：在输入时间信息时要进行格式的统一规定（如：xxxx-yy-zz），在搜索时允许用户指定年、月、日中的任何一个或它们的任意组合，程序同样按照符合要求的程度对输出进行排序

**增加图书文件模块**：将图书的信息保存在一个相关连的文件中（如：`book.txt`），对应不同的操作，文件内容都应该做出相应的增删改。（可以使用文件模块代替显示图书模块，即需要显示图书系统中的信息时，直接加载文件中的内容到屏幕上）





