# 🐄 Roundabout Rounding – USACO Bronze (December 2024)

This directory contains a C++ solution to the **"Roundabout Rounding"** problem from the USACO Bronze division.

## 📜 Problem Summary
> You’re given several test cases, each with an integer \( n \). For each test case, count how many numbers between 1 and \( n \) (inclusive) would end in 5–9 when rounded to the nearest 10 (i.e., they round **up**). These are the “boundary” numbers like 45–49, 450–499, 4 500–4 999, etc.

Cows aren’t mentioned, but we all know they’re silently judging our rounding habits.

## 📥 Input Format
t # number of test cases
n₁
n₂
...
nₜ

- (1 <= t <= 10^5), and each ( n_i ) can be as large as (10^9).

## 📤 Output Format
For each test case, output a single integer — the number of “round-up” integers between 1 and \( n \).

### Example
**Input:**
3
49
100
1000

**Output:**
5
15
95
## 💡 Strategy
1. Recognize the recurring pattern: numbers in \([\,45,49]\), \([\,450,499]\), \([\,4\,500,4\,999]\), … each tier.
2. Maintain a sliding window `[low, high]` representing the current 45–49-based range at each power of 10.
3. In a `while (low <= n)` loop:
   - Add `min(high, n) - low + 1` to the count.
   - Extend the window to the next decimal range by:
     ```cpp
     low  = low * 10 - 5;
     high = high * 10 + 9;
     ```
4. Loop terminates when `low > n`.
5. Repeat per test case.

- Time complexity: **O(log n)** per \( n \) (only ~10 iterations for \( n <= 10^9 \)).

## 🚀 How to Run
```sh
g++ -std=c++17 -o rounding rounding.cpp
./rounding < input.txt > output.txt
```
## 🧠 Time Complexity
Per test case: ~O(log n).

Overall: O(t × log n), which is efficient for large 
𝑡
t.

### 🔖 Tags
bronze math loops simulation rounding digits

## 🛠 Why This Exists
To practice detecting digit patterns and repeating numeric ranges.

To build searchable knowledge of digit-based counting problems.

To document the oddball tasks we solve in the pursuit of algorithmic fluency.

May your digits balance, your loops converge, and your boundary cases never trip your solutions.
