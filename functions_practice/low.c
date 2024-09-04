// Online C compiler to run C program online
#include <stdio.h>

void call_low(int numb[], int n){
    int min = numb[0];
    
    for(int j=1;j<n;j++){
        if(numb[j]< min){
            min = numb[j];
        }
    }
    printf("%d",min);
}

int main() {
    
    int numb[10000],n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++){
        scanf("%d", &numb[i]);
    }
    
    call_low(numb, n);
    
    return 0;
}
