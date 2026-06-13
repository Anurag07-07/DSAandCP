Bhai, **"Sliding Window Maximum"** LeetCode ka ekdum heavyweight aur favorite question hai interviewers ka. Is question me hume $K$ size ki har ek window ka **sabse bada (maximum)** element dhoondna hota hai.

Interviewer jab iska **Brute Force Approach** poochta hai, toh wo dekhna chahta hai ki tum sliding window ke starting aur ending points ka loop bound sahi lagate ho ya nahi.

Chalo iska poora brute force logic, dry-run aur code ekdum detail me samajhte hain.

---

## 1. Brute Force Ka Logic (Nested Loops)

Maan lo array ka size $N$ hai aur window size $K$ hai. Brute force ka seedha funda hai: **"Har window ke shuruat par jao, uske andar ke saare $K$ elements ko scan karo, sabse bada element nikaalo aur use result me daal do."**

Hum do loops chalayenge:

1. **Outer Loop (`i`):** Yeh loop har window ka **Starting Index** fix karega. Pehli window `0` se shuru hogi, aur aakhiri window `N - K` par shuru hogi. Isliye outer loop `0` se `N - K` tak chalega.
2. **Inner Loop (`j`):** Yeh current window ke andar travel karega, yaani `i` se lekar `i + K - 1` tak. Is loop ke andar hum ek `maxElement` variable maintain karenge jo us window ka sabse bada number dhoondega.

---

