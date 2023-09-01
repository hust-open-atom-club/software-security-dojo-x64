#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("./elf-crackme-level1.0", "r+b");  

    if (file == NULL) {
        perror("无法打开文件");
        return 1;
    }

    unsigned long position;
    unsigned char newData;

    printf("请输入要修改的位置（16进制）eg:0x1000：");
    scanf("%lx", &position);

    printf("请输入新的byte数据（16进制）eg:01：");
    scanf("%hhx", &newData);

 
    fseek(file, position, SEEK_SET);

 
    size_t bytesWritten = fwrite(&newData, 1, 1, file);

    if (bytesWritten != 1) {
        perror("写入数据失败");
        fclose(file);
        return 1;
    }

    fclose(file);

    printf("修改完成！\n");

    return 0;
}

