# 🐄 Sum Game – USACO Bronze (Training / Ad Hoc)

This directory contains a C++ solution to a **subset sum puzzle** where you are given 7 integers (sums of subsets), and need to recover the original 3 numbers.

## 📜 Problem Summary
> You are given **seven numbers**, which are all the distinct sums of the non-empty subsets of three unknown positive integers `A`, `B`, and `C`.
>
> Your task: recover the original values `A`, `B`, and `C`.

### 🧩 Known facts:
- There are `2^3 - 1 = 7` non-empty subsets of 3 elements.
- The **largest sum** will be `A + B + C`.
- The other sums will be from all other combinations (e.g., `A + B`, `A`, `B`, etc.)

## 📥 Input Format
- A single line with 7 space-separated integers

## 📤 Output Format
- Three integers: the original values `A B C`, in any order

## 💡 Strategy

1. **Sort** the input list of 7 numbers
2. The **largest number** is always `A + B + C`
3. Try all combinations of 3 distinct numbers among the first 6 (because 7th is the total) and check:
   - If their sum equals the largest number
   - If so, they must be `A`, `B`, and `C`

4. Output that triple

### 🧠 Key Observations:
- There are only 20 combinations (`C(6, 3)`), so brute-force is completely fine
- Sorting ensures the largest value is last, which simplifies identification

## 🚀 How to Run
```sh
g++ -std=c++17 -o sumgame sumgame.cpp
./sumgame < test.in > test.out
```
## 🧠 Time Complexity
Sort: O(7 log 7)

Triple-checking loop: O(20)

Total: O(1) in practice, because 7 is a constant and this isn’t your senior thesis

### 🔖 Tags
bronze subset brute-force ad-hoc mystery-puzzle

It’s a logic puzzle dressed as a math problem. A little guessing, a little looping, and boom—you’ve reverse-engineered a cow’s brain in 3 values.
