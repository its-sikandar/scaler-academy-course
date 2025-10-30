

def count_factor(num):
    count = 0

    for i in range (1, int (num**0.5) + 1):
        if (num%i == 0):
            if i * i == num:
                count += 1
            else:
                count += 2
    return count

def is_prime(num):
    if (count_factor(num) == 2):
        return 1
    else:
        return 0

def total_number_of_prime(A):
    count = 0

    if A <= 1:
        return 0
    
    for i in range(2, A + 1):
        if is_prime(i):
            count += 1

    return count

class Solution:
    # @param A : integer
    # @return an integer
    def solve(self, A):
        return total_number_of_prime(A)

## Runner code
if __name__ == "__main__":
    number = int(input("Enter the positive integer: "))
    solution = Solution()
    result = solution.solve(number)
    if result > 0:
        print(f"{result} is a total_number_of_prime number for {number}.")
    else:
        print(f"{result} is not a total_number_of_prime number for {number}.")