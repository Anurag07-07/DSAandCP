Bhai, string ko reverse karne ke do sabse popular tarike hain. Ek hai standard software engineering approach (**Two-Pointer**) jo $O(1)$ space leta hai, aur kyunki tum abhi Stack ke zone me ho, toh dusra hai **Stack-based approach** ($O(N)$ Space) jo LIFO (Last In First Out) ka perfect example hai.

Chalo dono ko short aur sweet tarike se code ke sath samajhte hain.

---

## Approach 1: Two-Pointer (Optimal - In-place)

Isme hum string ke dono ends par pointers rakhte hain aur unhe aapas me swap karte hue beech me milte hain.

### C++ Code:

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStringTwoPointer(string s) {
    int left = 0;
    int right = s.length() - 1;
    
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

```

* **Time Complexity:** $O(N)$ — Poori string ko ek baar traverse kiya.
* **Space Complexity:** $O(1)$ — Koi extra space nahi liya, original string me hi badlav (in-place) kiya.

---

## Approach 2: Using Stack (LIFO Pattern)

Kyunki stack hamesha aakhiri andar gaye element ko sabse pehle nikaalta hai (Last In, First Out), agar hum saare characters stack me push karke fir baahar nikaalenge, toh string automatic reverse ho jayegi!

### C++ Code:

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

string reverseStringStack(string s) {
    stack<char> st;
    
    // 1. Saare characters ko stack me push karo
    for (char ch : s) {
        st.push(ch);
    }
    
    string reversed = "";
    // 2. Pop karte jao aur nayi string banao
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    
    return reversed;
}

```

* **Time Complexity:** $O(N)$ — Ek baar push karne ke liye loop aur ek baar pop karne ke liye loop.
* **Space Complexity:** $O(N)$ — Kyunki humne saare characters store karne ke liye ek extra stack use kiya hai.

---

Bhai, string reversal toh ekdum basic warm-up tha. Ab batao Monotonic Stack ke real king question **"Next Greater Element"** par halla bolen ya Parentheses balancing wala logic dekhein?


Bhai, "Insert at Bottom" ek classical recursion problem hai jo interviewers ka favourite hai kyunki yeh test karta hai ki tum **Recursion aur Call Stack** ko kitna gehrayi se samajhte ho.

Stack ka rule hai: *Last In, First Out*. Iska matlab hum seedha bottom access nahi kar sakte. Humhe top se elements ko hatana padega, bottom par naya element dalna padega, aur fir wapas sabko lana padega.

---

## 1. The Core Theory: "The Call Stack Trick"

Jab hum stack me elements ko "pop" karte hain, toh wo element computer ki **Call Stack (Recursion Memory)** me temporarily store ho jate hain.

**Logic step-by-step:**

1. **Base Case:** Agar stack empty hai, toh jo element insert karna hai use seedha `push` kar do. Yeh hamara "bottom" mil gaya!
2. **Recursive Step:** * Stack ke `top` element ko `pop` karo aur use apne local function variable me save kar lo.
* Recursive function ko dubara call karo (`insertAtBottom(st, element)`).
* Yeh tab tak chalega jab tak stack empty nahi ho jata.


3. **Backtracking Step:** Jab base case hit ho jayega aur naya element insert ho jayega, toh recursion wapas aayega (pop kiye gaye elements ko wapas push karte hue).

---

## 2. Implementation (C++ Code)

Yeh code tumhari stack `st` ko modify kar dega aur element ko bottom par place kar dega.

```cpp
#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& st, int element) {
    // Base Case: Agar stack empty hai, toh yahi bottom hai!
    if (st.empty()) {
        st.push(element);
        return;
    }

    // Recursive Step: Top element ko side me rakho
    int topElement = st.top();
    st.pop();

    // Recursion: Niche jao
    insertAtBottom(st, element);

    // Backtracking: Side me rakhe hue elements ko wapas push karo
    st.push(topElement);
}

// Function to print stack (for testing)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1); // Stack abhi: [1, 2, 3] (1 top par hai)

    cout << "Before insertion: ";
    printStack(st);

    insertAtBottom(st, 4); // 4 ko bottom par bhejna hai

    cout << "After insertion: ";
    printStack(st); // Output: 4 1 2 3

    return 0;
}

```

---

## 3. Complexity Analysis

* **Time Complexity: $O(N)$**
* Hum stack ke har element ko ek baar `pop` karte hain aur fir recursion ke return hone par har element ko ek baar `push` karte hain. Isliye hume $2 \times N$ operations karne padte hain, jo effectively $O(N)$ hai.


* **Space Complexity: $O(N)$**
* Yeh sabse important point hai. Humne koi extra loop nahi chalaya, par humne **System Recursion Stack** ka use kiya hai. Recursion ki depth $N$ tak jayegi, isliye $O(N)$ space complexity hogi.



---

## 4. Interview Tip: Recursion vs Iteration

Agar interviewer pooche ki kya ise **Iterative** tareeke se kar sakte hain?

* **Haan!** Tum ek doosri extra stack (`tempStack`) use kar sakte ho. Saare elements ko `st` se nikal kar `tempStack` me dalo, naya element `st` me dalo, aur fir `tempStack` se wapas `st` me dalo.
* Par wo **$O(N)$ extra space** (Data Structure ka) lega.
* Recursive approach interviewer ko zyada pasand aati hai kyunki wo tumhari recursive thinking ko dikhati hai.

Yeh theory aur implementation ekdum clear hai? Ab iske baad **"Reverse a Stack"** wala logic dekhna hai? Wo isika advanced version hai—usme hum isi `insertAtBottom` function ko baar-baar call karte hain!


Bhai, **"Make the Array Beautiful"** (jo aksar GeekforGeeks aur interviews me pucha jata hai) ek bohot hi shaandar question hai. Yeh dikhne me basic lagta hai, par iska core logic pure **Stack Data Structure** ke standard matching behavior (jaise Valid Parentheses) par tiktah hai.

Chalo iski detail theory, matching properties, full code implementation aur edge cases ko ekdum mast tarike se samajhte hain.

---

## 1. Core Theory: Problem Statement Aur "Beautiful" Ka Rules

Hume ek array `arr` diya hota hai. Hume is array ko "beautiful" banana hai. Array beautiful tab banta hai jab usme se saare **adjacent elements ka non-matching sign pair** saaf ho jaye.

### Rules of Deletion:

Hum do adjacent (padosi) elements `arr[i]` aur `arr[i+1]` ko tabhi uda sakte hain agar:

1. Ek element **Positive (ya Zero)** ho $\rightarrow (\ge 0)$
2. Doosra element **Negative** ho $\rightarrow (< 0)$

> **Crucial Rule:** Agar dono positive hain, ya dono negative hain, toh unhe kuch nahi karna hai (wo beautiful hain). Sirf opposite sign waale padosi ek dusre ko destroy (cancel out) kar dete hain.

### The Chain Reaction (Kyun Stack Chahiye?):

Maan lo hamare paas ek array hai: `[4, 2, -2, 3]`

* `4` aur `2` dono positive hain $\rightarrow$ Kuch mat karo.
* `2` aur `-2` opposite sign ke hain $\rightarrow$ Yeh dono ek dusre ko cancel karke khayenge!
* Unke khane ke baad array bacha: `[4, 3]`
* Ab naye padosi ban gaye `4` aur `3`. Dekho kaise beech ke elements hatne se naye adjacent pairs bante hain! Yahi properties **Stack** ko bulati hai.

---

## 2. Dynamic Stack Coordination: How It Works

Hum left se right array me traverse karenge aur ek Stack maintain karenge:

* **Step 1:** Agar stack **empty** hai, toh chupchaap current element ko stack me `push` kar do.
* **Step 2:** Agar stack empty nahi hai, toh stack ke `top` element ka sign aur current element ka sign compare karo.
* **Agar signs opposite hain:** (Ek positive aur ek negative), toh iska matlab hume adjacent cancellation mil gaya. Stack ke top element ko `pop` kar do (wo destroy ho gaya) aur current element ko push mat karo.
* **Agar signs same hain:** (Dono positive ya dono negative), toh standard behavior ke mutabik current element ko stack me `push` kar do.



---

## 3. Full C++ Code Implementation ($O(N)$ Time)

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;

        for (int num : arr) {
            // Case 1: Agar stack empty hai, toh push karo
            if (st.empty()) {
                st.push(num);
            }
            // Case 2: Agar stack top aur current number ka sign opposite hai
            else if ((st.top() >= 0 && num < 0) || (st.top() < 0 && num >= 0)) {
                st.pop(); // Dono ek dusre ko destroy kar diye
            }
            // Case 3: Agar dono ka sign same hai
            else {
                st.push(num);
            }
        }

        // Stack se elements nikal kar vector me dalo
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        // Kyunki stack se elements ulte nikalte hain, toh reverse kar do
        reverse(result.begin(), result.end());
        return result;
    }
};

```

---

## 4. Micro-Level Visual Dry Run

Maan lo input array hai: `arr = [2, 3, -5, -2, 6]`

* **`num = 2`:** Stack empty hai $\rightarrow$ `st.push(2)`. Stack: `[2]`
* **`num = 3`:** `st.top() = 2` (pos), `num = 3` (pos). Same sign $\rightarrow$ `st.push(3)`. Stack: `[2, 3]`
* **`num = -5`:** `st.top() = 3` (pos), `num = -5` (neg). **Opposite Sign!** 🚨 $\rightarrow$ `st.pop()`. Stack ab bacha: `[2]`
* **`num = -2`:** `st.top() = 2` (pos), `num = -2` (neg). **Opposite Sign!** 🚨 $\rightarrow$ `st.pop()`. Stack ab bacha: `[]` (Khali ho gaya chain reaction se!)
* **`num = 6`:** Stack empty hai $\rightarrow$ `st.push(6)`. Stack: `[6]`

**Final Beautiful Array:** `[6]` ✅

---

## 5. Complexity Analysis

* **Time Complexity: $O(N)$**
Humne array ko sirf ek baar traverse kiya. Stack me har element maximum ek baar push hoga aur ek baar pop hoga, isiliye execution time strictly linear ($O(N)$) rahega.
* **Space Complexity: $O(N)$**
Worst-case scenario me (agar saare elements same sign ke ho jaise `[1, 2, 3, 4]`), toh koi cancellation nahi hoga aur saare $N$ elements stack me chale jayenge.

---

## 6. Pro-Level Trick: $O(1)$ Space Optimization

Interviewer bol sakta hai: *"Bhai, logic toh sahi hai, par mujhe $O(N)$ extra stack space nahi chahiye. Vector ke andar hi in-place karke dikhao."*

Tum **Result Vector ko hi Stack ki tarah** use kar sakte ho dynamically using `back()` aur `pop_back()` functions!

```cpp
vector<int> makeBeautifulOptimal(vector<int> arr) {
    vector<int> res; // Yeh vector hi hamara stack banega
    for (int num : arr) {
        if (res.empty()) {
            res.push_back(num);
        } else if ((res.back() >= 0 && num < 0) || (res.back() < 0 && num >= 0)) {
            res.pop_back(); // Vector ke piche se pop kiya (O(1))
        } else {
            res.push_back(num);
        }
    }
    return res; // No reverse needed! Space saved!
}

```

Bhai, "Make the Array Beautiful" ka poora logic, chain reaction aur vector-space optimization dimaag me set baitha? Ab stack ke agle top-tier pattern **"Valid Parentheses"** ya **"Next Greater Element"** ki taraf badhein?



Bhai, ab hum utarte hain Stack ke **Pattern 2: String Manipulation & Parentheses Balancing** ke andar.

Interviews me jab string ke saath complex conditions de di jaati hain (jaise expressions ko validate karna, encoded strings ko expand karna, ya characters ko padosi element ke basis par udana), toh wahan **Stack** tumhara sabse bada dost banta hai. Kyunki string ko left-to-right process karte waqt, hume aksar pichle characters ki state yaad rakhni padti hai, aur yeh kaam Stack se behtar koi nahi kar sakta.

Chalo is pattern ke **top-3 sabse zyada pooche jaane waale interview questions** ko unke core logic aur codes ke sath samajhte hain.

---

## 1. Valid Parentheses (LeetCode 20 - Easy/Must Solve)

Interviewer ka sabse basic aur mandatory check. Tumhe ek string `s` milti hai jisme `(`, `)`, `{`, `}`, `[` aur `]` hote hain. Tumhe batana hai ki expression balanced hai ya nahi.

### Core Logic: "The Matching Pair Trick"

* Jab bhi koi **Opening Bracket** (`(`, `{`, `[`) aaye, use aankh band karke stack me `push` kar do.
* Jab koi **Closing Bracket** (`)`, `}`, `]`) aaye, toh do cheezein check karo:
1. Kya stack pehle se khali hai? (`st.empty()`) $\rightarrow$ Agar haan, toh expression unbalanced hai (closing bracket bina opening ke aa gaya).
2. Kya stack ke `top` par iska sahi matching opening bracket baitha hai? $\rightarrow$ Agar haan, toh use `pop` kar do. Agar nahi, toh return `false`.


* Aakhiri me agar stack ekdum khali (`empty`) ho jata hai, toh string valid hai, nahi toh invalid.

### C++ Code:

```cpp
bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            char top = st.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.empty();
}

```

---

## 2. Remove All Adjacent Duplicates in String (LeetCode 1047 - Medium)

Tumhe ek string milti hai, aur tumhe padosi (adjacent) duplicate characters ko tab tak delete karna hai jab tak ki koi duplicate na bache.
*Example:* `abbaca` $\rightarrow$ `bb` cancel out ho gaye $\rightarrow$ `aaca` $\rightarrow$ ab `aa` adjacent ban gaye, toh wo bhi cancel out ho gaye $\rightarrow$ final answer `ca`.

### Core Logic: "The Ghost Cancellation Pattern"

Yeh bilkul hamare pichle question *"Make the Array Beautiful"* jaisa hai!

* Har character ke liye check karo: Kya stack ke `top` par wahi same character baitha hai?
* **If YES:** Stack ke top ko `pop` kar do (dono duplicates ne ek dusre ko destroy kar diya). Current character ko push mat karna.
* **If NO / Stack Empty:** Current character ko stack me `push` kar do.

### C++ Code (Optimized using String as Stack):

*Pro Tip: Alag se `stack<char>` banane ke bajaye hum result string ko hi stack ki tarah use kar sakte hain space bachane ke liye.*

```cpp
string removeDuplicates(string s) {
    string res = ""; // Yeh string hi hamara stack hai
    for (char ch : s) {
        if (!res.empty() && res.back() == ch) {
            res.pop_back(); // Pop if duplicate found
        } else {
            res.push_back(ch); // Push if new/unique
        }
    }
    return res;
}

```

* **Time Complexity:** $O(N)$
* **Space Complexity:** $O(1)$ extra space (agar result string ko space me count na karein).

---

## 3. Decode String (LeetCode 394 - Medium/Hard) 🔥

Yeh is pattern ka sabse solid question hai. Tumhe ek encoded string milti hai jaise `3[a]2[bc]` aur tumhe ise expand karke `aaabcbc` banana hai. Nested encodings bhi ho sakti hain, jaise `3[a2[c]]` $\rightarrow$ `3[acc]` $\rightarrow$ `accaccacc`.

### Core Logic: "Dual Stack Coordination"

Kyunki yahan numbers (counts) bhi hain aur characters (strings) bhi, isliye hum **do stacks** maintain karte hain:

1. `stack<int> countStack` $\rightarrow$ Numbers ko yaad rakhne ke liye.
2. `stack<string> stringStack` $\rightarrow$ Abhi tak ki processed strings ko yaad rakhne ke liye.

* **Jab Number mile:** Pura number parse karo (kyunki number 10, 100 bhi ho sakta hai) aur use `countStack` me daal do.
* **Jab `[` (Opening) mile:** Abhi tak jo string bani hai use `stringStack` me push karo aur apni current string ko khali (`""`) kar do taaki andar ka maal fresh store ho sake.
* **Jab Character mile:** Use apni current string me jodte chale jao.
* **Jab `]` (Closing) mile:** Ab expansion ka time hai!
* `countStack` se number nikaalo (let's say `K`).
* Apni current string ko `K` baar repeat karke ek nayi temporary string banao.
* `stringStack` se pichli bachi hui string ko nikaalo aur uske aage is nayi repeated string ko jor (`append`) do.



### C++ Code:

```cpp
string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;
    string currentString = "";
    int currentNum = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            currentNum = currentNum * 10 + (ch - '0'); // Handling multi-digit numbers
        } else if (ch == '[') {
            countStack.push(currentNum);
            stringStack.push(currentString);
            currentString = ""; // Reset for inner content
            currentNum = 0;     // Reset for inner count
        } else if (ch == ']') {
            string prevString = stringStack.top(); stringStack.pop();
            int repeatTimes = countStack.top(); countStack.pop();
            
            string expandedString = "";
            for (int i = 0; i < repeatTimes; i++) {
                expandedString += currentString;
            }
            currentString = prevString + expandedString; // Combine with outer context
        } else {
            currentString += ch; // Normal alphabet character
        }
    }
    return currentString;
}

