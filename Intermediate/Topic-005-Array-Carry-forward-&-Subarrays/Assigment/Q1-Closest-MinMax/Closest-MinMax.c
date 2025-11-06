/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

 int max(int *A, int n1) {
     int max = A[0], idx;
     for(idx = 1; idx < n1; idx++) {
         if (A[idx] > max) {
             max = A[idx];
         }
     }
     return max;
 }

 int min(int *A, int n1) {
     int min = A[0], idx;
     for(idx = 1; idx < n1; idx++) {
         if (A[idx] < min) {
             min = A[idx];
         }
     }
     return min;
 }
int solve(int* A, int n1) {

    int min_val = min(A, n1);
    int max_val = max(A, n1);


    int ans= n1, last_max_idx = -1, last_min_idx = -1;

    int idx, len;
    for (idx = 0; idx < n1; idx++) {
        if (A[idx] == max_val) 
            last_max_idx = idx;
        if (A[idx] == min_val)
            last_min_idx = idx;
            
        if ((last_min_idx != -1) && (last_max_idx != -1)) {
                len = (last_max_idx > last_min_idx) ? (last_max_idx - last_min_idx + 1) : (last_min_idx - last_max_idx +1);
                
                ans = ans < len ? ans : len;
            }
        }
    
    return ans;

}
