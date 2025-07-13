# 🐄 Kayaking – USACO Silver (Inspired by Codeforces B)

This directory contains a C++ solution to the “Kayaking” problem, where you must assign `2n` people into `n - 1` tandem kayaks and 2 single kayaks in a way that minimizes the **total instability**. Instability is defined as the absolute difference of weights for each tandem pair; single kayaks contribute zero.

## 📜 Problem Summary

You are given weights of `2n` people. You must:
- Choose **2** people to sit in **single kayaks** (zero instability),
- Pair the remaining `2n - 2` people into `n - 1` **tandem kayaks**,
- Calculate total instability as the sum of weight differences in tandem kayaks,
- And find the **minimum possible** total instability over all such configurations.

People do not enjoy flipping into lakes, surprisingly.

## 📥 Input Format

Line 1: Integer n (2 ≤ n ≤ 50)
Line 2: 2n integers — weights of the people

shell
Copy
Edit

### Example Input 1:
2
1 2 3 4

shell
Copy
Edit

### Example Input 2:
4
1 3 4 6 3 4 100 200

shell
Copy
Edit

## 📤 Output Format

A single integer — the **minimum possible total instability**.

### Example Output 1:
1

shell
Copy
Edit

### Example Output 2:
5

markdown
Copy
Edit

## 💡 Approach

### Strategy:
- Brutally brute-force™: try every pair of people as the two solo kayakers (yep, all O(n²) of them),
- Remove those two from the list, sort the remaining,
- Greedily pair adjacent people in the sorted list for minimum weight difference,
- Track the smallest total instability.

### Algorithm:
1. Try all pairs `(i, j)` to be in single kayaks.
2. Remove them from the array.
3. Sort the remaining weights.
4. Sum differences between every consecutive pair.
5. Keep the minimum sum over all `(i, j)`.

### Time Complexity:
- Brute-force all solo pairs: O(n²)
- For each pair:
  - Copy and sort list: O(n log n)
  - Pair greedily: O(n)

**Total:** O(n² · n log n) — which is... tolerable. Like lukewarm soup.

## 🧪 Example Walkthrough

For input `1 3 4 6 3 4 100 200`, one optimal configuration:
- Single kayaks: 100 and 200
- Remaining sorted: 1 3 3 4 4 6
- Pairs: (1,3), (3,4), (4,6) → Instability: 2 + 1 + 2 = **5**

## 🚀 How to Run

```bash
g++ -std=c++17 -O2 -o kayaking kayaking.cpp
./kayaking < kayaking.in > kayaking.out
Or submit it to the judge and pray to the segmentation fault gods.
```
## 🔖 Tags
silver brute-force greedy pairing introvert-simulator

## 🫠 Notes
- Avoid matching people with wildly different weights unless you're filming a kayaking disaster movie.

- This problem is a great demonstration of what happens when brute force meets actual constraints and nobody at Codeforces is there to stop you.
