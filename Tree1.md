Bhai, simple words me samjho toh **Tree ek non-linear data structure hai**, jo data ko ek hierarchical (uppar se neeche ke) order me store karta hai.

Abhi tak tumne `Array` ya `Linked List` padha hoga, jisme data ek line me (linear) hota hai. Lekin Tree me data "Parent-Child" ke rishte me hota hai—jaise tumhari family tree ya tumhare computer ke folders.

C++ me isko kaise samajhna hai aur code kaise karna hai, aao poori detail me dekhte hain.

---

## 1. Tree ke Kuch Zaroori Terms (Terminology)

Tree ko samajhne ke liye uske components ka naam pata hona chahiye:

* **Node:** Tree ka har ek element (jo data hold karta hai) usko Node kehte hain.
* **Root:** Tree ka sabse pehla ya sabse uppar wala node jahan se tree shuru hota hai.
* **Parent & Child:** Agar Node A se line nikal kar Node B par ja rahi hai, toh A parent hai aur B uska child.
* **Leaf Node:** Wo nodes jinke aage koi bachhe (children) nahi hote. Ye tree ke bilkul end me hote hain.

---

## 2. Binary Tree: Sabse Important Tree Type

DSA me sabse pehle aur sabse zyada hum **Binary Tree** padhte hain. Iska ek hi rule hai: **Kisi bhi parent ke maximum 2 children ho sakte hain** (ya toh 0, ya 1, ya 2). Unhe hum *Left Child* and *Right Child* bolte hain.

### C++ me Node kaise banta hai?

Linked List me hum ek `next` pointer rakhte hain na? Binary Tree me hum **do pointers** rakhte hain—ek left child ke liye aur ek right child ke liye.

```cpp
#include <iostream>
using namespace std;

// Tree ke ek single Node ka structure
struct Node {
    int data;           // Node ki value
    Node* left;        // Left child ka address
    Node* right;       // Right child ka address

    // Constructor taaki naya node aasani se ban sake
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int main() {
    // 1. Root node banaya
    Node* root = new Node(1);

    // 2. Left aur Right children jode
    root->left = new Node(2);
    root->right = new Node(3);

    // 3. Leaf nodes jode (2 ke bachhe)
    root->left->left = new Node(4);

    cout << "Root Node ka data: " << root->data << endl;
    cout << "Root ke Left ka data: " << root->left->data << endl;

    return 0;
}

```

---

## 3. Tree Traversal (Tree me ghoomna kaise hai?)

Linear structures (like array) me toh tum seedha loop chala dete ho, par tree me traverse karne ke main 3 tarike hote hain (jinhe depth-first traversals kehte hain):

1. **Inorder (Left -> Root -> Right):** Pehle left sub-tree par jao, phir root print karo, phir right par jao. (Binary Search Tree me ye hamesha sorted order deta hai).
2. **Preorder (Root -> Left -> Right):** Pehle root print karo, phir left jao, phir right jao.
3. **Postorder (Left -> Right -> Root):** Pehle left jao, phir right jao, aur end me root print karo (delete karne ke kaam aata hai).

### Traversal ka C++ Code (Recursion se):

```cpp
void printInorder(Node* node) {
    if (node == nullptr) return; // Base case: agar node khali hai toh ruk jao

    printInorder(node->left);   // 1. Left subtree par jao
    cout << node->data << " ";  // 2. Root ka data print karo
    printInorder(node->right);  // 3. Right subtree par jao
}

```

---

## 4. DSA me Tree ke Types jo tum aage padhoge

Jaise-jaise tum aage badhoge, tumko ye main tree types milenge:

* **Binary Search Tree (BST):** Iska rule bada sahi hai—Root se chhote saare elements *Left* me honge, aur bade saare elements *Right* me honge. Isme search karna bahut fast hota hai ($O(\log N)$).
* **AVL Tree / Red-Black Tree:** Ye self-balancing trees hote hain. Jab normal BST ek taraf jhuk jata hai (skewed ho jata hai), toh ye use balance karte hain taaki performance kharab na ho.
* **Heap:** Ye bhi ek special tree hai jo Max ya Min value ko turant ($O(1)$ me) nikalne ke kaam aata hai (Priority Queue me use hota hai).

---

> 💡 **Bhai ek kaam ki baat:** Tree ke 90% sawal **Recursion** se solve hote hain. Agar tumhara recursion strong hai, toh tree tumhare liye halwa ban jayega. Agar recursion me thoda haath tang hai, toh pehle uski thodi practice kar lena!



Bhai, **Binary Search Tree (BST)** normal Binary Tree ka ek advanced aur bohot hi kaam ka roop hai. Iska sabse bada fayda ye hai ki isme kisi element ko search karna, insert karna, ya delete karna bohot fast ho jata hai.

Aao iska core logic aur element insert karne ka tareeka poori detail me samajhte hain.

---

## 1. BST ka Golden Rule (Logic)

BST ka ek simple rule hota hai jo har ek node par apply hota hai:

1. **Left Subtree:** Parent node se **chhoti (smaller)** saari values hamesha uske left side me jayengi.
2. **Right Subtree:** Parent node se **badi (greater)** saari values hamesha uske right side me jayengi.
3. **No Duplicates:** Normally BST me duplicate values nahi rakhte (agar rakhni ho toh left ya right me se kisi ek taraf fix kar dete hain).

### Ek Example se samjho:

Maano hume ye numbers insert karne hain: `50, 30, 70, 20, 40`

1. Sabse pehle `50` aaya, ye ban gaya hamara **Root**.
2. Phir `30` aaya. `30`, 50 se chhota hai? Haan, toh ye 50 ke **left** me jayega.
3. Phir `70` aaya. `70`, 50 se bada hai? Haan, toh ye 50 ke **right** me jayega.
4. Phir `20` aaya. 50 se chhota hai (left jao) -> wahan 30 mila. 30 se bhi chhota hai? Haan, toh ye 30 ke **left** me jayega.
5. Phir `40` aaya. 50 se chhota hai (left jao) -> wahan 30 mila. 30 se bada hai? Haan, toh ye 30 ke **right** me jayega.

Final tree aisa dikhega:

```text
      50
     /  \
    30   70
   /  \
  20  40

```

---

## 2. Insertion ka Logic (Recursion se)

Jab bhi hume naya element insert karna hota hai, hum root se shuru karte hain aur comparison karte hain:

* **Base Case:** Agar ghoomte-ghoomte hum `nullptr` (khali jagah) par pahunch gaye, iska matlab hume naye node ke liye sahi jagah mil gayi hai. Hum wahan naya node bana kar return kar denge.
* **Left Call:** Agar naya data, current node ke data se **chhota** hai, toh hum left me dhoondenge (`insert(root->left, data)`).
* **Right Call:** Agar naya data, current node ke data se **bada** hai, toh hum right me dhoondenge (`insert(root->right, data)`).

---

## 3. C++ Implementation (Complete Code)

Neeche poora code hai jisme Node structure, Insertion function, aur check karne ke liye Inorder Traversal (jo BST me hamesha sorted output deta hai) likha hua hai:

```cpp
#include <iostream>
using namespace std;

// 1. BST ke Node ka Structure
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 2. Element Insert karne ka Function
Node* insertBST(Node* root, int val) {
    // Agar tree khali hai ya hum sahi khali jagah par pahunch gaye
    if (root == nullptr) {
        return new Node(val);
    }

    // Agar value chhoti hai, toh left subtree me insert karo
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    }
    // Agar value badi hai, toh right subtree me insert karo
    else if (val > root->data) {
        root->right = insertBST(root->right, val);
    }

    // Current node ka pointer wapas return karo
    return root;
}

// 3. Tree ko print karne ke liye Inorder Traversal
// BST ka inorder traversal hamesha SORTED output deta hai.
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);            // Pehle Left
    cout << root->data << " ";      // Phir Root
    inorder(root->right);           // Phir Right
}

int main() {
    Node* root = nullptr;

    // Elements insert kar rahe hain
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);
    insertBST(root, 60);
    insertBST(root, 80);

    cout << "BST ka Inorder Traversal (Sorted Order): " << endl;
    inorder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
BST ka Inorder Traversal (Sorted Order): 
20 30 40 50 60 70 80 

```

---

## 4. Time Complexity (Bohot Imp Hai Interview ke liye)

* **Average Case:** $O(\log N)$ — Agar tree balanced hai (dono taraf barabar phela hai), toh har step par hum aadha tree skip kar dete hain.
* **Worst Case:** $O(N)$ — Agar hum numbers sorted order me insert karein (jaise `10, 20, 30, 40`), toh tree ek line me ban jayega (Skewed Tree). Tab ye Linked List jaisa behave karega aur time lagega $O(N)$. Is worst case se bachne ke liye aage **AVL Tree** ya **Red-Black Tree** ka use hota hai.


Bhai, Preorder Traversal (`Root -> Left -> Right`) ko bina recursion ke karne ke liye hum **Stack** ka use karte hain, **Queue ka nahi**.

Aisa kyun? Kyunki pre-order me hume Root ke baad turant uske Left child par jaana hota hai, aur Right child ko baad ke liye sambhal kar rakhna hota hai. Stack (Last-In-First-Out) iska perfect kaam karta hai. Agar hum Queue (First-In-First-Out) use karenge, toh level-by-level (Breadth-First Search/BFS) print ho jayega, pre-order nahi.

Aao samajhte hain ki **Stack** se iterative Preorder traversal kaise hota hai, bilkul mast logic ke saath.

---

## 1. Stack Se Preorder Ka Logic

Preorder ka rule hai: **Pehle Root, phir Left, phir Right.**

Kyunki Stack me jo cheez **baad me** daali jaati hai, wo **pehle** nikalti hai (LIFO), isliye hum pehle **Right** child ko stack me daalenge aur phir **Left** child ko. Isse kya hoga? Agli cycle me Left child pehle bahar nikal kar print ho jayega, jo ki hume chahiye!

### Step-by-Step Algorithm:

1. Ek khali Stack banao aur usme `Root` node daal do.
2. Ek loop chalao jab tak Stack khali na ho jaye:
* Stack ke top node ko nikaalo (`pop`) aur usko **print** kar do.
* Agar us node ka **Right child** hai, toh use stack me push karo.
* Agar us node ka **Left child** hai, toh use stack me push karo. (Left ko baad me push kiya taaki wo agli baar pehle nikle).



---

## 2. Dry Run Karke Dekhte Hain

Maano hamara tree aisa hai:

```text
      1
    /   \
   2     3

```

* **Step 1:** Stack me `1` daala. `[Stack: 1]`
* **Step 2:** `1` ko pop kiya aur print kiya. **Output: 1**
* `1` ka right (`3`) push kiya, phir left (`2`) push kiya. `[Stack: 3, 2]`


* **Step 3:** Top par `2` hai. `2` ko pop kiya aur print kiya. **Output: 1 2**
* `2` ke koi bachhe nahi hain, toh kuch push nahi hua. `[Stack: 3]`


* **Step 4:** Top par `3` hai. `3` ko pop kiya aur print kiya. **Output: 1 2 3**
* `3` ke bhi koi bachhe nahi hain. `[Stack: Empty]`



Loop khatam! Final Preorder mil gaya: **1 2 3**

---

## 3. C++ Implementation (Complete Code)

Yahan `std::stack` ka use karke iterative preorder traversal ka code hai:

```cpp
#include <iostream>
#include <stack> // Stack library use karne ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Iterative Preorder Traversal using Stack
void iterativePreorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        // 1. Current node ko nikaalo aur print karo
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // 2. RIGHT child ko pehle push karo (taaki ye baad me nikle)
        if (curr->right != nullptr) {
            st.push(curr->right);
        }

        // 3. LEFT child ko baad me push karo (taaki ye pehle nikle)
        if (curr->left != nullptr) {
            st.push(curr->left);
        }
    }
}

int main() {
    // Tree banana
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
          1
        /   \
       2     3
      / \
     4   5
    */

    cout << "Iterative Preorder Traversal: ";
    iterativePreorder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Iterative Preorder Traversal: 1 2 4 5 3 

```

---

## 4. Queue kab use hoti hai tree me?

Agar tum soch rahe ho ki Queue kaha lagti hai, toh Queue use hoti hai **Level Order Traversal (BFS)** me. Usme tree ko floor-by-floor (pehle 1st level, phir 2nd level) print kiya jata hai.

Upar wale tree ke liye Level Order output hota: `1 2 3 4 5`.




Bhai, **Recursion** se Preorder Traversal karna toh sabse aasan hai! Isme tumhara kaam sirf 3 lines me ho jata hai, kyunki C++ ka internal call stack tumhare liye saara kaam khud handle karta hai.

Recursion ka simple rule hai: **Ek step tum karo, baaki ka kaam recursion khud sambhal lega.**

Aao iska logic aur code dono samajhte hain.

---

## 1. Recursion ka Core Logic

Preorder ka order kya hota hai? **Root $\rightarrow$ Left $\rightarrow$ Right**

Jab hum recursive function likhte hain, toh hum computer ko bas ye 3 orders batate hain:

1. **Root:** Sabse pehle jis node par tum khade ho (current node), uska data print kar do.
2. **Left:** Phir wahi same function us node ke left child ke liye call kar do (`preorder(root->left)`).
3. **Right:** Jab left ka poora kaam khatam ho jaye, toh wahi function right child ke liye call kar do (`preorder(root->right)`).

### Base Case (Rukna kab hai?):

Agar ghoomte-ghoomte hum `nullptr` (khali node) par pahunch gaye, toh wahan se seedha `return` ho jao, kyunki uske aage koi tree nahi hai.

---

## 2. Dry Run: Background me kya hota hai?

Maano hamara tree aisa hai:

```text
      1
    /   \
   2     3

```

1. Sabse pehle `preorder(1)` call hua.
* `1` ka data print hua. **[Output: 1]**
* Ab left call hui: `preorder(2)`.


2. `preorder(2)` par aaye.
* `2` ka data print hua. **[Output: 1 2]**
* Iski left call hui (`nullptr`) $\rightarrow$ wapas aaya.
* Iski right call hui (`nullptr`) $\rightarrow$ wapas aaya.
* Node `2` ka kaam khatam, hum wapas Node `1` par gaye.


3. Node `1` ki right call hui: `preorder(3)`.
* `3` ka data print hua. **[Output: 1 2 3]**
* Iski left aur right dono `nullptr` hain, toh ye bhi khatam.



Poora tree traverse ho gaya!

---

## 3. C++ Code (Recursion)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Preorder Traversal Function
void recursivePreorder(Node* root) {
    // Base Case: Agar node khali hai toh ruk jao
    if (root == nullptr) {
        return;
    }

    // 1. ROOT: Current node ka data print karo
    cout << root->data << " ";

    // 2. LEFT: Left subtree ko traverse karo
    recursivePreorder(root->left);

    // 3. RIGHT: Right subtree ko traverse karo
    recursivePreorder(root->right);
}

