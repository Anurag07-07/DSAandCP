**Morris Traversal** Tree Traversal ka ek aisa magical tareeka hai jismein bina kisi **Stack** ya **Recursion** ke (yani $O(1)$ Auxiliary Space mein) Inorder ya Preorder traversal kiya ja sakta hai.

Normal traversal (Recursive ya Iterative) mein computer ko wapas upar aane ke liye rasta yaad rakhna padta hai, jiske liye wo Memory Stack ka use karta hai. Morris Traversal mein hum **Threaded Binary Tree** ka concept use karte hain—yani tree ke andar hi khali padi links (NULL pointers) ko temporarily use karke wapas upar aane ka rasta bana lete hain.

---

## Morris Inorder Traversal ka Core Concept

Inorder traversal ka rule hota hai: **Left -> Root -> Right**.

Jab aap kisi node ke Left subtree mein chale jaate ho, toh wapas us node (Root) par aane ka koi rasta nahi bacha agar stack na ho. Morris Traversal iska jugaad aise nikalta hai:

> **Golden Rule:** Left subtree ka jo **sabse aakhri node** hoga (yani Inorder Predecessor), uska `right` pointer hamesha `NULL` hota hai. Hum us `NULL` ko temporarily current node se connect kar dete hain.

---

## Algorithm (Step-by-step)

Maan lo humara current node `curr` hai, jo shuru mein `root` par hoga. Jab tak `curr` NULL nahi hota, tab tak ye steps follow karo:

### Case 1: Agar `curr->left` NULL hai

* Iska matlab left mein kuch nahi hai, toh rule ke mutabik Root ko print karo.
* Aur right mein chale jao: `curr = curr->right`.

### Case 2: Agar `curr->left` NULL nahi hai

* Iska matlab left subtree exist karta hai. Abhi hume left mein jaane se pehle wapas aane ka rasta banana hoga.
* `curr` ke left subtree ka **Inorder Predecessor** dhoondo (Yani left child par jao, aur phir jitna right ja sakte ho jao).
* **Sub-case A (Rasta nahi bana hua):** Agar predecessor ka `right` pointer `NULL` hai:
* Us `right` pointer ko `curr` par point kar do (Rasta ban gaya!).
* Ab safely left mein move kar jao: `curr = curr->left`.


* **Sub-case B (Rasta pehle se bana hua hai):** Agar predecessor ka `right` pointer `curr` ko hi point kar raha hai:
* Iska matlab hum left subtree poora ghoom kar wapas aa chuke hain.
* Ab us temporary raste ko todo (Taaki tree jaisa tha waisa hi ho jaye): `predecessor->right = NULL`.
* `curr` ko print/visit karo.
* Aur ab right mein move kar jao: `curr = curr->right`.



---

## Dry Run (Ek Chote Example Se Samjho)

Maan lo humara tree ye hai:

```text
    1
   / \
  2   3

```

1. **Initial:** `curr` hai Node 1 par.
2. Node 1 ka left exist karta hai (Node 2). Hum iska predecessor dhoondenge. Node 2 ka koi right nahi hai, toh Node 2 hi khud predecessor hai.
3. Node 2 ka `right` abhi `NULL` hai (Sub-case A). Humne link bana di: `2->right = 1`.
4. `curr` move kar gaya left mein: `curr = 2`.
5. Ab `curr` hai Node 2 par. Iska left `NULL` hai (Case 1). Humne **2 ko print kiya**.
6. `curr` move kiya right mein: `curr = curr->right` (Yani wapas Node 1 par aa gaya link ki wajah se).
7. Ab `curr` phir se Node 1 par hai. Phir se predecessor dhoonda (Node 2). Is baar Node 2 ka `right` pehle se 1 ko point kar raha hai (Sub-case B).
8. Humne link todi: `2->right = NULL`. **1 ko print kiya**.
9. `curr` move kiya right mein: `curr = 3`.
10. Node 3 ka left `NULL` hai. **3 ko print kiya**. `curr` ho gaya `NULL`. Traversal Khatam!

**Output:** `2, 1, 3`

