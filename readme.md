Arre bhai, tension mat le! Ye question bohot simple hai, bas thoda dhyan se samajhna hai. Log aksar isme confuse ho jate hain, par ek baar concept pakad liya na, toh minto ka kaam hai.

Chalo, sabse pehle samajhte hain ki **question aakhir bol kya raha hai**.

---

## 1. Question Kya Bol Raha Hai? (The Problem Statement)

Simple shabdon me: Tumhe ek numbers ki list (yaani ek **Array**) di jayegi. Us array me kuch numbers Even (sam / jo 2 se divide ho jayein) honge aur kuch Odd (visham / jo 2 se divide na honge).

Tumhara kaam hai us array ke numbers ko is tarah rearrange (aage-piche) karna ki:

* Saare **Even numbers** array ke **shuruat (front)** me aa jayein.
* Saare **Odd numbers** array ke **aakhiri (end)** me chale jayein.

> **Sabse Zaruri Baat:** Numbers ka aapas me order kya hai (jaise pehle 4 aana chahiye ya 2), wo zyadaatar questions me maayne nahi rakhta. Bas Even pehle aur Odd baad me hone chahiye.

### Ek Example Se Samjho:

Maan lo tumhe ye array mila:
`[3, 8, 5, 2, 9, 4, 7]`

Hame ise aise badalna hai ki Even shuru me aur Odd baad me hon.

* **Even numbers kaunse hain?** `8, 2, 4`
* **Odd numbers kaunse hain?** `3, 5, 9, 7`

Toh tumhara final output kuch aisa dikhna chahiye:
`[8, 2, 4, 3, 5, 9, 7]` (Sare evens left me, sare odds right me!)

---

## 2. Isko C++ Me Kaise Karenge? (The Logic)

Isko karne ke do-teen tarike hain, par sabse best aur efficient tarika hai **"Two-Pointer Approach"**. Isme hum alag se koi naya array nahi banate, balki usi array me numbers ko aapas me swap (adla-badli) karte hain.

### Dimaag Me Socho:

Hum do pointer (yaani do variables/indexes) lenge:

1. `left`: Jo array ke shuruat `0` par khada hoga. Iska kaam hai Even numbers ko dhoodna.
2. `right`: Jo array ke aakhiri index `n-1` par khada hoga. Iska kaam hai Odd numbers ko dhoodna.

Hum loop chalayenge jab tak `left` aur `right` ek dusre ko cross nahi kar lete (`left < right`).

* **Case 1:** Agar `left` par khada number **Even** hai, toh wo apni sahi jagah par hai. Hum `left++` karke aage badh jayenge.
* **Case 2:** Agar `right` par khada number **Odd** hai, toh wo bhi apni sahi jagah par hai. Hum `right--` karke piche badh jayenge.
* **Case 3:** Agar `left` par **Odd** khada hai (galat jagah) aur `right` par **Even** khada hai (galat jagah), toh hum in dono ko **swap** kar denge! Phir `left++` aur `right--` kar denge.

---

## 3. C++ Code Dry Run Ke Saath

Chalo ab iska neat aur clean code dekhte hain:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void separateEvenOdd(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Agar left wala even hai, toh aage badho
        if (arr[left] % 2 == 0) {
            left++;
        }
        // Agar right wala odd hai, toh piche badho
        else if (arr[right] % 2 != 0) {
            right--;
        }
        // Agar left par odd aur right par even hai, toh swap karo
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {3, 8, 5, 2, 9, 4, 7};

    cout << "Pehle wala Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    separateEvenOdd(arr);

    cout << "Separate karne ke baad: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

```

### Dry Run (Ye andar kaam kaise kar raha hai):

Hamara array hai: `[3, 8, 5, 2, 9, 4, 7]`

* Shuru me: `left = 0` (value `3`), `right = 6` (value `7`)
* `3` odd hai aur `7` bhi odd hai. Code check karega: `arr[right] % 2 != 0` (7 odd hai), toh `right--` ho jayega. Ab `right` aa gaya `4` par.
* Naya state: `left` par `3` (odd), `right` par `4` (even). Dono galat jagah hain! **Swap** ho jayenge.
* Array ban gaya: `[4, 8, 5, 2, 9, 3, 7]`. `left` badh ke `1` par gaya, `right` kam ho ke `5` par gaya.

Aise hi karte-karte saare evens left me khisak jayenge aur odds right me! Is approach ki sabse achhi baat ye hai ki iski time complexity **$O(N)$** hai (matlab loop sirf ek baar poore array par chalta hai) aur space complexity **$O(1)$** hai (koi extra memory nahi use hui).


Arre bilkul bhai, brute force approach bhi pata hona bohot zaruri hai. Inteview me hamesha pehle brute force hi bataya jata hai, uske baad optimization par aate hain.

Brute force ka seedha matlab hai: **"Jo dimaag me sabse pehle sabse aasan tarika aaye, bina efficiency ki chinta kiye."**

---

## Brute Force Approach: Ek Naya Ghar (Extra Space)

Iska sabse simple tarika ye hai ki hum ek **naya khali array (ya vector)** bana lein. Phir purane array me do chakkar (loops) lagayein:

1. **Pehle loop me:** Saare **Even** numbers ko dhoodh kar naye array me daal dein.
2. **Doosre loop me:** Saare **Odd** numbers ko dhoodh kar naye array ke bache hue hisse me daal dein.
3. Aakhiri me, naye array ke elements ko wapas purane array me copy kar dein.

### Iska Fayda Aur Nuksan:

* **Fayda:** Isme numbers ka **original relative order** maintain rehta hai (jaise agar pehle 8 tha phir 2, toh naye array me bhi pehle 8 phir 2 hi rahega). Isko "Stable Sorting" jaisa bol sakte hain.
* **Nuksan:** Hame ek naya array banana pad raha hai, toh hamari memory (Space Complexity) badh jayegi.

---

## C++ Code (Brute Force)

Chalo iska code dekh lete hain, ye samajhne me bohot halwa hai:

```cpp
#include <iostream>
#include <vector>
using namespace std;

void separateEvenOddBruteForce(vector<int>& arr) {
    vector<int> temp; // Ek naya temporary array banaya

    // Step 1: Pehle saare EVEN numbers ko temp me daalo
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            temp.push_back(arr[i]);
        }
    }

    // Step 2: Phir saare ODD numbers ko temp me daalo
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 != 0) {
            temp.push_back(arr[i]);
        }
    }

    // Step 3: Temp array ke data ko wapas asli arr me copy kar do
    arr = temp;
}

