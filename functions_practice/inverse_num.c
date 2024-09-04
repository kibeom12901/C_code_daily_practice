// Online C compiler to run C program online
#include <stdio.h>

void inverse(int numb[],int n){
    for(int j = n-1;j>=0;j--){
        printf("%d ",numb[j]);
    }
}

int main() {
    // Write C code here
    int numb[1000],n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d", &numb[i]);
    }

    inverse(numb, n);
    
    return 0;
}