---

## C++ Code Implementation

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void morrisTraversalInorder(Node* root) {
    Node* curr = root;
    
    while (curr != NULL) {
        if (curr->left == NULL) {
            // Case 1: Left nahi hai, toh print karo aur right jao
            cout << curr->data << " ";
            curr = curr->right;
        } 
        else {
            // Case 2: Left hai, toh predecessor dhoondo
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            
            // Sub-case A: Link banana hai
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } 
            // Sub-case B: Link todna hai
            else {
                pred->right = NULL;
                cout << curr->data << " "; // Root visit ho gaya
                curr = curr->right;
            }
        }
    }
}

```

---

## Complexity Analysis

| Metric | Complexity | Explanation |
| --- | --- | --- |
| **Time Complexity** | $O(N)$ | Lagta hai ki nested `while` loop ki wajah se $O(N^2)$ hoga, lekin dhyan se dekho toh pure traversal mein hum har edge ko zyada se zyada 3 baar visit karte hain (Link banane, link todne, aur traverse karne). Isliye amortized time $O(N)$ hi rehta hai. |
| **Space Complexity** | $O(1)$ | Hum koi extra stack ya queue nahi bana rahe hain, na hi recursion use kar rahe hain. Hum sirf existing `NULL` pointers ko use kar rahe hain. |

## Morris Traversal ke Fayde aur Nuksaan

### Pros:

* **Memory Efficient:** Jahan memory bohot constrained hoti hai (jaise embedded systems), wahan ye vardan hai kyunki iski space complexity $O(1)$ hai.

### Cons:

* **Tree Modification:** Traversal ke dauran ye tree ke structure ko modify karta hai (halanki baad mein thik kar deta hai). Agar multi-threaded environment hai jahan koi doosra thread same time par tree read kar raha ho, toh ye fail ho jayega.
* **Code Complexity:** Normal recursive code 3-4 line ka hota hai, jabki ise samajhna aur implement karna thoda tricky hai.



Morris Traversal ke piche ki **soch (intuition)** bohot hi brilliant hai. Jab hum Recursion ya Stack use karte hain, toh computer background mein ek 'Roadmap' yaad rakhta hai ki: *"Pehle left jao, aur jab wahan se kaam khatam ho jaye toh wapas is root node par aana."*

Agar hume **$O(1)$ Space** mein kaam karna hai, toh iska matlab hum memory mein koi roadmap save nahi kar sakte. Toh Morris ne socha: **"Kyun na hum Tree ke andar hi temporary raste (links) bana dein, aur jab kaam ho jaye toh un raste ko mita dein?"**

Chalo bilkul shuru se samajhte hain ki ye dimaag mein kaise aata hai aur algorithm kaise kaam karta hai.

---

## Intution: Soch Kaise Bani?

Inorder Traversal ka standard niyam hai: **Left $\rightarrow$ Root $\rightarrow$ Right**.

Maan lo aap kisi Node par khade ho. Agar aap iske Left mein chale gaye, toh wapas is Node par aane ka koi rasta nahi bachega (agar Stack na ho).

1. **Wapas kaise aayein?** Left subtree ka jo **sabse aakhri node** hoga (Inorder traversal ke mutabik), uske theek baad is Node ki baari aani chahiye.
2. **Inorder Predecessor:** Left subtree ka sabse aakhri node kaise dhoondein? Left child par jao, aur phir jitna ho sake **Right** chalte jao. Jo aakhri node milega, use hum **Inorder Predecessor** kehte hain.
3. **Jugaad:** Us predecessor node ka `right` pointer hamesha `NULL` hota hai. Morris ne socha ki is `NULL` ko temporary use karke wapas Root node se connect (Thread) kar dete hain!

---

## 3 Core Cases (Kaise Kaam Karta Hai)

Hum ek `curr` pointer lete hain jo shuru mein `root` par hota hai. Hum pure tree mein sirf 3 conditions check karte hain:

### Case 1: Agar Left Subtree hai hi nahi (`curr->left == NULL`)

* Jab left mein kuch hai hi nahi, toh Inorder ke mutabik Root ko visit karo (Print `curr->data`).
* Aur right mein move kar jao: `curr = curr->right`.

### Case 2: Agar Left Subtree exist karta hai

Agar left subtree hai, toh pehle uske **Inorder Predecessor** (`pred`) ko dhoondo (Go left once, then right as much as possible). Ab yahan do baatein ho sakti hain:

* **Sub-case A: `pred->right == NULL` (Rasta nahi bana hai)**
* Iska matlab hum is node par pehli baar aaye hain. Hum rasta banayenge: `pred->right = curr;`
* Rasta ban gaya, ab hum safe hain. Toh left subtree ko explore karne chale jao: `curr = curr->left;`


* **Sub-case B: `pred->right == curr` (Rasta pehle se bana hua hai)**
* Iska matlab hum left subtree ko poora ghoom chuke hain aur is temporary link ki wajah se hi wapas upar aaye hain!
* Ab hum apna rasta saaf karenge (Tree ko wapas normal karenge): `pred->right = NULL;`
* Kyunki left subtree ho chuka hai, toh ab Root ki baari hai: Print `curr->data`.
* Aur phir right subtree mein chale jao: `curr = curr->right;`



---

## Ek Real Example Se Dry Run

Maan lo humara Tree aisa dikhta hai:

```text
      4
     / \
    2   5
   / \
  1   3

