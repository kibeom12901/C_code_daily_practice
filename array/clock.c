// Online C compiler to run C program online
#include <stdio.h>

int main() {

    int hr, min, add, total_min;
    scanf("%d %d", &hr, &min);
    scanf("%d", &add);
    
    total_min = hr *60 + min + add;
    
    if(total_min < 1440){
     printf("%d %d",total_min/60, total_min%60); 
    } else{
     printf("%d %d",(total_min-1440)/60, (total_min-1440)%60); 
    }

    return 0;
}
