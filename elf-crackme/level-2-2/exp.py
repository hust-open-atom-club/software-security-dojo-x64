import hashlib
import binascii


def calculate_md5(data):
    md5_hash = hashlib.md5(data).hexdigest()
    return md5_hash


def brute(a):
    bug_string = "f3 0f 1e fa 31 ed 49 89 d1 5e 48 89 e2 48 83 e4 f0 50 54 45 31 c0 31 c9 48 8d 3d ca 00 00 00 ff 15 53 2f 00 00 f4 66 2e 0f 1f 84 00 00 00 00 00 48 8d 3d 79 2f 00 00 48 8d 05 72 2f 00 00 48 39 f8 74 15 48 8b 05 36 2f 00 00 48 85 c0 74 09 ff e0 0f 1f 80 00 00 00 00 c3 0f 1f 80 00 00 00 00 48 8d 3d 49 2f 00 00 48 8d 35 42 2f 00 00 48 29 fe 48 89 f0 48 c1 ee 3f 48 c1 f8 03 48 01 c6 48 d1 fe 74 14 48 8b 05 05 2f 00 00 48 85 c0 74 08 ff e0 66 0f 1f 44 00 00 c3 0f 1f 80 00 00 00 00 f3 0f 1e fa 80 3d 05 2f 00 00 00 75 2b 55 48 83 3d e2 2e 00 00 00 48 89 e5 74 0c 48 8b 3d e6 2e 00 00 e8 19 ff ff ff e8 64 ff ff ff c6 05 dd 2e 00 00 01 5d c3 0f 1f 00 c3 0f 1f 80 00 00 00 00 f3 0f 1e fa e9 77 ff ff ff f3 0f 1e fa 55 48 89 e5 48 8d 05 b0 0e 00 00 48 89 c7 e8 f0 fe ff ff 48 8d 05 b9 0e 00 00 48 89 c7 e8 e1 fe ff ff " + a + "b8 00 00 00 00 5d c3"
    md5_2 = md5_check(bug_string)
    if md5_2 == "c167dcb0f90740af865511726a83e78e":
        print("key:", a)


def md5_check(hex_string):
    hex_string = hex_string.replace(" ", "")
    binary_data = binascii.unhexlify(hex_string)
    md5_result = calculate_md5(binary_data)
    return md5_result
    print("MD5 Hash:", md5_result)


if __name__ == "__main__":
    hex_string = "f3 0f 1e fa 31 ed 49 89 d1 5e 48 89 e2 48 83 e4 f0 50 54 45 31 c0 31 c9 48 8d 3d ca 00 00 00 ff 15 53 2f 00 00 f4 66 2e 0f 1f 84 00 00 00 00 00 48 8d 3d 79 2f 00 00 48 8d 05 72 2f 00 00 48 39 f8 74 15 48 8b 05 36 2f 00 00 48 85 c0 74 09 ff e0 0f 1f 80 00 00 00 00 c3 0f 1f 80 00 00 00 00 48 8d 3d 49 2f 00 00 48 8d 35 42 2f 00 00 48 29 fe 48 89 f0 48 c1 ee 3f 48 c1 f8 03 48 01 c6 48 d1 fe 74 14 48 8b 05 05 2f 00 00 48 85 c0 74 08 ff e0 66 0f 1f 44 00 00 c3 0f 1f 80 00 00 00 00 f3 0f 1e fa 80 3d 05 2f 00 00 00 75 2b 55 48 83 3d e2 2e 00 00 00 48 89 e5 74 0c 48 8b 3d e6 2e 00 00 e8 19 ff ff ff e8 64 ff ff ff c6 05 dd 2e 00 00 01 5d c3 0f 1f 00 c3 0f 1f 80 00 00 00 00 f3 0f 1e fa e9 77 ff ff ff f3 0f 1e fa 55 48 89 e5 48 8d 05 b0 0e 00 00 48 89 c7 e8 f0 fe ff ff 48 8d 05 b9 0e 00 00 48 89 c7 e8 e1 fe ff ff 90 90 b8 00 00 00 00 5d c3"

    print("Original hash c167dcb0f90740af865511726a83e78e")
    md5_check(hex_string)
    for i in range(0x10000):
        hex_string = format(i, '04x')
        brute(hex_string)