```

Chalo step-by-step dekhte hain dimaag mein kya chal raha hai:

1. **`curr` hai 4 par:** * 4 ka left hai (Node 2). Humne 4 ka predecessor dhoonda. 2 par gaye, phir right ghumte ghumte **Node 3** par pahuche.
* Node 3 ka `right` abhi `NULL` hai. Humne link bana di: `3->right = 4`.
* `curr` chala gaya left mein: `curr = 2`.


2. **`curr` hai 2 par:**
* 2 ka left hai (Node 1). 2 ka predecessor dhoonda, wo **Node 1** hi hai.
* Node 1 ka `right` abhi `NULL` hai. Link bana di: `1->right = 2`.
* `curr` chala gaya left mein: `curr = 1`.


3. **`curr` hai 1 par:**
* 1 ka left `NULL` hai (**Case 1**).
* **Print: 1**
* `curr` chala gaya right mein: `curr = curr->right` (Yani temporary link ki wajah se `curr` wapas **Node 2** par aa gaya).


4. **`curr` phir se hai 2 par:**
* 2 ka left hai, predecessor dhoonda (Node 1). Lekin is baar `1->right == 2` pehle se hai (**Sub-case B**).
* Iska matlab left ho gaya! Humne link todi: `1->right = NULL`.
* **Print: 2**
* `curr` chala gaya right mein: `curr = 3`.


5. **`curr` hai 3 par:**
* 3 ka left `NULL` hai.
* **Print: 3**
* `curr` chala gaya right mein: `curr = curr->right` (Temporary link ki wajah se `curr` wapas **Node 4** par pahuchega).


6. **`curr` phir se hai 4 par:**
* 4 ka left hai, predecessor dhoonda (Node 3). Is baar `3->right == 4` pehle se hai.
* Link todi: `3->right = NULL`.
* **Print: 4**
* `curr` chala gaya right mein: `curr = 5`.


7. **`curr` hai 5 par:**
* 5 ka left `NULL` hai.
* **Print: 5**
* `curr` gaya right mein: `curr = NULL`. (Loop Khatam!)



**Final Oupoot:** `1 2 3 4 5` (Ekdum Perfect Inorder!)

---

## C++ Code

```cpp
void morrisInorder(Node* root) {
    Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            cout << curr->data << " ";
            curr = curr->right;
        } else {
            // Predecessor dhoondo
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = curr; // Link banaya
                curr = curr->left;
            } else {
                pred->right = NULL; // Link toda
                cout << curr->data << " "; // Root visit kiya
                curr = curr->right;
            }
        }
    }
}