int main() {
    vector<int> arr = {3, 8, 5, 2, 9, 4, 7};

    separateEvenOddBruteForce(arr);

    cout << "Brute Force ke baad: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

```

---

## Complexity Analysis (Dono me farq kya hai?)

Ab tum interview me kaise bologe? Dono approaches ko compare karke dikhao:

| Criteria | Brute Force Approach | Two-Pointer Approach (Jo pehle seekha) |
| --- | --- | --- |
| **Time Complexity** | **$O(N)$** (Kyuki hum array par do-teen baar loop chala rahe hain, par loop alag-alag hain toh linear hi rahega) | **$O(N)$** (Ek hi baar me dono taraf se scan ho jata hai) |
| **Space Complexity** | **$O(N)$** ❌ (Kyuki hume ek naya `temp` vector banana pada jitna bada asli array tha) | **$O(1)$** (Koi extra space nahi chahiye, usi array me swap ho gaya) |
| **Order of Elements** | Original order same rehta hai (Stable) | Order badal jata hai (Unstable) |

Bhai, brute force samajh agaya ya isme koi doubt hai?


Bhai, brute force ke baad ab aate hain asli hero par—**Optimal Approach**.

Interview me jab tum brute force bata doge, toh interviewer bolega: *"Space $O(N)$ use nahi karni, bina kisi naye array ke $O(1)$ space me karke dikhao."* Wahan kaam aati hai **Two-Pointer Approach**, jise hum optimal approach kehte hain. Isme hum bina kisi extra space ke, sirf elements ko aapas me adla-badli (swap) karke poora kaam linear time me khatam kar dete hain.

---

## 1. Optimal Logic Kaise Kaam Karta Hai?

Hum do pointers lenge: `left` (jo array ke shuru me hoga, `0` index par) aur `right` (jo array ke aakhiri me hoga, `n-1` index par).

* **Left pointer** ka kaam hai: Shuruat se aage badhna aur **Odd number** ko dhoodhna (kyuki left me sirf even hone chahiye, odd dikha matlab wo galat jagah hai).
* **Right pointer** ka kaam hai: Aakhiri se piche aana aur **Even number** ko dhoodhna (kyuki right me sirf odd hone chahiye, even dikha matlab wo galat jagah hai).

Hum tab tak loop chalayenge jab tak `left < right` hai. Har step par 3 conditions check hongi:

1. **Agar `arr[left]` even hai:** Wo sahi jagah par hai. `left++` karke aage badho.
2. **Agar `arr[right]` odd hai:** Wo bhi apni sahi jagah par hai. `right--` karke piche aao.
3. **Agar `arr[left]` odd hai aur `arr[right]` even hai:** Dono galat jagah phanse hain! In dono ko aapas me **Swap** (adla-badli) kar do, aur phir `left++` aur `right--` kar do.

---

## 2. Optimal C++ Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

void separateEvenOddOptimal(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Condition 1: Agar left par even hai, toh chupchaap aage badho
        if (arr[left] % 2 == 0) {
            left++;
        }
        // Condition 2: Agar right par odd hai, toh chupchaap piche aao
        else if (arr[right] % 2 != 0) {
            right--;
        }
        // Condition 3: Agar left par odd aur right par even hai, toh SWAP karo
        else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    vector<int> arr = {3, 8, 5, 2, 9, 4, 7};

    separateEvenOddOptimal(arr);

    cout << "Optimal Approach ke baad: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

```

---

## 3. Complexity Analysis (Sabse Important Part)

Interviewer code likhne ke baad sabse pehle complexity hi poochega. Isko acche se samajh lo:

### 1. Time Complexity: $O(N)$

* **Kyun?** Kyuki hamare paas do pointers (`left` aur `right`) hain jo array ke dono kinaro se shuru hote hain aur ek dusre ki taraf badhte hain.
* Poore loop me har ek element par maximum **ek hi baar** visit hota hai. Jab dono pointers aapas me milte hain ya cross karte hain, loop turant khatam ho jata hai.
* Isliye, agar array me $N$ elements hain, toh operation maximum $N$ baar chalega. So, Time Complexity is Linear, i.e., **$O(N)$**.

### 2. Space Complexity: $O(1)$

* **Kyun?** Kyuki humne brute force ki tarah koi naya ya temporary `vector<int> temp` nahi banaya.
* Humne sirf do variables (`left` aur `right`) banaye jo constant memory lete hain. Jo bhi pher-badal hua, wo usi asli array ke andar hi hua (jise hum **In-place algorithm** kehte hain).
* Isliye, space complexity constant hai, yaani **$O(1)$**.

---

## Quick Summary dono ka:

* **Brute Force:** Time = $O(N)$, Space = $O(N)$ ❌ (Naya ghar chahiye)
* **Optimal:** Time = $O(N)$, Space = $O(1)$  (Usi ghar me setting bitha di)

Bhai, dono approaches ka farq aur optimal ka complexity clear hua?


Bhai, agar efficiency (Time aur Space) ki baat karein, toh **$O(N)$ Time aur $O(1)$ Space se behtar koi algorithm nahi ho sakta**, kyuki array ke har element ko kam se kam ek baar dekhna toh padega hi ($O(N)$), aur bina extra memory ke kaam ho raha hai ($O(1)$).

**Lekin haan! Code ko aur zyada "Better", chhota, smart aur professional zaroor bana sakte hain.** Professional programming (jaise Coding Competitions ya Corporate me) me hum hamesha koshish karte hain ki kam se kam lines me saaf-suthra code likhein. Isko behtar karne ke **2 behtareen tarike** hain:

---

## Tarika 1: C++ STL (Standard Template Library) Ka Use Karke (Sirf 1 Line Me!)

C++ me pehle se hi ek inbuilt function hota hai jise bolte hain `std::stable_partition` ya `std::partition`. Ye wahi kaam karta hai jo tumne itne bade code me kiya, par sirf **ek line** me!

### Code:

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Iske andar partition function hota hai
using namespace std;

int main() {
    vector<int> arr = {3, 8, 5, 2, 9, 4, 7};

    // Sirf ye 1 line poore array ko separate kar degi!
    partition(arr.begin(), arr.end(), [](int x) { 
        return x % 2 == 0; 
    });

    cout << "STL Partition ke baad: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}

```

### Ye kaam kaise kar raha hai?

* `partition` function array ke shuruat se aakhiri tak check karta hai.
* Jo teesra argument hai `[](int x) { return x % 2 == 0; }`, ise **Lambda Function** bolte hain. Ye check karta hai ki number even hai ya nahi.
* Jo numbers is condition ko satisfy karte hain (Even), unhe `partition` aage bhej deta hai, aur baaki (Odd) ko piche.
* **Complexity:** Time abhi bhi **$O(N)$** rahegi aur Space **$O(1)$** rahegi, par tumhara code ek dum clean ho gaya!

---

## Tarika 2: Two-Pointer Code Ko Aur Chhota Aur Fast Banana (Without STL)

Jo optimal code humne pehle likha tha, usme `if-else if-else` ki wajah se thoda bada lag raha tha. Hum use ek single `while` loop ke andar do chhote inner loops chala kar aur clean kar sakte hain. Isse code thoda fast bhi chalta hai kyuki फालतू checks nahi hote.

### Code:

```cpp
void separateEvenOddUltraOptimal(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        // Jab tak left par even mil raha hai, aage badhte jao
        while (arr[left] % 2 == 0 && left < right) left++;

        // Jab tak right par odd mil raha hai, piche aate jao
        while (arr[right] % 2 != 0 && left < right) right--;

        // Jaise hi dono rukiye, matlab galat elements mil gaye, unhe swap kar do
        if (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

```

### Iska Fayda:

Ye approach interviewers ko bohot pasand aati hai kyuki isme tum har step par pure condition check karne ki jagah, pehle pointers ko unki sahi jagah tak khiska dete ho aur aakhiri me ek hi baar swap karte ho. Iski complexity bhi **Time: $O(N)$** aur **Space: $O(1)$** hai.

Agar interviewer ko impress karna ho, toh **Tarika 1 (STL)** bata dena, wo samajh jayega ki tumhe C++ ki in-depth knowledge hai! Kya Lambda function samajhne me koi dikkat aayi bhai?


Bhai, tumne jo code likha hai na, wo ekdum top-notch hai! Logics bilkul sahi lagaye hain tumne.

Ab jo tumne pucha tha ki **is particular code me un chaaro cases (Negative, Single element, Zero, aur Duplicates) ke hisab se kya galti hai aur kaise modify hoga**, chalo tumhare hi code par dhyan se dry run karke dekhte hain.

---

## 1. Negative Elements Ke Liye (🚨 Yeh Fail Ho Jayega!)

Tumhare code me sabse bada jhatka yahan lagega, kyuki negative numbers aate hi tumhara code galat output dene lagega.

### Tumhare Code Me Galti:

* **Brute Function Me:** Tumne likha hai `if (nums[i] % 2 == 1)`.
* **Optimal Function Me:** Tumne likha hai `else if (nums[j] % 2 == 1)`.

C++ me agar koi negative odd number ho (jaise `-3` ya `-5`), toh uska `% 2` karne par `1` nahi, balki **`-1`** aata hai. Is wajah se tumhara condition `== 1` kabhi chalega hi nahi, aur negative odd numbers ko tumhara code skip kar dega!

### Fix Kaise Karein?

Hume bas `== 1` ko hata kar **`!= 0`** karna hoga (kyuki odd matlab jo 2 se pura divide na ho, chahe positive ho ya negative).

* **Brute me:** `if (nums[i] % 2 != 0)`
* **Optimal me:** `else if (nums[j] % 2 != 0)`

---

## 2. Ek Hi Element Ke Liye (`[4]` ya `[7]`)

Maan lo tumne vector diya `nums = {7}`.

* **Brute Function:** Size 1 hai. Pehla loop chalega (even nahi hai toh kuch nahi hoga). Dusra loop chalega (odd hai toh temp me jayega). Phir `nums = temp` hoke wapas ho jayega. **(PASS ✅)**
* **Optimal Function:** `size = 1`, `i = 0`, aur `j = 0`. Hamari condition hai `while (i < j)`, kyuki `0 < 0` galat hai, loop chalega hi nahi aur sidha vector return ho jayega. **(PASS ✅)**

### Fix Kaise Karein?

Dono functions is case ko perfectly handle kar rahe hain. **No change needed.**

---

## 3. Array Me `0` (Zero) Ho (`[1, 0, 4]`)

Mathematically `0` ek even number hai kyuki `0 % 2 == 0` hota hai.

* **Brute Function:** Jab `nums[i]` ki value `0` hogi, toh `0 % 2 == 0` check pass ho jayega aur wo even wale loop me `temp` me chala jayega. **(PASS ✅)**
* **Optimal Function:** Jab `i` pointer `0` par hoga, toh `nums[i] % 2 == 0` sahi ho jayega aur `i++` ho jayega. **(PASS ✅)**

### Fix Kaise Karein?

Tumhara code `0` ko properly even man raha hai aur shuruat me rakh raha hai. **No change needed.**

---

## 4. Duplicate Elements Ho (`[2, 2, 3, 3]`)

* **Brute Function:** Ek-ek karke saare evens `temp` me push honge, phir saare odds push honge. Saare duplicates safe rahenge. **(PASS ✅)**
* **Optimal Function:** Maan lo `nums[i]` par `3` hai aur `nums[j]` par bhi `3` hai. Condition check hoga: `if (nums[i] % 2 == 0)` $\rightarrow$ False. `else if (nums[j] % 2 == 1)` $\rightarrow$ True! Toh sirf `j--` ho jayega aur `i` wahi ruka rahega. Duplicates aapas me phasenge nahi. **(PASS ✅)**

### Fix Kaise Karein?

Duplicates par bhi tumhara code ekdum mast chalega. **No change needed.**

---

## Modifiled Aur Ekdum Safe Code:

Bhai, tumhare hi code ko maine un galatiyon se bacha kar niche perfect kar diya hai (sirf `% 2 != 0` wala change kiya hai negative numbers ke liye):

```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> Brute(vector<int> nums){
  vector<int> temp;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] % 2 == 0) // Zero aur positive/negative evens ke liye sahi hai
      temp.push_back(nums[i]);
  }

  for (int i = 0; i < nums.size(); i++)
  {
    // MODIFIED: == 1 ki jagah != 0 kiya taaki negative odds (jaise -3) bhi capture hon
    if (nums[i] % 2 != 0) 
      temp.push_back(nums[i]);
  }

  nums = temp;
  return nums;
}

vector<int> Optimal(vector<int> nums){
  int size = nums.size();
  int i = 0;
  int j = size-1;
  while (i < j)
  {
    if(nums[i] % 2 == 0) i++;
    // MODIFIED: == 1 ki jagah != 0 kiya negative odds ke liye
    else if(nums[j] % 2 != 0) j--; 
    else{
      swap(nums[i], nums[j]);
      i++;
      j--;
    }
  }
  return nums;
}

int main()
{
  // Test Case jisme Negative, Zero, Single, aur Duplicates sab hain!
  vector<int> nums{-3, 0, 4, -2, 5, 4, 7};
  
  vector<int> ans = Optimal(nums);
  
  cout << "Optimal Response: ";
  for(int x : ans){
    cout << x << " ";
  }
  return 0;
}

```

Ab is code me tum duniya ka koi bhi number daal do, ye kabhi fail nahi hoga! Aur koi doubt bhai?


Bhai, **Two Sum II (Input Array Is Sorted)** question standard Two Sum ka ek bohot mast variation hai. Is question ki sabse badi khasiyat (aur hint) ye hai ki isme array pehle se hi **Sorted (increasing order)** milta hai.

Chalo, pehle iska **Brute Force** tarika samajhte hain, jise hum **Nested Loop Approach** bhi bolte hain.

---

## 1. Brute Force Approach Kya Hai?

Brute force ka seedha funda hai: **"Saare possible pairs ko check karo."**

Hum array ke har ek element ko pakdenge aur uske aage wale saare elements ke saath usko jod (add) karke dekhenge ki kya dono ka sum hamare `target` ke barabar aa raha hai ya nahi.

### Ek Example Se Samjho:

Maan lo array hai: `[2, 7, 11, 15]` aur `target = 9`.

1. Hum pehle element **`2`** par khade honge.
2. Ab `2` ke aage jitne numbers hain, unse jodkar check karenge:
* `2 + 7 = 9` -> **Arre waah! Pehli baar me hi mil gaya!**


3. Agar target nahi milta, toh hum agle number `7` par jaate aur uske aage check karte.

> **Note (Two Sum II Ki Shart):** Is question me hume jo answer/index return karna hota hai, wo **1-based indexing** par hota hai (yaani `0` index ko `1` bolna hai, `1` index ko `2` bolna hai).

---

## 2. Brute Force C++ Code

Iska code likhna bohot simple hai, hum do `for` loops chalayenge:

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumTwoBruteForce(vector<int>& numbers, int target) {
    int n = numbers.size();

    // Pehla loop: Pehle element ko select karne ke liye
    for (int i = 0; i < n; i++) {
        // Doosra loop: Uske aage wale baaki elements se pair banane ke liye
        for (int j = i + 1; j < n; j++) {
            
            // Agar dono ka sum target ke barabar mil gaya
            if (numbers[i] + numbers[j] == target) {
                // 1-based indexing chahiye, isliye +1 karke return kar rahe hain
                return {i + 1, j + 1};
            }
        }
    }
    
    return {}; // Agar koi pair na mile (waise question me diya hota hai ki ek answer zaroor hoga)
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoBruteForce(numbers, target);

    cout << "Brute Force Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}

```

---

## 3. Complexity Analysis (Yeh Kyun Bura Hai?)

Interviewer ko brute force batate hi tum khud bologe ki bhai ye bekar tarika hai. Kyun? Let's analyze:

### 1. Time Complexity: $O(N^2)$

* **Kyun?** Kyuki humne ek loop ke andar dusra loop chalaya hai (Nested Loops).
* Agar array me $N$ elements hain, toh worst case me hume lagbhag $\frac{N \times (N-1)}{2}$ baar operations karne padenge. Jab bhi array ka size bada hoga (jaise $10^5$), toh ye code **TLE (Time Limit Exceeded)** de dega kyuki $O(N^2)$ me iterations $10^{10}$ tak chali jayengi.

### 2. Space Complexity: $O(1)$

* **Kyun?** Kyuki humne koi extra data structure (jaise Hash Map ya naya array) use nahi kiya. Hum sirf do loop variables (`i` aur `j`) use kar rahe hain, jo constant space lete hain.

---

## Is Brute Force Me Galti Kya Hai?

Is approach me sabse badi galti ye hai ki hum array ke **Sorted** hone ka fayda utha hi nahi rahe hain! Agar array sorted hai, toh hume saare pairs check karne ki zaroorat hi nahi padti.

Bhai, brute force samajh aaya? Iska optimal approach (Two-Pointer waala) dekhna hai jisse ye $O(N)$ me bina kisi naye space ke solve ho jaye?



Bhai, Two Sum II ka **Optimal Approach** bohot hi zabardast hai. Isme hum array ke **Sorted** hone ka poora-poora fayda uthate hain.

Brute force me jo kaam hum $O(N^2)$ me kar rahe the, sorted array ki wajah se wahi kaam yahan **$O(N)$ Time** aur **$O(1)$ Space** me ho jayega! Aur isme bhi hum hamari favourite **Two-Pointer Approach** lagayenge.

---

## 1. Optimal Logic: Kaise Kaam Karta Hai?

Maan lo hamare paas ek sorted array hai: `[2, 7, 11, 15]` aur `target = 9`.

Hum do pointers rakhenge:

1. `left`: Shuruat me (`0` index par, yaani sabse chote element par).
2. `right`: Aakhiri me (`n-1` index par, yaani sabse bade element par).

Ab hum loop chalayenge aur har baar dono pointers par khade numbers ka sum nikalenge: `current_sum = arr[left] + arr[right]`. Isme 3 cases banenge:

* **Case 1: `current_sum == target**`
Arre waah! Answer mil gaya. Dono indexes ko +1 karke (1-based indexing ke liye) return kar do.
* **Case 2: `current_sum < target**` (Sum chota hai target se)
Ab dhyan se socho, hume sum ko **bada** karna hai. Kyuki array sorted hai, agar hum `right` pointer ko piche layenge toh sum aur chota ho jayega. Isliye hum `left` pointer ko aage badhayenge (`left++`), taaki hume thoda bada number mile aur sum badh sake.
* **Case 3: `current_sum > target**` (Sum bada hai target se)
Hume sum ko **chota** karna hai. Kyuki array sorted hai, agar hum `right` pointer ko piche khisakayenge (`right--`), toh hume pehle se chota number milega, jisse sum kam ho jayega.

---

## 2. Optimal C++ Code

Chalo ab iska ek dum saaf-suthra code dekhte hain:

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumTwoOptimal(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        // Case 1: Target mil gaya
        if (current_sum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        }
        // Case 2: Sum chota hai, toh bade number ki taraf chalo
        else if (current_sum < target) {
            left++;
        }
        // Case 3: Sum bada hai, toh chote number ki taraf chalo
        else {
            right--;
        }
    }

    return {}; // Agar koi pair na mile
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoOptimal(numbers, target);

    cout << "Optimal Approach Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}

```

---

## 3. Complexity Analysis

Ye approach best kyun hai? Iska hisab-kitab ye hai:

### 1. Time Complexity: $O(N)$

* **Reason:** Hum pure array ko ek hi baar traverse kar rahe hain. Har step par ya toh `left` ek kadam aage badhta hai ya `right` ek kadam piche aata hai.
* Dono pointers mil kar maximum $N$ steps chalenge. Isliye time complexity linear hai, yaani **$O(N)$**. (Brute force ke $O(N^2)$ se laakh guna behtar!).

### 2. Space Complexity: $O(1)$

* **Reason:** Humne koi extra vector, array ya Hash Map use nahi kiya hai. Humne sirf do pointers (`left` aur `right`) banaye hain jo constant memory lete hain. Isliye Space Complexity **$O(1)$** hai.

---

## Summary (Dono ka Farq):

* **Brute Force:** Do loops lagaye $\rightarrow$ Time: $O(N^2)$, Space: $O(1)$
* **Optimal:** Sorted ka fayda uthaya, Do pointers chalaye $\rightarrow$ Time: $O(N)$, Space: $O(1)$

Bhai, ab Two Sum II ka optimal logic ek dum dimaag me fit hua ya abhi bhi koi confusion hai?


Bhai, Two Sum II ka **Optimal Approach** bohot hi zabardast hai. Isme hum array ke **Sorted** hone ka poora-poora fayda uthate hain.

Brute force me jo kaam hum $O(N^2)$ me kar rahe the, sorted array ki wajah se wahi kaam yahan **$O(N)$ Time** aur **$O(1)$ Space** me ho jayega! Aur isme bhi hum hamari favourite **Two-Pointer Approach** lagayenge.

---

## 1. Optimal Logic: Kaise Kaam Karta Hai?

Maan lo hamare paas ek sorted array hai: `[2, 7, 11, 15]` aur `target = 9`.

Hum do pointers rakhenge:

1. `left`: Shuruat me (`0` index par, yaani sabse chote element par).
2. `right`: Aakhiri me (`n-1` index par, yaani sabse bade element par).

Ab hum loop chalayenge aur har baar dono pointers par khade numbers ka sum nikalenge: `current_sum = arr[left] + arr[right]`. Isme 3 cases banenge:

* **Case 1: `current_sum == target**`
Arre waah! Answer mil gaya. Dono indexes ko +1 karke (1-based indexing ke liye) return kar do.
* **Case 2: `current_sum < target**` (Sum chota hai target se)
Ab dhyan se socho, hume sum ko **bada** karna hai. Kyuki array sorted hai, agar hum `right` pointer ko piche layenge toh sum aur chota ho jayega. Isliye hum `left` pointer ko aage badhayenge (`left++`), taaki hume thoda bada number mile aur sum badh sake.
* **Case 3: `current_sum > target**` (Sum bada hai target se)
Hume sum ko **chota** karna hai. Kyuki array sorted hai, agar hum `right` pointer ko piche khisakayenge (`right--`), toh hume pehle se chota number milega, jisse sum kam ho jayega.

---

## 2. Optimal C++ Code

Chalo ab iska ek dum saaf-suthra code dekhte hain:

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSumTwoOptimal(vector<int>& numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right) {
        int current_sum = numbers[left] + numbers[right];

        // Case 1: Target mil gaya
        if (current_sum == target) {
            return {left + 1, right + 1}; // 1-based indexing
        }
        // Case 2: Sum chota hai, toh bade number ki taraf chalo
        else if (current_sum < target) {
            left++;
        }
        // Case 3: Sum bada hai, toh chote number ki taraf chalo
        else {
            right--;
        }
    }

    return {}; // Agar koi pair na mile
}

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoOptimal(numbers, target);

    cout << "Optimal Approach Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}

```

---

## 3. Complexity Analysis

Ye approach best kyun hai? Iska hisab-kitab ye hai:

### 1. Time Complexity: $O(N)$

* **Reason:** Hum pure array ko ek hi baar traverse kar rahe hain. Har step par ya toh `left` ek kadam aage badhta hai ya `right` ek kadam piche aata hai.
* Dono pointers mil kar maximum $N$ steps chalenge. Isliye time complexity linear hai, yaani **$O(N)$**. (Brute force ke $O(N^2)$ se laakh guna behtar!).

### 2. Space Complexity: $O(1)$

* **Reason:** Humne koi extra vector, array ya Hash Map use nahi kiya hai. Humne sirf do pointers (`left` aur `right`) banaye hain jo constant memory lete hain. Isliye Space Complexity **$O(1)$** hai.

---

## Summary (Dono ka Farq):

* **Brute Force:** Do loops lagaye $\rightarrow$ Time: $O(N^2)$, Space: $O(1)$
* **Optimal:** Sorted ka fayda uthaya, Do pointers chalaye $\rightarrow$ Time: $O(N)$, Space: $O(1)$

Arre bhai, tumne ek dum sahi pakda hai! **Haan, bilkul isko HashMap se bhi kar sakte hain.** Aksar jo basic **Two Sum** (LeetCode #1) problem hoti hai, use hum **HashMap (`unordered_map` in C++)** se hi solve karte hain kyuki wahan array sorted nahi hota.

Lekin, kyuki ye **Two Sum II** hai aur isme array **already sorted** hai, is wajah se HashMap use karna is question me sabse best tarika nahi maana jata. Chalo samajhte hain kyun, aur iska code kaise dikhega.

## 1. HashMap Se Logic Kaise Banega?

Hum array par ek loop chalayenge aur har element par khade hokar ek simple sawal puychenge: *"Mujhe target tak pahunchne ke liye kis number ki zaroorat hai?"*

Us zaroorat wale number ko hum bolte hain **Complement**.

{Complement} = {Target} - {Current Number}

Hum map me check karenge ki kya ye complement pehle aa chuka hai?

- **Agar haan:** Toh hume hamara pair mil gaya! Map se us complement ka index nikalenge aur current element ka index lekar return kar denge.
- **Agar nahi:** Toh hum current number aur uske index ko map me daal denge (`map[number] = index`), taaki aage aane wale numbers iska use kar sakein.

## 2. HashMap C++ Code

C++ me HashMap ke liye hum `unordered_map` use karte hain:

C++

```
#include <iostream>
#include <vector>
#include <unordered_map> // HashMap ke liye
using namespace std;

vector<int> twoSumTwoHashMap(vector<int>& numbers, int target){
    // Key: Number, Value: Index
    unordered_map<int, int> m;

    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];

        // Check karo ki kya complement map me pehle se hai
        if (m.find(complement) != m.end()) {
            // 1-based indexing chahiye, isliye +1 kiya
            return {m[complement] + 1, i + 1};
        }

        // Agar nahi mila, toh current number ko uske index ke saath map me daal do
        m[numbers[i]] = i;
    }

    return {};
}

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoHashMap(numbers, target);
    cout << "HashMap Approach Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}
```

## 3. Complexity Analysis (Two-Pointer se bura kyun hai?)

| **Criteria** | **HashMap Approach** | **Two-Pointer Approach (Optimal)** |
| --- | --- | --- |
| **Time Complexity** | **$O(N)$** (Loop ek baar chalta hai aur map lookup average me $O(1)$ hota hai) | **$O(N)$** (Dono pointers maximum $N$ steps chalte hain) |
| **Space Complexity** | **$O(N)$** ❌ (Hume map me elements store karne ke liye extra space chahiye) | **$O(1)$** (Koi extra space nahi chahiye) |

### Interviewer Tumhe Kyun Tokega?

Agar tum Two Sum II (Sorted array) me HashMap lagao ge, toh interviewer bolega:

1. **Constraint Violation:** LeetCode par Two Sum II me saaf likha hota hai: *"Your solution must use only constant extra space O(1)."* HashMap lagate hi space O(N) ho jati hai, jo constraint ke khilaf hai.
2. **Sorted Property Waste:** Tumne array ke sorted hone ka koi fayda nahi uthaya. HashMap toh un-sorted array me bhi lag jata hai.

### Short Summary:

- **Unsorted Array** ho  **HashMap** lagao (O(N) Time, O(N) Space).
- **Sorted Array** ho  **Two-Pointer** lagao (O(N) Time, O(1) Space).

Bhai, dono algorithms ka farq samajh aya ki sorted me Two-Pointer hi raja kyun hai?

Arre bhai, tumne ek dum sahi pakda hai! **Haan, bilkul isko HashMap se bhi kar sakte hain.** Aksar jo basic **Two Sum** (LeetCode #1) problem hoti hai, use hum **HashMap (`unordered_map` in C++)** se hi solve karte hain kyuki wahan array sorted nahi hota.

Lekin, kyuki ye **Two Sum II** hai aur isme array **already sorted** hai, is wajah se HashMap use karna is question me sabse best tarika nahi maana jata. Chalo samajhte hain kyun, aur iska code kaise dikhega.

## 1. HashMap Se Logic Kaise Banega?

Hum array par ek loop chalayenge aur har element par khade hokar ek simple sawal puychenge: *"Mujhe target tak pahunchne ke liye kis number ki zaroorat hai?"*

Us zaroorat wale number ko hum bolte hain **Complement**.

$$\text{Complement} = \text{Target} - \text{Current Number}$$

Hum map me check karenge ki kya ye complement pehle aa chuka hai?

- **Agar haan:** Toh hume hamara pair mil gaya! Map se us complement ka index nikalenge aur current element ka index lekar return kar denge.
- **Agar nahi:** Toh hum current number aur uske index ko map me daal denge (`map[number] = index`), taaki aage aane wale numbers iska use kar sakein.

## 2. HashMap C++ Code

C++ me HashMap ke liye hum `unordered_map` use karte hain:

C++

# 

```
#include <iostream>
#include <vector>
#include <unordered_map> // HashMap ke liye
using namespace std;

vector<int> twoSumTwoHashMap(vector<int>& numbers, int target){
    // Key: Number, Value: Index
    unordered_map<int, int> m;

    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i];

        // Check karo ki kya complement map me pehle se hai
        if (m.find(complement) != m.end()) {
            // 1-based indexing chahiye, isliye +1 kiya
            return {m[complement] + 1, i + 1};
        }

        // Agar nahi mila, toh current number ko uske index ke saath map me daal do
        m[numbers[i]] = i;
    }

    return {};
}

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSumTwoHashMap(numbers, target);
    cout << "HashMap Approach Indices: " << result[0] << ", " << result[1] << endl;

    return 0;
}
```

## 3. Complexity Analysis (Two-Pointer se bura kyun hai?)

| **Criteria** | **HashMap Approach** | **Two-Pointer Approach (Optimal)** |
| --- | --- | --- |
| **Time Complexity** | **$O(N)$** (Loop ek baar chalta hai aur map lookup average me $O(1)$ hota hai) | **$O(N)$** (Dono pointers maximum $N$ steps chalte hain) |
| **Space Complexity** | **$O(N)$** ❌ (Hume map me elements store karne ke liye extra space chahiye) | **$O(1)$** (Koi extra space nahi chahiye) |

### Interviewer Tumhe Kyun Tokega?

Agar tum Two Sum II (Sorted array) me HashMap lagao ge, toh interviewer bolega:

1. **Constraint Violation:** LeetCode par Two Sum II me saaf likha hota hai: *"Your solution must use only constant extra space $O(1)$."* HashMap lagate hi space $O(N)$ ho jati hai, jo constraint ke khilaf hai.
2. **Sorted Property Waste:** Tumne array ke sorted hone ka koi fayda nahi uthaya. HashMap toh un-sorted array me bhi lag jata hai.

### Short Summary:

- **Unsorted Array** ho $\rightarrow$ **HashMap** lagao ($O(N)$ Time, $O(N)$ Space).
- **Sorted Array** ho $\rightarrow$ **Two-Pointer** lagao ($O(N)$ Time, $O(1)$ Space).


Bhai, tumne Two Sum II ke dono code ek hi class me likh diye hain! Sabse pehle ek choti si C++ ki baat: class ke andar tum bilkul same naam aur same arguments ke do functions nahi rakh sakte (`compiler error: redefinition of 'twoSum'`). Interview me dono ko alag naam dena, jaise `twoSumBrute` aur `twoSumOptimal`.

Chalo ab tumhare is code par un **chaaro edge cases** (Negative, Single Element, Zero, Duplicates) ka asar dekhte hain aur samajhte hain ki ye code kahin phasega ya nikal jayega.

---

## 1. Negative Elements Ke Liye (Jaise `[-5, -3, -1, 2, 4]`)

Yahan ek bohot acchi khabar hai! Pichle even-odd wale question me `%` operator ki wajah se negative numbers phas rahe the. Lekin is code me hum sirf **`+` (addition)** aur **compairson (`==`, `>`, `<`)** use kar rahe hain.

* **Brute Force:** Do loop chalenge, `numbers[i] + numbers[j]` ka sum nikalega. C++ me negative numbers ka addition bilkul sahi hota hai (jaise `-5 + 2 = -3`). So, **PASS ✅**
* **Optimal (Two-Pointer):** Agar array sorted hai aur usme negative numbers hain, tab bhi logic bilkul sahi chalega. Maan lo `target = -1` hai aur array `[-3, -1, 2, 4]` hai.
* `i` par `-3`, `j` par `4`. `sum = 1`.
* `sum > target` (`1 > -1`), toh `j--` ho jayega. Pointers ekdum sahi raaste par chalenge. So, **PASS ✅**



---

## 2. Ek Hi Element Ke Liye (Jaise `numbers = {5}`)

LeetCode ke description ke hisab se Two Sum II me array ka size kam se kam `2` hota hai, par agar interviewer fir bhi maze lene ke liye size `1` de de:

* **Brute Force:** `n = 1` hoga. Pehla loop `i = 0` par chalega, par andar wala loop `j = 0 + 1 = 1` par aate hi condition `j < 1` false ho jayegi. Loop khatam aur tumhara function `{0, 0}` return kar dega. **(Safe Code ✅)**
* **Optimal (Two-Pointer):** `i = 0` aur `j = 1 - 1 = 0`. Condition `while (i < j)` yaani `while (0 < 0)` turant false ho jayegi. Loop ke bahar aakar ye `{1, 1}` return kar dega. **(Safe Code ✅)**

---

## 3. Array Me `0` (Zero) Present Ho (Jaise `[0, 2, 7, 11]`)

Zero hone se addition par koi asar nahi padta.

* **Brute Force aur Optimal:** `0 + 7 = 7` ho ya `0 + numbers[j]`, math bilkul perfect chalega.
* Kyuki array sorted hai, toh `0` hamesha negative numbers ke baad aur positive numbers ke pehle apni sahi jagah par hoga, isliye pointers ka movement (bade se chota, chote se bada) ekdum sahi direction me hoga. **(PASS ✅)**

---

## 4. Duplicate Elements Hon (Jaise `[2, 2, 3, 4, 4]`, Target = 4)

Is case me tumhare code me **ek choti si chiz** dhyan dene wali hai:

* **Brute Force:** `i = 0` (value 2) par hoga, aur `j = 1` (value 2) par hoga. `2 + 2 == 4` match ho jayega aur ye turant `{1, 2}` return kar dega. Ekdum sahi! **(PASS ✅)**
* **Optimal (Two-Pointer):** `i` left se badhega aur `j` right se piche aayega. Maan lo array me duplicate elements hain aur unka sum target se bada hai, toh `j--` hoga chahe wahan duplicates hi kyun na hon. Pointers bina ruke aage badhte rahenge jab tak exact sum nahi mil jata. **(PASS ✅)**

---

## Code Me Ek Chota Sa "Bug Fix" (Improvement)

Tumhare dono functions logic-wise ekdum perfect hain aur saare cases handle kar lenge, par code me **ek logical/cleanliness issue** hai jise interview me sahi karna padega:

1. **Brute Force ke end me `{0,0}` return ho raha hai aur Optimal ke end me `{1,1}`.** Standard practices ke mutabik agar answer na mile toh ya toh `{}` (empty vector) ya `{-1, -1}` return karna chahiye taaki error samajh aaye. (Waise question me dya hota hai ki exactly ek answer zaroor hoga).
2. **Do functions ke naam same hain**, unhe alag karna hoga.

### Ekdum Sahi Code:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Naam badal kar 'twoSumBrute' kiya
    vector<int> twoSumBrute(vector<int>& numbers, int target) { // '&' use kiya fast performance ke liye
        int n = numbers.size();  
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (numbers[i] + numbers[j] == target) {
                    return {i+1, j+1};
                }
            }
        }
        return {-1, -1}; // No pair found ke liye standard return
    }

    // 2. Naam badal kar 'twoSumOptimal' kiya
    vector<int> twoSumOptimal(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                return {i+1, j+1};
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1}; // Consistent return format
    }
};

