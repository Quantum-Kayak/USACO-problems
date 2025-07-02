# 🐄 Leaders – USACO Bronze (January 2018)

This directory contains a C++ solution to the **"Leaders"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John’s cows have taken politics very seriously. Each cow is either a G-cow or an H-cow. Every cow has a “loyalty range” — an index range up to which they’ll follow someone else. A cow becomes a *leader* if every cow of its type in front of it would follow it, and it chooses to lead. Your task is to figure out how many valid pairs of leaders (one G-cow and one H-cow) could simultaneously choose to lead their factions.

## 📥 Input Format
- The first line: integer `N` — the number of cows.
- The second line: a string `s` of length `N`, where each character is either `'G'` or `'H'`.
- The third line: `N` integers, where the `i-th` integer `arr[i]` is the last index (0-based) cow `i` is willing to follow.

### Sample Input
6
GHGHGH
3 5 3 5 3 5

## 📤 Output Format
- A single integer: the number of valid (G-leader, H-leader) pairs.

### Sample Output
2

## 💡 Strategy
- First, identify the earliest and latest cows of each type: `eG`, `lG`, `eH`, `lH`.
- Then, verify if the earliest of each type can lead all others of their type:
  - For example, if `arr[eG] >= lG`, then G-leader is viable.
- If viable, count how many cows of the *opposite type* could be valid followers — cows earlier than the earliest leader with ranges that cover the opposite leader.
- Finally, if both `eG` and `eH` could be leaders and follow each other, count that pair.

- Time Complexity:  
  - O(N), single pass with a few condition checks.

## 🚀 How to Run
```sh
g++ -std=c++17 -o leaders leaders.cpp
./leaders < input.txt > output.txt
```
## 🧠 Time Complexity
Break it down cleanly:

One pass to find earliest/latest cows: O(N)

Looping through potential followers: O(N)

Total: O(N)

### 🔖 Tags
bronze simulation greedy array factions betrayal

bronze simulation greedy array factions betrayal
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your cows lead wisely, your loyalty be mutual, and your range checks never go out of bounds.
