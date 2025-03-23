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
}Student;

typedef struct{
    Student *ptr;
    int count;
}database;

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

void addStudent( database *db) {
    db -> ptr= realloc(db->ptr, (db->count + 1) * sizeof(Student));

    Student* newStudent = &db->ptr[db->count]; //Making space in library for new book

    printf("Enter a name: ");
    scanf("%s", newStudent->name);
    printf("Enter a id: ");
    scanf("%s", newStudent->id);
    getchar();
    printf("Enter an age: ");
    scanf("%d", &newStudent->age);

    printf("Enter a program: ");
    scanf("%s", newStudent->program);
    getchar();
    printf("Enter a gpa: ");
    scanf("%d", &newStudent->gpa);

    printf("Enter a group:");
    scanf("%s", &newStudent->group);



    for (size_t i = 0; newStudent->name[i] != '\0'; i++) {
        if (!isalpha(newStudent->name[i])) {
            printf("Invalid name format");
            return; // exit out of the function if not alphabet
        }
    }

    if (validateIdInput(newStudent->id) == 0) {
        printf("Invalid ID Format\n");
        return;
    }

    // for (size_t i = 0; i < *studentCount; i++) {
    //     if (newStudent->id == students[i] -> id) {
    //         printf("Student with this ID already exists.");
    //         return;
    //     }
    // }


    // newStudent->age = atoi(newStudent->age);
    // if (actualIntCheck(newStudent->age) == 0) {
    //     printf("Invalid age\n");
    //     return;
    // }

    // for (size_t i = 0; newStudent->program[i] != '\0'; i++) {
    //     if (!isalpha(newStudent->program[i])) {
    //         return; // exit out of the function if not alphabet
    //     }
    // }
    //
    //
    // if (!scanf("%f", &newStudent->gpa)) {
    //     printf("Invalid GPA input\n");
    //     int c;
    //     // loop to clear out input buffer!
    //     while ((c = getchar()) != '\n' && c != EOF) {
    //     };
    //     return;
    // }
    //
    // printf("- Enter a Group(B - BBY or D - DTC):");
    // scanf("%s", newStudent->group);
    // for (size_t i = 0; newStudent->group[i] != '\0'; i++) {
    //     if (!isalpha(newStudent->group[i])) {
    //         printf("Invalid group format");
    //         return; // exit out of the function if not alphabet
    //     }
    // }
    // // Validates input to be b or d
    // if (!(newStudent->group[0] == 'B' || newStudent->group[0] == 'b' ||
    // newStudent->group[0] == 'D' || newStudent->group[0] == 'd')) {
    //     printf("Invalid group format\n");
    //     return;
    // }


//    strcpy(studentName[*studentCount], name);

    // for (size_t i = 0; newStudent->program[i] != '\0'; i++) {
    //     if (!isalpha(newStudent->program[i])) {
    //         printf("Invalid program format");
    //         return; // exit out of the function if not alphabet
    //     }
    // }
    //
    //
    //
    // for (size_t i = 0; newStudent->group[i] != '\0'; i++) {
    //     if (!isalpha(newStudent->group[i])) {
    //         printf("Invalid group format");
    //         return; // exit out of the function if not alphabet
    //     }
    // }
//    strcpy(newStudent.group[*studentCount], newStudent.group);

//    studentID[*studentCount] = idInput;
//    studentAge[*studentCount] = ageInput;
//    studentGPA[*studentCount] = gpaInput;
   // Student *temp = realloc(students, sizeof(Student) * (*studentCount));
   //
   //  *students = temp;


    // students[*studentCount] = newStudent;
    db->count++;
    printf("\nStudent added successfully\n");
}

void displayAllStudents(const database *db) {
    if (db->count == 0) {
        printf("No Student records found.");
    }
    printf("\nGroup BBY\n");
    for (int i = 0; i < db -> count; i++) {
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
    for (int i = 0; i < db -> count; i++) {
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

    if (!validateIdInput(ID)){
        printf("Invalid ID");
        return;
    }

    for (int i = 0; i < db -> count; i++) {
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
    for (int i = 0; i < db -> count; i++) {
        if (strcmp(db->ptr[i].id, ID) == 0) {
            index = i;
            break;
        }
    }
    if (index == 0) {
        printf("Student ID was not found\n");
    }

    for (int i = index; i < db -> count; i++) {
        db->ptr[i] = db->ptr[i + 1];
    }
    db->count--;
    if (db -> count > 0) {
        Student *temp = realloc(db->ptr, (db -> count) * sizeof(Student));
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
        for (int i = 0; i < db -> count; i++) {
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
    }else if (userInput == 1) {
        printf("\nGroup BBY");
        for (int i = 0; i < db -> count; i++) {
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
    }else {
        printf("\nGroup not recognized\n");
    }
}
void populateSampleData(database *db) {
    db->ptr = realloc(db->ptr, 4 * sizeof(Student));
    if (db->ptr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    Student *s1 = &db->ptr[0];
    strcpy(s1->name, "John Doe");
    strcpy(s1->id, "A12345678");
    s1->age = 20;
    strcpy(s1->program, "Computer Science");
    s1->gpa = 3.50;
    strcpy(s1->group, "b");

    Student *s2 = &db->ptr[1];
    strcpy(s2->name, "Alice Brown");
    strcpy(s2->id, "A23456789");
    s2->age = 19;
    strcpy(s2->program, "Software Engineering");
    s2->gpa = 3.75;
    strcpy(s2->group, "b");

    Student *s3 = &db->ptr[2];
    strcpy(s3->name, "Bob Smith");
    strcpy(s3->id, "A34567890");
    s3->age = 21;
    strcpy(s3->program, "Mechanical Engineering");
    s3->gpa = 3.20;
    strcpy(s3->group, "d");

    Student *s4 = &db->ptr[3];
    strcpy(s4->name, "Emma Wilson");
    strcpy(s4->id, "A45678901");
    s4->age = 22;
    strcpy(s4->program, "Electrical Engineering");
    s4->gpa = 3.90;
    strcpy(s4->group, "d");

    db->count = 4;
}

int main(void) {
    int MAX_STUDENTS = 50;
    int MAX_CHARACTERS = 100;
    database db ={NULL, 0};
    populateSampleData(&db);
    int studentCount = 0;

    Student *students[10]; // Student**
    int input;
//
    do {
        printf("\nPick an option (1-6):\n1) Add Student\n2) Display All Students\n3) Search for a Student\n"
            "4) Delete a Student\n5) List All Group Members\n6) Exit the Program\n");

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
                break;
            case 7: printf("Exit the program");
                break;
            default: printf("Wrong choice");
        }
    } while (input != 6); // continuously asks user for input
}