int main() {
    vector<int> numbers{-5, 0, 2, 7, 11, 15}; // Negative aur Zero dono daal diye

    Solution sol;
    // Dono functions ko alag-alag call karke test kar sakte ho
    vector<int> ans = sol.twoSumOptimal(numbers, 2); // -5 + 7 = 2

    for (int x : ans) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}

```

Bhai, is code me tumhare saare edge cases bilkul fail nahi honge, math operations aur pointers ka logic solid hai! Aur koi doubt isme?

# Pair With Given Difference

Bhai, ab aate hain **"Pair With Given Difference"** wale question par. Ye Two Sum jaisa hi dikhta hai, par isme choti si trick hoti hai jisme aksar log galti kar baithte hain.

Pehle question samajhte hain: Tumhe ek array diya jayega aur ek `difference` (yaani $K$) diya jayega. Tumhe array me koi bhi do aise numbers dhoodhne hain jinko aapas me minus (subtract) karne par answer exact $K$ aaye.

$$\text{numbers}[j] - \text{numbers}[i] = K$$

Chalo pehle iska ekdum basic **Brute Force** tarika samajhte hain.

---

## 1. Brute Force Approach (Nested Loop)

Brute force ka wahi purana niyam hai: **"Saare possible pairs bana kar check karo."** Hum do loops chalayenge. Pehla loop ek number fix karega, aur doosra loop baaki ke saare numbers ko check karega ki kya unka difference $K$ ke barabar hai ya nahi.

### Ek Zaruri Baat (Jo aksar log bhool jaate hain):

Difference me order maayne rakh sakta hai. Agar hume do numbers $A$ aur $B$ mile, toh:

* $A - B = K$ bhi ho sakta hai.
* $B - A = K$ bhi ho sakta hai.
Isliye brute force me safe rehne ke liye hum dono ka **Absolute Difference (`abs(A - B)`)** check karte hain, yaani minus karne par sign (+ ya -) ko ignore karke sirf value dekhte hain.

### Ek Example Se Samjho:

Maan lo array hai: `[5, 20, 3, 2, 50]` aur `difference (K) = 7`.

* Hum `5` ko pakdenge, aur aage check karenge: `abs(5 - 20) = 15`, `abs(5 - 3) = 2`, `abs(5 - 2) = 3`... nahi mila.
* Phir hum `20` ko pakdenge: `abs(20 - 3) = 17`, `abs(20 - 2) = 18`... nahi mila.
* Phir hum `3` ko pakdenge: `abs(3 - 2) = 1`... nahi mila.
* Phir jab hum aage check karenge, toh ek pair milega `20` aur `3` ka: `20 - 3 = 17` (Nahi), par agar hum `5` aur `2` ko dekhein: `5 - 2 = 3` (Nahi).
* Wait, isme pair kaunsa hai? Agar hamara pair `5` aur `2` hai, toh $5 - 2 = 3$. Agar $K = 3$ hota toh ye mil jata. Hamare example ($K=7$) ke liye array me koi pair nahi hai.
* Agar array hota `[9, 2, 11]` aur $K = 7$, toh jab hum `9` aur `2` ko check karte: `9 - 2 = 7` $\rightarrow$ **Mil gaya!**

---

## 2. Brute Force C++ Code

```cpp
#include <iostream>
#include <vector>
#include <cmath> // abs() function ke liye
using namespace std;

