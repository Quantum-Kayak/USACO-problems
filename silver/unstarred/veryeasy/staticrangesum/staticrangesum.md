# 🧮 Static Range Sum – Prefix Sum Query

This directory contains a **C++ solution** to the “Static Range Sum” problem — a simple but foundational problem in array queries.

---

## 📜 Problem Summary

You’re given a non-negative integer sequence `A` of length `N`. You need to answer `Q` range sum queries of the form:  
**“What’s the sum of the elements from index `l` to `r-1` (inclusive of `l`, exclusive of `r`)?”**

This is the classic static range sum query:  
\[
\sum_{k=l}^{r-1} a_k
\]

---

## 📥 Input Format

- **Line 1:** Two integers, `N` and `Q` — number of elements and number of queries.  
- **Line 2:** The sequence `A`, consisting of `N` non-negative integers.  
- **Next `Q` lines:** Each query as two integers `l` and `r` (0-based indices).

**Example input:**
5 5
1 10 100 1000 10000
2 3
0 3
2 5
3 4
0 5

---

## 📤 Output Format

For each query, output the sum of the segment `[l, r)` on its own line.

**Example output:**
100
111
11100
1000
11111

---

## 💡 Strategy

We precompute **prefix sums** to answer each query in constant time:

- **Prefix sum array:**  
  `prefix[i] = a[0] + a[1] + ... + a[i-1]`  
  (`prefix[0] = 0` for convenience)
- For any range `[l, r)`, the sum is:  
  `prefix[r] - prefix[l]`

This approach ensures that, after an `O(N)` preprocessing step, each query can be answered in `O(1)`.

---

## 🚀 How to Run

```bash
g++ -std=c++17 -o static_range_sum static_range_sum.cpp
./static_range_sum < input.txt > output.txt
Make sure your input file follows the format shown above.
```
## 🧠 Time Complexity
Preprocessing: O(N)

Each Query: O(1)

Total: O(N + Q), making it efficient even for large inputs.

## 🔖 Tags
prefix_sum range_queries arrays static_queries

## 🛠 Why This Exists
To practice using prefix sums for static queries.

To handle up to 5×10^5 queries efficiently and learn the importance of preprocessing.

To document this so you can stop forgetting it every other week!

Happy coding, and may your sums always be accurate and your queries snappy.