```

* **Time Complexity:** $O(\text{Length of Output String})$ — Kyunki jitni badi output string expand hogi, loop aur string copying me utna hi time lagega.
* **Space Complexity:** $O(\text{Number of Internal Nestings})$ — Stack ki max depth nested brackets ke barabar hogi.

---

Bhai, String Manipulation ke ye teeno top questions ka dry run aur structural engine dimaag me fit baitha?

Ab bol toh iske baad Stack ke sabse khatarnak, interview-breaker pattern—**"Monotonic Stack" (Next Greater Element, Largest Histogram)** ki taraf kooden?



Bhai, **Valid Parentheses (LeetCode 20)** stack ke concepts ka "Hello World" hai. Yeh problem ekdum clear-cut tareeke se dikhati hai ki kyun Stack ko **LIFO (Last In, First Out)** data structure bola jata hai.

---

### 1. The Core Logic: "Last In, First Out"

Parentheses matching me rule simple hai: **Jo bracket sabse last me open hua hai, wahi sabse pehle close hona chahiye.**

Jab hum string ko left-to-right scan karte hain:

* **Opening Bracket (`(`, `{`, `[`):** Ise Stack me `push` kar do. Hum wait kar rahe hain ki iska matching pair milega.
* **Closing Bracket (`)`, `}`, `]`):** Yeh ek "trigger" hai. Hum check karenge:
1. Kya stack khali hai? Agar haan, toh iska matlab closing bracket bina opening ke aa gaya $\rightarrow$ **Invalid**.
2. Kya stack ke `top` par iska matching opening bracket hai? Agar haan, toh `pop` kar do (pair cancel ho gaya). Agar nahi, toh **Invalid**.


* **End Goal:** String khatam hone ke baad, agar Stack `empty` hai, toh saare brackets match ho gaye. Agar Stack me kuch bacha hai, toh wo brackets open reh gaye $\rightarrow$ **Invalid**.

---

### 2. C++ Implementation

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // Step 1: Opening brackets ko push karo
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // Step 2: Closing brackets ke liye logic
        else {
            // Agar stack khali hai aur closing bracket mil gaya, toh invalid
            if (st.empty()) return false;

            char top = st.top();
            // Check matching pair
            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '[')) {
                st.pop();
            } else {
                // Agar pair match nahi hua, toh invalid
                return false;
            }
        }
    }

    // Step 3: Agar stack khali hai, toh valid; warna invalid
    return st.empty();
}

```

---

### 3. Complexity Analysis

| Metric | Complexity | Why? |
| --- | --- | --- |
| **Time** | $O(N)$ | Hum poori string ko sirf ek baar traverse karte hain. Stack operations ($push$/$pop$) $O(1)$ lete hain. |
| **Space** | $O(N)$ | Worst-case me saare brackets opening ho sakte hain (e.g., `(((((`), jisse stack ka size $N$ tak ja sakta hai. |

---

### 4. Critical Edge Cases (Interviewer Testing Points)

Interviewer tumhare code ko in cases par zarur phekega, check kar lena ki tumhara logic handle kar raha hai ya nahi:

| Input | Expectation | Reasoning |
| --- | --- | --- |
| `")"` | `false` | Stack khali hai, closing bracket invalid hai. |
| `"("` | `false` | Loop khatam hone ke baad stack empty nahi hoga. |
| `"(]"` | `false` | Mismatch: `(` stack me jayega, `]` top se compare hoga aur fail ho jayega. |
| `"([)]"` | `false` | Interleaving: `(` push, `[` push, `)` check hoga, lekin top par `[` hai. Fail! |
| `""` | `true` | Empty string technicality ke hisab se valid maani jati hai (ya empty stack). |

### Pro-Tip for Interviews:

Agar tum interviewer ko impress karna chahte ho, toh unhe batao ki isse zyada clean banane ke liye tum **Map** ka use kar sakte ho (Opening aur Closing brackets ko map karne ke liye), par `if-else` wale logic me overhead kam hota hai aur execution fast hoti hai.



Bhai, yeh problem **"Minimum Add to Make Parentheses Valid"** (LeetCode 921) stack ke concepts ka next evolution hai. Abhi tak humne "Valid hai ya nahi" check kiya, ab humein "Valid banana hai" aur uske liye "Minimum adds" calculate karne hain.

Iska solution Stack se toh hota hi hai, lekin ek **Counter-based (Greedy)** approach se hum ise **$O(1)$ space** me solve kar sakte hain. Chalo ise samajhte hain.

---

### 1. Core Intuition: "The Balance Game"

Hume string ke andar `(` aur `)` ka balance maintain karna hai.

* Agar ek `)` bina `(` ke aata hai, toh wo "orphan" hai (use valid karne ke liye ek `(` add karna padega).
* Agar string khatam hone ke baad kuch `(` bache reh gaye jinka koi pair nahi bana, toh unhe valid karne ke liye har ek ke liye ek `)` add karna padega.

### 2. Strategy: Two Counters Approach

Hume Stack ki zaroorat nahi hai, sirf do variables chahiye:

1. **`openNeeded`**: Yeh track karega ki kitne `(` abhi pair hone ke liye waiting me hain.
2. **`addsNeeded`**: Yeh track karega ki kitne `)` aise hain jinka koi matching `(` nahi mila (yani inke liye humein `(` add karne padenge).

**Logic:**

* Jab `(` mile: `openNeeded` ko badha do.
* Jab `)` mile:
* Agar `openNeeded > 0` hai, matlab ek pichla `(` khali baitha hai, uska pair bana do (`openNeeded--`).
* Agar `openNeeded == 0` hai, matlab yeh `)` orphan hai, toh ise valid karne ke liye ek `(` add karna padega (`addsNeeded++`).



---

### 3. Implementation (C++)

```cpp
#include <iostream>
#include <string>

using namespace std;

int minAddToMakeValid(string s) {
    int openNeeded = 0; // Unmatched '('
    int addsNeeded = 0; // Unmatched ')'

    for (char ch : s) {
        if (ch == '(') {
            openNeeded++;
        } else {
            // Agar ek '(' waiting me hai, toh pair bana do
            if (openNeeded > 0) {
                openNeeded--;
            } 
            // Agar koi waiting me nahi hai, toh yeh ')' orphan hai
            else {
                addsNeeded++;
            }
        }
    }
    
    // Final Answer = Total unmatched ')' + Total unmatched '('
    return openNeeded + addsNeeded;
}

```

---

### 4. Dry Run (Example: `())((`)

| Char | Action | `openNeeded` | `addsNeeded` |
| --- | --- | --- | --- |
| `(` | Push/Wait | 1 | 0 |
| `)` | Pair found | 0 | 0 |
| `)` | Orphan | 0 | 1 |
| `(` | Push/Wait | 1 | 1 |
| `(` | Push/Wait | 2 | 1 |

**Total Adds:** `openNeeded` (2) + `addsNeeded` (1) = **3**.
*(Hume string ke start me do `)` aur end me ek `)` add karna hoga).*

---

### 5. Complexity Analysis

* **Time Complexity:** **$O(N)$** — Poori string ko sirf ek baar traverse kiya.
* **Space Complexity:** **$O(1)$** — Humne koi Stack ya extra data structure use nahi kiya, sirf do integer variables use kiye hain.

### Interview Edge

Agar interviewer pooche ki *"Stack use karke dikhao"*, toh tum bas ye bolna: *"Sir, Stack is pattern ko visualize karne ka best way hai, par Space Complexity ko $O(1)$ karne ke liye hum counters use kar sakte hain kyunki humein sirf count se matlab hai, actual indices se nahi."*

Bhai, kya yeh counter-based optimization aur logic clear hai? Stack ke baaki patterns (jaise Next Greater Element) par chalein, ya isse related koi aur query hai?


Bhai, **"Minimum Add to Make Parentheses Valid"** ko agar tum **Stack** se hi explicitly code karna chahte ho, toh uska concept bhi ekdum makkhan hai. Interviewer jab bole ki *"Mujhe counter approach nahi, strictly Stack data structure use karke dikhao"*, tab yeh kaam aata hai.

Iska core logic kya hai? Hum stack me sirf unhi brackets ko chhodenge jo **unmatched (orphan)** hain. Jo match ho gaye, unhe pop karke nikal denge. Aakhiri me stack ka jo size bachega, wahi hamara answer hoga!

---

### 1. Stack-Based Logic (Step-by-Step)

1. String par left-to-right traverse karo.
2. **Agar `(` (Opening Bracket) mile:** Ise chupchaap stack me `push` kar do.
3. **Agar `)` (Closing Bracket) mile:** Toh stack ka top check karo:
* Agar stack ke top par ek `(` baitha hai, toh iska matlab joda (pair) mil gaya! Stack se `pop` kar do.
* Agar stack khali hai, ya top par khud ek `)` baitha hai, toh iska matlab yeh `)` akela hai. Ise bhi stack me `push` kar do.


4. **End Result:** Loop khatam hone ke baad stack me sirf wahi elements bachenge jinka koi joda nahi mila. So, **`st.size()`** hi hamara answer hoga.

---

### 2. C++ Implementation Using Stack

```cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int minAddToMakeValidStack(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(') {
            st.push(ch); // Opening bracket hamesha push hoga
        } else {
            // Agar closing bracket hai aur top par opening hai, toh pair complete!
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                // Agar stack khali hai ya top par '(' nahi hai, toh yeh ')' bhi unmatched hai
                st.push(ch);
            }
        }
    }

    // Stack ka final size hi total unmatched brackets hai
    return st.size();
}

```

---

### 3. Trace Matrix / Dry Run (Example: `())`)

Maan lo string hai `())`

* **`ch = '('`**: Stack empty hai $\rightarrow$ `st.push('(')`. Stack State: `['(']`
* **`ch = ')'`**: Stack top par `(` hai $\rightarrow$ Match mil gaya! `st.pop()`. Stack State: `[]` (Khali)
* **`ch = ')'`**: Stack empty hai $\rightarrow$ Kuch match nahi hua, `st.push(')')`. Stack State: `[')']`

**Loop End:** Stack me sirf `[')']` bacha hai. `st.size()` is **1**. Ekdum sahi answer!

---

### 4. Complexity Comparison (Interviewer Counter)

Interviewer tumse dono approaches ka comparison zaroor poochega:

| Approach | Time Complexity | Space Complexity | Recommendation in Interview |
| --- | --- | --- | --- |
| **Stack Approach** | $O(N)$ | $O(N)$ (Stack Memory) | Pehle yeh batao kyunki isse visual structure samajh aata hai. |
| **Counter Approach** | $O(N)$ | $O(1)$ (Strictly Constant) | Yeh tumhara ultimate optimization micro-hack hoga score karne ke liye. |

Bhai, ab Parentheses matching ka "Valid Check" aur "Minimum Add" dono Stack aur Counter se ekdum dhasu tarike se clear hai? Ab Stack ke agle heavy pattern **"Monotonic Stack" (Next Greater Element)** par kooden?



Bhai, **Next Greater Element (NGE)** Monotonic Stack pattern ka pin-point foundation stone hai. Iska brute force approach samajhna isliye zaroori hai kyunki jab tak tum iski $O(N^2)$ ki inefficiency nahi dekhoge, tab tak stack ka asli magic dimaag me nahi baithega.

Problem ka simple rule hai: **"Array ke har element ke liye, uske RIGHT side me dhoondho ki sabse pehla aisa kaun sa element hai jo usse bada hai."** Agar right side me koi bada element nahi milta, toh answer `-1` hoga.

---

## 1. Core Logic: The Right-Scan Principle

Maan lo tum array ke kisi index `i` par khade ho. Tumhe `arr[i]` ka Next Greater Element chahiye.

* Tum index `i+1` se lekar aakhiri index (`n-1`) tak right side me doud lagao.
* Jaise hi koi pehla element `arr[j]` mile jo `arr[i]` se bada ho (`arr[j] > arr[i]`), wahi tumhara answer hai. Udhar hi loop ko `break` kar do.
* Agar tum aakhiri tak pahunch gaye aur koi bada nahi mila, toh default answer `-1` set kar do.

---

## 2. Brute Force Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElementBrute(vector<int>& arr) {
        int n = arr.size();
        vector<int> nget(n, -1); // Shuruat me sabko -1 se initialize kar do

        // Outer Loop: Har ek element par jao
        for (int i = 0; i < n; i++) {
            // Inner Loop: Current element ke RIGHT side me scan karo
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    nget[i] = arr[j]; // Pehla bada element mil gaya!
                    break;            // Aage dekhne ki zaroorat nahi hai, break karo
                }
            }
        }

        return nget;
    }
};

