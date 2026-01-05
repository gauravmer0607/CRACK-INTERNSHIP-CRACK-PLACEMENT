# SLIDING WINDOW CHEATSHEET

## Sliding window - is an optimization technique used to **reduce time complexity** when working with:
- Subarrays
- Substrings
- Continuous ranges

### ADDITION:
- substring + unique condition -> Then use set/Map/Array
- substring + sum/k operation -> shrink rule different

## 1️⃣ Frequency Array / Hash Map ⭐⭐⭐⭐⭐

👉 Used in **~60–70%** of Sliding Window problems  
This is the **MOST IMPORTANT** data structure for sliding window.

---

### 📌 When to Use
Use Frequency Array / Hash Map when you need to:

- Maintain **count of characters or numbers** inside the window  
- Track **distinct elements** in a window  
- Solve **substring / anagram** related problems  
- Check **validity of a window** based on counts  
- Expand and shrink window while keeping frequency updated

---

### 🧠 Core Idea
- Window expand → **add element to frequency**
- Window shrink → **remove element from frequency**
- Use frequency to check if window is **valid or invalid**

---

## 2️⃣ Two Pointers (l, r) ⭐⭐⭐⭐⭐

👉 **Mandatory for every Sliding Window problem**  
Sliding Window = Two Pointers (no exception)

---

### 📌 Role of Pointers
- `r` → **Expand window** (include new element)
- `l` → **Shrink window** (remove old element)

---

### 🧠 Core Idea
- Right pointer (`r`) aage badhta hai → window grow hoti hai
- Jab window **invalid** ho jaaye → left pointer (`l`) aage badhao
- Window ko valid banaye rakhte hue answer update karo

## 3️⃣ Deque (Double Ended Queue) ⭐⭐⭐⭐

👉 Used in **~10–15%** of Sliding Window problems

---

### 📌 When to Use
Use **Deque** when:
- Har window ka **maximum / minimum** nikalna ho
- Window ke elements ka **order maintain** karna ho
- O(n) time me sliding window max/min chahiye

---

### 🧠 Core Idea
- Deque me **indices store** kiye jaate hain (values nahi)
- Deque ko **monotonic** rakha jaata hai:
  - **Maximum** ke liye → decreasing order
  - **Minimum** ke liye → increasing order

---

## 4️⃣ Set / Ordered Map ⭐⭐⭐ (Rare but Powerful)

👉 Used in special sliding window problems where window ke elements sorted order me maintain karne hote hain.

### 📌 When to Use
- Window ke andar sorted order chahiye
- Exact max / min / median chahiye
- Window slide hote waqt insertion + deletion dono required ho
- Heap ka kaam ho raha ho but arbitrary deletion bhi chahiye

## 🧠 QUICK DECISION TABLE (INTERVIEW GOLD)

Use this table to **instantly decide** which data structure to use in a Sliding Window problem.

| Question Type              | Data Structure         |
|---------------------------|------------------------|
| Characters / Frequency    | Array / HashMap        |
| Distinct elements         | HashMap                |
| Fixed window sum          | No DS needed           |
| Max / Min in window       | Deque                  |
| Count subarrays           | Prefix Sum + HashMap   |
| Median in window          | Multiset / Heap        |

---

### 🧠 How to Use This in Interview
- Pehle question ko **category** me map karo  
- Table dekho → **data structure pick karo**
- Phir **two pointers** lagao (mandatory)

---

### 🥇 One-Liner Reminder
> **Sliding Window = Two Pointers + Right Data Structure**

### Written By - Gaurav Mer