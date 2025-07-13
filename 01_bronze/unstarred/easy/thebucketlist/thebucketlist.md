# 🐄 The Bucket List – USACO Bronze (December 2018)

This directory contains a C++ solution to the **"The Bucket List"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John’s cows have a strict milking schedule. Each cow starts at a specific time, ends at another, and needs a certain number of buckets during that window. Your task is to determine the **maximum number of buckets** that are needed at any one time to satisfy all cows’ bucket cravings.

## 📥 Input Format
- Line 1: Integer `n` — number of cows.
- Next `n` lines: Each contains three integers:
  - `start_i`, `end_i`, and `buckets_i` for the i-th cow.

### Sample Input
3
2 5 4
9 10 1
6 8 2

## 📤 Output Format
- A single integer — the maximum number of buckets needed at any point in time.

### Sample Output
4

## 💡 Strategy
- Use a time-based simulation.
- Track bucket usage per time unit using an array.
- For each cow, increment the bucket count for every time in `[start, end]`.
- At the end, take the max of the array to get the peak bucket demand.

- Alternate approach: simulate manually by looping through `[minStart, maxEnd]` and summing active cows.
- Both solutions run fine due to small time constraints (time ≤ 1000).

- Time Complexity:
  - O(n + T), where T is the range of time (≤ 1000)

## 🚀 How to Run
```sh
g++ -std=c++17 -o blist blist.cpp
./blist < blist.in > blist.out
```
## 🧠 Time Complexity
Break it down cleanly:

Reading cows: O(n)

Simulation pass: O(n * time range) or O(1000)

Final pass for max: O(1000)

Total: O(n + T)

### 🔖 Tags
bronze simulation timeline array greedy buckets bovine-scheduling

## 🛠 Why This Exists
To practice time-based simulation logic

To build searchable knowledge of greedy scheduling strategies

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your buckets always be clean, your cows punctual, and your simulations free of off-by-one regrets.
