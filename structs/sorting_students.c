#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    int index;
    int score;
    int rank;
}Student;

int compare(const void *a, const void *b){
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    return studentB->score - studentA->score;
}

int main() {

    int n;
    scanf("%d", &n);

    Student *students = (Student *)malloc(n*sizeof(Student));

    for(int i=0; i<n; i++){
        scanf("%d", &students[i].score);
        students[i].index = i+1;
    }

    printf("****Check Point for INITIAL STATE*****\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", students[i].score, students[i].index);
    }

    qsort(students, n, sizeof(Student), compare);

    printf("****Check Point for DESCENDING ORDER*****\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", students[i].score, students[i].index);
    }

    for(int i=0; i<n; i++){
        if(i>0 &&students[i].score == students[i-1].score){
            students[i].rank = students[i-1].rank;
        } else{
            students[i].rank = i+1;
        }
    }

    printf("****Check Point for RANK*****\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", students[i].score, students[i].index, students[i].rank);
    }

    printf("****FINAL RESULTS*****\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(students[j].index == i){
                printf("%d %d\n", students[j].score,students[j].rank);
            }
        }
    }

    free(students);
    
    return 0;
}