```

## Time aur Space Complexity ka Sach

* **Space Complexity: $O(1)$** - Humne koi stack ya queue nahi banayi, bas khali paday `NULL` pointers ka sahi use kiya.
* **Time Complexity: $O(N)$** - Dekhne mein lagta hai ki nested `while` loop hai toh $O(N^2)$ hoga. Par dhyan se dekho, hum pure tree mein har edge ko maximum **3 baar** touch karte hain (pehli baar rasta banane, doosri baar us raste se guzarne, aur teesri baar rasta todne).

Isliye mathematical terms mein ye $3 \times N$ steps leta hai, jise hum Big-O mein **$O(N)$** hi likhte hain.

Kya aapko Preorder Morris Traversal ki soch bhi samajhni hai, ya Inorder bilkul clear ho gaya?



Morris Traversal se **Preorder** nikalna bilkul Inorder jaisa hi hai, bas ek chota sa aur bohot bada change hai—**Printing ki timing!**

Preorder ka niyam hota hai: **Root $\rightarrow$ Left $\rightarrow$ Right**.
Yani jaise hi hume koi naya node mile, hume use **turant print** karna hai, bina left subtree mein ghoome.

Chalo iski soch aur algorithm ko breakdown karte hain.

---

## Intuition: Inorder se Preorder Kaise Alag Hai?

Inorder mein hum kya kar rahe the? Jab hum left subtree ghoom kar *wapas upar aa rahe the* (yani jab link pehle se bani hui milti thi), tab hum root ko print karte the.

Lekin Preorder mein hume pehle hi Root ko print karna hai. Toh iska matlab:

1. Jab left child **hai hi nahi**, tab toh hum print karenge hi.
2. Jab left child **hai**, aur hum **pehli baar** rasta (link) bana rahe hain, hum left subtree mein jaane se *theek pehle* hi current node ko print kar denge!

---

## Algorithm (Step-by-Step)

Maan lo pointer `curr` abhi `root` par hai. Jab tak `curr` NULL nahi hota, ye steps follow karo:

### Case 1: Agar `curr->left` NULL hai

* Left mein kuch nahi hai, toh Root ko print karo (Preorder niyam).
* Right mein chale jao: `curr = curr->right`.

### Case 2: Agar `curr->left` NULL nahi hai

* Left subtree ke **Inorder Predecessor** (`pred`) ko dhoondo.
* **Sub-case A (Link nahi bana hai - `pred->right == NULL`):**
* Iska matlab hum is node par **pehli baar** aaye hain.
* **CRITICAL STEP:** Kyunki hum left mein ghusne wale hain aur niyam Root $\rightarrow$ Left hai, isliye **`curr->data` ko abhi print kar do!**
* Temporary link banao: `pred->right = curr`.
* Left mein move kar jao: `curr = curr->left`.


* **Sub-case B (Link pehle se bana hai - `pred->right == curr`):**
* Iska matlab hum left subtree poora ghoom kar wapas aaye hain. (Aur Root ko hum pehli baar mein hi print kar chuke hain, toh ab dobara print nahi karna).
* Link ko todo: `pred->right = NULL`.
* Right mein move kar jao: `curr = curr->right`.



---

## Dry Run (Ek Chote Example Se)

Chalo wahi purana tree lete hain aur dekhte hain Preorder kaise nikalta hai:

```text
      4
     / \
    2   5
   / \
  1   3

