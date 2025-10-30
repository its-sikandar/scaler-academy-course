class Solution:
    def count_factor(self, n):
        count = 0
        for i in range(1, int(n**0.5) + 1):
            if n % i == 0:
                if i * i == n:
                    count += 1
                else:
                    count += 2
        return count

    def is_prime(self, n):
        if n <= 1:
            return 0
        if self.count_factor(n) == 2:
            return 1
        else:
            return 0

    def solve(self, n):
        return self.is_prime(n)


## Runner code
if __name__ == "__main__":
    number = int(input("Enter the positive integer: "))
    solution = Solution()
    result = solution.solve(number)
    if result == 1:
        print(f"{number} is a prime number.")
    else:
        print(f"{number} is not a prime number.")
