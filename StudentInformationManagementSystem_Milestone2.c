#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char name[50];
    char id[10];
    int age;
    char program[50];
    float gpa;
    char group[4];
} Student;

typedef struct {
    Student *ptr;
    int count;
} database;

int actualIntCheck(char input[]) {
    int found = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            found = 0;
        }
    }
    return found;
}

int validateIdInput(const char *input) {
    if (strlen(input) != 9) {
        return 0; // Invalid
    }
    if (input[0] != 'A' && input[0] != 'a') {
        return 0; // Invalid
    }
    for (int i = 1; i < 9; i++) {
        if (!isdigit(input[i])) {
            return 0; // Invalid
        }
    }
    return 1; // Valid
}

void addStudent(database *db) {
    db->ptr = realloc(db->ptr, (db->count + 1) * sizeof(Student));

    Student *newStudent = &db->ptr[db->count]; //Making space in library for new book

    printf("Enter a name: ");
    scanf("%s", newStudent->name);
    getchar();
    for (size_t i = 0; newStudent->name[i] != '\0'; i++) {
        if (!isalpha(newStudent->name[i])) {
            printf("Invalid name format");
            return; // exit out of the function if not alphabet
        }
    }

    printf("Enter a id: ");
    scanf("%s", newStudent->id);
    getchar();

    if (!validateIdInput(newStudent->id)) {
        printf("invalid id format\n");
        return;
    }

    for (size_t i = 0; i < db->count; i++) {
        if (newStudent->id == db->ptr[i].id) {
            printf("Student with this ID already exists.");
            return;
        }
    }


    printf("Enter an age: ");
    scanf("%d", &newStudent->age);


    if (isdigit(newStudent->age)) {
        printf("Invalid age format\n");
        return;
    }

    printf("Enter a program: ");
    scanf("%s", newStudent->program);
    getchar();
    for (size_t i = 0; newStudent->program[i] != '\0'; i++) {
        if (!isalpha(newStudent->program[i])) {
            printf("Invalid program format");
            return; // exit out of the function if not alphabet
        }
    }
    //Program checking here

    printf("Enter a gpa: ");
    scanf("%d", &newStudent->gpa);

    if (newStudent->gpa < 0) {
        printf("Invalid gpa format\n");
        return;
    }

    printf("- Enter a Group(B - BBY or D - DTC):");
    scanf("%s", newStudent->group);
    getchar();

    for (size_t i = 0; newStudent->group[i] != '\0'; i++) {
        if (!isalpha(newStudent->group[i])) {
            printf("Invalid group format");
            return; // exit out of the function if not alphabet
        }
    }
    // Validates input to be b or d
    if (!(newStudent->group[0] == 'B' || newStudent->group[0] == 'b' ||
          newStudent->group[0] == 'D' || newStudent->group[0] == 'd')) {
        printf("Invalid group format\n");
        return;
    }

    db->count++;
    printf("\nStudent added successfully\n");
}

void displayAllStudents(const database *db) {
    if (db->count == 0) {
        printf("No Student records found.");
    }
    printf("\nGroup BBY\n");
    for (int i = 0; i < db->count; i++) {
        if (*db->ptr[i].group == 'b' || *db->ptr[i].group == 'B') {
            printf("\nName: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   db->ptr[i].name,
                   db->ptr[i].id,
                   db->ptr[i].age,
                   db->ptr[i].program,
                   db->ptr[i].gpa,
                   db->ptr[i].group);
        }
    }
    printf("\nGroup DTC\n");
    for (int i = 0; i < db->count; i++) {
        if (*db->ptr[i].group == 'd' || *db->ptr[i].group == 'D') {
            printf("\nName: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   db->ptr[i].name,
                   db->ptr[i].id,
                   db->ptr[i].age,
                   db->ptr[i].program,
                   db->ptr[i].gpa,
                   db->ptr[i].group);
        }
    }
}

void searchStudent(const database *db) {
    char ID[10];

    printf("Enter a Student ID to find:");
    scanf("%s", &ID);

    if (!validateIdInput(ID)) {
        printf("Invalid ID");
        return;
    }

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->ptr[i].id, ID) == 0) {
            printf("\nName: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   db->ptr[i].name,
                   db->ptr[i].id,
                   db->ptr[i].age,
                   db->ptr[i].program,
                   db->ptr[i].gpa,
                   db->ptr[i].group);
            return;
        }
    }
    printf("Student ID was not found\n");
}

void deleteStudent(database *db) {
    char ID[100];
    int userInput;
    printf("\nEnter a Student ID to find:");
    scanf("%s", &ID);

    int result = validateIdInput(ID);

    int index = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->ptr[i].id, ID) == 0) {
            index = i;
            break;
        }
    }
    if (index == 0) {
        printf("Student ID was not found\n");
    }

    for (int i = index; i < db->count; i++) {
        db->ptr[i] = db->ptr[i + 1];
    }
    db->count--;
    if (db->count > 0) {
        Student *temp = realloc(db->ptr, (db->count) * sizeof(Student));
        db->ptr = temp;
    } else {
        free(db->ptr);
        db->ptr = NULL;
    }

    printf("Student is deleted from the world!");
}