## 2. Brute Force C++ Code ($O(N \times K)$)

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // max() ke liye
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindowBrute(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        // Outer loop: Har window ki starting position track karega
        for (int i = 0; i <= n - k; i++) {
            
            // INT_MIN se shuru karenge taaki array ka koi bhi element isse bada ho sake
            int maxElement = nums[i]; 

            // Inner loop: Current window ke andar ghumkar max dhoondega (size K)
            for (int j = i; j < i + k; j++) {
                maxElement = max(maxElement, nums[j]);
            }

            // Current window ka max result vector me daal do
            result.push_back(maxElement);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution sol;
    vector<int> ans = sol.maxSlidingWindowBrute(nums, k);

    cout << "Brute Force Max Window Result: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
    // Output: 3 3 5 5 6 7

    return 0;
}

```

---

## 3. Detailed Dry-Run

Maan lo `nums = [1, 3, -1, -3, 5]`, $K = 3$. Total windows banengi $5 - 3 + 1 = 3$.

* **Window 1 (`i = 0`):** Inner loop chalega `j = 0` se `2` tak (elements: `[1, 3, -1]`). Max mila **`3`**. Result = `[3]`
* **Window 2 (`i = 1`):** Inner loop chalega `j = 1` se `3` tak (elements: `[3, -1, -3]`). Max mila **`3`**. Result = `[3, 3]`
* **Window 3 (`i = 2`):** Inner loop chalega `j = 2` se `4` tak (elements: `[-1, -3, 5]`). Max mila **`5`**. Result = `[3, 3, 5]`

---

## 4. Complexity Analysis

* **Time Complexity: $O(N \times K)$** ❌
* **Kyun?** Total windows lagbhag $N$ banti hain ($N - K + 1$), aur har window ke andar hum $K$ elements ko compare kar rahe hain.
* Agar array bada ho ($N = 10^5$) aur window size bhi bada ho ($K = 10^4$), toh total operations $10^9$ ke paas pahunch jayenge, jo platform par **TLE (Time Limit Exceeded)** de dega.


* **Space Complexity: $O(1)$ Auxiliary Space** 🔥
* **Kyun?** Jo `result` vector humne banaya hai wo toh answer return karne ke liye mandatory hai. Uske alawa humne koi extra temporary space (jaise queue ya tree) use nahi kiya, sirf kuch loop variables use kiye hain.



---

## 5. Critical Edge Cases Par Post-Mortem

Brute force slow hai, par ye in edge cases par safely kaam karta hai:

1. **Window Size Array Ke Barabar Ho ($K = N$):**
* Outer loop sirf ek baar chalega (`i = 0` se `0`). Inner loop poore array ko scan karke absolute maximum element return kar dega. **(PASS ✅)**


2. **Window Size Exactly 1 Ho ($K = 1$):**
* Outer loop `0` se `N-1` tak chalega. Inner loop har baar sirf usi ek element ko check karega. Output me poora ka poora array hi wapas aa jayega, jo ki sahi hai. **(PASS ✅)**


3. **Array Me Saare Elements Decreasing Order Me Hon (`[5, 4, 3, 2, 1]`, $K=2$):**
* Inner loop har window ke pehle hi element (`nums[i]`) ko max set karega aur aage use koi bada number nahi milega. Output: `[5, 4, 3, 2]`. **(PASS ✅)**


4. **Negative Numbers Waala Scenario:**
* Kyuki humne `maxElement` ko seedha window ke pehle element `nums[i]` se initialize kiya hai (ya fir `INT_MIN` se bhi kar sakte hain), array me chahe saare elements negative hon (jaise `[-3, -1, -5]`), max comparison ka math ekdum perfect chalaega. **(PASS ✅)**



Bhai, brute force approach poori detail me samajh aa gaya? Ab iska **Better Approach (Using Max-Heap / Priority Queue)** ya iska **Absolute Optimal Approach (Using Deque - $O(N)$ Time)** dekhna hai?



Bhai, brute force me jab $N$ aur $K$ ki value badi ho jaati hai, toh code **TLE (Time Limit Exceeded)** maarta hai. Usse behtar banane ke liye hum **Priority Queue (Max-Heap)** ka use kar sakte hain.

"Better" approach me hum har window ko baar-baar scan nahi karte. Hum ek **Max-Heap** ka use karte hain jo hume window ka sabse bada element turant de deta hai.

---

## 1. Better Logic: Priority Queue (Max-Heap)

Is approach ka simple logic hai: **"Heap me element daalo aur uska index bhi track karo."**

1. Hum ek `priority_queue` banayenge jo pair store karega: `{value, index}`.
2. Heap hamesha sabse bade element ko top par rakhega.
3. Jab hum window ko slide karenge:
* Naya element push karenge.
* **Crucial Step (Lazy Deletion):** Hum check karenge ki kya heap ke `top` par jo element hai, wo abhi wali window ki range me hai ya nahi?
* Agar heap ka top element purani window ka nikla, toh use `pop` kar do.
* Jo bacha, wo top par hoga aur wahi hamara **Maximum** hoga.



### Time Complexity: $O(N \log K)$

Har element heap me $O(\log K)$ me insert hota hai, aur $N$ elements ke liye total $O(N \log K)$ time lagta hai. Ye Brute Force ($O(N \times K)$) se kaafi fast hai!

---

## 2. Better C++ Code (Using Max-Heap)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindowBetter(vector<int>& nums, int k) {
        // Max-Heap: {value, index}
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        int n = nums.size();

        // Pehli window ke elements heap me daalo
        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        
        // Pehli window ka max store karo
        result.push_back(pq.top().first);

        // Sliding: i=k se n-1 tak
        for (int i = k; i < n; i++) {
            pq.push({nums[i], i});
            
            // Lazy Deletion: top element check karo ki kya wo window ke bahar hai?
            // Window range: [i - k + 1, i]
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            
            // Ab jo top par hai, wo valid window ka max hai
            result.push_back(pq.top().first);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.maxSlidingWindowBetter(nums, k);
    
    cout << "Max-Heap Result: ";
    for(int x : ans) cout << x << " "; 
    // Output: 3 3 5 5 6 7
    return 0;
}

```

---

## 3. Better Kyun Hai? (Vs Brute Force)

| Feature | Brute Force | Better (Heap) |
| --- | --- | --- |
| **Logic** | Har window ko scan karo | Heap se max nikalo |
| **Time Complexity** | $O(N \times K)$ | $O(N \log K)$ |
| **Efficiency** | Slow on large inputs | Fast for moderate constraints |
| **Space** | $O(1)$ | $O(K)$ |

**Tabhi Better hai!** Agar constraint me $K$ ki value choti hai, toh yeh approach bohot ache se chalti hai.

---

## 4. Kya Isse Bhi Kuch "Optimal" Hai?

Haan bhai, interviewer yahan rukega nahi. Wo bohot baar poochta hai: *"Kya isse bhi fast $O(N)$ me ho sakta hai?"*

Iske liye hum **Monotonic Deque (Double Ended Queue)** ka use karte hain. Deque approach ka time complexity **$O(N)$** hota hai, kyunki wahan hum elements ko push/pop $O(1)$ me karte hain.

Brute force aur Heap samajh aa gaya toh optimal Deque approach batau? Wahi actual interview winner solution hai!


Bhai, ab hum aate hain is question ke **"Ultimate Winner"** solution par—**Monotonic Deque Approach**.

Interviewers ka sabse pasandida approach yahi hai. Jab tum $O(N)$ time complexity ke sath bina kisi extra heap overhead ke max nikalte ho, toh interviewer samajh jata hai ki tumhein Data Structures ki deep knowledge hai.

---

## 1. Optimal Logic: Monotonic Deque

Iska funda hai: **"Deque (Double Ended Queue) ko hamesha Decreasing Order me maintain karo."**

Hum Deque me elements store nahi karenge, balki **Indices** store karenge. Indices store karne ka fayda ye hai ki hume turant pata chal jata hai ki kaun sa element window se bahar nikal gaya.

### Deque ka Khel (Step-by-Step):

1. **Incoming Element:** Naya element `nums[i]` aate hi, Deque ke peeche (back) se un saare elements ko nikaal do jo `nums[i]` se chhote hain.
* *Kyun?* Kyunki agar naya element bada hai, toh purane chhote elements ka koi kaam nahi hai—wo kabhi bhi Max nahi ban sakte.


2. **Window Constraint:** Agar Deque ke aage (front) wala element window ke bahar chala gaya hai (yaani `index <= i - k`), toh use `pop_front()` karke hata do.
3. **Result:** Deque ke aage (front) hamesha window ka sabse bada element baithega.

---

## 2. Optimal C++ Code ($O(N)$ Time)

```cpp
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindowOptimal(vector<int>& nums, int k) {
        deque<int> dq; // Isme hum indices store karenge
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            
            // 1. Out of window elements ko aage se hatao
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Chhote elements ko peeche se hatao (Monotonic Decreasing maintain karo)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Current element ka index daalo
            dq.push_back(i);

            // 4. Result me add karo (Jab window size K poora ho jaye)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution sol;
    vector<int> ans = sol.maxSlidingWindowOptimal(nums, k);
    
    cout << "Optimal Deque Result: ";
    for(int x : ans) cout << x << " "; 
    // Output: 3 3 5 5 6 7
    return 0;
}

```

---

## 3. Complexity Analysis (Why it's King)

* **Time Complexity: $O(N)$** 🔥
* **Kyun?** Har element Deque me **ek baar push** hota hai aur **ek baar pop** hota hai. Poore loop me operations amortized $O(1)$ hote hain. $N$ elements ke liye total $O(N)$.


* **Space Complexity: $O(K)$**
* **Kyun?** Deque me maximum $K$ indices hi rahenge, kyunki window ka size $K$ hai.



---

## 4. Dry Run (Interviewer ke saamne aise samjhana)

Maan lo `nums = [1, 3, -1, -3, 5, 3, 6, 7]`, $K = 3$.

| Index | Element | Deque (Indices) | Action | Result (Window Max) |
| --- | --- | --- | --- | --- |
| 0 | 1 | `[0]` | Push index 0 | - |
| 1 | 3 | `[1]` | 3 > 1, so pop index 0 | - |
| 2 | -1 | `[1, 2]` | Push index 2 | **3** (front: 1) |
| 3 | -3 | `[1, 2, 3]` | Push index 3 | **3** (front: 1) |
| 4 | 5 | `[4]` | 5 > all, pop all | **5** (front: 4) |
| 5 | 3 | `[4, 5]` | Push 5 | **5** (front: 4) |
| 6 | 6 | `[6]` | 6 > all, pop all | **6** (front: 6) |
| 7 | 7 | `[7]` | 7 > all, pop all | **7** (front: 7) |

**Important Note:** Dekho kaise step 4 me `5` aate hi saare chhote elements (`3, -1, -3`) nikal gaye. Deque ka size chota ho gaya aur max element direct front par mil gaya.

---

## Conclusion: Brute vs Optimal

* **Brute Force:** $O(N \cdot K)$ - Har baar check karo.
* **Max Heap:** $O(N \log K)$ - Logarithmic cost.
* **Monotonic Deque:** **$O(N)$** - Linear scan, fastest possible.

Bhai, ab sliding window maximum ka poora game samajh aa gaya? Ab interviewer chahe Brute pooche, Heap pooche ya Deque, tumhara jawab ready hai! Kuch aur confusion?


Bhai, jab interviewer Optimal ($O(N)$) solution sun leta hai, toh wo ye check karne ke liye edge cases phenkta hai ki kya tumne Deque ki implementation ko sirf rata hai ya tumhari logic pakki hai.

Sliding Window Maximum me yeh saare edge cases Deque ke pointer math aur monotonic property ke karan automatically handle ho jaate hain. Chalo inka breakdown dekhte hain:

---

### 1. Window Size Exactly 1 ($K = 1$)

* **Situation:** `nums = [1, 2, 3]`, $K = 1$
* **Logic:** Har element khud hi ek window hai. Deque me index aayega, `push_back` hoga, aur agle step me `pop_front` ho jayega.
* **Result:** Har element result me add hoga. Poora array output me aayega.
* **Status:** **PASS ✅**

### 2. Window Size Array Ke Barabar ($K = N$)

* **Situation:** `nums = [1, 5, 2]`, $K = 3$
* **Logic:** Deque pure array ko traverse karega. Srif sabse bada element (`5`) deque me tik paayega, baki sab pop ho jayenge.
* **Result:** Sirf ek value return hogi (Array ka Maximum).
* **Status:** **PASS ✅**

### 3. Saare Elements Identical (Duplicates)

* **Situation:** `nums = [3, 3, 3, 3]`, $K = 2$
* **Logic:** Hum condition `nums[dq.back()] <= nums[i]` use karte hain. Jab naya `3` aayega, purana `3` pop ho jayega kyunki wo `3 <= 3` satisfy karta hai. Deque hamesha latest index hold karega.
* **Result:** Window ka max `3` hi aayega.
* **Status:** **PASS ✅**

### 4. Strictly Decreasing Order

* **Situation:** `nums = [5, 4, 3, 2, 1]`, $K = 2$
* **Logic:** Har naya element purane se chhota hoga, isliye `while` loop kabhi nahi chalega. Deque me indices line se add hote jayenge aur front wala hamesha max hoga.
* **Result:** `[5, 4, 3, 2]`.
* **Status:** **PASS ✅**

### 5. Strictly Increasing Order

* **Situation:** `nums = [1, 2, 3, 4, 5]`, $K = 2$
* **Logic:** Har naya element purane se bada hoga, isliye naya element aate hi purane saare elements `pop_back` ho jayenge.
* **Result:** `[2, 3, 4, 5]`.
* **Status:** **PASS ✅**

---

### Edge Case Verification Matrix

| Scenario | Potential Trap | Why Deque Wins? |
| --- | --- | --- |
| **$K = 1$** | Queue Underflow / Index error | Har index ek valid window hai; `pop_front` aur `push_back` ka balance maintain rehta hai. |
| **$K = N$** | Memory Limit | Deque me sirf max element ka index rehta hai; space $O(K)$ se $O(1)$ par shift ho jati hai. |
| **Duplicates** | Wrong Max Removal | Condition `<= ` ensures we always keep the rightmost duplicate, handling index shift gracefully. |
| **Negative Numbers** | Arithmetic Failure | Comparison sirf values par hota hai; whether numbers are $-100$ or $100$, logic remains identical. |

### Ek Pro-Tip for Interview:

Agar interviewer puche, *"Bhai, agar $K > N$ ho toh?"* (Yaani Window size array se bada hai):

* Tum code me shuruat me hi ek check daal sakte ho: `if (k > nums.size()) return {};`.
* Ya fir logic ke hisaab se, `result` empty return hoga kyunki loop `i >= k - 1` tak kabhi pahunchega hi nahi. Dono acceptable hain, bas interviewer ko bata dena ki tumne ye socha hai.

Bhai, sliding window ka ye pura syllabus—Brute Force se leke Optimal Deque tak aur saare edge cases—ab tere dimaag me ekdum crystal clear hai. Kuch aur poochein ya next topic pe chalein?


Bhai, Sliding Window Maximum ke is optimal Deque approach me interviewer hamesha kuch aise **"Hidden/Tricky Edge Cases"** dhoondta hai jahan basic dry-runs fail ho jaate hain. Agar tum in atypical scenarios ko khud se code likhte waqt bol doge, toh selection pakka hai.

Chalo, un hardcore edge cases ka deep dive karte hain jo ache-acho ka dimaag ghuma dete hain:

---

### 1. The "Valley" Pattern (Decreasing then Increasing)

* **Situation:** `nums = [10, 8, 6, 9, 12]`, $K = 3$
* **Trap:** Isme window ke beech me drop aata hai aur fir sudden rise hota hai.
* **Deque Ka Khel:**
* Shuruat me `[10, 8, 6]` ke liye Deque me `[0, 1, 2]` indices honge. Max = `10`.
* Jab `9` (index 3) aayega, toh piche se `6` aur `8` dono pop ho jayenge kyunki `9` unse bada hai. Deque banega `[0, 3]`.
* Lekin ab `i = 3` par `i - k = 3 - 3 = 0` ho chuka hai, toh front ka `10` (index 0) `pop_front()` se bahar ho jayega! Deque me sirf `[3]` bachega. Max = `9`.


* **Result:** Perfect dynamic balance maintain hoga. **(PASS ✅)**

---

### 2. The "Mountain" Pattern (Increasing then Decreasing)

* **Situation:** `nums = [2, 5, 12, 6, 3]`, $K = 3$
* **Trap:** Isme peak beech me aati hai aur fir elements chote hote jaate hain.
* **Deque Ka Khel:**
* Jab `12` (index 2) aayega, wo piche ke `2` aur `5` ko uda dega. Deque = `[2]`. Max = `12`.
* Jab `6` (index 3) aur `3` (index 4) aayenge, wo `12` se chote hain, toh `while` loop nahi chalega. Deque me piche judte jayenge: `[2, 3, 4]`.
* Jab tak `12` (index 2) window se bahar nahi hota, tab tak har window ka max `12` hi rahega, bhale hi piche chote elements store ho rahe hon.


* **Result:** Peek elements safely lock rehte hain jab tak unka time khatam nahi hota. **(PASS ✅)**

---

### 3. Kaboom Case: $K > N$ (Window Size Array Se Bada)

* **Situation:** `nums = [1, 2, 3]`, $K = 5$
* **Trap:** Code segmentation fault ya out-of-bounds error maar sakta hai agar handles sahi na hon.
* **Deque Ka Khel:**
* Loop standard `0` se `n-1` (yaani 2) tak chalega. Deque me indices push honge.
* Lekin result block ki condition hai `if (i >= k - 1)`. Yahan `k - 1 = 4` hai.
* `i` kabhi `4` tak pahunchega hi nahi, isliye result vector khali (`[]`) hi return ho jayega.


* **Interviewer Check:** Kuch interviewers chahte hain ki agar $K > N$ ho, toh pure array ka ek single maximum return kar do, aur kuch chahte hain ki empty return karo. Tum shuruat me hi pooch lena aur clear handle kar dena:
```cpp
if (k > nums.size()) {
    // Jo interviewer kahe, wo return karo (Empty ya poore array ka max)
    return {}; 
}

```



---

### 4. Large Negative Multi-Crossover

* **Situation:** `nums = [-7, -8, -7, -10, -5]`, $K = 3$
* **Trap:** Negative numbers me comparison logic (`-7 > -8`) aksar dimaag me confusion paida karta hai.
* **Deque Ka Khel:**
* Index 0 (`-7`) aaya $\rightarrow$ `[0]`
* Index 1 (`-8`) aaya $\rightarrow$ `-8 <= -7` true hai, toh bina pop kiye piche jud gaya $\rightarrow$ `[0, 1]`. Max = `-7`.
* Index 2 (`-7`) aaya $\rightarrow$ `-7 <= -8` false hai, toh index 1 (`-8`) pop ho jayega. Fir `-7 <= -7` true hai (duplicate handle), toh index 0 (`-7`) bhi pop ho jayega! Deque me sirf latest index aayega $\rightarrow$ `[2]`. Max = `-7`.


* **Result:** Strictly mathematical comparison hone ke kaaran negative math ekdum solid chalta hai. **(PASS ✅)**

---

### Ultimate Edge Case Matrix for Quick Review

| Edge Case Scenario | What Can Go Wrong? | Why Monotonic Deque Solves It? |
| --- | --- | --- |
| **Valley Pattern (`10 -> 5 -> 12`)** | Wrong element becomes front | In-between elements are evicted from the back, and old max is evicted from the front at the exact index expiration. |
| **Mountain Pattern (`2 -> 15 -> 1`)** | Peak might get lost early | Peak stays at `front` safely because incoming smaller elements are appended to the `back`. |
| **$K > N$** | Out of bounds / Crash | Code condition `i >= k - 1` naturally prevents processing, resulting in a safe empty vector. |
| **All Negative Arrays** | Sign conversion mismatch | The `<` and `>=` operators treat `-5 > -10` perfectly, keeping the relative monotonic order intact. |

Bhai, ab Sliding Window Maximum ka kissa poori tarah se khatam! Brute force, Heap, Deque, aur extreme edge cases ke saath tumhare paas absolute mastery hai is question par. Ab DSA ke agle padaav par chalein?


# Bit Flip


Bhai, yeh question dynamic array manipulation aur bitwise thinking ka ekdum solid mixture hai. Is sawal ka poora naam LeetCode par **"Minimum Number of K Consecutive Bit Flips"** hai.

Sawal simple lagta hai par iska index coordination dimaag ghuma deta hai. Chalo iska **Brute Force Approach** ekdum detail me, step-by-step tod kar samajhte hain.

---

## 1. Sawal Ka Asli Matlab Kya Hai?

Hume ek binary array `nums` diya hota hai (jisme sirf `0` aur `1` hote hain) aur ek integer `K` diya hota hai.
Hume array ke **saare elements ko `1` banana hai**.

Lekin twist ye hai ki hum akele ek single bit ko flip (0 ko 1, ya 1 ko 0) nahi kar sakte. Jab bhi hum flip karenge, hume **lagatar $K$ elements (consecutive window) ko ek saath flip** karna padega. Agar pure array ko `1` banana possible hai, toh minimum kitne flips lagenge wo batao, nahi toh `-1` return karo.

---

## 2. Brute Force Ka Main Logic: Greedy Simulation

Brute Force ka simple aur sasta logic **Greedy Approach** par chalta hai: *"Array me left se right travel karo. Jaise hi tumhe pehla `0` dikhe, use `1` banane ke liye us index se shuru hone wali poori $K$ size ki window ko pakad kar flip kar do!"*

### Hum aisa kyun kar rahe hain?

Kyunki agar hum left se right chal rahe hain aur index `i` par `0` hai, toh is `0` ko `1` banane ke liye hamare paas aur koi raasta nahi hai siwaye iske ki hum index `i` se shuru hone wali $K$-length ki window ko flip karein. Iske piche ke saare elements toh pehle se `1` ho chuke hain, toh unhe touch karne ka koi faayda nahi hai.

### Algorithm Steps:

1. Array ke shuruat (`i = 0`) se lekar aakhiri tak ek loop chalao.
2. Agar `nums[i] == 0` milta hai, toh iska matlab hume yahan ek flip operation lagana hi padega:
* **Check Bounds:** Pehle check karo ki kya index `i` se shuru karke $K$ elements aage tak bache bhi hain? (Yaani `i + K <= N`). Agar array khatam ho raha hai aur elements kam pad gaye, toh iska matlab is `0` ko kabhi `1` nahi banaya ja sakta $\rightarrow$ Direct return `-1`.
* **Flip Window:** Agar elements hain, toh ek **inner loop** chalao `j = i` se lekar `j < i + K` tak, aur un saare $K$ elements ko flip kar do (`0` ko `1`, aur `1` ko `0`).
* **Count Increment:** Apne `flipCount` variable ko `+1` kar do.


3. Agar loop bina kisi dikkat ke khatam ho jata hai, toh `flipCount` return kar do.

---

## 3. Brute Force C++ Code ($O(N \times K)$)

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlipsBrute(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;

        // Outer loop: Pure array par travel karega
        for (int i = 0; i < n; i++) {
            
            // Jaise hi pehla '0' dikhe, greedy hokar flip shuru karo
            if (nums[i] == 0) {
                
                // Edge Case Check: Agar index 'i' se K size ki window 
                // array ke bahar nikal rahi hai, toh flip karna impossible hai
                if (i + k > n) {
                    return -1; 
                }

                // Inner Loop: Current index 'i' se lekar agle K elements ko flip karo
                for (int j = i; j < i + k; j++) {
                    // Bit flip logic: 1 - 1 = 0, 1 - 0 = 1
                    nums[j] = 1 - nums[j]; 
                }

                // Ek valid flip operation poora hua
                flipCount++;
            }
        }

        return flipCount;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 0};
    int k = 4;

    Solution sol;
    int ans = sol.minKBitFlipsBrute(nums, k);

    cout << "Minimum Flips Required (Brute): " << ans << endl;
    // Output: 3
    return 0;
}