```

1. **`curr` hai 4 par:**
* 4 ka left hai (Node 2). Predecessor dhoonda, mila **Node 3**.
* Node 3 ka right `NULL` hai (Pehli baar aaye hain).
* **[PRINT: 4]** *(Kyunki left mein jaane se pehle print karna hai)*
* Link banayi: `3->right = 4` aur `curr` chala gaya left mein (`curr = 2`).


2. **`curr` hai 2 par:**
* 2 ka left hai (Node 1). Predecessor mila **Node 1**.
* Node 1 ka right `NULL` hai.
* **[PRINT: 2]**
* Link banayi: `1->right = 2` aur `curr` chala gaya left mein (`curr = 1`).


3. **`curr` hai 1 par:**
* 1 ka left `NULL` hai (**Case 1**).
* **[PRINT: 1]**
* `curr` chala gaya right mein (`curr = 2` link ki wajah se).


4. **`curr` phir se hai 2 par:**
* Predecessor (Node 1) ka right pehle se 2 ko point kar raha hai.
* Iska matlab left subtree ho chuka hai. Link todo: `1->right = NULL`.
* *(Yahan print nahi karenge, kyunki 2 pehle hi print ho chuka hai)*
* `curr` chala gaya right mein (`curr = 3`).


5. **`curr` hai 3 par:**
* 3 ka left `NULL` hai.
* **[PRINT: 3]**
* `curr` chala gaya right mein (`curr = 4` link ki wajah se).


6. **`curr` phir se hai 4 par:**
* Predecessor (Node 3) ka right pehle se 4 hai.
* Link todo: `3->right = NULL`.
* `curr` chala gaya right mein (`curr = 5`).


7. **`curr` hai 5 par:**
* 5 ka left `NULL` hai.
* **[PRINT: 5]**
* `curr = curr->right` (Yani `NULL`). Loop khatam!



**Final Preorder Output:** `4 2 1 3 5` (Ekdum Sahi!)

---

## C++ Code Implementation

Inorder aur Preorder ke code mein **95% similarity** hai. Bas dhyan se dekho `cout` kahan par lagaya hai:

```cpp
void morrisPreorder(Node* root) {
    Node* curr = root;
    
    while (curr != NULL) {
        if (curr->left == NULL) {
            // Case 1: Left nahi hai, toh print karo aur right jao
            cout << curr->data << " ";
            curr = curr->right;
        } 
        else {
            // Case 2: Predecessor dhoondo
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }
            
            // Sub-case A: Pehli baar aaye hain -> PRINT karo aur link banao
            if (pred->right == NULL) {
                cout << curr->data << " "; // <-- YAHAN CHANGE HAI (Preorder ke liye)
                pred->right = curr;
                curr = curr->left;
            } 
            // Sub-case B: Doosri baar aaye hain -> Link todo aur right jao
            else {
                pred->right = NULL;
                curr = curr->right;
            }
        }
    }
}

```

---

## Quick Summary: Inorder vs Preorder Morris

| Feature | Morris Inorder | Morris Preorder |
| --- | --- | --- |
| **`curr->left == NULL`** | Print karo, Right jao | Print karo, Right jao |
| **`pred->right == NULL` (Link banate waqt)** | Print **NAHI** karna, sirf Left jao | **PRINT KARO**, phir Left jao |
| **`pred->right == curr` (Link todte waqt)** | **PRINT KARO**, phir Right jao | Print **NAHI** karna, sirf Right jao |
| **Space/Time Complexity** | $O(1)$ Space, $O(N)$ Time | $O(1)$ Space, $O(N)$ Time |

Ab aap dono algorithms ko aaram se compare kar sakte ho. Dono mein sirf is baat ka khel hai ki `curr` node ko screen par kab show karna hai!




Morris Traversal se **Postorder (Left $\rightarrow$ Right $\rightarrow$ Root)** nikalna, Inorder aur Preorder ke mukable thoda sa tricky aur zyada interesting hai.

Inorder aur Preorder mein hum `curr` node ko kisi na kisi point par directly print kar dete the. Lekin Postorder ka niyam hai ki **Root sabse aakhri mein** visit hona chahiye (Left aur Right subtree ke baad). Hum binary tree mein niche se upar bina stack ke nahi ja sakte, isliye Morris Postorder mein ek mast trick use hoti hai—**"Reverse Linked List"** ka concept.

Chalo isko bilkul simplified tarike se samajhte hain.

---

## Core Intuition: Postorder ki Soch

Postorder mein jab hum kisi left subtree ko poora ghoom chuke hote hain, toh hume us left subtree ke nodes ko **niche se upar (reverse order mein)** print karna hota hai.

Maan lo humara ek chota subtree aisa hai:

```text
    2
   / \
  1   3

