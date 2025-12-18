#include <stdio.h>

// Định nghĩa struct Student giống bài 1
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm in tiêu đề bảng
void printHeader() {
    printf("%-5s %-10s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
}

// Hàm in thông tin 1 sinh viên
void printStudent(const Student *s) {
    printf("%-5d %-10s %-5d %-5.1f\n", s->id, s->name, s->age, s->gpa);
}

int main() {
    Student students[5];  // tối đa 5 sinh viên
    int n;

    printf("Nhap so luong sinh vien (toi da 5): ");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("So luong khong hop le!\n");
        return 0;
    }

    // Nhap thong tin sinh vien
    for (int i = 0; i < n; ++i) {
        printf("Nhap sinh vien thu %d (id name age gpa): ", i + 1);
        scanf("%d %49s %d %f", &students[i].id, students[i].name, &students[i].age, &students[i].gpa);
    }

    // In danh sach sinh vien ra man hinh
    printf("\n");
    printHeader();
    for (int i = 0; i < n; ++i) {
        printStudent(&students[i]);
    }

    return 0;
}