```

---

## 4. Detailed Dry-Run (Dimaag me bithaane ke liye)

Maan lo `nums = [0, 1, 0, 0, 1, 0]` aur `K = 4` ($N = 6$).

* **`i = 0`:** `nums[0] == 0` hai. Flip ki zaroorat hai!
* Bounds check: `0 + 4 <= 6` (True ✅, window valid hai).
* Index `0` se `3` tak ke elements flip ho jayenge.
* Array ab ban gaya: `[1, 0, 1, 1, 1, 0]`
* `flipCount = 1`


* **`i = 1`:** Array ab `[1, 0, 1, 1, 1, 0]` hai. `nums[1] == 0` hai. Fir flip karo!
* Bounds check: `1 + 4 <= 6` (True ✅, window valid hai).
* Index `1` se `4` tak ke elements flip ho jayenge.
* Array ab ban gaya: `[1, 1, 0, 0, 0, 0]`
* `flipCount = 2`


* **`i = 2`:** `nums[2] == 0` hai. Dobara flip karo!
* Bounds check: `2 + 4 <= 6` (True ✅, window valid hai).
* Index `2` se `5` tak ke elements flip ho jayenge.
* Array ab ban gaya: `[1, 1, 1, 1, 1, 1]`
* `flipCount = 3`


* **`i = 3, 4, 5`:** Saare elements ab `1` ho chuke hain, toh `if (nums[i] == 0)` kabhi chalega hi nahi.
* **Final Result:** Loop safely end hua aur `flipCount = 3` return ho gaya.

---

## 5. Complexity Analysis (Interviewer ka Reject Point)

* **Time Complexity: $O(N \times K)$** ❌
* **Kyun?** Outer loop $N$ baar chal raha hai, aur worst case me agar array me bohot saare zeroes hon, toh har baar inner loop strictly $K$ elements ko modify (flip) karega.
* Agar constraints badh jayein ($N = 10^5, K = 10^4$), toh total steps $10^9$ ho jayenge, jo strictly **TLE (Time Limit Exceeded)** de dega.


* **Space Complexity: $O(1)$ Auxiliary Space** 🔥
* **Kyun?** Humne koi extra data structure use nahi kiya, jo bhi alterations kiye wo direct original `nums` array ke andar hi modify kar diye.



---

## 6. Edge Cases Jo Brute Force Handle Karta Hai

1. **Window Size Array Ke Barabar ($K = N$):**
* Agar `nums = [0, 0, 0]`, $K = 3$. Pehle hi index `i = 0` par poora array ek baar me flip hoke `[1, 1, 1]` ban jayega. Baaki elements skip ho jayenge. Return `1`. **(PASS ✅)**


2. **Impossible Case (Out of Bounds Failure):**
* Maan lo `nums = [0, 1, 0]`, $K = 3$. Index `0` par poora array flip hoke `[1, 0, 1]` banega. Agla `0` index `1` par milega. Lekin ab `1 + 3 = 4 > 3`, window out of bounds ho gayi! Code turant `-1` return kar dega. **(PASS ✅)**



Bhai, brute force ka ye poora greedy logic aur loop breakdown ekdum detail me dimaag me set hua? Ab iska optimal tarika dekhna hai jahan hum bina elements ko bar-bar modify kiye **$O(N)$ Time** me khel khatam karte hain?



Bhai, Brute Force me sabse badi bwaal kya thi? Jab hum kisi index par flip karte the, toh hum agle $K$ elements par jaakar unki values ko physically change karte the (`0` ko `1` aur `1` ko `0`). Is wajah se time complexity $O(N \times K)$ ja rahi thi.

**Better Approach (Optimized Sliding Window / Sweep Line Concept)** ka main aim hai: *"Hum elements ko physically array me touch bhi nahi karenge, lekin pointer math aur ek single active flip variable se hume kisi bhi element par khade hokar pata chal jayega ki uska current status (0 ya 1) kya hai!"*

Chalo iska poora maths aur logic ekdum deep detail me samajhte hain.

---

## 1. Better Logic: Concept of "Flip State"

Bhai, ek simple bitwise property samajho:

* Agar kisi bit ko tum **Even times (0, 2, 4...)** flip karoge, toh uski value **same** rahegi.
* Agar kisi bit ko tum **Odd times (1, 3, 5...)** flip karoge, toh uski value **invert (flip)** ho jayegi.

Isliye, jab hum array me left se right travel kar rahe hain, toh hume poori window ko badalne ki zaroorat nahi hai. Hum bas ye track rakhenge ki **"Abhi hum jis element par khade hain, us par piche ki windows ki wajah se total kitne active flips chal rahe hain."**

### Do Main Pointers / Variables:

1. **`activeFlips` (Integer):** Yeh track rakhta hai ki current index par piche se kitne flips ka asar chal raha hai.
2. **`isFlipped` Vector/Array (Size $N$):** Yeh track rakhta hai ki kya humne kisi particular index par ek naya flip operation shuru kiya tha? (`isFlipped[i] = 1` agar index `i` par flip kiya hai, nahi toh `0`).

### Khel Kaise Chalega?

* **Step 1 (Window Expiry Check):** Jaise hi hum kisi index `i` par pahunche, hum dekhenge ki kya koi purani window ab khatam ho chuki hai? Agar `i >= K` hai, toh index `i - K` par jo window shuru hui thi, uska asar ab khatam ho gaya. Toh agar `isFlipped[i - K] == 1` tha, toh hum apne `activeFlips` me se `-1` kar denge.
* **Step 2 (Current State Nikalna):** Ab hum bina array ko change kiye current element ka asli roop nikalenge:
* Agar `activeFlips` **Even** hai, toh `nums[i]` jaisa hai waisa hi rahega.
* Agar `activeFlips` **Odd** hai, toh `nums[i]` flip ho chuka hoga (`1 - nums[i]`).


* **Step 3 (Greedy Flip Decision):** Agar evaluate karne ke baad pata chala ki current element abhi bhi `0` hai, toh hume yahan ek naya flip shuru karna padega:
* Bounds check karo (`i + K > n`). Agar jagah nahi hai, toh return `-1`.
* Naya flip shuru hua, toh `isFlipped[i] = 1` set karo, `activeFlips++` karo, aur `totalFlips++` karo.



---

## 2. Better C++ Code ($O(N)$ Time, $O(N)$ Space)

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlipsBetter(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Yeh array track karega ki kis index par naya flip lagaya gaya tha
        vector<int> isFlipped(n, 0); 
        
        int activeFlips = 0; // Current index par chal rahe valid flips ka count
        int totalFlips = 0;  // Total kitne flips kiye uska answer

        for (int i = 0; i < n; i++) {
            
            // 1. Window Expiry: Agar purani window (jo i-k par shuru hui thi) 
            // ki range se hum baahar aa gaye hain, toh uska asar khatam karo
            if (i >= k) {
                if (isFlipped[i - k] == 1) {
                    activeFlips--; // Active flip ka asar khatam
                }
            }

            // 2. State Evaluation: Piche ke active flips ke basis par 
            // check karo ki nums[i] ka current roop kya hai.
            // Agar activeFlips odd hain aur nums[i] 1 hai -> toh wo actually 0 ban chuka hai.
            // Agar activeFlips even hain aur nums[i] 0 hai -> toh wo abhi bhi 0 hi hai.
            if ((activeFlips % 2 == 0 && nums[i] == 0) || (activeFlips % 2 != 0 && nums[i] == 1)) {
                
                // Edge Case: Flip lagane ke liye aage K elements bache hone chahiye
                if (i + k > n) {
                    return -1;
                }

                // Naya flip apply karo
                isFlipped[i] = 1;
                activeFlips++;
                totalFlips++;
            }
        }

        return totalFlips;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 0};
    int k = 4;

    Solution sol;
    int ans = sol.minKBitFlipsBetter(nums, k);

    cout << "Minimum Flips Required (Better): " << ans << endl; // Output: 3
    return 0;
}

```