```

Jab hum temporary link todte hain (yani jab hume pata chalta hai ki left subtree khatam ho gaya), tab hum `curr->left` (Node 2) se lekar `predecessor` (Node 3) tak ki puri right boundary ko **ulte order** mein print karte hain.

* Seedha order kya hai: `2 -> 3`
* Ulta order kya hoga: `3, 2`

---

## Algorithm (Step-by-Step)

Hum ek dummy node concept ya last mein special check laga kar chalte hain, par aasan bhasha mein steps ye hain:

### Case 1: Agar `curr->left` NULL hai

* Isme hum kuch print nahi karenge (kyunki root ko abhi print nahi karna).
* Bas right mein move kar jao: `curr = curr->right`.

### Case 2: Agar `curr->left` NULL nahi hai

* Left subtree ke **Inorder Predecessor** (`pred`) ko dhoondo.
* **Sub-case A (Link nahi bana hai):**
* Temporary link banao: `pred->right = curr`.
* Left mein move kar jao: `curr = curr->left`.


* **Sub-case B (Link pehle se bana hai - `pred->right == curr`):**
* Iska matlab left subtree ka kaam ho chuka hai.
* Link ko todne se pehle ya baad mein, hume `curr->left` se lekar `pred` tak ke saare nodes ko **REVERSE order** mein print karna hai.
* Link ko todo: `pred->right = NULL`.
* Right mein move kar jao: `curr = curr->right`.



### Special Step (End of Traversal)

Jab loop khatam ho jaye, toh pooray tree ka jo main `root` hai, uski right boundary (Root se lekar extreme right node tak) abhi bhi print hona baki reh jati hai. Use loop ke bahar alag se reverse karke print karte hain.

---

## Reverse Kaise Karte Hain? (The Magic Trick)

Nodes ko ulta print karne ke liye hum standard **Reverse a Linked List** ka logic use karte hain:

1. `curr->left` se `pred` tak ki chain ko temporary pointer badal kar ulta (reverse) kar dete hain.
2. Unhe print karte hain.
3. Tree ka structure kharab na ho, isliye unhe **phir se reverse** karke seedha kar dete hain.

---

## C++ Code Implementation

Isko code mein dekhoge toh ekdum dimaag mein fit ho jayega:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Linked list ko reverse karne ka function
Node* reverseFunction(Node* start) {
    Node* prev = NULL;
    Node* curr = start;
    Node* next = NULL;
    while (curr != NULL) {
        next = curr->right;
        curr->right = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Right boundary ko ulta karke print karne ka function
void printReversePairs(Node* start, Node* end) {
    Node* reverseHead = reverseFunction(start);
    
    // Print karlo saare nodes ko
    Node* temp = reverseHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    
    // Wapas tree ko pehle jaisa seedha kar do
    reverseFunction(reverseHead);
}

void morrisPostorder(Node* root) {
    if (root == NULL) return;

    // Ek Dummy Node banate hain taaki loop ke baad wala special step na karna pade
    Node* dummy = new Node(0);
    dummy->left = root;
    Node* curr = dummy;

    while (curr != NULL) {
        if (curr->left == NULL) {
            curr = curr->right;
        } 
        else {
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = curr; // Link banaya
                curr = curr->left;
            } 
            else {
                // Jab link tod rahe hain, toh reverse print karenge
                printReversePairs(curr->left, pred);
                
                pred->right = NULL; // Link toda
                curr = curr->right;
            }
        }
    }
}

```

---

## Dry Run (Ek Chote Example Se)

Maan lo humara tree ye hai:

```text
    1
   / \
  2   3

```

Humne iske upar ek `dummy` node lagaya jiska left `1` hai. `curr` shuru hua `dummy` se.