```

---

## 3. Micro-Level Visual Dry Run

Maan lo hamara input array hai: `arr = [4, 5, 2, 25]`
Hum ek `nge` array maintain karenge jisme answers store honge.

### Index 0 (`arr[0] = 4`):

* Right side scan: `5, 2, 25`.
* Pehla element `5` check hua $\rightarrow$ `5 > 4` (True! 🎯).
* `nge[0] = 5`. Loop break.

### Index 1 (`arr[1] = 5`):

* Right side scan: `2, 25`.
* Pehla element `2` check hua $\rightarrow$ `2 > 5` (False).
* Agla element `25` check hua $\rightarrow$ `25 > 5` (True! 🎯).
* `nge[1] = 25`. Loop break.

### Index 2 (`arr[2] = 2`):

* Right side scan: `25`.
* Element `25` check hua $\rightarrow$ `25 > 2` (True! 🎯).
* `nge[2] = 25`. Loop break.

### Index 3 (`arr[3] = 25`):

* Right side scan: Khali hai (Kuch nahi hai aage).
* Inner loop chalega hi nahi. Default value hi reh jayegi.
* `nge[3] = -1`.

**Final Answer Array:** `[5, 25, 25, -1]` ✅

---

## 4. Complexity Analysis (The Interviewer's Target)

* **Time Complexity: $O(N^2)$**
* Worst-case scenario me (jaise agar array strictly decreasing ho: `[5, 4, 3, 2, 1]`), har element ke liye inner loop poore bache hue array ko scan karega. Total operations $\approx \frac{N \times (N-1)}{2}$, jo order of $N^2$ hota hai. Big inputs par yeh code **TLE (Time Limit Exceeded)** dega.


* **Space Complexity: $O(1)$**
* Humne koi extra helper space use nahi kiya hai (answer return karne wale array ko standard practice me extra space nahi mana jata).



---

## 5. Inefficiency Pattern (Why Stack is Needed?)

Interviewer puchega: *"Bhai, isme bar-bar kya faltu kaam ho raha hai?"*

Dhyan se dekho: Jab hum `4` par the, humne aage jaakar `5` ko dekha. Jab hum `5` par aaye, humne fir se aage jaakar dekha. Hum pichle scanned elements ki information ko aage use hi nahi kar pa rahe hain.

Agar hum right se left ki taraf travel karein aur ek **Monotonic Stack** ka use karein jo elements ko unke bade hone ke sequence me yaad rakhe, toh hum isi kaam ko strictly **$O(N)$ Time** me finish kar sakte hain.

Bhai, brute force ka logic aur iski limits ekdum crystal clear hain? Ab batao iska optimized **Monotonic Stack ($O(N)$ Time)** wala code aur logic phodein?



Bhai, ab hum Next Greater Element (NGE) ke **$O(N)$ Optimized Monotonic Stack Approach** ko ekdum dhasu tarike se deep-dive karenge. Is approach ke baad tumhara monotonic stack ka darr hamesha ke liye khatam ho jayega.

---

## 1. Asali Khel: The "Right-to-Left" Strategy

Brute force me dikkat kya thi? Hum left-to-right ja rahe the aur aage ka bhavishya (future) hume pata nahi tha, isliye baar-baar loop chalana pad raha tha.

Optimized approach me hum **Right se Left (Aakhiri se Shuruat)** travel karenge aur ek **Stack** maintain karenge.

* Stack ka kaam sirf ek hoga: **"Apne andar sirf unhi elements ko zinda rakhna jo aage aane waale (left waale) elements ke liye Next Greater banne ke layak hain."**
* Jo elements chote hain aur kisi ka next greater nahi ban sakte, stack unhe dhakka maar kar nikal (`pop`) dega.

---

## 2. The 3-Step Golden Rule of Monotonic Stack

Jab bhi hum right se left travel karte hue kisi current element `arr[i]` par pahunchenge, hum strictly **3 steps** follow karenge:

1. **Pop Element (Choton ko Bhagao):** Jab tak stack khali nahi hai, aur stack ke top par baitha element hamare current element se chota ya barabar hai (`st.top() <= arr[i]`), tab tak stack ko `pop()` karte jao.
* *Logic:* Agar stack ka top hamare current element se chota hai, toh woh iske left waale elements ke liye kabhi "Next Greater" nahi ban payega (kyunki current element usse bada aur pehle khada hai). Woh hamare liye bekar hai!


2. **Answer Assign (Apna Answer Lo):** Pop loop khatam hone ke baad:
* Agar stack **khali** ho gaya, iska matlab right side me current element se bada koi hai hi nahi $\rightarrow$ `nge[i] = -1`.
* Agar stack me koi bacha hai, toh stack ka **top element** hi hamara sabse pehla sabse pasandida Next Greater Element hai $\rightarrow$ `nge[i] = st.top()`.


3. **Push Element (Khud Stack Me Baitho):** Ab current element `arr[i]` ko stack me `push()` kar do, taaki woh apne left waale elements ke liye Next Greater banne ki race me shamil ho sake.

---

## 3. Micro-Level Visual Dry Run (The Live Simulation)

Chalo ek array lete hain: `arr = [4, 5, 2, 25]`
Hum piche se shuru karenge: `i = 3` se `i = 0` tak.

### Step 1: `i = 3` (`arr[3] = 25`)

* **Pop:** Stack khali hai (`st = []`). Kuch pop nahi hoga.
* **Answer:** Stack khali hai, toh `nge[3] = -1`.
* **Push:** `25` ko stack me daalo.
* **Stack State:** `[25]` (Top par 25 hai)

### Step 2: `i = 2` (`arr[2] = 2`)

* **Pop:** Stack top par `25` hai. Kya `25 <= 2` hai? Nahi! Pop loop nahi chalega.
* **Answer:** Stack top par `25` bacha hai, toh `nge[2] = 25`.
* **Push:** `2` ko stack me daalo.
* **Stack State:** `[25, 2]` (Top par 2 hai)

### Step 3: `i = 1` (`arr[1] = 5`)

* **Pop:** Stack top par `2` hai. Kya `2 <= 5` hai? Haan bhai! `2` ko bahar pheko (`st.pop()`).
* Next top check karo: `25` hai. Kya `25 <= 5` hai? Nahi! Loop stop.


* **Answer:** Stack top par ab `25` bacha hai, toh `nge[1] = 25`.
* **Push:** `5` ko stack me daalo.
* **Stack State:** `[25, 5]` (Top par 5 hai)

### Step 4: `i = 0` (`arr[0] = 4`)

* **Pop:** Stack top par `5` hai. Kya `5 <= 4` hai? Nahi! Pop loop nahi chalega.
* **Answer:** Stack top par `5` hai, toh `nge[0] = 5`.
* **Push:** `4` ko stack me daalo.
* **Stack State:** `[25, 5, 4]` (Top par 4 hai)

**Final `nge` Array:** `[5, 25, 25, -1]` ✅ (Ekdum perfect accuracy!)

---

## 4. Optimized C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n); // Answer array
        stack<int> st;      // Monotonic Stack

        // Right se Left doud lagao
        for (int i = n - 1; i >= 0; i--) {
            
            // Step 1: Chote elements ko stack se saaf karo
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            // Step 2: Agar stack khali nahi hai toh top hi answer hai, warna -1
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }

            // Step 3: Current element ko stack me push karo
            st.push(arr[i]);
        }

        return nge;
    }
};

```

---

## 5. Complexity Analysis & Interview Proof

* **Time Complexity: $O(N)$**
* Interviewer yahan fir se tumse trap daal kar poochega: *"Bhai, `for` loop ke andar `while` loop hai, toh yeh $O(N^2)$ kaise nahi hai?"*
* Tumhara jawab: *"Sir, pure array ka har ek element stack me maximum **ek baar push** hota hai aur maximum **ek baar pop** hota hai. Kisi bhi element par re-processing nahi hoti. Isiliye Amortized Time Complexity strictly **$O(N)$** hai."*


* **Space Complexity: $O(N)$**
* Worst case me (agar array strictly decreasing ho jaise `[5, 4, 3, 2, 1]`), koi pop nahi hoga aur saare elements stack me store ho jayenge, jisse stack ka size $N$ tak chala jayega.



Bhai, Next Greater Element ka ye Right-to-Left monotonic logic ab dimaag me shishe ki tarah saaf baitha? Iske baad ab iska dusra bhaari variation—**"Next Greater Element II (Circular Array Variant)"** dekhein ya Next Smaller/Largest Histogram par chalein?



Bhai, Next Greater Element (NGE) ke optimized monotonic stack code par jab interviewer edge cases phekega, toh woh tumhare `while` loop ki boundaries aur conditional statements ko check kar raha hota hai.

Chalo Next Greater Element ke saare **extreme aur tricky edge cases** ko track karte hain aur dekhte hain ki hamara monotonic stack unhe kaise tackle karta hai.

---

## 1. All Critical Edge Cases (The Interviewer's Arsenal)

### Edge Case 1: Strictly Increasing Array (Stairs Up) $\rightarrow$ `[10, 20, 30, 40]`

* **Interviewer Ka Dimaag:** Dekhte hain iska stack har baar poora khali hota hai ya nahi.
* **Under the Hood Process:** * Hum right se left process shuru karenge. Pehle `40` aayega, stack khali $\rightarrow$ Ans: `-1`, Stack: `[40]`.
* Jab `30` aayega, stack top par `40` hai. `40 <= 30` False hai! Pop nahi hoga $\rightarrow$ Ans: `40`, Stack: `[40, 30]`.
* Jab `20` aayega, stack top par `30` hai. Pop nahi hoga $\rightarrow$ Ans: `30`, Stack: `[40, 30, 20]`.


* **Result Array:** `[20, 30, 40, -1]`
* **Why it works:** Stack hamesha perfect increasing order maintain karegii aur left waale elements ko unka immediate right padosi hi greater mil jayega.

### Edge Case 2: Strictly Decreasing Array (Stairs Down) $\rightarrow$ `[40, 30, 20, 10]`

* **Interviewer Ka Dimaag:** Isme toh har baar pop hoga, loop fatega toh nahi?
* **Under the Hood Process:**
* Pehle `10` aaya $\rightarrow$ Ans: `-1`, Stack: `[10]`.
* Jab `20` aaya, stack top par `10` hai. `10 <= 20` True! `10` pop ho gaya. Stack khali $\rightarrow$ Ans: `-1`, Stack: `[20]`.
* Jab `30` aaya, stack top par `20` hai. `20 <= 30` True! `20` pop ho gaya. Stack khali $\rightarrow$ Ans: `-1`, Stack: `[30]`.


* **Result Array:** `[-1, -1, -1, -1]`
* **Why it works:** Kyunki left waale elements ke right me unse bada koi hai hi nahi. Hamara `while` loop har baar stack ko poora saaf (`pop`) kar dega aur `if (st.empty())` condition hit hokar sabko `-1` degi.

### Edge Case 3: All Elements Same (Flat Array) $\rightarrow$ `[5, 5, 5, 5]` 🔥 (Tricky!)

* **Interviewer Ka Dimaag:** Yahan equals to (`<=`) ki galti pakdi jayegi!
* **Under the Hood Process:**
* Pehle `5` aaya (index 3) $\rightarrow$ Ans: `-1`, Stack: `[5]`.
* Agla `5` aaya (index 2). `while` loop condition check karega: `st.top() <= arr[i]` $\rightarrow$ `5 <= 5` (True!).
* Stack ka `5` pop ho jayega! Stack khali $\rightarrow$ Ans: `-1`, Stack: `[5]`.


* **Result Array:** `[-1, -1, -1, -1]`
* **Why it works:** Definition ke mutabik Next **Greater** chahiye, Equal nahi. Isliye condition me `st.top() <= arr[i]` me `<=` lagana mandatory hai. Agar tumne sirf `<` lagaya hota, toh answer galat ho jata.

### Edge Case 4: Duplicate Elements with Alternating Peaks $\rightarrow$ `[3, 10, 4, 2, 4]`

* **Interviewer Ka Dimaag:** Dekhte hain duplicate heights par stack sahi state hold karta hai ya nahi.
* **Under the Hood Process:**
* `4` (index 4) $\rightarrow$ Ans: `-1`, Stack: `[4]`.
* `2` (index 3) $\rightarrow$ Top `4` bada hai $\rightarrow$ Ans: `4`, Stack: `[4, 2]`.
* `4` (index 2) $\rightarrow$ Top `2` chota hai, pop! Ab top par `4` hai, `4 <= 4` True, pop! Stack khali $\rightarrow$ Ans: `-1`, Stack: `[4]`.
* `10` (index 1) $\rightarrow$ Top `4` pop, Stack khali $\rightarrow$ Ans: `-1`, Stack: `[10]`.
* `3` (index 0) $\rightarrow$ Top `10` bada hai $\rightarrow$ Ans: `10`, Stack: `[10, 3]`.


* **Result Array:** `[10, -1, -1, 4, -1]`

### Edge Case 5: Single Element or Empty Array $\rightarrow$ `[7]` ya `[]`

* **Under the Hood Process:** Single element ke case me loop sirf ek baar chalega, stack khali milega aur answer `-1` aayega. Empty array me loop chalega hi nahi, empty vector return ho jayega. No segmentation fault!

---

## 2. Interviewer Tracker Checklist (Apne Code Ko Bulletproof Banao)

Jab tum board par code likh rahe ho, toh dhyan rakhna ki ye 3 galtiyan bilkul na hon:

1. **`!st.empty()` Pehle Likhna:** `while (st.top() <= arr[i] && !st.empty())` $\rightarrow$ **🚨 BUG!**
Agar stack khali hua, toh `st.top()` check karte hi code crash (Runtime Error) ho jayega. Hamesha stack khali hai ya nahi, ye pehle check karo: `while (!st.empty() && st.top() <= arr[i])`.
2. **Loop ki Direction:** Hamesha yaad rakhna ki standard Next Greater Element ke liye hum **Right se Left (`n-1` se `0`)** jate hain. Agar question "Previous Greater" ka ho jaye, tab hum **Left se Right (`0` se `n-1`)** chalte hain.

Bhai, saare edge cases ke saath Next Greater Element ka pura operation dimaag me freeze ho gaya? Ab iske circular version **"Next Greater Element II (LeetCode 503)"** par chalein jahan array ke aakhiri element ka answer dhoondhne ke liye wapas ghoom kar shuruat me aana padta hai?



Bhai, **Next Smaller Element (NSE)** bilkul Next Greater Element ka hi bhai hai, bas is baar hamari shart badal gayi hai. Next Greater me hum bada element dhoondh rahe the, aur yahan humein **"Array ke har element ke liye, uske RIGHT side me sabse pehla aisa element dhoondna hai jo usse CHOTA (Smaller) ho."**

Agar right side me koi chota element nahi milta, toh standard rule ke mutabik answer `-1` hoga.

Chalo iska **Brute Force Approach** ekdum detail me samajhte hain taaki iska infrastructure dimaag me set ho jaye.

---

## 1. Core Logic: The Right-Scan Smaller Principle

Maan lo tum array ke kisi index `i` par khade ho aur tumhara current element `arr[i]` hai.

* Tum index `i+1` se shuru karke aakhiri index (`n-1`) tak right side me scan karoge.
* Jaise hi koi pehla element `arr[j]` mile jo tumhare current element se chota ho (`arr[j] < arr[i]`), wahi tumhara answer hai! Udhar hi inner loop ko `break` kar do.
* Agar poora array khatam ho gaya aur koi chota element nahi mila, toh answer `-1` reh jayega.

---

## 2. Brute Force Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerElementBrute(vector<int>& arr) {
        int n = arr.size();
        // Shuruat me saare answers ko -1 se fill kar do
        vector<int> nse(n, -1); 

        // Outer Loop: Har ek element par ek-ek karke jao
        for (int i = 0; i < n; i++) {
            // Inner Loop: Current element ke RIGHT side me scan karo
            for (int j = i + 1; j < n; j++) {
                // Shart: Is baar chota element chahiye (<)
                if (arr[j] < arr[i]) {
                    nse[i] = arr[j]; // Pehla chota element mil gaya!
                    break;            // Milte hi break karo, aage nahi dekhna
                }
            }
        }

        return nse;
    }
};

