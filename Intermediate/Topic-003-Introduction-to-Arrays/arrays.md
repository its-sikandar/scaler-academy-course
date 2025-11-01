# Basics of Arrays

Arrays are data structures that store multiple values of the same type in a single variable. Each element is accessed using an index, and the array size is fixed upon creation.

Arrays have several key features:
- **Fixed Size**: Once an array's size is set, it cannot be changed.
- **Homogeneous Elements**: All elements in the array must be of the same data type.
- **Indexed**: Each element in the array can be accessed using its numeric index.
- **Contiguous Memory Allocation**: In most languages, arrays are stored in contiguous blocks of memory, which makes access to elements efficient.

## Declaring Arrays in Different Programming Languages

### Python
Python uses lists, which are more flexible than arrays but serve similar purposes. Lists in Python do not require declaration of size or type ahead of time:
```python
my_list = []  # An empty list
my_list = [1, 2, 3]  # A list with three integers
```

### C++
In C++, arrays are declared by specifying the type, followed by the size in square brackets:
```cpp
int myArray[10]; // Declares an array of 10 integers
```

### C
In C, arrays are declared similarly to C++:
```c
int myArray[10]; // Declares an array of 10 integers
```

## Iterating Over Arrays

Iterating over arrays involves accessing each element in the array sequentially. Here's how you can iterate over arrays in different programming languages:

### Python
In Python, iteration is straightforward using a for loop, as Python's lists are inherently iterable:
```python
my_list = [1, 2, 3, 4, 5]
for element in my_list:
    print(element)
```

### C++
C++ also supports traditional for loops and range-based for loops (since C++11):
```cpp
int myArray[] = {1, 2, 3, 4, 5};
// Traditional for loop
for (int i = 0; i < 5; i++) {
    cout << myArray[i] << endl;
}
// Range-based for loop (C++11 and later)
for (int element : myArray) {
    cout << element << endl;
}
```

### C
C supports traditional for loops:
```c
int myArray[] = {1, 2, 3, 4, 5};
// Traditional for loop
for (int i = 0; i < 5; i++) {
    printf("%d\n", myArray[i]);
}
```

## Dynamic Arrays

### Python
Python lists are inherently dynamic:
```python
my_list.append(6)  # Adding an element to the end of the list
```

### C++
In C++, std::vector is the equivalent of a dynamic array:
```cpp
vector<int> myVector;
myVector.push_back(1);  // Adding elements dynamically
```

### C
C doesn't have built-in dynamic arrays, but you can use malloc/realloc for dynamic memory allocation:
```c
int* myArray = malloc(10 * sizeof(int));  // Allocate memory for 10 integers
// Use realloc to resize if needed
myArray = realloc(myArray, 20 * sizeof(int));  // Resize to 20 integers
```

## Find Maximum Element from Array

### Python
```python
my_list = [1, 2, 3, 4, 5]
max_value = my_list[0]  # Assume the first element is the max initially
for i in range(1, len(my_list)):
    if my_list[i] > max_value:
        max_value = my_list[i]  # Update max if current element is greater
print("Max:", max_value)
```

### C++
```cpp
int myArray[] = {1, 2, 3, 4, 5};
int max = myArray[0];  // Assume the first element is the max initially
for (int i = 1; i < 5; i++) {
    if (myArray[i] > max) {
        max = myArray[i];  // Update max if current element is greater
    }
}
cout << "Max: " << max << endl;
```

### C
```c
int myArray[] = {1, 2, 3, 4, 5};
int max = myArray[0];  // Assume the first element is the max initially
for (int i = 1; i < 5; i++) {
    if (myArray[i] > max) {
        max = myArray[i];  // Update max if current element is greater
    }
}
printf("Max: %d\n", max);
```

In each example, we start by assuming the first element is the maximum, and then we check each subsequent element to see if it is greater than the current maximum. If it is, we update the maximum. This approach ensures that we only iterate through the array once, providing an efficient way to find the maximum value.

## Importance of Constraints

Understanding constraints is crucial for choosing the right algorithm:

### Constraint Analysis:
- **N ≤ 10⁵**: O(N), O(N log N) work. O(N²) causes TLE
- **N ≤ 10⁶**: O(N), O(N log N) work. O(N²) causes TLE
- **Maximum iterations**: 10⁷ to 10⁸ per second

## Problem-Solving Approach

1. **Read** question and constraints carefully
2. **Formulate** logic/idea
3. **Verify** correctness
4. **Develop** pseudocode
5. **Calculate** time complexity
6. **Check** if feasible (≤ 10⁸ operations)
7. **Re-evaluate** if TLE, otherwise code

## Space Complexity

**Definition**: Maximum memory used at any point during algorithm execution.

### Examples:
```c
// SC: O(1) - Constant space
void fun(int N) {
    int x = N;        // 4 bytes
    int y = 2*x;      // 4 bytes
    long z = x+y;     // 8 bytes
}

// SC: O(N) - Linear space
void fun2(int N) {
    int arr[N];       // 4*N bytes
    int x;            // 4 bytes
}

// SC: O(N²) - Quadratic space
void fun3(int N) {
    long arr[N][N];   // 8*N*N bytes
}
```

## Array Operations

### 1. Print All Elements
```c
for(int i = 0; i < N; i++) {
    printf("%d ", arr[i]);
}
// TC: O(N), SC: O(1)
```

### 2. Reverse Array
```c
int i = 0, j = N-1;
while(i < j) {
    // Swap without 3rd variable
    arr[i] = arr[i] + arr[j];
    arr[j] = arr[i] - arr[j];
    arr[i] = arr[i] - arr[j];
    i++; j--;
}
// TC: O(N), SC: O(1)
```

### 3. Rotate Array K Times (Optimized)
**Problem**: Rotate array right by K positions

**Efficient Approach** (3 reversals):
1. Reverse entire array
2. Reverse first K elements
3. Reverse remaining N-K elements

```c
// Example: [5,8,2,1,6,3,9,7] rotate by K=3
// Step 1: Reverse all → [7,9,3,6,1,2,8,5]
// Step 2: Reverse first 3 → [3,9,7,6,1,2,8,5]
// Step 3: Reverse last 5 → [3,9,7,5,8,2,1,6]
```
**TC: O(N), SC: O(1)**

## Dynamic Arrays - Advanced

Dynamic arrays automatically resize when capacity is exceeded:

### How it works:
1. **Initial capacity**: Small fixed size
2. **On overflow**: Create new array of double size
3. **Copy elements**: Transfer old data to new array
4. **Amortized TC**: O(1) per insertion on average

### Characteristics:
- **Worst case insertion**: O(N) during resize
- **Average case**: O(1) per element
- **Space overhead**: Some unused capacity for future growth