---

## 3. Detailed Dry-Run (Dimaag ka dahi khatam karne ke liye)

Maan lo `nums = [0, 1, 0, 0, 1, 0]`, `K = 4`. `isFlipped = [0, 0, 0, 0, 0, 0]`.

* **`i = 0` (Element `0`):** `i < k` hai (no expiry). `activeFlips = 0` (Even). `nums[0] == 0` hai.
* Condition hit! Flip zaroori hai.
* `isFlipped[0] = 1`, `activeFlips = 1`, `totalFlips = 1`.


* **`i = 1` (Element `1`):** No expiry. `activeFlips = 1` (Odd).
* Evaluate: `nums[1]` originally `1` hai, par chunki active flip `1` (odd) chal raha hai, toh iska roop badal kar ab `0` ho chuka hai!
* Condition hit! Flip zaroori hai.
* `isFlipped[1] = 1`, `activeFlips = 2`, `totalFlips = 2`.


* **`i = 2` (Element `0`):** No expiry. `activeFlips = 2` (Even).
* Evaluate: `activeFlips` even hai, toh `nums[2]` ka roop unchanged `0` hi hai.
* Condition hit! Flip zaroori hai.
* `isFlipped[2] = 1`, `activeFlips = 3`, `totalFlips = 3`.


* **`i = 3` (Element `0`):** No expiry. `activeFlips = 3` (Odd).
* Evaluate: Originally `0` hai, par active flip odd (3) hai, toh ye flip hokar `1` ban chuka hai! No flip needed.