```

---

## 3. Micro-Level Visual Dry Run

Chalo ek array lete hain: `arr = [4, 8, 5, 2, 25]`
Hum ek `nse` array maintain karenge answers ke liye.

### Index 0 (`arr[0] = 4`):

* Right side scan: `8, 5, 2, 25`.
* `8 < 4`? Nahi.
* `5 < 4`? Nahi.
* `2 < 4`? Haan bhai! Chota mil gaya. 🎯
* `nse[0] = 2`. Loop break.

### Index 1 (`arr[1] = 8`):

* Right side scan: `5, 2, 25`.
* `5 < 8`? Haan bhai! Pehla hi element chota mil gaya. 🎯
* `nse[1] = 5`. Loop break. *(Dhyan dena, right me 2 bhi chota tha, par humein **sabse pehla** chahiye, isliye 5 par hi break ho gaya).*

### Index 2 (`arr[2] = 5`):

* Right side scan: `2, 25`.
* `2 < 5`? Haan bhai! 🎯
* `nse[2] = 2`. Loop break.

### Index 3 (`arr[3] = 2`):

* Right side scan: `25`.
* `25 < 2`? Nahi.
* Aage array khatam. Koi chota nahi mila.
* `nse[3] = -1`.

### Index 4 (`arr[4] = 25`):

* Right side scan: Khali hai.
* Inner loop chalega hi nahi.
* `nse[4] = -1`.

**Final Answer Array (`nse`):** `[2, 5, 2, -1, -1]` ✅

---

## 4. Complexity Analysis

* **Time Complexity: $O(N^2)$**
* Worst-case scenario me (jaise agar array strictly increasing ho: `[1, 2, 3, 4, 5]`), har element ke liye inner loop aakhiri tak chalega kyunki right side me koi chota element milega hi nahi. Total operations $\approx \frac{N \times (N-1)}{2}$, yaani $O(N^2)$. Large arrays par yeh code **TLE** de dega.


* **Space Complexity: $O(1)$**
* Humne koi extra data structure (jaise stack/queue) use nahi kiya, sirf answer return karne wala array banaya hai, isiliye constant extra space hai.



---

## 5. Next Smaller Ke Saare Edge Cases

Jab interviewer brute force dekh lega, toh woh tumse in extreme inputs par logic validation maangega:

1. **Strictly Decreasing Array (`[5, 4, 3, 2, 1]`)**: Is case me har element ka answer uska immediate right padosi hoga. Loop hamesha pehli baar me hi break ho jayega. Answer: `[4, 3, 2, 1, -1]`.
2. **Strictly Increasing Array (`[1, 2, 3, 4, 5]`)**: Is case me kisi ke bhi right me chota element nahi hai. Inner loop poora ghoomkar thak jayega par kuch nahi milega. Answer: `[-1, -1, -1, -1, -1]`.
3. **All Elements Equal (`[7, 7, 7, 7]`)**: Kyunki shart strictly smaller (`<`) ki hai, toh barabar wale elements condition fail kar denge. Answer: `[-1, -1, -1, -1]`.

Bhai, Next Smaller Element ka Brute Force aur iski working ekdum clear hai? Ab isko optimize karne ke liye **Monotonic Stack** lagayein? Batao, iska optimized approach dekhna hai?



Bhai, chalo ab Next Smaller Element (NSE) ko **$O(N)$ Optimized Monotonic Stack Approach** se ekdum khol kar samajhte hain.

Concept bilkul Next Greater Element jaisa hi hai, bas is baar stack ki shart badal jayegi. Is baar hum ek **Monotonic Increasing Stack** maintain karenge, yaani stack me neeche badi buildings hongi aur upar choti.

---

## 1. Asali Khel: The Right-to-Left Strategy for Smaller

Yahan bhi hum **Right se Left (Aakhiri se Shuruat)** travel karenge.

Stack ka rule is baar yeh hoga: **"Apne andar sirf unhi elements ko zinda rakho jo aage aane waale (left waale) elements ke liye Next Smaller banne ke layak hain."**
Agar stack ke top par koi bada element baitha hai, toh woh hamare current element ke saamne bekar hai, use dhakka maar kar nikal (`pop`) do.

---

## 2. The 3-Step Golden Rule for Next Smaller

Jab hum right se left travel karte hue kisi current element `arr[i]` par pahunchenge, toh ye 3 steps chalenge:

1. **Pop Element (Badon ko Bhagao):** Jab tak stack khali nahi hai, aur stack ke top par baitha element hamare current element se **bada ya barabar** hai (`st.top() >= arr[i]`), tab tak `st.pop()` karte jao.
* *Logic:* Agar stack ka top hamare current element se bada hai, toh uske left waale elements ke liye "Next Smaller" hamesha hamara current element banega, kyunki current element chota bhi hai aur pehle khada hai. Isiliye stack ka top ab bekar ho chuka hai.


2. **Answer Assign:** Pop loop rukne ke baad:
* Agar stack **khali** ho gaya $\rightarrow$ `nse[i] = -1` (Right me koi chota nahi mila).
* Agar stack me koi bacha hai $\rightarrow$ `nse[i] = st.top()` (Wahi sabse pehla aur immediate smaller element hai).


3. **Push Element:** Current element `arr[i]` ko stack me `push()` kar do taaki woh apne left waale elements ke liye chota padosi ban sake.

---

## 3. Micro-Level Visual Dry Run

Array lete hain: `arr = [4, 8, 5, 2, 25]`
Hum piche se shuru karenge: `i = 4` se `i = 0` tak.

### Step 1: `i = 4` (`arr[4] = 25`)

* **Pop:** Stack khali hai (`st = []`). No pop.
* **Answer:** Stack khali hai $\rightarrow$ `nse[4] = -1`.
* **Push:** `25` ko push karo.
* **Stack:** `[25]` (Top par 25 hai).

### Step 2: `i = 3` (`arr[3] = 2`)

* **Pop:** Stack top par `25` hai. Shart: `st.top() >= arr[i]` $\rightarrow$ `25 >= 2` (True! 🚨). `25` ko pop karo. Stack ab khali hai.
* **Answer:** Stack khali ho gaya $\rightarrow$ `nse[3] = -1`.
* **Push:** `2` ko push karo.
* **Stack:** `[2]` (Top par 2 hai).

### Step 3: `i = 2` (`arr[2] = 5`)

* **Pop:** Stack top par `2` hai. `2 >= 5` (False). Pop nahi hoga.
* **Answer:** Stack top par `2` baitha hai $\rightarrow$ `nse[2] = 2`.
* **Push:** `5` ko push karo.
* **Stack:** `[2, 5]` (Top par 5 hai).

### Step 4: `i = 1` (`arr[1] = 8`)

* **Pop:** Stack top par `5` hai. `5 >= 8` (False). Pop nahi hoga.
* **Answer:** Stack top par `5` baitha hai $\rightarrow$ `nse[1] = 5`.
* **Push:** `8` ko push karo.
* **Stack:** `[2, 5, 8]` (Top par 8 hai).

### Step 5: `i = 0` (`arr[0] = 4`)

* **Pop:** Stack top par `8` hai. `8 >= 4` (True! 🚨) $\rightarrow$ `8` pop.
* Naya top `5` hai. `5 >= 4` (True! 🚨) $\rightarrow$ `5` pop.
* Naya top `2` hai. `2 >= 4` (False). Loop stop!


* **Answer:** Stack top par ab `2` bacha hai $\rightarrow$ `nse[0] = 2`.
* **Push:** `4` ko push karo.
* **Stack:** `[2, 4]` (Top par 4 hai).

**Final `nse` Array:** `[2, 5, 2, -1, -1]` ✅ (Brute force se ekdum match ho gaya!)

---

## 4. Optimized C++ Code

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;

        // Right se Left loop chalao
        for (int i = n - 1; i >= 0; i--) {
            
            // Step 1: Bade ya barabar elements ko stack se saaf karo
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // Step 2: Answer nikaalo
            if (st.empty()) {
                nse[i] = -1;
            } else {
                nse[i] = st.top();
            }

            // Step 3: Current element ko stack me daalo
            st.push(arr[i]);
        }

        return nse;
    }
};

```

---

## 5. Complexity Analysis

* **Time Complexity: $O(N)$** — Pure array ka har ek element stack me strictly ek baar andar (`push`) jata hai aur ek baar bahar (`pop`) jata hai. Isliye amortized time hamesha linear ($O(N)$) rahega.
* **Space Complexity: $O(N)$** — Worst-case me (agar array strictly increasing ho jaise `[1, 2, 3, 4]`), koi pop nahi hoga aur saare elements stack me store hote chale jayenge.

Bhai, Next Smaller Element ka ye optimized monotonic logic aur dry run ekdum dimaag me fit baitha?

Ab yahan se ek mazedar baat suno: Agar tumne **Next Smaller Element** aur **Previous Smaller Element** ko index ke roop me store karna seekh liya, toh tum LeetCode Hard ka sabse bada boss problem—**"Largest Rectangle in Histogram (LeetCode 84)"** agle 5 minute me dharashayi kar doge!

Batao, Histogram wale Hard problem par chalein ya iske edge cases dekhne hain?



Bhai, **Smallest Number on Left (Previous Smaller Element)** ka brute force approach NGE aur NSE (Next Smaller) ka bilkul reverse hai. Yahan hum right-to-left scan karne ke bajaye, har element ke liye **left side** me scan karte hain ki kaun sa element sabse pehle usse chota (smaller) milta hai.

---

## 1. Core Logic: The Left-Scan Principle

Maan lo tum array ke index `i` par khade ho. `arr[i]` ka "Previous Smaller Element" dhoondhne ke liye:

* Tum index `i-1` se shuru karke index `0` tak ulta (reverse) scan karoge.
* Jaise hi koi pehla element `arr[j]` mile jo tumhare current element se chota ho (`arr[j] < arr[i]`), wahi tumhara answer hai.
* Agar poora left side ghoomne ke baad bhi koi chota element nahi mila, toh default answer `-1` hoga.

---

## 2. Brute Force Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prevSmallerElementBrute(vector<int>& arr) {
        int n = arr.size();
        // Har element ke liye default -1 rakho
        vector<int> pse(n, -1); 

        // Outer Loop: Har index i par jao
        for (int i = 0; i < n; i++) {
            // Inner Loop: Current element ke LEFT side me scan karo
            for (int j = i - 1; j >= 0; j--) {
                // Shart: Chota element chahiye (<)
                if (arr[j] < arr[i]) {
                    pse[i] = arr[j]; // Pehla chota element mil gaya!
                    break;           // Milte hi break karo
                }
            }
        }
        return pse;
    }
};

```

---

## 3. Micro-Level Visual Dry Run

Array: `arr = [4, 8, 5, 2, 25]`

| Index | Element | Left Side Scan | Result | Explanation |
| --- | --- | --- | --- | --- |
| `0` | `4` | (None) | `-1` | Left me kuch nahi hai. |
| `1` | `8` | `4` | `4` | `4 < 8`, so 4 is the answer. |
| `2` | `5` | `8, 4` | `4` | `4 < 5`, so 4 is the answer. |
| `3` | `2` | `5, 8, 4` | `-1` | Sabhi elements 2 se bade hain. |
| `4` | `25` | `2, 5, 8, 4` | `2` | `2 < 25`, so 2 is the answer. |

**Final Answer Array (`pse`):** `[-1, 4, 4, -1, 2]`

---

## 4. Complexity Analysis

* **Time Complexity: $O(N^2)$**
* Worst-case (e.g., Sorted Array `[1, 2, 3, 4]`), har element ke liye hume saare pichle elements scan karne padte hain. Total comparisons $\approx \frac{N(N-1)}{2}$.


* **Space Complexity: $O(1)$**
* Brute force approach me hum sirf result array store kar rahe hain, koi extra stack ya helper data structure nahi le rahe.



---

## 5. Critical Edge Cases

Interviewer in cases par check karega ki tumhara loop boundaries handle kar raha hai ya nahi:

1. **Sorted Array (`[1, 2, 3, 4]`)**: Har element ka previous smaller uska immediate left neighbor hoga.
* *Result:* `[-1, 1, 2, 3]`


2. **Reverse Sorted Array (`[4, 3, 2, 1]`)**: Kisi bhi element ke left me chota element nahi hoga (kyunki array decreasing hai).
* *Result:* `[-1, -1, -1, -1]`


3. **Duplicates (`[3, 3, 3]`)**: Shart strict inequality (`<`) ki hai, toh equal elements condition fail karenge.
* *Result:* `[-1, -1, -1]`



Is brute force approach me $O(N^2)$ complexity iski sabse badi kamzori hai. Interviews me jab tum ye logic samjha doge, toh interviewer turant tumse isse $O(N)$ me optimize karne ko kahega using **Monotonic Stack**.


Bhai, chalo ab **Smallest Number on Left (Previous Smaller Element)** ko **$O(N)$ Optimized Monotonic Stack Approach** se ekdum deep-dive karke samajhte hain.

Yahan par ek chota sa dimagi twist hai: Next Greater/Smaller me hum array ke right side ka future dhoondh rahe the, isliye hum right-to-left ja rahe the. Lekin is baar hume **Left Side (Past/History)** ka chota element chahiye, isiliye hum normal direction me, yaani **Left se Right (`0` se `n-1`)** travel karenge!

---

## 1. Asali Khel: The Left-to-Right Strategy

Hum left-to-right travel karenge aur ek **Monotonic Increasing Stack** maintain karenge.

Stack ka rule simple hai: **"Apne andar sirf unhi elements ko zinda rakho jo aage aane waale (right waale) elements ke liye Previous Smaller banne ke layak hain."**
Agar hume koi bada element milta hai jo hamare current element ke saamne bekar hai, toh use stack se dhakka maar kar nikal (`pop`) denge.

---

## 2. The 3-Step Golden Rule for Previous Smaller

Jab hum left se right travel karte hue kisi current element `arr[i]` par pahunchenge, toh ye 3 steps chalenge:

1. **Pop Element (Badon ko Bhagao):** Jab tak stack khali nahi hai, aur stack ke top par baitha element hamare current element se **bada ya barabar** hai (`st.top() >= arr[i]`), tab tak `st.pop()` karte jao.
* *Logic:* Agar stack ka top hamare current element se bada hai, toh uske right waale elements ke liye "Previous Smaller" hamara current element banega, kyunki current element chota bhi hai aur zyada paas khada hai. Isiliye stack ka top ab bekar ho chuka hai, use uda do.


2. **Answer Assign:** Pop loop rukne ke baad:
* Agar stack **khali** ho gaya $\rightarrow$ `pse[i] = -1` (Left me koi chota nahi mila).
* Agar stack me koi bacha hai $\rightarrow$ `pse[i] = st.top()` (Wahi sabse pehla aur immediate left smaller element hai).


3. **Push Element:** Current element `arr[i]` ko stack me `push()` kar do taaki woh apne right waale elements ke liye chota padosi ban sake.

---

## 3. Micro-Level Visual Dry Run

Array lete hain: `arr = [4, 8, 5, 2, 25]`
Hum shuru karenge: `i = 0` se `i = 4` tak (Left to Right).

### Step 1: `i = 0` (`arr[0] = 4`)

* **Pop:** Stack khali hai (`st = []`). No pop.
* **Answer:** Stack khali hai $\rightarrow$ `pse[0] = -1`.
* **Push:** `4` ko push karo.
* **Stack:** `[4]` (Top par 4 hai).

### Step 2: `i = 1` (`arr[1] = 8`)

* **Pop:** Stack top par `4` hai. Kya `4 >= 8` hai? Nahi! Pop nahi hoga.
* **Answer:** Stack top par `4` baitha hai $\rightarrow$ `pse[1] = 4`.
* **Push:** `8` ko push karo.
* **Stack:** `[4, 8]` (Top par 8 hai).

### Step 3: `i = 2` (`arr[2] = 5`)

* **Pop:** Stack top par `8` hai. Shart: `st.top() >= arr[i]` $\rightarrow$ `8 >= 5` (True! 🚨). `8` ko pop karo.
* Naya top check karo: `4` hai. Kya `4 >= 5` hai? Nahi! Loop stop.


* **Answer:** Stack top par ab `4` bacha hai $\rightarrow$ `pse[2] = 4`.
* **Push:** `5` ko push karo.
* **Stack:** `[4, 5]` (Top par 5 hai).

### Step 4: `i = 3` (`arr[3] = 2`)

* **Pop:** Stack top par `5` hai. `5 >= 2` (True! 🚨) $\rightarrow$ `5` pop.
* Naya top `4` hai. `4 >= 2` (True! 🚨) $\rightarrow$ `4` pop.
* Stack khali ho gaya. Loop stop!


* **Answer:** Stack khali ho gaya $\rightarrow$ `pse[3] = -1`.
* **Push:** `2` ko push karo.
* **Stack:** `[2]` (Top par 2 hai).

### Step 5: `i = 4` (`arr[4] = 25`)

* **Pop:** Stack top par `2` hai. `2 >= 25` (False). Pop nahi hoga.
* **Answer:** Stack top par `2` baitha hai $\rightarrow$ `pse[4] = 2`.
* **Push:** `25` ko push karo.
* **Stack:** `[2, 25]` (Top par 25 hai).

**Final `pse` Array:** `[-1, 4, 4, -1, 2]` ✅ (Brute force se ekdum match ho gaya!)

---

## 4. Optimized C++ Code

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> prevSmallerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;

        // LEFT se RIGHT loop chalao
        for (int i = 0; i < n; i++) {
            
            // Step 1: Bade ya barabar elements ko stack se saaf karo
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // Step 2: Answer nikaalo
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }

            // Step 3: Current element ko stack me daalo
            st.push(arr[i]);
        }

        return pse;
    }
};

```

---

## 5. Complexity Analysis

* **Time Complexity: $O(N)$** — Kyunki har ek element stack me maximum ek baar `push` hoga aur ek baar `pop` hoga. Loop ke andar loop dekh kar $O(N^2)$ mat sochna, pure execution me total pops kabhi bhi $N$ se zyada nahi ho sakte. Isiliye amortized time strictly linear hai.
* **Space Complexity: $O(N)$** — Worst-case me (agar array strictly decreasing ho jaise `[4, 3, 2, 1]`), tab stack ka size $N$ tak chala jata hai.

---

## 💡 The Master Secret (Connecting to Histogram)

Bhai, ab dhyan se suno. Tumne abhi tak monotonic stack ke **3 brahmastra** seekh liye hain:

1. **Next Greater Element** (Right to Left, `st.top() <= arr[i]`)
2. **Next Smaller Element** (Right to Left, `st.top() >= arr[i]`)
3. **Previous Smaller Element** (Left to Right, `st.top() >= arr[i]`)

LeetCode Hard ka problem **"Largest Rectangle in Histogram"** pata hai kya hai? Wo kuch nahi hai, bas har building ke liye uska **Previous Smaller Element ka Index** aur **Next Smaller Element ka Index** nikalna hota hai! Dono indices ke beech ki doori hi rectangle ki width banti hai.

Bhai, yeh Previous Smaller ka logic ekdum dhasu tarike se dimaag me chhap gaya? Ab batao seedha iske bache hue chote bhai **"Previous Greater Element"** ko khatam karein, ya ab seedha **Histogram (LeetCode Hard)** par halla bolen?



Bhai, **Previous Smaller Element (PSE)** ke liye interviewer tumhare code ko unhi scenarios me test karega jahan logic break hone ke chance hote hain—khas kar jahan duplicate values ya strictly order wali arrays hoti hain.

Chalo, in 5 critical edge cases ko dissect karte hain aur dekhte hain ki tumhara monotonic stack logic inhein kaise handle karega.

---

### 1. Strictly Increasing Array (Stairs Up) $\rightarrow$ `[1, 2, 3, 4]`

* **Interviewer Ka Test:** Kya stack har step par growth dikha raha hai?
* **Stack Logic:**
* `1` aaya: Stack me push hua. PSE: `-1`.
* `2` aaya: Stack top (`1`) chota hai, pop nahi hoga. `1 >= 2` False hai. PSE: `1`.
* `3` aaya: Stack top (`2`) chota hai, pop nahi hoga. PSE: `2`.


* **Result Array:** `[-1, 1, 2, 3]`
* **Verdict:** Stack me increasing order maintain ho raha hai, logic perfectly working.

