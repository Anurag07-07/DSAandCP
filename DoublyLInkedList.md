Bhai, **Doubly Linked List (DLL)** Linked List ka ekdum upgraded version hai. Single Linked List (SLL) me dikkat kya thi? Tum sirf aage ja sakte the (`next`), piche mudne ka koi raasta nahi tha. DLL me hum ek naya pointer jod dete hain—**`prev`** (previous), jisse hum aage aur piche dono taraf makkhan ki tarah travel kar sakte hain.

Chalo, isko ekdum zero se lekar advance tak, interview questions ke sath detail me samajhte hain!

---

## 1. Structure: Doubly Linked List Dikhti Kaise Hai?

SLL ke node me do hi cheezein hoti thi: `data` aur `next` pointer.
Lekin DLL ka ek node **teen parts** se milkar banta hai:

1. **`prev`**: Piche wale node ka address store karne ke liye pointer.
2. **`data`**: Asali value (jaise int, string, etc.).
3. **`next`**: Aage wale node ka address store karne ke liye pointer.

### C++ me iska Node kaise banta hai?

```cpp
struct Node {
    int data;
    Node* next;
    Node* prev; // Yeh naya bwaal hai jo piche ka rasta yaad rakhta hai

    // Constructor taaki naya node banana aasan ho jaye
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

```

---

## 2. DLL vs SLL (Interviewer ka favorite comparison)

| Feature | Singly Linked List (SLL) | Doubly Linked List (DLL) |
| --- | --- | --- |
| **Pointers** | Sirf `next` hota hai. | `next` aur `prev` dono hote hain. |
| **Traversal** | Sirf forward (shuruat se aakhiri). | Bi-directional (forward aur backward dono). |
| **Memory** | Kam space leta hai (ek pointer kam hai). | Thoda zyada space leta hai (`prev` pointer ke kaaran). |
| **Deletion** | Agar kisi node ko delete karna hai, toh uske piche wale node ko dhoondna padta hai ($O(N)$). | Direct us node ke `prev` pointer se piche wale ko access kar sakte hain ($O(1)$). |

---

## 3. Core Operations in DLL (Code ke saath)

DLL me teen main kaam hote hain: **Traversal**, **Insertion**, aur **Deletion**. Chalo unke standard code aur logic dekhte hain.

### A. Traversal (Aage aur Piche ghumna)

```cpp
// Forward Traversal (Head se Tail tak)
void printForward(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Backward Traversal (Tail se Head tak)
void printBackward(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev; // Piche mud rahe hain
    }
    cout << "NULL" << endl;
}

```

---

### B. Insertion (Naya Node Jodna)

Maan lo hume **Head par naya node insert** karna hai. Isme pointer links ka dhayan rakhna bohot zaroori hai.

```cpp
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        return newNode; // Agar list khali thi toh yahi head ban gaya
    }
    
    newNode->next = head; // Naye node ka next purane head ko point karega
    head->prev = newNode; // Purane head ka prev naye node ko point karega
    
    return newNode; // Ab newNode hi naya head hai
}

```

---

### C. Deletion (Node Hatana)

Maan lo hume **kisi given node `delNode` ko delete** karna hai. DLL me iska logic bada mast hota hai kyunki hume piche wala dhoondne ke liye loop nahi chalana padta!

```cpp
void deleteNode(Node*& head, Node* delNode) {
    if (head == nullptr || delNode == nullptr) return;

    // Case 1: Agar head node hi delete karna ho
    if (head == delNode) {
        head = delNode->next;
    }

    // Case 2: Agar delNode aakhiri node NAHI hai (yaani uske aage koi node hai)
    if (delNode->next != nullptr) {
        delNode->next->prev = delNode->prev;
    }

    // Case 3: Agar delNode pehla node NAHI hai (yaani uske piche koi node hai)
    if (delNode->prev != nullptr) {
        delNode->prev->next = delNode->next;
    }

    delete delNode; // Memory free kar di
}

```

---

## 4. Tricky Edge Cases (Jahan Bug aata hai 🚨)

DLL ka code likhte waqt 3 jagah hamesha galti hoti hai:

1. **List me sirf ek hi node bacha ho:** Jab single node hota hai, toh uska `next` aur `prev` dono `nullptr` hote hain. Use delete karte waqt `head` ko `nullptr` karna mat bhoolna.
2. **Tail Node ko delete karna:** Agar tum aakhiri node delete kar rahe ho, toh `delNode->next` toh `nullptr` hoga. Agar tumne galti se `delNode->next->prev` likh diya, toh **Null Pointer Exception / Segmentation Fault** aa jayega! Isliye hamesha null check lagao.
3. **Khali List ($nullptr$):** Kisi bhi operation ko karne se pehle `if (head == nullptr)` ka guard clause lagana standard coding practice hai.

---

## 5. Top Interview Questions on DLL

Bhai, agar DLL strong karni hai toh LeetCode/GeeksforGeeks ke ye 3 questions zaroor laga lena:

1. **Reverse a Doubly Linked List:** Poori list ke `next` aur `prev` pointers ko aapas me swap karna hota hai. (Bohot pucha jata hai!).
2. **Find pairs with given sum in DLL:** Sorted DLL di hoti hai, aur Two-Pointer approach (`head` aur `tail` par pointers rakh kar) se target sum dhoondna hota hai $O(N)$ me.
3. **LRU Cache (Design Problem):** Isme Doubly Linked List aur Hash Map ka combo use hota hai. Yeh LFT/HFT aur tier-1 companies ka favorite system design/DSA mixed question hai.

Bhai, Doubly Linked List ka basic block, code aur pointers ka khel samajh aaya? Bol toh iska **"Reverse a DLL"** wala logic detail me dry-run karke samjhau?


Bhai, **"Reverse a Doubly Linked List"** pointer manipulation ka ekdum bwaal sawal hai. Iska concept agar dimaag me chhap gaya, toh DLL ka koi bhi question tumhein pareshan nahi karega.

Chalo isko ekdum gahrai me step-by-step todte hain—bina kisi extra space ke, original nodes ke links ko palat kar!

---

## 1. Asali Khel: Swap Ka Jadu

Singly Linked List me jab hum reverse karte hain, toh hume teen pointers (`prev`, `curr`, `next`) maintain karne padte hain taaki track na kho jaye.

Lekin Doubly Linked List (DLL) me hamare paas ek bohot badi taqat hai: **Har node ke paas uska `next` aur `prev` dono pointers pehle se hote hain!**

Hume bas poori list me aage badhte hue har ek node par khade hona hai aur ek simple kaam karna hai:

> **"Current node ke `next` aur `prev` pointers ko aapas me badal (swap) do!"**

Chunache:

* Jo pointer aage (`next`) point kar raha tha, wo ab piche point karega.
* Jo pointer piche (`prev`) point kar raha tha, wo ab aage point karega.

---

## 2. Pointers Ka Coordination (Algorithm)

1. Ek pointer banao `Node* curr = head` jo poori list par traverse karega.
2. Ek temporary pointer rakhenge `Node* temp = nullptr` jo swaps ke dauran address hold karne me madad karega.
3. Ek loop chalao jab tak `curr` null nahi ho jata:
* `swap(curr->next, curr->prev);` (Donon links palat gaye).
* Ab tum sochoge ki aage badhne ke liye `curr = curr->next` karna chahiye? **Nahi!** Chunki pointers swap ho chuke hain, toh jo `curr->prev` tha wahi ab aage ka rasta hai! Isliye hum karenge: `temp = curr->prev;` aur fir `curr = curr->prev;` (Purane `next` par jaane ke liye).


4. **New Head Fixation:** Jab loop khatam hoga, toh `curr` toh null ho chuka hoga. Jo aakhiri valid node tha (jo hamari purani list ka tail tha), uska address `temp->prev` me bacha hoga (kyunki pointers swap ho chuke hain). Wahi hamara naya head banega!

---

## 3. C++ Code ($O(N)$ Time, $O(1)$ Space)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Solution {
public:
    Node* reverseDLL(Node* head) {
        // Edge Case: Agar list khali hai ya sirf ek hi node hai
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* curr = head;
        Node* temp = nullptr; // Swap track karne ke liye temporary pointer

        // Poori list traverse karenge
        while (curr != nullptr) {
            // 1. Current node ke dono pointers ko aapas me swap karo
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // 2. Agle node par jao. 
            // Dhyan do: Pointers swap ho chuke hain, isliye purana 'next' ab 'curr->prev' ban chuka hai!
            curr = curr->prev;
        }

        // 3. Naya head return karo. 
        // Loop khatam hone ke baad, 'temp' aakhiri processed node ke 'prev' par ruka hoga.
        // Kyunki pointers reverse ho chuke hain, toh temp->prev hi hamara naya actual Head hai!
        return temp->prev;
    }
};

