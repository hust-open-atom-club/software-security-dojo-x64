利用缓冲区溢出漏洞，可以在栈、全局、堆等内存区域上输入精心构造的数据载荷（即，Payload），覆盖关键数据（如，局部变量，函数指针，返回地址等）。  
**注：为了更有效地解决这些挑战关卡，你首先需要运行 /challenge 目录下的挑战题目，随后根据提示完成挑战。**
\
\
**关卡等级分布：**
- Level 1.0 - 利用栈溢出覆盖局部变量，通过检查后读取 /flag
- Level 1.1 - 利用栈溢出覆盖局部函数指针变量，劫持控制流来读取 /flag
- Level 1.2 - 利用栈溢出覆盖局部数据指针变量，劫持控制流来读取 /flag
- Level 1.3 - 利用栈溢出覆盖返回地址，劫持控制流来读取 /flag
- Level 1.4 - 利用栈溢出覆盖局部布尔变量，翻转逻辑来读取 /flag
- Level 2.0 - 利用堆缓冲区溢出覆盖堆上数据变量，劫持控制流来读取 /flag
- Level 2.1 - 利用堆缓冲区溢出覆盖堆上函数指针，劫持控制流来读取 /flag
- Level 3.0 - 利用 Off-By-One 漏洞覆盖栈上数据，通过检查后读取 /flag
- Level 3.1 - 利用 Off-By-Null 漏洞覆盖栈上关键变量，劫持控制流后读取 /flag
- Level 4.0 - 利用 cylic 和 coredump 来自动计算返回地址的位置，劫持控制流后读取 /flag

References
- [Use pwntools for your exploits](https://mudongliang.github.io/2021/05/11/use-pwntools-for-your-exploits.html)