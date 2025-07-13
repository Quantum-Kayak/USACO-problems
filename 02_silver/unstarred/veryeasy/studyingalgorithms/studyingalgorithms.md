# 🧠 Studying Algorithms – Greedy Learning Problem

This directory contains a **C++ solution** to the “Studying Algorithms” problem from **Codeforces Round (???)**. Yes, Steph wants to learn algorithms, and we want to humor her.

---

## 📜 Problem Summary

Steph has a total of `X` minutes during winter break to study algorithms. She has `N` algorithms to choose from, each requiring a certain number of minutes to learn.  

Her goal? **Maximize the number of algorithms she can fully study** given her time constraints.

---

## 📥 Input Format

- **Line 1:** Two space-separated integers `N` and `X`  
- **Line 2:** `N` space-separated integers `a1, a2, ..., aN`, where `ai` is the number of minutes needed to learn algorithm `i`.

**Example input:**
6 15
4 3 8 4 7 3
---

## 📤 Output Format

A single integer: the **maximum number of algorithms** Steph can learn without exceeding her time limit `X`.

**Example output:**
4

---

## 💡 Strategy

This is a classic **greedy approach**:

- Sort the array of required minutes in increasing order.
- Keep learning algorithms in order from shortest to longest until she runs out of time.

---

## 🚀 How to Run

```bash
g++ -std=c++17 -o studying_algorithms studying_algorithms.cpp
./studying_algorithms < input.txt > output.txt
```
## 🧠 Time Complexity
Sorting: O(N log N)

Greedy loop: O(N)

Total: O(N log N), making it a brisk winter study session.

## 🔖 Tags
greedy sorting arrays time_management study_sadness

## 🛠 Why This Exists
To practice greedy algorithm strategies and sorting.

Because Steph deserves to know how many algorithms she can actually learn before she’s out of time (or interest).

So you can document your path to algorithm mastery one trivial problem at a time.

Happy coding, and may your studying be more focused than Steph’s attention span.