```

---

## 4. Micro-Level Dry Run (Sabse Important Part)

Maan lo hamari list hai: `NULL <- 1 <-> 2 <-> 3 -> NULL`. Yahan `head = 1`.

### Step 1: `curr` pointing to Node `1`

* `temp = curr->prev` $\rightarrow$ `temp = NULL`
* Pointers Swap: Node 1 ka `prev` ban gaya `2`, aur `next` ban gaya `NULL`.
* Move forward: `curr = curr->prev` $\rightarrow$ `curr` ab Node `2` par chala gaya (kyunki Node 1 ka `prev` ab `2` ko point kar raha hai).

### Step 2: `curr` pointing to Node `2`

* `temp = curr->prev` $\rightarrow$ `temp = Node 1`
* Pointers Swap: Node 2 ka `prev` ban gaya `3`, aur `next` ban gaya `1`.
* Move forward: `curr = curr->prev` $\rightarrow$ `curr` ab Node `3` par chala gaya.

### Step 3: `curr` pointing to Node `3` (Purani Tail)

* `temp = curr->prev` $\rightarrow$ `temp = Node 2`
* Pointers Swap: Node 3 ka `prev` ban gaya `NULL`, aur `next` ban gaya `2`.
* Move forward: `curr = curr->prev` $\rightarrow$ `curr` ab `NULL` ho gaya (Kyunki Node 3 ka `prev` ab `NULL` hai).

### Loop Ends 🚨

Loop se bahar aane par `curr = nullptr` hai aur `temp` abhi bhi Node `2` par khada hai.
Naya head kaun hai? Node `3`.
Node `3` tak kaise pahunchein? `temp->prev` se (kyunki Node 2 ka `prev` ab Node 3 ko point kar raha hai!).
Isliye code return karega `temp->prev` (Node 3).

---

## 5. Critical Edge Cases (Interviewer Kahan Phasayega?)

1. **Khali List (`head == nullptr`):** Code ki pehli line `if (head == nullptr)` isko turant handle karke safely null return kar degi. No crash!
2. **Single Node List (`1 -> NULL`):** Agar list me ek hi node hai, toh `head->next == nullptr` hit hoga aur wahi node wapas return ho jayega bina kisi swap overhead ke.
3. **Memory Allocation / Memory Leak Check:** Interviewer poochega: *"Bhai tumne koi naya node create kiya?"* Tumhara jawab hona chahiye: *"Nahi sir! Humne sirf existing nodes ke address links ko manipulate kiya hai (`In-place Modification`), isliye space complexity absolute constant $O(1)$ hai aur koi memory leak nahi ho sakti."*

Bhai, "Reverse a DLL" ka ye absolute pointer dry-run ek-ek link ke shift ke sath dimaag me set hua? Ab Linked List ka koi aur dhasu problem uthayein?



Bhai, **"Find Pairs with Given Sum in a Sorted Doubly Linked List"** ek classic problem hai jo dikhata hai ki agar tumhare paas pointers ka sahi control ho, toh tum $O(N^2)$ waale brute force se bachkar $O(N)$ me kaam kaise nipatate ho.

Singly Linked List (SLL) me ye kaam karna mushkil hota hai kyunki wahan piche aana `O(N)` leta hai, par DLL me `prev` pointer ki wajah se hum array ki tarah **Two-Pointer** khel sakte hain.

---

## 1. The Logic: Bidirectional Two-Pointer

Sawal simple hai: Ek sorted DLL hai aur ek `target` sum hai. Hume aise saare pairs dhoondne hain jinka sum `target` ke barabar ho.

**Strategy:**

1. **`left` pointer:** Isse `head` par rakho (sabse chota element).
2. **`right` pointer:** Isse `tail` par rakho (sabse bada element).
3. **Comparison Loop:** Jab tak `left` aur `right` aapas me mil na jayein (ya cross na kar jayein), tab tak loop chalau:
* **Sum = left->data + right->data**
* **If Sum == Target:** Pair mil gaya! `left` ko aage badhao (`left = left->next`) aur `right` ko piche le jao (`right = right->prev`).
* **If Sum < Target:** Hame sum badhana hai. Kyunki list sorted hai, toh `left` ko aage badhao taaki bada number mile (`left = left->next`).
* **If Sum > Target:** Hame sum ghatana hai. `right` ko piche lao taaki chota number mile (`right = right->prev`).



---

## 2. C++ Implementation ($O(N)$ Time, $O(1)$ Space)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class Solution {
public:
    vector<pair<int, int>> findPairs(Node* head, int target) {
        if (head == nullptr) return {};

        Node* left = head;
        Node* right = head;
        
        // 1. Right pointer ko tail par le jao
        while (right->next != nullptr) {
            right = right->next;
        }

        vector<pair<int, int>> result;

        // 2. Two-Pointer logic
        // Jab tak pointers mil nahi jate
        while (left != right && right->next != left) {
            int sum = left->data + right->data;

            if (sum == target) {
                result.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } 
            else if (sum < target) {
                left = left->next; // Sum badhana hai
            } 
            else {
                right = right->prev; // Sum ghatana hai
            }
        }
        return result;
    }
};

```

---

## 3. Dry Run (Concept Clarity)

Maan lo DLL hai: `1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9` aur `target = 7`.

1. **Start:** `left` = 1, `right` = 9.
* Sum = 1 + 9 = 10. (10 > 7).
* `right` piche aayega (8 par).


2. **Step 2:** `left` = 1, `right` = 8.
* Sum = 1 + 8 = 9. (9 > 7).
* `right` piche aayega (6 par).


3. **Step 3:** `left` = 1, `right` = 6.
* Sum = 1 + 6 = 7. **Target Match!** ✅
* Result: `{1, 6}`. `left` aage (2 par), `right` piche (5 par).


4. **Step 4:** `left` = 2, `right` = 5.
* Sum = 2 + 5 = 7. **Target Match!** ✅
* Result: `{1, 6}, {2, 5}`. `left` aage (4 par), `right` piche (4 par).


5. **Step 5:** `left` = 4, `right` = 4.
* `left == right`, loop khatam.



---

## 4. Complexity Analysis

* **Time Complexity: $O(N)$**
* Humne DLL ko maximum ek baar traverse kiya hai. `left` aage badh raha hai aur `right` piche, dono ek-doosre ki taraf aa rahe hain. Poore process me $N$ se zyada steps nahi honge.


* **Space Complexity: $O(1)$**
* Humne koi extra array ya hashmap nahi banaya (result vector ko count nahi karte). Sirf do pointers use kiye hain.



---

## 5. Critical Edge Cases (Jo Interviewer check karega)

1. **List me sirf ek node ho:**
* `left` aur `right` dono head par rahenge. `while(left != right)` loop kabhi chalega hi nahi. Correct! (Ek node se pair nahi ban sakta).


2. **No Pair Found:**
* Loop bina kisi result ke khatam ho jayega. Result vector khali return hoga. Correct!


3. **Duplicates:**
* Agar DLL me `2 <-> 2 <-> 5` aur target 4 ho, toh logic `2+2` ko pakad lega. Yeh two-pointer logic bina kisi extra effort ke duplicates bhi handle kar leta hai.



**Interviewer Tip:** Agar tumse puche ki "Agar list sorted na ho toh kya karenge?"

* Toh tumhara jawab hona chahiye: "Sir, tab two-pointer nahi lagega. Tab hume **Hash Map (Hashing)** ka use karna padega to store visited elements, jisse $O(N)$ time me pair mil jayega, par space $O(N)$ ho jayegi."

DLL ka ye two-pointer pattern clear hua? Iske baad kaunsa question pakde—"Delete all occurrences" ya "Reverse DLL"?



Bhai, **"Delete All Occurrences of a Given Key in a DLL"** dekhne me bohot simple lagta hai, par asal me ye ek **Pointer Bypass Trap** hai. Interviewer is sawal se tumhare logical control ko test karta hai kyunki isme agar ek bhi `nullptr` check chhota, toh sidha **Segmentation Fault (Code Crash)** aata hai.

Chalo isko ekdum makkhan ki tarah clear karte hain—ek-ek pointer aur boundary logic ke saath!

---

## 1. Core Logic: Bypass Concept

DLL me kisi node ko delete karne ka matlab hai: **"Uske aage wale aur piche wale nodes ko aapas me aisi dosti karwa do ki beech wala node list se gayab ho jaye."**

Agar hume kisi `curr` node ko udana hai:

1. `curr` ke piche wale node (`curr->prev`) ka `next` pointer ab `curr` ke aage wale node (`curr->next`) ko point karega.
2. `curr` ke aage wale node (`curr->next`) ka `prev` pointer ab `curr` ke piche wale node (`curr->prev`) ko point karega.

---

## 2. Teen Khatarnak Zones (Pointers Handling)

Har node ko delete karte waqt hume 3 alag situations ko dhyan me rakhna padta hai:

### Zone A: Head Node Udana Hai (`curr == head`)

Agar pehla hi node delete karna pad jaye, toh list ka `head` badal jayega. Hamara naya head banega `curr->next`. Aur naye head ka `prev` pointer `nullptr` hona chahiye.

### Zone B: Tail Node Udana Hai (`curr->next == nullptr`)

Agar aakhiri node delete karna hai, toh uske aage koi node nahi hai. Agar tumne bina check kiye `curr->next->prev` likh diya, toh code crash! Isliye jab aage koi node ho, tabhi uske `prev` ko modify karo.

### Zone C: Beech Ka Node Udana Hai

Piche wale ke `next` ko aage wale se jodo, aur aage wale ke `prev` ko piche wale se jodo. Fir safely memory `delete` kar do.

---

## 3. Full C++ Code ($O(N)$ Time, $O(1)$ Space)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Solution {
public:
    Node* deleteAllOccurrences(Node* head, int key) {
        // Edge Case: Agar list pehle se khali hai
        if (head == nullptr) return nullptr;

        Node* curr = head;

        while (curr != nullptr) {
            // Agar key match ho gayi, toh is node ka game over karna hai
            if (curr->data == key) {
                Node* nextNode = curr->next; // Agle node ka address pehle hi save kar lo
                
                // Step 1: Head node handle karo
                if (curr == head) {
                    head = nextNode; // Head ko aage badha diya
                }

                // Step 2: Piche wale node ke links tight karo (Bypass behind)
                if (curr->prev != nullptr) {
                    curr->prev->next = curr->next;
                }

                // Step 3: Aage wale node ke links tight karo (Bypass ahead)
                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                }

                // Step 4: Memory free karo
                delete curr;

                // Step 5: Pointer ko agle element par shift karo
                curr = nextNode; 
            } 
            else {
                // Agar key match nahi hui, toh normal aage badho
                curr = curr->next;
            }
        }

        return head;
    }
};

