# 🍎 Apple Division – CSES Problem Set (Introductory Problems)

This directory contains a C++ solution to the **"Apple Division"** problem from the CSES Problem Set (Introductory section).

## 📜 Problem Summary
> You’re given a set of apples, each with a positive weight. Your goal is to split them into two groups such that the **absolute difference of the total weights** of the two groups is minimized. It’s like a fair food fight, but with more combinatorics and less stickiness.

## 📥 Input Format
- Line 1: Integer `n` — the number of apples (1 ≤ n ≤ 20)
- Line 2: `n` integers — the weights of the apples (positive integers ≤ 10^9)

### Sample Input
5
3 2 7 4 1

## 📤 Output Format
- A single integer: the minimum possible absolute difference between the total weights of the two groups.

### Sample Output
1

## 💡 Strategy
- Brute-force every possible subset of the apples using a **bitmask**.
- For each mask (i.e., group A), compute the total weight of group A and group B.
- Track the minimum difference between the two group sums.
- Constraints are small (n ≤ 20), so 2^n = ~1 million possibilities is manageable.

- Time Complexity:
  - O(n * 2^n)

## 🚀 How to Run
```sh
g++ -std=c++17 -o apple apple.cpp
./apple < input.txt > output.txt
```
## 🧠 Time Complexity
Break it down cleanly:

Looping over all subsets: O(2^n)

Calculating each subset sum: O(n)

Total: O(n * 2^n)

### 🔖 Tags
cses bitmask subset-sum brute-force balanced partition

## 🛠 Why This Exists
To practice bitmask enumeration and partitioning problems

To build searchable knowledge of subset-sum patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your partitions be balanced, your masks valid, and your apples not contain off-by-one errors.
