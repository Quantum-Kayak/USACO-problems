# 🐄 Tic Tac Toe – USACO Bronze (January 2019)

This directory contains a C++ solution to the **"Tic Tac Toe"** problem (a.k.a. `tttt`) from the USACO Bronze division.

## 📜 Problem Summary
> The cows play a bizarre version of Tic Tac Toe on a 3×3 board, where each square contains a letter representing which cow marked it. Your job is to count:
- How many cows could have won **individually** (all three cells in a line are the same letter).
- How many **two-cow teams** could have "teamed up" to win a line (a line with exactly two distinct letters).

## 📥 Input Format
- 3 lines, each with 3 uppercase letters (A–Z) with no spaces.

### Sample Input
AAB
ACB
CCC

markdown
Copy
Edit

## 📤 Output Format
- Two lines:
  - First line: number of cows who won individually
  - Second line: number of winning two-cow teams

### Sample Output
1
2

sql
Copy
Edit

## 💡 Strategy
- Parse the board into a 2D array of integers (or characters).
- Check all 8 win lines (3 rows, 3 columns, 2 diagonals).
- For **individual wins**: line must be all one letter.
- For **team wins**: line must have exactly 2 different letters.

- Use a set to store unique solo winners and a set of pairs to store unique 2-cow teams (in sorted order to avoid duplicates).

- Time Complexity:
  - Constant time (fixed 3x3 board)

## 🚀 How to Run
```sh
g++ -std=c++17 -o tttt tttt.cpp
./tttt < tttt.in > tttt.out
```
## 🧠 Time Complexity
Break it down cleanly:

Checking 8 lines: O(1)

Set operations: O(1) due to fixed number of possibilities

Total: O(1)

### 🔖 Tags
bronze simulation tic-tac-toe set logic cows-in-geometry

## 🛠 Why This Exists
To practice parsing and pattern recognition on small inputs

To build searchable knowledge of simulation strategies

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your lines be unambiguous, your cows fair, and your board games never end in philosophical crisis.
