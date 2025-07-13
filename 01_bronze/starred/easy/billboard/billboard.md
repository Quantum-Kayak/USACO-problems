# 🐄 Billboard – USACO Bronze (December 2017)

This directory contains a C++ solution to the **"Billboard"** problem from the USACO Bronze division, December 2017 contest.

## 📜 Problem Summary
> You’re given two rectangles on a 2D plane:
> - One represents a **billboard** that should be visible.
> - The other represents a **covering banner** that might block part of the billboard.
>  
> The goal is to compute the visible area of the billboard after being partially or fully covered.

## 📥 Input Format
- First line: Coordinates of the billboard rectangle (x1 y1 x2 y2)
- Second line: Coordinates of the covering banner rectangle (x1 y1 x2 y2)

## 📤 Output Format
- A single integer representing the visible area of the billboard after accounting for any overlap

## 💡 Strategy

1. **Compute the full area** of the billboard:  
   `width × height`

2. **Determine the overlap**:
   - Use the classic 1D interval intersection trick for both `x` and `y`
   - Overlap area = `overlapX * overlapY`

3. **Edge Case**:
   - Only subtract the overlap if the banner completely blocks the billboard along either the full `x` **or** full `y` dimension.
   - If banner is just *partially* covering, we don’t subtract anything.

### 🧠 Key Conditions:
- `fullX`: if banner stretches across the entire horizontal span of the billboard
- `fullY`: if it stretches across the entire vertical span

### ✂️ Final Area:
- If either `fullX || fullY`, subtract the overlap area
- Otherwise, billboard is still fully visible → output full area

## 🚀 How to Run
```sh
g++ -std=c++17 -o billboard billboard.cpp
./billboard < billboard.in > billboard.out
```
## 🧠 Time Complexity
Input parsing: O(1)

Rectangle math: O(1)

Total: O(1) — as fast as a cow chewing gum

### 🔖 Tags
bronze geometry rectangle overlap visible-area edge-cases

The only billboard that matters is the one that wasn’t entirely blocked by a rogue banner. Geometry is harsh. Visibility is everything.
