# 🐄 Convention – USACO Silver (December 2018)

This directory contains a C++ solution to the **"Convention"** problem from the USACO Silver division.

## 📜 Problem Summary
> Farmer John is organizing CowCon, the premier bovine conference. There are `n` cows arriving at specific times, `m` buses, and each bus can hold at most `c` cows. Cows can’t be forced to wait too long — Farmer John wants to minimize the **maximum waiting time** any cow experiences on their assigned bus. Your job: determine the **smallest possible maximum waiting time** that allows all cows to be transported.

## 📥 Input Format
- Line 1: Three integers `n` `m` `c` — number of cows, buses, and capacity.
- Line 2: `n` integers representing the arrival times of each cow.

### Sample Input
6 2 3
7 2 4 8 1 4

## 📤 Output Format
- A single integer: the minimum possible maximum waiting time such that all cows can be placed on buses within the constraints.

### Sample Output
3

## 💡 Strategy
- Sort the cows by arrival time.
- Use **binary search** on the answer: the max waiting time.
- For each guess, simulate loading cows onto buses:
  - Start from the earliest cow.
  - If the next cow waits too long or the bus is full, use a new bus.
  - Check if the number of buses used is ≤ `m`.

- This is a classic **"binary search the answer"** problem.
- Edge Cases:
  - All cows arrive at the same time → waiting time is 0.
  - Only one bus → max diff from first to last.

- Time Complexity:
  - Sorting: O(n log n)
  - Binary search: O(log(maxT)) iterations × O(n) per check → O(n log T)

## 🚀 How to Run
```sh
g++ -std=c++17 -o convention convention.cpp
./convention < convention.in > convention.out
```
## 🧠 Time Complexity
Break it down cleanly:

Sorting arrivals: O(n log n)

Binary search loop: O(log(max_wait))

Within each step, simulation: O(n)

Total: O(n log n + n log T)

### 🔖 Tags
silver binary-search greedy buses simulation optimization waiting-room

## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your buses be plentiful, your cows patient, and your binary search converge without off-by-one errors.