1. `curr` gaya Node 1 par. Node 1 ka left hai Node 2. Predecessor Node 2 hi hai. Link banayi: `2->right = 1`. `curr` chala gaya Node 2 par.
2. Node 2 ka left `NULL` hai, toh `curr` chala gaya right mein (`curr` wapas 1 par aa gaya).
3. Node 1 par dobara aaye, link pehle se thi. Ab hum link todenge aur **`curr->left` (Node 2) se lekar `pred` (Node 2) tak** ki boundary ko reverse print karenge. Yahan sirf ek hi node hai, toh **[PRINT: 2]**. Link toot gayi. `curr` chala gaya Node 3 par.
4. Node 3 ka left `NULL` hai, `curr` chala gaya right mein (Yani dummy node par wapas aa gaya).
5. Dummy node par link pehle se bani thi (Node 3 se Dummy tak). Hum link todenge aur `curr->left` (Node 1) se lekar `pred` (Node 3) tak ki right boundary ko reverse karenge.
* Seedhi boundary thi: `1 -> 3`
* Reverse ho kar bani: `3 -> 1`
* **[PRINT: 3 1]**


6. Loop khatam!

**Final Output:** `2 3 1` (Perfect Postorder!)

---

## Complexity Analysis

* **Space Complexity:** $O(1)$ - Kyunki hum reverse karte waqt bhi sirf pointers badal rahe hain, koi naya space ya stack create nahi kar rahe.
* **Time Complexity:** $O(N)$ - Har node ki boundary ko hum pure traversal mein maximum 2-3 baar hi reverse/visit karte hain, isliye time complexity linear hi rehti hai.

## 💡 Pro-Tip (Interview ke liye Shortcut)

Agar Interviewer aapse kahe ki Morris Postorder likho aur aapko reverse list wala logic bohot complex lag raha ho, toh ek **Tricky-Jugaad** hota hai:

> Morris **Preorder** ka code likho par usme `Root -> Left -> Right` ki jagah **`Root -> Right -> Left`** kar do (yani left ke saare logic ko right se badal do). Isse jo output aayega, wo pure Postorder ka **Ulaalat (Reverse)** hoga. Baad mein pure output array/vector ko reverse karke interviewer ko de do! Halanki isme $O(N)$ space lag jayega array store karne ke liye, par bina stack ke traversal ho jayega.

Agar pure $O(1)$ space chahiye, toh upar bataya hua **Reverse Linked List** wala method hi standard aur sahi tarika hai.

Kya Postorder ka ye reverse karne wala logic clear hua?



**Flatten Binary Tree to Linked List** ek bohot hi popular problem hai. Iska matlab hota hai ki ek normal Binary Tree ko hume ek **Single Right-Skewed Tree** (jo ek Linked List ki tarah dikhe) mein convert karna hai.

Iska order hamesha **Preorder Traversal (Root $\rightarrow$ Left $\rightarrow$ Right)** ke mutabik hona chahiye, aur do conditions follow karni hoti hain:

1. Har node ka `left` pointer `NULL` ho jana chahiye.
2. Har node ka `right` pointer next node ko point karna chahiye.

Ise karne ke 3 tarike hain, lekin sabse best aur **$O(1)$ Space** wala tarika **Morris Traversal ke concept** par hi chalta hai. Chalo isko ekdum deeply samajhte hain.

---

## 💡 Intuition: Soch Kaise Bani?

Preorder mein hum kya karte hain? **Root $\rightarrow$ Left $\rightarrow$ Right**.

Maan lo aapke paas ek tree hai:

```text
    1
   / \
  2   5

```

Agar hum ise flatten karenge, toh 1 ke right mein 2 aana chahiye, aur 2 ke right mein 5 aana chahiye (`1 -> 2 -> 5`).

Lekin agar humne 1 ke `right` mein seedhe 2 ko daal diya, toh **Node 5 toh kho jayega!** **Toh solution kya hai?** Hume pata hai ki Preorder ke mutabik, Node 5 ki baari tab aayegi jab Left Subtree (Node 2) ka kaam poora khatam ho jayega. Aur left subtree ka kaam kab khatam hota hai? Uske **sabse aakhri node (Inorder Predecessor)** par!

* Yahan Node 2 ka koi child nahi hai, toh Node 2 hi aakhri node hai.
* Agar hum Node 5 ko temporarily uthakar Node 2 ke `right` mein chipka dein, toh humara kam aasan ho jayega!

