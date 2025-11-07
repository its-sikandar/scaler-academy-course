/**
 * @input A : String termination by '\0'
 * 
 * @Output Long
 */
long long solve(char* A) {
    long long count = 0;
    long long count_a = 0;
    int i;
    for (i = 0; A[i] != '\0'; i++) {
        if (A[i] == 'A') {
            count_a += 1;
        }

        if (A[i] == 'G') {
            count += count_a;
        }
    }

    return count;
}
