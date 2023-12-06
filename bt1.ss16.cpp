#include <stdio.h>
int main() {
    FILE *file = fopen("D:Documents\\bt01.txt", "w");
    if (file == NULL) {
        printf("Không th? m? file.\n");
        return 1; 
    }
    char inputString[100];
    printf("Nh?p chu?i: ");
    fgets(inputString, sizeof(inputString), stdin);
    fprintf(file, "%s", inputString);
    fclose(file);
    printf("Chu?i dã du?c ghi vào file bt01.txt.\n");
    return 0; 
}
