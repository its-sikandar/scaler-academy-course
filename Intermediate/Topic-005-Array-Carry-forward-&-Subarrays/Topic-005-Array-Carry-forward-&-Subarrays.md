# Topic 005: Array - Carry Forward & Subarrays

## Quick Revision Tips 📝
- **Carry Forward:** Carry information from previous iterations to optimize current calculation
- **Subarray Count:** Always N(N+1)/2 
- **Min-Max:** Track last positions, min distance between max & min
- **Time Complexity:** Carry forward = O(N), Brute force = O(N²/N³)

---

## 1. Count 'a-g' Pairs
**Problem:** Count pairs (i,j) where i < j, s[i] = 'a', s[j] = 'g'

## Carry Forward: Think backwards! Count 'g's from right, add when finding 'a'

**Carry Forward Solution:** O(N)
```c
int ans = 0, cnt_g = 0;
for (int i = N-1; i >= 0; i--) {
    if (s[i] == 'g') 
        cnt_g++;
    if (s[i] == 'a')
        ans += cnt_g;
}
```
**Key:** Traverse right to left, count 'g's, add to answer when finding 'a'

**💡 Memory Trick:** "a comes before g" → count g's first, then multiply by a's

---

## 2. Subarrays
**Definition:** Contiguous part of array

**Total Subarrays:** N(N+1)/2 for array of size N

**🔢 Quick Examples:**
- N=3: 3×4/2 = 6 subarrays
- N=4: 4×5/2 = 10 subarrays  
- N=5: 5×6/2 = 15 subarrays

**Representation:** 
- (start, end) indices
- (start, length)

---

## 3. Print Subarray
```c
for (int i = si; i <= ei; i++) {
    printf("%d ", arr[i]);
}
```

---

## 4. Print All Subarrays
```c
for (int si = 0; si < N; si++) {        // Start index: 0 to N-1
    for (int ei = si; ei < N; ei++) {    // End index: si to N-1  
        for (int i = si; i <= ei; i++) { // Print elements from si to ei
            printf("%d ", arr[i]);
        }
        printf("\n");                    // New line after each subarray
    }
}
```

**📋 Step-by-Step Logic:**
1. **Loop 1 (si):** Choose starting position 
2. **Loop 2 (ei):** Choose ending position (≥ si)
3. **Loop 3 (i):** Print all elements in range [si, ei]

**🔍 Example:** arr = [1, 2, 3]
- si=0: [1], [1,2], [1,2,3]  
- si=1: [2], [2,3]
- si=2: [3]

**Time:** O(N³)  
**⚠️ Remember:** 3 nested loops = N³ complexity

---

## 5. Min-Max Subarray
**Problem:** Find smallest subarray containing both min and max elements

**Optimized Solution:** O(N)
```c
// Find max and min
int max_val = arr[0], min_val = arr[0];
for (int i = 1; i < N; i++) {
    max_val = max(max_val, arr[i]);
    min_val = min(min_val, arr[i]);
}

if (max_val == min_val) return 1; // All same elements

int ans = N, last_max = -1, last_min = -1;
for (int i = 0; i < N; i++) {
    if (arr[i] == max_val) {
        if (last_min != -1) ans = min(ans, i - last_min + 1);
        last_max = i;
    }
    if (arr[i] == min_val) {
        if (last_max != -1) ans = min(ans, i - last_max + 1);
        last_min = i;
    }
}
```

**Key Points:**
- Track last positions of max/min elements
- Calculate distance when finding opposite element
- Min and max must be endpoints of optimal subarray

**🎯 Pattern Recognition:**
- If you see "both min & max" → think last position tracking
- If you see "pairs where i < j" → think carry forward
- If you see "contiguous" → think subarrays

---

## Key Concepts
1. **Carry Forward:** Optimize by carrying information forward/backward
2. **Subarray Count:** N(N+1)/2
3. **Index Tracking:** Remember last seen positions
4. **Edge Cases:** All same elements, single element arrays

## Common Mistakes to Avoid ❌
- ❌ Forgetting to handle all same elements in min-max
- ❌ Using wrong direction in carry forward (should be right to left for 'a-g')
- ❌ Confusing subarray (contiguous) with subsequence (not contiguous)
- ❌ Off-by-one errors in distance calculations