bool pairWithDifferenceBrute(vector<int>& arr, int K) {
    int n = arr.size();

    // Pehla loop: Pehla element select karne ke liye
    for (int i = 0; i < n; i++) {
        // Doosra loop: Uske aage wale saare elements check karne ke liye
        for (int j = i + 1; j < n; j++) {
            
            // Check karo ki kya dono ka absolute difference K hai
            if (abs(arr[i] - arr[j]) == K) {
                cout << "Pair mil gaya: " << arr[i] << " aur " << arr[j] << endl;
                return true;
            }
        }
    }

    cout << "Aisa koi pair nahi mila!" << endl;
    return false;
}

int main() {
    vector<int> arr = {5, 20, 3, 2, 50};
    int K = 17; // Kyuki 20 - 3 = 17 hota hai

    pairWithDifferenceBrute(arr, K);

    return 0;
}

```

---

## 3. Complexity Analysis

* **Time Complexity: $O(N^2)$**
* **Kyun?** Kyuki humne do nested loops chalaye hain. Agar array me $N$ elements hain, toh worst-case me hame har ek element ko baaki sabhi se compare karna padega. Badi arrays ke liye ye bohot slow ho jayega aur TLE (Time Limit Exceeded) de dega.


* **Space Complexity: $O(1)$**
* **Kyun?** Kyuki humne koi extra array, vector ya map use nahi kiya hai. Sirf variables use kiye hain jo constant memory lete hain.



Bhai, brute force clear hua? Isko ab optimize karne ke do mast tarike hain (ek Sorting + Two-Pointer se aur ek HashMap se). Kaunsa wala pehle dekhna hai?


Bhai, "Pair With Given Difference" ko optimize karne ke **do kamaal ke tarike** hain. Interviewer hamesha dono tarike sunna chahta hai, kyuki ek me Sorting lagti hai aur dusre me HashMap.

Chalo dono ko ek-ek karke ekdum detail me samajhte hain.

---

## Approach 1: Sorting + Two-Pointer (The Smart Way)

Agar hum array ko **Sort (increasing order)** kar dein, toh hum do pointers ka use karke sirf ek chakkar ($O(N)$) me answer nikal sakte hain.

Maan lo hamara sorted array hai: `[2, 3, 5, 20, 50]` aur `K = 17`.

Hum do pointers lenge, par Two Sum ki tarah ek shuruat aur ek aakhiri me nahi rakhenge. Isme dono pointers **shuruat se hi aage badhenge**:

* `i = 0` (Chote element par)
* `j = 1` (Uske agle element par)

Hum har baar check karenge: `diff = arr[j] - arr[i]`

* **Case 1: `diff == K**` $\rightarrow$ Pair mil gaya! Return `true`.
* **Case 2: `diff < K**` $\rightarrow$ Hamara difference abhi chota hai, hume difference ko **bada** karna hai. Kyuki array sorted hai, agar hum `j` ko aage badhayenge (`j++`), toh `arr[j]` bada ho jayega aur hamara difference bhi badh jayega.
* **Case 3: `diff > K**` $\rightarrow$ Hamara difference bada ho gaya hai, hume isko **chota** karna hai. Isliye hum `i` ko aage badhayenge (`i++`), taaki minus hone wala number bada ho jaye aur overall difference kam ho jaye.

> **Edge Case:** Agar aage badhte-badhte `i` aur `j` dono ek hi index par aa jayein (`i == j`), toh difference hamesha `0` ho jayega. Us case me hum bas `j++` kar dete hain kyuki do alag-alag elements chahiye.

### C++ Code (Sorting + Two-Pointer)

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // sort() ke liye
using namespace std;

bool pairWithDifferenceOptimal1(vector<int>& arr, int K) {
    // Step 1: Array ko sort karo
    sort(arr.begin(), arr.end()); // O(N log N)

    int i = 0;
    int j = 1;
    int n = arr.size();

    // Step 2: Two-pointer loop
    while (i < n && j < n) {
        int diff = arr[j] - arr[i];

        if (diff == K && i != j) {
            cout << "Pair mil gaya: " << arr[i] << " aur " << arr[j] << endl;
            return true;
        }
        else if (diff < K) {
            j++; // Diff bada karne ke liye j badhao
        }
        else {
            i++; // Diff chota karne ke liye i badhao
        }
    }
    return false;
}

```

