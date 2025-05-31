# 🐄 Milk Visits – USACO Silver Division (December 2019)

This directory contains **C++ solutions** to the “Milk Visits” problem from the **USACO 2019 December Silver** contest.

---

## 📜 Problem Summary

Ah, cows. Again.  
In this problem, you’re managing a bunch of cows living in a tree (not *on* a tree, relax). Each cow has a breed (either `1` or `2`, because apparently cows are binary, deal with it). You’re given a series of queries asking:  
**“Is there at least one cow of breed `c` along the unique path between cows `A` and `B`?”**  

A classic binary search for a binary world.

---

## 📥 Input Format

- **Line 1:** Two integers, `n` (number of cows) and `m` (number of queries).  
- **Line 2:** A string of `n` characters (`1` or `2`) representing each cow’s breed (indexed 1-based).  
- **Next `n-1` lines:** The edges of the tree (pairs of integers, undirected).  
- **Next `m` lines:** Three integers `A B c`, each a query about cows on the path from `A` to `B`.

**Example input:**
4 2
1212
1 2
1 3
3 4
1 4 1
2 3 2

---

## 📤 Output Format

For each query, output `1` if there’s at least one cow of breed `c` on the path from `A` to `B`. Otherwise, output `0`.  
All answers are printed as one continuous line of binary digits, followed by a newline.

**Example output:**
10

---

## 💡 Strategy

Both of the provided solutions use **brute-force traversal** for each query:

- **BFS-based approach:**  
  Runs a BFS from cow `A`, looking for cow `c` while walking toward `B`.  

- **DFS-based approach:**  
  Uses recursion to wander from `A` to `B` and toggles a global variable when it finds breed `c`.

This approach has a time complexity of `O(NM)`, which is perfectly fine for small `n` and `m` but will make your computer as lethargic as a cow in summer for large inputs.

---

## 🚀 How to Run

For either approach:
```bash
g++ -std=c++17 -o milkvisits milkvisits.cpp
./milkvisits < input.txt > output.txt
```
## 🧠 Time Complexity
Query: O(N) because you search the path each time.

Overall: O(NM) because you repeat this for all m queries.

## 🔖 Tags
usaco silver trees dfs bfs 2019 inefficiency

## 🛠 Why This Exists
To practice USACO-style competitive programming (even if it’s a bit masochistic).

To document my questionable approaches so I don’t have to reinvent the wheel next time.

So future me (or you) can look back and think: “Wow, I was young and foolish… but at least I tried.”

Happy coding! May your cows be cooperative and your time limits generous.