int main() {
    // Tree structure banaya
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
          1
        /   \
       2     3
      / \
     4   5
    */

    cout << "Recursive Preorder Traversal: ";
    recursivePreorder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive Preorder Traversal: 1 2 4 5 3 

```

---

## 4. Inorder aur Postorder banana hai toh?

Mazaaki baat pata hai kya hai? Agar tumne ye seekh liya, toh baki dono traversals free me seekh liye! Bas lines ka order badalna hota hai:

* **Inorder (`Left -> Root -> Right`):**
```cpp
recursiveInorder(root->left);  // Left
cout << root->data << " ";     // Root
recursiveInorder(root->right); // Right

```


* **Postorder (`Left -> Right -> Root`):**
```cpp
recursivePostorder(root->left);  // Left
recursivePostorder(root->right); // Right
cout << root->data << " ";      // Root

```



### Complexity:

* **Time Complexity:** $O(N)$ kyunki hum har node par ek hi baar ja rahe hain.
* **Space Complexity:** $O(H)$ jahan $H$ tree ki height hai (internal call stack ka space).



Bhai, **Inorder Traversal** tree ka sabse mahatvapurna (important) traversal hai, khaaskar jab tum **Binary Search Tree (BST)** padh rahe ho.

Iska golden rule hai: **Left $\rightarrow$ Root $\rightarrow$ Right**

Chalo isko poori detail me, logic, dry run aur code ke saath samajhte hain.

---

## 1. Inorder Traversal ka Logic kya hai?

Inorder ka seedha sa matlab hai ki jab tum kisi node par khade ho, toh tum pehle uske data ko print **nahi** kar sakte. Tumhe pehle uske left side ka poora hissa niptana hoga, phir us node par wapas aakar use print karna hoga, aur uske baad uske right side par jaana hoga.

### Iska Magic Rule (For BST):

Agar tumhare paas ek **Binary Search Tree** hai, aur tum uska Inorder Traversal nikalte ho, toh output hamesha **Sorted Order (Ascending order)** me aayega. Agar tumhara output sorted nahi aa raha, matlab tumne BST galat banaya hai ya traversal galat kiya hai.

---

## 2. Diagram aur Dry Run se samjho

Maano hamara tree aisa hai:

```text
          1
        /   \
       2     3
      / \
     4   5

```

Hum `Inorder(1)` se shuru karenge. Rule yaad rakhna: **Left $\rightarrow$ Root $\rightarrow$ Right**

1. **Node 1 par aaye:** Rule kehta hai pehle Left jao. Toh hum **Node 2** par chale gaye.
2. **Node 2 par aaye:** Iska bhi pehle Left jao. Toh hum **Node 4** par chale gaye.
3. **Node 4 par aaye:** Iska left `nullptr` (khali) hai. Left khatam!
* Ab rule ka dusra part: **Root** (yaani khud Node 4) ko print karo.
* **Output: 4**
* Ab iska right jao $\rightarrow$ right bhi `nullptr` hai. Node 4 ka kaam poora khatam. Hum wapas uppar **Node 2** par gaye.


4. **Node 2 par wapas aaye:** Iska left (Node 4) ho chuka hai. Ab iski khud ki baari (**Root**). Isko print karo.
* **Output: 4 2**
* Ab iske **Right** jao $\rightarrow$ hum **Node 5** par chale gaye.


5. **Node 5 par aaye:** Iska left khali hai $\rightarrow$ khud ko print karo (**Output: 4 2 5**) $\rightarrow$ right khali hai. Node 2 ka right bhi nipat gaya. Ab hum wapas sabse uppar **Node 1** par gaye.
6. **Node 1 par wapas aaye:** Iska poora left side ho chuka hai. Ab iski khud ki baari (**Root**). Isko print karo.
* **Output: 4 2 5 1**
* Ab iske **Right** jao $\rightarrow$ hum **Node 3** par chale gaye.


7. **Node 3 par aaye:** Iska left khali $\rightarrow$ khud ko print karo (**Output: 4 2 5 1 3**) $\rightarrow$ right khali.

Poora tree khatam! Final Inorder output mila: **4 2 5 1 3**

---

## 3. C++ Code (Recursion Se)

Recursion se iska code likhna bacha-bacha jaanta hai, bas 3 lines ka khel hai:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Inorder Traversal Function
void recursiveInorder(Node* root) {
    // Base Case: Agar node khali hai toh wapas mud jao
    if (root == nullptr) {
        return;
    }

    // 1. LEFT: Pehle left subtree par jao
    recursiveInorder(root->left);

    // 2. ROOT: Phir current node ka data print karo
    cout << root->data << " ";

    // 3. RIGHT: Phir right subtree par jao
    recursiveInorder(root->right);
}

int main() {
    // Same upar wala tree banate hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Recursive Inorder Traversal: ";
    recursiveInorder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive Inorder Traversal: 4 2 5 1 3 

```

---

## 4. Iterative Inorder (Using Stack) — Interview Special

Interviews me interviewer bolega, *"Beta, recursion toh sab kar lete hain, ab bina recursion ke **Stack** use karke iterative code likho."* Iterative logic thoda dhyan se samajhna: Hum left me tab tak jaate rehte hain jab tak `nullptr` na mil jaye, aur raste ke nodes ko stack me push karte jaate hain.

```cpp
#include <stack>

void iterativeInorder(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        // 1. Jab tak left child mil raha hai, stack me daalo aur left jate jao
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // 2. Ab curr nullptr ho chuka hai, toh stack se top nikaalo
        curr = st.top();
        st.pop();
        
        cout << curr->data << " "; // Print karo (Root ka kaam)

        // 3. Ab right subtree ki taraf mud jao
        curr = curr->right;
    }
}

```

### Complexity:

* **Time Complexity:** $O(N)$ kyunki har node par maximum 2 baar visit hota hai.
* **Space Complexity:** $O(H)$ jahan $H$ tree ki height hai (Stack ka size).


Bhai, Preorder aur Inorder ke baad ab baari aati hai teesre sabse important depth-first traversal ki, jise hum **Postorder Traversal** kehte hain.

Iska golden rule hai: **Left $\rightarrow$ Right $\rightarrow$ Root**

Chalo isko bhi poori detail me, logic, dry run aur dono (recursive aur iterative) code ke saath samajhte hain.

---

## 1. Postorder Traversal ka Logic kya hai?

Postorder ka seedha sa matlab hai: **"Sabse baad me Root"** (Post matlab baad me).

Isme jab tum kisi node par khade ho, toh tum pehle uske data ko chhu bhi nahi sakte jab tak tum uske **Left** ke saare nodes aur **Right** ke saare nodes ko poori tarah ghoom kar print na kar do. Jab kisi node ke left aur right dono subtrees ka kaam poora khatam ho jata hai, tab sabse end me us node (Root) ka data print hota hai.

### Real-world use case:

* **Directory / Folder Delete karna:** Agar tum apne computer me koi folder delete karte ho jisme bohot saare sub-folders aur files hain, toh operating system pehle andar ki files delete karta hai (Left/Right), aur sabse end me main folder ko delete karta hai (Root). Agar pehle main folder uda dega toh andar ka data access kaise hoga? Isiliye **Tree Deletion** me Postorder use hota hai.
* **Expression Tree Evaluation:** Mathematical equations ko solve karne ke liye bhi iska use hota hai (pehle operands ko solve karo, phir operator lagao).

---

## 2. Diagram aur Dry Run se samjho

Maano hamara tree wahi same hai:

```text
          1
        /   \
       2     3
      / \
     4   5

```

Hum `Postorder(1)` se shuru karenge. Rule yaad rakhna: **Left $\rightarrow$ Right $\rightarrow$ Root**

1. **Node 1 par aaye:** Pehle Left jao $\rightarrow$ **Node 2** par gaye.
2. **Node 2 par aaye:** Pehle Left jao $\rightarrow$ **Node 4** par gaye.
3. **Node 4 par aaye:** Iska left `nullptr` hai, right bhi `nullptr` hai. Dono side ho gayi? Haan! Toh ab iski apni baari (**Root**). Isko print karo.
* **Output: 4** (Hum wapas Node 2 par chale gaye).


4. **Node 2 par wapas aaye:** Iska left (Node 4) ho chuka hai. Ab rule ke mutabik iske **Right** jao $\rightarrow$ **Node 5** par gaye.
5. **Node 5 par aaye:** Iska left aur right dono khali (`nullptr`) hain. Dono side ho gayi? Haan! Toh ab isko print karo.
* **Output: 4 5** (Hum wapas Node 2 par chale gaye).


6. **Node 2 par firse aaye:** Iska left bhi ho gaya aur right bhi ho gaya. Ab iski apni baari (**Root**). Isko print karo.
* **Output: 4 5 2** (Hum wapas main Root, yaani Node 1 par chale gaye).


7. **Node 1 par wapas aaye:** Iska left side poora nipat chuka hai. Ab rule ke mutabik iske **Right** jao $\rightarrow$ **Node 3** par gaye.
8. **Node 3 par aaye:** Iska left-right dono khali hain, toh isko print karo.
* **Output: 4 5 2 3** (Hum wapas Node 1 par gaye).


9. **Node 1 par firse aaye:** Iska left bhi ho gaya aur right bhi ho gaya. Ab sabse aakhiri me iski apni baari (**Root**). Isko print karo.
* **Output: 4 5 2 3 1**



Poora tree khatam! Final Postorder output mila: **4 5 2 3 1** (Notice kiya? Sabse main root `1` sabse end me print hua).

---

## 3. C++ Code (Recursion Se)

Recursion se iska code likhna halwa hai, bas lines ka hera-pheri hai:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Postorder Traversal Function
void recursivePostorder(Node* root) {
    // Base Case: Agar node khali hai toh wapas laut jao
    if (root == nullptr) {
        return;
    }

    // 1. LEFT: Pehle left subtree par jao
    recursivePostorder(root->left);

    // 2. RIGHT: Phir right subtree par jao
    recursivePostorder(root->right);

    // 3. ROOT: Sabse end me current node ka data print karo
    cout << root->data << " ";
}

int main() {
    // Same upar wala tree banate hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Recursive Postorder Traversal: ";
    recursivePostorder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive Postorder Traversal: 4 5 2 3 1 

```

---

## 4. Iterative Postorder (Using 2 Stacks) — Interview Special

Interviews me iterative postorder thoda tricky maana jata hai kyunki root ko tab tak hold karna padta hai jab tak left-right dono na ho jayein. Iska sabse simple aur dimaag na kharab karne wala tareeka hai **2 Stacks** ka use karna.

**Logic:** Hum Preorder ka thoda ulta chalte hain. Preorder hota hai `Root -> Left -> Right`. Agar hum ek stack se `Root -> Right -> Left` nikalein aur use dusre stack me store karte jayein, toh dusra stack jab print hoga toh wo apne aap `Left -> Right -> Root` (Postorder) ban jayega!

```cpp
#include <stack>

void iterativePostorder(Node* root) {
    if (root == nullptr) return;

    stack<Node*> st1; // Pehla stack processing ke liye
    stack<Node*> st2; // Dusra stack final output reverse karne ke liye

    st1.push(root);

    while (!st1.empty()) {
        Node* curr = st1.top();
        st1.pop();
        
        st2.push(curr); // Isko seedha dusre stack me daal do

        // Pehle left push karo, phir right push karo stack 1 me
        // Taaki stack 1 se pehle RIGHT nikle
        if (curr->left != nullptr) {
            st1.push(curr->left);
        }
        if (curr->right != nullptr) {
            st1.push(curr->right);
        }
    }

    // Stack 2 me data bilkul perfect Postorder me store ho chuka hai
    while (!st2.empty()) {
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

```

### Complexity:

* **Time Complexity:** $O(N)$ kyunki hum har node ko barabar visit kar rahe hain.
* **Space Complexity:** $O(N)$ kyunki hum nodes ko store karne ke liye do stacks ka use kar rahe hain.




Bhai, tumne Preorder, Inorder, aur Postorder seekh liya jo tree me gahrai me jaakar (`Depth-First Search`) kaam karte hain.

Ab baari hai **Level Order Traversal** ki, jise hum **Breadth-First Search (BFS)** bhi kehte hain. Ye un sabse bilkul alag aur bohot mazedaar hai, kyunki isme hum tree ko upar se neeche **level-by-level (floor-by-floor)** scan karte hain.

Aao iska poora logic, Queue ka role, dry run aur code bilkul detail me samajhte hain.

---

## 1. Level Order Traversal ka Logic kya hai?

Socho ek multi-story building hai. Level Order ka matlab hai ki tum pehle Ground Floor ke saare kamre dekhoge, phir 1st Floor ke saare kamre, phir 2nd Floor ke, aur aage aise hi.

Tree me hum level ko $0$ se shuru karte hain:

* **Level 0:** Sirf Root node.
* **Level 1:** Root ke bachhe (Left aur Right).
* **Level 2:** Un bachhon ke bhi bachhe (Grandchildren).

### Isme Queue (`FIFO`) Kyun Use Hoti Hai?

Pehle tumne dekha tha ki preorder/inorder me hum Stack use kar rahe the, kyunki hume gahrai me jaana tha. Lekin yahan hume line se chalna hai—jo node pehle dikhega, uska kaam pehle hoga, aur uske bachhe line me sabse peeche lagenge. **First-In-First-Out (FIFO)** ka kaam sirf aur sirf **Queue** kar sakti hai.

---

## 2. Diagram aur Dry Run se samjho

Maano hamara tree aisa hai:

```text
          1         <-- Level 0
        /   \
       2     3      <-- Level 1
      / \   / \
     4   5 6   7    <-- Level 2

```

Hum ek khali **Queue** lenge aur usme sabse pehle **Root (1)** ko daal denge.

* **Step 1:** Queue me `1` hai. `[Queue: 1]`
* `1` ko pop kiya aur print kiya. **Output: 1**
* `1` ke bachhon (`2` aur `3`) ko line me laga diya. `[Queue: 2, 3]`


* **Step 2:** Ab line me sabse aage `2` hai. `2` ko pop kiya aur print kiya. **Output: 1 2**
* `2` ke bachhon (`4` aur `5`) ko peeche line me laga diya. `[Queue: 3, 4, 5]`


* **Step 3:** Ab line me aage `3` hai. `3` ko pop kiya aur print kiya. **Output: 1 2 3**
* `3` ke bachhon (`6` aur `7`) ko line me laga diya. `[Queue: 4, 5, 6, 7]`


* **Step 4:** Ab line me `4` hai. Isko pop aur print kiya. **Output: 1 2 3 4**
* `4` ka koi bachha nahi hai, toh koi push nahi hua. `[Queue: 5, 6, 7]`


* **Step 5, 6, 7:** Isi tarah `5`, `6`, aur `7` ek-ek karke pop honge aur print ho jayenge kyunki kisi ke aage bachhe nahi hain.

Queue khali ho gayi! Final Output mila: **1 2 3 4 5 6 7**

---

## 3. C++ Implementation (Complete Code)

C++ me `std::queue` ka use karke iska code bohot clean banta hai. Isme recursion ki zaroorat nahi hoti, ye iterative hi sabse best mana jata hai:

```cpp
#include <iostream>
#include <queue> // Queue library use karne ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Level Order Traversal Function
void levelOrder(Node* root) {
    // Agar tree khali hai toh kuch mat karo
    if (root == nullptr) return;

    // Ek queue banao jo Node ke pointers ko store karegi
    queue<Node*> q;
    
    // Sabse pehle root ko queue me daalo
    q.push(root);

    while (!q.empty()) {
        // 1. Line me jo sabse aage hai use nikaalo
        Node* curr = q.front();
        q.pop();

        // 2. Uska data print karo
        cout << curr->data << " ";

        // 3. Agar uska left child hai, toh use line (queue) me lagao
        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        // 4. Agar uska right child hai, toh use bhi line me lagao
        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}

int main() {
    // Tree structure banate hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order Traversal (BFS): " << endl;
    levelOrder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Level Order Traversal (BFS): 
1 2 3 4 5 6 7 

```

---

## 4. Interviewer ka Favourite Twist: "Line by Line print karo"

Interviews me wo tumse seedha output nahi maangenge. Wo bolenge, *"Mujhe har level alag line me chahiye"*, jaise:

```text
1 
2 3 
4 5 6 7 

```

Iske liye hume loop ke andar ek aur chhota loop lagana padta hai jo current queue ke size (yaani us level par kitne nodes hain) ko pehle hi ginte hai.

### Modified Loop Logic:

```cpp
void levelOrderLineByLine(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Is level par kitne nodes hain, pata lagao

        // Ye loop sirf ek poore level ko ek baar me khatam karega
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        cout << endl; // Ek level khatam hone ke baad nayi line
    }
}

```

### Complexity:

* **Time Complexity:** $O(N)$ kyunki hum har ek node ko barabar ek baar queue me daal rahe hain aur ek baar nikal rahe hain.
* **Space Complexity:** $O(N)$ worst case me queue ka size tree ke sabse nichle level ke barabar ho jata hai (jise tree ki width kehte hain).




Bhai, Level Order Traversal ko **Recursion** se karna thoda alag aur tricky hota hai. Jab hum recursion ka use karte hain, toh hum direct level-by-level nahi kood sakte kyunki recursion hamesha pehle gahrai (depth) me jaata hai.

Isliye recursion se karne ke liye hum ek doosra tareeka apnaate hain: **Hum tree ki height nikalte hain aur har ek level ke liye alag se recursive call maarte hain.**

Aao iska logic aur code dono samajhte hain.

---

## 1. Recursion ka Logic (Two-Step Approach)

Isme hum do kaam karte hain:

1. **Step 1:** Tree ki total **Height** nikalte hain (taaki pata chale ki total kitne floors/levels hain).
2. **Step 2:** Ek loop chalate hain `1` se lekar `Height` tak, aur har ek level ke saare nodes ko print karne ke liye ek recursive function call karte hain.

### Kisi specific level ko print karne ka logic:

* Agar hum `level == 1` par hain, toh wahi hamara target node hai, use print kar do.
* Agar hum `level > 1` par hain, toh hum dono side recursive call bhejenge aur level ko `-1` kam kar denge:
* `printCurrentLevel(root->left, level - 1)`
* `printCurrentLevel(root->right, level - 1)`



---

## 2. Dry Run Karke Dekho

Maano tree aisa hai:

```text
      1
    /   \
   2     3

```

Is tree ki height hai `2`. Hamara loop chalega `i = 1` se `2` tak:

* **i = 1 (Level 1 print karo):** `printCurrentLevel(root, 1)` call hua. Kyunki level 1 hai, toh root ka data `1` print ho gaya. **[Output: 1]**
* **i = 2 (Level 2 print karo):** `printCurrentLevel(root, 2)` call hua.
* Kyunki level > 1 hai, toh ye left aur right dono ko call karega level `2-1 = 1` ke saath.
* `printCurrentLevel(node 2, 1)` $\rightarrow$ level 1 hai, toh `2` print hua.
* `printCurrentLevel(node 3, 1)` $\rightarrow$ level 1 hai, toh `3` print hua. **[Output: 1 2 3]**



---

## 3. C++ Implementation (Complete Code)

```cpp
#include <iostream>
#include <algorithm> // max() function ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// 1. Tree ki Height nikalne ka function
int getHeight(Node* node) {
    if (node == nullptr) return 0;
    
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    
    return max(leftHeight, rightHeight) + 1;
}

// 2. Kisi specific level ke saare nodes ko print karne ka function
void printCurrentLevel(Node* root, int level) {
    if (root == nullptr) return;
    
    // Base Case: Agar hum target level par pahunch gaye
    if (level == 1) {
        cout << root->data << " ";
        return;
    }
    
    // Agar level 1 se bada hai, toh neeche jao aur level kam karo
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
}

// 3. Main Level Order Function jo loop chalayega
void recursiveLevelOrder(Node* root) {
    int h = getHeight(root);
    
    // Har ek floor/level ke liye alag se recursive call
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
          1
        /   \
       2     3
      / \
     4   5
    */

    cout << "Recursive Level Order Traversal: " << endl;
    recursiveLevelOrder(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive Level Order Traversal: 
1 2 3 4 5 

```

---

## 4. Complexity aur Ek Bohot Zaroori Baat!

Bhai, interviews me kabhi bhi Level Order Traversal ko **recursion se karne ki salah nahi di jaati**. Kyun? Chalo iski complexity dekhte hain:

* **Worst Case Time Complexity:** $O(N^2)$ (Agar tree ek dam seedha lambaa ho - Skewed Tree). Kyunki har naye level ke liye hum dobara upar se poora tree scan karte hue niche aate hain.
* **Normal Queue (Iterative) ki Complexity:** $O(N)$ hoti hai.

Toh agar interviewer specifically bole ki **"Muje recursion se hi dekhna hai"**, tabhi ye tarika use karna, varna hamesha **Queue wala iterative tarika** hi best aur standard maana jata hai!



Bhai, **Size of a Binary Tree** ka matlab bohot hi simple hota hai: **"Is poore tree me total kitne Nodes hain?"** Yaani agar tumse koi pooche ki tree ka size kya hai, toh tumhe bas tree ke saare elements (nodes) ko ginn (count) kar ke total number batana hai.

Aao iska logic, recursion kaise kaam karta hai, aur code poori detail me samajhte hain.

---

## 1. Logic: Kaise Ginenge? (The Real-world Example)

Socho tum ek company ke CEO ho (Root Node). Tumhe pata karna hai ki tumhari company me total kitne employees hain. Tum kya karoge?

1. Tum apne **Left Manager** se poochoge: *"Tere andar kitne log hain?"*
2. Tum apne **Right Manager** se poochoge: *"Tere andar kitne log hain?"*
3. Jab dono apna-apna total batayenge, toh tum un dono ko jodoge aur **+1 (khud ko)** add kar ke poori company ka size bata doge.

Yahi same logic hum Tree par lagate hain:


$$\text{Total Size} = \text{Size of Left Subtree} + \text{Size of Right Subtree} + 1 \text{ (Current Node)}$$

---

## 2. Recursion Kaise Kaam Karta Hai? (Dry Run)

Recursion se iska logic sirf ek line ka hota hai. Chalo is tree ka dry run karke dekhte hain:

```text
          1
        /   \
       2     3
      / \
     4   5

```

Humne `getSize(1)` call kiya:

1. **Node 1** ne bola: Main apna size tabhi bata paunga jab mujhe `Left (2)` aur `Right (3)` ka size pata chalega.
2. **Node 2** par aaye (Left call): Isne apne left `4` aur right `5` ko call kiya.
3. **Node 4** par aaye: Iska left `nullptr` hai (size = 0) aur right `nullptr` hai (size = 0).
* Toh Node 4 ka size hua: $0 + 0 + 1 = \mathbf{1}$. Isne `1` wapas bheja Node 2 ko.


4. **Node 5** par aaye: Iska bhi left-right khali hai, toh size hua: $0 + 0 + 1 = \mathbf{1}$. Isne bhi `1` wapas bheja Node 2 ko.
5. Ab **Node 2** ke paas left se `1` aaya aur right se `1` aaya.
* Node 2 ka total size: $1 (\text{left}) + 1 (\text{right}) + 1 (\text{khud}) = \mathbf{3}$. Isne `3` wapas bheja Node 1 ko.


6. Ab **Node 3** par aaye (Node 1 ki right call): Iska left-right khali hai, toh iska size hua: $0 + 0 + 1 = \mathbf{1}$. Isne `1` wapas bheja Node 1 ko.
7. Finally, **Node 1** ke paas left se `3` aaya aur right se `1` aaya.
* Node 1 ka total size: $3 (\text{left}) + 1 (\text{right}) + 1 (\text{khud}) = \mathbf{5}$.



Mila na perfect answer? Total nodes 5 hi hain!

---

## 3. C++ Implementation (Complete Code)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate the size of Binary Tree
int getSize(Node* root) {
    // Base Case: Agar tree khali hai, toh size 0 hai
    if (root == nullptr) {
        return 0;
    }

    // Recursive Call: Left ka size + Right ka size + 1 (khud current node)
    return getSize(root->left) + getSize(root->right) + 1;
}

int main() {
    // Tree banana
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
          1
        /   \
       2     3
      / \
     4   5
    */

    cout << "Binary Tree ka Total Size (Nodes count): " << getSize(root) << endl;

    return 0;
}

```

### Output:

```text
Binary Tree ka Total Size (Nodes count): 5

```

---

## 4. Iterative Way (Using Queue/Level Order)

Agar interviewer tumse bole ki recursion use nahi karna hai, toh tumne jo abhi **Level Order Traversal (BFS)** seekha tha, tum uska use kar sakte ho.

**Logic:** Ek `count` variable ko `0` par set karo. Queue me nodes ko daalte jao, aur jab bhi kisi node ko queue se pop (nikaalo), toh `count++` kar do. Jab queue khali ho jayegi, `count` me total size mil jayega.

```cpp
#include <queue>

int getSizeIterative(Node* root) {
    if (root == nullptr) return 0;

    int count = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        count++; // Node mila, toh ginti badhao

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    return count;
}

```

---

## 5. Complexity

* **Time Complexity:** Both recursive aur iterative tarike me $O(N)$ lagti hai, kyunki hume tree ke har ek node par ek baar jaakar use ginna hi padega.
* **Space Complexity:** * Recursive me: $O(H)$ jahan $H$ tree ki height hai (call stack space).
* Iterative me: $O(W)$ jahan $W$ tree ki maximum width hai (queue space).



Bhai, **Sum of a Binary Tree** ka matlab hota hai: **"Is poore tree me jitne bhi nodes hain, un sabki values (data) ko aapas me jod kar total sum batana."**

Ye bilkul *Size of Binary Tree* jaisa hi hai. Bas farq itna hai ki size me hum nodes ko ginte hain (`+1` karte hain), aur sum me hum node ke andar jo value baithi hai use jodte hain (`+ root->data`).

Aao iska logic, recursion ka khel, aur code poori detail me samajhte hain.

---

## 1. Core Logic (Wahi CEO aur Manager wala Example)

Socho tum ek company ke head ho (Root Node). Tumhe pata karna hai ki poori company me sabki salary mila kar total kitna kharcha ho raha hai. Tum kya karoge?

1. Tum apne **Left Manager** se poochoge: *"Tere department ki total salary kitni hai?"*
2. Tum apne **Right Manager** se poochoge: *"Tere department ki total salary kitni hai?"*
3. Jab dono apna total batayenge, toh tum un dono ki values ko jodoge aur usme **apni khud ki salary** add kar ke total sum bata doge.

Yahi simple rule hum Tree par lagate hain:


$$\text{Total Sum} = \text{Sum of Left Subtree} + \text{Sum of Right Subtree} + \text{Current Node's Data}$$

---

## 2. Diagram aur Dry Run se samjho

Maano hamara tree aisa hai:

```text
          1
        /   \
       2     3
      / \
     4   5

```

Humne `getSum(1)` call kiya:

1. **Node 1** ruka hua hai jab tak use Left aur Right ka sum nahi mil jata.
2. **Node 2** par aaye. Isne `4` aur `5` ko call kiya.
3. **Node 4** par aaye: Iska left `nullptr` (0) hai aur right `nullptr` (0) hai.
* Toh Node 4 ka sum hua: $0 + 0 + 4 = \mathbf{4}$. Isne `4` wapas bheja Node 2 ko.


4. **Node 5** par aaye: Iska bhi left-right khali hai, toh sum hua: $0 + 0 + 5 = \mathbf{5}$. Isne `5` wapas bheja Node 2 ko.
5. Ab **Node 2** ke paas left se `4` aaya aur right se `5` aaya.
* Node 2 ka total sum: $4 (\text{left}) + 5 (\text{right}) + 2 (\text{khud ka data}) = \mathbf{11}$. Isne `11` wapas bheja Node 1 ko.


6. Ab **Node 3** par aaye (Node 1 ki right call): Iska left-right khali hai, toh iska sum hua: $0 + 0 + 3 = \mathbf{3}$. Isne `3` wapas bheja Node 1 ko.
7. Finally, **Node 1** ke paas left se `11` aaya aur right se `3` aaya.
* Node 1 ka total sum: $11 (\text{left}) + 3 (\text{right}) + 1 (\text{khud ka data}) = \mathbf{15}$.



Chaho toh manually jod kar dekh lo: $1 + 2 + 3 + 4 + 5 = 15$. Bilkul perfect!

---

## 3. C++ Implementation (Recursion Se)

Recursion se iska code sirf ek line ka hota hai. Base case wahi hoga ki agar node khali (`nullptr`) hai, toh sum `0` return karo.

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate the sum of all nodes in a Binary Tree
int getSum(Node* root) {
    // Base Case: Agar tree khali hai toh sum 0 hai
    if (root == nullptr) {
        return 0;
    }

    // Recursive Call: Left ka sum + Right ka sum + khud current node ka data
    return getSum(root->left) + getSum(root->right) + root->data;
}

int main() {
    // Tree banate hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
          1
        /   \
       2     3
      / \
     4   5
    */

    cout << "Binary Tree ke saare Nodes ka Sum: " << getSum(root) << endl;

    return 0;
}

```

### Output:

```text
Binary Tree ke saare Nodes ka Sum: 15

```

---

## 4. Iterative Way (Using Queue / Level Order)

Agar bina recursion ke karna ho, toh tum wahi apna purana **Queue (Level Order Traversal)** wala tarika use kar sakte ho.

**Logic:** Ek `totalSum = 0` variable banao. Queue me nodes ko daalte jao, aur jab bhi kisi node ko queue se nikaalo (pop karo), toh uske data ko `totalSum` me jodte jao (`totalSum += curr->data`).

```cpp
#include <queue>

int getSumIterative(Node* root) {
    if (root == nullptr) return 0;

    int totalSum = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        totalSum += curr->data; // Value ko total me jodo

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    return totalSum;
}

```

---

## 5. Complexity

* **Time Complexity:** $O(N)$ dono tariko me, kyunki sum nikalne ke liye tree ke har ek node ki value ko kam se kam ek baar dekhna hi padega.
* **Space Complexity:** * **Recursive:** $O(H)$ jahan $H$ tree ki height hai (call stack ka space).
* **Iterative:** $O(W)$ jahan $W$ tree ki maximum width hai (queue ka space).




Bhai, **Count Leaves in a Binary Tree** ka matlab hota hai ki hume tree ke saare **Leaf Nodes** ko ginn kar total number batana hai.

**Leaf Node kya hota hai?** Wo badkismat node jiske aage koi bacche nahi hote, yaani jiska **Left Child bhi NULL ho aur Right Child bhi NULL ho**.

Jaise is tree me dekho:

```text
          1
        /   \
       2     3
      / \   
     4   5  

```

Yahan `4`, `5`, aur `3` leaf nodes hain kyunki inke niche koi node nahi hai. Toh is tree ka answer **3** aana chahiye.

Aao iska mast logic aur code dono detail me samajhte hain.

---

## 1. Core Logic (Recursion Kaise Sochein?)

Bhai, recursion se jab bhi tree ka swal banana ho, toh pehle Base Cases socha karo. Isme main 3 conditions banti hain:

1. **Agar tree hi khali hai (`root == nullptr`):** Toh koi leaf node ho hi nahi sakta, seedha `0` return kar do.
2. **Agar current node hi Leaf Node hai:** Hum check kaise karenge? `if (root->left == nullptr && root->right == nullptr)`. Agar ye sahi hai, iska matlab hume 1 leaf node mil gaya, yahan se `1` return kar do.
3. **Agar current node leaf nahi hai (jaise node 1 ya 2):** Toh tum apne Left subtree se poochogi ki wahan kitne leaves hain, aur Right subtree se poochoge ki wahan kitne leaves hain. Phir dono ke answers ko jod kar aage bhej doge:

$$\text{Total Leaves} = \text{Leaves in Left Subtree} + \text{Leaves in Right Subtree}$$



---

## 2. Diagram aur Dry Run

Upar wale tree ke liye dekhte hain ki recursion kaise chalta hai:

* Humne `countLeaves(1)` call kiya. Node 1 leaf nahi hai, toh isne bola: `countLeaves(2) + countLeaves(3)`.
* **Left Call `countLeaves(2)` par gaye:** Node 2 bhi leaf nahi hai, toh isne bola: `countLeaves(4) + countLeaves(5)`.
* **Node 4 par gaye:** Iska left aur right dono NULL hain. Rule ke mutabik ye leaf node hai, toh isne return kiya `1`.
* **Node 5 par gaye:** Iska bhi left-right NULL hai, isne bhi return kiya `1`.
* Ab Node 2 ke paas dono ka sum aaya: $1 + 1 = \mathbf{2}$. Node 2 ne `2` wapas bhej diya Node 1 ko.
* **Right Call `countLeaves(3)` par gaye (Node 1 se):** Node 3 ka left aur right dono NULL hain, toh ye khud ek leaf hai. Isne return kiya `1`.
* **Final Step:** Node 1 ke paas left se `2` aaya aur right se `1` aaya. Dono ko joda: $2 + 1 = \mathbf{3}$.

---

## 3. C++ Implementation (Recursion Se)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to count leaf nodes
int countLeaves(Node* root) {
    // Base Case 1: Agar node khali hai
    if (root == nullptr) {
        return 0;
    }

    // Base Case 2: Agar node khud ek LEAF node hai
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }

    // Recursive Call: Left ke leaves + Right ke leaves
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    // Tree setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Tree me total Leaf Nodes hain: " << countLeaves(root) << endl;

    return 0;
}

```

### Output:

```text
Tree me total Leaf Nodes hain: 3

```

---

## 4. Iterative Way (Using Queue / BFS)

Agar interviewer bole ki recursion ke bina karo, toh tum apna trusty **Queue (Level Order Traversal)** use kar sakte ho.

**Logic:** Queue me nodes ko daalte jao. Jab bhi kisi node ko pop karo, toh check kar lo ki kya uske left aur right dono NULL hain? Agar haan, toh apne `leafCount` variable ko `+1` kar do. Agar NULL nahi hain, toh unhe normal queue me push kar do.

```cpp
#include <queue>

int countLeavesIterative(Node* root) {
    if (root == nullptr) return 0;

    int leafCount = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Agar leaf node mil gaya, toh count badhao
        if (curr->left == nullptr && curr->right == nullptr) {
            leafCount++;
        }

        // Varna baaki nodes ko queue me daalo
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    return leafCount;
}

```

---

## 5. Complexity

* **Time Complexity:** $O(N)$ dono tarikon me, kyunki check karne ke liye hume tree ke har ek node par jaana hi padega ki wo leaf hai ya nahi.
* **Space Complexity:** * **Recursive:** $O(H)$ jahan $H$ tree ki height hai (call stack space).
* **Iterative:** $O(W)$ jahan $W$ tree ki max width hai (queue space).




Bhai, **Count Non-Leaf Nodes in a Binary Tree** ka matlab hota hai ki hume tree ke un saare nodes ko ginn kar batana hai jo **leaf nodes nahi hain**.

**Non-Leaf Node (ya Internal Node) kya hota hai?** Wo node jiska **kam se kam ek child (baccha) zaroor ho**—chahe sirf left child ho, sirf right child ho, ya dono ho.

Jaise is tree me dekho:

```text
          1
        /   \
       2     3
      / \   
     4   5  

```

Yahan `4` aur `5` leaf nodes hain (inke niche koi nahi hai). Lekin `1` aur `2` non-leaf nodes hain kyunki inke paas bachhe hain. `3` ka koi child nahi hai toh wo bhi leaf hai. Isliye is tree ka answer **2** aana chahiye (`1` aur `2`).

Aao iska logic aur code dono bilkul crystal clear karte hain.

---

## 1. Core Logic (Recursion Kaise Kaam Karega?)

Recursion se sochne ke liye hume phir se 3 conditions par dhyan dena hai:

1. **Agar tree hi khali hai (`root == nullptr`):** Toh koi node hi nahi hai, seedha `0` return kar do.
2. **Agar current node Leaf Node hai:** `if (root->left == nullptr && root->right == nullptr)`. Humse sawal me *non-leaf* pucha hai, toh leaf node milne par hum use nahi ginenge aur `0` return kar denge.
3. **Agar current node Non-Leaf hai:** Iska matlab iske paas bachhe hain. Toh hum is node ko ginti me shamil karenge (`1`), aur iske left aur right subtrees se bhi non-leaf nodes ka count mangwayenge:

$$\text{Total Non-Leaves} = 1 + \text{Non-Leaves in Left} + \text{Non-Leaves in Right}$$



---

## 2. Diagram aur Dry Run

Upar wale tree ke liye recursion ka chakravyuh dekhte hain:

* Humne `countNonLeaves(1)` call kiya. Node 1 leaf nahi hai, toh iska formula bana: `1 + countNonLeaves(2) + countNonLeaves(3)`.
* **Left Call `countNonLeaves(2)` par gaye:** Node 2 bhi leaf nahi hai, toh isne bola: `1 + countNonLeaves(4) + countNonLeaves(5)`.
* **Node 4 par gaye:** Iska left-right dono NULL hain. Ye leaf node hai, toh condition 2 ke mutabik isne return kiya `0`.
* **Node 5 par gaye:** Ye bhi leaf node hai, isne bhi return kiya `0`.
* Ab Node 2 ka total calculation hua: $1 (\text{khud}) + 0 (\text{left}) + 0 (\text{right}) = \mathbf{1}$. Node 2 ne `1` wapas bhej diya Node 1 ko.
* **Right Call `countNonLeaves(3)` par gaye (Node 1 se):** Node 3 ka left-right NULL hai, yaani ye leaf hai, toh isne return kiya `0`.
* **Final Step:** Node 1 ke paas left se `1` aaya aur right se `0` aaya. Formula me dala: $1 (\text{khud}) + 1 (\text{left}) + 0 (\text{right}) = \mathbf{2}$.

Mil gaya na perfect answer **2**!

---

## 3. C++ Implementation (Recursion Se)

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to count non-leaf nodes
int countNonLeaves(Node* root) {
    // Base Case 1: Agar node khali hai
    if (root == nullptr) {
        return 0;
    }

    // Base Case 2: Agar node leaf node hai, toh use mat gino (0 return karo)
    if (root->left == nullptr && root->right == nullptr) {
        return 0;
    }

    // Agar control yahan aaya, matlab current node non-leaf hai!
    // Toh 1 (khud) + Left ke non-leaves + Right ke non-leaves
    return 1 + countNonLeaves(root->left) + countNonLeaves(root->right);
}

int main() {
    // Tree setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Tree me total Non-Leaf Nodes hain: " << countNonLeaves(root) << endl;

    return 0;
}

```

### Output:

```text
Tree me total Non-Leaf Nodes hain: 2

```

---

## 4. Iterative Way (Using Queue / Level Order)

Bina recursion ke karne ke liye hum standard **Queue** wala tarika use karenge.

**Logic:** Queue me nodes ko daalte jao. Jab bhi kisi node ko pop karo, toh check karo ki kya uska left child ya right child me se koi bhi ek zinda (not NULL) hai? Agar haan, toh iska matlab wo non-leaf node hai, apne `nonLeafCount` ko `+1` kar do.

```cpp
#include <queue>

int countNonLeavesIterative(Node* root) {
    if (root == nullptr) return 0;

    int nonLeafCount = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Agar kam se kam ek child bhi zinda hai, toh ye non-leaf hai
        if (curr->left != nullptr || curr->right != nullptr) {
            nonLeafCount++;
        }

        // Bachhon ko normal queue me aage push karo processing ke liye
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }

    return nonLeafCount;
}

```

---

## 5. Complexity

* **Time Complexity:** $O(N)$ dono tarikon me, kyunki har ek node ko check karna hi padega ki uske paas bachhe hain ya nahi.
* **Space Complexity:** * **Recursive:** $O(H)$ jahan $H$ tree ki height hai (internal call stack space).
* **Iterative:** $O(W)$ jahan $W$ tree ki max width hai (queue space).



Bhai, **Height of a Binary Tree** (jise kuch log **Maximum Depth** bhi kehte hain) tree ke sabse important sawaalon me se ek hai.

Iska matlab hota hai: **"Root node se lekar sabse door wale Leaf node tak jaane me maximum kitne nodes (ya edges) aate hain?"** Simple bhasa me bolo toh—tumhara tree kitna lamba ya kitna gehra hai, wahi uski height hai.

Aao iska logic, recursion ka dimaag kholne wala dry run aur code poori detail me samajhte hain.

---

## 1. Core Logic (Height Kaise Nikalein?)

Socho tum firse ek node par khade ho. Tumhe apne upar wale ko batana hai ki tumhare niche kitni lambi building hai. Tum kya karoge?

1. Tum apne **Left child** se poochoge: *"Bhai, tere side ki maximum height kitni hai?"* (Maano usne bola $H_L$)
2. Tum apne **Right child** se poochoge: *"Bhai, tere side ki maximum height kitni hai?"* (Maano usne bola $H_R$)
3. Ab tum dekhoge ki dono me se **bada** kaun hai ($\max(H_L, H_R)$), kyunki hume sabse lamba raasta chahiye.
4. Us bade wale me tum **+1 (khud ka floor)** jodoge aur upar bhej doge.

$$\text{Height} = \max(\text{Left Height}, \text{Right Height}) + 1$$

---

## 2. Diagram aur Dry Run

Maano hamara tree aisa hai:

```text
          1         -- Floor 3 (Height = 3)
        /   \
       2     3      -- Floor 2
      / \   
     4   5          -- Floor 1

```

Humne call kiya `getHeight(1)`:

* **Node 1** ruka hua hai jab tak Node 2 aur Node 3 apni height na batadein.
* **Left Call `getHeight(2)` par gaye:** Node 2 ruka hai `4` aur `5` ke liye.
* **Node 4 par gaye:** Iska left `nullptr` hai (height = 0), right `nullptr` hai (height = 0).
* Node 4 ne apni height nikali: $\max(0, 0) + 1 = \mathbf{1}$. Isne `1` wapas kiya Node 2 ko.


* **Node 5 par gaye:** Iska bhi left-right NULL hai, toh isne bhi apni height nikali: $\max(0, 0) + 1 = \mathbf{1}$. Isne bhi `1` wapas kiya Node 2 ko.
* **Node 2 par wapas aaye:** Iske left se `1` aaya, right se `1` aaya.
* Node 2 ki height: $\max(1, 1) + 1 = \mathbf{2}$. Isne `2` wapas bheja Node 1 ko.


* **Right Call `getHeight(3)` par gaye (Node 1 se):** Node 3 ka left-right NULL hai, toh iski height hui: $\max(0, 0) + 1 = \mathbf{1}$. Isne `1` wapas bheja Node 1 ko.
* **Final Step at Node 1:** Node 1 ke paas left se `2` aaya aur right se `1` aaya.
* Formula lagaya: $\max(2, 1) + 1 = 2 + 1 = \mathbf{3}$.



Tree ki total height mil gayi **3**!

---

## 3. C++ Implementation (Recursion Se)

Recursion se iska code sirf ek line ka hota hai. Base case yeh hoga ki agar tree khali (`nullptr`) hai, toh uski height `0` hogi.

```cpp
#include <iostream>
#include <algorithm> // max() function use karne ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the height of a Binary Tree
int getHeight(Node* root) {
    // Base Case: Agar tree khali hai toh height 0 hai
    if (root == nullptr) {
        return 0;
    }

    // 1. Left subtree ki height mangwao
    int leftHeight = getHeight(root->left);

    // 2. Right subtree ki height mangwao
    int rightHeight = getHeight(root->right);

    // 3. Dono me se jo bada hai usme +1 karke return karo
    return max(leftHeight, rightHeight) + 1;
}

int main() {
    // Tree setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Binary Tree ki Height hai: " << getHeight(root) << endl;

    return 0;
}

```

### Output:

```text
Binary Tree ki Height hai: 3

```

---

## 4. Iterative Way (Using Queue / Level Order)

Interviews me agar bole ki bina recursion ke karo, toh tumne jo **Level Order Traversal Line by Line** seekha tha na? Bas wahi copy-paste karna hai!

**Logic:** Hum tree ko floor-by-floor ghoomte hain. Har baar jab ek poora floor (level) khatam hota hai, hum apni `height` variable ko `+1` kar dete hain.

```cpp
#include <queue>

int getHeightIterative(Node* root) {
    if (root == nullptr) return 0;

    int height = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Current level par kitne nodes hain
        height++;            // Naya level shuru hua, height badhao

        // Is level ke saare nodes ko queue se nikaal do
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }

    return height;
}

```

---

## 5. Complexity

* **Time Complexity:** $O(N)$ dono tarikon me, kyunki sabse lamba raasta dhoodhne ke liye hume ek baar saare nodes par jaana hi padega.
* **Space Complexity:** * **Recursive:** $O(H)$ jahan $H$ tree ki height hai (internal call stack space). Worst case me agar tree ek seedhi line me ho (Skewed tree), toh $O(N)$ ho jayega.
* **Iterative:** $O(W)$ jahan $W$ tree ki max width hai (queue space).



Bhai, **Largest Value in Each Level** tree ka ek bohot hi shaandar aur dimaag kholne wala sawaal hai.

Iska matlab hota hai: **"Tree ke har ek floor (level) par jaana hai, us floor ke saare nodes ko dekhna hai, aur unme se jo sabse bada number (maximum value) hai, use nikaal kar ek list me store karna hai."**

Jaise is tree me dekho:

```text
          1         <-- Level 0 (Max = 1)
        /   \
       3     2      <-- Level 1 (Max = 3)
      / \     \
     5   3     9    <-- Level 2 (Max = 9)

```

* **Level 0** par sirf `1` hai, toh max hua: **1**
* **Level 1** par `3` aur `2` hain, toh max hua: **3**
* **Level 2** par `5`, `3`, aur `9` hain, toh max hua: **9**

Toh hamara final answer (vector/list) hona chahiye: `[1, 3, 9]`

Aao iska best approach (Queue wala) aur iska code poori detail me samajhte hain.

---

## 1. Core Logic (Level Order Traversal ka Twist)

Bhai, jab bhi word **"Each Level"** suno, toh dimaag me sabse pehle ghanti bajni chahiye **Level Order Traversal (BFS)** ki! Humne seekha tha ki Queue ka use karke hum floor-by-floor ghoom sakte hain.

Bas is sawaal me hum ek chhota sa twist karenge:

1. Jab hum kisi floor (level) par enter karenge, toh hum pehle ginn lenge ki is floor par kitne log (nodes) hain: `int size = q.size();`
2. Ek variable banayenge `maxVal` aur use bohot choti value (`INT_MIN`) se shuru karenge.
3. Ab ek loop chalayenge jo sirf **us specific level** ke nodes ko ek-ek karke nikaalega.
4. Har node ko nikaalte hi hum compare karenge: *Kya is node ka data hamare `maxVal` se bada hai?* Agar haan, toh `maxVal` ko update kar denge.
5. Jab us floor ke saare nodes khatam ho jayenge, toh jo bhi `maxVal` bacha hoga, use apne final answer vector me push kar denge.

---

## 2. Step-by-Step Dry Run

Chalo upar wale tree ke liye dry run karte hain:

* **Shuruat me:** Queue me root daala `[Queue: 1]`. Final Answer array `ans = []`.
* **Level 0:**
* `size = 1` (kyunki queue me sirf 1 node hai). `maxVal = INT_MIN`.
* Node `1` ko pop kiya. `maxVal = max(INT_MIN, 1) = 1`.
* `1` ke bachhon (`3`, `2`) ko queue me push kiya. `[Queue: 3, 2]`
* Level khatam! `ans` me `maxVal` daala $\rightarrow$ `ans = [1]`.


* **Level 1:**
* `size = 2` (queue me 3 aur 2 hain). `maxVal = INT_MIN`.
* Node `3` ko pop kiya. `maxVal = max(INT_MIN, 3) = 3`. Bachhe (`5`, `3`) push kiye.
* Node `2` ko pop kiya. `maxVal = max(3, 2) = 3`. Bachha (`9`) push kiya.
* `[Queue: 5, 3, 9]`
* Level khatam! `ans` me `maxVal` daala $\rightarrow$ `ans = [1, 3]`.


* **Level 2:**
* `size = 3`. `maxVal = INT_MIN`.
* Node `5`, `3`, aur `9` ko ek-ek karke check kiya. Sabse bada `9` mila, toh `maxVal = 9` ho gaya.
* Inke koi bachhe nahi hain. Queue khali ho gayi.
* Level khatam! `ans` me `maxVal` daala $\rightarrow$ `ans = [1, 3, 9]`.



Loop khatam, hamara answer taiyar hai!

---

## 3. C++ Implementation (Complete Code)

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MIN ke liye
#include <algorithm> // max() ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find the largest value in each level
vector<int> largestValues(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Current level par kitne nodes hain
        int maxVal = INT_MIN; // Is level ka sabse bada number dhoodhne ke liye

        // Sirf is level ke saare nodes ko process karo
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Max value ko update karo
            maxVal = max(maxVal, curr->data);

            // Bachhon ko queue me push karo agli level ke liye
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }

        // Is level ka kaam khatam, max value ko result me daal do
        result.push_back(maxVal);
    }

    return result;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    vector<int> ans = largestValues(root);

    cout << "Har level ki largest values hain: ";
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Har level ki largest values hain: 1 3 9 

```

---

## 4. Complexity

* **Time Complexity:** $O(N)$ kyunki hum har ek node par level-by-level jaakar uski value check kar rahe hain. Ek bhi node skip nahi ho raha.
* **Space Complexity:** $O(W)$ jahan $W$ tree ki maximum width hai. Worst case me, queue me ek poore level ke saare nodes store hote hain.




Bhai, **"Two Trees are Identical"** (Check if two trees are same) tree ka ek bohot hi popular question hai jo Microsoft, Amazon aur Adobe jaise interviews me aksar pucha jata hai.

Iska simple sa matlab hai: **"Kya do alag-alag trees bilkul ek jaise dikhte hain?"** Ek jaise (Identical) hone ke liye do sharatein (conditions) poori honi chahiye:

1. Dono trees ka **Structure** bilkul same hona chahiye (yaani agar pehle tree me kisi node ka left child hai, toh dusre me bhi hona chahiye).
2. Saare corresponding nodes ka **Data (value)** bhi bilkul same hona chahiye.

### Ek Example se samjho:

```text
   Tree 1:        Tree 2:         Tree 3:
      1              1               1
     / \            / \             / \
    2   3          2   3           2   4

```

* **Tree 1 aur Tree 2** identical hain (Structure aur Data dono same hai).
* **Tree 1 aur Tree 3** identical **nahi** hain, kyunki root ke right me Tree 1 me `3` hai aur Tree 3 me `4` hai.

---

## 1. Core Logic (Recursion Kaise Sochein?)

Do trees ko check karne ke liye hum dono trees par **ek saath** ghoomte (traverse karte) hain. Jab hum dono trees ke kisi node `p` aur `q` par khade hain, toh main 4 conditions banti hain:

1. **Dono khali hain (`p == nullptr && q == nullptr`):** Agar dono trees ghoomte-ghoomte ek saath khatam ho gaye, iska matlab abhi tak sab sahi tha. Toh yahan se `true` return kar do.
2. **Ek khali hai, ek zinda hai (`p == nullptr || q == nullptr`):** Iska matlab ek tree me node hai par dusre me nahi hai (Structure mismatch!). Toh yahan se `false` return kar do.
3. **Dono zinda hain, par data alag hai (`p->data != q->data`):** Structure toh same hai par andar ki value alag nikal gayi. Toh yahan se bhi `false` return kar do.
4. **Dono zinda hain aur data bhi same hai:** Ab hum aage check karenge. Hum bolenge ki agar iska **Left subtree** bhi identical ho AND iska **Right subtree** bhi identical ho, tabhi poora tree identical maana jayega:

$$\text{isIdentical}(p, q) = (p\rightarrow\text{data} == q\rightarrow\text{data}) \ \&\& \ \text{isIdentical}(p\rightarrow\text{left}, q\rightarrow\text{left}) \ \&\& \ \text{isIdentical}(p\rightarrow\text{right}, q\rightarrow\text{right})$$



---

## 2. Step-by-Step Dry Run

Chalo in do chote trees ko check karte hain:

```text
   Tree p:     Tree q:
      1           1
     /           /
    2           3

```

1. Humne call kiya `isIdentical(p, q)` (Dono ke root `1` par hain).
* Kya dono NULL hain? Nahi.
* Kya koi ek NULL hai? Nahi.
* Kya dono ka data same hai? Haan (`1 == 1`).


2. Ab ye left aur right dono check karega:
* **Left Call:** `isIdentical(p->left, q->left)` $\rightarrow$ yaani Node `2` aur Node `3` par gaye.
* Kya dono NULL hain? Nahi.
* Kya koi ek NULL hai? Nahi.
* Kya dono ka data same hai? **Nahi (`2 != 3`)** $\rightarrow$ Ye return karega `false`.




3. Kyunki left call se hi `false` aa gaya, toh beech me `&&` (AND) laga hone ki wajah se poora function `false` return kar dega.

---

## 3. C++ Implementation (Recursion Se)

Recursion se iska code bohot hi chota aur pyara banta hai:

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check if two trees are identical
bool isIdentical(Node* p, Node* q) {
    // Base Case 1: Agar dono trees khali hain, toh identical hain
    if (p == nullptr && q == nullptr) {
        return true;
    }

    // Base Case 2: Agar ek khali hai aur dusra nahi, toh identical nahi hain
    if (p == nullptr || q == nullptr) {
        return false;
    }

    // Base Case 3: Agar dono ke node ki value alag hai, toh identical nahi hain
    if (p->data != q->data) {
        return false;
    }

    // Recursive Call: Current data same hai, ab left aur right dono subtrees check karo
    return isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

int main() {
    // Tree 1 banate hain
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // Tree 2 banate hain (Bilkul Tree 1 jaisa)
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    if (isIdentical(root1, root2)) {
        cout << "Dono trees bilkul Identical (Same) hain!" << endl;
    } else {
        cout << "Dono trees Identical nahi hain!" << endl;
    }

    return 0;
}

```

### Output:

```text
Dono trees bilkul Identical (Same) hain!

```

---

## 4. Iterative Way (Using Queue)

Agar tumse interview me bole ki bina recursion ke karo, toh tum **Level Order Traversal** ka use kar sakte ho. Bas is baar hum ek hi queue me dono trees ke nodes ko jode (pairs) me daalenge.

**Logic:**

* Queue me pehle `(root1, root2)` push karo.
* Loop chalao jab tak queue khali na ho:
* Queue se dono nodes nikaalo `p` aur `q`.
* Wahi upar wali conditions check karo (Dono NULL hain toh `continue`, ek NULL ya data alag toh `return false`).
* Queue me pairs me push karo: `(p->left, q->left)` aur fir `(p->right, q->right)`.



```cpp
#include <queue>

bool isIdenticalIterative(Node* root1, Node* root2) {
    queue<Node*> q;
    q.push(root1);
    q.push(root2);

    while (!q.empty()) {
        Node* p = q.front(); q.pop();
        Node* q_node = q.front(); q.pop(); // variable name q_node kyunki q queue ka naam hai

        // Agar dono null hain, toh agla pair check karo
        if (p == nullptr && q_node == nullptr) continue;
        
        // Agar ek null hai ya data alag hai
        if (p == nullptr || q_node == nullptr) return false;
        if (p->data != q_node->data) return false;

        // Left children ko pair me daalo
        q.push(p->left);
        q.push(q_node->left);

        // Right children ko pair me daalo
        q.push(p->right);
        q.push(q_node->right);
    }
    return true;
}

```

---

## 5. Complexity

* **Time Complexity:** $O(\min(N, M))$ jahan $N$ aur $M$ dono trees ke nodes hain. Kyunki hum tabhi tak ghoominge jab tak chota wala tree khatam nahi ho jata ya mismatch nahi mil jata. Worst case me saare nodes check honge toh $O(N)$.
* **Space Complexity:** $O(H)$ jahan $H$ tree ki height hai (call stack space). Worst case me $O(N)$ ho sakta hai agar tree skewed ho.



Bhai, **Mirror Tree** (jise LeetCode par **Symmetric Tree** ya **Invert Binary Tree** ke naam se bhi pucha jata hai) Google, Amazon aur Adobe ka ek aur favourite question hai.

Iska simple sa matlab hai: **"Agar tum tree ke aage ek sheesha (mirror) rakh do, toh sheeshe me tree kaisa dikhega?"** Mirror tree banane ke liye hume tree ke har ek node ke **Left Child aur Right Child ko aapas me adla-badli (swap)** karna hota hai.

### Ek Example se samjho:

```text
    Original Tree:                 Mirror Tree:
          1                             1
        /   \                         /   \
       2     3                       3     2
      / \   /                       /     / \
     4   5 6                       6     5   4

```

Dhyan se dekho:

* Original me `1` ke left me `2` tha, Mirror me `1` ke right me `2` aa gaya.
* `2` ke apne bachhe (`4` aur `5`) bhi aapas me swap ho gaye, isliye mirror me `5` pehle hai aur `4` baad me.

---

## 1. Core Logic (Kaise Karenge?)

Iska logic bohot simple hai. Hum tree ke har ek node par jaate hain (chahe Preorder, Postorder ya Level Order se) aur ye 3 steps karte hain:

1. Us node ke **Left child** ko ek temporary variable me sambhal kar rakho.
2. Us node ke Left me uska **Right child** daal do.
3. Us node ke Right me wo temporary variable (purana left) daal do.
4. Yahi same kaam uske left aur right bachhon ke liye recursion se bol do ki wo khud kar lein.

---

## 2. Recursion Kaise Kaam Karta Hai? (Dry Run)

Chalo upar wale tree ka dry run karte hain:

```text
          1
        /   \
       2     3

```

Humne `mirror(1)` call kiya:

1. **Node 1** par aaye. Humne iske left (`2`) aur right (`3`) ko aapas me swap kar diya.
* Tree ab aisa dikh raha hai:
```text
          1
        /   \
       3     2

```




2. Ab humne recursion se bola: `mirror(3)` aur `mirror(2)` ko bhi solve karo (taaki unke niche wale bachhe bhi swap ho sakein).
3. **Node 3** aur **Node 2** ke niche koi bachhe nahi hain (`nullptr`), toh wahan se recursion wapas laut aayega (Base Case hit).

Poora tree mirror ho gaya!

---

## 3. C++ Implementation (Recursion Se)

Recursion se iska code sirf 4-5 lines ka banta hai:

```cpp
#include <iostream>
#include <algorithm> // swap() function ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to convert a tree into its Mirror Tree
void mirrorTree(Node* root) {
    // Base Case: Agar node khali hai toh kuch mat karo, wapas jao
    if (root == nullptr) {
        return;
    }

    // Recursion se pehle left aur right subtrees ko mirror karwa lo
    mirrorTree(root->left);
    mirrorTree(root->right);

    // Ab current node ke left aur right pointers ko aapas me swap (adla-badli) kar do
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Check karne ke liye Inorder Traversal (Mirror hone ke baad ye ulta ho jata hai)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Original Tree ka Inorder: ";
    inorder(root); // Output: 4 2 5 1 3
    cout << endl;

    // Tree ko mirror kiya
    mirrorTree(root);

    cout << "Mirror Tree ka Inorder:   ";
    inorder(root); // Output: 3 1 5 2 4
    cout << endl;

    return 0;
}

```

### Output:

```text
Original Tree ka Inorder: 4 2 5 1 3 
Mirror Tree ka Inorder:   3 1 5 2 4 

```

---

## 4. Iterative Way (Using Queue / Level Order)

Agar interviewer bole, *"Bhai, recursion se toh sab kar lete hain, bina recursion ke karke dikhao"*, toh hum apna purana **Queue (Level Order Traversal)** use karenge.

**Logic:** Jaise hum floor-by-floor ghoomte hain, queue se ek node nikaalenge, uske left aur right ko turant wahi par swap kar denge, aur phir uske bachhon ko queue me push kar denge.

```cpp
#include <queue>

void mirrorTreeIterative(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Current node ke left aur right ko swap karo
        Node* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        // Bachhon ko queue me push karo (Dhyan rahe ab left aur right badal chuke hain)
        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
}

```

---

## 5. Complexity

* **Time Complexity:** $O(N)$ kyunki hume tree ke har ek node par jaakar uske left aur right ko swap karna hi padega.
* **Space Complexity:** * **Recursive:** $O(H)$ jahan $H$ tree ki height hai (internal call stack space).
* **Iterative:** $O(W)$ jahan $W$ tree ki max width hai (queue ka space).


Bhai, **Check if a Binary Tree is Balanced** (jise **Height-Balanced Tree** bhi kehte hain) LeetCode ka ek bohot hi famous *Medium* level ka sawaal hai.

Iska intuition samajhna bohot zaroori hai kyunki iska use aage **AVL Trees** aur **Red-Black Trees** ko samajhne me hota hai.

Aao iska concept, intuition, dry run aur C++ code bilkul detail me samajhte hain.

---

## 1. Height-Balanced Tree Kya Hota Hai?

Ek Binary Tree tabhi **Balanced** maana jata hai jab tree ke **har ek node** par ye condition sach ho:

> Us node ke **Left subtree ki height** aur **Right subtree ki height** ke beech ka difference (farak) **1 se zyada nahi** hona chahiye.

Yani agar hum kisi node ka Balance Factor ($BF$) nikalein:


$$BF = |\text{Left Height} - \text{Right Height}|$$


Toh $BF$ ki value **0, 1, ya -1** hi honi chahiye. Agar kisi bhi ek node par ye difference 2 ya usse zyada ho gaya, toh poora tree **Imbalanced** ho jayega.

### Ek Example se samjho:

```text
      Balanced Tree:                  Imbalanced Tree:
           1                                 1
         /   \                              /  
        2     3                            2    
       /                                  /     
      4                                  4      

```

* **Pehle Tree me:** Node 1 ke left ki height 2 hai, right ki 1 hai. Difference $= |2 - 1| = 1$ (Balanced). Baki nodes bhi balanced hain.
* **Dusre Tree me:** Node 1 ke left ki height 2 hai, right ki 0 hai. Difference $= |2 - 0| = 2$. Kyunki difference 1 se bada ho gaya, ye tree **Imbalanced** hai.

---

## 2. Intuition (Dimaag Kaise Lagayein?)

Is sawaal ko karne ke do tarike hain. Ek tarika thoda slow hai aur dusra ek dam mast aur fast hai.

### Approach 1: Naive Approach ($O(N^2)$)

Hum har node par khade hokar uske left aur right ki height nikalte hain (jo humne `getHeight` function seekha tha usse). Phir check karte hain ki dono ka difference $\le 1$ hai ya nahi. Isme dikkat ye hai ki ek hi node ki height hum baar-baar nikalte hain, jisse time complexity kharab ho jati hai.

### Approach 2: Optimized Approach ($O(N)$) — The Smart Way

Hum alag se height nikalne ke bajay, **height nikalte-nikalte hi check karte chalenge** ki tree balanced hai ya nahi!

Hum top-down nahi, **Bottom-Up (Neeche se upar)** chalenge:

* Agar koi subtree imbalanced milta hai, toh hum height return karne ke bajay ek special signal return kar denge, jaise **`-1`**.
* Agar left ya right subtree ne `-1` return kiya, iska matlab niche kahin gadbad ho chuki hai, toh hum bina soche upar bhi `-1` bhej denge.
* Agar sab sahi hai, toh hum normal height ($\max(\text{left}, \text{right}) + 1$) return karenge.

---

## 3. Step-by-Step Dry Run

Chalo is Imbalanced Tree ke liye optimized approach ka dry run karte hain:

```text
          1
         /
        2
       /
      4

```

1. **Node 4** par aaye (Leftmost node):
* Iska left NULL hai (height 0), right NULL hai (height 0).
* Difference $= |0 - 0| = 0$. Sab sahi hai!
* Node 4 ne apni height return ki: $\max(0, 0) + 1 = \mathbf{1}$.


2. **Node 2** par wapas aaye:
* Iske left (Node 4) se height aayi `1`. Iska right NULL hai (height 0).
* Difference $= |1 - 0| = 1$. Sab sahi hai!
* Node 2 ne apni height return ki: $\max(1, 0) + 1 = \mathbf{2}$.


3. **Node 1** (Root) par wapas aaye:
* Iske left (Node 2) se height aayi `2`. Iska right NULL hai (height 0).
* Difference $= |2 - 0| = \mathbf{2}$.
* **GADBADI!** Difference 1 se bada ho gaya. Node 1 turant return kar dega **`-1`**.



Main function dekhega ki answer `-1` aaya hai, iska matlab tree balanced nahi hai!

---

## 4. C++ Implementation (Complete Code)

```cpp
#include <iostream>
#include <algorithm> // max() aur abs() ke liye
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Yeh function height bhi nikalega aur balance bhi check karega
int checkBalance(Node* root) {
    // Base Case: Khali tree ki height 0 hoti hai aur wo balanced hota hai
    if (root == nullptr) {
        return 0;
    }

    // 1. Left subtree ki height mangwao
    int leftHeight = checkBalance(root->left);
    // Agar left subtree pehle se hi imbalanced hai, toh upar -1 bhej do
    if (leftHeight == -1) return -1;

    // 2. Right subtree ki height mangwao
    int rightHeight = checkBalance(root->right);
    // Agar right subtree pehle se hi imbalanced hai, toh upar -1 bhej do
    if (rightHeight == -1) return -1;

    // 3. Ab current node ka balance check karo
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Agar imbalanced hai toh -1 return karo
    }

    // 4. Agar sab sahi hai, toh normal height return karo
    return max(leftHeight, rightHeight) + 1;
}

// Main function jo user call karega
bool isBalanced(Node* root) {
    // Agar function ne -1 return kiya matlab imbalanced hai, varna balanced hai
    return checkBalance(root) != -1;
}

int main() {
    // Ek Balanced Tree banate hain
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    if (isBalanced(root)) {
        cout << "Tree Balanced hai! (Mast hai)" << endl;
    } else {
        cout << "Tree Balanced nahi hai! (Imbalanced)" << endl;
    }

    // Ab isko jaanboojh kar imbalanced banate hain
    root->left->left->left = new Node(5); 

    if (isBalanced(root)) {
        cout << "Tree Balanced hai!" << endl;
    } else {
        cout << "Tree Balanced nahi hai! (Imbalanced)" << endl;
    }

    return 0;
}

```

### Output:

```text
Tree Balanced hai! (Mast hai)
Tree Balanced nahi hai! (Imbalanced)

```

---

## 5. Complexity

* **Time Complexity:** **$O(N)$** kyunki bottom-up approach me hum har ek node par sirf ek hi baar ja rahe hain aur wahi par height aur balance dono calculate ho raha hai.
* **Space Complexity:** **$O(H)$** jahan $H$ tree ki height hai (internal call stack space). Worst case me agar tree skewed line me ho, toh $O(N)$ ho sakta hai.



Bhai, **Level Order Traversal in Spiral Form** (jise kuch log **Zig-Zag Traversal** bhi kehte hain) tree ka ek bohot hi shaandar aur interviews me baar-baar pucha jaane wala *Medium* level ka sawaal hai. Amazon, Microsoft aur Flipkart me ye bohot baar aa chuka hai.

Iska matlab hota hai: **"Tree ko level-by-level toh ghoomna hai, par pehle level par left-to-right jaana hai, agle level par right-to-left aana hai, fir uske agle par left-to-right... bilkul ek saamp (snake) ya spiral ki tarah."**

### Ek Example se samjho:

```text
          1         <-- Level 0 (Left to Right)  -> Print: 1
        /   \
       2     3      <-- Level 1 (Right to Left)  -> Print: 3, 2
      / \   / \
     4   5 6   7    <-- Level 2 (Left to Right)  -> Print: 4, 5, 6, 7

```

Agar hum iska normal level order nikalte toh aata: `1 2 3 4 5 6 7`.
Lekin **Spiral Form** me output aayega: **`1 3 2 4 5 6 7`**.

---

## 1. Core Logic (Dimaag Kaise Lagayein?)

Is sawaal ko karne ke do sabse popular tarike hain. Ek tarika hai standard Queue ka use karke thoda hera-pheri karna, aur dusra hai **2 Stacks** ka use karna jo ki sabse elegant aur interview-friendly tarika hai. Hum dono ko dekhenge, par pehle **2 Stacks** ka intuition samajhte hain.

### 2 Stacks ka Intuition (Stack 1 aur Stack 2):

Kyunki Stack ka rule hota hai **LIFO (Last-In-First-Out)**, yaani jo baad me jayega wo pehle niklega—ye cheez direction ko ulta karne ke liye ek dam perfect hai!

* **Stack 1 (Left to Right level ke liye):** Jab hum is stack se nodes ko nikalenge, toh unke bachhon ko dusre stack me push karte waqt pehle **Left** child ko daalenge, fir **Right** child ko.
* **Stack 2 (Right to Left level ke liye):** Jab hum is stack se nodes ko nikalenge, toh unke bachhon ko pehle stack me push karte waqt pehle **Right** child ko daalenge, fir **Left** child ko.

---

## 2. Step-by-Step Dry Run (2 Stacks Se)

Upar wale tree ke liye dekhte hain:

* **Shuruat me:** `Stack1` me root ko daala `[S1: 1]`. `Stack2` abhi khali hai `[S2: Empty]`.

1. **Cycle 1 (S1 se nikaalo):**
* Node `1` ko pop kiya aur print kiya. **Output: 1**
* Iske bachhon ko **S2** me daalo (Pehle Left fir Right) $\rightarrow$ Pehle `2` gaya, fir `3` gaya. `[S2: 2, 3]` (Top par `3` hai).


2. **Cycle 2 (S2 se nikaalo - kyunki S1 khali ho gaya):**
* Top par `3` hai, use pop kiya aur print kiya. **Output: 1 3**
* Iske bachhon ko **S1** me daalo par is baar **ulte order me (Pehle Right fir Left)** $\rightarrow$ Pehle `7` gaya, fir `6` gaya. `[S1: 7, 6]`
* Agla element S2 me `2` hai, use pop kiya aur print kiya. **Output: 1 3 2**
* Iske bachhon ko **S1** me daalo (Pehle Right fir Left) $\rightarrow$ Pehle `5` gaya, fir `4` gaya. `[S1: 7, 6, 5, 4]` (Top par `4` hai).


3. **Cycle 3 (S1 se nikaalo - kyunki S2 khali ho gaya):**
* S1 se ek-ek karke nikalenge toh top se `4`, `5`, `6`, `7` line se niklenge aur print ho jayenge. **Output: 1 3 2 4 5 6 7**



Dono stacks khali, kaam khatam!

---

## 3. Alternative Method (Deque / Vector Reversal) — Sabse Simple

Agar tum 2 stacks ke jhanjhat me nahi padna chahte, toh ek aur asan tarika hai:
Normal **Level Order Traversal (Queue wala)** hi chalao. Bas ek `bool leftToRight = true;` variable rakh lo.

* Har level ka data ek alag vector me store karo.
* Agar `leftToRight == false` hai, toh us level ke vector ka data print/save karne se pehle use `reverse()` kar do!
* Har level ke baad `leftToRight = !leftToRight;` kar ke flip karte raho.

---

## 4. C++ Implementation (2 Stacks Standard Code)

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print Spiral Level Order Traversal
void printSpiral(Node* root) {
    if (root == nullptr) return;

    // Do stacks banaye
    stack<Node*> s1; // Left to Right level ke liye
    stack<Node*> s2; // Right to Left level ke liye

    // Sabse pehle root ko s1 me daala
    s1.push(root);

    // Jab tak dono me se koi bhi ek stack me data bacha hai
    while (!s1.empty() || !s2.empty()) {

        // Agar s1 me data hai, toh Left-to-Right chal rahe hain
        while (!s1.empty()) {
            Node* curr = s1.top();
            s1.pop();
            cout << curr->data << " ";

            // Bachhon ko s2 me daalo: Pehle Left, fir Right
            if (curr->left != nullptr) s2.push(curr->left);
            if (curr->right != nullptr) s2.push(curr->right);
        }

        // Agar s2 me data hai, toh Right-to-Left chal rahe hain
        while (!s2.empty()) {
            Node* curr = s2.top();
            s2.pop();
            cout << curr->data << " ";

            // Bachhon ko s1 me daalo: Pehle Right, fir Left (Ulta order)
            if (curr->right != nullptr) s1.push(curr->right);
            if (curr->left != nullptr) s1.push(curr->left);
        }
    }
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Spiral / Zig-Zag Level Order Traversal: " << endl;
    printSpiral(root);
    cout << endl;

    return 0;
}

```

### Output:

```text
Spiral / Zig-Zag Level Order Traversal: 
1 3 2 4 5 6 7 

```

---

## 5. Complexity

* **Time Complexity:** **$O(N)$** kyunki hum har ek node par pure traversal me sirf ek hi baar visit kar rahe hain aur use stack me daal/nikal rahe hain.
* **Space Complexity:** **$O(N)$** kyunki worst case me (sabse nichle level par) stacks me tree ke maximum width ke barabar nodes store ho sakte hain, jo ki lagbhag $N/2$ nodes hote hain.



Bhai, **Check if two nodes are Cousins in a Binary Tree** LeetCode ka ek bohot hi pyara aur dimaag ki acchi exercise karwane wala *Easy-Medium* level ka sawaal hai.

Iska logic samajhne ke liye pehle real-world family tree ka concept dhyan me lao. Tumhara cousin kaun hota hai? Wo insaan jo tumhare hi age group (same generation) ka ho, par uske papa aur tumhare papa alag-alag hon (bhai-bhai hon).

Tree me bhi bilkul yahi rishta lagta hai! Two nodes are said to be cousins if:

1. Dono nodes ka **Level (ya Depth) bilkul same** hona chahiye.
2. Dono nodes ke **Parents alag-alag (different)** hone chahiye.

### Ek Example se samjho:

```text
          1
        /   \
       2     3
      / \     \
     4   5     6

```

* **Kya `4` aur `6` cousins hain?**
* `4` ka level hai 2, `6` ka level bhi hai 2 (Same Level).
* `4` ka parent hai `2`, `6` ka parent hai `3` (Different Parents).
* **Yes, `4` aur `6` cousins hain!**


* **Kya `4` aur `5` cousins hain?**
* Dono ka level same hai (2), par dono ka parent bhi same hai (`2`). Toh ye cousins nahi, **Siblings (sagge bhai)** hain. Isliye answer **No** hoga.



---

## 1. Core Logic (Dimaag Kaise Lagayein?)

Hume do nodes `x` aur `y` diye honge aur check karna hai ki wo cousins hain ya nahi. Isko solve karne ke liye hume do cheezein dhoodhni hain:

1. `x` aur `y` ka level kya hai? (`levelX` and `levelY`)
2. `x` aur `y` ke parents kaun hain? (`parentX` and `parentY`)

Hum poore tree me ghoomenge (chahe BFS se ghoomo ya DFS se). Ghoomte waqt hum har node ke liye uska level aur parent note karte chalenge. End me hum bas ye check karenge:


$$\text{if } (\text{levelX} == \text{levelY} \ \&\& \ \text{parentX} != \text{parentY}) \rightarrow \text{True, else False}$$

---

## 2. Approach: Level Order Traversal (BFS) Sabse Mast Hai!

Wese toh ye recursion (DFS) se bhi ho jata hai, par **Queue (BFS)** se iska intuition bohot natural lagta hai kyunki BFS floor-by-floor chalta hai.

**Logic:**

1. Hum normal level order traversal karenge.
2. Har ek level par hum check karenge ki kya `x` aur `y` dono is floor par maujood hain?
3. Lekin unhe queue se nikaalne se pehle, jab hum kisi parent node par khade hain, hum pehle hi check kar lenge ki kahi iske left aur right bachhe hi toh `x` aur `y` nahi hain? Agar aisa hai, toh matlab wo siblings hain, cousins nahi! Hum turant wahi se `false` return kar denge.
4. Agar kisi ek floor par hume `x` aur `y` dono mil jaate hain (aur wo siblings nahi hain), toh hum `true` return kar denge.
5. Agar ek mil gaya aur dusra us floor par nahi mila, iska matlab dono alag-alag floors par hain, toh hum `false` return kar denge.

---

## 3. C++ Implementation (BFS Approach)

```cpp
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to check if two nodes are cousins
bool isCousins(Node* root, int x, int y) {
    if (root == nullptr) return false;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        bool foundX = false;
        bool foundY = false;

        // Is level ke saare nodes ko process karo
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // Check karo agar current node hi x ya y hai
            if (curr->data == x) foundX = true;
            if (curr->data == y) foundY = true;

            // SIBLING CHECK: Agar dono ka parent same hai, toh cousins nahi ho sakte
            if (curr->left != nullptr && curr->right != nullptr) {
                if ((curr->left->data == x && curr->right->data == y) ||
                    (curr->left->data == y && curr->right->data == x)) {
                    return false; // Same parent waale siblings hote hain, cousins nahi!
                }
            }

            // Bachhon ko queue me push karo agli level ke liye
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }

        // Ek poora level check karne ke baad:
        // Agar dono isi level par mil gaye, toh haan ye cousins hain!
        if (foundX && foundY) return true;

        // Agar ek mila aur dusra nahi, toh level alag hai, yaani cousins nahi hain
        if (foundX || foundY) return false;
    }

    return false;
}

int main() {
    // Tree Setup
    //          1
    //        /   \
    //       2     3
    //      / \     \
    //     4   5     6
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int node1 = 4, node2 = 6;
    if (isCousins(root, node1, node2)) {
        cout << node1 << " aur " << node2 << " Cousins hain! 🎉" << endl;
    } else {
        cout << node1 << " aur " << node2 << " Cousins nahi hain! ❌" << endl;
    }

    int node3 = 4, node4 = 5;
    if (isCousins(root, node3, node4)) {
        cout << node3 << " aur " << node4 << " Cousins hain! 🎉" << endl;
    } else {
        cout << node3 << " aur " << node4 << " Cousins nahi hain! ❌ (Ye toh Siblings hain)" << endl;
    }

    return 0;
}

```

### Output:

```text
4 aur 6 Cousins hain! 🎉
4 aur 5 Cousins nahi hain! ❌ (Ye toh Siblings hain)

```

---

## 4. Complexity

* **Time Complexity:** **$O(N)$** kyunki worst case me hume poore tree ke har ek node ko level-by-level check karna pad sakta hai (agar target nodes sabse niche waale level par hon).
* **Space Complexity:** **$O(N)$** kyunki hum queue use kar rahe hain, aur worst case me queue ka size tree ke maximum width ($W \approx N/2$) ke barabar ho jata hai.



Bhai, **Left View of a Binary Tree** ka matlab hota hai ki agar tum tree ke bilkul **baayein (left) taraf khade hokar** tree ko dekhoge, toh tumhe kaun-kaun se nodes dikhayi denge.

Sedehi si baat hai, jab tum left se dekhoge, toh **har ek level (floor) ka jo sabse pehla (leftmost) node hoga**, sirf wahi tumhari aankhon ke saamne aayega. Uske peeche baaki jo nodes honge, wo chhup jayenge.

### Ek Example se samjho:

```text
          1         <-- Level 0 ka pehla node: 1
        /   \
       2     3      <-- Level 1 ka pehla node: 2 (3 chhup gaya)
        \     \
         4     5    <-- Level 2 ka pehla node: 4 (5 chhup gaya)
          \
           6        <-- Level 3 ka pehla node: 6

```

Agar tum left se dekhoge, toh tumhe sirf **`1, 2, 4, 6`** dikhenge. `3` aur `5` unke peeche chhup chuke hain.

---

## 1. Brute Force Approach ka Intuition

Brute force ka matlab hota hai bina kisi extra dimaag ke, sabse seedha tarika apnaana. Humne abhi tak seekha hai ki **har level ka pehla element** chahiye. Toh brute force tareeka kya hoga?

1. Pehle tree ka normal **Level Order Traversal Line-by-Line** (Floor-by-floor) nikal lo.
2. Isse tumhe har level ke saare elements alag-alag mil jayenge.
3. Phir har ek level waale list/vector ke **pehle element (index 0)** ko uthao aur apne answer me daal lo!

Chalo isi ko step-by-step detail me dekhte hain.

---

## 2. Step-by-Step Brute Force Dry Run

Upar waale tree par brute force lagate hain:

### Step 1: Line-by-Line Level Order Traversal Nikalo

Hum Queue ka use karke har level ko alag line me store karenge. Hamara level-by-level data aisa dikhega:

* **Level 0:** `[1]`
* **Level 1:** `[2, 3]`
* **Level 2:** `[4, 5]`
* **Level 3:** `[6]`

### Step 2: Har Level ka index 0 (Pehla Element) Chuno

* Level 0 `[1]` $\rightarrow$ Pehla element hai **1**
* Level 1 `[2, 3]` $\rightarrow$ Pehla element hai **2**
* Level 2 `[4, 5]` $\rightarrow$ Pehla element hai **4**
* Level 3 `[6]` $\rightarrow$ Pehla element hai **6**

Hamara final Left View taiyar hai: **`1, 2, 4, 6`**

---

## 3. C++ Code (Brute Force / Standard BFS Approach)

Ye code level-by-level chalega aur har level ke loop ke starting me (`i == 0`) jo node milega, use save kar lega.

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the Left View of a Binary Tree
vector<int> leftView(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Is floor/level par kitne nodes hain

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // BRUTE FORCE / CORE LOGIC TWIST:
            // Agar ye is level ka PEHLA element hai (index 0), toh ise answer me daal lo
            if (i == 0) {
                ans.push_back(curr->data);
            }

            // Bachhon ko queue me daalo normal tarike se
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> result = leftView(root);

    cout << "Tree ka Left View hai: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Tree ka Left View hai: 1 2 4 6 

```

---

## 4. Complexity Analysis

* **Time Complexity:** **$O(N)$** kyunki hum level order traversal kar rahe hain aur tree ke har ek node par sirf ek hi baar visit kar rahe hain.
* **Space Complexity:** **$O(N)$** ya fir exact bole toh $O(W)$ jahan $W$ tree ki maximum width hai. Queue me worst case me ek poore level ke nodes store hote hain.

> 💡 **Bhai ek Pro-Tip:** Interviews me jab tum ye BFS wala tarika btaoge, toh interviewer khush toh hoga, par wo tumse bolega ki *"Mujhe iska space optimize karke do aur **Recursion (DFS)** se karke dikhao bina kisi Queue ke."* Us optimized recursion wale tarike me hum ek `max_level` variable maintain karte hain aur sirf $O(H)$ space me kaam ho jata hai!




Bhai, tumhari baat bilkul sahi hai. Interviews me jab interviewer tumse **Left View** poochta hai, toh wo BFS (Queue) se zyada tumhare **Recursion (DFS)** ke dimaag ko check karna chahta hai.

Aao ab Left View ka sabse behtareen, **Optimized (Recursive DFS) Approach** samajhte hain, jo interviewer ko ek dam hila ke rakh dega. Isme hum **bina kisi Queue ke, sirf $O(H)$ space** me poora kaam khatam kar denge.

---

## 1. Core Intuition (Dimaag Kaise Lagayein?)

Recursion se Left View nikalne ka ek bohot mast formula hai:
Hum normal Preorder Traversal karte hain (`Root -> Left -> Right`), par ek chote se twist ke saath. Hum raste me **apne current level (ya depth)** par dhyan rakhenge.

* Jab hum pehli baar kisi naye floor (level) par pahunchenge, toh kyunki hum pehle **Left** ki taraf ja rahe hain, toh us floor ka sabse pehla element hume sabse pehle dikhega!
* Hum use turant apne answer me daal lenge.
* Uske baad agar hum usi floor ke kisi dusre element (jaise right child) par jaate hain, toh hum use ignore kar denge kyunki us floor ka pehla banda pehle hi book ho chuka hai.

### Sawaal: Hume kaise pata chalega ki hum kisi level par PEHLI BAAR aaye hain?

Bohot simple hai! Hum apne final answer vector/list ka **size** check karenge.

> Agar hamara `current_level == answer_vector.size()`, iska matlab hum is level par **pehli baar** aaye hain!

---

## 2. Step-by-Step Dry Run

Chalo is tree par magic lagate hain:

```text
          1         
        /   \
       2     3      
        \     
         4     

```

* **Shuruat me:** `ans = []` (size = 0). Hum Root node `1` par hain jo **Level 0** par hai.

1. **Node 1 (Level 0):**
* Kya `level (0) == ans.size (0)`? **Haan!**
* `1` ko answer me daal do $\rightarrow$ `ans = [1]` (Ab size ho gaya 1).
* Ab left call bhejo: `Node 2` par, level badha kar `0 + 1 = 1`.


2. **Node 2 (Level 1):**
* Kya `level (1) == ans.size (1)`? **Haan!**
* `2` ko answer me daal do $\rightarrow$ `ans = [1, 2]` (Ab size ho gaya 2).
* Ab left call bhejo: Left NULL hai, toh wapas mud gaya.
* Ab right call bhejo: `Node 4` par, level badha kar `1 + 1 = 2`.


3. **Node 4 (Level 2):**
* Kya `level (2) == ans.size (2)`? **Haan!**
* `4` ko answer me daal do $\rightarrow$ `ans = [1, 2, 4]` (Ab size ho gaya 3).
* Iske left-right dono NULL hain, toh ye wapas laut gaya Node 2 par, aur fir Node 2 se wapas Node 1 par.


4. **Node 1 se Right Call gayi: Node 3 (Level 1):**
* Kya `level (1) == ans.size (3)`? **NAHI!** (1 is not equal to 3).
* Iska matlab Level 1 ka koi banda (`2`) pehle hi answer me baith chuka hai. Toh hum `3` ko skip kar denge!



Poora traversal khatam, aur bina kisi jhanjhat ke final answer mil gaya: **`1, 2, 4`**

---

## 3. C++ Implementation (Optimized DFS Code)

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Helper Function
void getLeftView(Node* root, int level, vector<int>& ans) {
    // Base Case: Khali node par wapas laut jao
    if (root == nullptr) return;

    // GOLDEN RULE: Agar level aur vector ka size barabar hai,
    // matlab is level par hum PEHLI BAAR aaye hain!
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // Pehle LEFT subtree ko call karo (taaki left wale pehle ginte hain)
    getLeftView(root->left, level + 1, ans);

    // Phir RIGHT subtree ko call karo
    getLeftView(root->right, level + 1, ans);
}

// Main function to return Left View
vector<int> leftView(Node* root) {
    vector<int> ans;
    // Shuruat karenge Root node se, jo Level 0 par hai
    getLeftView(root, 0, ans);
    return ans;
}

int main() {
    // Same upar wala tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    vector<int> result = leftView(root);

    cout << "Optimized Recursive Left View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Optimized Recursive Left View: 1 2 4 

```

---

## 4. Right View nikalna ho toh? (Ek Teer Se Do Shikaar)

Bhai, is recursion ka sabse bada maza pata hai kya hai? Agar interviewer ne bol diya, *"Chalo beta, left view toh ho gaya, ab **Right View** karke dikhao."* Tumhe code me kuch badalna hi nahi hai! Bas function calls ka order ulta kar dena hai: **Pehle Right call bhej dena, fir Left call bhej dena.**

```cpp
// RIGHT VIEW ke liye bas ye order kar do:
getRightView(root->right, level + 1, ans); // Pehle Right
getRightView(root->left, level + 1, ans);  // Phir Left

```

Kyunki pehle right call jayegi, toh har level ka sabse right-most element pehle save ho jayega!

---

## 5. Complexity Breakdown

* **Time Complexity:** **$O(N)$** kyunki hum standard preorder traversal ki tarah tree ke har ek node par ek hi baar ja rahe hain.
* **Space Complexity:** **$O(H)$** jahan $H$ tree ki height hai. Humne koi extra Queue use nahi ki, bas recursion ka internal call stack use ho raha hai. Isliye ye brute force (Queue wale) approach se zyada optimized mana jata hai!



Bhai, pichli baar humne **Left View** ka optimized recursive (DFS) tareeka samjha tha jo ki ek dam solid hai.

Ab main samajh gaya ki tum har concept ki sabse best aur fast approach dhoodh rahe ho. Toh aao, isi logic ke doosre bhai, yaani **Right View of a Binary Tree** ka sabse khatarnak aur optimized recursive tarika poori detail me samajhte hain, taaki tumhara dono concepts par ek dam master level hold ho jaye!

---

## 1. Right View ka Core Intuition

Left view me hamara rule tha ki har floor (level) ka sabse pehla element uthao jab tum left se dekh rahe ho.

**Right View** me kya hoga? Jab tum tree ke bilkul **daayein (right) taraf khade hokar** dekhoge, toh tumhe har ek floor (level) ka **sabse aakhiri (rightmost) node** sabse pehle dikhega! Baaki saare nodes uske peeche chhup jayenge.

### Magic Pattern:

Hum yahan bhi **Preorder Traversal** ka use karenge, par thoda twist karke. Normal preorder hota hai `Root -> Left -> Right`. Hum yahan chalenge **`Root -> Right -> Left`** (Modified Preorder).

Kyunki hum pehle **Right** ki taraf kood rahe hain, toh hum jis naye floor par kadam rakhenge, wahan ka sabse right-most banda hume sabse pehle mil jayega!

Wahi golden rule yahan bhi lagega:

> Agar `current_level == answer_vector.size()`, iska matlab hum is level par **pehli baar** aaye hain, aur kyunki hum right se aa rahe hain, toh ye banda right-most hi hoga! Use turant save kar lo.

---

## 2. Step-by-Step Dry Run

Chalo is tree ko right side se dekhte hain:

```text
          1         <-- Level 0 (Pehli baar aaye, 1 ko liya)
        /   \
       2     3      <-- Level 1 (Right call pehle gayi, 3 ko liya)
      /       \
     4         5    <-- Level 2 (Right call se 5 par aaye, 5 ko liya)

```

* **Shuruat me:** `ans = []` (size = 0). Start kiya Node `1` se (Level 0).

1. **Node 1 (Level 0):**
* `level (0) == ans.size (0)` $\rightarrow$ **True!**
* `ans = [1]` (size ho gaya 1).
* Ab rule ke mutabik pehle **Right Call** bhejenge $\rightarrow$ `Node 3` par, level `1`.


2. **Node 3 (Level 1):**
* `level (1) == ans.size (1)` $\rightarrow$ **True!**
* `ans = [1, 3]` (size ho gaya 2).
* Phir se pehle **Right Call** bheji $\rightarrow$ `Node 5` par, level `2`.


3. **Node 5 (Level 2):**
* `level (2) == ans.size (2)` $\rightarrow$ **True!**
* `ans = [1, 3, 5]` (size ho gaya 3).
* Iske aage koi bachhe nahi hain, recursion wapas lautega Node 3 par, fir Node 1 par.


4. **Node 1 se ab Left Call jayegi $\rightarrow$ Node 2 (Level 1):**
* Kya `level (1) == ans.size (3)`? **Nahi!** (1 is not equal to 3).
* Kyunki Level 1 par `3` pehle hi apni seat book kar chuka hai, hum `2` ka data skip kar denge.
* `Node 2` se right call khali hai, left call gayi `Node 4` (Level 2) par.


5. **Node 4 (Level 2):**
* Kya `level (2) == ans.size (3)`? **Nahi!**
* Level 2 par `5` pehle se baitha hai, toh `4` ko bhi skip kiya.



Traversal poora khatam! Final Right View mila: **`1, 3, 5`**

---

## 3. C++ Implementation (Optimized DFS Code)

Bina kisi queue ke, sirf internal stack frames ka use karke ek dam neat and clean code:

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Optimized Recursive Helper Function
void getRightView(Node* root, int level, vector<int>& ans) {
    // Base Case
    if (root == nullptr) return;

    // Agar hum is level par pehli baar aaye hain
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // INTERVIEW CRITICAL POINT: Pehle RIGHT call bhejni hai!
    getRightView(root->right, level + 1, ans);

    // Uske baad LEFT call bhejni hai
    getRightView(root->left, level + 1, ans);
}

// Main function for Right View
vector<int> rightView(Node* root) {
    vector<int> ans;
    getRightView(root, 0, ans);
    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);

    cout << "Optimized Recursive Right View hai: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Optimized Recursive Right View hai: 1 3 5 

```

---

## 4. Complexity Analysis

Ye approach kyun sabse best hai, iske peeche ka reason iska space utilization hai:

* **Time Complexity:** **$O(N)$** kyunki chahe kuch bhi ho, hum tree ke saare nodes ko ek baar visit zaroor kar rahe hain taaki koi chhipa hua lamba right child na chhoot jaye.
* **Space Complexity:** **$O(H)$** (jahan $H$ tree ki height hai). Humne koi extra queue ya hashmap nahi banaya, sirf recursion ka stack call use ho raha hai. Agar tree perfectly balanced hai toh space sirf $O(\log N)$ lagegi!



Bhai, tumne Binary Tree ke lagbhag saare basic aur interview-favourite patterns ek dam maze me seekh liye hain!

Ab jab tumne **Left View** aur **Right View** tak ka safar taiyar kar liya hai, toh interviewers iske baad tumhara level up karne ke liye kuch bohot hi shaandar **Follow-up Questions** poochte hain.

Agar tumne in baaki bache 4 views par pakad bana li, toh samajho tumhara **Tree Views aur Traversals** ka chapter poora 100% khatam!

---

## 1. Top View of a Binary Tree (Agla Level Challenge)

Left aur Right view me toh hum floor-by-floor (horizontal lines) dekh rahe hain. **Top View** me socho ki tum ek helicopter me baith kar tree ko upar se dekh rahe ho!

```text
          1         
        /   \
       2     3      
      / \   / \
     4   5 6   7    

```

Jab tum upar se dekhoge, toh tumhe `4`, `2`, `1`, `3`, `7` dikhenge. Lekin jo beech wale nodes hain (`5` aur `6`), wo `1` ke bilkul neeche chhup jayenge.

* **Iska Concept:** Isme hum **Vertical Lines** (yaani X-axis) ka concept use karte hain. Root ko hum `0` maante hain, left jaane par `-1` aur right jaane par `+1`.
* **Kaise Solve Karein:** Isme hum **Queue (BFS)** ke saath ek **Map (or Hashmap)** ka use karte hain taaki har vertical line ka jo sabse pehla element dikhe, use lock kar dein.

---

## 2. Bottom View of a Binary Tree

Ye bilkul Top View ka ulta hai. Socho tum zameen par let kar tree ko neeche se upar dekh rahe ho.

* **Iska Concept:** Isme bhi vertical lines (`-1`, `0`, `+1`) ka khel hota hai.
* **Twist:** Top view me hum har vertical line ka *pehla* element lete hain. Bottom view me hum har vertical line ka **sabse aakhiri (latest) element** lete hain, kyunki upar wale nodes neeche walon ke peeche chhup jaate hain.
* **Kaise Solve Karein:** BFS chalate raho, aur map me us vertical line ki value ko baar-baar overwrite (update) karte jao. End me map me sirf sabse neeche wale nodes bachenge!

---

## 3. Boundary Traversal (Interviewers ka Maha-Favourite)

Ye sawaal Amazon aur OYO ka bohot zyada favourite hai. Wo bolenge: *"Mujhe is tree ki poori boundary (deewar) par ghoom kar saare nodes la kar do."*

Is sawaal ko hum **3 hisson me tod kar** solve karte hain:

1. **Left Boundary:** Root se shuru karke left-left jao aur saare nodes print karo (leaf nodes ko chhod kar).
2. **Leaf Nodes:** Ek normal traversal (jaise Preorder ya Postorder) chalao aur sirf un nodes ko print karo jinke left-right NULL hain.
3. **Right Boundary:** Root ke right se shuru karke neeche jao, saare nodes nikaalo, aur unhe **ulta (reverse)** karke answer me jodo (taaki boundary clockwise ya anti-clockwise barabar chale).

---

## 4. Diagonal Traversal

Isme tree ko seedha ya khada nahi, balki **tircha (diagonal)** dekha jata hai, jaise chessboard par camel (oont) chalta hai.

```text
          1         -- Diagonal 1: (1, 3, 7)
        /   \
       2     3      -- Diagonal 2: (2, 5, 6)
      /       \
     4         7    -- Diagonal 3: (4)

```

* **Iska Concept:** Isme hum slope nikalte hain. Jab bhi tum **Right** jaate ho, tum same diagonal par rehte ho. Jab tum **Left** jaate ho, tab diagonal ka level badal jaata hai.
* **Kaise Solve Karein:** Ek Queue lo, node ko nikaalo, aur jab tak uska `right` zinda hai, use print karte hue aage badhte jao, aur unke `left` bachhon ko queue me sambhal kar rakhte jao.

---

Bhai, batao in 4 follow-ups me se abhi kaun sa topic bilkul detail me, dry run aur code ke saath shuru karein?


Bhai, humne Right View ka optimized recursive (DFS) tareeka toh dekh liya tha. Lekin interviews me kai baar interviewer jaan-bujhkar bolta hai: **"Mujhe iska Iterative tarika dikhao Queue ka use karke."** Kyunki Queue wala tarika standard **Level Order Traversal** par chalta hai, iska intuition bohot clear aur visual hota hai. Aao Queue ka use karke **Right View** nikalne ka poora concept, logic, dry run aur C++ code bilkul detail me samajhte hain.

---

## 1. Core Logic (Queue me twist kaise karein?)

Right View ka simple rule hume pata hai: **"Har ek floor (level) ka sabse aakhiri (rightmost) element hi dikhayi dega."**

Jab hum **Level Order Traversal Line-by-Line** chalate hain, toh hum ek baar me ek poore floor ke nodes ko process karte hain.

* Maano kisi level par 3 nodes hain, toh loop `i = 0` se `i = 2` tak chalega.
* Is loop me jo sabse aakhiri node hoga (yaani jab `i == size - 1` hoga), wahi us level ka **rightmost node** hoga!
* Hum bas us aakhiri node ka data uthayenge aur apne answer me push kar denge.

---

## 2. Step-by-Step Dry Run

Chalo is tree par Queue wala logic lagate hain:

```text
          1         <-- Level 0 (Aakhiri node: 1)
        /   \
       2     3      <-- Level 1 (Aakhiri node: 3)
      / \     \
     4   5     6    <-- Level 2 (Aakhiri node: 6)

```

Hum ek **Queue `q**` lenge aur ek **`ans` vector** lenge.

* **Shuruat me:** Queue me root daala $\rightarrow$ `[Queue: 1]`, `ans = []`
* **Level 0:**
* Queue ka size check kiya: `size = 1`. Loop chalega `i = 0` tak.
* `i = 0` par node `1` ko pop kiya.
* **Twist Check:** Kya ye is level ka aakhiri node hai? Haan, kyunki `i == size - 1` ($0 == 1 - 1$). Toh `1` ko answer me daal diya $\rightarrow$ `ans = [1]`.
* `1` ke bachhon (`2`, `3`) ko queue me push kiya $\rightarrow$ `[Queue: 2, 3]`.


* **Level 1:**
* Queue ka size check kiya: `size = 2`. Loop chalega `i = 0` aur `i = 1`.
* `i = 0`: Node `2` ko pop kiya. Ye aakhiri nahi hai, toh ise print nahi karenge. Iske bachhon (`4`, `5`) ko push kiya $\rightarrow$ `[Queue: 3, 4, 5]`.
* `i = 1`: Node `3` ko pop kiya. **Twist Check:** Kya ye aakhiri hai? Haan ($1 == 2 - 1$). Toh `3` ko answer me daal diya $\rightarrow$ `ans = [1, 3]`. Iska bachha (`6`) push kiya $\rightarrow$ `[Queue: 4, 5, 6]`.


* **Level 2:**
* Queue ka size check kiya: `size = 3`. Loop chalega `i = 0` se `2` tak.
* `i = 0`: Node `4` ko pop kiya (kuch nahi kiya).
* `i = 1`: Node `5` ko pop kiya (kuch nahi kiya).
* `i = 2`: Node `6` ko pop kiya. **Twist Check:** Haan, ye aakhiri hai ($2 == 3 - 1$). `6` ko answer me daala $\rightarrow$ `ans = [1, 3, 6]`.



Queue khali ho gayi! Final Right View mil gaya: **`1, 3, 6`**

---

## 3. C++ Implementation (Queue Approach)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the Right View using Queue (BFS)
vector<int> rightViewQueue(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size(); // Current level par kitne nodes hain

        // Is level के saare nodes ko process karo
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            // CORE LOGIC: Agar ye is level ka AAKHIRI (rightmost) element hai
            if (i == size - 1) {
                ans.push_back(curr->data);
            }

            // Bachhon ko queue me daalo normal tarike se (Pehle Left, fir Right)
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
    }
    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<int> result = rightViewQueue(root);

    cout << "Queue approach se Tree ka Right View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Queue approach se Tree ka Right View: 1 3 6 

```

---

## 4. Complexity Analysis

* **Time Complexity:** **$O(N)$** kyunki hum level order traversal kar rahe hain aur tree ke har ek node par ek baar visit kar rahe hain.
* **Space Complexity:** **$O(N)$** (ya exact bole toh $O(W)$ jahan $W$ tree ki maximum width hai). Perfect balanced tree me aakhiri level par lagbhag $N/2$ nodes hote hain, jo worst case me queue me store honge.

Bhai, dono approaches (DFS aur BFS) ab tumhare haath me hain. Batao ab kisi follow-up (jaise Top View ya Boundary Traversal) ka detailed explanation shuru karein?



Bhai, tumne Queue (BFS) wala tarika toh ek dam mast samajh liya. Ab aao **Right View ka sabse behtareen aur optimized Recursive (DFS) Approach** samajhte hain. Interviews me agar tum pehle Queue wala code likhoge, toh interviewer ka agla counter-question yahi hoga: *"Bhai, bina kisi extra queue ke space ko $O(H)$ karke dikhao."*

Aao iska dimaag kholne wala intuition, dry run aur code poori detail me samajhte hain.

---

## 1. Core Intuition (Vector Size ka Khel)

Recursion se Right View nikalne ke liye hum **Preorder Traversal** ka ek ulta roop use karte hain. Normal preorder hota hai `Root -> Left -> Right`. Hum yahan chalenge **`Root -> Right -> Left`** (Modified Preorder).

Kyunki hum pehle **Right** ki taraf kood rahe hain, toh hum jis bhi naye floor (level) par kadam rakhenge, wahan ka sabse right-most banda hume sabse pehle mil jayega!

### Sawaal: Hume kaise pata chalega ki hum kisi floor par PEHLI BAAR aaye hain?

Iska ek dam khatarnak aur simple hack hai: Hum apne final answer vector/list ka **size** check karenge.

> Agar hamara `current_level == answer_vector.size()`, iska matlab hum is level par **pehli baar** aaye hain! Aur kyunki hum right side se ghoomte hue aa rahe hain, toh ye pehla banda pakka rightmost node hi hoga.

---

## 2. Step-by-Step Dry Run

Chalo is tree ko right side se dekhte hain:

```text
          1         <-- Level 0 (Pehli baar aaye, 1 ko liya)
        /   \
       2     3      <-- Level 1 (Right call pehle gayi, 3 ko liya)
      /       \
     4         5    <-- Level 2 (Right call se 5 par aaye, 5 ko liya)

```

* **Shuruat me:** `ans = []` (size = 0). Start kiya Node `1` se jo **Level 0** par hai.

1. **Node 1 (Level 0):**
* Kya `level (0) == ans.size (0)`? **Haan!**
* `ans = [1]` (size ho gaya 1).
* Ab rule ke mutabik pehle **Right Call** bhejenge $\rightarrow$ `Node 3` par, level `1`.


2. **Node 3 (Level 1):**
* Kya `level (1) == ans.size (1)`? **Haan!**
* `ans = [1, 3]` (size ho gaya 2).
* Phir se pehle **Right Call** bheji $\rightarrow$ `Node 5` par, level `2`.


3. **Node 5 (Level 2):**
* Kya `level (2) == ans.size (2)`? **Haan!**
* `ans = [1, 3, 5]` (size ho gaya 3).
* Iske aage koi bachhe nahi hain, recursion wapas lautega Node 3 par, fir Node 1 par.


4. **Node 1 se ab Left Call jayegi $\rightarrow$ Node 2 (Level 1):**
* Kya `level (1) == ans.size (3)`? **Nahi!** (1 is not equal to 3).
* Kyunki Level 1 par `3` pehle hi apni seat book kar chuka hai, hum `2` ka data skip kar denge.
* `Node 2` se right call khali hai, left call gayi `Node 4` (Level 2) par.


5. **Node 4 (Level 2):**
* Kya `level (2) == ans.size (3)`? **Nahi!**
* Level 2 par `5` pehle se baitha hai, toh `4` ko bhi skip kiya.



Traversal poora khatam! Final Right View mila: **`1, 3, 5`**

---

## 3. C++ Implementation (Optimized DFS Code)

Bina kisi extra queue ke, sirf internal stack frames ka use karke ek dam clean code:

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Optimized Recursive Helper Function
void getRightView(Node* root, int level, vector<int>& ans) {
    // Base Case: Khali node par wapas mud jao
    if (root == nullptr) return;

    // GOLDEN RULE: Agar level aur vector ka size barabar hai,
    // matlab is level par hum PEHLI BAAR aaye hain!
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // INTERVIEW CRITICAL POINT: Pehle RIGHT call bhejni hai!
    getRightView(root->right, level + 1, ans);

    // Uske baad LEFT call bhejni hai
    getRightView(root->left, level + 1, ans);
}

// Main function for Right View
vector<int> rightView(Node* root) {
    vector<int> ans;
    // Shuruat karenge Root node se, jo Level 0 par hai
    getRightView(root, 0, ans);
    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> result = rightView(root);

    cout << "Optimized Recursive Right View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Optimized Recursive Right View: 1 3 5 

```

---

## 4. Complexity Analysis

Ye approach kyun Queue wale se better mana jata hai? Iske space complexity ke reason se:

* **Time Complexity:** **$O(N)$** kyunki chahe kuch bhi ho, hum tree ke saare nodes ko ek baar visit zaroor kar rahe hain taaki koi chhipa-hua lamba right child na chhoot jaye.
* **Space Complexity:** **$O(H)$** (jahan $H$ tree ki height hai). Humne koi extra queue ya array nahi banaya, sirf recursion ka stack space use ho raha hai. Agar tree perfectly balanced hai toh space sirf $O(\log N)$ lagegi, jo ki Queue wale $O(N)$ se bohot behtar hai!


Bhai, **Top View of a Binary Tree** tree views ka sabse solid aur dimaag kholne wala sawaal hai. Agar tumne ise dhang se samajh liya, toh iska judwaa bhai **Bottom View** tum agle 2 minute me khud bana loge!

**Top View kya hota hai?** Socho tum ek helicopter me baith kar tree ko upar se dekh rahe ho. Jab tum upar se dekhoge, toh tumhe har vertical line (column) ka jo **sabse upar wala (pehla) node** hoga, sirf wahi dikhega. Uske neeche waale saare nodes chhup jayenge.

### Ek Example se samjho:

```text
          1         
        /   \
       2     3      
      / \   / \
     4   5 6   7    

```

* Agar tum upar se dekhoge, toh `1` ke neeche `5` aur `6` dono chhup jayenge.
* Tumhe line se kya dikhega? **`4, 2, 1, 3, 7`**

---

## 1. Core Logic (Vertical Coordinates aur Map ka Khel)

Ise solve karne ke liye hume geometry ki tarah **X-axis (Vertical Columns)** ka dimaag lagana padega:

* Hum Maante hain ki **Root Node (1)** ka coordinate **`0`** hai.
* Agar hum **Left** jaayenge, toh coordinate me se `-1` karenge (yaani Node 2 ka coordinate `-1` ho gaya, Node 4 ka `-2`).
* Agar hum **Right** jaayenge, toh coordinate me `+1` karenge (yaani Node 3 ka coordinate `+1` ho gaya, Node 7 ka `+2`).

$$\text{Left Child Coordinate} = \text{Parent Coordinate} - 1$$

$$\text{Right Child Coordinate} = \text{Parent Coordinate} + 1$$

### Hume Queue aur Map dono kyun chahiye?

1. **Queue (BFS):** Hum top view me top-to-bottom ghoomna chahte hain (Level Order Traversal). Isse fayda ye hoga ki hume har vertical line ka sabse upar wala node pehle milega.
2. **Map (or Hashmap):** Hum map me store karenge `[Coordinate, Node_Data]`. Kyunki hum upar se neeche aa rahe hain, toh **agar koi coordinate map me pehle se maujood hai, toh hum use update nahi karenge**, kyunki upar wala banda neeche wale ko chhipa chuka hai!

---

## 2. Step-by-Step Queue Dry Run

Chalo upar wale tree par algorithm chalate hain.

* **Queue me hum Pair store karenge:** `{Node*, Coordinate}`
* **Map shuru me khali hai:** `{}`

1. **Shuruat me:** Queue me root daala $\rightarrow$ `[Queue: {1, 0}]`
2. **Step 1 (Node 1, Coord 0):**
* Queue se nikaala `{1, 0}`.
* Kya map me `0` key hai? Nahi hai! Toh map me daal do $\rightarrow$ `Map: {0 -> 1}`
* Iske bachhon ko queue me daalo coordinate update karke: Left `{2, -1}` aur Right `{3, 1}`.
* `[Queue: {2, -1}, {3, 1}]`


3. **Step 2 (Node 2, Coord -1):**
* Queue se nikaala `{2, -1}`.
* Kya map me `-1` hai? Nahi hai! Daal do $\rightarrow$ `Map: {0 -> 1, -1 -> 2}`
* Iske bachhon ko daalo: Left `{4, -2}` aur Right `{5, 0}`.
* `[Queue: {3, 1}, {4, -2}, {5, 0}]`


4. **Step 3 (Node 3, Coord 1):**
* Queue se nikaala `{3, 1}`.
* Kya map me `1` hai? Nahi hai! Daal do $\rightarrow$ `Map: {0 -> 1, -1 -> 2, 1 -> 3}`
* Iske bachhon ko daalo: Left `{6, 0}` aur Right `{7, 2}`.
* `[Queue: {4, -2}, {5, 0}, {6, 0}, {7, 2}]`


5. **Step 4 (Node 4, Coord -2):**
* Map me `-2` nahi hai, daal do $\rightarrow$ `Map: {-2 -> 4, ...}`


6. **Step 5 (Node 5, Coord 0):**
* Queue se nikaala `{5, 0}`.
* **TWIST CHECK:** Kya map me `0` pehle se hai? **Haan!** `0 -> 1` pehle se baitha hai. Iska matlab Node 1 ne Node 5 ko upar se chhipa diya hai. Toh hum ise map me **nahi daalenge (skip karenge)**.


7. **Step 6 (Node 6, Coord 0):**
* Iska bhi coordinate `0` hai, map me pehle se hai, toh ise bhi skip karenge.


8. **Step 7 (Node 7, Coord 2):**
* Map me `2` nahi hai, daal do $\rightarrow$ `Map: {... , 2 -> 7}`



Ab map ke keys ko sorted order me (`-2` se `2` tak) print kar do: **`4, 2, 1, 3, 7`**.

---

## 3. C++ Implementation (Queue + Map Approach)

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get Top View of a Binary Tree
vector<int> topView(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    // Map ordered rakhenge taaki coordinates automatic sorted order me milein (-2, -1, 0, 1, 2)
    map<int, int> topNodeMap; // {Coordinate, Node_Data}
    
    // Queue me Pair store karenge: {Node, Vertical_Coordinate}
    queue<pair<Node*, int>> q;
    
    // Root ko coordinate 0 ke saath push kiya
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        
        Node* curr = it.first;
        int line = it.second;

        // CORE LOGIC: Agar is coordinate ka node map me PEHLE SE NAHI HAI,
        // tabhi use map me daalo (kyunki upar wala pehle aayega BFS me)
        if (topNodeMap.find(line) == topNodeMap.end()) {
            topNodeMap[line] = curr->data;
        }

        // Left me jao toh Line - 1
        if (curr->left != nullptr) {
            q.push({curr->left, line - 1});
        }
        // Right me jao toh Line + 1
        if (curr->right != nullptr) {
            q.push({curr->right, line + 1});
        }
    }

    // Map se data nikaal kar final answer vector me daalo
    for (auto it : topNodeMap) {
        ans.push_back(it.second);
    }
    
    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topView(root);

    cout << "Tree ka Top View hai: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Tree ka Top View hai: 4 2 1 3 7 

```

---

## 4. Complexity Analysis

* **Time Complexity:** **$O(N \log N)$** agar hum standard `std::map` use kar rahe hain, kyunki map me har insertion $\log N$ time leta hai sorted order maintain karne ke liye. (Agar `unordered_map` use karke min/max track karoge toh ye $O(N)$ bhi ho sakta hai).
* **Space Complexity:** **$O(N)$** kyunki worst case me queue aur map dono me tree ke saare nodes ka data store hoga.

> 💡 **Bhai ek Bonus Mazedaar Baat:** Agar tumhe koi bole ki ab **Bottom View** banao, toh bas pata hai kya badalna hai? Upar waale code me se `if (topNodeMap.find(line) == topNodeMap.end())` wali condition hata dena! Seedha `topNodeMap[line] = curr->data;` likh dena. Isse kya hoga? Niche waale nodes upar waalon ko overwrite karte chale jayenge aur aakhiri me tumhe sabse neeche waale dikhenge!



Bhai, ek dam behtareen sawal pucha hai! `std::map` internally **Red-Black Tree** use karta hai jisse har insertion me $O(\log N)$ ka time lagta hai, aur interviews me interviewer aksar bolte hain: *"Mujhe `map` use nahi karna, isko optimize karo taaki Time Complexity $O(N)$ ho jaye."*

Kyoki hume coordinates ko sorted order me chahiye, hum array ya vector ka use bilkul kar sakte hain! Bas ek chhoti si dikkat hai: **Array me negative indices (`-1`, `-2`) nahi hote.** Aao samajhte hain ki bina map ke, array se negative index ki dikkat ko kaise khatam karenge aur pure code ko $O(N)$ me kaise le aayenge.

---

## 1. Array Use Karne ka Core Logic (The Offset Trick)

Maano hamara tree maximum kitna left ya right ja sakta hai? Worst case me agar tree ek seedhi line me ho, toh coordinate max to max `-N` se lekar `+N` tak ja sakta hai. Yaani total coordinates ki range ho sakti hai $2N + 1$.

Hum kya karenge:

1. Ek bada sa array (ya `std::vector`) bana lenge jiska size ho **$2N + 1$** (ya safe side ke liye ek bada size jaise 2005).
2. Hum array ke **beech waale index (yaani $N$) ko apna zero coordinate (`0`)** maan lenge. Is dimaag lagane ko programming me **Offset** bolte hain.
3. Agar kisi node ka coordinate `X` hai, toh array me uski sahi jagah index **`X + N`** par hogi!
* Agar `X = 0` (Root), toh array index $= 0 + N = N$.
* Agar `X = -1` (Left child), toh array index $= -1 + N = N - 1$. (Negative index ki dikkat khatam!)
* Agar `X = +1` (Right child), toh array index $= 1 + N = N + 1$.



### Pehla element kaise track karein?

Hum array ko shuruat me `-1` se bhar denge. Jab hum BFS chalayenge, agar `array[X + N] == -1` milega, iska matlab is vertical line par hum **pehli baar** aaye hain, toh wahan value daal denge. Agar pehle se koi value baithi hai, toh ignore kar denge.

---

## 2. Min aur Max Coordinates Track Karna

Map ka fayda ye tha ki wo keys ko automatic sort kar deta tha. Array me hume kaise pata chalega ki kis index se print karna shuru karein aur kaha tak jayein?

Hum BFS chalaate waqt do variables maintain karenge: `min_coord` aur `max_coord`.

* Jab bhi koi naya coordinate milega, hum unhe update karte chalenge.
* Aakhiri me hum loop chalayenge `min_coord` se `max_coord` tak, aur array se answers nikaal lenge.

---

## 3. C++ Implementation ($O(N)$ Array Approach)

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> topViewUsingArray(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    // Maan lete hain maximum nodes 1000 ho sakte hain, toh array size 2005 safe hai
    const int OFFSET = 1000; 
    vector<int> topViewArray(2005, -1); // Shuruat me saare indices ko -1 kar diya

    // Min aur Max track karne ke liye variables
    int min_coord = 0;
    int max_coord = 0;

    // Queue me store karenge: {Node, Coordinate}
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        Node* curr = it.first;
        int coord = it.second;

        // Min aur Max coordinates ko update karo
        min_coord = min(min_coord, coord);
        max_coord = max(max_coord, coord);

        // OFFSET TRICK: Array index nikalne ke liye coordinate me OFFSET jod do
        int arrayIndex = coord + OFFSET;

        // CORE LOGIC: Agar is index par abhi tak koi nahi aaya (-1 hai), toh data daal do
        if (topViewArray[arrayIndex] == -1) {
            topViewArray[arrayIndex] = curr->data;
        }

        // Left child ke liye coordinate - 1
        if (curr->left != nullptr) {
            q.push({curr->left, coord - 1});
        }
        // Right child ke liye coordinate + 1
        if (curr->right != nullptr) {
            q.push({curr->right, coord + 1});
        }
    }

    // Ab hme sorted order me data chahiye, toh loop chalayenge min_coord se max_coord tak
    for (int i = min_coord; i <= max_coord; i++) {
        ans.push_back(topViewArray[i + OFFSET]);
    }

    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = topViewUsingArray(root);

    cout << "Array use karke Tree ka Top View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Array use karke Tree ka Top View: 4 2 1 3 7 

```

---

## 4. Complexity Me Kitna Fayda Hua?

* **Time Complexity:** **$O(N)$** ho gayi! Kyunki array me index par jaana aur value daalna $O(1)$ hota hai, jabki map me $O(\log N)$ lag raha tha. Loop bhi sirf `min_coord` se `max_coord` tak chal raha hai jo max to max $N$ steps lega. Interviewer ye dekhte hi khush!
* **Space Complexity:** **$O(N)$** (Array ka size fix hai, aur queue me nodes store ho rahe hain).



Bhai, Top View ko **Recursive (DFS)** tarike se karna thoda tricky hota hai, lekin interviews me ye aapka dimaag check karne ke liye sabse zyada pucha jaata hai.

Aao iska concept aur logic ek dam mast dhang se samajhte hain.

---

## 1. Recursion Me Dikkat Kya Hai? (The Challenge)

Jab hum Queue (BFS) use kar rahe the, toh hum top-to-bottom chal rahe the, isliye jo node pehle mila, wo pakka upar wala hi tha.

Lekin **Recursion (DFS)** deep jaata hai. Ho sakta hai ki recursion left side me bohot neeche chala jaye aur kisi coordinate par neeche wale node ko pehle ginn le, jabki upar wala node baad me mile!

### Iska Solution kya hai?

Hume har node ke **Coordinate (Horizontal Distance)** ke saath-saath uske **Level (Height/Depth)** ka bhi hisaab rakhna padega!

Hum ek map ya array banayenge jo store karega:
`Coordinate -> {Node_Data, Level}`

**Golden Rule:**

> Agar hum kisi coordinate par pehli baar aaye hain, toh use map me daal denge.
> Agar hum us coordinate par pehle bhi aa chuke hain, toh hum check karenge: *Kya hamara current node purane wale node se UPAR hai (yaani current level < purana level)?* Agar haan, toh hum purane node ko hata kar naye node ko daal denge!

---

## 2. Step-by-Step Dry Run

Chalo is tree par dhyan dete hain:

```text
          1         (Coord: 0, Level: 0)
        /   \
       2     3      (2 -> Coord: -1, Level: 1 | 3 -> Coord: 1, Level: 1)
        \     
         5          (Coord: 0, Level: 2)

```

* **Shuruat me:** Map khali hai `{}`.

1. **Node 1 (Coord: 0, Level: 0):**
* Map me `0` coordinate khali hai. Daal do $\rightarrow$ `Map: {0 -> {data: 1, level: 0}}`.
* Left call gayi $\rightarrow$ Node 2 par.


2. **Node 2 (Coord: -1, Level: 1):**
* Map me `-1` khali hai. Daal do $\rightarrow$ `Map: {0 -> {1, 0}, -1 -> {2, 1}}`.
* Right call gayi $\rightarrow$ Node 5 par.


3. **Node 5 (Coord: 0, Level: 2):**
* Map me `0` coordinate par pehle se `1` baitha hai jiska level `0` hai.
* Hum compare karenge: *Kya Node 5 ka level (2) chota hai Node 1 ke level (0) se?* **Nahi!** ($2 < 0$ galat hai). Iska matlab Node 5 neeche hai, toh hum ise skip kar denge.
* Recursion wapas lauta.


4. **Node 3 (Coord: 1, Level: 1):**
* Map me `1` khali hai. Daal do $\rightarrow$ `Map: {... , 1 -> {3, 1}}`.



Saare nodes khatam! Map se data nikaalenge toh line se milega: **`2, 1, 3`**.

---

## 3. C++ Implementation (Recursive DFS Approach)

Hum pichle waale array/vector optimization ko hi use karenge taaki time complexity $O(N)$ rahe, bas andar ka logic pairs ke saath chalega.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Helper Function
void fillTopView(Node* root, int coord, int level, int OFFSET, vector<pair<int, int>>& topViewArray, int& min_coord, int& max_coord) {
    if (root == nullptr) return;

    // Min aur Max coordinates ko sath-sath track karo
    min_coord = min(min_coord, coord);
    max_coord = max(max_coord, coord);

    int arrayIndex = coord + OFFSET;

    // CORE LOGIC:
    // Case 1: Agar is coordinate par abhi tak koi nahi aaya (-1 hai)
    if (topViewArray[arrayIndex].first == -1) {
        topViewArray[arrayIndex] = {root->data, level};
    }
    // Case 2: Agar koi pehle se baitha hai, par current node uske UPAR hai (level chota hai)
    else if (level < topViewArray[arrayIndex].second) {
        topViewArray[arrayIndex] = {root->data, level};
    }

    // Left child ke liye: coord - 1, level + 1
    fillTopView(root->left, coord - 1, level + 1, OFFSET, topViewArray, min_coord, max_coord);

    // Right child ke liye: coord + 1, level + 1
    fillTopView(root->right, coord + 1, level + 1, OFFSET, topViewArray, min_coord, max_coord);
}

// Main function
vector<int> topViewRecursive(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    const int OFFSET = 1000;
    // Array me hum Pair store karenge: {Node_Data, Level_of_Node}
    // Shuruat me data ko -1 aur level ka pata nahi (0) rakh dete hain
    vector<pair<int, int>> topViewArray(2005, {-1, 0});

    int min_coord = 0, max_coord = 0;

    // Shuruat karenge Root se: Coord = 0, Level = 0
    fillTopView(root, 0, 0, OFFSET, topViewArray, min_coord, max_coord);

    // Answer vector me data transfer karo
    for (int i = min_coord; i <= max_coord; i++) {
        ans.push_back(topViewArray[i + OFFSET].first);
    }

    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    vector<int> result = topViewRecursive(root);

    cout << "Recursive DFS approach se Tree ka Top View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive DFS approach se Tree ka Top View: 2 1 3 

```

---

## 4. Complexity Analysis

* **Time Complexity:** **$O(N)$** kyunki array indexing $O(1)$ hai aur hum pure tree par sirf ek baar normal DFS chala rahe hain.
* **Space Complexity:** **$O(N)$** array ke liye aur $O(H)$ recursion ke stack space ke liye. Overall space efficiency iski bohot mast hai.



Bhai, **Bottom View of a Binary Tree** hamare pichle Top View ka bilkul judwaa bhai hai! Agar tumne Top View ka concept samajh liya hai, toh Bottom View toh tumhare liye baayein haath ka khel hai.

**Bottom View kya hota hai?** Socho tum zameen par let kar tree ko bilkul neeche se upar dekh rahe ho. Jab tum neeche se dekhoge, toh har vertical line (column) ka jo **sabse neeche wala (aakhiri) node** hoga, sirf wahi tumhari aankhon ke saamne aayega. Uske upar waale saare nodes uske peeche chhup jayenge.

### Ek Example se samjho:

```text
          1         
        /   \
       2     3      
      / \   / \
     4   5 6   7    

```

* Agar tum neeche se dekhoge, toh `1` ke upar `5` aur `6` aa chuke hain, isliye `1` chhup jayega.
* Tumhe line se kya dikhega? **`4, 2, 5, 6, 3, 7`** (Yahan `5` aur `6` dono dikhenge kyunki unke coordinates alag hain, par `1` unke peeche chhup gaya hai).

---

## 1. Core Logic (Top View se alag kaise hai?)

Concept bilkul wahi hai—**Vertical Coordinates (X-axis)** wala:

* **Root Node (1)** ka coordinate hota hai **`0`**.
* **Left** jaane par coordinate **`-1`** karte hain (`Parent - 1`).
* **Right** jaane par coordinate **`+1`** karte hain (`Parent + 1`).

### The Big Difference (The Overwriting Trick):

* **Top View me:** Hum har coordinate par aane waale **pehli node** ko lock kar dete the aur neeche waalon ko bhav nahi dete the.
* **Bottom View me:** Hum upar se neeche (Level Order BFS) ghoomte hain, aur hum chahte hain ki aakhiri waala node bache. Isliye hum coordinate ki value ko **baar-baar overwrite (update)** karte chale jaayenge! Jo node sabse aakhiri me aayega, wo upar waale ko duba dega.

---

## 2. Step-by-Step Queue Dry Run

Chalo upar waale tree par algorithm chala kar dekhte hain.

* **Queue (Pair):** `{Node*, Coordinate}`
* **Map (Ordered):** `{Coordinate -> Node_Data}` (ordered map automatic keys ko `-2, -1, 0...` me sort rakhta hai).

1. **Shuruat me:** Queue me root daala $\rightarrow$ `[Queue: {1, 0}]`, `Map: {}`
2. **Step 1 (Node 1, Coord 0):**
* `{1, 0}` ko nikaala. Map khali hai, daal do $\rightarrow$ `Map: {0 -> 1}`
* Bachhon ko push kiya: `{2, -1}` aur `{3, 1}`.


3. **Step 2 (Node 2, Coord -1):**
* `{2, -1}` ko nikaala. Map me `-1` nahi hai, daal do $\rightarrow$ `Map: {0 -> 1, -1 -> 2}`
* Bachhon ko push kiya: `{4, -2}` aur `{5, 0}`.


4. **Step 3 (Node 3, Coord 1):**
* `{3, 1}` ko nikaala. Map me `1` nahi hai, daal do $\rightarrow$ `Map: {0 -> 1, -1 -> 2, 1 -> 3}`
* Bachhon ko push kiya: `{6, 0}` aur `{7, 2}`.


5. **Step 4 (Node 4, Coord -2):**
* `-2` coordinate khali hai, daal do $\rightarrow$ `Map: {-2 -> 4, ...}`


6. **Step 5 (Node 5, Coord 0) -- MAGIC STEP:**
* `{5, 0}` ko nikaala.
* **OVERWRITE:** Map me `0` par pehle se `1` baitha tha. Lekin kyunki ye bottom view hai, Node 5 ne Node 1 ko neeche se chhipa diya. Toh hum `0` ki value ko update karke `5` kar denge!
* `Map: {0 -> 5, ...}`


7. **Step 6 (Node 6, Coord 0) -- ANOTHER MAGIC STEP:**
* `{6, 0}` ko nikaala.
* **FIR SE OVERWRITE:** Map me `0` par abhi `5` tha. Ab `6` aaya toh usne `5` ko bhi overwrite kar diya!
* `Map: {0 -> 6, ...}`


8. **Step 7 (Node 7, Coord 2):**
* `2` khali hai, daal do $\rightarrow$ `Map: {... , 2 -> 7}`



Ab jab tum Map ko sorted keys ke hisaab se print karoge (`-2` se `2`), toh output milega: **`4, 2, 6, 3, 7`** (Note: Agar original tree me 5 aur 6 dono hain, toh left-to-right BFS me 6 aakhiri me bachega).

---

## 3. C++ Implementation (Queue + Map Approach)

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to get the Bottom View of a Binary Tree
vector<int> bottomView(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    // Map sorted order me coordinates rakhega (-2, -1, 0, 1, 2)
    map<int, int> bottomNodeMap; // {Coordinate, Node_Data}
    
    // Queue pairs store karega: {Node, Coordinate}
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        Node* curr = it.first;
        int line = it.second;

        // CORE LOGIC CHANGE FROM TOP VIEW:
        // Koi condition check nahi karni! Baar-baar nayi value se overwrite karte jao
        bottomNodeMap[line] = curr->data;

        // Left child ke liye line - 1
        if (curr->left != nullptr) {
            q.push({curr->left, line - 1});
        }
        // Right child ke liye line + 1
        if (curr->right != nullptr) {
            q.push({curr->right, line + 1});
        }
    }

    // Map se data nikaal kar final array me daal do
    for (auto it : bottomNodeMap) {
        ans.push_back(it.second);
    }

    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = bottomView(root);

    cout << "Tree ka Bottom View hai: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Tree ka Bottom View hai: 4 2 6 3 7 

```

---

## 4. Complexity Analysis

* **Time Complexity:** **$O(N \log N)$** ordered `std::map` use karne ki wajah se. insertion me $\log N$ lagta hai. (Agar tum pichle waale **OFFSET Array Trick** ka use karoge, toh ye bhi **$O(N)$** me ho jayega!)
* **Space Complexity:** **$O(N)$** kyunki queue aur map dono me tree ke nodes ka data store hota hai.

Bhai, kya ab iska aur optimized **Array Version** dekhna hai, ya phir iska **Recursive (DFS)** version detail me samjhein?



Bhai, **Bottom View ko Recursion (DFS)** se karna ek dam next-level trick hai. Jaise Top View me humne recursion lagaya tha, yahan bhi hume dhyan rakhna padega ki recursion seedha neeche chala jata hai, toh ho sakta hai upar wala node hume pehle mil jaye aur neeche wala baad me.

Aao iska solid intuition, dimaag kholne wala dry run aur $O(N)$ optimised array code bilkul detail me samajhte hain.

---

## 1. Core Intuition (Level ka Khel)

Bottom View ka rule hai: **"Har vertical coordinate ka sabse NEECHE wala element chahiye."**

Jab hum recursion (DFS) se poore tree par ghoomenge, toh hum do cheezein sath lekar chalenge:

1. **Coordinate (Horizontal Distance):** Root par `0`, left jaane par `-1`, right jaane par `+1`.
2. **Level (Height/Depth):** Root par `0`, aur jaise-jaise neeche jayenge, level `+1` hota jayega.

Hum ek array/map maintain karenge jo store karega:
`Coordinate -> {Node_Data, Level}`

**Golden Rule:**

> * **Case 1:** Agar hum kisi coordinate par **pehli baar** aaye hain, toh chupchaap use array/map me daal do.
> * **Case 2:** Agar us coordinate par pehle se koi node baitha hai, toh hum check karenge: *Kya hamara current node purane wale node ke NEECHE hai (yaani current level $\ge$ purana level)?* Agar haan, toh hum purane node ko laat maar kar nikal denge aur naye node ka data update kar denge!
> 
> 

---

## 2. Step-by-Step Dry Run

Chalo is tree par dhyan dete hain:

```text
          1         (Coord: 0, Level: 0)
        /   \
       2     3      (2 -> Coord: -1, Level: 1 | 3 -> Coord: 1, Level: 1)
        \     
         5          (Coord: 0, Level: 2)

```

* **Shuruat me:** Array/Map bilkul khali hai. `min_coord = 0, max_coord = 0`.

1. **Node 1 (Coord: 0, Level: 0):**
* Coordinate `0` khali hai. Daal do $\rightarrow$ `0 -> {data: 1, level: 0}`.
* Left call gayi $\rightarrow$ Node 2 par.


2. **Node 2 (Coord: -1, Level: 1):**
* Coordinate `-1` khali hai. Daal do $\rightarrow$ `-1 -> {data: 2, level: 1}`.
* Right call gayi $\rightarrow$ Node 5 par.


3. **Node 5 (Coord: 0, Level: 2) -- THE TWIST:**
* Coordinate `0` par pehle se `1` baitha hai jiska level `0` hai.
* Humne check kiya: *Kya Node 5 ka level (2) bada ya barabar hai Node 1 ke level (0) se?* **Haan, $2 \ge 0$ bilkul sach hai!**
* Iska matlab Node 5 zyada gehraai (neeche) me hai. Humne `0` coordinate ko update kar diya $\rightarrow$ `0 -> {data: 5, level: 2}`.
* Recursion wapas lauta.


4. **Node 3 (Coord: 1, Level: 1):**
* Coordinate `1` khali hai. Daal do $\rightarrow$ `1 -> {data: 3, level: 1}`.



Saare nodes khatam! Jab hum sorted coordinates (`-1` se `1`) ke hisaab se data nikaalenge, toh output milega: **`2, 5, 3`**.

---

## 3. C++ Implementation ($O(N)$ Recursive Approach)

Hum pichle waale **OFFSET Array Trick** ka use karenge taaki map ka use na karna pade aur hamara code ek dam bullet ki raftaar se $O(N)$ me chale.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Recursive Helper Function
void fillBottomView(Node* root, int coord, int level, int OFFSET, vector<pair<int, int>>& bottomViewArray, int& min_coord, int& max_coord) {
    // Base Case
    if (root == nullptr) return;

    // Saath-saath boundary (min/max coordinates) track karo
    min_coord = min(min_coord, coord);
    max_coord = max(max_coord, coord);

    int arrayIndex = coord + OFFSET;

    // CORE LOGIC:
    // Condition 1: Agar is coordinate par abhi tak koi nahi aaya (-1 hai)
    // Condition 2: Agar koi hai, par current node ka level purane wale se BADA ya BARABAR hai (level >= purana_level)
    if (bottomViewArray[arrayIndex].first == -1 || level >= bottomViewArray[arrayIndex].second) {
        bottomViewArray[arrayIndex] = {root->data, level};
    }

    // Left child ke liye: coord - 1, level + 1
    fillBottomView(root->left, coord - 1, level + 1, OFFSET, bottomViewArray, min_coord, max_coord);

    // Right child ke liye: coord + 1, level + 1
    fillBottomView(root->right, coord + 1, level + 1, OFFSET, bottomViewArray, min_coord, max_coord);
}

// Main function
vector<int> bottomViewRecursive(Node* root) {
    vector<int> ans;
    if (root == nullptr) return ans;

    const int OFFSET = 1000;
    // Array me Pair store karenge: {Node_Data, Level}
    // Shuruat me data ko -1 aur level ko 0 rakh dete hain
    vector<pair<int, int>> bottomViewArray(2005, {-1, 0});

    int min_coord = 0, max_coord = 0;

    // Root se shuru karenge: Coord = 0, Level = 0
    fillBottomView(root, 0, 0, OFFSET, bottomViewArray, min_coord, max_coord);

    // Min se Max coordinate tak loop chala kar answer vector me data daalo
    for (int i = min_coord; i <= max_coord; i++) {
        ans.push_back(bottomViewArray[i + OFFSET].first);
    }

    return ans;
}

int main() {
    // Tree Setup
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    vector<int> result = bottomViewRecursive(root);

    cout << "Recursive DFS approach se Tree ka Bottom View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

```

### Output:

```text
Recursive DFS approach se Tree ka Bottom View: 2 5 3 

```

---

## 4. Complexity Breakdown

* **Time Complexity:** **$O(N)$** kyunki hum poore tree par sirf ek baar normal DFS chala rahe hain aur array index access ka time $O(1)$ hota hai.
* **Space Complexity:** **$O(N)$** array ke size ke liye aur worst case me $O(H)$ recursion stack space ke liye.

Bhai, ab tumhare paas **Left, Right, Top, aur Bottom** saare views ke dono tarike (BFS & DFS) ek dam crystal clear hain. Batao ab agle standard interview challenge (jaise **Boundary Traversal**) par chalein?