### 2. Strictly Decreasing Array (Stairs Down) $\rightarrow$ `[4, 3, 2, 1]`

* **Interviewer Ka Test:** Kya stack poora empty ho raha hai?
* **Stack Logic:**
* `4` push. `3` aaya $\rightarrow$ `4 >= 3` True, `4` pop. Stack empty! PSE: `-1`.
* `2` aaya $\rightarrow$ `3 >= 2` True, `3` pop. Stack empty! PSE: `-1`.


* **Result Array:** `[-1, -1, -1, -1]`
* **Verdict:** Logic sahi hai kyunki decreasing order me left side koi chota element exist hi nahi karta.

### 3. Duplicate Elements (The Equality Trap) $\rightarrow$ `[3, 3, 3]` 🔥

* **Interviewer Ka Test:** Yeh sabse important case hai. Agar tumne `st.top() >= arr[i]` ki jagah sirf `st.top() > arr[i]` likh diya, toh tumhara code galat answer dega.
* **Stack Logic:**
* Pehla `3` push.
* Dusra `3` aaya $\rightarrow$ `st.top()` (`3`) `>=` `arr[i]` (`3`) True hai! Stack ka `3` pop ho jayega.
* Stack empty ho gaya $\rightarrow$ PSE: `-1`.


* **Result Array:** `[-1, -1, -1]`
* **Why it matters:** Question "Smaller" hai, "Smaller or Equal" nahi. Equal elements condition fail karni chahiye. `=` sign lagana **mandatory** hai.

### 4. Alternating/Peaks (`[5, 2, 8, 2, 4]`)

* **Interviewer Ka Test:** Complex popping sequence handle ho raha hai?
* **Stack Logic:**
* `5` push. PSE: `-1`. Stack: `[5]`
* `2` aaya $\rightarrow$ `5 >= 2` True, pop 5. Stack empty. PSE: `-1`. Push 2. Stack: `[2]`
* `8` aaya $\rightarrow$ `2 >= 8` False. PSE: `2`. Push 8. Stack: `[2, 8]`
* `2` aaya $\rightarrow$ `8 >= 2` True (pop 8), `2 >= 2` True (pop 2). Stack empty. PSE: `-1`. Push 2.
* `4` aaya $\rightarrow$ `2 >= 4` False. PSE: `2`.


* **Result Array:** `[-1, -1, 2, -1, 2]`

### 5. Single Element or Empty Array

* **Empty Array (`[]`):** Loop chalega hi nahi, empty vector return hoga. Safe.
* **Single Element (`[5]`):** Loop `i=0` ke liye chalega, `st.empty()` True hoga, `-1` return hoga. Safe.

---

### 💡 Interviewer Checklist (Code ko Bulletproof banane ke liye):

Jab tum board par code likho, toh ye 3 cheezein check-list ki tarah dimaag me rakhna:

1. **Safety First:** `while (!st.empty() && st.top() >= arr[i])` likhte waqt `!st.empty()` ko hamesha pehle likhna. Agar `st.top()` pehle likh diya aur stack empty hua, toh **Runtime Error (Segmentation Fault)** aa jayega.
2. **Strictly Smaller vs Smaller/Equal:** Agar question bole "Smaller", toh `while` me `>=` use karo. Agar question bole "Smaller or Equal", toh `while` me sirf `>` use karo.
3. **Variable Names:** PSE (Previous Smaller Element) variable name use karna, interviewer ko code readability me maza aata hai.

Bhai, ab Histogram ka boss level (Next Smaller Index + Previous Smaller Index) tackle karne ke liye taiyaar ho? Histogram waali problem me PSE aur NSE dono indices ka use hota hai. Histogram shuru karein?



Bhai, ab tumne monotonic stack ke saare standard linear variations (NGE, NSE, PSE) phod diye hain. Ab aata hai Monotonic Stack ka ek bohot hi popular interview variation: **Next Greater Element II (LeetCode 503)**.

Is problem me interviewer ek twist dalta hai—**Circular Array**.

---

## 1. The Circular Twist: Problem Statement

Normal NGE me kya hota tha? Agar array `[1, 2, 1]` hai, toh aakhiri `1` ke right me koi nahi hai, isliye uska answer `-1` ho jata tha.

Lekin **Circular Array** ka matlab hai ki array khatam hone ke baad khatam nahi hoti, ghoom kar wapas shuruat par aa jaati hai!

* `[1, 2, 1]` me aakhiri `1` ka next greater element dhoondhne ke liye hum wapas shuruat se scan kar sakte hain, aur use pehla bada element mil jayega `2`.

---

## 2. Brute Force (The Virtual Double Array Concept)

Circular array ko computer me visualize karne ka sabse asaan tarika hai ki **array ko do baar jod do (Concatenate)**.
Agar original array `[1, 2, 1]` hai, toh do baar jodne par yeh banegi: `[1, 2, 1,  1, 2, 1]`.

Ab agar tum pehli wali array ke elements par khade hokar standard right scan brute force chaloge, toh circularity automatic handle ho jayegi! Iski Brute Force time complexity **$O(N^2)$** hogi.

---

## 3. Optimized Approach: Hyperspace Monotonic Stack ($O(N)$ Time)

Interviewer bolega: *"Bhai, mujhe array ko copy karke duplicate nahi karna hai ($O(N)$ extra memory consume nahi karni). Original array ke size ko badhaye bina $O(N)$ time me karke dikhao."*

Yahan hum use karte hain **Modulus Operator (`%`)** aur **Virtual Loop Extension** ka master hack.

### The Core Logic:

Hum loop ko `n - 1` se shuru karne ke bajaye **`2*n - 1`** se shuru karenge aur piche (`0`) tak layenge. Hum bas assume kar rahe hain ki array do baar likhi hui hai, actual me hum koi extra space nahi badha rahe.

* Jab bhi hume kisi index par element ko access karna hoga, hum **`arr[i % n]`** use karenge.
* Hum standard 3-Step rule hi follow karenge (Pop $\rightarrow$ Ans $\rightarrow$ Push).
* **Ek chota dhyan:** Answer hum sirf tabhi fill karenge jab hum loop ke pehle aadhe hisse me honge (`i < n`), kyunki aage ka loop (`i >= n`) sirf stack ko build karne aur circular elements ko stack me bharne ke liye chal raha hai.

---

## 4. Optimized C++ Code ($O(N)$ Time, $O(N)$ Space)

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElementsII(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n, -1); // Answer array
        stack<int> st;          // Stack stores the elements

        // Virtual Loop: Array ke double size se reverse travel karenge
        for (int i = 2 * n - 1; i >= 0; i--) {
            
            // Step 1: st.top() <= current element tak pop karte jao
            // Circular indexing ke liye hamesha % n use karenge
            while (!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }

            // Step 2: Answer sirf real elements (0 se n-1) ke liye set karenge
            if (i < n) {
                if (!st.empty()) {
                    nge[i] = st.top();
                } else {
                    nge[i] = -1;
                }
            }

            // Step 3: Current element ko stack me push karo
            st.push(arr[i % n]);
        }

        return nge;
    }
};

```

---

## 5. Micro Dry Run (`arr = [1, 2, 1]`, `n = 3`)

Loop chalega `i = 5` se lekar `i = 0` tak.

| `i` | `i % n` | `arr[i % n]` | Stack State Before Pop | Action / Output | Stack State After Push |
| --- | --- | --- | --- | --- | --- |
| **5** | 2 | `1` | `[]` | Stack empty $\rightarrow$ No Pop, No Ans (`i>=n`) | `[1]` |
| **4** | 1 | `2` | `[1]` | `1 <= 2` (True) $\rightarrow$ Pop `1`. No Ans (`i>=n`) | `[2]` |
| **3** | 0 | `1` | `[2]` | `2 <= 1` (False) $\rightarrow$ No Pop. No Ans (`i>=n`) | `[2, 1]` |
| **2** | 2 | `1` | `[2, 1]` | `1 <= 1` (True) $\rightarrow$ Pop `1`. **Ans (`i<n`):** Top is `2` $\rightarrow$ `nge[2] = 2` | `[2, 1]` |
| **1** | 1 | `2` | `[2, 1]` | `1<=2` & `2<=2` $\rightarrow$ Pop `1` and `2`. Stack Empty. **Ans:** `nge[1] = -1` | `[2]` |
| **0** | 0 | `1` | `[2]` | `2 <= 1` (False) $\rightarrow$ No Pop. **Ans:** Top is `2` $\rightarrow$ `nge[0] = 2` | `[2, 1]` |

**Final Output:** `[2, -1, 2]` ✅ (Dekho aakhiri `1` ko circular ghoom kar `2` mil gaya!)

---

## 6. Critical Edge Cases

1. **Strictly Decreasing Array (`[5, 4, 3, 2, 1]`)**:
* *Twist:* Normal NGE me sabka answer `-1` aata tha. Par yahan `4` ghoom kar `5` ko dekh sakta hai, `3` bhi `5` ko dekh sakta hai.
* *Result:* Only max element (`5`) ka answer `-1` aayega, baaki sabka answer `5` ban jayega! (`[-1, 5, 5, 5, 5]`).


2. **All Elements Equal (`[3, 3, 3]`)**:
* Kyunki strictly greater chahiye, toh circularity ghoomne ke baad bhi koi kisi se bada nahi milega.
* *Result:* `[-1, -1, -1]`.



Bhai, Circular Array ka `% n` wala logic aur double-loop execution dimaag me fit baitha? Ab iske baad straight **Largest Rectangle in Histogram (LeetCode Hard)** ko target karein, ya abhi isme koi doubt hai?



Bhai, **Stock Span Problem** (LeetCode 901) ek aur bohot hi zabardast interview question hai. Iska concept financial markets se zaroorat par banta hai, par coding ke terms me yeh bilkul hamare pichle pattern **"Previous Greater Element"** jaisa hi hai.

Chalo pehle iska **Brute Force Approach** ekdum detail me samajhte hain taaki iska infrastructure clear ho sake.

---

## 1. Problem Statement Kya Hai?

Stock span ka matlab hota hai ki **"Aaj ke din ko milakar, piche ke lagatar (consecutive) kitne dino ka stock price aaj ke price se chota ya uske barabar (`<=`) tha."**

Maan lo tumhare paas 7 dino ke prices hain: `[100, 80, 60, 70, 60, 75, 85]`

* Pehle din `100` ka span hamesha `1` hoga (kyunki piche kuch nahi hai).
* `80` ke piche `100` hai (jo bada hai), toh iska span bhi `1` (sirf khud ka din).
* Jab tum `70` par aate ho: Iske piche `60` chota hai, par uske piche `80` bada hai. Toh consecutive kitne chote ya barabar mile? `[70, 60]` $\rightarrow$ yaani `2` days!

---

## 2. Core Logic: The Left-Scan Price Principle

Brute force me hum har ek naye price ke liye **left side (history)** me tab tak scan karte hain jab tak hume koi aisa price na mil jaye jo aaj ke price se strictly bada (`>`) ho.

1. Maan lo aaj index `i` hai aur price `prices[i]` hai.
2. Ek counter rakho `span = 1` (aaj ka din included).
3. Ek loop chalao `j = i - 1` se lekar `0` tak (piche ki taraf).
4. Agar `prices[j] <= prices[i]` hai, toh iska matlab yeh din bhi hamare span me aayega $\rightarrow$ `span++` karo.
5. Jaise ہی koi element bada mile (`prices[j] > prices[i]`), loop ko **break** kar do.

---

## 3. Brute Force Code Implementation (C++)

Interviews me aksar yeh problem ek **Class Design** ke roop me puchi jaati hai, jahan ek `next(int price)` function hota hai jo har naye din ka price leta hai aur uska span return karta hai.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class StockSpannerBrute {
private:
    vector<int> prices; // Saare pichle prices ko store karne ke liye

public:
    StockSpannerBrute() {
        // Constructor
    }
    
    int next(int price) {
        // 1. Naye price ko apni history vector me daalo
        prices.push_back(price);
        
        int span = 1; // Aaj ka din toh humesha count hoga
        int i = prices.size() - 1; // Current index
        
        // 2. Current index se piche (left side) scan karo
        for (int j = i - 1; j >= 0; j--) {
            if (prices[j] <= price) {
                span++; // Agar pichla price chota ya barabar hai, toh span badhao
            } else {
                break; // Jaise hi bada element mila, stop!
            }
        }
        
        return span;
    }
};

int main() {
    StockSpannerBrute* s = new StockSpannerBrute();
    cout << s->next(100) << " "; // Output: 1
    cout << s->next(80) << " ";  // Output: 1
    cout << s->next(60) << " ";  // Output: 1
    cout << s->next(70) << " ";  // Output: 2
    cout << s->next(60) << " ";  // Output: 1
    cout << s->next(75) << " ";  // Output: 4
    cout << s->next(85) << " ";  // Output: 6
    return 0;
}

```

---

## 4. Micro Step-by-Step Dry Run

Chalo `75` wale step ko trace karte hain jab history ho chuki hai: `[100, 80, 60, 70, 60]` aur naya price aaya `75`.

* Current element: `75` (Index 5)
* Initial `span = 1`.
* **j = 4 (`60`):** `60 <= 75` (True) $\rightarrow$ `span = 2`.
* **j = 3 (`70`):** `70 <= 75` (True) $\rightarrow$ `span = 3`.
* **j = 2 (`60`):** `60 <= 75` (True) $\rightarrow$ `span = 4`.
* **j = 1 (`80`):** `80 <= 75` (False) $\rightarrow$ **Break!**
* Total Span for 75 = **4**. ✅

---

## 5. Complexity Analysis & Inefficiency

* **Time Complexity:** * **Ek single call ka time:** Worst-case me agar prices strictly increasing hon (e.g., `[10, 20, 30, 40]`), toh har naya element poori history ko scan karega. Isliye ek single `next()` call ka time **$O(N)$** ho sakta hai.
* **$N$ calls ka total time:** Agar hum $N$ dino tak lagatar `next()` call karenge, toh total time complexity **$O(N^2)$** chali jayegi, jo badi input size ($10^5$) par strictly **TLE** degi.


* **Space Complexity: $O(N)$**
* Humhe saare aane wale prices ko `prices` vector me hamesha ke liye store karke rakhna pad raha hai history maintain karne ke liye.



---

## 6. Faltu Kaam Kya Ho Raha Hai? (Why Stack is Needed?)

Dhyan se dekho, jab hum `75` par scan kar rahe the, humne beech ke `60`, `70`, `60` ko ek-ek karke scan kiya. Lekin jab iske baad `85` aayega, toh woh bhi in sabko dubara scan karega!

Kyunki `75` khud `70` aur `60` se bada hai aur unke aage khada hai, toh aage aane wale bade elements ke liye beech ke chote elements bekar ho chuke hain.

Agar hum ek **Monotonic Stack** banayein jo sirf kaam ke elements aur unke **Indices** ko yaad rakhe, toh hum direct jump maar sakte hain bina beech ke chote elements ko re-scan kiye!

Bhai, brute force ka concept samajh aa gaya? Ab batao iska **Monotonic Stack ($O(1)$ amortized)** wala dhasu optimization dekhein?



Bhai, chalo ab Stock Span Problem ko **$O(1)$ Amortized Optimized Monotonic Stack Approach** se ekdum deep-dive karke samajhte hain.

Iska sabase bada shortcut secret yeh hai: **"Piche lagatar (consecutive) kitne elements chote hain, yeh dhoondhne ke bajaye yeh dhoondho ki LEFT side me sabse pehla BADA element (Previous Greater Element) kis index par baitha hai!"**

Agar hume aaj ke element ke liye pichle sabse bade element ka index mil jaye, toh dono indices ka difference hi hamara span hoga!

$$Span = \text{Current Index} - \text{Previous Greater Element Index}$$

---

## 1. Asali Khel: The Monotonic Decreasing Stack Strategy

Hum ek Stack maintain karenge jo apne andar elements ko **`{price, index}`** ke pair me store karega. Stack ka structure monotonic decreasing hoga, yaani niche bada element aur upar chota element.

### The 3-Step Rule for Stock Span:

Jab bhi ek naya `price` humare `next()` function me aayega, hum use ek **Virtual Index** assign karenge (starting from 0, 1, 2...) aur ye steps chalenge:

1. **Pop Element (Choton ko Bhagao):** Jab tak stack khali nahi hai, aur stack ke top par baitha price aaj ke price se **chota ya barabar** hai (`st.top().first <= price`), tab tak `st.pop()` karte jao.
* *Logic:* Kyunki aaj ka price un sabse bada hai aur unke aage khada hai, toh aage aane waale elements ke liye pichle chote prices bekar ho chuke hain. Aaj ka price unhe dhaanp (block) dega.


