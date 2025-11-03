def reverse(A, start, end):
    i = start
    j = end
    
    while (i < j):
        temp = A[i]
        A[i] = A[j]
        A[j] = temp

        i += 1
        j -= 1

    return A 

    

class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return a list of integers
    def solve(self, A, B):

        if len(A) <= 1: 
            return A 
        
        B = B % len(A)
        if (B == 0):
            return A 

        reverse(A, 0, len(A) - 1)
        reverse(A, 0, B - 1)
        reverse(A, B, len(A) - 1)


        return A 
    

