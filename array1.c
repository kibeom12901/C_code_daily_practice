#include <stdio.h>

int main() {
    // Write C code here
    int numb[1000], n, min;
    scanf("%d", &n);
    
    for(int i=0;i < n; i++){
        scanf("%d", &numb[i]);
        numb[n+i] = numb[i];
    }
    printf("\n");
    
    for(int j = 0; j < n; j++){
        for(int c = j; c < n + j; c++){
        printf("%d ", *(numb+c));
        } 
        printf("\n");
    } 

    
    return 0;
}


output:
5
1 2 3 4 5

1 2 3 4 5 
2 3 4 5 1 
3 4 5 1 2 
4 5 1 2 3 
5 1 2 3 4 
