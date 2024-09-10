#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char name[100];
    char date[100];
    struct Student *partner;
    int printed;
}Student;

void match_students(Student *students, int n);
void print_pairings(Student *students, int n);

int main() {
    
    int n;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    
    Student *students = (Student*) malloc(n*sizeof(Student));

    if (students == NULL) {
        printf("Memory not available.\n");
        return -1;
    }
    
    for(int i=0; i<n; i++){
        printf("Enter the name of the student %d:\n", i+1);
        scanf("%s", students[i].name);
        printf("Enter the available time for student %d (e.g., Morning, Afternoon):\n", i + 1);
        scanf("%s", students[i].date);
        students[i].partner = NULL;
        students[i].printed = 0;
    }
    
    match_students(students, n);
    
    print_pairings(students, n);
    
    return 0;
}

void match_students(Student *students, int n){
    for(int i=0;i<n;i++){
        if(students[i].partner != NULL){
            continue;   
        }
        for(int j=i+1;j<n;j++){
            if(strcmp(students[i].date, students[j].date) == 0){
                students[i].partner = &students[j];
                students[j].partner = &students[i];
                break;
            }
        }
    }
}


//*(student[i].partner).name

void print_pairings(Student *students, int n) {
    for (int i = 0; i < n; i++) {
        if (students[i].partner != NULL && students[i].printed == 0) {
            printf("%s --- %s\n", students[i].name, students[i].partner->name);
            students[i].printed = 1;
            students[i].partner->printed = 1;
        } else if (students[i].partner == NULL && students[i].printed == 0) {
            printf("%s does not have a partner\n", students[i].name);
            students[i].printed = 1;
        }
    }
}

Input:
Enter the number of students:
7
Enter the name of the student 1:
Andrew
Enter the available time for student 1 (e.g., Morning, Afternoon):
Morning
Enter the name of the student 2:
Isabella
Enter the available time for student 2 (e.g., Morning, Afternoon):
Afternoon
Enter the name of the student 3:
Caroline
Enter the available time for student 3 (e.g., Morning, Afternoon):
Evening
Enter the name of the student 4:
Colin
Enter the available time for student 4 (e.g., Morning, Afternoon):
Morning
Enter the name of the student 5:
Eric
Enter the available time for student 5 (e.g., Morning, Afternoon):
Afternoon
Enter the name of the student 6:
Lillian
Enter the available time for student 6 (e.g., Morning, Afternoon):
Afternoon
Enter the name of the student 7:
Sabrina
Enter the available time for student 7 (e.g., Morning, Afternoon):
Evening

Output:
Andrew --- Colin
Isabella --- Eric
Caroline --- Sabrina
Lillian does not have a partner





