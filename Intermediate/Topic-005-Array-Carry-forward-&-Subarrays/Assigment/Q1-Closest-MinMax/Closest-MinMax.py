class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        max_arr = max(A)
        min_arr = min(A)



        ans = len(A)
        last_min_idx = -1
        last_max_idx = -1


        for i in range(len(A)):
            if (A[i] == max_arr):
                if (last_min_idx != -1):
                    ans = min(ans, (i - last_min_idx + 1))
                last_max_idx = i
            if (A[i] == min_arr):
                if (last_max_idx != -1):
                    ans = min(ans, (i - last_max_idx +1))
                last_min_idx = i
        
        return ans

