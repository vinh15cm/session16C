#include <stdio.h>
int main() {
    FILE *file = fopen("D:Documents\\bt01.txt", "w");
    if (file == NULL) {
        printf("Kh�ng th? m? file.\n");
        return 1; 
    }
    char inputString[100];
    printf("Nh?p chu?i: ");
    fgets(inputString, sizeof(inputString), stdin);
    fprintf(file, "%s", inputString);
    fclose(file);
    printf("Chu?i d� du?c ghi v�o file bt01.txt.\n");
    return 0; 
}
