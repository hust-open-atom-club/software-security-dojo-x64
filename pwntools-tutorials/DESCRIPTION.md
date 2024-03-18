Pwntools 是一个工具包（包含各种好用的小工具）与软件库，旨在尽可能简化 CTF 比赛的渗透攻击过程，同时尽可能攻击代码的可读性。  
**注：为了更有效地解决这些挑战关卡，你首先需要运行 /challenge 目录下的挑战题目，随后根据提示完成挑战。**

**关卡等级分布：**
- Level 1.0 - 利用 pwntools 生成特定输入绕过检查，并读取 /flag
- Level 1.1 - 利用 pwntools 生成特定输入绕过检查，并读取 /flag
- Level 2.0 - 利用 pwtools asm 生成特定指令来设置特定寄存器，通过检查后获取 /flag
- Level 2.1 - 利用 pwtools asm 生成特定指令来交换特定寄存器，通过检查后获取 /flag
- Level 2.2 - 利用 pwtools asm 生成特定指令来计算特定公式，结果通过检查后获取 /flag
- Level 2.3 - 利用 pwtools asm 生成特定指令来设置特定全局数据区域，通过检查后获取 /flag
- Level 2.4 - 利用 pwtools asm 生成特定指令来设置特定栈内存区域，通过检查后获取 /flag
- Level 2.5 - 利用 pwtools asm 利用 if 语句来计算特定公式，结果通过检查后获取 /flag
- Level 2.6 - 利用 pwtools asm 利用 for 循环来计算特定公式，结果通过检查后获取 /flag
- Level 3.0 - 利用 pwtools 循环生成特定输入绕过检查，并读取 /flag
- 除此之外，pwntools 还有一些其他功能，如 ELF 解析（elf-crackme 关卡会用到），cyclic（缓冲区溢出关卡会用到）以及 GDB 调试等。


References
- [Pwntools Tutorials](https://github.com/Gallopsled/pwntools-tutorial)
- [Pwntools Documentation](https://docs.pwntools.com/en/stable/index.html)
- [GDB Cheat Sheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
