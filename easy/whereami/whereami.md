# whereami – USACO Bronze Problem (January 2019)

This repository contains a C++ solution to the **"Where Am I?"** problem from the USACO Bronze division.

## 🐄 Problem Summary

Farmer John wants to send secret instructions to Bessie the cow using a string of letters. To ensure that Bessie can determine where in the message she is at any given time, Farmer John needs to pick the shortest length `k` such that **all substrings of length `k` in the message are unique**.

You are given a string of `n` uppercase letters (`1 ≤ n ≤ 100`), and your task is to find the minimum such `k`.

## 📥 Input

- A single integer `n`, the length of the string.
- A string of `n` uppercase letters.

Example:
4
ABCA

r
Copy
Edit

## 📤 Output

- A single integer: the minimum `k` for which all substrings of length `k` are unique.

Example:
3

markdown
Copy
Edit

## 💡 Approach

The program:
1. Iterates over all possible substring lengths `k` from 1 to `n`.
2. For each `k`, extracts all substrings of length `k` and checks if any repeats occur.
3. The first `k` that yields all unique substrings is printed as the answer.

It uses an `unordered_set` for efficient duplicate detection.

## 📁 Files

- `whereami.cpp` – C++ source code implementing the solution.
- `whereami.in` / `whereami.out` – Standard USACO-style input/output files.
- `whereami.md` – (You’re here. Welcome to markdown heaven.)

## 🚀 How to Run

Make sure you have a C++ compiler installed. Then:

```bash
g++ -std=c++17 -o whereami whereami.cpp
./whereami < whereami.in > whereami.out
Or just let USACO’s judge do it for you and pretend it was easy.
```
🧠 Time Complexity
Outer loop over k: O(n)

Inner loop to extract substrings: O(n)

Each substring check uses hashing: ~O(1) average

Total: O(n²) — perfectly acceptable for small inputs like these.

🫠 Notes
This code uses freopen to handle file I/O, as required by USACO problems.

If you’re new to C++, the unordered_set helps us check for duplicates quickly.
