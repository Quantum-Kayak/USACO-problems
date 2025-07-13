# speedingticket – USACO Bronze Problem (December 2017)

This repository contains a C++ solution to the "Speeding Ticket" problem from the USACO Bronze division.

---

### 🐄 Problem Summary

Bessie the cow is driving down a long road divided into 100 miles. The road has varying speed limits over different segments, and Bessie, being a statistical anomaly, also drives at varying speeds across her own set of segments.

Your task is to determine how badly Bessie breaks the speed limit — specifically, **the maximum amount by which she exceeds the speed limit at any single mile**.

---

### 📥 Input

- First line: An integer `n` — the number of road segments (1 ≤ n ≤ 100)
- The next `n` lines: Each contains two integers — the segment length and speed limit for that road segment
- Then, an integer `m` — the number of segments Bessie drives
- The next `m` lines: Each contains two integers — the segment length and Bessie's speed for that segment

**Example:**
3
40 75
50 35
10 40
3
40 76
50 35
10 40

---

### 📤 Output

A single integer — the maximum amount by which Bessie exceeds the speed limit over any individual mile.

**Example:**
1

---

### 💡 Approach

The program:

- Reads in both the road's speed limits and Bessie's driving speeds as a series of segments.
- Expands each segment into a per-mile representation using arrays of size 100.
- Compares Bessie's speed to the road limit at each mile.
- Tracks the **maximum overspeeding** across all 100 miles.

It uses simple arrays and looping logic, no fancy data structures required — just clean brute-force, Bronze-style.

---

### 📁 Files

- `speedingticket.cpp` – C++ source code implementing the solution.
- `speedingticket.in / speedingticket.out` – Standard USACO-style input/output files.
- `speedingticket.md` – (You're here. Welcome to the README.)

---

### 🚀 How to Run

Make sure you have a C++ compiler installed. Then:

```bash
g++ -std=c++17 -o speedingticket speedingticket.cpp
./speedingticket < speedingticket.in > speedingticket.out
Or just submit it to the USACO judge and pretend the compiler whispered you the answer.
```
## 🧠 Time Complexity
Reading & expanding segments: O(n + m)

Max overspeed comparison: O(100)

Total: O(n + m) — smooth and efficient for Bronze problems.

## 🫠 Notes
This solution uses freopen for file redirection (.in / .out) as required by USACO submissions.

Arrays are sized exactly to 100 because the road is guaranteed to be that length.

Speed is processed per mile for accurate comparison.

Happy cow ticketing!