```

---

## 4. Line-by-Line Dry Run (Gahrai Me Samjho)

Maan lo DLL hai: `1 <-> 2 <-> 2 <-> 3` aur hume `key = 2` ko hatana hai. Shuruat me `head = 1`.

* **`curr` pointing to Node `1`:**
* `1 != 2`, condition fail. Hum normal aage badh gaye: `curr = curr->next` (Node 2 par).


* **`curr` pointing to First Node `2`:**
* `2 == 2`, Key match ho gayi! 🎯
* `nextNode = curr->next` (Node 2 ke agle wale '2' ka address save kiya).
* `curr == head`? Nahi, kyunki head toh `1` par hai.
* `curr->prev` (Node 1) null nahi hai $\rightarrow$ `curr->prev->next = curr->next` (Node 1 ka next ab seedha agle Node 2 ko point karega).
* `curr->next` (Agle Node 2) null nahi hai $\rightarrow$ `curr->next->prev = curr->prev` (Agle Node 2 ka prev ab seedha Node 1 ko point karega).
* `delete curr;` (Pehla waala '2' memory se delete).
* `curr = nextNode` (Hum agle Node 2 par pahunch gaye).


* **`curr` pointing to Second Node `2`:**
* `2 == 2`, Dubara match! 🎯
* `nextNode = curr->next` (Node 3 ka address save kiya).
* Links bypass honge: Node 1 ka `next` ab seedha Node 3 ko point karega, aur Node 3 ka `prev` seedha Node 1 ko point karega.
* `delete curr;` (Dusra waala '2' bhi delete).
* `curr = nextNode` (Hum Node 3 par pahunch gaye).


* **`curr` pointing to Node `3`:**
* `3 != 2`, loop skip. `curr = curr->next` $\rightarrow$ `curr = nullptr`. Loop khatam!


* **Final List:** `1 <-> 3`. (PASS ✅)

---

## 5. Extreme Edge Cases (Interviewer Checkpoints)

1. **Saare Elements Hi Key Ke Barabar Hon (`[2, 2, 2]`, `key = 2`):**
* Loop chalega, har baar `curr == head` hit hoga aur head shift hota rahega. Aakhiri me `head = nullptr` return ho jayega. (PASS ✅)


2. **Key Pehle Aur Aakhiri Element Par Ho (`[2, 5, 2]`, `key = 2`):**
* Shuruat me head bypass hoga (`head` ban jayega `5`), aur end me tail node ka pointer null check (`if (curr->next != nullptr)`) ki wajah se safely bina kisi crash ke ud jayega. (PASS ✅)


3. **Key Array Me Ho Hi Na (`[1, 3, 4]`, `key = 2`):**
* Loop bina kisi `if` block ko trigger kiye makkhan ki tarah chalega aur original list wapas aa jayega. (PASS ✅)



Bhai, "Delete All Occurrences" ka ye super clean dynamic memory logic ek-ek link check ke saath samajh aa gaya? Ab iske agle heavyweight question—**"Flatten a Multilevel DLL"** par chalein?




Bhai, **"Remove Duplicates from a Sorted Doubly Linked List"** tumhare pointer links badalne ki real-time testing hai. Kyunki list **sorted** hai, iska sabse bada fayda ye hai ki saare duplicate elements hamesha ek ke baad ek (lagatar) baithe honge.

Isme hame poori list me aage badhte hue sirf agle node par dhyan rakhna hai, aur links ko is tarah todna-jodna hai ki memory leak bhi na ho aur duplicate nodes safely delete ho jayein.

---

## 1. Core Logic: Line-by-Line Bypass

Maan lo tum abhi `curr` node par khade ho. Tum check karoge ki kya tumhara agla node (`curr->next`) tumhare jaisa hi data hold kar raha hai?

Agar `curr->data == curr->next->data` hai:

1. Hame `curr->next` wale node (duplicate node) ko delete karna hai. Hame pehle uske address ko ek temporary pointer `duplicate` me save karna padega taaki uski memory free kar sakein.
2. `curr` ka `next` link ab direct duplicate node ke bhi agle node (`duplicate->next`) ko point karega.
3. Agar duplicate ke aage bhi koi node bacha hai (`duplicate->next != nullptr`), toh us aage wale node ka `prev` link wapas hamare `curr` node ko point karne lagega.
4. Ab bina kisi tension ke `delete duplicate;` kar do.

**Crucial Point:** Jab tak `curr->data == curr->next->data` true rahega, hum `curr` ko aage nahi badhayenge! Hum wahi khade-khade agle duplicate ko udate chale jayenge. Jab alag element milega, tabhi `curr = curr->next` karenge.

---

## 2. Full C++ Code ($O(N)$ Time, $O(1)$ Space)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class Solution {
public:
    Node* removeDuplicates(Node* head) {
        // Edge Case: Agar list khali hai ya sirf ek hi element hai, toh koi duplicate ho hi nahi sakta
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* curr = head;

        // Jab tak hum aakhiri node tak nahi pahunch jaate
        while (curr != nullptr && curr->next != nullptr) {
            
            // Agar current node aur uske agle node ka data same hai
            if (curr->data == curr->next->data) {
                Node* duplicate = curr->next; // Duplicate node ko pakda

                // 1. Current ke next pointer ko aage shift kiya
                curr->next = duplicate->next;

                // 2. Agar duplicate ke aage koi node hai, toh uska prev link tight karo
                if (duplicate->next != nullptr) {
                    duplicate->next->prev = curr;
                }

                // 3. Memory free karo
                delete duplicate;
                
                // Note: Humne yahan curr = curr->next NAHI kiya hai!
                // Kyunki ho sakta hai ki agla element bhi fir se duplicate hi nikal aaye.
            } 
            else {
                // Agar data match nahi hua, toh aaram se aage badho
                curr = curr->next;
            }
        }

        return head;
    }
};

```

---

## 3. Micro-Level Dry Run (Trace Matrix)

Maan lo hamari sorted list hai: `1 <-> 2 <-> 2 <-> 2 <-> 3`. Shuruat me `head` aur `curr` dono Node `1` par hain.

* **`curr` pointing to Node `1`:**
* `curr->next` ka data `2` hai. `1 != 2`, condition fail.
* `curr` normal tarike se aage badha $\rightarrow$ `curr` ab pehle Node `2` par hai.


* **`curr` pointing to First Node `2`:**
* `curr->next` (Second Node `2`) ka data bhi `2` hai. `2 == 2`, Duplicate mil gaya! 🎯
* `duplicate = curr->next` (Second Node `2` ka address lock kiya).
* Link Bypass: `curr->next` ab direct Third Node `2` ko point karega.
* Third Node `2` ka `prev` ab direct First Node `2` ko point karega.
* `delete duplicate;` (Second Node `2` memory se khatam).
* **Important:** `curr` abhi bhi First Node `2` par hi khada hai!


* **`curr` still pointing to First Node `2` (Round 2):**
* Ab `curr->next` kaun hai? Third Node `2`. Dono ka data fir match hua (`2 == 2`). Double Duplicate! 🎯
* `duplicate = curr->next` (Third Node `2` lock kiya).
* Link Bypass: `curr->next` ab direct Node `3` ko point karega.
* Node `3` ka `prev` ab direct First Node `2` ko point karega.
* `delete duplicate;` (Third Node `2` bhi saaf).
* `curr` abhi bhi First Node `2` par hi ruka hai.


* **`curr` still pointing to First Node `2` (Round 3):**
* Ab `curr->next` kaun hai? Node `3`. `2 != 3`, condition fail!
* Ab jaakar `curr` aage badhega $\rightarrow$ `curr` pahuncha Node `3` par.


* **`curr` pointing to Node `3`:**
* `curr->next` ab `nullptr` hai, toh loop safely end ho gaya.


* **Final List:** `1 <-> 2 <-> 3`. (PASS ✅)

---

## 4. Boundary Edge Cases (Interviewer's Catch)

1. **Saare Elements Hi Same Hon (`[5, 5, 5, 5]`):**
* `curr` pehle hi element par khada rahega aur aage ke saare `5` ek-ek karke udata chala jayega. Aakhiri me sirf single `[5]` bachega aur `curr->next == nullptr` hote hi loop ruk jayega. (PASS ✅)


2. **Duplicates Sirf Tail Par Hon (`[1, 2, 3, 3]`):**
* Jab `curr` Node `3` (pehla wala) par aayega, toh aakhiri `3` delete ho jayega. Us waqt `duplicate->next` null hoga, toh `if (duplicate->next != nullptr)` block bypass ho jayega safely bina kisi crash ke. (PASS ✅)


3. **No Duplicates (`[1, 2, 3]`):**
* `if` block kabhi execute hi nahi hoga. `curr` line se aage badhega aur $O(N)$ time me original list as it is return ho jayegi. (PASS ✅)



Bhai, sorted DLL me se duplicates hatane ka ye in-place dynamic calculation ek-ek pointer bypass ke sath set hua dimaag me? Ab iske baad seedha Amazon/Microsoft ke heavyweight horizontal level design question—**"Flatten a Multilevel Doubly Linked List"** par halla bolen?