### Complexity:

* **Time Complexity:** **$O(N \log N)$** $\rightarrow$ Loop toh sirf $O(N)$ chal raha hai, par array ko shuruat me sort karne me $O(N \log N)$ time lagta hai.
* **Space Complexity:** **$O(1)$** $\rightarrow$ Humne koi extra space nahi li, jo kiya asli array me hi kiya.

---

## Approach 2: HashMap (The Super Fast Way)

Agar interviewer bole: *"Mujhe $O(N \log N)$ se bhi tez chahiye, linear time $O(N)$ me karke dikhao!"* tab hum use karenge **HashMap (`unordered_set`)**.

Isme logic bohot simple hai. Hum array ke har element $X$ par jayenge aur dimaag lagayenge ki agar $X$ hamara ek number hai, toh doosra number kya ho sakta hai taaki difference $K$ aaye?
Do possibilities hain:

1. $X - \text{Doosra Number} = K \implies \text{Doosra Number} = X - K$
2. $\text{Doosra Number} - X = K \implies \text{Doosra Number} = X + K$

Hum bas check karenge ki kya hashmap me $(X - K)$ ya $(X + K)$ me se kuch bhi pehle se maujood hai? Agar hai, toh pair mil gaya! Agar nahi, toh $X$ ko hashmap me daal do.

