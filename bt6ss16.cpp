#include <stdio.h>
struct Student{
    char name[100];
    int age;
    char phone[15];
    char email[100];
};

int main() {
    int numStudents;
    printf("Nh?p s? lu?ng sinh vi�n: ");
    scanf("%d", &numStudents);
    struct Student students[numStudents];
    for (int i = 0; i < numStudents; i++) {
        printf("\nNh?p th�ng tin cho sinh vi�n th? %d:\n", i + 1);
        printf("H? v� t�n: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Tu?i: ");
        scanf("%d", &students[i].age);
        printf("S? di?n tho?i: ");
        scanf("%s", students[i].phone);
        printf("Email: ");
        scanf("%s", students[i].email);
    }
    FILE *file = fopen("D:\\Documents\\students.txt", "w");
    if (file == NULL) {
        printf("Kh�ng th? m? file d? ghi.\n");
        return 1;
    }
    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %s %s\n", students[i].name, students[i].age, students[i].phone, students[i].email);
    }
    fclose(file);
    file = fopen("D:\\Documents\\students.txt", "r");
    if (file == NULL) {
        printf("Kh�ng th? m? file d? d?c.\n");
        return 1;
    }
    printf("Danh s�ch sinh vi�n l�:\n");
    for (int i = 0; i < numStudents; i++) {
        fscanf(file, "%s %d %s %s", students[i].name, &students[i].age, students[i].phone, students[i].email);
        printf("%s %d %s %s\n", students[i].name, students[i].age, students[i].phone, students[i].email);
    }
    fclose(file);
    printf("Th�ng tin sinh vi�n d� du?c luu v�o file students.txt v� du?c d?c l?i t? file.\n");
    return 0;
}