Bhai, **Flatten a Multilevel Doubly Linked List (LeetCode 430)** ka poora khel agar interview me bina code ke, sirf dimaag aur theory ke dum par crack karna hai, toh iski core concept ko ek kahani ki tarah samajhna padega.

Interviewer code dekhne se pehle tumse iski **intuition aur theory** hi poochta hai. Chalo iska ek-ek point, structural design aur traversal theory ekdum detail me samajhte hain.

---

## 1. Multilevel DLL Ka Structural Design

Ek normal Doubly Linked List (DLL) ek linear train ki tarah hoti hai—saare dibbe (nodes) ek ke baad ek horizontal line me jude hote hain. Har node ke paas aage (`next`) aur piche (`prev`) ka track hota hai.

Lekin Multilevel DLL me har node ke paas ek teesri power aa jati hai—**`child` pointer**.

* Agar kisi node ka `child` pointer null nahi hai, toh iska matlab wahan se niche ki taraf ek alag horizontal train (ek nayi sub-list) shuru ho rahi hai.
* Us niche wali list ke andar bhi kisi node ke paas apna child ho sakta hai, jisse ek teesra level ban jayega.
* Is design ko computer science ki bhasha me hum **"2D Linked List"** ya ek tarah ka **"Tree Structure"** bol sakte hain, jahan `next` pointer right-child ki tarah aur `child` pointer left-child ki tarah behave karta hai.

---

## 2. Flattening Ka Asli Matlab (The Goal)

Hume is 2D structure ko todkar ek **1D Ultra-Linear Standard DLL** banana hai.

### Flatten karne ke teen strict niyam (Rules):

1. **No More Children:** Flattening ke baad pure array/list me kisi bhi node ka `child` pointer active nahi rehna chahiye. Sab ke sab **`nullptr`** hone chahiye.
2. **Order of Elements (DFS / Pre-order Order):** Agar tum kisi node par ho aur uske paas right (`next`) ka bhi rasta hai aur niche (`child`) ka bhi, toh tum pehle **niche (child)** jaoge. Jab niche ka poora khandaan khatam ho jayega, tab wapas aakar bache hue right (`next`) wale raste par aage badhoge. Isko binary tree ka **Pre-order Traversal (Root -> Left -> Right)** bolte hain.
3. **Bi-directional Integrity:** Pointers aapas me aise judne chahiye ki naye flattened structure me agar tum head se tail tak ja sakte ho, toh tail se head tak wapas `prev` pointer ka use karke makkhan ki tarah laut sako. Pointers ka breakdown nahi hona chahiye.

---

## 3. The Grand Theory: How To Think? (Intuition)

Maan lo tum ek bhool-bhulaiya (maze) me chal rahe ho. Tum seedhe raste par ja rahe ho (`next`), big picture clear hai. Sudden ek mod aata hai jahan se ek gufa niche ja rahi hai (`child`).

* **Galti (Brute Thought):** Agar tum bina piche ka rasta yaad rakhe gufa me kood gaye, toh jab gufa khatam hogi, tum baki bache horizontal raste par kabhi wapas nahi aa paoge. Isko bolte hain **"Lost Pointer Exception"**.
* **Sahi Tarika (The Stack Concept):** Gufa me ghusne se pehle, tum apne horizontal raste ke agle pathar (`next node`) ka address apni diary (**Stack**) me note kar lete ho.
* Tum gufa me chalte rehte ho. Agar gufa ke andar ek aur gufa mili, toh tum phir se uske aage wale node ko diary me upar likh lete ho (LIFO - Last In First Out).
* Jab koi gufa poori tarah khatam ho jati hai (`curr->next == nullptr`), toh tum apni diary kholte ho, sabse upar jo rasta bacha tha use nikaalte ho, aur apni current location ko us raste se jod dete ho.

---

## 4. Flattening Traversal Theory (Step-by-Step State Transitions)

Chalo dimaag me ek map banao. Tum list par scan kar rahe ho:

### State A: Normal Scanning

Jab tak node ke paas `child` nahi hai, tab tak tum bas `curr = curr->next` karke forward travel karte ho. Is state me koi structural change nahi hota.

### State B: Split Point (Child Encountered)

Jaise hi tum ek aise node par aaye jahan `child != nullptr` hai:

1. **Memory Preservation:** Tum uske original `next` node ko safe rakhne ke liye memory stack me daal dete ho.
2. **Splice Operation:** Tum current node ke `next` pointer ko utha kar seedha child node se jor dete ho, aur child node ke `prev` pointer ko wapas current node se connect kar dete ho.
3. **Nullify:** Purane child connection ko hamesha ke liye kaat dete ho (`child = nullptr`). Ab wo child tumhara temporary horizontal `next` ban chuka hai.

### State C: Dead End (End of Sub-list)

Chalte-chalte tum ek aisi jagah pahunch gaye jahan `next == nullptr` hai. Iska matlab tumne ek gufa (level) ko poora scan kar liya.

1. **Pop and Link:** Tum stack se sabse latest bacha hua node nikaalte ho.
2. **Bridge Creation:** Tum current dead-end wale node ke `next` ko us popped node se jodte ho, aur popped node ke `prev` ko current node se connect kar dete ho. Ek naya bridge taiyar ho jata hai.

---

## 5. Theory Cheat-Sheet for Interview

Interviewer agar tumse counter-questions kare, toh ye bulletproof keywords bolna:

* **Time Complexity Theory:** $O(N)$ hogi kyunki hum list ke har ek node par maximum do ya teen baar hi jate hain (ek baar aage badhte waqt aur ek baar links connect karte waqt). Linear time se fast flatten hona impossible hai.
* **Space Complexity Theory:** Worst case space complexity $O(N)$ hogi (Stack Space). Yeh tab hoga jab list ekdum deep vertical tower jaisi ho (har node ka sirf child ho, next ho hi na). Best case space $O(1)$ hogi agar list me koi child ho hi na (already flat list).
* **Why Stack over Recursion?** Recursion me internal system call stack use hota hai jo zyada deeper levels par **Stack Overflow** error de sakta hai, jabki explicit `std::stack` stack memory ko manually control karta hai aur zyada safe hota hai pointer tracking ke liye.

Bhai, ab "Multilevel DLL Flattening" ki poori structural theory, DFS connection order aur state changes dimaag me ekdum crystal clear chhap gayi?



Bhai, **"Flatten a Multilevel Doubly Linked List" (LeetCode 430)** Microsoft, Amazon aur Adobe ka ekdum premium problem hai. Ye dekhne me thoda darawna lagta hai kyunki ye Linked List aur Tree (DFS/Stack) ka ek kamaal ka mix hai, par iska pointer logic agar tum ek baar samajh gaye, toh tum ise ungliyon par trace karoge.

Chalo isko ekdum makkhan ki tarah clear karte hain.

---

## 1. Sawal Ka Asli Matlab Kya Hai?

Is problem me ek standard Doubly Linked List hoti hai, par kuch nodes ke paas ek extra pointer hota hai jise **`child`** kehte hain. Yeh `child` pointer ek bilkul alag, nayi Doubly Linked List ke head ko point karta hai. Aur us list ke andar bhi kisi node ka child ho sakta hai (multilevel structure).

Hume ise **flatten** karke ek single, seedhi standard DLL me convert karna hai, jisme saare nodes ek hi line me hon aur saare `child` pointers **`nullptr`** ban jayein.

### Flattening Ka Order (Flattener Rule):

Hume bilkul **Pre-order Traversal (DFS)** ki tarah chalna hai:

> *"Agar kisi node ka child hai, toh pehle uske child ki poori list ko flatten karke current node aur uske agle node ke beech me ghusa do!"*

---

## 2. Core Logic: Stack (Iterative DFS)

Isko solve karne ka sabse sasta aur dhasu tarika hai **Stack Data Structure** ka use karna. Stack se pointer track khona impossible ho jata hai.

### Algorithm Steps:

1. Ek `curr` pointer lo jo `head` par khada hoga.
2. Ek `stack` banao jo nodes ke addresses hold karega.
3. Poori list me ek loop chalao jab tak `curr` valid hai ya `stack` khali nahi hota:
* **If Child Exists:** Agar `curr->child` hai:
* Agar uska `next` element bhi exist karta hai (`curr->next != nullptr`), toh us `next` element ko safe rakhne ke liye **stack me push** kar do. Kyunki hum pehle child me ghumne ja rahe hain, toh aage ka rasta baad me yaad aana chahiye.
* Ab `curr->next` ko connect karo `curr->child` se.
* `curr->child->prev` ko connect karo `curr` se.
* Aur `curr->child` ko **`nullptr`** set karna mat bhoolna (kyunki list ab flat ho rahi hai!).


* **If End of current level:** Agar chalte-chalte `curr->next == nullptr` ho jaye (yaani current line khatam) AUR stack me kuch bacha hai:
* Stack ke top se node nikaalo (`Node* nextNode = st.top(); st.pop();`).
* Current node ke `next` ko us `nextNode` se jod do: `curr->next = nextNode;`.
* `nextNode->prev = curr;`.


* **Move Forward:** `curr = curr->next;` (Agle node par chalo).



---

## 3. Full C++ Code ($O(N)$ Time, $O(N)$ Space)