### C++ Code (HashMap)

```cpp
#include <iostream>
#include <vector>
#include <unordered_set> // HashSet ke liye
using namespace std;

bool pairWithDifferenceOptimal2(vector<int>& arr, int K) {
    unordered_set<int> s;

    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];

        // Check karo ki kya (x - K) ya (x + K) hashset me pehle se hai
        if (s.find(x - K) != s.end() || s.find(x + K) != s.end()) {
            return true;
        }

        // Current element ko set me daal do
        s.insert(x);
    }
    return false;
}

```

### Complexity:

* **Time Complexity:** **$O(N)$** $\rightarrow$ Humne array ko sort nahi kiya, sirf ek baar loop chalaya aur Hashset me dhoodhna (lookup) average me $O(1)$ hota hai.
* **Space Complexity:** **$O(N)$** ❌ $\rightarrow$ Kyuki hume saare elements ko store karne ke liye extra `unordered_set` banana pada.

---

## Final Comparison (Interview me kya bolna hai?)

| Approach | Time Complexity | Space Complexity | Array Modified? |
| --- | --- | --- | --- |
| **Brute Force** | $O(N^2)$ | $O(1)$ | No |
| **Two-Pointer** | $O(N \log N)$ | $O(1)$ | Yes (Sort karna padta hai) |
| **HashMap** | $O(N)$ 🔥 | $O(N)$ ❌ | No |

