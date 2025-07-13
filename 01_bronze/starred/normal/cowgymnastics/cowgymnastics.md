# 🐄 Gymnastics – USACO Bronze (December 2019)

This directory contains a C++ solution to the **"Gymnastics"** problem from the USACO Bronze division.

---

## 📜 Problem Summary
> In this barnyard drama, we have `K` practice sessions where `N` gymnasts are ranked from best to worst. For every pair of gymnasts `(i, j)`, we want to find how many pairs exist such that `i` is consistently ranked above `j` in every session.  
> Because cows apparently do gymnastics and take their rankings very seriously.

---

## 📥 Input Format
- First line: two integers, `K` (number of sessions) and `N` (number of gymnasts).
- Next `K` lines: each contains the rankings of the `N` gymnasts in that session (1-based IDs).

**Sample Input:**  
3 4
3 1 2 4
1 2 3 4
2 3 4 1

---

## 📤 Output Format
- A single integer: the number of pairs `(i, j)` where gymnast `i` consistently outranks gymnast `j` in every session.

**Sample Output:**  
5

---

## 💡 Strategy
- **Key Idea**: For every pair `(i, j)`, check if `i` always appears before `j` in each session’s ranking.
- **Edge Cases**: Pairs where `i` and `j` are the same (skipped), or where rankings change each session.
- **Algorithm**:  
  - Read the rankings into a 2D vector.  
  - For every pair `(i, j)`, verify if `i` always precedes `j`.  
  - Count these pairs.  
- **Time Complexity**:  
  - Preprocessing rankings: O(K * N)  
  - Checking all pairs: O(N^2 * K)  
  - Overall: O(K * N^2) — efficient enough for small N.

---

## 🚀 How to Run
```sh
g++ -std=c++17 -o gymnastics gymnastics.cpp
./gymnastics < gymnastics.in > gymnastics.out
```
## 🧠 Time Complexity
Preprocessing rankings: O(K * N)

Pair comparisons: O(N^2 * K)

Overall: O(K * N^2)

## 🔖 Tags
bronze easy simulation cows gymnastics

## 🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

Happy coding. May your segments never overflow, and your trees remain acyclic.
