# 🐄 Milk Measurement – USACO Bronze (December 2017)

This directory contains a C++ solution to the **"Milk Measurement"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Three cows (Bessie, Elsie, and Mildred) each start with 7 units of milk. Farmer John logs changes in their output over several days. After each log, he updates the leaderboard showing who’s currently producing the most milk. You need to calculate **how many times the leaderboard display changes**.

## 📥 Input Format
- Line 1: Integer `n` — number of entries in the log.
- Next `n` lines: Each contains:
  - Day of log,
  - Cow’s name,
  - Change in milk output (`+x` or `-x`).

### Sample Input
4
7 Mildred +3
4 Elsie -1
9 Mildred -1
1 Bessie +2

bash
Copy
Edit

## 📤 Output Format
- A single integer: number of times the displayed leaderboard changes.

### Sample Output
3

markdown
Copy
Edit

## 💡 Strategy
- Initialize all cows with 7 units of milk.
- Parse and sort all logs by day.
- For each log:
  - Apply the milk output change.
  - Recalculate the **current top producers**.
  - If the leaderboard changed from the previous day, increment the counter.
- Use sorting to make leaderboard comparison order-insensitive.

- Time Complexity:
  - O(n log n) for sorting logs
  - O(n) to process logs and compare leaderboard

## 🚀 How to Run
```sh
g++ -std=c++17 -o measurement measurement.cpp
./measurement < measurement.in > measurement.out
```
## 🧠 Time Complexity
Break it down cleanly:

Sorting log entries: O(n log n)

Processing logs and comparing sets: O(n)

Total: O(n log n)

### 🔖 Tags
bronze simulation leaderboard sorting dairy-drama

## 🛠 Why This Exists
To practice simulation with dynamic state changes

To build searchable knowledge of sorting + mapping problems

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your milk outputs be stable, your cows honest, and your leaderboard drama-free.