* **`i = 4` (Element `1`):** `i >= k` yaani `4 >= 4` true! **Expiry Time!**
* Check `isFlipped[4 - 4] = isFlipped[0] == 1`. Haan, index 0 wali window expire ho gayi!
* `activeFlips` घटकर `3 - 1 = 2` ho gaya.
* Evaluate: `activeFlips = 2` (Even). `nums[4]` originally `1` hai. Even flips matlab unchanged `1`. No flip needed.


* **`i = 5` (Element `0`):** **Expiry Time!** `isFlipped[5 - 4] = isFlipped[1] == 1`. Index 1 wali window expire!
* `activeFlips` घटकर `2 - 1 = 1` ho gaya.
* Evaluate: `activeFlips = 1` (Odd). `nums[5]` originally `0` hai, odd flip se badal kar `1` ho gaya! No flip needed.



Final `totalFlips = 3`. Ekdum bina array ko chue $O(N)$ me kaam ho gaya!

---

## 4. Complexity Analysis

* **Time Complexity: $O(N)$** 🔥🔥🔥
* **Kyun?** Kyunki andar ka jo physical flipping loop tha ($K$ size ka), wo poori tarah se uda diya gaya hai. Hum array par sirf ek baar linear travel kar rahe hain aur saare operations (expiry check, evaluation) $O(1)$ constant time me ho rahe hain.


