#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 50
#define MAX_CHARACTERS 100

int studentCount = 0;
char studentName[MAX_STUDENTS][MAX_CHARACTERS], studentProgram[MAX_STUDENTS][MAX_CHARACTERS],
        studentGroup[MAX_STUDENTS][MAX_CHARACTERS];
int studentID[MAX_STUDENTS], studentAge[MAX_STUDENTS];
float studentGPA[MAX_STUDENTS];

int actualIntCheck(char input[]) {
    int found = 1;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            found = 0;
        }
    }
    return found;
}

void addStudent() {
    char name[100], program[100], group[50];
    char ID[100], age[100];
    int idInput, ageInput;
    float gpaInput;
    if (studentCount > MAX_STUDENTS) {
        printf("Max students reached.");
        return;
    }


    printf("- Enter a Name:");
    scanf("%s", name);
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            printf("Invalid name format");
            return; // exit out of the function if not alphabet
        }
    }

    printf("- Enter an ID:");
    scanf("%s", ID);
    if (actualIntCheck(ID) == 0) {
        printf("Invalid ID Format\n");
        return;
    }
    idInput = atoi(ID);
    if ((0 >= idInput) || (idInput >= 99999999)) {
        printf("ID out of range.");
        return;
    }
    for (size_t i = 0; i < studentCount; i++) {
        if (idInput == studentID[i]) {
            printf("Student with this ID already exists.");
            return;
        }
    }

    printf("- Enter an Age:");
    scanf("%s", age);
    ageInput = atoi(age);
    if (actualIntCheck(age) == 0) {
        printf("Invalid age\n");
        return;
    }
    for (size_t j = 0; j < studentCount; j++) {
        if (ageInput == studentAge[j]) {
            printf("Student with this ID already exists.");
            return;
        }
    }

    printf("- Enter a Program:");
    scanf("%s", program);
    for (size_t i = 0; program[i] != '\0'; i++) {
        if (!isalpha(program[i])) {
            return; // exit out of the function if not alphabet
        }
    }

    printf("- Enter a GPA:");
    if (!scanf("%f", &gpaInput)) {
        printf("Invalid GPA input\n");
        int c;
        // loop to clear out input buffer!
        while ((c = getchar()) != '\n' && c != EOF) {
        };
        return;
    }

    printf("- Enter a Group(B - BBY or D - DTC):");
    scanf("%s", group);
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            printf("Invalid group format");
            return; // exit out of the function if not alphabet
        }
    }
    // Validates input to be b or d
    if (!(group[0] == 'B' || group[0] == 'b' || group[0] == 'D' || group[0] == 'd')) {
        printf("Invalid group format\n");
        return;
    }


    strcpy(studentName[studentCount], name);

    for (size_t i = 0; program[i] != '\0'; i++) {
        if (!isalpha(program[i])) {
            return; // exit out of the function if not alphabet
        }
    }
    strcpy(studentProgram[studentCount], program);

    for (size_t i = 0; group[i] != '\0'; i++) {
        if (!isalpha(group[i])) {
            return; // exit out of the function if not alphabet
        }
    }
    strcpy(studentGroup[studentCount], group);

    studentID[studentCount] = idInput;
    studentAge[studentCount] = ageInput;
    studentGPA[studentCount] = gpaInput;
    studentCount++;
    printf("\nStudent added successfully\n");
}

void displayAllStudents() {
    if (studentCount == 0) {
        printf("No Student records found.");
    }
    printf("\nGroup BBY\n");
    for (int i = 0; i < studentCount; i++) {
        if (studentGroup[i][0] == 'B' || studentGroup[i][0] == 'b') {
            printf("\nName: %s, ID: %d, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   studentName[i],
                   studentID[i],
                   studentAge[i],
                   studentProgram[i],
                   studentGPA[i],
                   studentGroup[i]);
        }
    }
    printf("\nGroup DTC\n");
    for (int i = 0; i < studentCount; i++) {
        if (studentGroup[i][0] == 'D' || studentGroup[i][0] == 'd') {
            printf("\nName: %s, ID: %d, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   studentName[i],
                   studentID[i],
                   studentAge[i],
                   studentProgram[i],
                   studentGPA[i],
                   studentGroup[i]);
        }
    }
}

void searchStudent() {
    char ID[100];
    int userInput;
    printf("Enter a Student ID to find:");
    scanf("%s", &ID);

    int result = actualIntCheck(ID);

    if (result != 1) {
        printf("invalid ID");
        return;
    }

    userInput = atoi(ID);

    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == userInput) {
            printf("\nName: %s, ID: %d, Age: %d, Program: %s, GPA: %.2f, Group: %s",
                   studentName[i],
                   studentID[i],
                   studentAge[i],
                   studentProgram[i],
                   studentGPA[i],
                   studentGroup[i]);
            return;
        }
    }
    printf("Student ID was not found\n");
}


void deleteStudent() {
    char ID[100];
    int userInput;
    printf("Enter a Student ID to find:");
    scanf("%s", &ID);

    int result = actualIntCheck(ID);

    if (result != 1) {
        printf(
            "You fucked up you dumb stupid bitch your are going to fail the math exam and your mom doesnt love you and i have sex with her.");
        return;
    }

    userInput = atoi(ID);


    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == userInput) {
            for (int j = i; j < studentCount - 1; j++) {
                strcpy(studentName[j], studentName[j + 1]);
                studentID[j] = studentID[j + 1];
                studentAge[j] = studentAge[j + 1];
                studentGPA[j] = studentGPA[j + 1];
                strcpy(studentProgram[j], studentProgram[j + 1]);
                strcpy(studentGroup[j], studentGroup[j + 1]);
            }
            studentCount--;
            printf("Student is deleted from the world!");
            return;
        }
    }
    printf("ID wasn't found\n");
}

void listStudentGroup() {
    char group[100];
    int userInput;
    char result1 = 'd';
    char result2 = 'b';

    printf("Enter a group(1. BBY / 2. DTC):");
    scanf("%s", &group);

    int result = actualIntCheck(group);

    if (result != 1) {
        printf("Invalid group Input.");
        return;
    }

    userInput = atoi(group);

    if (userInput == 2) {
        printf("\nGroup DTC");
        for (size_t i = 0; i < studentCount; i++) {
            if (result1 == studentGroup[i][0]) {
                printf("\nName: %s, ID: %d, Age: %d, Program: %s, GPA: %.2f, Group: %s\n",
                       studentName[i],
                       studentID[i],
                       studentAge[i],
                       studentProgram[i],
                       studentGPA[i],
                       studentGroup[i]);
            }
        }
    } else if (userInput == 1) {
        printf("\nGroup BBY");
        for (size_t i = 0; i < studentCount; i++) {
            if (result2 == studentGroup[i][0]) {
                printf("\nName: %s, ID: %d, Age: %d, Program: %s, GPA: %.2f, Group: %s \n",
                       studentName[i],
                       studentID[i],
                       studentAge[i],
                       studentProgram[i],
                       studentGPA[i],
                       studentGroup[i]);
            }
        }
    } else {
        printf("\nGroup not recognized\n");
        return;
    }
}

int main(void) {
    int input;

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
                addStudent();
                break;
            case 2:
                displayAllStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                listStudentGroup();
                break;
            case 6: printf("Exit the program");
                break;
            default: printf("Wrong choice");
        }
    } while (input != 6); // continuously asks user for input

}