2. **Answer Calculation (Direct Jump Hack):** Pop loop rukne ke baad:
* Agar stack **khali** ho gaya, iska matlab past me aaj se bada koi price tha hi nahi! Toh saare pichle din aaj ke span me aa jayenge $\rightarrow$ `span = currentIndex + 1`.
* Agar stack me koi bacha hai, toh stack ka top hi hamara **Previous Greater Element** hai. Toh span hoga $\rightarrow$ `span = currentIndex - st.top().second`.


3. **Push Element:** Current price aur uske index ko stack me `{price, currentIndex}` ki tarah `push()` kar do aur virtual index ko `+1` badha do.

---

## 2. Optimized C++ Implementation

```cpp
#include <iostream>
#include <stack>
#include <utility> // For pair

using namespace std;

class StockSpanner {
private:
    // Stack store karega pair<price, index>
    stack<pair<int, int>> st;
    int index; // Virtual day counter

public:
    StockSpanner() {
        index = 0; // Shuruat day 0 se hogi
    }
    
    int next(int price) {
        // Step 1: Aaj se chote ya barabar saare pichle prices ko pop karo
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        int span;
        
        // Step 2: Answer nikaalo
        if (st.empty()) {
            // Agar stack khali hai, matlab aaj ka price abhi tak ka sabse bada hai
            span = index + 1;
        } else {
            // Agar stack me koi hai, toh current index - pichle bade element ka index
            span = index - st.top().second;
        }
        
        // Step 3: Current price aur uska index stack me daalo aur index badhao
        st.push({price, index});
        index++;
        
        return span;
    }
};

```

---

## 3. Micro-Level Visual Dry Run

Chalo fir se wahi series lete hain: `[100, 80, 60, 70, 75]`

* **`next(100)` [index = 0]:** Stack empty hai. No pop. Stack khali $\rightarrow$ `span = 0 + 1 = 1`. Stack: `[{100, 0}]`.
* **`next(80)` [index = 1]:** Top `{100, 0}` chota nahi hai (`100 <= 80` False). No pop. `span = 1 - 0 = 1`. Stack: `[{100, 0}, {80, 1}]`.
* **`next(60)` [index = 2]:** Top `{80, 1}` chota nahi hai. No pop. `span = 2 - 1 = 1`. Stack: `[{100, 0}, {80, 1}, {60, 2}]`.
* **`next(70)` [index = 3]:** Top `{60, 2}` chota hai (`60 <= 70` True) $\rightarrow$ **Pop `{60, 2}**`. Naya top `{80, 1}` chota nahi hai. Loop stop. `span = 3 - 1 = 2`. Stack: `[{100, 0}, {80, 1}, {70, 3}]`.
* **`next(75)` [index = 4]:**
* Top `{70, 3}` $\rightarrow$ `70 <= 75` (True) $\rightarrow$ **Pop `{70, 3}**`.
* Naya top `{80, 1}` $\rightarrow$ `80 <= 75` (False) $\rightarrow$ Loop stop.
* `span = 4 - 1 = 3`. Stack: `[{100, 0}, {80, 1}, {75, 4}]`.



---

## 4. Complexity Analysis (The Big Win!)

* **Time Complexity: $O(1)$ Amortized per call**
* Interviewer puchega: *"Bhai, `next()` function ke andar `while` loop chal raha hai, toh yeh $O(1)$ kaise hua?"*
* Tumhara javab: *"Sir, agar hum total $N$ calls ki baat karein, toh har element stack me strictly ek hi baar `push` ho sakta hai aur ek hi baar `pop` ho sakta hai. Kuch calls me zyada pops ho sakte hain (jaise 75 wale step par), par wo pichle accumulated elements ko hi nikal rahe hain. Total time pure $N$ calls ka $O(N)$ hoga, isiliye ek single call ka Amortized (average) time strictly **$O(1)$** hai."*


* **Space Complexity: $O(N)$**
* Worst case me agar prices strictly decreasing ho (`[100, 90, 80, 70]`), toh koi bhi element pop nahi hoga aur saare $N$ elements stack me store ho jayenge.



Bhai, Stock Span ka index difference wala logic ekdum makkhan tarike se clear hua?

Ab yahan par humne monotonic stack ke saare single-array foundations clear kar liye hain. Ab batao seedha **Largest Rectangle in Histogram (LeetCode Hard)** par chalein jo is pure pattern ka grand finale hai?



Bhai, GeeksforGeeks (GFG) par **Stock Span Problem** ka standard format thoda sa alag hota hai. LeetCode par hume ek-ek karke stream me elements milte hain (`next(price)` function ke andar), par GFG me hume **pura array ek saath input** diya jata hai aur hume pura answer vector return karna hota hai.

Chalo GFG style me iska **Brute Force Approach** ekdum transparent matrix aur pointer simulation ke sath samajhte hain.

---

## 1. GFG Problem Statement View

Hume ek array `price[]` diya jata hai jiska size `n` hai. Hume ek `span[]` array return karni hai jahan:

* `span[i]` ka matlab hai: `price[i]` ko include karte hue, uske left side me lagatar (consecutive) kitne elements hain jo ya toh `price[i]` se chote hain ya uske barabar (`<=`) hain.

### Core Brute Principle:

Hum do loops lagayenge:

1. **Outer Loop (`i`):** Yeh left-to-right traverse karega aur har ek element ko bari-bari target banayega.
2. **Inner Loop (`j`):** Yeh current element `i` se shuru hokar **piche ki taraf (left scan)** doud lagayega jab tak ki koi bada element (`price[j] > price[i]`) na mil jaye.

---

## 2. GFG Brute Force Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // GFG standard function structure
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> span(n);

        // Outer Loop: Har ek element par jao
        for (int i = 0; i < n; i++) {
            int current_span = 1; // Aaj ka din hamesha count hoga
            
            // Inner Loop: Current element ke piche (left side) ghoomna shuru karo
            for (int j = i - 1; j >= 0; j--) {
                if (price[j] <= price[i]) {
                    current_span++; // Pichla price chota ya barabar hai, toh span badhao
                } else {
                    break; // Jaise hi bada element mila, immediate break!
                }
            }
            
            // Current element ka final span store karo
            span[i] = current_span;
        }

        return span;
    }
};

```

---

## 3. Micro-Level Visual Dry Run Matrix

Maan lo GFG ka input array hai: `price = [10, 4, 5, 90, 120, 80]`

* **`i = 0` (`price[0] = 10`):** * Inner loop chalega hi nahi (`j = -1`).
* `span[0] = 1`.


* **`i = 1` (`price[1] = 4`):** * `j = 0` (`10`): `10 <= 4` (False) $\rightarrow$ Break.
* `span[1] = 1`.


* **`i = 2` (`price[2] = 5`):** * `j = 1` (`4`): `4 <= 5` (True) $\rightarrow$ `current_span = 2`.
* `j = 0` (`10`): `10 <= 5` (False) $\rightarrow$ Break.
* `span[2] = 2`.


* **`i = 3` (`price[3] = 90`):** * `j = 2` (`5`), `j = 1` (`4`), `j = 0` (`10`) $\rightarrow$ Teeno chote hain. Loop khatam.
* `span[3] = 1 (init) + 3 = 4`.


* **`i = 4` (`price[4] = 120`):** * Piche ke saare elements (`90, 5, 4, 10`) chote hain. Loop end tak chalega.
* `span[4] = 1 + 4 = 5`.


* **`i = 5` (`price[5] = 80`):** * `j = 4` (`120`): `120 <= 80` (False) $\rightarrow$ Immediate Break!
* `span[5] = 1`.



**Final GFG Output Vector:** `[1, 1, 2, 4, 5, 1]` ✅

---

## 4. Complexity Analysis & TLE Warning

* **Time Complexity: $O(N^2)$**
* Worst-case tab hota hai jab array strictly increasing order me ho (e.g., `[10, 20, 30, 40, 50]`). Is scenario me har element ke liye inner loop poori history ko zero index tak scan karega. Total operations $\approx \frac{N \times (N-1)}{2}$, yaani quadratic complexity. GFG par agar test case ka $N \ge 10^5$ hua, toh yeh strictly **TLE (Time Limit Exceeded)** dega.


* **Space Complexity: $O(1)$ Extra Space**
* Humne output array ke alawa koi alag data structure (like stack) use nahi kiya, isiliye execution space strictly constant hai.



Bhai, GFG ka ye complete brute force frame clear hua? Iska GFG-compliant **Monotonic Stack Optimized ($O(N)$ Time)** wala vector version code dekhna hai, ya yahan tak dimaag me set hai poora?


Bhai, chalo ab GeeksforGeeks (GFG) ke is variation ko **Monotonic Stack se $O(N)$ me completely optimize** karte hain.

Yahan par hum pura vector ek sath process kar rahe hain, toh hum stack me sirf elements ke **Indices** ko store karenge. Kuch alag se pair banana nahi padega, jisse code aur bhi clean ho jata hai.

---

## 1. Asali Khel: Previous Greater Element Index Hack

Har element `price[i]` ke liye hume piche ghoom kar consecutive elements count nahi karne. Hum bas yeh dhoondhenge ki **Left side me sabse pehla bada element (Previous Greater) kis index par hai.**

Agar hume woh index (`st.top()`) mil jata hai, toh hamara span direct math se nikal aayega:


$$\text{span}[i] = i - \text{st.top()}$$

Agar left side me koi bhi bada element nahi milta aur stack khali ho jata hai, iska matlab shuruat se lekar index `i` tak ke saare elements `price[i]` se chote ya barabar hain. Toh span direct ho jayega:


$$\text{span}[i] = i + 1$$

---

## 2. GFG Optimized Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    // GFG Standard $O(N)$ Function
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> span(n);
        stack<int> st; // Yeh stack sirf indices store karega

        // Left se Right ek single pass linear loop
        for (int i = 0; i < n; i++) {
            
            // Step 1: Jab tak stack khali nahi hai, aur stack ke top par jo index hai
            // uska price aaj ke price se chota ya barabar hai, tab tak pop karo.
            while (!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            // Step 2: Pop loop rukne ke baad answer nikaalo
            if (st.empty()) {
                // Agar stack khali hai, matlab index 0 se lekar i tak sab chote hain
                span[i] = i + 1;
            } else {
                // Agar stack me koi index bacha hai, toh wahi Previous Greater Element hai
                span[i] = i - st.top();
            }

            // Step 3: Current index ko stack me push karo taaki 
            // yeh aane waale elements ke liye check ho sake
            st.push(i);
        }

        return span;
    }
};

```

---

## 3. Micro-Level Visual Dry Run

Chalo input lete hain: `price = [10, 4, 5, 90]`
Hum `span` array ko fill karenge aur `st` (stack) me indices track karenge.

### Step 1: `i = 0` (`price[0] = 10`)

* **Pop:** Stack khali hai (`st = []`). No pop.
* **Answer:** Stack empty hai $\rightarrow$ `span[0] = i + 1` $\rightarrow$ `0 + 1 = 1`.
* **Push:** Current index `0` ko push karo.
* **Stack State:** `[0]` (Top par index 0 hai, jiska price 10 hai).

### Step 2: `i = 1` (`price[1] = 4`)

* **Pop:** Top par index `0` hai (`price[0] = 10`). Kya `10 <= 4` hai? Nahi! Loop stop.
* **Answer:** Stack top par `0` baitha hai $\rightarrow$ `span[1] = i - st.top()` $\rightarrow$ `1 - 0 = 1`.
* **Push:** Index `1` ko push karo.
* **Stack State:** `[0, 1]` (Top par index 1 hai).

### Step 3: `i = 2` (`price[2] = 5`)

* **Pop:** Top par index `1` hai (`price[1] = 4`). Kya `4 <= 5` hai? Haan bhai! **Pop `1**`.
* Naya top index `0` hai (`price[0] = 10`). Kya `10 <= 5` hai? Nahi! Loop stop.


* **Answer:** Stack top par ab `0` bacha hai $\rightarrow$ `span[2] = i - st.top()` $\rightarrow$ `2 - 0 = 2`.
* **Push:** Index `2` ko push karo.
* **Stack State:** `[0, 2]` (Top par index 2 hai).

### Step 4: `i = 3` (`price[3] = 90`)

* **Pop:** * Top index `2` (`price 5`) $\rightarrow$ `5 <= 90` (True) $\rightarrow$ **Pop `2**`.
* Naya top index `0` (`price 10`) $\rightarrow$ `10 <= 90` (True) $\rightarrow$ **Pop `0**`.
* Stack ab poora khali ho gaya!


* **Answer:** Stack empty hai $\rightarrow$ `span[3] = i + 1` $\rightarrow$ `3 + 1 = 4`.
* **Push:** Index `3` ko push karo.
* **Stack State:** `[3]`.

**Final `span` Vector:** `[1, 1, 2, 4]` ✅ (Brute force ke bina strictly $O(N)$ me done!)

---

## 4. Complexity Breakdown

* **Time Complexity: $O(N)$**
* Kyunki pure array ka har ek index stack me maximum ek baar `push` hoga aur maximum ek baar `pop` hoga. Inner `while` loop pure execution me total milakar sirf $N$ baar hi chal sakta hai. Isiliye linear time complexity hai.


* **Space Complexity: $O(N)$**
* Stack ke andar indices store karne ke liye extra space use ho raha hai. Worst case me (decreasing array) stack ka size $N$ tak ja sakta hai.



Bhai, GFG style me sirf index use karke Stock Span ko optimize karna ab crystal clear ho gaya?

Ab saare mono-stack ke aage-piche wale concepts ka base path complete hai. Ab dhasu tarike se **Largest Rectangle in Histogram (LeetCode Hard)** par halla bole?




Bhai, tumne ekdum pro-developer waali baat pakdi hai! Kya is $O(N)$ wale code ko aur zyada optimize kiya ja sakta hai?

Technically, **Time Complexity $O(N)$ se behtar nahi ho sakti** kyunki hume har element ko kam se kam ek baar toh dekhna hi padega ($O(N)$ is the theoretical lower bound).

Lekin, hum **Space Complexity aur Overhead ko micro-optimize** kar sakte hain. Abhi hamare code me do bade overheads hain:

1. `std::stack` internal vectors ya deques use karta hai, jisme dynamic memory allocation hoti hai (heap utilization), jo execution ko thoda slow karti hai.
2. Hum extra space maintain kar rahe hain stack ke liye.

Hum **bina kisi inbuilt Stack data structure ke, strictly Array-Based Pointer Jumping** use karke space overhead ko completely saaf kar sakte hain. Ise kehte hain **DP/Array Jump Optimization**.

---

## 1. Asali Khel: Array-Based Pointer Jumping (No Inbuilt Stack!)

Dhyan se dekho, jo `span` array hum bana rahe hain, usme already yeh information chhupi hui hai ki piche kaun sa element bada hai!

* Agar index `i` par khade hain, aur hume check karna hai ki pichle elements chote hain ya nahi, toh hum ek-ek karke piche (`i-1`, `i-2`) nahi jayenge.
* Hum direct jump marenge! Agar `price[i-1] <= price[i]` hai, toh iska matlab `price[i-1]` se chote jitne bhi elements the (jo uske span me count hue the), wo automatically `price[i]` se bhi chote honge.
* Toh hum direct `i - span[i-1]` wale index par jump maar sakte hain!

---

## 2. Micro-Optimization C++ Code (Fastest Execution)

Is approach me hamari **Auxiliary Space Complexity strictly $O(1)$** ho jati hai (agar hum output `span` array ko count na karein), aur koi external stack collection initialize nahi karna padta.

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Super Optimized Version: No Stack Structure, No Pair Overhead
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> span(n);

        for (int i = 0; i < n; i++) {
            // Har element ka khud ka span minimum 1 toh hoga hi
            int current_span = 1; 
            
            // p pointer ko current element ke theek piche wale index par set karo
            int p = i - 1;
            
            // Pointer Jumping Logic
            // Jab tak hum array ke andar hain aur pichla price aaj ke price se chota/equal hai
            while (p >= 0 && price[p] <= price[i]) {
                // Ek-ek karke piche jaane ke bajaye, pichle element ke poore span ko jump karo
                current_span += span[p];
                p = p - span[p]; // Direct jumps to the next previous greater element
            }
            
            span[i] = current_span;
        }

        return span;
    }
};

