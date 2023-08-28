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
    main()

