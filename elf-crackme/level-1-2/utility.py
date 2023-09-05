#!/opt/pwn.college/python
file_path = "./elf-crackme-level1.2"

def read_flag():
    with open('/flag', 'r') as file:
        file_contents = file.read()
        print(file_contents)

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
            position = 0x4060
            length = 16
            file.seek(position)
            data_read = file.read(length)
            provided_hex_value = "B03f000000000000B02f000000000000"
            #print(data_read)
            expected_value = bytes.fromhex(provided_hex_value)
            if data_read == expected_value:
                print("[+] Repair successful")
                read_flag()
            else:
                print("[-] Repair failed")
 
    except Exception as e:
        print("[-] An error occurred:", e)

if __name__ == "__main__":
    print("###")
    print("### Welcome to ./elf-crackme-level1.2!")
    print("###")
    print("")
    print("We have modified the Address and Offset of a GOT table entry in the Section Header.")
    print("Please try to restore them. After restoring, execute to obtain the flag.")
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
    else:
        print("Invalid option, please enter again.")