# 有理数计算器
有理数计算器，用来进行有理数加减乘除的计算
## 问题描述：
有理数是一个可以化为一个分数的数，例如2/3，533/920，-12/49都是有理数，而就为无理数。在C++中，并没有预先定义有理数，需要时可以定义一个有理数类，将有理数的分子和分母分别存放在两个整型变量中。对有理数的各种操作都可以用重载运算符来实现。
## 基本要求：
定义并实现一个有理数类，通过重载运算符+、-、*、/对有理数进行算术运算，能够完成基本实数运算的同时，还可以求有理数的绝对值、有理数数的加、减、乘、除、乘方、自加、自减以及比较大小的运算等，自运算要求完成前置运算和后置运算，通过重载运算符==实现判定两个有理数是否相等。</br>
实现提示</br>
设有两个有理数a/b和c/d，则有：</br>
（1）	有理数相加  分子=a*d+b*c；分母=b*d</br>
（2）	有理数相减  分子=a*d-b*c；分母=b*d</br>
（3）	有理数相乘  分子=a*c；    分母=b*d</br>
（4）	有理数相除  分子=a*d；    分母=b*c</br>
（5）	重载>>,要求能够从键盘输入a/b形式的有理数，在程序中可以识别出分子和分母并进行赋值。</br>
（6）	重载<<，输出运算结果，其中有理数数以a/b的形式输出，要求输出的是约分之后的形式。</br>
（7）	设计用户使用计算器记录功能，可以记录下不同用户使用计算器的情况，记录以文件的形式保存在计算机内，每次程序运行时要求用户输入用户名，显示该名户以前的记录。用户记录用包括：做了多少次加减法、乘法、进行测试的次数，后3次的测试平均正确率等，在退出计算器程序时用心的用户记录代替原有的记录</br>
（8）	每次给用户随机出10道计算题，记录用户每次做题的日期，包括年月日和时间，将题目和用户运算结果以及正确结果和做题时间以文件的形式保存，并记录用户的准确率</br>。


### 使用说明
1. 这是一个用C++语言写的程序，使用VS2010进行调试。
2. 本程序涉及文件操作，以下**变量可在头部公共数据块看见**，具体路径请自行修改
   1. string uname_pwd_file = "user.txt";  //存储用户名和密码的文件位置
   2. string fName = "";//存放用户使用记录，这里只是进行了初始化，具体路径可使用Ctrl+F查找变量名之后进行修改。
   3. string FName = "";//存放临时数据，这里只是进行了初始化，具体路径可使用Ctrl+F查找变量名之后进行修改。
3. 本程序有有理数运算测试功能，为方便测试，我把答案输出了，如有需要，可在Test()方法中自行注释

### 写在最后
第一次写这么多行代码，难免有bug，本人qq 664474618，欢迎指出，我会及时修正。

    
   
