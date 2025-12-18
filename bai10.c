#include <stdio.h>

#define MAX_STUDENTS 100

// Định nghĩa struct Student
typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

// ================== CÁC HÀM HỖ TRỢ CƠ BẢN ==================

// In danh sách sinh viên hiện có
void printStudents(const Student *students, int n) {
    if (n == 0) {
        printf("Danh sach hien dang rong.\n");
        return;
    }

    printf("ID   Name                 Age  GPA\n");
    printf("====================================\n");
    for (int i = 0; i < n; ++i) {
        printf("%-4d %-20s %-4d %.2f\n",
               students[i].id,
               students[i].name,
               students[i].age,
               students[i].gpa);
    }
}

// Nhập danh sách sinh viên từ bàn phím (ghi đè danh sách cũ)
void inputStudents(Student *students, int *n) {
    int count;
    printf("Nhap so luong sinh vien (toi da %d): ", MAX_STUDENTS);
    scanf("%d", &count);

    if (count < 0 || count > MAX_STUDENTS) {
        printf("So luong khong hop le.\n");
        return;
    }

    for (int i = 0; i < count; ++i) {
        printf("Sinh vien thu %d (id name age gpa): ", i + 1);
        scanf("%d %49s %d %f",
              &students[i].id,
              students[i].name,
              &students[i].age,
              &students[i].gpa);
    }

    *n = count;
}

// Ghi danh sách hiện tại ra file văn bản
void saveToFile(const Student *students, int n, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Khong mo duoc file %s de ghi.\n", filename);
        return;
    }

    // Ghi tiêu đề để dễ đọc file
    fprintf(f, "ID   Name                 Age  GPA\n");
    fprintf(f, "====================================\n");

    for (int i = 0; i < n; ++i) {
        fprintf(f, "%-4d %-20s %-4d %.2f\n",
                students[i].id,
                students[i].name,
                students[i].age,
                students[i].gpa);
    }

    fclose(f);
    printf("Da ghi %d sinh vien vao file %s\n", n, filename);
}

// Đọc danh sách sinh viên từ file (ghi đè danh sách cũ)
int loadFromFile(Student *students, int maxSize, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong mo duoc file %s de doc.\n", filename);
        return 0;
    }

    char header[256];
    // Bỏ qua 2 dòng tiêu đề đầu file
    fgets(header, sizeof(header), f);
    fgets(header, sizeof(header), f);

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
    printf("Da doc %d sinh vien tu file %s\n", count, filename);
    return count;
}

// Tìm sinh viên theo ID, trả về chỉ số hoặc -1 nếu không thấy
int findStudentById(const Student *students, int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Sắp xếp danh sách theo GPA giảm dần (Bubble Sort)
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
    printf("Da sap xep danh sach theo GPA giam dan.\n");
}

// Thêm 1 sinh viên (nếu còn chỗ và không trùng ID)
int addStudent(Student *students, int currentSize, int maxSize, Student newStudent) {
    if (currentSize >= maxSize) {
        printf("Danh sach da day, khong the them.\n");
        return currentSize;
    }

    if (findStudentById(students, currentSize, newStudent.id) != -1) {
        printf("ID %d da ton tai, khong the them.\n", newStudent.id);
        return currentSize;
    }

    students[currentSize] = newStudent;
    printf("Da them sinh vien ID %d.\n", newStudent.id);
    return currentSize + 1;
}

// Xóa sinh viên theo ID nếu tìm thấy
int removeStudentById(Student *students, int currentSize, int id) {
    int index = findStudentById(students, currentSize, id);
    if (index == -1) {
        printf("Khong tim thay sinh vien co ID = %d.\n", id);
        return currentSize;
    }

    for (int i = index; i < currentSize - 1; ++i) {
        students[i] = students[i + 1];
    }

    printf("Da xoa sinh vien ID %d.\n", id);
    return currentSize - 1;
}

