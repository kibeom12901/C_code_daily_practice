// Online C compiler to run C program online
#include <stdio.h>

struct Student{
    char name[100];
    int first, second, third;
};

int main() {
    // Write C code here
    int n;
    scanf("%d",&n);
    
    struct Student students[100];
    
    for(int i=0;i<n;i++){
        scanf("%s %d %d %d", &students[i].name, &students[i].first, &students[i].second, &students[i].third);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(students[j+1].first > students[j].first){
                struct Student temp = students[j+1];
                students[j+1] = students[j];
                students[j] = temp;
            }
        }
    }

    struct Student topStudent = students[0];
    
    int rank_second = 1, rank_third = 1;
    
    for(int i=1;i<n;i++){
        if(students[i].second>students[0].second){
            rank_second++;
        }

        if(students[i].third>students[0].third){
            rank_third++;
        }
    }
    
        printf("%s %d %d", topStudent.name, rank_second, rank_third);

    return 0;
}

Input:
4
Jeon 95 80 100
Kim 59 85 75
Lee 90 100 75
Bae 100 82 80

Output:
Bae 3 2
