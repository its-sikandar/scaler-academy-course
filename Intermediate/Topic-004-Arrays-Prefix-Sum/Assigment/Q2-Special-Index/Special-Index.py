class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        n = len(A)
        psum_even = [0] * n
        psum_odd = [0] * n
        psum_even[0] = A[0]
        psum_odd[0] = 0
        # Create the array of prefix sum of even and odd;
        for i in range(1,n):
            if(i%2==0):
                psum_even[i] = psum_even[i - 1] + A[i]
                psum_odd[i] = psum_odd[i -1]
            else:
                psum_even[i] = psum_even[i - 1]
                psum_odd[i] = psum_odd[i - 1] + A[i]
        
        # find the indices for which sum of even and odd indeices are equal

        count = 0

        
        for i in range (n):
            if (i == 0) :
                sum_e = psum_odd[n -1]
                sum_o = psum_even[n -1]
            else:
                sum_e = psum_even[i - 1] + (psum_odd[n - 1] - psum_odd[i])
                sum_o = psum_odd[i - 1] + (psum_even[n - 1] - psum_even[i])
            
            if sum_e == sum_o:
                count += 1

        
        return count


