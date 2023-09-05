#!/opt/pwn.college/python
file_path = "./elf-crackme-level1.0"
    
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
            
        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    patch()

