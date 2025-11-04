# Q3. Range Sum Query

**Status:** ✅ Solved  
**Difficulty:** Easy-Medium  
**Topic:** Arrays - Prefix Sum

---

## Problem Description

You are given an integer array **A** of length **N**.

You are also given a 2D integer array **B** with dimensions **M x 2**, where each row denotes a **[L, R]** query.

For each query, you have to find the sum of all elements from **L** to **R** indices in **A** (0-indexed).

More formally, find **A[L] + A[L + 1] + A[L + 2] +... + A[R - 1] + A[R]** for each query.

---

## Problem Constraints

- `1 <= N, M <= 10^5`
- `1 <= A[i] <= 10^9`
- `0 <= L <= R < N`

---

## Input Format

1. The first argument is the integer array **A**.
2. The second argument is the 2D integer array **B**.

---

## Output Format

Return an integer array of length **M** where **ith** element is the answer for **ith** query in **B**.

---

## Example Input & Output

### Example 1:
**Input:**
```
A = [1, 2, 3, 4, 5]
B = [[0, 3], [1, 2]]
```

**Output:**
```
[10, 5]
```

**Explanation:**
- The sum of all elements of A[0...3] = 1 + 2 + 3 + 4 = **10**
- The sum of all elements of A[1...2] = 2 + 3 = **5**

### Example 2:
**Input:**
```
A = [2, 2, 2]
B = [[0, 0], [1, 2]]
```

**Output:**
```
[2, 4]
```

**Explanation:**
- The sum of all elements of A[0...0] = 2 = **2**
- The sum of all elements of A[1...2] = 2 + 2 = **4**

---

## Approach

### Brute Force Approach:
- For each query [L, R], iterate from L to R and sum all elements
- **Time Complexity:** O(M × N)
- **Space Complexity:** O(1)

### Optimized Approach (Prefix Sum):
1. Create a prefix sum array where `prefix[i] = A[0] + A[1] + ... + A[i]`
2. For each query [L, R]:
   - If L = 0: answer = `prefix[R]`
   - If L > 0: answer = `prefix[R] - prefix[L-1]`
3. **Time Complexity:** O(N + M)
4. **Space Complexity:** O(N)

---

## Key Insights

- **Prefix Sum** is the optimal solution for multiple range sum queries
- Single preprocessing step enables O(1) query answering
- Handle edge case when L = 0 carefully
- Watch out for integer overflow with large arrays

---

## Tags
`Arrays` `Prefix Sum` `Range Queries` `Optimization`