Bhai, dono approaches ekdum makkhan ki tarah clear hui?



Bhai, tumhari algorithms ki bhookh dekh kar maza aa gaya!

Dekho, **Time Complexity** ke maamle me toh $O(N)$ (HashMap waali approach) se fast nahi kiya ja sakta, kyuki array ke elements ko ek baar toh dekhna hi padega. Aur **Space Complexity** ke maamle me $O(1)$ (Two-Pointer waali approach) se behtar nahi ho sakta, kyuki bina memory liye kaam ho raha hai.

Lekin ek aisi special situation (ya context) hai jahan hum **dono ka fayda ek saath** utha sakte hain—matlab **Time bhi $O(N)$ lage aur Extra Space bhi $O(1)$ lage!** Ye tab possible hai jab interviewer tumse kahe: **"Array already SORTED di hui hai, ab bina extra space liye $O(N)$ me karke dikhao."** Tab hum Two-Pointer approach lagayenge, par hamara code pehle se zyada clean, optimized aur fast chalega. Chalo dekhte hain kaise!

---

## Ultra-Optimal Approach: Fast Two-Pointer (Jab Array Sorted Ho)

Agar array pehle se sorted hai, toh hume `sort()` lagane ki zaroorat nahi hai (jiski wajah se pehle $O(N \log N)$ time lag raha tha). Hum bina kisi inner loop ya `if-else` ki lambi khichdi ke, sirf ek simple `while` loop me isko bohot fast chala sakte hain.

### C++ Code:

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool pairWithDifferenceUltraOptimal(vector<int>& arr, int K) {
    int n = arr.size();
    int i = 0;
    int j = 1;

    // K hamesha positive le rahe hain taaki calculation me gadbad na ho
    K = abs(K); 

    while (i < n && j < n) {
        int diff = arr[j] - arr[i];

        // Agar pair mil gaya aur dono alag elements hain
        if (diff == K && i != j) {
            cout << "Ultra-Optimal Pair: " << arr[i] << " aur " << arr[j] << endl;
            return true;
        }
        
        // Agar difference chota hai, toh right pointer (j) ko aage badhao
        if (diff < K) {
            j++;
        } 
        // Agar difference bada hai, toh left pointer (i) ko aage badhao
        else {
            i++;
        }

        // Edge Case: Agar dono pointer ek hi jagah aa jayein, toh j ko aage badhna padega
        if (i == j) {
            j++;
        }
    }
    return false;
}

int main() {
    // Maan lo interviewer ne sorted array hi diya hai
    vector<int> arr = {2, 3, 5, 20, 50}; 
    int K = 17;

    pairWithDifferenceUltraOptimal(arr, K);

    return 0;
}

