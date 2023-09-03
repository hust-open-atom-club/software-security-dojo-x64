
def main():
    file_path = "./elf-crackme-level2.2"
    
    try:
        with open(file_path, "r+b") as file:
            position = 0x116f
            new_data = 0x66
            
            file.seek(position)
            file.write(new_data.to_bytes(1, byteorder='little')) 

        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    main()

