# 🐄 USACO Problems Repository

Welcome to my archive of solved USACO problems, organized for brutal clarity, long-term reference, and future self-roasting. Each problem includes:

- ✅ A `.cpp` file with the complete solution
- 🧠 A `README.md` (or `.XN.md`) with an explanation, strategy breakdown, and mental notes
- 🗂 Sorted by **division**, **difficulty**, and **problem metadata**

---

## 📁 Repository Structure

```text
USACO-problems/
├── bronze/
│   ├── starred/
│   │   ├── easy/
│   │   ├── normal/
│   │   ├── hard/
│   │   └── insane/
│   └── unstarred/
│       ├── easy/
│       ├── normal/
│       ├── hard/
│       └── insane/
├── silver/
│   └── starred/...
├── gold/
│   └── ...
└── plat/
    └── ...
```
## 🎯 Naming Convention

Each problem folder contains:

- `problemname.cpp` → The actual C++ solution  
- `problemname.md` → Writeup and explanation  
- `problemname.XN.md` → If the problem is cursed, deranged, or deserves its own therapy session  

**Examples:**
```text
bronze/starred/easy/blockgame/
├── blockgame.cpp
└── blockgame.md

silver/unstarred/hard/fencedin/
├── fencedin.cpp
└── fencedin.XN.md
```

# 🐄 Problem Name – USACO [Division] ([Month Year])

This directory contains a C++ solution to the **"[Problem Name]"** problem from the USACO [Division] division.

## 📜 Problem Summary
> Your own words summary of what’s going on, who’s angry (usually cows), and what you’re solving.

## 📥 Input Format
- Line-by-line breakdown
- Optional sample input

## 📤 Output Format
- What it prints
- Optional example output

## 💡 Strategy
- Key idea / pattern used
- Edge cases handled
- Algorithm + time complexity

## 🚀 How to Run
```sh
g++ -std=c++17 -o problem problem.cpp
./problem < input.txt > output.txt
```

🔖 Tags  
division difficulty topics regret

```
division difficulty topics regret
```

---

## 🛠 Why This Exists

- To **practice USACO-style competitive programming**  
- To **build searchable knowledge** of problem-solving patterns  
- To **leave behind a map** for myself (and maybe others) on how I solved — or suffered through — each problem  

---

Happy coding. May your segments never overflow, and your trees remain acyclic.  
---

## 📜 Problem Summary

> Brief description of what the problem asks you to do, in your own words.  
> Mention the core entities (e.g., cows, segments, paths, trees) and what the goal is.  
> Keep it short but clear enough to understand without reading the whole problem again.  

---


## 📥 Input Format

Explain the input line by line.  
Use bullet points or line-by-line breakdowns.

Example:

- Line 1: An integer `n` — the number of road segments (1 ≤ n ≤ 100)
- Next `n` lines: Two integers — segment length and speed limit
- Line after that: Integer `m` — the number of Bessie's segments
- Next `m` lines: Two integers — segment length and speed

*(Include an example input if useful)*

---

## 📤 Output Format

Describe exactly what the output should be.  
If it's a number, what does it represent?  
If it’s multiple values, in what order?

*(Optional: Include a sample output with explanation)*

---

## 💡 Approach

Explain your strategy:

- Step-by-step reasoning or algorithm
- How you modeled or represented the input
- Key logic used (e.g., prefix sums, greedy, DFS, arrays)
- What edge cases you handled

---

## 🧪 Example(s)
```txt
Input:
3
40 75
50 35
10 40
3
40 76
50 35
10 40

Output:
1
```

Explanation: Bessie is 1 mph over the speed limit at mile 40.

## 🧠 **Time Complexity**  
Break it down cleanly:

- Reading/expanding segments: O(n + m)  
- Comparison loop: O(100)  
- Overall: O(n + m)  

## 📁 **Files**  
- \`problemname.cpp\` – C++ source code  
- \`problemname.in\` / \`problemname.out\` – Sample input/output  
- \`problemname.md\` – You are here. Welcome to the pain log.  

## 🚀 **How to Run**

```sh
g++ -std=c++17 -o problemname problemname.cpp
./problemname < problemname.in > problemname.out
```

Or submit to the judge and pray.

## 🫠 **Notes**  
Mention any USACO quirks (e.g., \`freopen\`, file names)


Edge cases you almost missed

Optional regrets and rage quotes

## 🔖 Tags
bronze arrays brute-force sim rage-minor

# USACO template🐮

``` cpp
#include <iostream>
#include <fstream>
using namespace std;

void setIO(const string &name) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("test"); 
    
    return 0;
}


```
