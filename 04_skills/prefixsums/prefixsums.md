### Prefix Sums in C++

A **prefix sum array** is an array `P` where each `P[i]` is the sum of elements from `A[0]` to `A[i]`.

---

#### Example:

Original array:
```cpp
vector<int> A = {3, 2, -1, 6, 5};
```
Compute prefix sum array:
```cpp
vector<int> P(A.size());
P[0] = A[0];
for (int i = 1; i < A.size(); ++i) {
    P[i] = P[i - 1] + A[i];
}
```
How to Use:
To get the sum of a subarray A[i..j]:
```cpp
If i == 0:

sum = P[j];
```
Otherwise:
```cpp
sum = P[j] - P[i - 1];
```
Full Example:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A = {3, 2, -1, 6, 5};
    vector<int> P(A.size());

    // Compute prefix sums
    P[0] = A[0];
    for (int i = 1; i < A.size(); ++i) {
        P[i] = P[i - 1] + A[i];
    }

    // Print prefix sums
    cout << "Prefix sum array: ";
    for (int p : P) {
        cout << p << " ";
    }
    cout << endl;

    // Example: get sum of subarray from index 2 to 4
    int i = 2, j = 4;
    int subarray_sum = (i == 0) ? P[j] : P[j] - P[i - 1];

    cout << "Sum of A[" << i << ".." << j << "] = " << subarray_sum << endl;

    return 0;
}
```
### Output:

Prefix sum array: 3 5 4 10 15
Sum of A[2..4] = 10
## Takeaway
- Prefix sums: precompute once, get range sums instantly.

- Very handy for range sum queries in O(1) time.

- Now go forth and misuse them in ways that make me question your competency.
