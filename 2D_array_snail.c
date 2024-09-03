#include <stdio.h>

int main() {
    int array[50][50], a;
    scanf("%d", &a);
    
    int top = 0, bottom = a - 1;
    int left = 0, right = a - 1;
    int numb = 1;
    
    while (top <= bottom && left <= right) {
        // Fill the top row from left to right
        for (int i = left; i <= right; i++) {
            array[top][i] = numb++;
        }
        top++;
        
        // Fill the right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            array[i][right] = numb++;
        }
        right--;
        
        // Fill the bottom row from right to left
        for (int i = right; i >= left; i--) {
            array[bottom][i] = numb++;
        }
        bottom--;
        
        // Fill the left column from bottom to top
        for (int i = bottom; i >= top; i--) {
            array[i][left] = numb++;
        }
        left++;
    }

    // Print the snail (spiral) array
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    
    return 0;  
}

output:
3
1 2 3 
8 9 4 
7 6 5 
