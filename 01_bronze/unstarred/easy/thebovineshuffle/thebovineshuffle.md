# 🐄 The Bovine Shuffle – USACO Bronze (January 2017)

This directory contains a C++ solution to the **"The Bovine Shuffle"** problem from the USACO Bronze division.

## 📜 Problem Summary
> N cows stand in a line, each with a unique ID. Each cow has a preferred position to move to (like a personal square on the dance floor). This shuffle happens **3 times**. The task is to determine the final order of cow IDs after all three rounds of moves.

## 📥 Input Format
- Line 1: Integer `n` – number of cows.
- Line 2: `n` integers – the shuffle pattern (1-indexed positions to move each cow to).
- Line 3: `n` integers – initial cow IDs at each position.

### Sample Input
3
1 2 1
3 2 1

## 📤 Output Format
- `n` lines, each with one integer representing the ID of the cow in that position after 3 shuffles.

### Sample Output
1
2
3

## 💡 Strategy
- Use a `vector<cow>` to track cows and their IDs.
- Simulate the shuffle 3 times using the given dance pattern.
- After each shuffle, update the positions accordingly.

- Time Complexity:
  - O(n × 3) = O(n)

## 🚀 How to Run
```sh
g++ -std=c++17 -o shuffle shuffle.cpp
./shuffle < shuffle.in > shuffle.out
```
## 🧠 Time Complexity
Break it down cleanly:

Each shuffle: O(n)

3 shuffles: O(3n)

Total: O(n)

### 🔖 Tags
bronze simulation permutation cows-with-choreography

## 🛠 Why This Exists
To practice direct simulation of sequences

To get comfortable with 1-indexed vs 0-indexed brain traps

To document my debugging pain for future archaeologists of cow logic

May your shuffles stay finite, your loops never infinite, and your cows never dance off the edge of the array.
