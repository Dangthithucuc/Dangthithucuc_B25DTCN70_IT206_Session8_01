#include <stdio.h>

// Định nghĩa struct Student giống các bài trước
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

/**
 * sortByGpaDesc
 * -------------
 * Sắp xếp mảng sinh viên theo GPA giảm dần bằng thuật toán Bubble Sort.
 *
 * Ý tưởng thuật toán (Bubble Sort):
 *  - Duyệt nhiều lần qua mảng.
 *  - Mỗi lần duyệt, so sánh từng cặp phần tử kề nhau.
 *  - Nếu phần tử đứng trước có GPA nhỏ hơn phần tử đứng sau,
 *    ta hoán đổi vị trí của chúng.
 *  - Sau mỗi lượt duyệt, phần tử có GPA lớn nhất trong vùng chưa
 *    được sắp xếp sẽ "nổi" dần về đầu mảng (do ta sắp xếp giảm dần).
 */
void sortByGpaDesc(Student *students, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (students[j].gpa < students[j + 1].gpa) {
                Student tmp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = tmp;
            }
        }
    }
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

// Test case 1: GPA ngẫu nhiên (theo yêu cầu output ví dụ)
void testRandomGpa() {
    Student students[] = {
        {1, "An",  20, 8.0f},
        {2, "Binh",21, 7.5f},
        {3, "Chi", 19, 9.0f}
    };
    int n = sizeof(students) / sizeof(students[0]);

    sortByGpaDesc(students, n);
    printf("Danh sach sau khi sap xep (GPA ngau nhien):\n");
    printStudents(students, n);
    printf("\n");
}

// Test case 2: GPA bằng nhau
void testEqualGpa() {
    Student students[] = {
        {1, "A", 20, 8.0f},
        {2, "B", 21, 8.0f},
        {3, "C", 22, 8.0f}
    };
    int n = sizeof(students) / sizeof(students[0]);

    sortByGpaDesc(students, n);
    printf("Danh sach sau khi sap xep (GPA bang nhau):\n");
    printStudents(students, n);
    printf("\n");
}

// Test case 3: GPA đã tăng dần sẵn
void testAscendingGpa() {
    Student students[] = {
        {1, "X", 20, 6.0f},
        {2, "Y", 21, 7.0f},
        {3, "Z", 22, 8.0f}
    };
    int n = sizeof(students) / sizeof(students[0]);

    sortByGpaDesc(students, n);
    printf("Danh sach sau khi sap xep (GPA tang dan san):\n");
    printStudents(students, n);
    printf("\n");
}

int main() {
    // Chạy các test case
    testRandomGpa();
    testEqualGpa();
    testAscendingGpa();

    return 0;
}


