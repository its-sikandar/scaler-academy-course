# Q7. In-place Prefix Sum

**Topic:** Arrays - Prefix Sum

---

## Problem Description

Given an array **A** of **N** integers. Construct prefix sum of the array **in the given array itself**.

**Key Point:** Modify the original array to store the prefix sum without using extra space.

---

## Problem Constraints

- `1 <= N <= 10^5`
- `1 <= A[i] <= 10^3`

---

## Input Format

Only argument **A** is an array of integers.

---

## Output Format

Return an array of integers denoting the prefix sum of the given array.

---

## Example Input & Output

### Example 1:
**Input:**
```
A = [1, 2, 3, 4, 5]
```

**Output:**
```
[1, 3, 6, 10, 15]
```

**Explanation:**
- `A[0] = 1` (remains same)
- `A[1] = 1 + 2 = 3`
- `A[2] = 3 + 3 = 6`
- `A[3] = 6 + 4 = 10`
- `A[4] = 10 + 5 = 15`

### Example 2:
**Input:**
```
A = [4, 3, 2]
```

**Output:**
```
[4, 7, 9]
```

**Explanation:**
- `A[0] = 4` (remains same)
- `A[1] = 4 + 3 = 7`
- `A[2] = 7 + 2 = 9`

---

## Approach

### In-place Modification Algorithm:
```c
// Modify the same array to store prefix sum
// A[0] remains the same
for (int i = 1; i < N; i++) {
    A[i] = A[i-1] + A[i];
}
return A;
```


### Key Insight:
- We can safely overwrite `A[i]` because we've already used its original value
- `A[i-1]` already contains the prefix sum up to index `i-1`
- This ensures we don't lose any information during the process

---

## Complexity Analysis

- **Time Complexity:** O(N) - Single pass through the array
- **Space Complexity:** O(1) - No extra space used (in-place modification)

---




## Alternative Implementation (Functional Style)

```python
def in_place_prefix_sum(A):
    for i in range(1, len(A)):
        A[i] += A[i-1]
    return A
```

---