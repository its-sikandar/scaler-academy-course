#include <stdio.h>


/*

Function to check if a number is prime

if (n > 1 and count_of_factors == 2) then n is prime

*/



int is_prime(int n);


int count_factors(int n) {

    int count = 0;
    int i;
    for (i = 1; i * i <= n; i ++) {
        if ( n %i == 0) {
            // Perfect square case
            if (i * i  == n) {
                count++;
            } else {
                count += 2;
            }
        }
    }

    return count;
}

int is_prime(int n) {
    if (n <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }

    if (count_factors(n)== 2 ) {
        return 1;
    }

    return 0;
}

int solve(long long n) {
    return is_prime(n);
}

// Runner code
int main() {
    long long number;
    printf("Enter the positive integer: ");
    scanf("%lld", &number);

    int prime_status = solve(number);
    if (prime_status) {
        printf("%lld is a prime number.\n", number);
    } else {
        printf("%lld is not a prime number.\n", number);
    }

    return 0;
}


