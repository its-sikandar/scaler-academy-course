/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int solve(int* A, int n1) {
    int i, total, left_sum = 0;

    for (i = 0; i < n1; i++) {
        total += A[i];
    }

    for (i = 0; i < n1; i++) {
        int right_sum;
        right_sum = total - left_sum - A[i];

        if (right_sum == left_sum) {
            return i;
        }

        left_sum += A[i];
    }

    return -1;
}
