# distinctnumbers – CSES Problem Set: Distinct Numbers

This repository contains a C++ solution to the "Distinct Numbers" problem from the [CSES Problem Set](https://cses.fi/problemset/task/1621).  
Your task? Count how many *different* numbers there are in a list. That’s it. You’re basically just being asked to identify variety in a numerical smoothie.

---

### 🐄 Problem Summary

You are given a list of `n` integers. Some of them are repeats (copycats), and some are unique (trendsetters). You must determine how many **distinct** integers are in the list — meaning, how many different numbers appear, regardless of how many times.

---

### 📥 Input

- First line: An integer `n` — the number of elements in the list (1 ≤ n ≤ 2⋅10⁵).
- Second line: `n` space-separated integers (1 ≤ xᵢ ≤ 10⁹).

**Example:**
5
2 3 2 2 3

yaml
Copy
Edit

---

### 📤 Output

- A single integer — the number of **distinct** values.

**Example Output:**
2

yaml
Copy
Edit

---

### 💡 Approach

The program:

1. Reads in `n` and the list of integers.
2. Uses a `std::unordered_set` or `std::set` to automatically eliminate duplicates.
3. Outputs the size of the set, which is literally the count of distinct elements.

So yes, the C++ standard library is doing all the work for you.  
You’re basically just wrapping a present and taking credit for what the factory already did.

---

### 📁 Files

- `distinctnumbers.cpp` – The C++ source file with the elegant 5-line solution.
- `distinctnumbers.md` – This charming README that’s doing *way more work* than the actual code.

---

### 🚀 How to Run

Make sure you have a C++ compiler like g++. Then:

```bash
g++ -std=c++17 -o distinctnumbers distinctnumbers.cpp
./distinctnumbers
Type the input, hit enter, and bask in the glory of basic set operations.
```
### 🧠 Time Complexity
Insertions into a set: O(log n) per item (if using set)
or O(1) average (if using unordered_set)

Total Time: O(n)

Blazing fast. Practically microwaved.

