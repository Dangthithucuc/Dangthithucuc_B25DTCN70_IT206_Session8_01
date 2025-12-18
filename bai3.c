#include <stdio.h>

// Định nghĩa struct Student giống bài 1
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm in danh sách sinh viên ra màn hình (để kiểm tra)
void printStudents(const Student *students, int n) {
    printf("%-5s %-20s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    printf("=========================================\n");
    for (int i = 0; i < n; ++i) {
        printf("%-5d %-20s %-5d %-5.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Hàm saveToFile: lưu danh sách sinh viên vào file students.txt
void saveToFile(const Student *students, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return;
    }

    // Ghi tiêu đề
    fprintf(f, "%-5s %-20s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    fprintf(f, "=========================================\n");

    // Ghi từng sinh viên
    for (int i = 0; i < n; ++i) {
        fprintf(f, "%-5d %-20s %-5d %-5.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }

    fclose(f);
    printf("Da luu %d sinh vien vao file %s\n", n, filename);
}

int main() {
    // Khởi tạo danh sách sinh viên giống bài 1 (ví dụ 3 sinh viên)
    Student students[3] = {
        {1, "Nguyen Van A", 20, 3.2f},
        {2, "Tran Thi B",   21, 3.6f},
        {3, "Le Van C",     19, 2.9f}
    };
    int n = 3;

    // In ra màn hình để kiểm tra
    printf("Danh sach sinh vien:\n");
    printStudents(students, n);

    // Ghi ra file students.txt
    saveToFile(students, n, "students.txt");

    return 0;
}


