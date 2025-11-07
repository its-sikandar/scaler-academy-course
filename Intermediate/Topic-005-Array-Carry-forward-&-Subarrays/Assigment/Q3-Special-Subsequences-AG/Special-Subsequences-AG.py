class Solution:
    # @param A : string
     # @return an long
    def solve(self, A):
        count = 0
        count_a = 0

        for i in range(len(A)):
            if (A[i] == 'A'):
                count_a += 1
            if (A[i] == 'G'):
                count += count_a
        return count
