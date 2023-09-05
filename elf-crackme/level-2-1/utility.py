import hashlib
import binascii


file_path = "./elf-crackme-level2.1"

def calculate_md5(data):
    md5_hash = hashlib.md5(data).hexdigest()
    return md5_hash

def md5_check(hex_string):
    hex_string = hex_string.replace(" ", "")  
    binary_data = binascii.unhexlify(hex_string)
    md5_result = calculate_md5(binary_data)
    return md5_result
    print("MD5 Hash:", md5_result)

def patch():    
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
    try:
         with open(file_path, "rb") as file:
            text_position = 0x1120
            text_length = 566
            position = 0x3000
            length = 24
            file.seek(text_position)
            data = file.read(text_length)
            if calculate_md5(data) == "a9a34acaa2a0bc23109eec05471f3542" :
                file.seek(position)
                data_read = file.read(length)
                expected_hash = "bab1deb320c6d058403c0700ee4fd711"
                data_hash = calculate_md5(data_read) 
                if data_hash != expected_hash:
                    print("修复成功")
                else:
                    print("修复失败")
            else :
                print(".text段hash检验失败，不可以修改text段") 
    except Exception as e:
        print("发生错误:", e)

if __name__ == "__main__":
    print("###")
    print("### Welcome to ./elf-crackme-level2.1!")
    print("###")
    print("")
    print("我们修改了.text 段，请尝试分析代码，并通过utils.py 脚本修改binary中data段完成check，修复完成后，执行binary即可获得flag.")
    while True:
        print("请选择要执行的功能:")
        print("1. 修改 ELF 文件")
        print("2. 检查修复后的内容")
        print("3. 退出")
        
        choice = input("请输入选项数字: ")
        
        if choice == "1":
            patch()
        elif choice == "2":
            check()
        elif choice == "3":
            print("程序已退出。")

            break
        else:
            print("无效的选项，请重新输入。")