---

## Algorithm (Step-by-Step)

Hum ek pointer `curr` lenge jo `root` se shuru hoga. Jab tak `curr` NULL nahi hota, tab tak:

1. **Check karo:** Kya `curr->left` exist karta hai?
2. **Agar nahi karta (`curr->left == NULL`):** Toh tension nahi hai, bas right mein badh jao: `curr = curr->right`.
3. **Agar left exist karta hai (`curr->left != NULL`):**
* Left subtree mein jao aur uska **sabse rightmost (aakhri) node** dhoondo. Ise hum `pred` (predecessor) bolenge.
* Us `pred` ke `right` pointer ko `curr->right` se connect kar do. (Yani humne right subtree ko safe jagah shift kar diya).
* Ab `curr->right` ko uthakar `curr->left` par point kar do.
* `curr->left` ko `NULL` kar do (Kyunki left mein kuch nahi chorna).
* Ab `curr` ko uske naye right child par move kar do: `curr = curr->right`.



---

## 🔍 Dry Run: Ek Real Example Se Samjho

Chalo is tree ko flatten karte hain:

```text
        1
       / \
      2   5
     / \   \
    3   4   6

```

### Step 1: `curr` hai Node 1 par

* 1 ka left exist karta hai (Node 2).
* Node 2 ka rightmost node dhoondo $\rightarrow$ Mila **Node 4**.
* Node 4 ke right ko 1 ke right se connect karo: `4->right = 5`.
* Ab 1 ka left uthakar uske right mein daal do: `1->right = 2`.
* 1 ke left ko `NULL` kar do: `1->left = NULL`.
* `curr` move kiya right mein: `curr = 2`.

**Tree ab aisa dikhega:**

```text
    1
     \
      2
     / \
    3   4
         \
          5
           \
            6

```

### Step 2: `curr` hai Node 2 par

* 2 ka left exist karta hai (Node 3).
* Node 3 ka rightmost node dhoondo $\rightarrow$ Node 3 ka koi right nahi hai, toh **Node 3** hi khud hai.
* Node 3 ke right ko 2 ke right se connect karo: `3->right = 4`.
* Ab 2 ka left uthakar uske right mein daal do: `2->right = 3`.
* 2 ke left ko `NULL` kar do: `2->left = NULL`.
* `curr` move kiya right mein: `curr = 3`.

**Tree ab aisa dikhega:**

```text
    1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6

```

### Baaki Steps:

Ab `curr` jab Node 3, 4, 5, aur 6 par jayega, toh kisi ka bhi left child nahi milega (`curr->left == NULL`). Toh loop bas `curr = curr->right` karke aage badhta jayega aur end mein poora tree ek Linked List ban chuka hoga!

---

## 💻 C++ Code Implementation

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void flattenTree(Node* root) {
    Node* curr = root;
    
    while (curr != NULL) {
        // Agar left child exist karta hai
        if (curr->left != NULL) {
            // Left subtree ka rightmost node (predecessor) dhoondo
            Node* pred = curr->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            
            // Predecessor ke right ko current ke right se connect karo
            pred->right = curr->right;
            
            // Current ke left ko right mein shift karo
            curr->right = curr->left;
            curr->left = NULL; // Left ko NULL banana compulsory hai
        }
        
        // Agle node par jao (jo ki ab right mein hi hoga)
        curr = curr->right;
    }
}

```

---

## 📊 Complexity Analysis

* **Time Complexity: $O(N)$** Aapko lag sakta hai ki loop ke andar loop hai toh $O(N^2)$ hoga. Lekin pure process mein hum har edge ko maximum do baar visit karte hain (ek baar rightmost node dhoondte waqt aur ek baar `curr` ko aage badhate waqt). Isliye amortized time $O(N)$ aata hai.
* **Space Complexity: $O(1)$**
Humne na toh koi recursion use kiya (no call stack space) aur na hi koi extra queue/stack banayi. Humne sirf tree ke existing pointers ko hi rearrange kiya hai.

Kya ye approach aur iska dry run aapko achhe se clear hua?