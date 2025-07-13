# 🐄 Word Processor – USACO Bronze (December 2018)

This directory contains a C++ solution to the **"Word Processor"** problem from the USACO Bronze division, December 2018 contest.

## 📜 Problem Summary
> Farmer John is trying to format text on his ancient cowputer.
> - He has `N` words to print.
> - Each line can hold at most `K` characters.
> - Words are separated by single spaces.
>  
> Your job: format the words such that no line exceeds `K` characters.

## 📥 Input Format
- Line 1: `N K` – number of words and max line length
- Line 2: `N` space-separated words (each ≤ `K` characters)

## 📤 Output Format
- Print the words across lines, ensuring no line is longer than `K`
- Do not print trailing spaces

## 💡 Strategy

- Read all words
- Track the current line’s length (`cur`)
- If `cur + word.size()` exceeds `K`, start a new line
- Otherwise, print with space if needed

### 🧠 Notes:
- This is *literally* word wrapping. If you’ve written a blog post or an essay in your life, you’ve mentally solved this problem already.
- Only the first word of a line has no space before it. Every other word on the line does.

## 🚀 How to Run
```sh
g++ -std=c++17 -o word word.cpp
./word < word.in > word.out
```
## 🧠 Time Complexity
Reading + processing: O(N)

String operations are bounded and small

Total: O(N) — this thing runs faster than Farmer John types

### 🔖 Tags
bronze simulation string-formatting line-breaking spacing

This problem is just a text editor without backspace. You’ve basically built the world's worst LaTeX parser. Congratulations.
