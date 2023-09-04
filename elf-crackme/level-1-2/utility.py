file_path = "./elf-crackme-level1.2"

def read_elf():
    with open('/flag', 'r') as file:
        file_contents = file.read()
        print(file_contents)


def main():
    
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
def check():
print(1)
    try:
         with open(file_path, "rb") as file:
            position = 0x4060
            length = 16
            file.seek(position)
            data_read = file.read(length)
            provided_hex_value = "B03f000000000000B02f000000000000"
            print(data_read)
            expected_value = bytes.fromhex(provided_hex_value)
            if data_read == expected_value:
                print("修复成功")
                read_flag()
            else:
                print("修复失败")
 
    except Exception as e:
        print("发生错误:", e)

if __name__ == "__main__":
    print("我们修改了Section Header 中的got表项的Address，Offset请尝试将他恢复，恢复后执行即可获得flag.")
    while True:
        print("请选择要执行的功能:")
        print("1. 修改 ELF 文件")
        print("2. 检查修复后的内容")
        print("3. 退出")
        
        choice = input("请输入选项数字: ")
        
        if choice == "1":
            main()
        elif choice == "2":
            check()
        elif choice == "3":
            print("程序已退出。")
            break
        else:
            print("无效的选项，请重新输入。")