// Sinh sẵn 10 sinh viên giả lập để test nhanh
void createMockStudents(Student *students, int *n) {
    *n = 10;
    students[0] = (Student){1, "S1", 20, 7.5f};
    students[1] = (Student){2, "S2", 21, 8.0f};
    students[2] = (Student){3, "S3", 22, 9.0f};
    students[3] = (Student){4, "S4", 20, 6.5f};
    students[4] = (Student){5, "S5", 19, 8.2f};
    students[5] = (Student){6, "S6", 21, 7.8f};
    students[6] = (Student){7, "S7", 20, 8.9f};
    students[7] = (Student){8, "S8", 22, 5.5f};
    students[8] = (Student){9, "S9", 23, 6.9f};
    students[9] = (Student){10, "S10", 19, 8.4f};
}

// ================== HÀM MAIN VÀ MENU ==================

void printMenu() {
    printf("\n===== Student Manager =====\n");
    printf("1. Nhap sinh vien\n");
    printf("2. In danh sach\n");
    printf("3. Ghi file\n");
    printf("4. Doc file\n");
    printf("5. Tim kiem theo ID\n");
    printf("6. Sap xep theo GPA giam dan\n");
    printf("7. Them sinh vien\n");
    printf("8. Xoa sinh vien\n");
    printf("0. Thoat\n");
    printf("===========================\n");
    printf("Chon chuc nang: ");
}

int main() {
    Student students[MAX_STUDENTS];
    int n = 0;
    int choice;

    // Khởi tạo sẵn 10 sinh viên giả lập để test
    createMockStudents(students, &n);
    printf("Da khoi tao %d sinh vien gia lap de test.\n", n);

    do {
        printMenu();
        if (scanf("%d", &choice) != 1) {
            // Nếu nhập không phải số, thoát để tránh vòng lặp vô hạn
            printf("Nhap khong hop le. Thoat.\n");
            break;
        }

        switch (choice) {
            case 1: {
                // Nhập mới danh sách sinh viên (ghi đè danh sách hiện tại)
                inputStudents(students, &n);
                break;
            }
            case 2: {
                // In toàn bộ danh sách hiện tại ra màn hình
                printStudents(students, n);
                break;
            }
            case 3: {
                // Ghi danh sách hiện tại ra file students.txt
                saveToFile(students, n, "students.txt");
                break;
            }
            case 4: {
                // Đọc danh sách từ file students.txt vào mảng (ghi đè danh sách cũ)
                n = loadFromFile(students, MAX_STUDENTS, "students.txt");
                break;
            }
            case 5: {
                // Tìm kiếm sinh viên theo ID và in ra nếu có
                int id;
                printf("Nhap ID can tim: ");
                scanf("%d", &id);
                int index = findStudentById(students, n, id);
                if (index == -1) {
                    printf("Khong tim thay sinh vien co ID = %d.\n", id);
                } else {
                    printf("Tim thay: ");
                    printf("%d %s %d %.2f\n",
                           students[index].id,
                           students[index].name,
                           students[index].age,
                           students[index].gpa);
                }
                break;
            }
            case 6: {
                // Sắp xếp danh sách hiện tại theo GPA giảm dần
                sortByGpaDesc(students, n);
                break;
            }
            case 7: {
                // Nhập thông tin 1 sinh viên và thêm vào danh sách
                Student s;
                printf("Nhap sinh vien moi (id name age gpa): ");
                scanf("%d %49s %d %f",
                      &s.id,
                      s.name,
                      &s.age,
                      &s.gpa);
                n = addStudent(students, n, MAX_STUDENTS, s);
                break;
            }
            case 8: {
                // Xóa 1 sinh viên theo ID
                int id;
                printf("Nhap ID can xoa: ");
                scanf("%d", &id);
                n = removeStudentById(students, n, id);
                break;
            }
            case 0: {
                // Thoát chương trình
                printf("Dang thoat chuong trinh...\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le.\n");
                break;
            }
        }
    } while (choice != 0);

    return 0;
}


