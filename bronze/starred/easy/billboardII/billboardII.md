# 🐄 Billboard II – USACO Bronze (January 2018)

This directory contains a C++ solution to the **"Billboard II"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John has a billboard made of grass (obviously) and he also has a large rectangular mower. After placing a second billboard over part of the first one, he wants to mow *only* the visible part of the first billboard. Your job? Figure out the area of the first billboard that is still visible after the second billboard partially or fully covers it.

## 📥 Input Format
- Two lines, each with four integers:
  - First line: `(x1, y1, x2, y2)` of the lawnmower billboard.
  - Second line: `(x1, y1, x2, y2)` of the second billboard that might cover it.

### Sample Input
1 2 7 8
4 5 9 12

## 📤 Output Format
- A single integer representing the visible area of the first billboard after the second one overlaps it.

### Sample Output
36

## 💡 Strategy
- Define two rectangles: `lawnmower` and `remaingrass`.
- Calculate the area of `lawnmower` normally.
- Use axis-aligned rectangle intersection math to compute the area of overlap.
- Subtract the overlap area unless the overlap completely cuts across the height or width — in which case, nothing is hidden (as per the problem’s quirk).
- This requires some condition checks to avoid full-width/height covering from masking anything.

- Time Complexity:
  - O(1), just geometry and conditional logic.

## 🚀 How to Run
```sh
g++ -std=c++17 -o billboard billboard.cpp
./billboard < billboard.in > billboard.out
```
## 🧠 Time Complexity
Break it down cleanly:

Area calculation: O(1)

Overlap logic: O(1)

Total: O(1)

### 🔖 Tags
bronze geometry rectangles conditionals overthinking regret

bronze geometry rectangles conditionals overthinking regret
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your rectangles always intersect politely, and your area calculations never involve fencepost errors.
