# 🐄 Mixing Milk – USACO Bronze (December 2018)

This directory contains a C++ solution to the **"Mixing Milk"** problem from the USACO Bronze division.

## 📜 Problem Summary
> Farmer John has three buckets full of milk, and because he apparently hates consistency, he pours milk from one to the next repeatedly. Each bucket has a capacity, and the goal is to simulate **100 such pours** in a specific sequence: A → B, B → C, C → A... and so on, forever—or until 100 pours break the cycle and end the madness. You're asked to compute how much milk ends up in each bucket.

## 📥 Input Format
- Three lines, one for each bucket.
- Each line contains two integers: capacity and initial amount of milk.

### Sample Input
10 3
11 4
12 5

## 📤 Output Format
- Three lines:
  - Final amount of milk in bucket A
  - Final amount in bucket B
  - Final amount in bucket C

### Sample Output
0
10
12

## 💡 Strategy
- Use structs to represent each bucket’s capacity and current milk level.
- Simulate 100 iterations:
  - On turn i:
    - Pour from bucket `i % 3` to bucket `(i + 1) % 3`
    - Pour as much as will fit, up to what’s available
- Avoid overflows by using `min(from.milk, to.cap - to.milk)`

- Time Complexity:
  - O(100), constant-time simulation

## 🚀 How to Run
```sh
g++ -std=c++17 -o mixmilk mixmilk.cpp
./mixmilk < mixmilk.in > mixmilk.out
```
## 🧠 Time Complexity
Break it down cleanly:

100 operations, each O(1)

Total: O(1)

### 🔖 Tags
bronze simulation milk pouring buckets cow zen

bronze simulation milk pouring buckets cow zen
## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

May your buckets stay upright, your pours be exact, and your cows forever hydrated.
