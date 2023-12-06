#include <stdio.h>
int main(){
    FILE *file1, *file3, *file5;
    char File5[1000];
    char ch;
    file1 = fopen("D:Documents\\bt01.txt", "r");
    file3 = fopen("D:Documents\\bt3.txt", "r");
    if (file1 == NULL || file3 == NULL) {
        printf("Không th? m? file ngu?n.\n");
        return 1;
    }
    file5 = fopen("D:Documents\\bt05.txt", "w");
    if (file5 == NULL) {
        printf("Không th? t?o ho?c m? file dích.\n");
        fclose(file1);
        fclose(file3);
        return 1;
    }
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file5);
    }
    fputc('\n', file5);
    while ((ch = fgetc(file3)) != EOF) {
        fputc(ch, file5);
    }
    fclose(file1);
    fclose(file3);
    file5 = fopen("D:Documents\\bt05.txt", "r");
    printf("N?i dung dã du?c sao chép t? bt01.txt và bt3.txt sang bt5.txt.\n");
    fread(file5 , sizeof(char), sizeof(File5),file5);
    printf("%s",file5);
    fclose(file5);
    return 0;
}
