#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    int score;
} Student;

void grade_scheme(Student *students, int n);

int main() {
    int n;
    printf("How many students are in your class: ");
    scanf("%d", &n);

    Student *students = (Student*) malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter student ID and grade for student %d: ", i + 1);
        scanf("%d %d", &students[i].id, &students[i].score);
    }

    grade_scheme(students, n);

    free(students);
    return 0;
}

void grade_scheme(Student *students, int n) {
    int A = 0, B = 0, C = 0, D = 0, F = 0;
    int max = 0, min = 100;
    float sum = 0.0;

    for (int i = 0; i < n; i++) {
        if (students[i].score >= 90) {
            A++;
        } else if (students[i].score >= 80) {
            B++;
        } else if (students[i].score >= 70) {
            C++;
        } else if (students[i].score >= 60) {
            D++;
        } else {
            F++;
        }

        // Updating max and min grades
        if (students[i].score > max) {
            max = students[i].score;
        }
        if (students[i].score < min) {
            min = students[i].score;
        }

        sum += students[i].score;
    }

    // Printing results
    printf("There were %d A's.\n", A);
    printf("There were %d B's.\n", B);
    printf("There were %d C's.\n", C);
    printf("There were %d D's.\n", D);
    printf("There were %d F's.\n", F);
    printf("The highest grade was %d.\n", max);
    printf("The lowest grade was %d.\n", min);
    printf("The mean was %.2f.\n", sum / n);
}
