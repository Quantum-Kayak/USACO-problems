# 🐄 MooTube – USACO Silver (January 2018)

This directory contains a C++ solution to the **"MooTube"** problem from the USACO Silver division.

---

## 📜 Problem Summary
> Farmer John’s cows are getting into video sharing (naturally), and they want to find suggested videos for a given video, based on a relevance threshold K. Each video pair has a relevance weight, and for each query, we count how many other videos are reachable from a given video while only traversing edges with relevance ≥ K.

---

## 📥 Input Format
- First line: N (number of videos) and Q (number of queries)
- Next N-1 lines: p, q, r (two videos connected with relevance r)
- Next Q lines: k, v (query: minimum relevance threshold and starting video)

Sample input:
4 3
1 2 3
2 3 2
2 4 4
1 2
4 1
3 1

---

## 📤 Output Format
- For each query, output the number of videos (excluding the starting video) that meet the relevance requirement.

Sample output:
3
0
2

---

## 💡 Strategy
- Model the videos as a tree (since there are N-1 edges).
- Use DFS (or BFS, if you’re feeling fancy) to find all reachable videos from the given starting video for each query.
- Only traverse edges with relevance ≥ K.
- Reset the `visited` array and `count` for each query.
- Time complexity: O(NQ), which is good enough for small N and Q.

---

## 🚀 How to Run
```sh
g++ -std=c++17 -o mootube mootube.cpp
./mootube < mootube.in > mootube.out
```
## 🧠 Time Complexity
Break it down cleanly:

Building adjacency list: O(N)

Each DFS per query: O(N)

Overall for Q queries: O(NQ)

## 🔖 Tags
silver easy dfs trees thresholds

silver easy dfs trees thresholds
🛠 Why This Exists
To practice USACO-style competitive programming

To build searchable knowledge of problem-solving patterns

To leave behind a map for myself (and maybe others) on how I solved — or suffered through — each problem

Happy coding. May your segments never overflow, and your trees remain acyclic.