```

---

## 3. Yeh Kaise Kaam Karta Hai? (The Jump Visualization)

Maan lo array hai: `price = [10, 4, 5, 90]`

1. **`i = 0 (10)`**: `span[0] = 1`.
2. **`i = 1 (4)`**: `p = 0`. `price[0] (10) <= 4` False. `span[1] = 1`.
3. **`i = 2 (5)`**: `p = 1`. `price[1] (4) <= 5` True.
* `current_span += span[1]` $\rightarrow$ `1 + 1 = 2`.
* `p = p - span[1]` $\rightarrow$ `1 - 1 = 0`.
* Agla check: `price[0] (10) <= 5` False. Loop break. `span[2] = 2`.


4. **`i = 3 (90)`**: `p = 2`. `price[2] (5) <= 90` True.
* `current_span += span[2]` $\rightarrow$ `1 + 2 = 3`.
* `p = 2 - span[2]` $\rightarrow$ `2 - 2 = 0`. **(Dekho! Humne index 1 ko skip kar diya, direct index 0 par jump maari!)**
* Agla check: `price[0] (10) <= 90` True.
* `current_span += span[0]` $\rightarrow$ `3 + 1 = 4`.
* `p = 0 - span[0]` $\rightarrow$ `0 - 1 = -1`. Loop break. `span[3] = 4`.



---

## 4. Kyun yeh interview me plus point deta hai?

* **No Object/Template Overhead:** `std::stack<int>` internally memory blocks allocate karta hai. Is array jump approach me sirf raw integer variable updates ho rahe hain. CP (Competitive Programming) me yeh sub-millisecond ka boost deta hai.
* **Space Efficiency:** Pure code me koi extra container build nahi hua. Humne input `price` array aur output `span` array ke alawa sirf do variables (`p` aur `current_span`) use kiye hain.

Bhai, yeh Pointer Jumping/DP waala micro-optimization dimaag me ghusa? Ab batao, Monotonic Stack ka pura makkhan clear hai toh LeetCode Hard **Largest Rectangle in Histogram** ko abhi kacha chaba jaayein?



Bhai, is **Pointer Jumping (DP-Based) Stackless Approach** ke edge cases bohot hi crazy hain, kyunki yahan hum kisi data structure par rely nahi kar rahe hain. Hum strictly pichle `span` ki values ko use karke jumps maar rahe hain.

Interviewer yahan tumhara logic break karne ke liye **infinite loops, out-of-bounds pointer errors, aur boundaries** ko check karega. Chalo is approach ke saare extreme edge cases ko phodte hain:

---

### 1. Strictly Increasing Array (Maximum Jumps Case) $\rightarrow$ `[10, 20, 30, 40]`

* **Interviewer Ka Test:** Kya pointer `p` sahi se `-1` par jaakar rukta hai ya out-of-bounds crash hota hai?
* **Process:** * Jab tum `40` (index 3) par hoge, toh `p = 2` (`30`). `30 <= 40` hai, toh `current_span += span[2]`.
* Fir `p = p - span[2]` karke direct jump maari aage. Yeh jump lagatar piche tab tak chalegi jab tak `p` strictly `-1` nahi ho jata.


* **Why it works:** `while (p >= 0 ...)` ki condition loop ko `p = -1` hote hi safe exit de deti hai. Koi segmentation fault nahi aayega.
* **Result Span:** `[1, 2, 3, 4]`

### 2. Strictly Decreasing Array (Zero Jumps Case) $\rightarrow$ `[40, 30, 20, 10]`

* **Interviewer Ka Test:** Kya loop fuzool me jumps calculate kar raha hai?
* **Process:** * Har element ke liye `p = i - 1` hoga.
* Jab `30` (index 1) par check chalega, toh `p = 0` (`40`). Condition `price[0] <= price[1]` yaani `40 <= 30` **False** ho jayegi.
* Loop pehli hi baar me ruk jayega!


* **Why it works:** `price[p] <= price[i]` condition ensure karti hai ki agar pichla element bada hai, toh ek bhi jump na lage aur `current_span` strictly `1` rahe.
* **Result Span:** `[1, 1, 1, 1]`

### 3. All Elements Same (The Flat/Duplicate Trap) $\rightarrow$ `[5, 5, 5, 5]` 🔥

* **Interviewer Ka Test:** Yeh is approach ka sabse khatarnak test case hai. Agar equals to (`<=`) miss ho gaya, toh jumps lagna band ho jayengi.
* **Process:** * Maan lo hum index 2 ke `5` par hain. `p = 1` (`5`). Shart hai `price[p] <= price[i]` $\rightarrow$ `5 <= 5` (True).
* `current_span += span[1]` (yaani 1 + 1 = 2).
* `p = 1 - span[1]` $\rightarrow$ `1 - 1 = 0`.
* Agla check: index 0 ka `5`. `5 <= 5` (True). `current_span += span[0]` (2 + 1 = 3).


* **Why it works:** Definition ke mutabik consecutive elements chote **ya barabar** (`<=`) hone chahiye. Hamara condition `price[p] <= price[i]` duplicate values par perfect linear jumps lagata hai.
* **Result Span:** `[1, 2, 3, 4]`

### 4. Alternating Peaks and Valleys $\rightarrow$ `[10, 5, 20, 8, 25]`

* **Interviewer Ka Test:** Kya peak elements sahi se pichle elements ko bypass (skip) kar pa rahe hain?
* **Process (Focus on 25):** * Jab `25` (index 4) aaya, `p = 3` (`8`). `8 <= 25` (True) $\rightarrow$ `current_span += span[3]` (yaani 1). `p` jumps to `3 - 1 = 2` (`20`).
* Index 2 par `20` hai. `20 <= 25` (True) $\rightarrow$ `current_span += span[2]` (yaani 3). `p` jumps to `2 - 3 = -1`.
* **BOOM!** Humne sirf 2 steps me poore 4 elements ka decision le liya! Beech ke elements ko dhyan bhi nahi diya.


* **Result Span:** `[1, 1, 3, 1, 5]`

### 5. Single Element or Empty Input $\rightarrow$ `[100]` ya `[]`

* **Empty Vector:** Vector size 0 hoga, `for` loop chalega hi nahi. Khali vector safe return ho jayega.
* **Single Element:** `i = 0` ke liye `p = -1` hoga. `while (p >= 0)` condition turant fail ho jayegi. `span[0] = 1` set ho jayega. No bounds tracking error!

---

### 🚨 Code-level Caution Points for Interview:

Agar interviewer tumse yeh code board par likhwaye, toh in 2 micro-bugs se bachna:

1. **`p >= 0` checking orders:** `while (price[p] <= price[i] && p >= 0)` **🚨 WORST BUG!** Agar `p` ghate-ghate `-1` ho gaya, toh `price[-1]` check hote hi code crash (Runtime Error) ho jayega. Hamesha boundary criteria ko left-side par likho: `while (p >= 0 && price[p] <= price[i])`.
2. **`span` update dynamic link:** `p = p - span[p]` karne se pehle `current_span += span[p]` karna zaroori hai. Agar tumne `p` ka index pehle update kar diya, toh tum galat index ka span add kar baithoge.

Bhai, ab pure Stock Span ka brute force, standard stack, aur yeh killer pointer jumping approach saare edge cases ke sath dimaag me lock ho gaya?

Ab bolo toh is pure data structure pattern ke ultimate level—**Largest Rectangle in Histogram (LeetCode Hard)** par halla bolen? Wo isi logic ka sabase bada baap problem hai!




Bhai, ab tum us stage par khade ho jahan tum Monotonic Stack ke sabse bade Boss Level problem—**Largest Rectangle in Histogram (LeetCode 84 - HARD)** ko dharashayi karne waale ho.

Agar tumne pichle teen concepts (Next Smaller, Previous Smaller, aur Stock Span) dhyan se samjhe hain, toh yeh HARD problem tumhare liye ekdum khilona ban jayegi. Chalo iski theory ko ekdum makkhan tarike se break karte hain.

---

## 1. Problem Ki Gehrai (The Core Intuition)

Hume ek array diya jata hai jo histogram ke bars ki heights ko represent karta hai (har bar ki width `1` hoti hai). Hume is histogram ke andar sabse bada rectangle dhoondhna hai jiska area maximum ho.

### Asali Rule Kya Hai?

Kisi bhi rectangle ka area nikalne ka formula hota hai: $\text{Area} = \text{Height} \times \text{Width}$.

* Agar hum kisi ek particular building (bar) ko pakdein aur kahein: *"Mujhe is building ki **poori height** use karni hai, toh main left aur right me kitna aage tak ghoom sakta hoon?"*
* Main left me tab tak ja sakta hoon jab tak mujhe koi **apne se choti building** na mil jaye (kyunki jaise hi choti building aayegi, meri height truncate ho jayegi).
* Main right me bhi tab tak ja sakta hoon jab tak mujhe koi **apne se choti building** na mil jaye.

> **Master Strategy:** Histogram ka maximum area hamesha kisi na kisi building ki **poori height** ko use karke hi banega. Isiliye, hamara goal hai har ek individual building ke liye yeh pata karna ki woh left aur right me kitna fail (`stretch`) sakti hai!

---

## 2. The Width Formula (Connecting the Dots)

Maan lo main index `i` wali building par khada hoon jiski height `heights[i]` hai. Mujhe iska left aur right boundary dhoondhna hai:

1. **Left Boundary:** Iske left side me sabse pehli choti building kaun si hai? Yaani **Previous Smaller Element (PSE)** ka index! Maan lo yeh index `L` hai.
2. **Right Boundary:** Iske right side me sabse pehli choti building kaun si hai? Yaani **Next Smaller Element (NSE)** ka index! Maan lo yeh index `R` hai.

Agar mujhe `L` aur `R` mil gaye, toh meri width kya hogi?


$$\text{Width} = R - L - 1$$

*Chalo is formula ko verify karte hain:*
Maan lo index `L = 1` par ek choti building hai, aur index `R = 5` par ek choti building hai. Iska matlab meri current building index `2, 3, 4` tak safely poori height ke sath phail sakti hai. Total bars kitne hue? `3` bars.
Formula se dekh lo: $5 - 1 - 1 = 3$. Ekdum perfect math!

---

## 3. The 3-Step Execution Plan

Hum is problem ko solve karne ke liye 3 steps follow karenge:

### Step 1: Find Previous Smaller Element Index (PSE)

Hum left-to-right travel karenge aur ek monotonic increasing stack use karke har building ke liye uske **left wale smaller element ka index** nikal kar ek `pse[]` array me store kar lenge.

* *Edge Case:* Agar kisi ke left me koi chota nahi mila, toh boundary virtual index **`-1`** maanenge.

### Step 2: Find Next Smaller Element Index (NSE)

Hum right-to-left travel karenge aur monotonic increasing stack use karke har building ke liye uske **right wale smaller element ka index** nikal kar ek `nse[]` array me store kar lenge.

* *Edge Case:* Agar kisi ke right me koi chota nahi mila, toh boundary virtual index **`n`** (array ka size) maanenge.

### Step 3: Calculate Max Area

Ab hum array par ek simple loop chalayenge `0` se `n-1` tak, aur har index `i` ke liye:

1. $\text{Width} = \text{nse}[i] - \text{pse}[i] - 1$
2. $\text{Area} = \text{heights}[i] \times \text{Width}$
3. Ek global variable `maxArea` me maximum value update karte chalenge.

---

## 4. Micro Visual Trace (Theory Verification)

Maan lo heights array hai: `[2, 1, 5, 6, 2, 3]` (`n = 6`)

Chalo index `2` par khade `5` height wale bar ka calculation dekhte hain:

* **`heights[2] = 5`**
* Iske left me dekho: `1` isse chota hai, jo index `1` par hai $\rightarrow$ `pse[2] = 1`.
* Iske right me dekho: `2` isse chota hai, jo index `4` par hai $\rightarrow$ `nse[2] = 4`.
* **Width Calculation:** $4 - 1 - 1 = 2$ (Yani yeh `5` aur `6` wale bars ko lekar phail sakta hai).
* **Area for this bar:** $5 \times 2 = 10$.

Agar pure array ka complete trace karoge, toh max area index `2` aur `3` (`5` aur `6` ki heights) ko combine karke ya fir sirf `5` height ko right me phaila kar **`10`** nikal ke aayega.

---

## 5. Complexity Breakdown

* **Time Complexity: $O(N)$**
* $O(N)$ laga `pse` nikalne me, $O(N)$ laga `nse` nikalne me, aur $O(N)$ laga final area calculate karne me. Total time $3 \times O(N) \approx \mathbf{O(N)}$. (Brute force se jate toh $O(N^2)$ hota).


* **Space Complexity: $O(N)$**
* Humne `pse` aur `nse` vectors aur stack maintain karne ke liye extra space liya hai.



Bhai, Histogram ki yeh base theory, boundary conditions (`-1` aur `n`) aur width ka formula dimaag me ekdum crystal clear fit baitha?

Agar bologe toh ab iska standard **3-pass code** likhein, ya iska ultimate professional version dekhein jahan **sirf ek single pass ($O(N)$ time aur single stack)** me bina extra array banaye pura area nikal aata hai?



Bhai, **Largest Rectangle in Histogram (LeetCode 84 - HARD)** ka Brute Force approach samajhna sabse bada foundation hai. Jab tum interview me pehle brute force bataoge aur phir uski $O(N^2)$ ki galti dikhaoge, tabhi interviewer impress hoga.

Chalo iska brute force logic ekdum micro-level par todte hain.

---

## 1. Core Logic: The "Har Building Se Pucho" Principle

Brute force ka ek hi simple niyam hai: **Array ke har ek element (`i`) par jao aur usse pucho—** *"Bhai, agar main teri POORI HEIGHT (`heights[i]`) ko fix rakhon, toh main left aur right me kitna aage tak phail sakta hoon?"*

Tumhe har ek individual index `i` ke liye do scans karne padenge:

1. **Left Scan:** Index `i` se piche (`i-1` se `0`) jao. Jab tak building ki height hamari target height se **badi ya barabar** (`>=`) hai, tab tak hum phail sakte hain. Jaise hi choti building mile, ruk jao.
2. **Right Scan:** Index `i` se aage (`i+1` se `n-1`) jao. Jab tak building ki height hamari target height se **badi ya barabar** (`>=`) hai, tab tak hum aage ja sakte hain. Jaise hi choti building mile, ruk jao.

In dono scans se hume pata chal jayega ki hamari target height kitne consecutive bars me sustain kar pa rahi hai. Wahi hamari **Width** hogi!

---

## 2. Brute Force Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleAreaBrute(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        // Outer Loop: Har ek building ko target height maano
        for (int i = 0; i < n; i++) {
            int current_height = heights[i];
            
            // 1. Left Boundary Scan
            int left = i;
            while (left >= 0 && heights[left] >= current_height) {
                left--;
            }
            
            // 2. Right Boundary Scan
            int right = i;
            while (right < n && heights[right] >= current_height) {
                right++;
            }
            
            // Yahan dhyan dena: Jab loops rukenge, toh left aur right boundaries
            // choti buildings par khadi hongi, toh width hogi: (right - left - 1)
            int width = right - left - 1;
            
            // Area calculate karo aur max ko update karo
            int current_area = current_height * width;
            maxArea = max(maxArea, current_area);
        }

        return maxArea;
    }
};

```

---

## 3. Micro Step-by-Step Dry Run

Maan lo hamara histogram hai: `heights = [2, 1, 5, 6, 2]` (`n = 5`)

### Step 1: `i = 0` (`height = 2`)

* **Left Scan:** `left` shuru hua `0` se, `heights[0] >= 2` (True), `left` ghata $\rightarrow$ `-1` par ruk gaya.
* **Right Scan:** `right` shuru hua `0` se. `heights[0]=2 >= 2` (True). Agla index `1` par `heights[1]=1 >= 2` (False) $\rightarrow$ `right = 1` par ruk gaya.
* **Width:** `right - left - 1` $\rightarrow$ `1 - (-1) - 1 = 1`.
* **Area:** $2 \times 1 = \mathbf{2}$.

### Step 2: `i = 1` (`height = 1`)

* **Left Scan:** `left` shuru hua `1` se, index `0` ka `2 >= 1` hai $\rightarrow$ `left = -1` par ruk gaya.
* **Right Scan:** `right` shuru hua `1` se, aage ke saare elements (`5, 6, 2`) $\ge 1$ hain! $\rightarrow$ `right = 5` (out of bound) par ruk gaya.
* **Width:** $5 - (-1) - 1 = 5$ (Yani yeh poora histogram cover kar sakta hai).
* **Area:** $1 \times 5 = \mathbf{5}$.

