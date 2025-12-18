#include <stdio.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm in danh sách sinh viên
void printStudents(const Student *students, int n) {
    printf("%-5s %-10s %-5s %-5s\n", "ID", "Name", "Age", "GPA");
    for (int i = 0; i < n; ++i) {
        printf("%-5d %-10s %-5d %-5.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Hàm loadFromFile: đọc từ students.txt vào mảng Student
// Trả về số lượng sinh viên đọc được, hoặc 0 nếu lỗi.
int loadFromFile(const char *filename, Student *students, int maxSize) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong mo duoc file %s\n", filename);
        return 0;
    }

    char header[256];
    // Đọc 2 dòng đầu (tiêu đề) nếu file giống cấu trúc bài 3
    fgets(header, sizeof(header), f); // dòng tiêu đề
    fgets(header, sizeof(header), f); // dòng =========...

    int count = 0;
    while (count < maxSize &&
           fscanf(f, "%d %49s %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
    }

    fclose(f);
    return count;
}

int main() {
    Student students[100];
    int n = loadFromFile("students.txt", students, 100);

    if (n == 0) {
        printf("Khong co du lieu hoac khong doc duoc file.\n");
        return 0;
    }

    printf("Danh sach doc tu file:\n");
    printStudents(students, n);

    return 0;
}


