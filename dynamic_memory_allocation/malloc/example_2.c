// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int name;
}Number ;

int main() {
    // Write C code here
    int i, n;
    printf("Enter the number of integers:\n");
    scanf("%d", &n);

    Number *ptr = (Number*) malloc(n*sizeof(Number));
    
    if(ptr == NULL){
        printf("memory is not available");
        return -1;
    }
    
    for(int i=0; i<n; i++){
        printf("Enter an integer:\n");
        scanf("%d", &(ptr+i)->name);
    }    
    
    for(int i=0;i<n; i++){
        printf("%d\n", (ptr+i)->name);
    }

    free(ptr);
    
    return 0;
}
