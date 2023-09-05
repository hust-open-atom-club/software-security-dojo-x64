#!/opt/pwn.college/python

def main():
    file_path = "./elf-crackme-level1.0"
    
    try:
        with open(file_path, "r+b") as file:
            position = 0x4 
            new_data = 0x2  
            
            file.seek(position)
            file.write(new_data.to_bytes(1, byteorder='little')) 
            
            
            position_2 = 0x12
            new_data_2 = 0x3e
            file.seek(position_2)
            file.write(new_data_2.to_bytes(1, byteorder='little'))  
            
        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    print("###")
    print("### Welcome to ./elf-crackme-level1.0!")
    print("###")
    print("")
    main()

