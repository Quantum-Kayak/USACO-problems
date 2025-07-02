# 🐄 Back and Forth – USACO Bronze (January 2019)

This directory contains a C++ solution to the **"Back and Forth"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John has two barns, each with 10 buckets of varying capacities. Over four days, the cows mischievously move one bucket per day: barn 1 → barn 2 (Tuesday), barn 2 → barn 1 (Wednesday), and repeat until Friday. You start with 1000 units of milk in barn 1. How many **distinct final amounts** of milk could be in barn 1 after all the swapping chaos?

## 📥 Input Format
- First 10 lines: the bucket sizes in barn 1.
- Next 10 lines: the bucket sizes in barn 2.

### Sample Input
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34
34

## 📤 Output Format
- A single integer: number of distinct possible amounts of milk in barn 1 after four swaps.

### Sample Output
1

## 💡 Strategy
- Use a recursive DFS to simulate **all possible 4-day swap sequences**:
  - Alternate which barn gives the bucket.
  - Track the amount of milk in barn 1 after each move.
  - At day 4, store the milk amount in a set to track distinct outcomes.
- State is small:
  - Only 10 buckets in each barn
  - Only 4 moves total → manageable brute force

- Time Complexity:
  - Worst-case: O(10^4) due to branching factor (~10) and recursion depth 4

## 🚀 How to Run
```sh
g++ -std=c++17 -o backforth backforth.cpp
./backforth < backforth.in > backforth.out
```
## 🧠 Time Complexity
Break it down cleanly:

Recursive DFS, depth = 4

Each level: O(10) choices

Total states explored: O(10^4)

Output: O(1) (size of set)

### 🔖 Tags
bronze recursion brute-force dfs simulation milk-thieves

## 🛠 Why This Exists
To practice recursive DFS on a small state space

To build searchable knowledge of simulation & backtracking

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your swaps be optimal, your sets distinct, and your barns equally full of regret.
