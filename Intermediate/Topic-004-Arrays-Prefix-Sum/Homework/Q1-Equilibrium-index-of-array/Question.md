# Q2. Equilibrium Index of an Array


**Topic:** Arrays - Prefix Sum  


---

## Problem Description

You are given an array **A** of integers of size **N**.

Your task is to find the **equilibrium index** of the given array.

The **equilibrium index** of an array is an index such that the sum of elements at **lower indexes** is equal to the sum of elements at **higher indexes**.

If there are no elements that are at lower indexes or at higher indexes, then the corresponding sum of elements is considered as **0**.

---

## Important Notes

- Array indexing starts from **0**
- If there is **no equilibrium index** then return **-1**
- If there are **more than one equilibrium indexes** then return the **minimum index**

---

## Problem Constraints

- `1 <= N <= 10^5`
- `-10^5 <= A[i] <= 10^5`

---

## Input Format

First argument is an array **A**.

---

## Output Format

Return the equilibrium index of the given array. If no such index is found then return **-1**.

---

## Example Input & Output

### Example 1:
**Input:**
```
A = [-7, 1, 5, 2, -4, 3, 0]
```

**Output:**
```
3
```

**Explanation:**

| i | Sum of elements at lower indexes | Sum of elements at higher indexes |
|---|----------------------------------|-----------------------------------|
| 0 | 0                               | 7                                |
| 1 | -7                              | 6                                |
| 2 | -6                              | 1                                |
| 3 | -1                              | -1                               |
| 4 | 1                               | 3                                |
| 5 | -3                              | 0                                |
| 6 | 0                               | 0                                |

**Index 3** is an equilibrium index because:  
`A[0] + A[1] + A[2] = A[4] + A[5] + A[6]`  
`(-7) + 1 + 5 = (-4) + 3 + 0`  
`-1 = -1` ✅

### Example 2:
**Input:**
```
A = [1, 2, 3]
```

**Output:**
```
-1
```

**Explanation:**

| i | Sum of elements at lower indexes | Sum of elements at higher indexes |
|---|----------------------------------|-----------------------------------|
| 0 | 0                               | 5                                |
| 1 | 1                               | 3                                |
| 2 | 3                               | 0                                |

Thus, there is **no equilibrium index**.

---

## Approach

### Brute Force Approach:
```c
for (int i = 0; i < N; i++) {
    int left_sum = 0, right_sum = 0;
    
    // Calculate left sum
    for (int j = 0; j < i; j++) {
        left_sum += A[j];
    }
    
    // Calculate right sum  
    for (int j = i + 1; j < N; j++) {
        right_sum += A[j];
    }
    
    if (left_sum == right_sum) {
        return i;
    }
}
return -1;
```
**Time Complexity:** O(N²)  
**Space Complexity:** O(1)

### Optimized Approach (Using Total Sum):
```c
// Calculate total sum
int total_sum = 0;
for (int i = 0; i < N; i++) {
    total_sum += A[i];
}

int left_sum = 0;
for (int i = 0; i < N; i++) {
    // Right sum = total_sum - left_sum - A[i]
    int right_sum = total_sum - left_sum - A[i];
    
    if (left_sum == right_sum) {
        return i;
    }
    
    left_sum += A[i];
}
return -1;
```
**Time Complexity:** O(N)  
**Space Complexity:** O(1)

### Alternative: Using Prefix Sum Array
```c
// Create prefix sum array
int prefix[N];
prefix[0] = A[0];
for (int i = 1; i < N; i++) {
    prefix[i] = prefix[i-1] + A[i];
}

for (int i = 0; i < N; i++) {
    int left_sum = (i == 0) ? 0 : prefix[i-1];
    int right_sum = prefix[N-1] - prefix[i];
    
    if (left_sum == right_sum) {
        return i;
    }
}
return -1;
```
**Time Complexity:** O(N)  
**Space Complexity:** O(N)

---

## Key Insights

1. **Equilibrium Condition:** `left_sum = right_sum`
2. **Total Sum Relationship:** `left_sum + A[i] + right_sum = total_sum`
3. **Optimization:** Use total sum to avoid recalculating right sum
4. **Edge Cases:** Handle first and last elements properly
5. **Multiple Solutions:** Return the minimum index

---

## Step-by-Step Example

For `A = [-7, 1, 5, 2, -4, 3, 0]` with `total_sum = 0`:

```
i=0: left_sum=0, right_sum=0-0-(-7)=7  → 0≠7
i=1: left_sum=-7, right_sum=0-(-7)-1=6 → -7≠6
i=2: left_sum=-6, right_sum=0-(-6)-5=1 → -6≠1
i=3: left_sum=-1, right_sum=0-(-1)-2=-1 → -1=-1 ✅
```

**Result:** Return index **3**

---

## Edge Cases

1. **Single Element:** `[5]` → Index 0 (left_sum=0, right_sum=0)
2. **All Zeros:** `[0,0,0]` → Index 0 (first equilibrium)
3. **No Solution:** `[1,2,3]` → Return -1
4. **Negative Numbers:** Handle properly in sum calculations

---
