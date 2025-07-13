# 🐄 Pair Up – USACO Silver (January 2018)

This directory contains a C++ solution to the **"Pair Up"** problem from the USACO Silver division, January 2018 contest.

## 📜 Problem Summary
> You are given `n` groups of cows, each group with a count and a fixed milking time. You can only milk two cows at a time (from any two groups), and your goal is to **minimize the maximum milking time among all pairings**.

- Some groups might pair with themselves if there's an odd count
- All cows must be paired
- You want the smallest possible *worst-case* milking time across all those pairs

## 📥 Input Format
- Line 1: `n` (number of cow groups)
- Next `n` lines: each line contains `count` and `milking time` for that group

## 📤 Output Format
- A single integer: the **minimum possible maximum milking time** among all cow pairs

## 💡 Strategy

1. **Store the cow groups** as `(milking time, count)` pairs.
2. **Sort by milking time**
3. Use a **two-pointer** strategy:
   - Start from both ends (`i`, `j`)
   - Pair cows from `i` and `j`
   - Track the sum of their milking times → keep the **max** seen
   - Adjust counts, move pointers if exhausted
4. Special case when `i == j`: pair within the same group, divide count by 2.

### 🧠 Key Insights
- Greedy pairing: fastest cow + slowest cow = best shot at keeping the worst pair manageable.
- Sorting guarantees optimality: no reason to match two slow cows unless forced.

## 🚀 How to Run
```sh
g++ -std=c++17 -o pairup pairup.cpp
./pairup < pairup.in > pairup.out
```
## 🧠 Time Complexity
Sorting: O(n log n)

Two-pointer sweep: O(n)

Total: O(n log n) — beautifully efficient, like a cow on rollerblades

###🔖 Tags
silver greedy two-pointers sorting pairing optimization

They say two cows are better than one, unless you're optimizing for time. In which case: group by guilt, sort by shame, and pair with ruthless efficiency.
