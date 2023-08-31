#!/opt/pwn.college/python

def main():
    file_path = "./elf-crackme-level1.0"
    
    try:
        with open(file_path, "r+b") as file:
            position = int(input("Please provide the offset of ELF file in hex format, e.g., 0x1000"), 16)
            new_data = int(input("Please provide the data byte by byte in hex format, e.g., 01"), 16)
            
            file.seek(position)
            file.write(bytes([new_data]))
            
        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    print("Can you identify the differences of ELF header between x86 and x86_64?")
    print("We provide a x86_64 ELF file. Can you please fix it and run it to get flag?")
    while True:
        main()