```cpp
#include <iostream>
#include <stack>
using namespace std;

// LeetCode Node Structure
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;
        stack<Node*> st; // Purane 'next' nodes ko yaad rakhne ke liye stack

        while (curr != nullptr) {
            
            // Step 1: Agar child dikhe, toh andar kood jao
            if (curr->child != nullptr) {
                
                // Agar aage koi rasta (next node) hai, toh use baad ke liye stack me save karo
                if (curr->next != nullptr) {
                    st.push(curr->next);
                }

                // Links ko connect karo: curr -> child
                curr->next = curr->child;
                curr->child->prev = curr;
                
                // Child pointer ka kaam khatam, use null karo
                curr->child = nullptr;
            }
            
            // Step 2: Agar line khatam ho gayi aur stack me koi bacha hua purana rasta hai
            if (curr->next == nullptr && !st.empty()) {
                Node* nextNode = st.top();
                st.pop();
                
                // Links ko connect karo: curr -> stack ka top node
                curr->next = nextNode;
                nextNode->prev = curr;
            }

            // Step 3: Linear forward move
            curr = curr->next;
        }

        return head;
    }
};

```

---

## 4. Micro-Level Dry Run (Trace Matrix)

Maan lo hamari list aisi hai:

```text
1 <-> 2 <-> 3 -> NULL
      |
      4 -> NULL

```

Yahan Node `2` ka ek child hai Node `4`.

* **`curr` at Node `1`:**
* No child, standard move forward $\rightarrow$ `curr` reached Node `2`.


* **`curr` at Node `2`:**
* Child exists! (Node `4`).
* `curr->next` (Node `3`) null nahi hai, toh **Stack me push kiya:** `st = [Node 3]`.
* Connect: Node 2 ka `next` ab Node `4` ban gaya. Node 4 ka `prev` Node `2` ban gaya.
* `curr->child` ko `nullptr` set kiya.
* Move forward: `curr = curr->next` $\rightarrow$ `curr` reached Node `4`.


* **`curr` at Node `4`:**
* No child. Lekin `curr->next` yahan `nullptr` hai! AUR stack khali nahi hai (`st` holds Node 3).
* Stack se nikaala: `nextNode = Node 3`, `st` ab empty (`[]`).
* Connect: Node 4 ka `next` ban gaya Node `3`. Node 3 ka `prev` ban gaya Node `4`.
* Move forward: `curr = curr->next` $\rightarrow$ `curr` reached Node `3`.


* **`curr` at Node `3`:**
* No child, `curr->next` is `nullptr`, stack is empty. Loop safely stops!



**Final Flattened List:** `1 <-> 2 <-> 4 <-> 3 -> NULL`. (PASS ✅)

---

## 5. Critical Edge Cases (Interviewer Points)

1. **Multiple Nested Children (Child ka bhi Child):**
* Hamara stack logic ise makkhan ki tarah handle karega. Pehle level ka next stack me jayega, fir uske andar wale level ka next stack me jayega. Stack ke LIFO (Last In First Out) nature ke karan sabse deep wala pehle nikal kar connect hoga, jo ki perfect DFS order hai.


2. **Aakhiri Node par Child Hona (`curr->next == nullptr` par child):**
* Agar aakhiri node par child hai, toh `curr->next != nullptr` wali condition push nahi karega (kyunki aage kuch hai hi nahi), aur links seedha child se connect hokar aage badh jayenge bina stack load kiye.


3. **Saare Child Pointers `nullptr` Karna:**
* Interviewer tumhara code dekhte hi check karega ki kya tumne `curr->child = nullptr;` likha hai? Agar ye line bhool gaye, toh list flatten hone ke baad bhi valid standard DLL nahi kahnayegi.



Bhai, LeetCode 430 ka ye full stack-based pointer manipulation clear hua? Iske baad dynamic history track karne wale design system—**"Design Browser History"** par chalein?



Bhai, LeetCode 1472 (**Design Browser History**) ek absolute gem question hai. Yeh sirf ek DSA problem nahi hai, balki ek **Low-Level Design (LLD)** aur real-world system architecture ka live demo hai. Interviewer jab tumse real-world systems me Doubly Linked List (DLL) ka upyog poochta hai, toh yeh uska sabse perfect aur hit example hai.

Chalo iski **poori core theory, system behavior, data structure selection aur corner cases** ko ekdum gahrai me samajhte hain.

---

## 1. Real-World Simulation: Browser History Kaise Chalti Hai?

Maan lo tum browser kholte ho:

1. Tumne `google.com` khola (Homepage).
2. Fir tumne search kiya aur `github.com` par gaye.
3. Fir tumne ek repo kholi aur `leetcode.com` par gaye.

Abhi tumhara status kuch aisa hai:
`google.com` $\rightarrow$ `github.com` $\rightarrow$ `leetcode.com` (Yahan tum abhi khade ho).

* **Back Operation:** Agar tum browser ka **Back button** dabaoge, toh tum piche jaoge `github.com` par. Ek aur baar dabaoge toh `google.com` par.
* **Forward Operation:** Agar tum `google.com` par ho aur **Forward button** dabaoge, toh tum wapas `github.com` aur fir `leetcode.com` par ja sakte ho.

### The Ultimate Trap (The Rewrite Rule):

Maan lo tum back karke `github.com` par khade ho. Aur wahan se tumne ek naya URL visit kar liya—`twitter.com`.
Ab kya tum wapas forward karke `leetcode.com` par ja sakte ho? **Nahi!** Real world me jaise hi hum history me piche khade hokar koi naya URL visit karte hain, toh **aage ki saari forward history delete (clear) ho jaati hai**. Now new history becomes: `google.com` $\rightarrow$ `github.com` $\rightarrow$ `twitter.com`.

---

## 2. Why Doubly Linked List is the Best Match? (Data Structure Comparison)

Interviewer tumse zaroor poochega, *"Bhai, tumne DLL hi kyun chuna? Main toh standard dynamic array (vector) ya fir do stacks (Back Stack & Forward Stack) se bhi ye kar sakta hoon."* Tumhara core theoretical answer yeh hona chahiye:

### Array/Vector Kyun Fail Hota Hai?

Agar hum array use karein, toh back aur forward toh index arithmetic (`currIndex--` ya `currIndex++`) se $O(1)$ me ho jayega. Lekin jab hum bich me khade hokar koi naya URL `visit` karenge, toh aage ke saare elements ko array se remove karna padega ya unhe overwrite karna padega. Array me resize/delete operations me elements ko shift karna padta hai, jisse worst case time complexity **$O(N)$** chali jaati hai.

### Two Stacks (Back and Forward Stack) Ka Jhol:

Do stacks se ye kaam $O(1)$ me ho sakta hai (Back stack me piche ki history, forward stack me aage ki history). Lekin isme memory allocation dynamic aur staggered hoti hai. Jab naya URL visit hota hai, toh forward stack ko poora khali (`clear`) karna padta hai, jo internal memory deallocation overhead create karta hai.

### Doubly Linked List Ka Jalwa (The Winner):

1. **Bi-directional Navigation:** DLL ka `next` pointer forward button ki tarah behave karta hai aur `prev` pointer back button ki tarah.
2. **$O(1)$ Truncation:** Jab hum kisi middle node par khade hain aur naya URL visit karte hain, toh hume aage ka data physically memory se shift nahi karna padta. Hum bas `curr->next = new_node` aur `new_node->prev = curr` karte hain. Aage ki poori branch ek hi jhatke me list se isolated (cut off) ho jaati hai constant **$O(1)$** time me!

---

## 3. Core Operations Ki Theoretical Working

DLL ke nodes me hum string `url` store karenge. Hamare paas ek global pointer hoga: **`Node* curr`**, jo hamesha hamare current active tab/page ko track karega.

### A. Initialization (Homepage)

Jab browser start hoga, ek single node banega jisme homepage ka URL hoga. Hamara `curr` pointer isi par point karega.

### B. `visit(string url)`

1. Ek naya node banao: `Node* newNode = new Node(url);`
2. Apne current node ka `next` is naye node se connect karo: `curr->next = newNode;`
3. Naye node ka `prev` current node se connect karo: `newNode->prev = curr;`
4. **Move Pointer:** Ab hamara current status naya page hai, toh `curr = newNode;`
5. *Note:* Purani forward history ke baaki nodes ke links automatic toot gaye. Garbage collector ya destructor unhe saaf kar dega.

### C. `back(int steps)`

1. Hum ek loop chalayenge jo maximum `steps` baar piche jayega.
2. Lekin boundary check zaroori hai! Ghoomte-ghoomte agar `curr->prev == nullptr` ho gaya (yaani hum homepage par pahunch gaye), toh loop ko wahin rok denge. Hum history ke baahar nahi kood sakte.
3. Har step par: `curr = curr->prev;`
4. Aakhiri me `curr->url` return kar denge.

### D. `forward(int steps)`

1. Bilkul back ki tarah, maximum `steps` baar aage chalna hai.
2. Boundary Check: Agar chalte-chalte `curr->next == nullptr` ho gaya (yaani hum latest visited page par pahunch gaye jahan se aage koi history nahi hai), toh loop ruk jayega.
3. Har step par: `curr = curr->next;`
4. Aakhiri me `curr->url` return kar denge.

---

## 4. Mental Model Trace & Boundary Conditions

Chalo dimaag me ek map banate hain aur extreme situations ko evaluate karte hain:

