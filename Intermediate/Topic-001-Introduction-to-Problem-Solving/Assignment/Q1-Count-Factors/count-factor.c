#include<stdio.h>

int count_factors(int n);



int main() {
    int number;
    printf("Enter the positive integer: ");
    scanf("%d", &number);

    int num_factors = count_factors(number);
    printf("Number of factors of %d is %d\n", number, num_factors);
    
    return 0;
}


int count_factors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n%i == 0) {
            // Perfect square case
            if (i * i == n) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;

}