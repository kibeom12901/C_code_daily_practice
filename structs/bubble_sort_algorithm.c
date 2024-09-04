// Online C compiler to run C program online
#include <stdio.h>

struct Device{
    int id;
    int gas_amount;
};

int main() {
    // Write C code here
    int n;
    scanf("%d", &n);
    
    struct Device devices[100];
    
    for(int i=0;i<n;i++){
        scanf("%d %d", &devices[i].id, &devices[i].gas_amount);
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0; j<n-i-1;j++){
            if(devices[j].id>devices[j+1].id){
                struct Device temp = devices[j];
                devices[j] = devices[j+1]; 
                devices[j+1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%d %d\n", devices[i].id, devices[i].gas_amount);
    }
    return 0;
}
