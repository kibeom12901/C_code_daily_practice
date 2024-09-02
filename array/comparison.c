// Online C compiler to run C program online
#include <stdio.h>

int main() {

    int numb[1000],n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &numb[i]);
    }
    
    for(int j=0; j<n; j++){
        printf("%d:",j+1);
            for(int k=0; k<n; k++){
            if (j != k) { 
                if(numb[j] < numb[k]) {
                    printf("< ");
                } else if(numb[j] > numb[k]) {
                    printf("> ");
                } else {
                    printf("= ");
                }
            }

            }
        printf("\n");
    }
    
    return 0;
}

output:
5
1 2 3 2 1 

1: < < < = 
2: > < = > 
3: > > > > 
4: > = < > 
5: = < < < 
