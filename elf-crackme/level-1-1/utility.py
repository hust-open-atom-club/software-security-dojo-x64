#!/opt/pwn.college/python

file_path = "./elf-crackme-level1.1"

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
            position = 0x48
            length = 24
            file.seek(position)
            data_read = file.read(length)
            provided_hex_value = "400000000000000040000000000000004000000000000000"
            expected_value = bytes.fromhex(provided_hex_value)
            if data_read == expected_value:
                print("[+] Repair successful")
            else:
                print("[-] Repair failed")
 
    except Exception as e:
        print("[-] An error occurred:", e)

if __name__ == "__main__":
    print("###")
    print("### Welcome to ./elf-crackme-level1.1!")
    print("###")
    print("")
    print("We have modified certain Offset, VirtAddr, and PhysAddr in the Program Header.")
    print("Please try to restore them. After restoring, execute to obtain the flag.")
    
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