class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        min = A[0]
        max = A[0]

        for i in range(len(A)):
            if A[i] < min:
                min = A[i]
            if A[i] > max:
                max = A[i]
        total = max + min
        return total