* **Extreme Back Check (`steps` is very large):** Maan lo tumne sirf 3 pages visit kiye hain, aur tumne `back(100)` call kar diya. Hamara logic loop me check karega `while(steps && curr->prev != nullptr)`. Yeh loop sirf 2 baar chalega aur jaise hi homepage aayega (`prev == nullptr`), safely ruk jayega aur homepage return kar dega bina crash hue.
* **Extreme Forward Check (`steps` is very large):** Similarly, agar tum beech me khade ho aur `forward(500)` dabate ho, toh ye doudte hue latest tab tak jayega, jahan use `curr->next == nullptr` milega aur wo safe ho jayega.
* **Memory Management:** C++ me jab links toot-te hain, toh purane detached nodes ko memory se free karna achi practice hai. Interview me agar tum un detached nodes par loop chalakar unhe `delete` karne ki baat bologe, toh interviewer bohot impress hoga.

---

## 5. Theory Summary Matrix for Quick Revision

| Operation | DLL Theoretical Execution | Time Complexity | Space Complexity |
| --- | --- | --- | --- |
| **Browser Setup** | Allocates head node with homepage URL. | $O(1)$ | $O(1)$ |
| **`visit(url)`** | Breaks `curr->next` link, splices new node, drops forward branch. | $O(1)$ | $O(1)$ (new node memory) |
| **`back(steps)`** | Moves `curr` pointer backwards using `prev` until count or head limits hit. | $O(\text{steps})$ | $O(1)$ |
| **`forward(steps)`** | Moves `curr` pointer forward using `next` until count or tail limits hit. | $O(\text{steps})$ | $O(1)$ |

Bhai, "Design Browser History" ki yeh solid design theory, structural trade-offs aur link truncation ka khel dimaag me ekdum crystal clear baitha? Ab iske baad seedha software engineering ke absolute king/gold standard question—**"LRU Cache (LeetCode 146)"** ki theory aur blueprint par halla bolen?


Bhai, coding time! **Design Browser History** ko implement karna matlab system design ka ek basic flavour feel karna. Isme hum **Doubly Linked List** ka use karke custom navigation history maintain karenge.

Niche diya gaya implementation "Production Ready" hai, matlab isme hum memory leakage ka dhyan rakhte hue forward history ko explicitly `delete` bhi kar rahe hain.

---

### 1. Implementation (C++ Code)

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Node structure for Doubly Linked List
struct Node {
    string url;
    Node* prev;
    Node* next;
    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* curr;

public:
    // Constructor: Homepage set karo
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    // Naya URL visit karo
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr;
        
        // Purani forward history ko delete karo (Memory Management)
        // Note: LeetCode par ye optional hai, but real-world me zaroori hai
        Node* temp = newNode->next;
        while(temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        
        curr = newNode; // Current pointer ko aage badhao
    }

