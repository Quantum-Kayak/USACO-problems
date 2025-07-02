# 🐄 Measuring Traffic – USACO Bronze (December 2015)

This directory contains a C++ solution to the **"Measuring Traffic"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Along a highway, traffic monitors record segments of vehicles passing with three types of instructions:
> - `"on a b"`: between `a` and `b` cars entered.
> - `"off a b"`: `a` to `b` cars exited.
> - `"none a b"`: always between `a` and `b` cars present.
>
> Given these segments in chronological order, determine:
> 1. The range of possible traffic before the first monitoring segment.
> 2. The range of possible traffic after the final segment.

## 📥 Input Format
- Line 1: `n` — number of recorded segments.
- Next `n` lines: each contains:
  - A string `type` (`on`, `off`, `none`)
  - Two integers `low` and `high`.

### Sample Input
3
none 10 20
on 5 10
none 15 25
## 📤 Output Format
- Line 1: two integers — possible range of cars *before* the first segment.
- Line 2: two integers — possible range of cars *after* the last segment.

### Sample Output
5 15
20 30

## 💡 Strategy
1. **Reverse-simulate** from the last to the first segment to find the initial range `(blow, bhigh)`:
   - If `"off a b"` → add `a` to `b`
   - If `"on a b"` → subtract `b` (min) and `a` (max), clamping to zero
   - If `"none a b"` → intersect with `[a, b]`
2. **Forward-simulate** from the first to the last to find the final range `(low, high)`, mirroring the inverse operations.
3. Print the two ranges.

All operations are O(n).

## 🚀 How to Run
```sh
g++ -std=c++17 -o traffic traffic.cpp
./traffic < traffic.in > traffic.out
```
## 🧠 Time Complexity
Break it down cleanly:

One reverse pass: O(n)

One forward pass: O(n)

Total: O(n)

### 🔖 Tags
bronze simulation interval arithmetic highway flow ranges

## 🛠 Why This Exists
To practice simulation of inverse operations

To build searchable knowledge of range-tracking patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your ranges intersect cleanly, your off-steps balance your on-steps, and your traffic never gridlock your logic.