* **Space Complexity: $O(N)$** ⚠️
* **Kyun?** Kyunki humne $N$ size ka ek extra `isFlipped` vector maintain kiya hai ye track karne ke liye ki kis-kis state par naye flips lagaye gae the.



---

## 5. Interviewer Ka Agla Trap (The Ultimate Leap to Optimal)

Interviewer khush ho jayega ki tumne $O(N \times K)$ se sidha lineally **$O(N)$** me code la diya. Par wo select karne se pehle akhiri punch marega:

*"Bhai, Time toh mast $O(N)$ kar diya, par tumne jo ye $O(N)$ ka `isFlipped` array banaya hai, mujhe ye extra space bhi nahi chahiye. Kya tum original array ko hi modify karke ya bina kisi extra array ke isko **$O(1)$ Space** me la sakte ho?"*

Bhai, is $O(N)$ wale logic me thoda sa bit-manipulation aur inplace encoding lagate hi yeh $O(1)$ Space ka master code ban jata hai. Kya uska logic aur code todkar bataun?




Bhai, ab aate hain is question ke sabse dhasu aur interview-clearing **Absolute Optimal Approach** par!

Pichli (Better) approach me tumne Time Complexity toh $O(N)$ kar di thi, par interviewer ne tumhe space par tok diya tha ki *"Mujhe $O(N)$ ka `isFlipped` array nahi chahiye, isko $O(1)$ Auxiliary Space me karke dikhao."*

Optimal approach ka core secret hai: **In-place State Encoding (Original array ke data ko hi as a marker use karna)**. Hum original array ke elements ko temporary change karke bina kisi extra space ke track rakh lenge ki kahan flip shuru hua tha.

---

## 1. Optimal Logic: In-place Array Modification

Better approach me hum `isFlipped[i] = 1` mark kar rahe the. Optimal approach me hum kya karenge? Jab hume kisi index `i` par flip karna hoga, toh hum original array ke usi element ko out of bound values (jaise **`2`** ya koi flag value) me badal denge!

### Khel Kaise Chalega?

Hum `activeFlips` aur `totalFlips` waala logic bilkul same rakhenge, bas `isFlipped[i - K]` ki checking badal jayegi:

1. **Window Expiry Check:** Jab `i >= K` hoga, toh hum check karenge ki kya index `i - K` par jo element hai, wo **`2`** ho chuka hai? Agar `nums[i - K] == 2` hai, iska matlab wahan ek flip shuru hua hai jo ab expire ho raha hai. Toh hum `activeFlips--` kar denge aur us element ko wapas normal kar sakte hain (ya chhod bhi sakte hain).
2. **Greedy Flip Decision:** Agar evaluation ke baad pata chala ki current element `nums[i]` abhi bhi `0` hai, aur aage space valid hai (`i + K <= n`), toh hum naya flip lagayenge:
* Hum `activeFlips++` karenge.
* `totalFlips++` karenge.
* Aur bina kisi extra space ke, original array me hi mark kar denge: **`nums[i] = 2`** (Yeh `2` hume piche se bacha ke batayega ki yahan flip hua tha).



---

## 2. No-Space Optimal C++ Code ($O(N)$ Time, $O(1)$ Space)

Interview me jab interviewer space par ban lagaye, toh ye clean code unke saamne rakhna:

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlipsOptimal(vector<int>& nums, int k) {
        int n = nums.size();
        int activeFlips = 0; 
        int totalFlips = 0;  

        for (int i = 0; i < n; i++) {
            
            // 1. Window Expiry: Agar purani window ki range se bahar aa gaye hain
            // Hum check karenge ki kya nums[i - k] par humne '2' mark kiya tha?
            if (i >= k) {
                if (nums[i - k] == 2) {
                    activeFlips--; // Us window ka asar ab khatam
                }
            }

            // 2. State Evaluation: Check karo current element activeFlips ke baad kya bana
            // Same logic: even flips par same roop, odd flips par inverted roop
            if ((activeFlips % 2 == 0 && nums[i] == 0) || (activeFlips % 2 != 0 && nums[i] == 1)) {
                
                // Edge Case Check: Agar aage K elements bache hi nahi hain
                if (i + k > n) {
                    return -1;
                }

                // 3. In-place Encoding: Extra space ke bajay original element ko '2' bana do
                nums[i] = 2; 
                activeFlips++;
                totalFlips++;
            }
        }

        return totalFlips;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 0, 1, 0};
    int k = 4;

    Solution sol;
    int ans = sol.minKBitFlipsOptimal(nums, k);

    cout << "Minimum Flips Required (Optimal): " << ans << endl; // Output: 3
    return 0;
}

```

---

## 3. Complexity Analysis (Asali Maal)

* **Time Complexity: $O(N)$** 🔥
* **Kyun?** Humne array par strictly **ek single pass** kiya hai. Na koi nested loop hai, na koi elements ko aage jaakar physically baar-baar palatne ka cost hai. Saare operations $O(1)$ constant time me nipta diye gaye hain.


* **Space Complexity: $O(1)$ Auxiliary Space** 🔥🔥🔥
* **Kyun?** Dhyan se dekho code ko! Humne koi extra vector ya map nahi banaya. Jo marking hum pehle extra array me kar rahe the (`isFlipped[i] = 1`), wahi marking ab hum direct memory optimize karke input array ke hi element ko change karke kar rahe hain (`nums[i] = 2`).



---

## 4. Boundary aur Edge Cases Verification

1. **Window Size Exactly Array Ke Barabar ($K = N$):**
* Maan lo `nums = [0, 0, 0]`, $K = 3$. Pehle index `i = 0` par `activeFlips = 0`, `nums[0] == 0`. Condition hit karegi!
* `nums[0]` ban jayega `2`. `activeFlips = 1`, `totalFlips = 1`.
* Agle indices `i = 1` aur `i = 2` par `activeFlips = 1` (Odd) chal raha hai, toh original `0` ab `1` ban chuke hain, isliye loops direct bypass ho jayenge safely. Output: `1`. **(PASS ✅)**


2. **Impossible Scenario (Khatam Hote Elements):**
* Maan lo `nums = [0, 1, 0]`, $K = 3$. Index `0` par check perfect chalega aur use `2` bana dega. `activeFlips = 1`.
* Index `1` par original `1` ab active flip (1) ki vajah se `0` dikhega. Condition hit karegi.
* Par check hoga `i + k > n` yaani `1 + 3 > 3` (True!). Code turant bina kisi error ke `-1` return kar dega. **(PASS ✅)**


3. **Saare Elements Pehle Se `1` Hon (`[1, 1, 1]`, $K=2$):**
* Loop line se chalega. Kisi bhi index par condition hit nahi hogi kyunki `activeFlips` hamesha `0` (Even) rahega aur elements `1` hain. Total flips `0` safely return ho jayenge. **(PASS ✅)**



Bhai, ab Is Question ke teeno models: Brute ($O(N \times K)$), Better ($O(N)$ Space), aur Optimal ($O(1)$ Space) ekdum dhasu tarike se clear hain? Interviewer ko in-place encoding ka jalwa samjha doge ab?


Bhai, is **In-place Optimal ($O(1)$ Space)** approach par interviewer jab extreme edge cases phenkta hai, toh wo ye dekhta hai ki tumhara pointer math aur array modifications boundary conditions par crash toh nahi kar rahe.

Chalo is optimal code ke **saare micro-level edge cases** ka poora breakdown dekhte hain taaki tumhara logic bulletproof ho jaye:

---

## 1. Impossible Core Boundaries (Jab String ya Array Short Padh Jaye)

**Situation:** `nums = [0, 0, 1, 0, 0]`, $K = 4$
**Trap:** Isme aakhiri me `0` bacha reh jayega jise flip karne ke liye aage $K$ elements bache hi nahi honge.

**Dry Run:**

* `i = 0`: `nums[0] == 0`, `activeFlips = 0`. Condition hit hui $\rightarrow$ `nums[0] = 2`, `activeFlips = 1`.
* `i = 1`: `nums[1] == 0`, par `activeFlips = 1` (Odd) hai, toh ye mentally `1` ban chuka hai. Skip ❌.
* `i = 2`: `nums[2] == 1`, `activeFlips = 1` (Odd) hai, toh ye mentally `0` ban chuka hai.
* Check hoga: `i + k > n` $\rightarrow$ `2 + 4 > 5` ($6 > 5$ is True!).
* Code aage badhne se pehle hi turant **`-1`** return kar dega bina kisi out-of-bounds index execution ke. (PASS ✅)



---

## 2. Window Size Exactly Array Size Ke Barabar ($K = N$)

**Situation:** `nums = [0, 0, 0]`, $K = 3$ ($N = 3$)

**Dry Run:**

* **`i = 0`:** `nums[0] == 0`, `activeFlips = 0`. Condition hit! `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.
* **`i = 1`:** `activeFlips = 1` (Odd). `nums[1]` originally `0` hai, toh odd flip se ye `1` ban gaya. Skip ❌.
* **`i = 2`:** `activeFlips = 1` (Odd). `nums[2]` originally `0` hai, odd flip se ye bhi `1` ban gaya. Skip ❌.
* **Result:** Loop bina kisi boundary conflict ke safely khatam hua aur `totalFlips = 1` return ho gaya. (PASS ✅)

