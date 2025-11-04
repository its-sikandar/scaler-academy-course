class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        total_sum = sum(A)
        left_sum=0
   
        for i in range(len(A)):
            right_sum = total_sum - left_sum - A[i]

            if right_sum == left_sum :
                return i
            left_sum += A[i]
        return -1
