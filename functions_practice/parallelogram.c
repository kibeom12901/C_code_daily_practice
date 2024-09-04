// Online C compiler to run C program online
#include <stdio.h>

void shape(int n){
    for(int i=n-1;i>=0;i--){
        for(int j= 0; j<i; j++){
            printf(" ");
        }
        for(int k= 0; k<n; k++){
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    // Write C code here
    int n;
    scanf("%d", &n);
    
    shape(n);
    
    return 0;
}

output:
4
   ****
  ****
 ****
****
