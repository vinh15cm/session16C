#include<stdio.h>
struct Book {
    int maSach;
    char tenSach[100];
    char tacGia[100];
    float giaTien;
    char Theloai[50];
};

void inputSach(struct Book books[], int *soLuongSach) {
    int num;
    printf("Nh?p s? lu?ng s�ch: ");
    scanf("%d", &num);
    if ((*soLuongSach) + num > 100) {
        printf("S? lu?ng s�ch vu?t qu� gi?i h?n.\n");
        return;
    }
    for (int i = *soLuongSach; i < *soLuongSach + num; i++) {
        printf("\nNh?p th�ng tin cho s�ch th? %d:\n", i + 1);
        books[i].maSach = i + 1;
        printf("M� s�ch: %d\n", books[i].maSach);
        printf("T�n s�ch: ");
        scanf(" %[^\n]s", books[i].tenSach);
        printf("T�c gi?: ");
        scanf(" %[^\n]s", books[i].tacGia);
        printf("Gi� ti?n: ");
        scanf("%f", &books[i].giaTien);
        printf("Th? lo?i: ");
        scanf(" %[^\n]s", books[i].Theloai);
    }
    *soLuongSach += num;
}

void luuThongTinSach(struct Book books[], int soLuongSach) {
    FILE *file = fopen("books.txt", "w");
    if (file == NULL) {
        printf("Kh�ng th? m? file d? ghi.\n");
        return;
    }
    for (int i = 0; i < soLuongSach; i++) {
        fprintf(file, "%d;%s;%s;%.2f;%s\n", books[i].maSach, books[i].tenSach, books[i].tacGia, books[i].giaTien, books[i].Theloai);
    }
    fclose(file);
    printf("Th�ng tin s�ch d� du?c luu v�o file books.txt.\n");
}

void hienThiThongTinSachTuFile() {
    FILE *file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Kh�ng th? m? file d? d?c.\n");
        return;
    }
    printf("\nTh�ng tin s�ch t? file:\n");
    printf("%-8s%-20s%-20s%-15s%-15s\n", "Ma Sach|", "Ten sach|", "Tac gia|", "gia tien|", "the loai|");
    struct Book book;
    while (fscanf(file, "%d;%[^;];%[^;];%f;%[^\n]\n", &book.maSach, book.tenSach, book.tacGia, &book.giaTien, book.Theloai) != EOF) {
        printf("%-8d%-21s%-20s%-15.3f%-s\n", book.maSach, book.tenSach, book.tacGia, book.giaTien, book.Theloai);
    }
    fclose(file);
}

int main() {
    struct Book books[100];
    int choice, soLuongSach = 0;
    do {
        printf("\nMENU\n");
        printf("1. Nh?p s? lu?ng v� th�ng tin s�ch\n");
        printf("2. Luu th�ng tin s�ch v�o file\n");
        printf("3. Hi?n th? th�ng tin s�ch t? file\n");
        printf("4. Tho�t\n");
        printf("Ch?n ch?c nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputSach(books, &soLuongSach);
                break;
            case 2:
                luuThongTinSach(books, soLuongSach);
                break;
            case 3:
                hienThiThongTinSachTuFile();
                break;
            case 4:
                printf("Tho�t kh?i chuong tr�nh.\n");
                break;
            default:
                printf("Ch?c nang kh�ng h?p l?. Vui l�ng ch?n l?i.\n");
        }
    } while (choice != 4);
    return 0;
}