---

## 3. Window Size Exactly 1 ($K = 1$) — Dynamic Reset Check

**Situation:** `nums = [0, 1, 0]`, $K = 1$
**Trap:** Har single element khud me ek alag window hai, toh har ek agle index par piche wali window ka expiry check (`i >= k`) hit hoga.

**Dry Run:**

* **`i = 0`:** `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.
* **`i = 1`:** Expiry check active hua (`1 >= 1`). `nums[1 - 1] == nums[0] == 2` hai, toh `activeFlips` घटकर `0` ho gaya!
* Ab `activeFlips = 0`. `nums[1] == 1` hai, toh no flip needed. Skip ❌.


* **`i = 2`:** Expiry check active (`2 >= 1`). `nums[2 - 1] == nums[1] == 1` (not 2), toh activeFlips unchanged (`0`) raha.
* `nums[2] == 0` hai. Condition hit! `nums[2] = 2`, `activeFlips = 1`, `totalFlips = 2`.


* **Result:** Har step par perfectly binary states coordinate hui aur answer `2` aaya. (PASS ✅)

---

## 4. Alternate Repeating Zeroes Aur Onnes (`[0, 1, 0, 1]`, $K=2$)

**Situation:** Continuous alternate values chal rahi hain.

**Dry Run:**

* `i = 0`: `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.
* `i = 1`: `activeFlips = 1`. `nums[1]` originally `1` hai, odd flip se `0` bana. Condition hit!
* `nums[1] = 2`, `activeFlips = 2`, `totalFlips = 2`.


* `i = 2`: Expiry time (`2 >= 2`). `nums[2 - 2] == nums[0] == 2` hai $\rightarrow$ `activeFlips` घटकर `1` hua.
* Live state: `activeFlips = 1`. `nums[2]` originally `0` hai, odd flip se `1` bana. Skip ❌.


* `i = 3`: Expiry time (`3 >= 2`). `nums[3 - 2] == nums[1] == 2` hai $\rightarrow$ `activeFlips` घटकर `0` hua.
* Live state: `activeFlips = 0`. `nums[3]` originally `1` hai. Skip ❌.


* **Result:** State encoding (`2`) ne purane elements ke flip details ko live sequence me overlap hone se perfectly bacha liya. (PASS ✅)

---

## 5. Pure Elements Array (No Flips Needed)

**Situation:** `nums = [1, 1, 1]`, $K = 2$

* `activeFlips` hamesha `0` rahega.
* `if` condition kabhi true nahi hogi kyuki har element `1` dikhega aur even flips (`0`) par state change nahi hoti.
* `totalFlips = 0` safely return ho jayega bina kisi computational wastage ke. (PASS ✅)

---

## Interview Cheat-Sheet: K-Bit Flips Edge Cases Verification

| Edge Case Scenario | Potential Danger | Why In-place Optimal Logic Wins? | Result |
| --- | --- | --- | --- |
| **$K > N$ (Large Window)** | Segmentation Fault | The check `i + k > n` drops execution cleanly on day one. | **`-1` Safely** |
| **$K = 1$ (Micro Window)** | Expiry Overlap | Every single loop step correctly checks `i - 1` index flag to instantly drop the active state. | **PASS ✅** |
| **Alternate Patterns** | Lost Flip Counts | The value `2` uniquely tags only the exact initiation indexes, keeping the count mathematically pure. | **PASS ✅** |
| **All Ones (`[1, 1, 1]`)** | Unnecessary Flips | Loop acts as a direct passive scanner; complexity remains strictly linear $O(N)$ with zero state write overhead. | **`0` Flips** |

Bhai, ab Is Blockbuster Problem ke saare brute, better, optimal models aur unke micro-level edge cases tumhare dimaag me crystalline format me store ho chuke hain!

Ab Sliding Window aur Deque/Queue Base Systems ka koi bhi doubt bacha hai ya hum agle fresh DSA pattern par kooden?



Bhai, LeetCode ke is **"Minimum Number of K Consecutive Bit Flips"** problem me interviewer hamesha in **charo specific edge cases** ko dhyan se check karta hai taaki tumhare logic ki boundaries test ho sakein.

Chalo hamare in-place optimal code (`nums[i] = 2` waale logic) ke upar in charo cases ka ek-ek karke poora deep detail dry-run dekhte hain, taaki tum interview me board par ekdum makkhan tarike se trace karke dikha sako!

---

## Case 1: Window Size Exactly Array Size Ke Barabar ($K = N$)

**Situation:** `nums = [0, 0, 0]` aur $K = 3$ ($N = 3$).
**Interviewer Point:** Wo dekhna chahta hai ki kya poora array ek hi jhatke me flip ho raha hai aur aage ke elements safely bypass ho rahe hain ya nahi.

### Step-by-Step Trace:

* **`i = 0`:** * Expiry Check: `0 >= 3` (False). No expiry.
* State Evaluate: `activeFlips = 0` (Even), `nums[0] == 0`. Condition sahi baithi!
* Bounds Check: `0 + 3 > 3` ($3 > 3$ is False). Space ekdum perfect hai.
* **Action:** `nums[0] = 2`, `activeFlips` badhkar `1` hua, `totalFlips = 1`.


