#include <stdio.h>
#include <string.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

/**
 * addStudent
 * ----------
 * Thêm 1 sinh viên mới vào cuối mảng nếu:
 *  - Chưa đủ sức chứa (currentSize < maxSize)
 *  - ID chưa tồn tại trong mảng (tránh trùng ID)
 *
 * Tham số:
 *   - students: mảng sinh viên hiện tại
 *   - currentSize: số lượng sinh viên hiện có (truyền theo giá trị)
 *   - maxSize: kích thước tối đa của mảng
 *   - newStudent: sinh viên cần thêm
 *
 * Giá trị trả về:
 *   - Số lượng sinh viên mới sau khi thêm (có thể bằng currentSize nếu không thêm được)
 */
int addStudent(Student *students, int currentSize, int maxSize, Student newStudent) {
    // Kiểm tra còn chỗ trống không
    if (currentSize >= maxSize) {
        printf("Khong the them, danh sach da day.\n");
        return currentSize;
    }

    // Kiểm tra trùng ID
    for (int i = 0; i < currentSize; ++i) {
        if (students[i].id == newStudent.id) {
            printf("Khong the them, ID %d da ton tai.\n", newStudent.id);
            return currentSize;
        }
    }

    // Thêm vào cuối mảng
    students[currentSize] = newStudent;
    return currentSize + 1;
}

/**
 * removeStudentById
 * -----------------
 * Xóa 1 sinh viên khỏi mảng dựa trên ID.
 *
 * Ý tưởng:
 *   - Tìm vị trí (index) của sinh viên có ID cần xóa.
 *   - Nếu tìm thấy, dịch trái các phần tử phía sau để lấp chỗ trống.
 *
 * Tham số:
 *   - students: mảng sinh viên hiện tại
 *   - currentSize: số lượng sinh viên hiện có (truyền theo giá trị)
 *   - id: mã số sinh viên cần xóa
 *
 * Giá trị trả về:
 *   - Số lượng sinh viên mới sau khi xóa (có thể bằng currentSize nếu không xóa được)
 */
int removeStudentById(Student *students, int currentSize, int id) {
    int index = -1;

    // Tìm vị trí sinh viên có ID cần xóa
    for (int i = 0; i < currentSize; ++i) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // Không tìm thấy ID
        printf("Khong tim thay sinh vien co ID = %d de xoa.\n", id);
        return currentSize;
    }

    // Dịch các phần tử phía sau sang trái để lấp chỗ trống
    for (int i = index; i < currentSize - 1; ++i) {
        students[i] = students[i + 1];
    }

    return currentSize - 1;
}

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

// Chạy các test case theo yêu cầu đề bài
void runTestCases() {
    Student students[10] = {
        {1, "An",  20, 8.0f},
        {2, "Binh",21, 7.5f},
        {3, "Chi", 19, 9.0f}
    };
    int size = 3;

    printf("=== Test: Them sinh vien moi ===\n");
    // Thêm sinh viên mới (ID chưa tồn tại)
    Student s4 = {4, "Dung", 22, 6.5f};
    size = addStudent(students, size, 10, s4);
    printStudents(students, size);
    printf("\n");

    printf("=== Test: Them trung ID ===\n");
    // Thêm trùng ID (ID = 2 đã tồn tại)
    Student dup = {2, "TrungID", 23, 5.0f};
    size = addStudent(students, size, 10, dup);
    printStudents(students, size);
    printf("\n");

    printf("=== Test: Xoa ID ton tai ===\n");
    // Xóa ID tồn tại (2)
    size = removeStudentById(students, size, 2);
    printStudents(students, size);
    printf("\n");

    printf("=== Test: Xoa ID khong ton tai ===\n");
    // Xóa ID không tồn tại (999)
    size = removeStudentById(students, size, 999);
    printStudents(students, size);
    printf("\n");
}

int main() {
    // Demo đúng theo ví dụ đề bài
    Student students[10] = {
        {1, "An",  20, 8.0f},
        {2, "Binh",21, 7.5f},
        {3, "Chi", 19, 9.0f}
    };
    int size = 3;

    // Thêm: 4 Dung 22 6.5
    Student s4 = {4, "Dung", 22, 6.5f};
    size = addStudent(students, size, 10, s4);

    // Xóa: 2
    size = removeStudentById(students, size, 2);

    printf("Danh sach sau khi chinh sua:\n");
    printStudents(students, size);
    printf("\n\n");

    // Chạy thêm các test case tự động để kiểm thử các tình huống
    runTestCases();

    return 0;
}


