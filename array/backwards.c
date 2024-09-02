// Online C compiler to run C program online
#include <stdio.h>

int main() {

    int numb[1000],n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &numb[i]);
    }
    
    for(int j=n-1; j>=0; j--){
        printf("%d", *(numb+j));
    }
    
    return 0;
}

output:
5
1 3 5 6 8

8 6 5 3 1
