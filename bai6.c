#include <stdio.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

/**
 * calcAverageGpa
 * --------------
 * Tính GPA trung bình của danh sách sinh viên.
 *
 * Tham số:
 *   - students: mảng các sinh viên
 *   - n: số lượng sinh viên trong mảng
 *
 * Giá trị trả về:
 *   - GPA trung bình (float)
 *   - Nếu n <= 0, trả về 0.0
 */
float calcAverageGpa(const Student *students, int n) {
    if (n <= 0) {
        return 0.0f;
    }

    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        sum += students[i].gpa;
    }
    return sum / n;
}

// Tạo 10 sinh viên giả lập với GPA khác nhau để kiểm thử
void createMockStudents(Student *students, int *nOut) {
    *nOut = 10;
    students[0] = (Student){1,  "S1", 20, 7.5f};
    students[1] = (Student){2,  "S2", 20, 8.0f};
    students[2] = (Student){3,  "S3", 20, 9.0f};
    students[3] = (Student){4,  "S4", 20, 8.5f};
    students[4] = (Student){5,  "S5", 20, 8.0f};
    students[5] = (Student){6,  "S6", 20, 8.5f};
    students[6] = (Student){7,  "S7", 20, 8.0f};
    students[7] = (Student){8,  "S8", 20, 8.0f};
    students[8] = (Student){9,  "S9", 20, 8.5f};
    students[9] = (Student){10, "S10",20, 8.0f};
    // Trung bình của các GPA trên là 8.25
}

int main() {
    Student students[10];
    int n;

    // Test chính: 10 sinh viên giả lập
    createMockStudents(students, &n);
    float avg = calcAverageGpa(students, n);
    printf("GPA trung binh cua lop la: %.2f\n", avg);

    // Test case: danh sách rỗng
    Student empty[1];
    int emptyCount = 0;
    float avgEmpty = calcAverageGpa(empty, emptyCount);
    printf("GPA trung binh (danh sach rong) la: %.2f\n", avgEmpty);

    return 0;
}


