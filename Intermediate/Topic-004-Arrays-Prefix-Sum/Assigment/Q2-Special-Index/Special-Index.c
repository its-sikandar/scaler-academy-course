/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int solve(int* A, int n1) {


    int sum_even[n1], sum_odd[n1], sum_e, sum_o, count;

    // Create even and odd prefix sum array

    sum_even[0] = A[0];
    sum_odd[0] = 0;

    int i;
    for (i = 1; i < n1; i++) {
        if (i % 2 == 0) {
            sum_even[i] = sum_even[i - 1] + A[i];
            sum_odd[i] = sum_odd[i - 1]; 
        } else {
            sum_even[i] = sum_even[i - 1];
            sum_odd[i] = sum_odd[i - 1] + A[i];
        }
    }

    // Find the sum of enven indices and odd after removal of indices

    for (i = 0; i < n1; i++) {
        if (i == 0) {
            sum_e = sum_even[0];
            sum_o = sum_odd[0];
        } else {
            sum_e = sum_even[i - 1] + (sum_odd[n1 - 1] - sum_odd[i]);
            sum_o = sum_odd[i - 1] + (sum_even[n1 - 1] - sum_even[i]);
        }

        if (sum_e == sum_o) {
            count += 1;
        }
    }

    return count;


}
