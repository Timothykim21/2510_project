#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 50
#define MAX_CHARACTERS 100

int studentCount = 0;
char studentName[MAX_STUDENTS][MAX_CHARACTERS], studentProgram[MAX_STUDENTS][MAX_CHARACTERS],
studentGroup[MAX_STUDENTS][MAX_CHARACTERS];
int  studentID[MAX_STUDENTS], studentAge[MAX_STUDENTS];
float studentGPA[MAX_STUDENTS];

// initialise all empty
void initStudentIDs(int idArray[]) {
    for (size_t i = 0; i < MAX_STUDENTS; i++) {
        idArray[i] = -1;
    }
}

void addStudent(char name[], int ID, int age, char program[], float gpa, char group[]) {
    if (studentCount > MAX_STUDENTS){
        printf("Max students reached.");
        return;
    }
    for (size_t i = 0; name[i] != '\0'; i++) {
        if (!isalpha(name[i])) {
            return; // exit out of the function if not alphabet
        }
    }strcpy(studentName[studentCount], name);
    for (size_t i = 0; program[i] != '\0'; i++) {
        if (!isalpha(program[i])) {

            return; // exit out of the function if not alphabet
        }
    }strcpy(studentProgram[studentCount], program);
    for (size_t i = 0; group[i] != '\0'; i++) {
        if (!isalpha(group[i])) {
            return; // exit out of the function if not alphabet
        }
    }strcpy(studentGroup[studentCount], group);
    if (!isdigit(ID) && (0 >= ID) || (ID >= 99999999)) {
        return;
    }

    for (size_t i = 0; i < studentCount; i++) {
        if (ID == studentID[i]) {
            printf("Student with this ID already exists.");
            return;
        }
    }
    studentID[studentCount] = ID;
    studentAge[studentCount] = age;
    studentGPA[studentCount] = gpa;
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
    int ID;
    printf("Enter a Student ID to find:");
    scanf("%d", &ID);
    for (int i = 0; i < studentCount; i++) {
        if (studentID[i] == ID) {
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


void deleteStudent() {
       int ID;
       printf("Enter a ID to be Deleted.");
       scanf("%d", &ID);
       for(int i = 0; i < studentCount; i++){
           if(studentID[i] == ID){
                for(int j = i; j < studentCount - 1; j++){
                      strcpy(studentName[j], studentName[j+1]);
                       studentID[j] = studentID[j + 1];
                       studentAge[j] = studentAge[j + 1];
                       studentGPA[j] = studentGPA[j + 1];
                       strcpy(studentProgram[j], studentProgram[j+1]);
                       strcpy(studentGroup[j], studentGroup[j+1]);
                }
                 studentCount--;
                 printf("Student is deleted from the world!");
                 return;
           }
      }
  }

void listStudentGroup() {
    int input = 0;
    char result1 = 'd';
    char result2 = 'b';
    printf("Enter a group(1. BBY / 2. DTC):");
    scanf("%d", &input);
    //input = atoi(pre_input);
    if (!isdigit(input)){
        return;
    }
    if ((input != 1) && (input !=2)){
        return;
    }

    if(input == 2){
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

    } else if(input == 1){
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
    printf("\nGroup not recognized");
   }
}

int main(void) {
    char name[100], program[100], group[50];
    int ID, age;
    float gpa;
    char pre_input[128];
    int input;
    do{

        printf("\nPick an option (1-6):\n1) Add Student\n2) Display All Students\n3) Search for a Student\n"
                "4) Delete a Student\n5) List All Group Members\n6) Exit the Program\n");

        while (!isdigit(pre_input[0])) {
            scanf("%s", &pre_input);
        }

        input = atoi(pre_input);

       switch(input){

         case 1:

              printf("- Enter a Name:");
              scanf("%s", name);
              if (!isalpha(name)){
                  printf("sit dog.");
                  break;
              }

              printf("- Enter a ID:");
              scanf("%d", &ID);


              printf("- Enter an Age:");
              scanf("%d", &age);
              if (!isdigit(age)){
                  printf("sit dog.");
                  break;
              }

              printf("- Enter a Program:");
              scanf("%s", program);
            if (!isalpha(program)){
                printf("sit dog.");
                break;
            }


              printf("- Enter a GPA:");
              scanf("%f", &gpa);
              if (!isdigit(gpa)){
                  printf("sit dog.");
                  break;
              }

              printf("- Enter a Group(B - BBY or D - DTC):");
              scanf("%s", group);
            if (!isalpha(group)){
                printf("sit dog.");
                break;
            }


              addStudent(name, ID, age, program, gpa, group);



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
         case 6: printf("Exit the program"); break;
         default: printf("Wrong choice");
       }
    } while(input != 6 );           // continuously asks user for input
   return 0;
}

