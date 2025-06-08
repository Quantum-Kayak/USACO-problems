# 🐄 Race – USACO Gold (January 2019)

This directory contains a C++ solution to the **"Race"** problem from the USACO Gold division, January 2019 contest.

## 📜 Problem Summary
> You’re given a total distance `K` and `N` test cases. For each test case, you're given a minimum speed `X` that you must reach at some point. You must start from rest (speed 0), accelerate by at most 1 per time unit, and eventually stop (speed 0 again). The goal is to compute the minimum time it takes to travel distance `K` while satisfying the constraint for each `X`.

## 📥 Input Format
- First line: `K N`  
- Next `N` lines: Each line contains one integer `X`

## 📤 Output Format
- `N` lines, each containing the minimum time required to complete the race for the corresponding `X`

## 💡 Strategy

### 🚗 Two Cases:
1. **Case 1 – Small Distance**:  
   If `K ≤ X*(X+1)/2`, then the cow can just accelerate to speed `≤ X` and stop without needing to cruise.
   - Simulate acceleration until total distance `≥ K`.

2. **Case 2 – Needs Cruising**:  
   If `K` is too large, we must accelerate beyond `X`, then decelerate back to `X`, and potentially cruise at peak speed.
   - Try all peak speeds from `X` upwards
   - Simulate:  
     - Accelerate up to peak  
     - Decelerate down to `X`  
     - Cruise at peak speed if still under `K`

### 🧠 Key Observations:
- Acceleration phase contributes `(peak*(peak+1))/2`
- Deceleration (from `peak` to `X`) contributes `(peak-1+X)*steps/2`
- Remaining distance can be cruised at `peak`
- Binary search possible, but bounded loop up to ~1e5 is fast enough

## 🚀 How to Run
```sh
g++ -std=c++17 -o race race.cpp
./race < race.in > race.out
```
## 🧠 Time Complexity
For each test case:

Worst-case loop over peak ∈ [X, 1e5]

Simulation inside loop is O(1) since all steps are linear and controlled

Total: O(N * max peak tries) — good for N ≤ 10000

## 🔖 Tags
gold simulation math acceleration-rules brute-but-fine

Happy racing. May your cows be swift, your speed legal, and your cruise phases minimal.
