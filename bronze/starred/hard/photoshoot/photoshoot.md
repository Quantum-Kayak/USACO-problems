# 🐄 Photo Shoot – USACO Bronze (January 2021)

This directory contains a C++ solution to the **"Reversing Cows"** problem from the USACO Bronze division.

## 📜 Problem Summary
> In this problem, cows are standing in a line, represented by a string of `'G'` and `'H'` characters. You want to see if it’s possible to increase the number of `'G'` cows at **odd** indices (0-based) by reversing some prefix of the line. You’re only allowed to reverse a prefix of even length.

## 📥 Input Format
- **Line 1:** An integer, `N` (1 ≤ N ≤ 100), the number of cows.
- **Line 2:** A string of length `N` with each character either `'G'` or `'H'`.
- **Example Input:**
4
GHGH

## 📤 Output Format
- **Line 1:** `1` if there exists a reversal that increases the number of `'G'` cows at odd indices, `0` otherwise.
- **Example Output:**
1

## 💡 Strategy
- Count the number of `'G'` cows at odd indices in the original string.
- For every **even** prefix length `i` (2, 4, ...), reverse the prefix and check if the `'G'` count at odd indices increases.
- If it ever increases, output `1`. Otherwise, output `0`.
- Edge cases? Well, the problem constraints are so small that there’s no real performance concern.

**Algorithm:**  
- Brute-force reversal check for each even `i`.  
- Use in-place reversals to avoid making new strings every time.

**Time Complexity:**  
- Reading input: O(N)  
- Loop through prefixes: O(N²)  
- Overall: O(N²), which is fine for `N ≤ 100`.

---

## 🚀 How to Run
```sh
g++ -std=c++17 -o problem problem.cpp
./problem < input.txt > output.txt
``` 
## 🧠 Time Complexity
Counting & checking: O(N²)

No fancy tricks. Just a tiny problem.

## 🔖 Tags
bronze easy strings regret

bronze easy strings regret
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

Happy coding. May your segments never overflow, and your cows never run out of 'G's.
