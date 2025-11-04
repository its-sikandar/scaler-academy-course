# Q4. Special Index

**Status:** ✅ Solved  
**Difficulty:** Medium  
**Topic:** Arrays - Prefix Sum

---

## Problem Description

Given an array **arr[]** of size **N**, the task is to find the count of array indices such that removing an element from these indices makes the sum of **even-indexed** and **odd-indexed** array elements equal.

**Note:** After removing an element, the array elements are re-indexed starting from 0.

---

## Problem Constraints

- `1 <= N <= 10^5`
- `-10^5 <= A[i] <= 10^5`
- `Sum of all elements of A <= 10^9`

---

## Input Format

First argument contains an array **A** of integers of size **N**.

---

## Output Format

Return the count of array indices such that removing an element from these indices makes the sum of even-indexed and odd-indexed array elements equal.

---

## Example Input & Output

### Example 1:
**Input:**
```
A = [2, 1, 6, 4]
```

**Output:**
```
1
```

**Explanation:**
- Removing `arr[1]` from the array modifies `arr[]` to `{2, 6, 4}`
- After removal: `arr[0] + arr[2] = 2 + 4 = 6` and `arr[1] = 6`
- Sum of even indices = Sum of odd indices = 6
- Therefore, the required output is **1**.

### Example 2:
**Input:**
```
A = [1, 1, 1]
```

**Output:**
```
3
```

**Explanation:**
- **Removing arr[0]:** Array becomes `{1, 1}` → `arr[0] = arr[1] = 1` ✅
- **Removing arr[1]:** Array becomes `{1, 1}` → `arr[0] = arr[1] = 1` ✅  
- **Removing arr[2]:** Array becomes `{1, 1}` → `arr[0] = arr[1] = 1` ✅
- Therefore, the required output is **3**.

---

## Approach

### Brute Force Approach:
1. For each index i from 0 to N-1:
   - Remove element at index i
   - Calculate sum of even and odd indexed elements in the new array
   - Check if both sums are equal
2. **Time Complexity:** O(N²)
3. **Space Complexity:** O(1)

### Optimized Approach (Prefix Sum):
1. **Key Insight:** When we remove element at index `i`, all elements after index `i` shift left by one position
   - Elements that were at even indices become odd indices
   - Elements that were at odd indices become even indices

2. **Algorithm:**
   - Create two prefix sum arrays:
     - `P_even[i]` = sum of elements at even indices from 0 to i
     - `P_odd[i]` = sum of elements at odd indices from 0 to i
   
   - For each index `i` to remove:
     - **Sum_even_after_removal** = `P_even[i-1] + (P_odd[N-1] - P_odd[i])`
     - **Sum_odd_after_removal** = `P_odd[i-1] + (P_even[N-1] - P_even[i])`
     - If both sums are equal, increment count

3. **Time Complexity:** O(N)
4. **Space Complexity:** O(N)

---

## Key Insights

- **Index Shifting:** Critical to understand how removal affects indices
- **Prefix Sum Optimization:** Avoid recalculating sums for each removal
- **Edge Cases:** Handle removal of first element (i=0) separately
- **Even/Odd Separation:** Maintain separate prefix sums for even and odd indices

---

## Step-by-Step Example

For `A = [2, 1, 6, 4]`:

**Step 1:** Create prefix sum arrays
```
Original:  [2, 1, 6, 4]
Indices:   [0, 1, 2, 3]
P_even:    [2, 2, 8, 8]  (sum of elements at even indices)
P_odd:     [0, 1, 1, 5]  (sum of elements at odd indices)
```

**Step 2:** Check each removal
- **Remove index 0:** Sum_even = 1, Sum_odd = 8 → Not equal
- **Remove index 1:** Sum_even = 6, Sum_odd = 6 → Equal ✅
- **Remove index 2:** Sum_even = 3, Sum_odd = 5 → Not equal  
- **Remove index 3:** Sum_even = 8, Sum_odd = 1 → Not equal

**Result:** Count = 1

---

## Tags
`Arrays` `Prefix Sum` `Even-Odd Indices` `Index Manipulation` `Optimization`