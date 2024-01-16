学习并修改 ELF 可执行文件格式  
**注：为了更有效地解决这些挑战关卡，你首先需要执行 utility.py 查看关卡提示，根据提示信息利用 utility.py 修改关卡可执行文件，通过检查后即可获取 flag。**
\
\
**关卡等级分布：**
- Level 1.0 - 学习并理解 ELF 文件头，修复关卡可执行文件，通过检查后读取 /flag
- Level 1.1 - 学习并理解程序头表，修复关卡可执行文件，通过检查后读取 /flag
- Level 1.2 - 学习并理解节头表，修复关卡可执行文件，通过检查后读取 /flag
- Level 2.0 - 学习并理解 .text 段，修复关卡可执行文件，通过检查后读取 /flag
- Level 2.1 - 学习并理解 .data 段，修复关卡可执行文件，通过检查后读取 /flag
- Level 2.2 - 编写程序进行遍历，修复关卡可执行文件，通过检查后读取 /flag
- Level 3.0 - 学习并理解 plt 跳转，修复关卡可执行文件，通过检查后读取 /flag
- Level 3.1 - 学习并理解 plt，got 跳转，修复关卡可执行文件，通过检查后读取 /flag

References
- [Concrete Value for fields in ELF format](https://github.com/WolfgangSt/libelf/blob/master/lib/elf_repl.h)