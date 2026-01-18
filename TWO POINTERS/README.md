# 🧠 Two Pointers Pattern – Ultimate Recognition Guide

Two Pointers is one of the **highest ROI DSA patterns**.  
If you master **pattern recognition**, ~40–50% array/string problems become straightforward.

---

## ✅ When to Think of Two Pointers (95% Accuracy Rule)

If **any one** of these conditions matches, **Two Pointers should be your first instinct** 👇

---

## 1️⃣ Array / String (Sequential / Contiguous Data) ⭐⭐⭐⭐⭐

**Keywords / Signals**
- array
- string
- linked list
- continuous memory
- traversal from start/end

👉 **Default instinct: Two Pointers**

**Common Variants**
- Same direction (slow–fast)
- Opposite direction (left–right)

**Examples**
- Remove Duplicates
- Move Zeroes
- Reverse String
- Linked List Cycle

---

## 2️⃣ Sorted Input (or Sorting Allowed) ⭐⭐⭐⭐⭐

**Keywords**
- sorted
- increasing / non-decreasing
- smallest / largest pair
- closest sum
- target sum

👉 **Opposite Two Pointers (`l`, `r`)**

**Why?**
- Sorting gives monotonic behavior
- Decisions become greedy

**Examples**
- Two Sum II
- 3Sum / 4Sum
- Boats to Save People
- Container With Most Water

---

## 3️⃣ In-Place Modification Required ⭐⭐⭐⭐⭐

**Keywords**
- modify array in-place
- O(1) extra space
- remove / move elements

👉 **Read–Write Two Pointers**

**Idea**
- One pointer reads
- One pointer writes valid elements

**Examples**
- Move Zeroes
- Remove Duplicates I / II
- Merge Sorted Array

---

## 4️⃣ Subarray / Substring With Condition ⭐⭐⭐⭐

**Keywords**
- longest / shortest / count
- contiguous segment
- maintain condition

👉 **Sliding Window (Two Pointers)**

**Structure**
- expand right pointer
- shrink left pointer when condition breaks

**Examples**
- Longest Substring Without Repeating Characters
- Minimum Window Substring
- Max Consecutive Ones
- Subarray Sum Equals K

---

## 5️⃣ Compare From Both Ends ⭐⭐⭐⭐

**Keywords**
- palindrome
- symmetric
- reverse logic

👉 **Left–Right Two Pointers**

**Examples**
- Valid Palindrome
- Backspace String Compare
- Reverse Vowels of a String

---

## 6️⃣ Pair / Triplet / K-Sum Problems ⭐⭐⭐⭐

**Keywords**
- pair / triplet
- sum / target

👉 **Sort + Two Pointers**

**Flow**
1. Sort array
2. Fix one element
3. Apply two pointers on remaining part

**Examples**
- 3Sum
- 4Sum
- Triplet Sum Closest

---

## 7️⃣ Partitioning / Rearrangement ⭐⭐⭐⭐

**Keywords**
- rearrange
- divide into categories
- left / right placement

👉 **Multiple Pointers**

**Examples**
- Sort Colors (Dutch National Flag)
- Partition Array

---

## 8️⃣ Negative + Positive Mix (Sorted Array) ⭐⭐⭐

**Keywords**
- negative + positive
- square / absolute values
- sorted result required

👉 **Two Ends → Merge Technique**

**Examples**
- Squares of a Sorted Array

---

## 🧠 Pattern → Pointer Mapping (Quick Table)

| Problem Signal | Pointer Strategy |
|---------------|------------------|
| Sorted + target | Left–Right |
| In-place | Read–Write |
| Longest / shortest subarray | Sliding Window |
| Palindrome | Both Ends |
| Rearrangement | Multiple pointers |
| Sorted negatives + positives | Two ends merge |

---

## 🚀 Interview Mindset

> **Rule of Thumb**  
If data is **array or string**,  
and traversal is possible from **start to end**,  
**Two Pointers must be considered first.**

---

## 📌 How to Practice Effectively

1. Identify **pattern before coding**
2. Decide **pointer type**
3. Write brute → optimize using pointers
4. Dry run with multiple test cases

---

## 🔥 Final Note

If you can **recognize the pattern**,  
implementation becomes **mechanical**.

Master recognition → speed + confidence 💯
