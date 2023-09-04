import hashlib
import binascii

file_path = "./elf-crackme-level2.2"
def read_flag():
    with open('/flag', 'r') as file:
        file_contents = file.read()
        print(file_contents)

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
            position = 0x1060
            length = 405
            file.seek(position)
            data_read = file.read(length)
            md5_2 = calculate_md5(data_read)
            if md5_2 == "7c3cdd4c8acdff1e3518c919bee03a7c":
                print("key:",a)
                read_flag();
            else:
                print(".text hash检验失败，请重新修改")

 
    except Exception as e:
        print("发生错误:", e)

if __name__ == "__main__":

    print("Original .text hash is d5a7cfeb46121dbb703fe0929ab060b2")
    print("我们修改了.text中的某两个字节为66，请尝试找到并爆破出原来的结果，修复完成后，执行即可获得flag.")
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


