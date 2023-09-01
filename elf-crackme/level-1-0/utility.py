#!/opt/pwn.college/python

def main():
    file_path = "./elf-crackme-level1.0"
    
    try:
        with open(file_path, "r+b") as file:
            position = 0x4 
            new_data = 0x1   # 将要写入的数据设置为0x66 0x66
            
            file.seek(position)
            file.write(new_data.to_bytes(1, byteorder='little'))  # 使用little-endian字节顺序写入两个字节
            
        print("Done!")
    except FileNotFoundError:
        print("[-] open failed")
    except Exception as e:
        print("Error occurs", e)

if __name__ == "__main__":
    main()

