# 🐄 Cow Basic HashMap – USACO Bronze (Mock or Training)

This directory contains a C++ solution to a **key-value store simulation** problem, likely from a USACO Bronze practice set or training module.

## 📜 Problem Summary
> You’re given `n` operations. Each operation is one of the following:
>
> - `0 b c`: Store the value `c` under key `b`
> - `1 b`: Retrieve and print the value stored at key `b`
>
> This is literally a hashmap in disguise. A cow-map, if you will.

## 📥 Input Format
- First line: integer `n` – number of operations
- Next `n` lines: each operation, either `0 b c` (set) or `1 b` (get)

## 📤 Output Format
- For every get (`1 b`) operation, output the value stored under key `b`

## 💡 Strategy

- Use `unordered_map<ll, ll>` to simulate the key-value store
- For `a == 0`, set `arr[b] = c`
- For `a == 1`, print `arr[b]`
  - Assume key `b` is always valid and exists before being accessed

### 🧠 Notes:
- This problem is just here to make sure you remember how maps work
- You could almost solve it in Python in 3 lines
- C++ is just extra drama sometimes

## 🚀 How to Run
```sh
g++ -std=c++17 -o hashmap hashmap.cpp
./hashmap < hashmap.in > hashmap.out
```
## 🧠 Time Complexity
Each operation: O(1) average-case (thanks to unordered_map)

Total: O(n) — which is why the cow keeps using it

### 🔖 Tags
bronze hashmap unordered_map simulation key-value memory

This problem proves two things:

Cows have learned about associative containers.

We’re all just one line of unordered_map away from enlightenment.
