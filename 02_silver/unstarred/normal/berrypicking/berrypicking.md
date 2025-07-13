# 🍓 Berry Picking – USACO Silver (December 2019)

This directory contains a C++ solution to the **"Berry Picking"** problem from the USACO Silver division.

## 📜 Problem Summary
> Bessie and Elsie are picking berries. There are `n` trees with different numbers of berries. Bessie chooses `k/2` baskets first, then Elsie chooses the remaining `k/2`. They both want the **most berries possible**, but you only care about **how many berries Bessie can guarantee**, assuming Elsie picks after her and plays optimally. You can slice berries into baskets however you like (because of course that's a thing now).

## 📥 Input Format
- Line 1: Integers `n` and `k` — number of trees and total baskets (even).
- Line 2: `n` integers, the number of berries on each tree.

### Sample Input
4 4
9 7 5 3
## 📤 Output Format
- A single integer: the **maximum number of berries Bessie can collect** assuming optimal play.

### Sample Output
12
## 💡 Strategy
- Try all possible **basket sizes** `s` from 1 to max berry count.
- For each size `s`, simulate splitting the berries from all trees into baskets of size `s`, and smaller leftovers.
- Sort all the resulting basket values in descending order.
- Give Elsie the first `k/2` (the best ones), then give Bessie the next `k/2`.
- Track the maximum Bessie can guarantee over all basket sizes.

- Time Complexity:
  - For each possible size `s` (≤ max berry count): O(n + k log k)

## 🚀 How to Run
```sh
g++ -std=c++17 -o berries berries.cpp
./berries < berries.in > berries.out
```
## 🧠 Time Complexity
Break it down cleanly:

Outer loop over s: O(max berry count)

For each s, generate & sort all baskets: O(n log n)

Total: O(n * maxB * log n)

### 🔖 Tags
silver greedy sorting simulation slicing berries fruity-violence

## 🛠 Why This Exists
To practice greedy approaches combined with sorting

To build searchable knowledge of adversarial two-player simulations

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your baskets overflow, your slices be sharp, and your greedy strategy always beat your cow rivals.
