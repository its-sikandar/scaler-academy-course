#include <stdio.h>


/**
 * @input A : Integer
 * 
 * @Output Integer
 */

int count_factor(int num) {
    int count = 0;
    int idx;

    for ( idx = 1; (idx * idx) <= num; idx++ ) {
        if (num %idx == 0) {
            if (idx * idx == num) {
                count += 1;
            } else {
                count +=2;
            }
            
        }
    }
    return count;
}
int is_prime(int num) {
    if (count_factor(num) == 2) {
        return 1;
    }
    return 0;
}
int total_number_of_prime(int A) {

    if (A <= 1) {
        return 0;
    }

    int idx;
    int count = 0;

    for (idx = 2; idx <= A; idx++) {
        if (is_prime(idx)) {
            count++;
        }
    }

return count;

}

int solve(int A) {
    return total_number_of_prime(A);
}

// Runner code
int main() {
    int number;
    printf("Enter the positive integer: ");
    scanf("%d", &number);

    int prime_status = solve(number);
    if (prime_status) {
        printf("%d number have total primes <= %d.\n", number, prime_status);
    } else {
        printf("%d There are no primes <= %d\n", number, prime_status);
    }

    return 0;
}