
def main():
    file_path = "./elf-crackme-level1.0"
    
    try:
        with open(file_path, "r+b") as file:
            position = 0x1332
            new_data = 0x75
            
            file.seek(position)
            file.write(new_data.to_bytes(1, byteorder='little')) 

        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    main()

