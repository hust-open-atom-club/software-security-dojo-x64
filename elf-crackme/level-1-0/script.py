def main():
    file_path = "./elf_header"
    
    try:
        with open(file_path, "r+b") as file:
            position = int(input("请输入要修改的位置（16进制），例如：0x1000："), 16)
            new_data = int(input("请输入新的 byte 数据（16进制），例如：01："), 16)
            
            file.seek(position)
            file.write(bytes([new_data]))
            
        print("修改完成！")
    except FileNotFoundError:
        print("无法打开文件")
    except Exception as e:
        print("发生错误:", e)

if __name__ == "__main__":
    print("你能看出x86和x64两种的ELF-header的区别吗？")
    print("我们提供了一个x64的文件，你能修复他吗？修复完成后执行即可获得flag。")
    while True:
        main()

