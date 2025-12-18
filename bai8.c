#include <stdio.h>
#include <string.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// Hàm in danh sách sinh viên
void printStudents(const Student *students, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d %s %d %.1f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Hàm đọc danh sách sinh viên từ file (mỗi dòng: id name age gpa)
int loadFromFile(const char *filename, Student *students, int maxSize) {
    // Mở file ở chế độ đọc văn bản
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        // Nếu mở file thất bại, in thông báo lỗi và trả về 0 phần tử
        printf("Khong mo duoc file %s\n", filename);
        return 0;
    }

    int count = 0;
    // Đọc từng dòng cho đến khi hết file hoặc đủ maxSize sinh viên
    while (count < maxSize &&
           fscanf(f, "%d %49s %d %f",
                  &students[count].id,
                  students[count].name,
                  &students[count].age,
                  &students[count].gpa) == 4) {
        count++;
    }

    // Đóng file sau khi đọc xong
    fclose(f);
    return count; // Trả về số lượng sinh viên đọc được
}

// Hàm tạo dữ liệu giả lập cho 3 lớp vào 3 file riêng
void createMockClassFiles() {
    // classA.txt
    FILE *f = fopen("classA.txt", "w");
    if (f != NULL) {
        // Mỗi dòng là 1 sinh viên: id name age gpa
        fprintf(f, "1 An 20 8.0\n");
        fprintf(f, "2 Binh 21 7.5\n");
        fclose(f);
    }

    // classB.txt
    f = fopen("classB.txt", "w");
    if (f != NULL) {
        fprintf(f, "1 Hoa 19 8.5\n");
        fprintf(f, "2 Lan 20 7.8\n");
        fprintf(f, "3 Mai 21 9.0\n");
        fclose(f);
    }

    // classC.txt
    f = fopen("classC.txt", "w");
    if (f != NULL) {
        fprintf(f, "1 Nam 20 6.5\n");
        fprintf(f, "2 Son 22 7.0\n");
        fclose(f);
    }
}

int main() {
    // Bước 1: Tạo dữ liệu giả lập cho 3 lớp (A, B, C) vào 3 file riêng
    // Lưu ý: Trong thực tế, phần này có thể không cần nếu file đã tồn tại sẵn.
    createMockClassFiles();

    // Bước 2: Hỏi người dùng muốn đọc dữ liệu từ file nào (classA.txt, classB.txt, classC.txt)
    char filename[100];
    printf("Nhap ten file: ");
    scanf("%99s", filename);

    // Bước 3: Đọc dữ liệu sinh viên từ file người dùng nhập
    Student students[100];
    int n = loadFromFile(filename, students, 100);

    if (n == 0) {
        // Nếu không đọc được sinh viên nào, kết thúc chương trình
        return 0;
    }

    // Bước 4: Xác định tên lớp từ tên file (chỉ để in đẹp hơn)
    char className = '?';
    if (strcmp(filename, "classA.txt") == 0) {
        className = 'A';
    } else if (strcmp(filename, "classB.txt") == 0) {
        className = 'B';
    } else if (strcmp(filename, "classC.txt") == 0) {
        className = 'C';
    }

    // Bước 5: In danh sách sinh viên đã đọc được
    if (className != '?') {
        printf("Danh sach sinh vien lop %c:\n", className);
    } else {
        // Trường hợp file không phải A/B/C, vẫn in nhưng không có tên lớp cụ thể
        printf("Danh sach sinh vien tu file %s:\n", filename);
    }

    printStudents(students, n);

    return 0;
}


