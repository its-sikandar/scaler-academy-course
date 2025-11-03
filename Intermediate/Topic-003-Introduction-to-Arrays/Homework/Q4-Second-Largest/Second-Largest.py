def next_max(A):
    if len(A) < 2:
        return -1


    max = float('-inf')
    next_max = float('-inf')

    for i in range(len(A)):
        if (A[i] > max):
            next_max = max
            max = A[i]
        elif ((A[i] < max) and (A[i] > next_max )):
            next_max = A[i]

    if next_max == float('-inf'):
        return -1
    return next_max

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):

        return next_max(A)
