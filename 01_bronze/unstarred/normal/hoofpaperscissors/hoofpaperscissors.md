# 🐄 Hoof-Paper-Scissors – USACO Bronze (December 2017)

This directory contains a C++ solution to the **"Hoof-Paper-Scissors"** problem (`hps`) from USACO Bronze.

## 📜 Problem Summary
> Bessie believes there's some magical mapping between cow gestures and human gestures (hoof, paper, scissors). She records `n` rounds against an opponent who plays known gestures. Each gesture is coded as:
> 1 = Hoof, 2 = Paper, 3 = Scissors.
>
> Bessie can remap **each** of her three gestures to any of the three actual moves (a permutation). Find the maximum number of rounds she can **win**, assuming an optimal mapping.

## 📥 Input Format
- Line 1: Integer `n` — number of rounds.
- Lines 2..n+1: Each contains two integers `a b`, where:
  - `a` = Bessie's **gesture ID** (1..3)
  - `b` = opponent's gesture (1..3)

### Sample Input
5
1 3
2 1
3 2
1 1
2 3
## 📤 Output Format
- Single integer: maximum wins Bessie can secure under an optimal gesture mapping.

### Sample Output
3

## 💡 Strategy
- For each possible **permutation** of mapping Bessie's IDs 1,2,3 → actual moves (1,2,3):
  - Simulate all rounds:
    - Map Bessie's gesture through the permutation.
    - Check if it wins against the opponent using `wins(a, b)`.
  - Count total wins and track the maximum across all permutations.
- There are only **6 mappings** → brute-force all, O(6 × n).

- Time Complexity:
  - O(n × 6)

## 🚀 How to Run
```sh
g++ -std=c++17 -o hps hps.cpp
./hps < hps.in > hps.out
```
## 🧠 Time Complexity
Break it down clearly:

6 permutations × n rounds = O(n)

### 🔖 Tags
bronze brute-force permutation mapping rock-paper-scissors cows

## 🛠 Why This Exists
To practice brute-force over small permutations

To build searchable knowledge of mapping and simulation strategies

To document that yes, even games of chance can be systematically optimized

May your mappings be optimal, your wins maximum, and your cows never throw a hoof you can’t counter.
