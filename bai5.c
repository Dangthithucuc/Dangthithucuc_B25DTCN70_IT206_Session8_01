#include <stdio.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

/**
 * findStudentById
 * ----------------
 * Tìm kiếm sinh viên trong mảng theo mã số ID.
 *
 * Tham số:
 *   - students: mảng các sinh viên
 *   - n: số lượng phần tử thực tế trong mảng
 *   - id: mã số sinh viên cần tìm
 *
 * Giá trị trả về:
 *   - Vị trí (chỉ số index) của sinh viên nếu tìm thấy
 *   - -1 nếu không tìm thấy hoặc id không hợp lệ (âm)
 */
int findStudentById(const Student *students, int n, int id) {
    if (id < 0) {
        return -1; // ID âm là không hợp lệ
    }

    for (int i = 0; i < n; ++i) {
        if (students[i].id == id) {
            return i;
        }
    }

    return -1; // không tìm thấy
}

// Hàm in thông tin 1 sinh viên
void printStudent(const Student *s) {
    printf("ID: %d, Name: %s, Age: %d, GPA: %.1f\n",
           s->id, s->name, s->age, s->gpa);
}

// Hàm chạy một test case đơn giản
void runTestCase(const Student *students, int n, int testId) {
    int idx = findStudentById(students, n, testId);
    printf("Test ID = %d: ", testId);

    if (idx >= 0) {
        printStudent(&students[idx]);
    } else {
        printf("Khong tim thay sinh vien.\n");
    }
}

int main() {
    // Khởi tạo danh sách sinh viên ví dụ
    Student students[] = {
        {1, "An",   20, 8.0f},
        {2, "Binh", 21, 7.5f},
        {3, "Cuong",22, 6.8f}
    };
    int n = sizeof(students) / sizeof(students[0]);

    // Sinh test case:
    // 1) ID tồn tại
    // 2) ID không tồn tại
    // 3) ID âm
    printf("=== Test cases ===\n");
    runTestCase(students, n, 2);   // tồn tại
    runTestCase(students, n, 10);  // không tồn tại
    runTestCase(students, n, -1);  // ID âm

    // Chức năng tìm kiếm tương tác theo yêu cầu đề bài
    int idToFind;
    printf("\nNhap ID can tim: ");
    scanf("%d", &idToFind);

    int index = findStudentById(students, n, idToFind);

    printf("\nKet qua tim kiem:\n");
    if (index >= 0) {
        printStudent(&students[index]);
    } else {
        printf("Khong tim thay sinh vien co ID = %d\n", idToFind);
    }

    return 0;
}