* **`i = 1`:** * Expiry Check: `1 >= 3` (False).
* State Evaluate: `activeFlips = 1` (Odd). `nums[1]` originally `0` tha, par odd flips ki vajah se mentally ye ab `1` ban chuka hai!
* **Action:** Condition fail (`nums[1]` mentally `1` hai), toh loop bina kuch kiye seedha skip ho gaya ❌.


* **`i = 2`:** * Expiry Check: `2 >= 3` (False).
* State Evaluate: `activeFlips = 1` (Odd). `nums[2]` originally `0` tha, odd flip ki vajah se ye bhi mentally `1` ban gaya.
* **Action:** Loop bypass ❌.


* **Final Result:** Loop khatam. `totalFlips = 1` safely return hua. Poora array ek hi flip me wrap up! (PASS ✅)

---

## Case 2: Window Size Exactly 1 ($K = 1$) — Dynamic Reset Check

**Situation:** `nums = [0, 1, 0]` aur $K = 1$ ($N = 3$).
**Interviewer Point:** Jab $K = 1$ hota hai, toh har ek single index apni khud ki window hota hai. Iska matlab har agle step par piche wale element ka asar turant khatam (expire) hona chahiye.

### Step-by-Step Trace:

* **`i = 0`:**
* Expiry Check: `0 >= 1` (False).
* State Evaluate: `activeFlips = 0` (Even), `nums[0] == 0`. Condition Hit!
* Bounds Check: `0 + 1 > 3` (False).
* **Action:** `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.


* **`i = 1`:**
* Expiry Check: `1 >= 1` (True!). Hum check karenge `nums[i - k] == nums[1 - 1] == nums[0]`. Chunki `nums[0] == 2` hai, iska matlab index 0 par flip shuru hua tha jo ab expire ho raha hai.
* **Expiry Action:** `activeFlips` ghat kar `1 - 1 = 0` ho gaya!
* State Evaluate: Now `activeFlips = 0` (Even). `nums[1]` originally `1` hai. Even flips par status unchanged rehta hai, yaani ye `1` hi hai.
* **Action:** No flip needed, loop skip ❌.


* **`i = 2`:**
* Expiry Check: `2 >= 1` (True!). Check `nums[2 - 1] == nums[1]`. `nums[1]` ki value `1` hai (2 nahi hai), iska matlab index 1 par koi flip shuru nahi hua tha, toh kuch expire nahi hoga. `activeFlips` remains `0`.
* State Evaluate: `activeFlips = 0` (Even), `nums[2] == 0`. Condition Hit!
* Bounds Check: `2 + 1 > 3` (False).
* **Action:** `nums[2] = 2`, `activeFlips = 1`, `totalFlips = 2`.


* **Final Result:** Code safely array scan karke `totalFlips = 2` return karega. (PASS ✅)

---

## Case 3: Alternating Repeating Patterns (`[0, 1, 0, 1]`)

**Situation:** `nums = [0, 1, 0, 1]` aur $K = 2$ ($N = 4$).
**Interviewer Point:** Wo dekhna chahta hai ki continuous alternations me kya `activeFlips` ka addition aur subtraction aapas me synchronize ho pa raha hai.

### Step-by-Step Trace:

* **`i = 0`:** No expiry. `activeFlips = 0`. `nums[0] == 0`. Hit!
* **Action:** `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.


* **`i = 1`:** No expiry (`1 >= 2` False).
* State Evaluate: `activeFlips = 1` (Odd). `nums[1]` originally `1` hai, odd flip ki vajah se ye mentally `0` ban chuka hai!
* **Action:** Chunki mentally `0` ban gaya, toh yahan bhi flip marna padega! `nums[1] = 2`, `activeFlips` badhkar `1 + 1 = 2` hua, `totalFlips = 2`.


* **`i = 2`:** Expiry time! `2 >= 2` (True).
* Check `nums[2 - 2] == nums[0] == 2`. Haan bhai, index 0 wali window expire ho gayi!
* **Expiry Action:** `activeFlips` ghat kar `2 - 1 = 1` ho gaya.
* State Evaluate: Now `activeFlips = 1` (Odd). `nums[2]` originally `0` hai, odd flip ki vajah se mentally ye `1` ban chuka hai! No flip needed. Skip ❌.


* **`i = 3`:** Expiry time! `3 >= 2` (True).
* Check `nums[3 - 2] == nums[1] == 2`. Haan, index 1 wali window bhi expire ho gayi!
* **Expiry Action:** `activeFlips` ghat kar `1 - 1 = 0` ho gaya.
* State Evaluate: `activeFlips = 0` (Even). `nums[3]` originally `1` hai. Even flip matlab unchanged `1`. No flip needed. Skip ❌.


* **Final Result:** Perfect tracking ke sath `totalFlips = 2` return ho jayega. (PASS ✅)

---

## Case 4: Impossible Core Boundaries (Jab Array Short Padh Jaye)

**Situation:** `nums = [0, 0, 1, 0, 0]` aur $K = 4$ ($N = 5$).
**Interviewer Point:** Yeh sabse bada catch hai. Code aakhiri un-flippable zeroes par crash hone ke bajay safely `-1` de raha hai ya nahi.

### Step-by-Step Trace:

* **`i = 0`:** `activeFlips = 0`, `nums[0] == 0`. Hit!
* **Action:** `nums[0] = 2`, `activeFlips = 1`, `totalFlips = 1`.


* **`i = 1`:** `activeFlips = 1` (Odd). `nums[1]` originally `0` hai $\rightarrow$ mentally `1` ban gaya. Skip ❌.
* **`i = 2`:** `activeFlips = 1` (Odd). `nums[2]` originally `1` hai $\rightarrow$ mentally `0` ban gaya.
* **The Trap Active:** Chunki ye mentally `0` hai, code flip karne ki koshish karega.
* **Bounds Check:** `i + k > n` $\rightarrow$ `2 + 4 > 5` ($6 > 5$ is **True**!).
* **Action:** Code samajh jayega ki aage window phelane ke liye jagah hi nahi bachi hai. Wo loop ko aage chalne hi nahi dega aur yahin se direct **`-1`** phenk kar bahar nikal jayega!


* **Final Result:** Safely returned `-1` bina kisi segmentation fault ya array indexing out of bound error ke. (PASS ✅)

---

### Charo Cases Ki Quick Summary Sheet

| Case | Core Target | Logic Outcome | Safety Driver |
| --- | --- | --- | --- |
| **Case 1 ($K = N$)** | Single stroke whole array flip | First index sets state to `2`, rest elements auto-bypass. | Strictly `1` Flip |
| **Case 2 ($K = 1$)** | Immediate continuous eviction | Next step checks `i - 1` index, drops active flip count instantly. | Exact Individual Flips |
| **Case 3 (Alternate)** | Overlapping flip calculations | State encoding `2` perfectly separates active cascades. | Balanced Tracking |
| **Case 4 (Short Array)** | Out of Bound protection | `i + k > n` catches the constraint failure before writing memory. | **`-1` Safely** |

Bhai, ab yeh charo extreme cases poore index mapping aur mathematical trace ke saath dimaag me lock ho gaye? Interviewer ab inme se koi bhi pattern white-board par dega, toh ek-ek pointer trace karke dhasu impact bana doge!


