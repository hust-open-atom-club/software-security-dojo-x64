ROP(Return Oriented Programming) 通过控制程序栈上数据串连 gadgets（如，末尾为 ret 指令的微小代码片段）来达到图灵完备的功能。  
**注：为了更有效地解决这些挑战关卡，你首先需要运行 /challenge 目录下的挑战题目，随后根据提示完成挑战。**
\
\
**关卡等级分布：**
- Level 1.0 - 本关卡需学习利用栈溢出，构造 ROP 链控制函数参数，来读取 /flag
- Level 1.1 - 本关卡需学习 ret2syscall 劫持控制流，构造 ROP 链来读取 /flag
- Level 2.0 - 本关卡需学习 ret2libc，利用 ELF 现有函数劫持控制流，构造 ROP 链来读取 /flag
- Level 2.1 - 本关卡需学习 ret2libc，利用 libc 函数，构造 ROP 链来读取 /flag
- Level 2.2 - 本关卡需学习 ret2libc，泄露并利用 libc 函数，构造 ROP 链来读取 /flag
- Level 2.3 - 本关卡需学习 ret2libc，利用缓冲区溢出和格式化字符串漏洞，构造 ROP 链来读取 /flag
- Level 2.4 - 本关卡需学习 ret2libc，仅利用格式化字符串漏洞，绕过保护机制，构造 ROP 链来读取 /flag