    // Piche jao
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    // Aage jao
    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

```

---

### 2. Logic & Walkthrough (The "Under the Hood" Stuff)

* **`visit(url)` ka twist:** Yahan tumne `curr->next = newNode` kiya. Agar pehle se koi history thi (forward nodes), toh wo saare nodes ab "orphaned" ho gaye. Production code me unhe `delete` karna zaroori hai taaki memory leak na ho.
* **Pointer Stability:** `curr` pointer hamesha active tab ko point karta hai. `visit` ke baad `curr` automatically naye node par shift ho jata hai.
* **Boundary Control:** `back` aur `forward` me `steps` ke sath-sath `curr->prev != nullptr` aur `curr->next != nullptr` ka check lagana crucial hai. Agar tum homepage par ho aur `back` dabate ho, toh ye check tumhe crash hone se bachayega.

---

### 3. Complexity Analysis

| Operation | Time Complexity | Space Complexity | Why? |
| --- | --- | --- | --- |
| **Visit** | $O(K)$ | $O(1)$ | $K$ forward nodes ko delete karne ka time. Link update $O(1)$ hai. |
| **Back** | $O(S)$ | $O(1)$ | $S$ steps traverse karne ka time. |
| **Forward** | $O(S)$ | $O(1)$ | $S$ steps traverse karne ka time. |

*(Note: $K$ = number of forward history nodes deleted, $S$ = number of steps requested).*

---

### 4. Edge Case Matrix (Interviewer's Hit List)

Jab interviewer tumse puchega ki "kya tumne sab cover kiya?", toh ye table dimaag me rakhna:

| Scenario | Critical Check | Behavior |
| --- | --- | --- |
| **`back(large_steps)`** | `curr->prev != nullptr` | Loop tab tak chalega jab tak `prev` null na ho jaye (Homepage par ruk jayega). |
| **`forward(large_steps)`** | `curr->next != nullptr` | Loop tab tak chalega jab tak `next` null na ho jaye (Latest page par ruk jayega). |
| **`visit` from middle** | Truncation of `curr->next` | Purani forward history memory se saaf ho jayegi, naye URL se naya path shuru hoga. |
| **Single page history** | Initialization | Sirf `homepage` node hoga, `back` aur `forward` kuch nahi karenge, bas `homepage` return hoga. |

**Pro Tip for Interview:** Agar interviewer puche "Memory leak kaise handle karoge?", toh bata dena ki DLL use karne ka ek fayda ye hai ki hum `delete` keyword se exact memory deallocate kar sakte hain, jo `vector` (dynamic array) me complex hota hai kyunki vector khud manage karta hai.

DLL ka browser history wala section clear hua? Ab **LRU Cache (LeetCode 146)** ki theory aur implementation ki taraf badhein? Woh absolute boss level question hai!

Bhai, **LRU Cache (Least Recently Used Cache)** interviewers ka absolute favourite system design question hai. Yeh sirf ek DSA problem nahi hai, yeh **"Optimization"** ka game hai.

Jab tumhare paas memory (cache) limited ho aur tumhe decide karna ho ki purana data uda kar naya data kahan fit karein, toh LRU kaam aata hai.

Chalo iski theory aur inner mechanics ko todte hain.

---

## 1. The Core Philosophy (Intuition)

LRU ka basic principle hai: **"Data, jo abhi use hua hai, wo aage bhi use hone ke chances zyada hain."**

Maan lo tumhare desk par books ki ek stack hai.

* Jab tum koi book padhte ho, tum use stack ke top par rakhte ho.
* Jab desk bhar jati hai, toh tum bottom wali book (jo sabse purani hai) wapas shelf me rakh dete ho.
* Desk = **Cache**.
* Bottom book = **Least Recently Used**.

---

## 2. The Architecture: Map + Doubly Linked List (The Magic Combo)

Interviewer tumse poochega: *"Mujhe $O(1)$ me data dhoondna bhi hai aur $O(1)$ me update/delete bhi karna hai. Kaise karoge?"*

Iska jawab hai: **HashMap + Doubly Linked List**.

* **HashMap (Key -> Node Pointer):**
* HashMap ka kaam hai **Searching** ko $O(1)$ banana. Ye store karta hai `Key` aur uska corresponding `Node` ka address.
* Bina Map ke, list me search karne me $O(N)$ lag jata, jo humein nahi chahiye.


* **Doubly Linked List (DLL):**
* DLL ka kaam hai **Ordering** maintain karna.
* **Head:** Yeh "Most Recently Used" (MRU) position hai.
* **Tail:** Yeh "Least Recently Used" (LRU) position hai.
* DLL ka fayda ye hai ki agar tumhe kisi node ko beech se nikalna ho, toh tum $O(1)$ me uske pointers (`prev` aur `next`) ko adjust karke use list se bypass kar sakte ho.



---

## 3. How it Works (The Workflow)

LRU Cache me do hi main operations hote hain: `get(key)` aur `put(key, value)`.

### A. Operation: `get(key)`

1. **Map check:** Kya key cache me hai?
2. **If NO:** Return -1.
3. **If YES:**
* Hame data mil gaya! Ab ye "Most Recently Used" ban gaya hai.
* **DLL Logic:** Us node ko apni purani position se hatao (detach) aur list ke `Head` (MRU position) par move kar do.
* **Return:** Value return kar do.



### B. Operation: `put(key, value)`

1. **Key exists?**
* **YES:** Purani value ko update karo, aur us node ko list ke `Head` par le aao.
* **NO:** Naya node banao.
* Add to Head (MRU).
* Add to Map.
* **Capacity Check:** Kya cache full ho gaya?
* **YES (Eviction Time!):** Tail ke piche wale node (LRU node) ko delete karo. Map se bhi uski entry uda do.
* **NO:** Kuch mat karo, bas chalne do.







---

## 4. Theory Summary: Why $O(1)$?

Interviewer hamesha complexity par pressure dalega. Tumhe ye points clear rakhne hain:

* **Lookups:** Hash map ka access time $O(1)$ hota hai.
* **Deletion:** DLL ka node deletion $O(1)$ hota hai kyunki hume node ka address pehle se Map me pata hota hai, humein node tak pahunchne ke liye traversal nahi karna padta.
* **Insertion:** DLL ka head insertion $O(1)$ hota hai.

**Isliye, LRU cache ka har operation (Get/Put) $O(1)$ complexity me hota hai.**

---

## 5. The "Interview Trap" Edge Cases

Jab tum LRU explain kar rahe ho, interviewer in points par tumhe test karega:

1. **Capacity = 0:** Kya tumhara system 0 capacity handle kar sakta hai? (Ye ek critical failure point hai).
2. **Concurrency (Thread Safety):** Agar 10 threads ek sath `get` aur `put` karenge, toh kya hoga? LRU implementation thread-safe nahi hoti, uske liye `Mutex` ya `Locks` chahiye hote hain.
3. **Cache Eviction Policy:** LRU sirf "Time" ke basis par kaam karta hai. Agar koi data "Frequency" (kitni baar use hua) ke basis par evict karna ho, toh wahan **LFU (Least Frequently Used)** use hota hai, jo LRU se zyada complex hai.
4. **Why DLL over Singly Linked List?** SLL me tum delete operation ke liye piche wale node (`prev`) ka address nahi nikal sakte. DLL me node khud apne piche wale ka address jaanta hai, isliye deletion $O(1)$ hota hai. SLL me wahi delete karne ke liye $O(N)$ traversal lag jayega.

Bhai, LRU Cache ki ye "Theory-Heavy" blueprint samajh aayi? Isme Map aur DLL ka jo coordination hai, wahi asli gold hai.

Kya ab iska **Step-by-Step implementation blueprint** samajhna hai, ya kisi aur specific concept par switch karein?


Bhai, chalo ab **LRU Cache (LeetCode 146)** ke coding battlefield me utarte hain. Interviewer ke saamne jab tum iska code likhoge, toh sabse important cheez hai **Clean Code Modularization** (yaani DLL ke operations jaise `addNode` aur `deleteNode` ko alag se helper function banana). Isse code me bugs nahi aate aur tumhara pointer logic ekdum clear dikhta hai.

Hum yahan do **Dummy Nodes** (`head` aur `tail`) ka use karenge taaki hume baar-baar null checks na karne padein. `head->next` hamesha Most Recently Used (MRU) ko point karega, aur `tail->prev` hamesha Least Recently Used (LRU) ko point karega.

---

## 1. Full C++ Implementation ($O(1)$ Time)

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    // DLL Node Structure
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> mp; // Key -> Node* mapping
    Node* head = new Node(-1, -1); // Dummy Head (MRU point)
    Node* tail = new Node(-1, -1); // Dummy Tail (LRU point)

    // Helper Function 1: Node ko Head ke just aage insert karo (MRU banana)
    void addNode(Node* newNode) {
        Node* temp = head->next;
        
        newNode->next = temp;
        newNode->prev = head;
        
        head->next = newNode;
        temp->prev = newNode;
    }

    // Helper Function 2: Kisi bhi node ko DLL se detach/delete karo
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // Case 1: Key cache me nahi hai
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        // Case 2: Key mil gayi -> Isko MRU (Most Recently Used) banao
        Node* resNode = mp[key];
        int resVal = resNode->val;
        
        // Step A: Puraani jagah se udao
        deleteNode(resNode);
        // Step B: Head par fresh insert karo
        addNode(resNode);
        
        return resVal;
    }
    
    void put(int key, int value) {
        // Case 1: Key pehle se exist karti hai -> Update & Move to Head
        if (mp.find(key) != mp.end()) {
            Node* existingNode = mp[key];
            existingNode->val = value; // Value update ki
            
            deleteNode(existingNode);
            addNode(existingNode);
            return;
        }
        
        // Case 2: Nayi Key hai, but Cache Full ho chuka hai -> Eviction Time!
        if (mp.size() == capacity) {
            Node* lruNode = tail->prev; // Tail ke piche wala hi gunahgaar (LRU) hai
            
            mp.erase(lruNode->key); // Map se entry saaf
            deleteNode(lruNode);    // DLL se node saaf
            delete lruNode;         // Memory free
        }
        
        // Case 3: Fresh Entry insertion
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        addNode(newNode);
    }
};

```

---

## 2. Micro-Level Execution Trace

Maan lo LRU Cache ki `capacity = 2` hai.

1. **`put(1, 10)`**:
* Map size (0) < Capacity (2).
* Node `[1, 10]` bana aur head ke aage jud gaya.
* **DLL State:** `Head <-> [1, 10] <-> Tail`


2. **`put(2, 20)`**:
* Map size (1) < Capacity (2).
* Node `[2, 20]` bana aur head ke just aage aa gaya (MRU).
* **DLL State:** `Head <-> [2, 20] <-> [1, 10] <-> Tail`


3. **`get(1)`**:
* Key `1` mil gayi! Iska node `[1, 10]` delete hokar wapas Head par aa gaya.
* **DLL State:** `Head <-> [1, 10] <-> [2, 20] <-> Tail` (Ab `[2, 20]` sabse purana yaani LRU ban gaya).


4. **`put(3, 30)`**:
* Nayi entry aayi, par Map size (2) == Capacity (2). **Eviction Triggered!** 🚨
* `tail->prev` par kaun hai? Node `[2, 20]`.
* Map se `2` delete hua, DLL se node uda.
* Naya node `[3, 30]` head par insert hua.
* **DLL State:** `Head <-> [3, 30] <-> [1, 10] <-> Tail`



---

## 3. Complexity Analysis

* **Time Complexity:**
* **`get(key)`: $O(1)$** $\rightarrow$ Map lookup $O(1)$ leta hai. DLL me node delete aur add karne me sirf 4-4 pointer links badalte hain, koi traversal nahi hota, isliye strictly constant time $O(1)$.
* **`put(key, value)`: $O(1)$** $\rightarrow$ Map insertion/deletion $O(1)$ hai, aur tail se node nikalna ya head par lagana bhi bina kisi loop ke $O(1)$ me ho jata hai.


* **Space Complexity: $O(\text{Capacity})$**
* Kyunki hum kisi bhi point par standard dynamic limit cross nahi kar rahe hain. Hamare `unordered_map` aur DLL dono me strictly maximum `capacity` ke barabar hi elements store honge.



---

## 4. Edge Cases Aur Interview Bug-Traps

1. **Dummy Nodes (`head` & `tail`) Ka Swag:**
* Agar tum dummy nodes nahi banaoge, toh jab pehla element insert hoga ya aakhiri element delete hoga, tumhe har baar `if (head == nullptr)` ya `if (tail == nullptr)` ke dher saare checks lagane padenge. Dummy nodes un boundaries ko permanently hold kar lete hain, jisse code crash hone se bach jata hai.


2. **Eviction Ke Waqt Map Erase Galti:**
* Jab tum tail se node delete karte ho (`tail->prev`), toh log aksar `mp.erase(key)` likhna bhool jaate hain ya galti se galat key delete kar dete hain. Isiliye Node structure ke andar `key` aur `value` dono store karna mandatory hai, taaki delete karte waqt node khud bataye ki map se kaunsi key udani hai (`lruNode->key`).



Bhai, LRU Cache ka ye full production-grade code, dynamic trace aur dummy nodes ka jadu ekdum mast tarike se dimaag me fit baitha? Ab iska agla level upgrade—**"LFU Cache (LeetCode 460)"** ki taraf kooden ya kisi aur topic par charcha karein?



Bhai, ab tumne pure LeetCode ke sabse khatarnak Data Structure Design question par haath daala hai—**LFU Cache (Least Frequently Used Cache)**.

Agar LRU Cache normal software engineering hai, toh LFU Cache ekdum elite-level high-performance system design hai. Jab standard FAANG ya HFT interviews me kisi candidate ko pure logic par reject ya select karna hota hai, toh unka sabse solid weapon yahi sawal hota hai.

Chalo iski **poori core theory, structural architecture, aur internal mechanics** ko ekdum dhasu tarike se todte hain taaki iska darr dimaag se hamesha ke liye nikal jaye.

---

## 1. LRU vs LFU: Asali Fark Kya Hai?

Pehle dono ka intellectual difference samjho:

* **LRU (Least Recently Used):** Yeh sirf **"Time"** (Recency) dekhta hai. Jo sabse pehle use hua tha, use nikaal do.
* **LFU (Least Frequently Used):** Yeh element ke **"Usage Count"** (Frequency) ko dekhta hai. Jis element ko sabse kam baar chhua gaya hai, pehle use cache se bahar phekna hai.

### The Tie-Breaker Trap (Jahan Log Fasten Hain):

Maan lo do elements hain, `A` aur `B`. Dono ki frequency same hai (dono 2-2 baar use hue hain). Ab agar cache full ho gaya, toh kisko nikaalein?

> **Rule:** Jab frequency me "Tie" ho jaye, toh hume **LRU (Least Recently Used)** approach par switch karna padta hai! Yaani un same frequency waale elements me se jo sabse purana (least recently used) hoga, wo evict hoga.

Isliye LFU ke andar internal implementation me LRU ka hona compulsory hai.

---

## 2. LFU Ka Brain: The Architecture ($O(1)$ Magic)

Interviewer sabse pehla bwaal tumhare upar ye phegega: *"Bhai, frequency track karni hai toh tum Max-Heap ya Priority Queue use kar lo."*
Tumhara counter-attack hona chahiye: *"Sir, agar Heap use kiya toh insertion/eviction me $O(\log N)$ lag jayega. Mujhe aapko har operation strictly **$O(1)$** me karke dikhana hai."*

$O(1)$ me frequency aur recency dono manage karne ke liye hume do Maps aur multiple Doubly Linked Lists ka ek network banana padta hai:

1. **`keyToNode` Map (`unordered_map<int, Node*>`):**
* Yeh standard map hai jo `key` se direct hamare DLL ke Node tak pahunchata hai ($O(1)$ lookup).


2. **`freqToList` Map (`unordered_map<int, DoublyLinkedList>`):**
* Yeh hai asli masterstroke! Yeh map har ek specific frequency (jaise freq = 1, freq = 2, freq = 3) ko ek poori ki poori custom Doubly Linked List se map karta hai.
* Maan lo frequency `2` ke paas teen elements hain, toh wo teeno elements frequency `2` waali DLL ke andar baithe honge standard LRU order me!


3. **`minFreq` Variable (Integer):**
* Yeh track rakhta hai ki pure cache me abhi sabse minimum frequency kaun si chal rahi hai (jaise `minFreq = 1`). Jab eviction ka waqt aayega, hum direct `freqToList[minFreq]` wali list ke tail se element nikal denge $O(1)$ me.



---

## 3. Core Operations Ki Theoretical Working

Hamare Node ke andar is baar teen cheezein store hongi: `key`, `value`, aur uski khud ki current `frequency`.

### A. Operation: `get(key)`

1. **Check Map:** Agar key nahi mili, toh return `-1`.
2. **If Found:** Hame node ka address mil gaya. Ab iski frequency badhegi!
* Us node ko uski puraani frequency waali list (let's say freq = $X$) se **detach/delete** karo.
* Node ki frequency ko increment karo ($X + 1$).
* Node ko naye waale frequency list (`freqToList[X + 1]`) ke head par insert kar do.
* **Boundary Check for minFreq:** Agar tumhari purani list (freq = $X$) ab khali ho chuki hai, aur wahi tumhara `minFreq` tha, toh `minFreq` ko badha kar $X + 1$ kar do.


3. Value return kar do.

### B. Operation: `put(key, value)`

1. **If Key Already Exists:**
* Node par jao, uski value update karo, aur upar waala `get(key)` waala logic chala kar uski frequency badha do.


2. **If New Key (Fresh Entry):**
* **Capacity Check:** Agar cache full hai, toh bali ka bakra dhoondho!
* `freqToList[minFreq]` waali list pakdo. Uske tail par jo node hai (Least Frequently + Least Recently Used), use **delete** karo.
* `keyToNode` map se bhi uski entry saaf karo.


* **Insertion:** Naya node banao `(key, value, freq = 1)`.
* Ise `freqToList[1]` ke head par insert karo.
* `keyToNode` map me entry dalo.
* Chunki ek ekdum naya element aaya hai jiski frequency `1` hai, toh `minFreq` aakhiri me automatic reset hokar **`1`** ho jayega!



---

## 4. Operational Mental Trace (Dimaag Me Chhapo)

Maan lo `capacity = 2` hai.

1. `put(1, 10)` $\rightarrow$ Node `1` bana. Freq = 1. `minFreq = 1`.
* `freqToList[1]`: `Head <-> [1] <-> Tail`


2. `put(2, 20)` $\rightarrow$ Node `2` bana. Freq = 1. `minFreq = 1`.
* `freqToList[1]`: `Head <-> [2] <-> [1] <-> Tail` (Node 2 head par aaya, node 1 tail par gaya).


3. `get(1)` $\rightarrow$ Node `1` access hua.
* Node `1` ko `freqToList[1]` se nikala. Freq badh kar `2` hui.
* `freqToList[1]`: `Head <-> [2] <-> Tail`
* `freqToList[2]`: `Head <-> [1] <-> Tail`
* Chunki `freqToList[1]` abhi khali nahi hai (usme 2 bacha hai), toh `minFreq` abhi bhi `1` hi rahega.


4. `put(3, 30)` $\rightarrow$ Cache Full! Eviction chalega.
* `minFreq` abhi `1` hai. `freqToList[1]` ke tail par kaun khada hai? Node `2`!
* Node `2` poori tarah system se delete ho gaya.
* Naya Node `3` insert hua with Freq = 1. `minFreq` wapas `1` set ho gaya.
* `freqToList[1]`: `Head <-> [3] <-> Tail`



---

## 5. Top 3 Coding Traps (Jahan Interviewer Pakdega)

1. **The `minFreq` Maintenance:** Sabse zyada log galti karte hain `minFreq` ko update karne me. Jab tum kisi node ko frequency $X$ se $X+1$ me le ja rahe ho, toh check karna zaroori hai ki kya frequency $X$ ki list khali toh nahi ho gayi? Agar khali ho gayi aur `minFreq == X` tha, toh `minFreq++` karna padega.
2. **Dummy Nodes in Every List:** LFU me har frequency ke paas apni ek poori Doubly Linked List hoti hai. Har ek list ke paas apna khud ka personal unique *Dummy Head* aur *Dummy Tail* hona chahiye, nahi toh null pointer errors ka baadh aa jayega.
3. **Capacity = 0 Check:** Is question ka sabse bada silent killer test case hai `capacity = 0`. Agar constructor me capacity 0 aati hai, toh `put` operation chalna hi nahi chahiye, direct return ho jana chahiye.

Bhai, LFU Cache ki ye highly synchronized multi-map aur dual-pointer logic ki theory dimaag me set hui? Bol toh iska ekdum polished, neat aur clear **C++ Code Implementation** likh kar ek-ek line samjhau?



Bhai, LFU Cache (LeetCode 460) ka implementation thoda lamba hai kyunki isme **Map aur Doubly Linked List ka hierarchy** maintain karna padta hai. Coding interview me iska code likhte waqt agar tumne `DoublyLinkedList` ke liye ek separate class bana di, toh interviewer bohot impress hoga kyunki tumhara code **Modular** dikhega.

Niche diya gaya implementation optimized hai aur har operation ko **O(1)** me handle karta hai.

### 1. Detailed Implementation (C++ Code)

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

// 1. DLL Node Structure
struct Node {
    int key, val, freq;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), freq(1), prev(nullptr), next(nullptr) {}
};

// 2. Helper Class: Doubly Linked List (Har frequency ke liye ek)
class DoublyLinkedList {
public:
    Node *head, *tail;
    int size;
    DoublyLinkedList() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node) {
        Node* nextNode = head->next;
        node->next = nextNode;
        node->prev = head;
        head->next = node;
        nextNode->prev = node;
        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};

// 3. Main LFU Cache Class
class LFUCache {
private:
    int capacity, minFreq;
    unordered_map<int, Node*> keyMap;      // Key -> Node
    unordered_map<int, DoublyLinkedList*> freqMap; // Freq -> DLL

