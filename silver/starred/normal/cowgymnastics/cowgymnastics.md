# gymnastics – USACO Bronze Problem (December 2019)

This repository contains a C++ solution to the "Gymnastics" problem from the USACO Bronze division.

---

## 🐄 Problem Summary

Bessie the cow is in gymnastics training. She and the other cows attend multiple practice sessions where they are each ranked based on performance.

Your job is to find **how many cow pairs** have a *consistent ranking order* — that is, if cow A was ranked higher than cow B in one session, she must also be ranked higher in **all** the other sessions for the pair to count.

---

## 📥 Input

- First line: Two integers `K` and `N` — the number of practice sessions and the number of cows (1 ≤ K ≤ 10, 1 ≤ N ≤ 20).  
- Next `K` lines: Each line contains `N` integers — the ranking of cows for that session (from best to worst).

**Example:**
3 4
1 2 3 4
1 2 4 3
1 3 2 4

yaml
Copy
Edit

---

## 📤 Output

- A single integer — the number of cow pairs (A, B) such that A is ranked higher than B in **every** session.

**Example:**
4

yaml
Copy
Edit

---

## 💡 Approach

The program:

- Reads in the rankings from all K sessions.
- Converts the rankings into a fast-lookup table: `position[session][cow] = rank`.
- Iterates over every possible pair of cows (a, b) where a ≠ b.
- For each pair, checks all sessions to see if cow `a` is always ranked higher than `b`.
- If yes, counts that pair as "consistent."

Uses basic nested loops and 2D arrays — perfect for Bronze-level thinking with a dash of algorithmic rigor.

---

## 📁 Files

- `gymnastics.cpp` – C++ source code implementing the solution.  
- `gymnastics.in` / `gymnastics.out` – Standard USACO-style input/output files.  
- `gymnastics.md` – (You're here. Soak it in.)

---

## 🚀 How to Run

Make sure you have a C++ compiler installed. Then:

```bash
g++ -std=c++17 -o gymnastics gymnastics.cpp  
./gymnastics < gymnastics.in > gymnastics.out
Or submit it to USACO and let the grader bask in your cow-ranking logic.
```
## 🧠 Time Complexity
Parsing sessions: O(K × N)

Comparing all cow pairs across sessions: O(N^2 × K)

Total: O(N^2 × K) — totally manageable for N ≤ 20.

## 🫠 Notes
Uses freopen to handle .in and .out file redirection (USACO-style).

Indexes cows from 1 to N for clarity and alignment with problem constraints.

Brute force, but beautiful. Just like Bessie’s double backflip.

Happy cow comparing! 🐄✨