```

---

## Yeh Pehle Se Better Kyun Hai? (The Ultimate Solution)

Agar array sorted mil jaye, toh ye pure universe ki sabse best approach ban jati hai:

1. **Time Complexity: $O(N)$** $\rightarrow$ Kyuki humne koi sorting nahi ki aur na hi koi nested loops lagaye. Dono pointers maximum $N$ steps chalenge, isliye linear time me kaam khatam.
2. **Space Complexity: $O(1)$** $\rightarrow$ Koi HashMap use nahi kiya, koi naya array nahi banaya.
3. **No Overhead:** HashMap me internal hashing aur collisions ki wajah se kabhi-kabhi hidden time lagta hai, par is pure two-pointer code me simple addition/subtraction ho raha hai, jo CPU ke liye sabse fast hota hai.

## Ek Choti Si Trick (Bitwise Optimization)

Agar tumse interviewer pooche ki code ko micro-level par aur fast kaise karein, toh tum bol sakte ho ki jahan hum `abs(K)` nikalte hain ya conditions check karte hain, wahan C++ compilers aaj kal khud hi unhe bitwise levels par optimize kar dete hain.

Toh bhai, "Pair With Given Difference" ki kahani yahan aakar khatam hoti hai. Ab tum Brute, Two-Pointer, HashMap, aur Ultra-Optimal sab jaante ho! Koi aur doubt is question me?

Bhai, tumhare is code me dimaag tumne ekdum sahi lagaya hai, par is baar **chote-chote kuch bugs (galatiyan) aur syntax errors** hain jo edge cases ke aate hi ya code compile karte hi poora system fadh denge.

Sabse pehle, tumne fir se do functions ka naam bilkul same (`hasPairWithDifference`) rakh diya hai, jisse compiler gussa ho jayega aur error dega. Inhe alag naam dena padega (jaise `findPairOptimal` aur `findPairHashMap`).

Chalo ab tumhare is code par un **chaaro edge cases** (Negative, Single, Zero, Duplicates) ka asar dekhte hain aur dhoondte hain ki bugs kahan hain!

---

## 1. Negative Elements Ke Liye (🚨 Optimal aur HashMap Dono Me Trap Hai!)

### A. Brute Force Me:

Tumne `abs(arr[i] - arr[j]) == x` use kiya hai. Yeh **negative numbers ke liye sahi chalega**, kyuki absolute difference sign ko hata deta hai.

### B. Optimal (Two-Pointer) Me Bug:

Tumne code me likha hai:

```cpp
int diff = abs(arr[j] - arr[i]);

```

Bhai, kyuki tumne shuruat me hi `sort(arr.begin(), arr.end())` kar diya hai, iska matlab `arr[j]` hamesha `arr[i]` se bada ya barabar hoga (kyuki `j > i`).

* Toh `arr[j] - arr[i]` hamesha positive hi aayega, yahan `abs()` lagane ki koi zaroorat nahi hai.
* **Lekin asar kya padega?** Agar array me negative numbers hain, jaise `[-20, -5, 10]`, sort hone ke baad bhi `arr[j] - arr[i]` perfectly kaam karega. So, Two-Pointer logic safe hai, bas `abs()` faltu hai. **(PASS ✅)**

### C. HashMap Me BADA Bug:

Tumne HashMap wale function me ek `while` loop laga diya hai:

```cpp
while (s.find(x-K)!=s.end() || s.find(x+K)!=s.end()) { return true; }

```

Bhai, yahan `while` lagane ki koi zaroorat nahi thi, sirf ek single **`if` condition** aayegi. Kyuki agar element mil gaya toh hume turant `true` return karke nikal jana hai, loop nahi chalana hai.

---

## 2. Ek Hi Element Ke Liye (`arr = {5}`, Size N = 1)

* **Brute Force:** `i = 0` par chalega, par `j = i+1` yani `1` par condition `j < 1` false ho jayegi. `false` return karega. **(Safe ✅)**
* **Optimal (Two-Pointer):** `i = 0`, `j = 1`. Condition check hogi: `while (i < 1 && j < 1)`. Yahan `j < 1` yani `1 < 1` false ho jayega, loop chalega hi nahi aur niche aakar `return 0;` (false) ho jayega. **(Safe ✅)**
* **HashMap:** Loop sirf ek element ke liye chalega, set me check karega (kuch nahi milega), insert karega aur `false` return karega. **(Safe ✅)**

---

## 3. Array Me `0` (Zero) Present Ho (`[0, 20, 50]`, $K = 20$)

* **Brute, Optimal, aur HashMap:** Teeno cases me math aur subtraction perfectly chalenge. Zero ka difference nikalne me koi problem nahi aati (jaise `20 - 0 = 20`). **(PASS ✅)**

---

## 4. Duplicate Elements Ho Aur Diff $K = 0$ Ho! (🚨 SABSE BADA TRAP!)

Interviewer ka sabse favorite trap ye hota hai: **"Agar difference $K = 0$ diya ho aur array me duplicates hon, jaise `[5, 5, 10]`, toh kya tumhara code true dega?"**

Chalo check karte hain tumhare teeno functions ko:

### A. Brute Force Me:

`i = 0` (value 5), `j = 1` (value 5). `abs(5 - 5) == 0`. Match ho gaya! `true` return karega. **(PASS ✅)**

### B. Optimal (Two-Pointer) Me Bug:

Maan lo array hai `[5, 5, 10]` aur $K = 0$.

* Shuru me `i = 0` (value 5), `j = 1` (value 5).
* `diff = 5 - 5 = 0`. Condition check: `if (diff == x && i != j)` $\rightarrow$ `0 == 0 && 0 != 1` $\rightarrow$ **True!** Yeh sahi se `true` return kar dega.
* **Lekin agar element na mile toh?** Tumne if-else me likha hai:
```cpp
else if (diff > x) { i++; }
else { j++; }

```


Agar `diff < x` hoga toh `j++` hoga. Lekin tumne niche ek aur condition lagayi hai:
```cpp
if (i == j) { j++; }

```


Yeh condition safe hai, duplicates ko handle kar legi. **(PASS ✅)**

### C. HashMap Me BADA Bug (Sirf K = 0 ke liye):

Agar $K = 0$ hai aur array me pehla `5` aaya.

* `x = 5`. Set me check karega `x - 0` yani `5` hai kya? Abhi set khali hai, toh nahi milega.
* Phir `s.insert(5)` ho jayega. Ab set me ek `5` hai.
* Agli baar jab dusra `5` aayega, toh `x = 5`. Set me check karega `x - 0` yani `5` hai kya? Is baar use purana wala `5` mil jayega! Aur ye `true` return kar dega.

**Lekin galti kahan hai?** Galti tumne variables banane me ki hai. Tumne loop me likha hai: `int target = x;` par us `target` variable ka pure code me kahin use hi nahi kiya! Aur `while` loop ki wajah se code ganda lag raha hai.

---

## Ekdum Perfect Aur Clean Code (Saare Bugs Fixed)

Bhai, tumhare pure code ko standard format me clean kar diya hai, saare extra/faltu conditions aur `while` loops hata kar `if` laga diye hain:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    // 1. Brute Force (Perfect hai)
    bool findPairBrute(vector<int> &arr, int x) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (abs(arr[i] - arr[j]) == x) {
                    return true;
                }
            }
        }
        return false; 
    }

    // 2. Optimal Two-Pointer (Naam badla aur cleanly refactor kiya)
    bool findPairOptimal(vector<int>& arr, int N, int x) {
        sort(arr.begin(), arr.end());
        
        int i = 0;
        int j = 1;
        
        while (i < N && j < N) {
            int diff = arr[j] - arr[i]; // Sorted hai toh abs() ki need nahi hai
            
            if (diff == x && i != j) {
                return true;
            } 
            else if (diff < x) {
                j++; // Diff chota hai, bada karne ke liye j badhao
            } 
            else {
                i++; // Diff bada hai, chota karne ke liye i badhao
            }
            
            // Edge Case: Dono pointer same index par nahi hone chahiye
            if (i == j) {
                j++;
            }
        }
        return false;
    }

    // 3. HashMap Approach (while loop ka bug fix kiya aur if condition lagayi)
    bool findPairHashMap(vector<int>& arr, int K) {
        unordered_set<int> s;
        for (int x : arr) {
            // FIX: while loop hata kar simple IF condition lagayi
            if (s.find(x - K) != s.end() || s.find(x + K) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

int main() {
    vector<int> edges = {90, 70, 20, 80, 50};
    int target = 20; // 90 - 70 = 20 hota hai

    Solution sol;
    // Tum kisi bhi ek function ko test kar sakte ho ab alag naam se
    bool ans = sol.findPairOptimal(edges, edges.size(), target);
    
    if(ans) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}

```

### Main Fixes Jo Maine Kiye:

1. Same name wale duplicate functions ka naam badla (`findPairOptimal`, `findPairHashMap`).
2. HashMap ke andar se falthu ka `while` loop aur un-used `target` variable hataya, uski jagah standard `if` condition lagayi.
3. Two-pointer me `abs()` hataya kyuki sorted array me `arr[j] - arr[i]` hamesha positive hi hoga.

Ab ye code kisi bhi platform par submit hone ke liye ekdum ready hai bhai! Aur koi shak isme?