# 🎖️ Badge – Graph Traversal (Simulation)

This directory contains a **C++ solution** to the “Badge” problem from **Codeforces Round (???)**.

---

## 📜 Problem Summary

In the summer informatics school, the teacher puts a hole in a student’s badge for bad behavior, and each student reports another student as the “true culprit.” This creates a chain reaction:  
- The teacher keeps moving to the next reported student.  
- This process eventually loops back to a student who already has a hole in their badge.  
- That unlucky student ends up with **two** holes in their badge.

Your task: for each student `a` from `1` to `n`, find out which student ends up with two holes if the teacher starts the process with `a`.

---

## 📥 Input Format

- **Line 1:** Integer `n` (1 ≤ n ≤ 1000) – number of students.  
- **Line 2:** `n` integers `p1, p2, ..., pn` – where `pi` is the student that student `i` blames.

**Example input:**
3
2 3 2

---

## 📤 Output Format

Print `n` integers: the final student who gets two holes in their badge if the teacher starts with each student `a` (from `1` to `n`).

**Example output:**
2 2 3

---

## 💡 Strategy

For each starting student `a`:

- Use a **visited array** to track which student’s badge has already been pierced.  
- Start at `a` and keep following the blame chain: `a → p[a] → p[p[a]] → ...`  
- When you reach a student who’s already been visited, that’s your answer.  
- Repeat for each student as the starting point.

No fancy data structures, no fancy algorithms — just plain **brute-force simulation**.

---

## 🚀 How to Run

```bash
g++ -std=c++17 -o badge badge.cpp
./badge < input.txt > output.txt
```
## 🧠 Time Complexity
For each of the n students, you might traverse up to O(n) steps.

Overall: O(n^2), which is fine because n ≤ 1000.

Works fast enough for a summer informatics school, even if your soul feels slow.

## 🔖 Tags
graph simulation dfs cycles badge_piercing why_are_we_like_this

## 🛠 Why This Exists
Because every good story starts with a teacher and some troublemakers.

To practice simulation and cycle detection in permutations.

So you can look back in 3 months and think: “Why was I so worried about holes in badges?”

Happy coding! May you always find your cycles and never be the student getting two holes.