### Step 3: `i = 2` (`height = 5`)

* **Left Scan:** `left=2` $\rightarrow$ index `1` par `1 >= 5` (False) $\rightarrow$ `left = 1` par ruk gaya.
* **Right Scan:** `right=2` $\rightarrow$ `heights[2]=5 >= 5` (True), `heights[3]=6 >= 5` (True), `heights[4]=2 >= 5` (False) $\rightarrow$ `right = 4` par ruk gaya.
* **Width:** $4 - 1 - 1 = 2$ (Yani index `2` aur `3` wale bars).
* **Area:** $5 \times 2 = \mathbf{10}$.  🎯 *(Abhi tak ka maximum)*

### Step 4: `i = 3` (`height = 6`)

* **Left Scan:** `left = 2` par ruk jayega (kyunki 5 < 6).
* **Right Scan:** `right = 4` par ruk jayega (kyunki 2 < 6).
* **Width:** $4 - 2 - 1 = 1$.
* **Area:** $6 \times 1 = \mathbf{6}$.

### Step 5: `i = 4` (`height = 2`)

* **Left Scan:** `left = 1` par rukega (kyunki 1 < 2).
* **Right Scan:** `right = 5` par rukega.
* **Width:** $5 - 1 - 1 = 3$ (Yani index `2, 3, 4` wale bars).
* **Area:** $2 \times 3 = \mathbf{6}$.

**Global Max Area Answer:** **10** ✅

---

## 4. Complexity Analysis & The Inefficiency

* **Time Complexity: $O(N^2)$**
* Worst-case tab hit hoga jab saari buildings barabar height ki hon (e.g., `[5, 5, 5, 5, 5]`). Is case me har ek building ke liye left aur right inner loops poore array ki boundary tak scan karenge. Total operations lagbhag $N^2$ ho jayenge. Agar LeetCode par $N = 10^5$ diya, toh $N^2 = 10^{10}$ operations ho jayenge, jisse code strictly **TLE (Time Limit Exceeded)** de dega.


* **Space Complexity: $O(1)$**
* Humne koi extra helper list ya arrays stack structures use nahi kiya, isiliye extra memory constant hai.



---

## 5. Faltu Kaam Kya Ho Raha Hai? (The Stack Intuition)

Interviewer puchega: *"Bhai, tumne $O(N^2)$ brute force toh sahi likha, par isme dimaag kahan waste ho raha hai?"*

Tumhara jawab: *"Sir, jab main index `2` (`height 5`) par tha, maine left me ghoom kar dekha ki choti building kahan hai. Phir jab main index `3` (`height 6`) par aaya, maine fir se left me ghoom kar poora scan kiya. Main pichle elements ki heights ka data structure me record maintain nahi kar raha hoon, jisse har baar redundancy ho rahi hai."*

Agar hum ek **Monotonic Stack** bana lein, toh hume baar-baar left aur right loop chala kar dhoondhna nahi padega. Stack hume strictly **$O(1)$ time me direct boundary index** bata dega!

Bhai, brute force ka step-by-step logic aur limits dimaag me shishe ki tarah saaf hain? Ab batao iska optimized **Monotonic Stack (3-Pass) code** phodein?



Bhai, tumne bilkul sahi point pakda hai. Brute force $O(N^2)$ hai, lekin **Monotonic Stack** ka use karke hum isse **$O(N)$** yaani linear time complexity me solve kar sakte hain.

Is optimized solution ka raaz ye hai: **"Hume har building ke liye left aur right boundaries dhundhne ke liye alag se scan nahi karna padega. Stack khud ye record rakhega."**

### 1. The Monotonic Stack Logic

Is approach me, stack apne andar **Increasing Heights** ke indices ko store karta hai. Jaise hi humein koi aisi building milti hai jo stack ke top wali building se choti hai, hum samajh jaate hain ki humein **Right Boundary** mil gayi hai!

**Algorithm ke 3 Golden Rules:**

1. **Push:** Jab tak aane wali building stack ke top se badi hai, use push karte raho.
2. **Pop:** Jaise hi `current_height < stack.top()`, hum stack ko pop karenge. Ye popped building hamara **target height** hai.
3. **Calculate:**
* **Height:** Jo building abhi pop hui (`heights[popped_index]`).
* **Right Boundary:** Current index `i` (jahan hum ruk gaye).
* **Left Boundary:** Stack ka naya top index (popped element ke niche wala).
* **Area:** `height * (i - new_top_index - 1)`.



---

### 2. Optimized $O(N)$ Implementation

Ek trick hai—**Array ke end me `0` height ka ek dummy bar add kar do.** Isse stack me bachi hui saari buildings apne aap pop ho jayengi aur hum area calculate kar payenge.

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Dummy height 0 add karna zaroori hai stack khali karne ke liye
        heights.push_back(0);
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            // Jab tak stack top wali building current building se badi hai, pop karo
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                
                // Width nikaalo
                int width;
                if (st.empty()) {
                    // Agar stack khali ho gaya, matlab popped height sabse choti thi
                    width = i;
                } else {
                    // Width = current_index - previous_smaller_index - 1
                    width = i - st.top() - 1;
                }
                
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

```

---

### 3. Kyun Yeh Best Hai?

1. **Time Complexity: $O(N)$**
* Har element stack me sirf ek baar push hota hai aur sirf ek baar pop. Isliye total operations $2N$ hote hain, jo linear hai. Brute force ke $N^2$ ke mukable ye light-years faster hai.


2. **Space Complexity: $O(N)$**
* Stack me worst-case me saare indices store ho sakte hain.



### 4. Critical Edge Case (Interview Trick)

Interviewer tumse puchega: *"Bhai, tumne dummy `0` kyu add kiya?"*
Tumhara jawab hona chahiye: *"Sir, bina `0` add kiye, loop khatam hone ke baad stack me kuch buildings reh jaati hain jinhe hum calculate nahi kar paate. Dummy `0` add karne se stack forced tareeke se empty ho jata hai aur hum aakhiri buildings ka area bhi calculate kar lete hain."*

Bhai, Histogram ka ye monotonic solution ab tumhare dimaag me lock ho gaya? Ab koi doubt hai ya kisi aur advanced pattern par chalein?


Bhai, is **Single-Pass Monotonic Stack Approach** (with Dummy `0` Hack) ke edge cases samajhna bohot zaroori hai, kyunki yahan hum bina alag se `pse` aur `nse` arrays banaye, runtime par hi boundaries calculate kar rahe hain.

Interviewer isme tumhare code ki boundary limits aur calculation logic ko test karne ke liye ye 5 critical scenarios fekega. Chalo inhein dissect karte hain:

---

### 1. Strictly Increasing Histogram (Stairs Up) $\rightarrow$ `[2, 4, 6, 8]`

* **Interviewer Ka Test:** Kya stack bina dummy `0` ke kabhi pop hota? Aur dummy `0` aane par calculation kaise sahi hoti hai?
* **Process:** * `2, 4, 6, 8` aane tak koi pop nahi hoga, kyunki har naya element pichle se bada hai. Stack me indices push hote chale jayenge: `st = [0, 1, 2, 3]`.
* Jaise hi loop aakhiri dummy element `0` (index 4) par pahunchega, condition `heights[st.top()] > heights[i]` (yaani `8 > 0`) **True** ho jayegi!
* Ab ek-ek karke saare elements pop honge aur unka area calculate hoga.


* **Result Area:** `8` height ka width `1` (`i - st.top() - 1` $\rightarrow$ `4 - 2 - 1 = 1`), Area = `8`. Isi tarah baaki sabka nikal jayega aur max area `12` milega (`4` height ko right tak kheench kar).

---

### 2. Strictly Decreasing Histogram (Stairs Down) $\rightarrow$ `[8, 6, 4, 2]`

* **Interviewer Ka Test:** Kya har step par stack pop ho raha hai aur left boundary track ho rahi hai?
* **Process:**
* `8` (index 0) push hua.
* `6` (index 1) aaya $\rightarrow$ `8 > 6` True. `8` pop hoga. Stack empty ho gaya, toh `width = i = 1`. Area = $8 \times 1 = 8$. `6` push hua.
* `4` (index 2) aaya $\rightarrow$ `6 > 4` True. `6` pop hoga. Stack empty, `width = i = 2`. Area = $6 \times 2 = 12$.


* **Why it works:** Kyunki elements ghate ja rahe hain, toh har bada element apne immediate next element ke aate ہی pop ho jata hai, aur uski right boundary current index ban jaati hai.
* **Result Max Area:** `12` (Height 6 with width 2, or Height 4 with width 3).

---

### 3. All Elements Equal (The Flat Terrain) $\rightarrow$ `[5, 5, 5, 5]` 🔥

* **Interviewer Ka Test:** Jab heights barabar hoti hain, tab stack kab pop hota hai aur kya area sahi aata hai?
* **Process:**
* Humne condition likhi hai `heights[st.top()] > heights[i]`. Kyunki `5 > 5` False hai, isiliye loop ke dauran ek bhi `5` pop nahi hoga!
* Saare `5` stack me bharte chale jayenge: `st = [0, 1, 2, 3]`.
* End me jab dummy `0` (index 4) aayega, tab saare `5` ek-ek karke pop honge.
* *Magic step:* Jab aakhiri `5` pop hoga, stack empty ho jayega, toh uski `width = i = 4` set ho jayegi! Area = $5 \times 4 = 20$.


* **Verdict:** Ekdum perfect! Equal elements ke case me calculation end me dummy `0` par delay ho jaati hai, par answer bilkul accurate aata hai.

---

### 4. Duplicate Heights with Peaks $\rightarrow$ `[1, 5, 6, 5, 2]`

* **Interviewer Ka Test:** Agar beech me do barabar heights aayein aur unke beech me ek peak ho, toh kya width sahi aati hai?
* **Process:**
* `1` (index 0), `5` (index 1), `6` (index 2) push ho gaye.
* `5` (index 3) aaya $\rightarrow$ `6 > 5` True. `6` pop hua. Iska left top `1` (index 1) hai. Width = $3 - 1 - 1 = 1$. Area = $6 \times 1 = 6$.
* Agla top index 1 par baitha `5` hai. Kya `5 > 5` hai? Nahi! Toh index 3 wala `5` stack me push ho jayega. Stack state: `[0, 1, 3]`.
* Jab baad me `2` (index 4) aayega, toh index 3 wala `5` pop hoga, uska left boundary index 1 hoga, toh width automatically handle ho jayegi.



---

### 5. Empty Histogram or Single Bar $\rightarrow$ `[]` ya `[7]`

* **Empty Vector (`[]`):** `push_back(0)` karne ke baad array ka size 1 ban jayega (`[0]`). Loop `i=0` ke liye chalega, `0 > 0` False hoga, `st.push(0)` hoga aur loop khatam. `maxArea` strictly `0` return hoga. Completely safe!
* **Single Bar (`[7]`):** `push_back(0)` se array `[7, 0]` banegi.
* `i=0`: `7` push hua.
* `i=1`: Dummy `0` aaya $\rightarrow$ `7 > 0` True. `7` pop hua, stack empty $\rightarrow$ `width = i = 1`. Area = $7 \times 1 = 7$. Safe!



---

### 🚨 Code-Level Boundary Checklist for Interviews

Jab tum interviewer ke saamne whiteboard par pure single-pass code ka validation dikha rahe ho, toh ye 2 baatein bolna mat bhoolna:

1. **Strictly Greater (`>`) vs Greater-Equal (`>=`):** Stack pop loop me hamesha `heights[st.top()] > heights[i]` use karna. Agar `>=` lagaya, toh equal heights par loop pehle hi pop karne lagega, jisse width ki calculation thodi complex ho sakti hai (halanki answer phir bhi sahi laya ja sakta hai, par `>` sabse clean hai).
2. **The Vector Modification Warning:** Kuch companies me coding platform par input vector `const vector<int>& heights` pass kiya hota hai. Agar vector `const` hai, toh tum `heights.push_back(0)` nahi kar sakte (compiler error dega).
* *Hack:* Us case me original array ko chhedne ke bajaye, loop ko `i <= n` tak chalao, aur loop ke andar ek check daal do: `int curHeight = (i == n) ? 0 : heights[i];` aur standard logic chalao!



Bhai, ab Largest Rectangle in Histogram ka brute force, optimized, single-pass, aur saare edge cases dimaag me pathar ki lakeer ban chuke hain? Ab stack ka koi naya pattern uthayein ya isme kuch aur phodna hai?




Bhai, tumhari yahi soch ek top-tier product company ya HFT (High-Frequency Trading) engineer ki hoti hai! Ek single-pass $O(N)$ solution ko aur zyada optimize karne ke baare me sochna hi apne aap me ek next-level approach hai.

Technically, **Time Complexity $O(N)$ se kam nahi ho sakti** kyunki har building ko kam se kam ek baar dekhna mandatory hai. Lekin hum **Space Complexity aur execution speed (runtime overhead)** ko micro-optimize kar sakte hain.

Abhi jo humne standard single-pass kiya, usme do chhote overheads hain:

1. `std::stack` internally `std::deque` ya `std::vector` use karta hai jo memory dynamic heap par allocate karta hai. Isme pointer manipulation aur system calls ka overhead hota hai.
2. `heights.push_back(0)` karne se agar vector ki capacity full ho chuki hai, toh pura vector double size ke naye memory block me copy hota hai, jo $O(N)$ ka lag (latency) de sakta hai.

Chalo in dono overheads ko hata kar isko strictly **$O(1)$ Auxiliary Space** aur **Zero Heap Allocation** ke sath optimize karte hain using **Raw Array Pointer-Based Simulation**.

---

## 1. Asali Khel: Raw Array Simulated Stack

Hum koi standard `std::stack` object nahi banayenge. Uske bajaye hum ek raw primitive pointer array use karenge jo stack ki tarah behave karega, aur vector modification ko bypass karne ke liye **Virtual Zero Height Index** ka use karenge.

### The Micro-Optimized Code (C++)

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleAreaUltimate(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        // Dynamic stack ki jagah fixed-size raw array allocated on Stack Memory (No Heap Overhead)
        // Memory allocation bypass ho gayi
        int st[n + 1]; 
        int top = -1; // Stack pointer
        int maxArea = 0;

        // Loop n tak chalega (i == n par hum virtually height 0 maanenge)
        for (int i = 0; i <= n; i++) {
            // Virtual Element Hack: Original vector ko push_back karke chheda nahi
            int current_height = (i == n) ? 0 : heights[i];

            // Standard Monotonic Rule using Raw Pointer Operations
            while (top != -1 && heights[st[top]] > current_height) {
                int height = heights[st[top]];
                top--; // st.pop()
                
                // Width Calculation
                int width = (top == -1) ? i : (i - st[top] - 1);
                
                int area = height * width;
                if (area > maxArea) {
                    maxArea = area;
                }
            }
            
            // st.push(i)
            top++;
            st[top] = i;
        }

        return maxArea;
    }
};

```

---

## 2. Is Ultimate Optimization Se Kya Fayda Hua?

| Parameter | Standard Single Pass | Ultimate Optimized Version |
| --- | --- | --- |
| **Data Structure Used** | `std::stack<int>` (Uses Heap) | Primitive `int st[]` (Uses Stack Memory) |
| **Vector Modification** | `heights.push_back(0)` (Triggers copy) | Virtual Ternary Operator `(i == n) ? 0 : ...` |
| **Auxiliary Space** | $O(N)$ overhead due to deque wrappers | Strictly $O(N)$ raw integers, zero tracking overhead |
| **Cache Locality** | Medium (Heap memory chunks can be scattered) | **Excellent** (Raw arrays contiguous hotey hain, CPU Cache me direct hit hote hain) |

---

## 3. Interviewer Ke Saamne Boss Move 😎

Jab tum interviewer ko yeh dikhaoge, toh tum use bata sakte ho:

> *"Sir, standard `std::stack` competitive programming aur low-latency systems me minor library lag create karta hai due to dynamic memory re-allocations. Maine stack ko ek local array se simulate kiya hai jo compiler ke memory stack frame me instantly create ho jati hai. Plus, `const vector<int>&` ke restriction ko bypass karne ke liye dummy element ko loop condition me hi evaluate kar liya hai."*

Bhai, ab Histogram ka pura framework brute force se lekar high-performance hardware-level coding logic tak dimaag me lock ho gaya?

Ab bolo toh Stack ka agla dhasu variant uthayein (jaise **Maximal Rectangle in 2D Binary Matrix - LeetCode 85**, jo isi Histogram ka use karke banta hai), ya isme kuch aur discuss karein?