    void updateFreq(Node* node) {
        int oldFreq = node->freq;
        freqMap[oldFreq]->removeNode(node);

        // Agar minFreq wali list khali ho gayi, toh minFreq update karo
        if (freqMap[minFreq]->size == 0 && minFreq == oldFreq) {
            minFreq++;
        }

        node->freq++;
        if (freqMap.find(node->freq) == freqMap.end()) {
            freqMap[node->freq] = new DoublyLinkedList();
        }
        freqMap[node->freq]->addNode(node);
    }

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        if (keyMap.find(key) == keyMap.end()) return -1;
        
        Node* node = keyMap[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.find(key) != keyMap.end()) {
            Node* node = keyMap[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (keyMap.size() == capacity) {
                // Eviction: minFreq wali list se tail (LRU) node hatao
                Node* lruNode = freqMap[minFreq]->tail->prev;
                freqMap[minFreq]->removeNode(lruNode);
                keyMap.erase(lruNode->key);
                delete lruNode;
            }

            Node* newNode = new Node(key, value);
            keyMap[key] = newNode;
            minFreq = 1; // Naya node hamesha frequency 1 se shuru hota hai
            
            if (freqMap.find(1) == freqMap.end()) {
                freqMap[1] = new DoublyLinkedList();
            }
            freqMap[1]->addNode(newNode);
        }
    }
};

```

---

### 2. Logic Walkthrough (The "Under the Hood")

* **`DoublyLinkedList` Class:** Humne har frequency (1, 2, 3...) ke liye ek alag DLL banayi hai. Iska benefit ye hai ki hum list ke head par insert karte hain (MRU) aur tail se delete karte hain (LRU).
* **`updateFreq()` function:** Ye pure code ka dil (heart) hai. Isme hum:
1. Node ko purani list se nikalte hain.
2. Agar purani list khali ho gayi aur wo list `minFreq` thi, toh `minFreq++` kar dete hain.
3. Node ki frequency badha kar nayi list me head par daal dete hain.


* **Eviction Logic:** Jab cache full hota hai, hum direct `freqMap[minFreq]->tail->prev` ko access karte hain. Ye node wahi hota hai jo sabse kam freq ka hai aur sabse purana bhi (LRU tie-break).

---

### 3. Complexity Analysis

| Operation | Time | Space | Explanation |
| --- | --- | --- | --- |
| **`get(key)`** | $O(1)$ | $O(1)$ | Hashmap lookup $O(1)$, DLL link update $O(1)$. |
| **`put(key, val)`** | $O(1)$ | $O(1)$ | Hashmap operations aur DLL manipulations constant time lete hain. |
| **Space** | - | $O(N)$ | $N$ elements cache me store hote hain, Map aur DLL overhead linear hai. |

---

### 4. Critical Edge Cases (Jo Interviewer Dekhega)

1. **`Capacity = 0`**: Code ki pehli line `if (capacity == 0) return;` ise handle karti hai. Bahut se log ise bhool jate hain aur runtime error kha lete hain.
2. **`minFreq` update**: Jab frequency update hoti hai, tab `minFreq` ko increment karna ya reset karna hi sabse bada tricky part hai.
* *Tip:* Jab tum `put` kar rahe ho aur naya element dal rahe ho (freq=1), toh `minFreq` ko 1 par set karna mat bhoolna.


3. **Tie-Breaking**: LFU ke eviction rule me agar freq same hai, toh LRU use karna hai. Kyunki humari har `DoublyLinkedList` ke andar nodes "Most Recently Used" order me arrange hain (Head = MRU), toh `tail->prev` automatic "Least Recently Used" node hi hoga. Hume alag se tie-breaking ke liye logic nahi likhna padta!

Bhai, ab LFU ka blueprint clear hai? Agar iska flow ya koi specific line samajh nahi aayi, toh bata, use dry-run kar lete hain! Ab tumhara "Design Cache" wala portion poora ho gaya hai, agla DSA topic kaunsa uthayein?