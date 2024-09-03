// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int a;
    scanf("%d",&a);
    
    for(int i=1;i<a&&i<7;i++){
        for(int j = 1; j<a&&j<7; j++){
            if(i + j == a){
                printf("%d %d\n", i, j);
            }
        }
        
    }
    return 0;
}

Output:
      8
    2 6
    3 5
    4 4
    5 3
    6 2

    
