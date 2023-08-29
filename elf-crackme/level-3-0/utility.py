def main():
    file_path = "./elf-crackme-level3.0"
    
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
    print("我们提供了一个plt表损坏的binary，请大家根据plt表跳转顺序，使用脚本后执行，即可获得flag")
    main()