void listStudentGroup(const database *db) {
    // char group[100];
    int userInput;
    char result1 = 'd';
    char result2 = 'b';

    printf("Enter a group(1. BBY / 2. DTC):");
    // scanf("%s", &group);
    scanf("%d", &userInput);

    // if (result != 1) {
    //     printf("\nInvalid group Input.\n");
    //     return;
    // }

    if (userInput == 2) {
        printf("\nGroup DTC");
        for (int i = 0; i < db->count; i++) {
            if (*db->ptr[i].group == result1) {
                printf("\nName: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s\n",
                       db->ptr[i].name,
                       db->ptr[i].id,
                       db->ptr[i].age,
                       db->ptr[i].program,
                       db->ptr[i].gpa,
                       db->ptr[i].group);
            }
        }
    } else if (userInput == 1) {
        printf("\nGroup BBY");
        for (int i = 0; i < db->count; i++) {
            if (*db->ptr[i].group == result2) {
                printf("\nName: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s \n",
                       db->ptr[i].name,
                       db->ptr[i].id,
                       db->ptr[i].age,
                       db->ptr[i].program,
                       db->ptr[i].gpa,
                       db->ptr[i].group);
            }
        }
    } else {
        printf("\nGroup not recognized\n");
    }
}

int idSortAsc(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    return strcmp(studentA->id, studentB->id);
}

int idSortDes(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    return strcmp(studentB->id, studentA->id);
}

int nameSortAsc(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    return strcmp(studentA->name, studentB->name);
}

int nameSortDes(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    return strcmp(studentB->name, studentA->name);
}

int gpaSortAsc(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    if (studentA->gpa < studentB->gpa) return -1;
    if (studentA->gpa > studentB->gpa) return 1;
    return 0;
}

int gpaSortDes(const void *a, const void *b) {
    const Student *studentA = (const Student *) a;
    const Student *studentB = (const Student *) b;
    if (studentB->gpa < studentA->gpa) return -1;
    if (studentB->gpa > studentA->gpa) return 1;
    return 0;
}

void sortStudents(database *db) {
    int sortBy;
    int sortOrder;

    printf("\nPick an option (1-3):\n1) Sort by ID\n2) Sort by name\n3) Sort by GPA\n");
    scanf("%d", &sortBy);
    printf("\nPick an option (1-2):\n1) Sort by ascending\n2) Sort by descending\n");
    scanf("%d", &sortOrder);

    switch (sortBy) {
        case 1:
            qsort(db->ptr, db->count, sizeof(Student), (sortOrder == 1) ? idSortAsc : idSortDes);
            break;
        case 2:
            qsort(db->ptr, db->count, sizeof(Student), (sortOrder == 1) ? nameSortAsc : nameSortDes);
            break;
        case 3:
            qsort(db->ptr, db->count, sizeof(Student), (sortOrder == 1) ? gpaSortAsc : gpaSortDes);
        default:
            printf("Invalid option passed\n");
            break;
    }
}

int fileTime(database *db) {
    FILE *filePtr;
    filePtr = fopen("students.txt", "w");
    for (int i = 0; i < db->count; i++) {
        fprintf(filePtr, "Name: %s, ID: %s, Age: %d, Program: %s, GPA: %.2f, Group: %s\n",
                db->ptr[i].name,
                db->ptr[i].id,
                db->ptr[i].age,
                db->ptr[i].program,
                db->ptr[i].gpa,
                db->ptr[i].group);
    }
    fclose(filePtr);
    return 0;
}

int readToDatabase(database *db) {
    FILE *filePtr;
    char buffer[1000];

    filePtr = fopen("students.txt", "r");
    if (filePtr == NULL) {
        printf("Error opening file!\n");
        return -1;
    }

    // Count lines first to allocate correct memory
    int lineCount = 0;
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL) {
        lineCount++;
    }
    rewind(filePtr); // Go back to start of file

    // Allocate memory for the students
    db->ptr = (Student *) malloc(lineCount * sizeof(Student));
    if (db->ptr == NULL) {
        printf("Memory allocation failed!\n");
        fclose(filePtr);
        return -1;
    }

    // Read and parse each line
    int index = 0;
    while (fgets(buffer, sizeof(buffer), filePtr) != NULL) {
        Student *student = &db->ptr[index];

        // Parse the line - note the spaces after colons match your output format
        if (sscanf(buffer, "Name: %[^,], ID: %[^,], Age: %d, Program: %[^,], GPA: %f, Group: %s",
                   student->name,
                   student->id,
                   &student->age,
                   student->program,
                   &student->gpa,
                   student->group) == 6) {
            index++;
        } else {
            printf("Error parsing line: %s", buffer);
        }
    }

    db->count = index; // Update actual count of successfully read students

    fclose(filePtr);
    return 0;
}


int main(void) {
    database db = {NULL, 0};
    if ("students.txt" != NULL) {
        readToDatabase(&db);
    }

    int input;

    do {
        printf("\nPick an option (1-7):\n1) Add Student\n2) Display All Students\n3) Search for a Student\n"
            "4) Delete a Student\n5) List All Group Members\n6) Sort Students\n7) Saves to File\n8) Exit program\n");

        if (scanf("%d", &input) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {
            };
        }
        switch (input) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                displayAllStudents(&db);
                break;
            case 3:
                searchStudent(&db);
                break;
            case 4:
                deleteStudent(&db);
                break;
            case 5:
                listStudentGroup(&db);
                break;
            case 6:
                sortStudents(&db);
                break;
            case 7:
                fileTime(&db);
                break;
            case 8: printf("Exit the program");
                break;
            default: printf("Wrong choice");
        }
    } while (input != 8);
}


