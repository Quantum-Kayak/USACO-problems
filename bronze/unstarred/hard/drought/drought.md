
# 🐄 Drought – USACO Bronze (January 2019)

This directory contains a C++ solution to the **"Drought"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John's cows are starving (again). You’re given the hunger levels of cows lined up in a row, and you can only reduce hunger by feeding three consecutive cows at once—reducing each of their hunger values by 1. Your task: figure out the **minimum number of total feedings** required to make all cows equally hungry, or declare it impossible. The feeding process is brutal and bizarre, like a three-headed trough of sadness.

## 📥 Input Format
- The first line contains an integer `T`, the number of test cases.
- For each test case:
  - The first line contains an integer `N`, the number of cows.
  - The second line contains `N` integers `h[0], h[1], ..., h[N-1]`, the hunger levels.

### Sample Input
2
3
4 2 2
1
5

## 📤 Output Format
- For each test case, print a single integer:
  - The minimum number of feedings needed, or
  - `-1` if it’s impossible.

### Sample Output
4
0

## 💡 Strategy
- Model the hunger transformation as a recurrence:
  - Express hunger differences in terms of prior differences.
  - Track `coef` and `const` terms to represent the effect of initial cow's feeding (`x0`) on others.
- If at any point we require negative feedings, it's invalid.
- For **odd `N`**, solve for `x0` directly.
- For **even `N`**, ensure consistency of final recurrence (`const == 0`) and minimal non-negative `x0`.

- Time Complexity:  
  - O(N) per test case
  - O(T * N) total

## 🚀 How to Run
```sh
g++ -std=c++17 -o drought drought.cpp
./drought < input.txt > output.txt
```
## 🧠 Time Complexity
Break it down cleanly:

Per test case: O(N)

Total: O(T * N)

### 🔖 Tags
bronze medium recurrence parity greed regret

bronze medium recurrence parity greed regret
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your feedings be efficient, your cows nonviolent, and your hunger levels symmetrical.
