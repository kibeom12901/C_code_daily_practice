#include <stdio.h>

int main() {
    // Write C code here
    int numb[50], n, min;
    scanf("%d", &n);
    
    for(int i=0;i < n-1; i++){
        scanf("%d", &numb[i]);
    }
    
    int sum, add, missing;
    sum = n * (n + 1) / 2;
    
    for(int j=0;j<n-1;j++){
        add += numb[j];
    }
    
    missing = sum - add;
    printf("%d", missing);
    
    return 0;
}

output:
10
3
4
1
10
2
6
7
5
9

8



