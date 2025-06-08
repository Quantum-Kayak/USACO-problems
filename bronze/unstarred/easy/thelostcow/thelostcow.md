# 🐄 Lost Cow – USACO Bronze (December 2017)

This directory contains a C++ solution to the **"Lost Cow"** problem from the USACO Bronze division, December 2017 contest.

## 📜 Problem Summary
> Farmer John loses track of his cow. He's at position `x`, and he knows the cow is at position `y`.  
> Being Farmer John, he searches in the dumbest possible way:
> - First he walks from `x` to `x+1`, then back to `x-2`, then to `x+4`, then back to `x-8`, and so on.
> - He keeps doubling his search distance and alternating direction.
>  
> The cow stays in place and waits. We must compute the **total distance FJ walks** until he finds the cow.

## 📥 Input Format
- A single line with integers `x y` (FJ's position, cow's position)

## 📤 Output Format
- A single integer: the total distance FJ walks before reaching the cow

## 💡 Strategy

- Simulate Farmer John's bouncing path:
  - He alternates direction (+, -, +, -...)
  - Each segment is `2^n` long
- For each new segment:
  - If the cow lies between `now` and `next`, he finds it mid-walk.
  - Otherwise, add full segment length to total and continue.

### 🧠 Key Observations:
- The direction flips (`dir *= -1`)
- Step length doubles (`cstep *= 2`)
- He always starts from his original `x`, never from `0`

## 🚀 How to Run
```sh
g++ -std=c++17 -o lostcow lostcow.cpp
./lostcow < lostcow.in > lostcow.out
```
## 🧠 Time Complexity
Simulated until FJ finds the cow

Worst-case: walks until cow lies within a segment → exponential growth

Total steps: O(log(abs(x - y)))

### 🔖 Tags
bronze simulation number-line direction-flip doubling chaos

This problem proves that if you’re stubborn enough and make all the wrong decisions in just the right way, you’ll still eventually succeed. Very inspirational. Very bovine.
