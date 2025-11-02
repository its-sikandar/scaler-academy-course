 #include <stdio.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
int solve(int* A, int n1, int B) {
    int idx, jdx;

    if (n1 <= 1) { 
        return 0;
    }
    for (idx = 0; idx < n1; idx++) {
        for (jdx= 0; jdx < n1; jdx++) {
            if (idx == jdx) {
                continue;
            } else {
                if ((A[idx] + A[jdx]) == B) {
                    return 1;
                }
                
            }
        }
    }
    return 0;
}



int main() {
    int A[] = {1, 2, 3, 4, 5};
    int n1 = 5;
    int B = 7;
    
    int result = solve(A, n1, B);
    
    if (result == 1) {
        printf("Good pair found\n");
    } else {
        printf("No good pair found\n");
    }
    
    return 0;
}