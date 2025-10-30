#include <stdio.h>

int perfect_number(int A) {
     if (A < 1) {
        return 0;
    }

     int idx;
     int sum = 0;
     for (idx = 1; idx <= A/2; idx++) {
         if (A % idx == 0) {
             sum += idx;
         }
     }
     if ( sum == A) {
         return 1;
     } else {
         return 0;
     }
 }
int solve(int A) {
    return perfect_number(A);
}


// Runner code
int main() {
    int number;
    printf("Enter the positive integer: ");
    scanf("%d", &number);

    int prime_status = solve(number);
    if (prime_status) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}