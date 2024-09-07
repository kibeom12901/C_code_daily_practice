// Online C compiler to run C program online
#include <stdio.h>

struct Student{
    char name[1003];
    int score;
};

int main() {
    
    int n, f;
    scanf("%d %d", &n, &f);
    
    struct Student students[100];
    
    for(int i = 0; i<n ; i++){
        scanf("%s %d", &students[i].name, &students[i].score);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(students[j].score < students[j+1].score){
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<f;i++){
        printf("%s\n", students[i].name);
    }


    return 0;
}

입력 예시   
4 2
Jeon 95
Kim 59
Lee 90
Bae 100

Output:
Bae
Jeon
