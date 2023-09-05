#!/opt/pwn.college/python
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
            position = int(input("[+] Please enter the position to modify (in hexadecimal, e.g., 0x1000): "), 16)
            new_data = int(input("[+] Please enter the new byte data (in hexadecimal, e.g., 01): "), 16)
            
            file.seek(position)
            file.write(bytes([new_data]))
            
        print("[+] Modification completed!")
    except FileNotFoundError:
        print("[-] Unable to open the file")
    except Exception as e:
        print("[-] An error occurred:", e)
def check():
    try:
         with open(file_path, "rb") as file:
            text_position = 0x1120
            text_length = 677
            position = 0x3000
            length = 24
            file.seek(text_position)
            data = file.read(text_length)
            if calculate_md5(data) == "065e467b8789b95859d7d33fd30addeb" :
                file.seek(position)
                data_read = file.read(length)
                expected_hash = "bab1deb320c6d058403c0700ee4fd711"
                data_hash = calculate_md5(data_read) 
                if data_hash != expected_hash:
                    print("[+] Modification completed!")
                else:
                    print("[+] Modification error!")
            else :
                print("Hash verification for the .text segment failed; you cannot modify the text segment.")
            
 
    except Exception as e:
        print("发生错误:", e)

if __name__ == "__main__":
    print("We have modified the .text segment. Please analyze the code and use the utility.py script to modify the data segment in the binary for checking. After completing the repair, execute the binary to obtain the flag.")
    while True:
        print("Select the action you want to perform:")
        print("1. Modify the ELF file")
        print("2. Check the repaired content")
        print("3. Exit")
        
        choice = input("Enter the option number: ")
        
        if choice == "1":
            patch()
        elif choice == "2":
            check()
        elif choice == "3":
            print("The program has exited.")
            break
        else:
            print("Invalid option, please enter again.")








