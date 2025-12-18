#include <stdio.h>

// Định nghĩa struct Student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm in tiêu đề bảng
void printHeader() {
    printf("%-5s %-20s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    printf("=========================================\n");
}

// Hàm in thông tin 1 sinh viên
void printStudent(const Student *s) {
    printf("%-5d %-20s %-5d %-5.2f\n", s->id, s->name, s->age, s->gpa);
}

int main() {
    // Khởi tạo sẵn 3 sinh viên
    Student students[3] = {
        {1, "Nguyen Van A", 20, 3.2},
        {2, "Tran Thi B",  21, 3.6},
        {3, "Le Van C",    19, 2.9}
    };

    // In danh sách sinh viên dưới dạng bảng
    printf("Danh sach sinh vien:\n\n");
    printHeader();

    for (int i = 0; i < 3; ++i) {
        printStudent(&students[i]);
    }

    return 0;
}