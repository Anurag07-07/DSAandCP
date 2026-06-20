Bazaaz! Recursion start karte hain. Yeh programming ka ek aisa topic hai jo shuru mein thoda dimaag ghumata hai, lekin ek baar samajh aa gaya toh yeh aapka sabse bada dost ban jata hai.

Recursion ka simple matlab hai: **Jab ek function apne aap ko hi call kare.** Isko samajhne ke liye do cheezein sabse zaroori hoti hain:

1. **Base Case:** Woh condition jahan recursion ko rukna hai (warna code infinite loop mein phans jayega aur *Stack Overflow* ho jayega).
2. **Recursive Call:** Function ka apne aap ko dobara call karna, har baar problem ko thoda chota karke.

Chaliye aapke dono examples (Forward aur Backward) ko bilkul dhang se dekhte hain.

---

## 1. Print 1 to N (Forward)

Agar hamein 1 se $N$ tak forward print karna hai, toh recursion ka logic thoda dimaag lagane wala hota hai. Hamein lagta hai ki pehle print hona chahiye, phir agla call. Lekin nahi! Agar hum pehle print kar denge, toh recursion ulta chalega.

Hamein pehle recursion ko **deeply call karte jana hai**, aur jab woh wapas laut raha ho (**Backtracking** ke waqt), tab print karna hai.

### Code (Java/C++ Style)

```cpp
void printForward(int n) {
    // 1. Base Case
    if (n == 0) {
        return; 
    }
    
    // 2. Recursive Call (Pehle andar jao)
    printForward(n - 1);
    
    // 3. Self Work (Wapas aate waqt print karo)
    cout << n << " ";
}

```

### Detailed Explanation (Agar $N = 3$ hai)

Jab hum `printForward(3)` call karte hain, toh computer ki memory (Call Stack) mein kya hota hai, dekhiye:

1. `printForward(3)` call hua. $3 == 0$ nahi hai. Yeh line `printForward(2)` ko call kar deta hai. (Abhi 3 print nahi hua, line paused hai).
2. `printForward(2)` call hua. Yeh `printForward(1)` ko call kar deta hai. (Line paused).
3. `printForward(1)` call hua. Yeh `printForward(0)` ko call kar deta hai. (Line paused).
4. `printForward(0)` call hua. Yeh **Base Case** hai, toh yeh yahin se `return` ho jata hai (khatam).

**Ab stack se wapas lautne (Unwinding) ki baari:**

* Control wapas aata hai `printForward(1)` ke paas. Agli line chalti hai: **Print 1**.
* Control wapas aata hai `printForward(2)` ke paas. Agli line chalti hai: **Print 2**.
* Control wapas aata hai `printForward(3)` ke paas. Agli line chalti hai: **Print 3**.

**Output:** `1 2 3`

---

## 2. Print N to 1 (Backward)

Yeh forward wale se kaafi aasan hai. Ismein hamein kya karna hai? Pehle apna kaam karna hai (yaani current number ko print karna hai), aur uske baad aage ka kaam recursion par chhod dena hai.

### Code (Java/C++ Style)

```cpp
void printBackward(int n) {
    // 1. Base Case
    if (n == 0) {
        return;
    }
    
    // 2. Self Work (Pehle print karo)
    cout << n << " ";
    
    // 3. Recursive Call (Phir chote number ke liye call karo)
    printBackward(n - 1);
}

```

### Detailed Explanation (Agar $N = 3$ hai)

Yahan stack kaise kaam karta hai:

1. `printBackward(3)` call hua.
* Sabse pehle line chali: **Print 3**.
* Phir call hua `printBackward(2)`.


2. `printBackward(2)` call hua.
* Sabse pehle line chali: **Print 2**.
* Phir call hua `printBackward(1)`.


3. `printBackward(1)` call hua.
* Sabse pehle line chali: **Print 1**.
* Phir call hua `printBackward(0)`.


4. `printBackward(0)` call hua. Base case match hua aur yeh return ho gaya.

Yahan wapas aate waqt koi kaam bacha hi nahi tha, isliye jaise-jaise function call ho raha tha, waise-waise hi output screen par aata gaya.

**Output:** `3 2 1`

---

### Key Takeaway (Golden Rule of Recursion)

* **Pre-order (Call se pehle kaam):** Agar aap call karne se **pehle** apna kaam (print) karte ho, toh cheezein **Top-to-Bottom** (N se 1) chalti hain.
* **Post-order (Call ke baad kaam):** Agar aap call karne ke **baad** apna kaam karte ho, toh cheezein **Bottom-to-Top** (1 se N) chalti hain kyunki kaam stack se wapas aate waqt hota hai.

Kya yeh stack ka khel aur dono ka differece samajh mein aaya? Agar haan, toh batao agla program kaun sa try karna hai—Factorial ya Fibonacci?


Factorial recursion ka ek bohot hi classic aur best example hai. Isko samajhne ke baad aapko recursion ka **"value return karne"** wala concept bilkul crystal clear ho jayega.

Chaliye isko bilkul basic se break down karte hain.

---

## Factorial Kya Hota Hai? (Maths Behind It)

Kisi bhi number $N$ ka factorial (jisko hum $N!$ likhte hain) ka matlab hota hai 1 se lekar $N$ tak ke saare numbers ka multiplication.

* $5! = 5 \times 4 \times 3 \times 2 \times 1 = 120$
* $4! = 4 \times 3 \times 2 \times 1 = 24$
* $3! = 3 \times 2 \times 1 = 6$

Agar aap dhyan se dekhein, toh kya hum $5!$ ko aise likh sakte hain?


$$5! = 5 \times (4 \times 3 \times 2 \times 1)$$


Aur $(4 \times 3 \times 2 \times 1)$ kya hai? Woh toh $4!$ hai!

Yahan se hamein recursion ka formula milta hai:


$$\text{Factorial}(N) = N \times \text{Factorial}(N - 1)$$

---

## Recursion ke 2 Pillars (Is Problem Ke Liye)

1. **Base Case:** Hum sabko pata hai ki $0! = 1$ aur $1! = 1$ hota hai. Toh jaise hi $N$ ki value 1 ya 0 hogi, hum aage multiply nahi karenge, seedhe `1` return kar denge.
2. **Recursive Call:** Agar $N$ bada hai, toh hum computer se kahenge: *"Bhai, tum mujhe $(N-1)$ ka factorial laakar do, main usmein $N$ multiply kar dunga."*

---

## Code (Java/C++)

```cpp
int factorial(int n) {
    // 1. Base Case
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // 2. Recursive Call & Self Work
    // Pehle choti problem ka answer mangvaya, phir usmein n multiply kiya
    int chotaAnswer = factorial(n - 1);
    int badaAnswer = n * chotaAnswer;
    
    return badaAnswer;
}

```

---

## Detailed Dry Run (Call Stack Kaise Kaam Karta Hai)

Maano humne call kiya `factorial(4)`. Dekhte hain memory (Stack) mein yeh kaise solve hota hai:

### Phase 1: Andar Jaana (Top to Bottom)

1. **`factorial(4)`** call hua. 4 base case nahi hai. Yeh wait karega `factorial(3)` ke answer ka.
2. **`factorial(3)`** call hua. 3 base case nahi hai. Yeh wait karega `factorial(2)` ke answer ka.
3. **`factorial(2)`** call hua. 2 base case nahi hai. Yeh wait karega `factorial(1)` ke answer ka.
4. **`factorial(1)`** call hua. Yeh **Base Case** hai! Yeh turant return karega **`1`**.

### Phase 2: Wapas Aana aur Calculate Karna (Bottom to Top)

Ab stack niche se upar ki taraf khali hoga aur calculations hongi:

* `factorial(1)` ne return kiya `1` $\rightarrow$ Control wapas gaya `factorial(2)` ke paas.
* `factorial(2)` ne calculation ki: $2 \times \text{factorial}(1) = 2 \times 1 = \mathbf{2}$. Yeh `2` upar return karega.


* Control wapas gaya `factorial(3)` ke paas.
* `factorial(3)` ne calculation ki: $3 \times \text{factorial}(2) = 3 \times 2 = \mathbf{6}$. Yeh `6` upar return karega.


* Control wapas gaya `factorial(4)` ke paas.
* `factorial(4)` ne calculation ki: $4 \times \text{factorial}(3) = 4 \times 6 = \mathbf{24}$.



**Final Output:** `24`

---

> 💡 **Ek Mazedaar Baat:** > Agar aap code mein base case lagana bhool gaye (yaani `if (n == 1)` nahi likha), toh function `factorial(-1)`, `factorial(-2)` call karta rahega aur tab tak chalta rahega jab tak aapke computer ki memory khatam nahi ho jaati. Isiko hum **Stack Overflow Error** kehte hain.

Kya factorial ka yeh "wait karna aur wapas aate waqt multiply karna" wala logic samajh aaya? Agar yeh clear hai, toh bolo agla concept **Fibonacci Series** par chalein ya ismein koi doubt hai?


Fibonacci Series recursion ka ek aisa topic hai jahan se **"Multiple Recursion Calls"** (ek hi function mein do baar recursion use karna) ka concept shuru hota hai. Yeh factorial se thoda alag aur zyada interesting hai kyunki iska stack ek seedhi line mein nahi, balki ek **Tree** ki tarah banta hai.

Chaliye isko bilkul aasan bhasha mein samajhte hain.

---

## Fibonacci Series Kya Hoti Hai?

Fibonacci ek aisi numbers ki series hai jahan har number apne pichle do numbers ka sum (jod) hota hai. Series ki shuruat $0$ aur $1$ se hoti hai:

$$\mathbf{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, \dots}$$

Agar hum isko index ke hisab se dekhein (0-based indexing):

* $F(0) = 0$
* $F(1) = 1$
* $F(2) = F(1) + F(0) = 1 + 0 = 1$
* $F(3) = F(2) + F(1) = 1 + 1 = 2$
* $F(4) = F(3) + F(2) = 2 + 1 = 3$

Yahan se hamara recursion formula nikalta hai:


$$F(N) = F(N - 1) + F(N - 2)$$

---

## Recursion ke 2 Pillars

1. **Base Case:** Hamein pata hai ki agar $N = 0$ hai toh answer $0$ hoga, aur agar $N = 1$ hai toh answer $1$ hoga. Toh hum likh sakte hain: `if (n == 0 || n == 1) return n;`
2. **Recursive Call:** Kisi bhi $N$ ke liye, hum pehle uske pichle number $(N-1)$ ka fibonacci nikalenge, phir uske pichle se pichle $(N-2)$ ka nikalenge, aur dono ko jod denge.

---

## Code (Java/C++)

```cpp
int fibonacci(int n) {
    // 1. Base Case
    if (n == 0 || n == 1) {
        return n;
    }
    
    // 2. Multiple Recursive Calls
    int pichla = fibonacci(n - 1);       // Call A
    int pichleSePichla = fibonacci(n - 2); // Call B
    
    // 3. Self Work
    return pichla + pichleSePichla;
}

```

---

## Detailed Dry Run: Recursion Tree

Maano hamein **$F(4)$** nikalna hai. Jab ek function mein do recursive calls hoti hain, toh computer pehle **Call A** (left side) ko poora andar tak solve karta hai, uske baad hi woh **Call B** (right side) par jata hai.

Isko samajhne ke liye hum ek **Recursion Tree** banate hain:

### Yeh Tree Kaam Kaise Karta Hai? (Step-by-Step)

1. **$F(4)$** call hua. Yeh pehle apni left call lagayega $\rightarrow$ **$F(3)$**. (Abhi right call $F(2)$ line mein khadi hai, chali nahi hai).
2. **$F(3)$** ne apni left call lagayi $\rightarrow$ **$F(2)$**.
3. **$F(2)$** ne apni left call lagayi $\rightarrow$ **$F(1)$**.
4. **$F(1)$** Base Case hai! Isne return kiya **`1`**.
5. Ab $F(2)$ ki left call khatam hui, toh $F(2)$ ne apni right call lagayi $\rightarrow$ **$F(0)$**.
6. **$F(0)$** Base Case hai! Isne return kiya **`0`**.
7. Ab **$F(2)$** ke paas dono answers aa gaye: Left se `1` aur Right se `0`. Isne dono ko joda ($1 + 0 = \mathbf{1}$) aur upar $F(3)$ ko return kar diya.

> 💡 **Notice Karo:** Abhi tak $F(4)$ ki right side wali branch ($F(2)$) shuru bhi nahi hui thi. Pehle left ka poora khandaan solve hua!

8. Ab **$F(3)$** ke paas left se `1` aa chuka hai. Yeh apni right call lagayega $\rightarrow$ **$F(1)$**.
9. **$F(1)$** Base Case hai, isne return kiya **`1`**.
10. **$F(3)$** ke paas left se `1` aur right se `1` aaya. Isne joda ($1 + 1 = \mathbf{2}$) aur upar $F(4)$ ko return kiya.
11. Ab final stage par, **$F(4)$** apni right call lagayega $\rightarrow$ **$F(2)$**. Yeh $F(2)$ bilkul waise hi dubara solve hoga jaise upar hua tha, aur return karega **`1`**.
12. Akhir mein, **$F(4)$** ko left se mila `2` aur right se mila `1`. Dono ko joda ($2 + 1 = \mathbf{3}$).

**Final Output:** `3`

---

## Ek Badi Problem: Overlapping Subproblems 😮

Agar aap upar diye gaye Tree ko dhyan se dekhenge, toh aapko ek gadbad dikhegi. **$F(2)$** ko humne left side mein bhi poora solve kiya, aur wahi $F(2)$ right side mein dobara call hua aur humne use phir se poora solve kiya!

Isko programming mein **"Overlapping Subproblems"** kehte hain—yaani ek hi kaam ko baar-baar karna. Agar $N$ bohot bada ho jaye (jaise $N = 50$), toh computer hang ho jayega kyunki tree bohot bada ho jayega.

Is problem ko theek karne ke liye hum aage chalkar **DP (Dynamic Programming)** seekhte hain, jahan hum ek baar nikale gaye answer ko yaad (store) rakh lete hain taaki dobara mehnat na karni pade.

---

Kya Fibonacci ka yeh Tree structure aur left-to-right chalne ka tareeqa samajh mein aaya? Ab aap recursion ke basic strong kar chuke ho. Kya aage arrays/strings par recursion seekhna hai, ya koi specific question mind mein hai?



Recursion ka agla padao: **Sum of N Natural Numbers**. Agar aapne factorial ka concept dhyan se samjha hai, toh yeh aapke liye ekdam halwa (bohot aasan) hone wala hai. Dono ka logic lagbhag 90% same hai—factorial mein hum multiply karte hain, aur ismein hum plus (+) karenge.

Chaliye isko poori detail mein samajhte hain.

---

## 1. Problem Kya Hai? (The Math)

Hamein 1 se lekar $N$ tak ke saare natural numbers ka sum nikalna hai.
Agar $N = 5$ hai, toh hamein nikalna hai:


$$\text{Sum} = 5 + 4 + 3 + 2 + 1 = 15$$

Isi cheez ko agar hum thoda dhyan se dekhein:


$$\text{Sum}(5) = 5 + (4 + 3 + 2 + 1)$$


Aur $(4 + 3 + 2 + 1)$ kya hai? Yeh toh $1$ se $4$ tak ka sum hai, yaani $\text{Sum}(4)$!

Yahan se hamara recursion formula banta hai:


$$\text{Sum}(N) = N + \text{Sum}(N - 1)$$

---

## 2. Recursion ke 2 Pillars

1. **Base Case:** Sabse chota natural number $1$ hota hai (kuch log $0$ se bhi shuru karte hain). Agar $N = 1$ hai, toh 1 tak ka sum toh sirf `1` hi hoga. Toh hamara base case ho gaya: `if (n == 1) return 1;`
2. **Recursive Call:** Agar $N$ bada hai, toh hum recursion se kahenge: *"Tum mujhe $(N-1)$ tak ka sum lakar do, main usmein $N$ ko plus (+) kar dunga."*

---

## 3. Code (Java/C++)

```cpp
int getSum(int n) {
    // 1. Base Case
    if (n == 1) {
        return 1;
    }
    
    // 2. Recursive Call
    int chotaSum = getSum(n - 1);
    
    // 3. Self Work
    int badaSum = n + chotaSum;
    
    return badaSum;
}

```

---

## 4. Detailed Dry Run (Call Stack Trace)

Maano humne call kiya `getSum(4)`. Chaliye dekhte hain memory ke andar stack kaise banta aur tootgta hai:

### Phase 1: Call Stack Memory mein upar jaana (Push Operation)

* `getSum(4)` call hua. $4 == 1$ nahi hai. Yeh line `getSum(3)` ke answer ka wait karegi. (Paused)
* `getSum(3)` call hua. $3 == 1$ nahi hai. Yeh line `getSum(2)` ke answer ka wait karegi. (Paused)
* `getSum(2)` call hua. $2 == 1$ nahi hai. Yeh line `getSum(1)` ke answer ka wait karegi. (Paused)
* `getSum(1)` call hua. Yeh **Base Case** hai! Yeh bina aage call kiye turant return karega **`1`**.

### Phase 2: Wapas aate waqt plus (+) karna (Pop Operation)

Ab jaise-jaise functions stack se khatam honge, calculations hoti jayengi:

1. `getSum(1)` ne return kiya `1`, control wapas aaya `getSum(2)` par.
* `getSum(2)` ne calculation ki: $2 + \text{getSum}(1) \rightarrow 2 + 1 = \mathbf{3}$. Yeh `3` upar return karega.


2. Control wapas aaya `getSum(3)` par.
* `getSum(3)` ne calculation ki: $3 + \text{getSum}(2) \rightarrow 3 + 3 = \mathbf{6}$. Yeh `6` upar return karega.


3. Control wapas aaya `getSum(4)` par (Hamara main call).
* `getSum(4)` ne calculation ki: $4 + \text{getSum}(3) \rightarrow 4 + 6 = \mathbf{14 \dots}$ sorry, maths galat ho gayi, $4 + 6 = \mathbf{10}$! 😂



**Final Output:** `10`

---

## Direct Formula vs Recursion (Ek Zaroori Baat)

Aap soch rahe honge ki jab maths mein iska direct formula hota hai:


$$\text{Sum} = \frac{N \times (N + 1)}{2}$$


Toh hum recursion kyun use kar rahe hain?

Aap bilkul sahi ho! Real-world mein hum formula hi use karenge kyunki formula $O(1)$ time (ek baar mein) answer de deta hai, jabki recursion $O(N)$ time aur memory leta hai. Lekin recursion hum yahan isliye seekh rahe hain taaki aapka **dimaag open ho sake** ki backend par memory kaise kaam karti hai, kyunki aage chal kar Trees aur Graphs jaise bade topics bina recursion ke hilenge bhi nahi.

Kya Sum of N natural numbers ka yeh logic samajh aaya? Agar haan, toh ab batao—kya $A^B$ (Power nikalna) seekhna hai recursion se, ya ab Arrays (like print array, find max in array) par move karein?


Recursion ki seedhi mein agla step hai **GCD (Greatest Common Divisor)** nikalna, jisko hum **HCF (Highest Common Factor)** bhi kehte hain.

Do numbers ka GCD woh sabse bada number hota hai jo dono ko poori tarah divide kar sake. Jaise $GCD(12, 8) = 4$, kyunki 4 sabse bada number hai jiske table mein 12 aur 8 dono aate hain.

Isko recursion se solve karne ke liye hum use karte hain duniya ka sabse purana aur efficient tareeqa: **Euclid's Algorithm**.

---

## Euclid's Algorithm Kya Hai? (The Logic)

Euclid baba ne ek bohot simple baat kahi thi:

> Agar aapko do numbers $A$ aur $B$ ka GCD nikalna hai (maan lete hain $A > B$), toh aap bade number ko chhote number se divide karo aur uska **Remainder (sheshfal)** nikal lo ($A \% B$).
> Ab, jo GCD $A$ aur $B$ ka hoga, wahi same GCD $B$ aur us ($A \% B$) ka bhi hoga!

Chaliye isko ek example se dekhte hain: $A = 60, B = 24$

1. $60 \% 24 = 12$ (Remainder aaya 12)
2. Ab hum purane chhote number ($24$) aur naye remainder ($12$) ka GCD nikalenge.
3. $24 \% 12 = 0$ (Remainder aaya 0)
4. **Jaise hi remainder 0 aaye, wahi par jo hamara divisor tha (yaani 12), woh hamara answer ban jata hai.**

So, $GCD(60, 24) = 12$.

---

## Recursion ke 2 Pillars

1. **Base Case:** Jab chhota number (yaani $B$) zero ($0$) ho jaye, toh hamara answer bada number ($A$) hoga. Kyunki kisi bhi number aur $0$ ka GCD woh number khud hota hai ($GCD(A, 0) = A$).
2. **Recursive Call:** Har baar hum function ko dobara call karenge, lekin is baar parameters badal jayenge:
* Naya $A$ ban jayega purana $B$.
* Naya $B$ ban jayega purana remainder ($A \% B$).



---

## Code (Java/C++)

```cpp
int gcd(int a, int b) {
    // 1. Base Case
    if (b == 0) {
        return a;
    }
    
    // 2. Recursive Call
    // b ban gaya naya 'a', aur a % b ban gaya naya 'b'
    return gcd(b, a % b);
}

```

---

## Detailed Dry Run

Chaliye dekhte hain agar hum `gcd(24, 60)` call karein toh kya hoga. (Aap soch rahe honge yahan toh $A < B$ hai, toh kya code toot jayega? Bilkul nahi! Dekhiye pehli call mein hi recursion isko khud seedha kar dega).

### Step-by-Step Execution:

1. **`gcd(24, 60)`** call hua.
* Yahan $B = 60$ hai (zero nahi hai).
* Recursive call hui: `gcd(60, 24 % 60)`. Hum jaante hain $24 \% 60 = 24$ hota hai.
* Toh agli call bani: **`gcd(60, 24)`**. (Dekha? Apne aap bada number pehle aur chhota baad mein aa gaya!)


2. **`gcd(60, 24)`** call hua.
* $B = 24$ hai (zero nahi hai).
* Remainder nikala: $60 \% 24 = 12$.
* Agli call bani: **`gcd(24, 12)`**.


3. **`gcd(24, 12)`** call hua.
* $B = 12$ hai (zero nahi hai).
* Remainder nikala: $24 \% 12 = 0$.
* Agli call bani: **`gcd(12, 0)`**.


4. **`gcd(12, 0)`** call hua.
* Yahan **$B == 0$** ho gaya! Base case hit hua.
* Yeh turant return karega $A$ ki value, yaani **`12`**.



Saari pichli calls is `12` ko upar pass on karti jayengi aur hamara final answer aa jayega `12`.

---

## Yeh Iterative Loop se Behtar Kyun Hai?

Agar aap isko normal loop lagakar `i = 1` se lekar `B` tak chalate aur check karte, toh uski Time Complexity $O(B)$ hoti. Agar number bohot bade hote (jaise 10 digit ke), toh loop bohot slow ho jata.

Lekin Euclid's Algorithm se recursion ki Time Complexity **$O(\log(\min(A, B)))$** hoti hai. Yeh itna tez hai ki chahe kitne bhi bade numbers hon, computer palak jhapkate hi answer de deta hai.

Kya GCD ka yeh recursion logic samajh aaya? Agar haan, toh kya iska bhai **LCM** nikalna seekhein ya fir ab kuch naya pattern shuru karein?

Ab aate hain recursion ke ek aisi classic problem par jo Amazon, Microsoft aur Paytm jaise interviews mein bohot puchi jaati hai: **Nth Stair Problem** (ya **Climbing Stairs**).

Yeh problem dikhne mein lagti hai ki koi dimaag ghumane wali puzzle hai, lekin jab iska logic banta hai toh aap kahoge, *"Arey! Yeh toh bilkul Fibonacci jaisa hi hai!"*

Chaliye isko poori detail mein samajhte hain.

---

## 1. Problem Statement Kya Hai?

Aap ek seedhi (staircase) ke sabse neeche khade ho (yaani $0^{\text{th}}$ stair par). Aapko sabse upar yaani **$N^{\text{th}}$ stair** par pahunchna hai.

Aapke paas ek baar mein chalne ke do tareeqe hain:

1. Aap **1 step** chal sakte ho.
2. Ya fir aap ek baar mein **2 steps** ki chalaang (jump) maar sakte ho.

Aapko batana hai ki **kul kitne alag-alag tareeqe (distinct ways)** hain $N^{\text{th}}$ stair tak pahunchne ke?

### Ek chhota example dekhte hain ($N = 3$):

Agar hamein 3rd stair par jaana hai, toh hum kaise-kaise ja sakte hain?

* Tareeqa 1: $1 \rightarrow 1 \rightarrow 1$ (Teeno baar ek-ek step liya)
* Tareeqa 2: $1 \rightarrow 2$ (Pehle 1 step liya, fir 2 ki jump maari)
* Tareeqa 3: $2 \rightarrow 1$ (Pehle 2 ki jump maari, fir 1 step liya)

Toh $N = 3$ ke liye kul **3 tareeqe** hain.

---

## 2. Iska Recursive Logic Kaise Banayein? (Think Backwards)

Recursion ka sabse bada rule hai: **Badi problem ko choti sub-problems mein todo.**

Maan lo aapko $N^{\text{th}}$ stair par pahunchna hai. Toh zara socho, aap apni aakhri chalaang kahan se maar kar aaye hoge? Kyunki aap sirf 1 ya 2 step hi chal sakte ho, iska matlab aap do hi jagah se $N$ par pahunch sakte ho:

1. Ya toh aap **$(N-1)^{\text{th}}$ stair** par khade the aur wahan se aapne **1 step** liya.
2. Ya fir aap **$(N-2)^{\text{th}}$ stair** par khade the aur wahan se aapne **2 steps** ki jump maari.

Iska matlab, agar hamein $N$ tak pahunchne ke total tareeqe chahiye, toh hum bas yeh nikal lein ki $(N-1)$ tak pahunchne ke kitne tareeqe hain aur $(N-2)$ tak pahunchne ke kitne tareeqe hain, aur dono ko jod dein!

$$\text{Ways}(N) = \text{Ways}(N - 1) + \text{Ways}(N - 2)$$

Dekha? Yeh toh bilkul Fibonacci jaisa formula ban gaya!

---

## 3. Base Cases Kya Honge?

* **Agar $N = 0$ hai:** Aap pehle se hi ground par ho. Wahan khade rehne ka sirf **1 tareeqa** hai (ki kuch mat karo).
* **Agar $N = 1$ hai:** 1st stair par jaane ka sirf **1 tareeqa** hai (0 se 1 step lo).
* **Agar $N < 0$ hai (Negative):** Maan lo koi peeche chalaang maar de, toh woh possible nahi hai. Isliye agar $N$ negative ho jaye toh hum return karenge **`0`** ways.

---

## 4. Code (Java/C++)

```cpp
int climbStairs(int n) {
    // 1. Base Cases
    if (n < 0) return 0; // Agar seedhi ke neeche chale gaye
    if (n == 0 || n == 1) return 1; // 0th aur 1st stair ke liye 1 tareeqa
    
    // 2. Recursive Calls
    int pichliStair Se = climbStairs(n - 1);
    int pichleSePichliStairSe = climbStairs(n - 2);
    
    // 3. Self Work
    return pichliStairSe + pichleSePichliStairSe;
}

```

---

## 5. Detailed Dry Run ($N = 3$)

Chaliye dekhte hain hamara code `climbStairs(3)` ke liye kaise kaam karega. Iska bhi ek **Recursion Tree** banega:

1. **`climbStairs(3)`** call hua.
* Yeh apni left call lagayega: `climbStairs(2)`.


2. **`climbStairs(2)`** call hua.
* Yeh apni left call lagayega: `climbStairs(1)`.


3. **`climbStairs(1)`** Base Case hai, isne return kiya **`1`**.
4. Ab `climbStairs(2)` apni right call lagayega: `climbStairs(0)`.
5. **`climbStairs(0)`** Base Case hai, isne return kiya **`1`**.
6. `climbStairs(2)` ko left se `1` mila aur right se `1` mila. Isne return kiya $1 + 1 = \mathbf{2}$.
7. Ab main function `climbStairs(3)` apni right call lagayega: `climbStairs(1)`.
8. **`climbStairs(1)`** Base Case hai, isne return kiya **`1`**.
9. Akhir mein, `climbStairs(3)` ko left se mila `2` aur right se mila `1`. Dono ko joda ($2 + 1 = \mathbf{3}$).

**Final Answer:** `3` (Jo humne shuru mein manually nikala tha!)

---

### Interviewer Ka Agla Google Googly Question 🚨

Kyunki yeh Fibonacci series ki tarah kaam karta hai, iski Time Complexity bhi **$O(2^N)$** ho jaati hai (yaani bohot slow). Real interviews mein jab aap yeh code likhoge, toh interviewer kahega: *"Isko optimize karo."* Tab aapko ismein **Memoization (Dynamic Programming)** lagani padegi taaki jo stair aap ek baar calculate kar chuke ho, use baar-baar solve na karna pade.

Kya yeh Nth stair ka concept samajh aaya ki kaise humne piche se socha? Agar ismein koi doubt hai toh poocho, nahi toh batao—kya ab Arrays ke questions par chalein?


Ab hum move kar rahe hain recursion ke ek naye padao par—**Arrays**.

Array ke problems mein recursion lagane ka dhang thoda alag hota hai kyunki yahan hamein array ke saath-saath **Index** (pointers) ka bhi dhyaan rakhna padta hai.

Chaliye dekhte hain ki kisi array ka **Maximum Element** recursion se kaise nikalte hain.

---

## 1. Logic: Sochna Kaise Hai?

Maan lijiye aapke paas ek array hai: `arr = [3, 8, 2, 5]` aur aapko iska maximum nikalna hai.

Recursion ka wahi sasta aur sabse tikau niyam lagate hain—**Badi problem ko choti sub-problem mein todo.**

Hum computer se kahenge:

> *"Bhai, pehle element (`arr[0] = 3`) ko main apne paas rakhta hoon. Tum mujhe baaki bache huye array (`[8, 2, 5]`) ka maximum nikal kar de do. Phir main apne wale element aur tumhare laaye huye maximum ko compare kar lunga, jo bada hoga wahi poore array ka king (maximum) hoga!"*

Iska matlab, kisi index `i` ke liye hamara formula banta hai:


$$\text{MaxElement} = \text{Max}(\text{arr}[i], \text{MaxElement of rest of the array from } i+1)$$

---

## 2. Recursion ke 2 Pillars

1. **Base Case:** Hum array mein aage badhte-badhte kab rukenge? Jab hum array ke aakhri element par pahunch jayenge! Agar array mein sirf ek hi element bacha hai (yaani `index == array.length - 1`), toh wahi element khud ka maximum hoga. Hum wahi se use return kar denge.
2. **Recursive Call:** Har baar hum index ko badhate jayenge (`index + 1`) taaki recursion bache huye chote array par kaam kar sake.

---

## 3. Code (Java/C++)

```cpp
int findMax(int arr[], int index, int size) {
    // 1. Base Case: Agar hum aakhri element par hain
    if (index == size - 1) {
        return arr[index];
    }
    
    // 2. Recursive Call: Bache huye array ka max mangvaya
    int chotaMax = findMax(arr, index + 1, size);
    
    // 3. Self Work: Apne element aur choteMax ko compare kiya
    if (arr[index] > chotaMax) {
        return arr[index];
    } else {
        return chotaMax;
    }
}

```

*Note: Is function ko pehli baar call karte waqt hum `index = 0` pass karenge: `findMax(arr, 0, size);*`

---

## 4. Detailed Dry Run (Call Stack Kaise Kaam Karega)

Maan lijiye hamara array hai `arr = [3, 9, 5]` aur iska size hai `3`.

### Phase 1: Call Stack mein andar jaana (Top to Bottom)

1. **`findMax(arr, 0, 3)`** call hua.
* Index 0 hai, jo ki `size - 1` (yaani 2) ke barabar nahi hai.
* Yeh wait karega `findMax(arr, 1, 3)` ke answer ka.


2. **`findMax(arr, 1, 3)`** call hua.
* Index 1 hai, base case nahi mila.
* Yeh wait karega `findMax(arr, 2, 3)` ke answer ka.


3. **`findMax(arr, 2, 3)`** call hua.
* Yahan `index == 2` hai, jo ki `size - 1` ($3 - 1 = 2$) ke barabar hai!
* **Base Case Hit!** Isne turant return kiya `arr[2]` ki value, yaani **`5`**.



### Phase 2: Wapas aate waqt Comparisons (Bottom to Top)

Ab stack khali hoga aur asli mukabla (comparison) shuru hoga:

* Control wapas gaya **`findMax(arr, 1, 3)`** ke paas.
* Iska apna element tha `arr[1] = 9` aur recursion se answer aaya tha `chotaMax = 5`.
* Dono ka mukabla hua: Kya $9 > 5$? Haan! Toh isne upar return kiya **`9`**.


* Control wapas gaya sabse pehli call **`findMax(arr, 0, 3)`** ke paas.
* Iska apna element tha `arr[0] = 3` aur recursion se answer aaya tha `chotaMax = 9`.
* Dono ka mukabla hua: Kya $3 > 9$? Nahi! Toh bada kaun hua? `9`.
* Isne final answer return kiya **`9`**.



**Final Output:** `9`

---

## Time aur Space Complexity

* **Time Complexity:** $O(N)$ - Kyunki hum array ke har ek element par ek-ek baar ja rahe hain.
* **Space Complexity:** $O(N)$ - Kyunki recursion ke waqt call stack mein ek sath maximum $N$ functions store hote hain. (Agar hum ise normal loop se karte toh space $O(1)$ lagta, lekin hum yahan recursion seekh rahe hain toh dimaag chalana zaroori hai!)

Kya array mein recursion lagane ka yeh "Index badhane wala" tareeqa samajh aaya? Agar haan, toh batao agla target kya hai—**Array ko reverse print karna** ya fir **Array mein koi element search karna (Linear/Binary Search)**?


Recursion se **Palindrome** check karna ek bohot hi interesting problem hai. Yeh arrays aur strings dono par bilkul ek hi tarah se kaam karta hai.

Palindrome ka matlab hota hai ki koi string ya array **aage se padho ya peeche se, bilkul same dikhe**. Jaise: `radar`, `madam`, `12321`, ya `[1, 2, 3, 2, 1]`.

Chaliye isko recursion se solve karne ka dhang dekhte hain.

---

## 1. Logic: Do Pointers Ka Khel 🔍

Isko recursion se check karne ke liye hum **Two Pointers** ka logic use karte hain:

1. Ek pointer shuruat mein (`start`)
2. Ek pointer aakhri mein (`end`)

Hum computer se kahenge:

> *"Pehle tum check karo ki kya `start` aur `end` wale elements barabar hain? Agar dono barabar hain, toh hum recursion se kahenge ki tum bache huye andar ke array/string ko check karke batao. Agar beech wale bhi palindrome hue, toh poora array palindrome hai!"*

---

## 2. Recursion ke 2 Pillars

1. **Base Cases (Rukna Kab Hai?):**
* **`start >= end`**: Agar check karte-karte dono pointers beech mein mil gaye (ya ek doosre ko cross kar gaye), iska matlab abhi tak saare elements match ho chuke hain. Hum return kar denge `true`.


2. **Recursive Call:**
* Agar `arr[start] == arr[end]`, toh hum `start` ko ek aage badhayenge (`start + 1`) aur `end` ko ek peeche le jayenge (`end - 1`).



---

## 3. Code (Java/C++)

```cpp
bool isPalindrome(int arr[], int start, int end) {
    // 1. Base Case: Agar saare elements check ho gaye
    if (start >= end) {
        return true;
    }
    
    // 2. Self Work: Agar shuru aur aakhri ka element match nahi hua
    if (arr[start] != arr[end]) {
        return false;
    }
    
    // 3. Recursive Call: Bache huye andar ke hisse ko check karo
    return isPalindrome(arr, start + 1, end - 1);
}

```

*Note: Pehli baar isko call karte waqt hum `start = 0` aur `end = size - 1` pass karenge: `isPalindrome(arr, 0, size - 1);*`

---

## 4. Detailed Dry Run

Maan lijiye hamara array hai: `arr = [1, 2, 1]` (Size = 3)
Humne call kiya: `isPalindrome(arr, 0, 2)`

### Step-by-Step Execution:

1. **`isPalindrome(arr, 0, 2)`**:
* Check kiya: Kya `0 >= 2`? Nahi.
* Check kiya: Kya `arr[0] != arr[2]`? (1 != 1) $\rightarrow$ Nahi, dono barabar hain!
* Ab recursion call hui: `isPalindrome(arr, 0 + 1, 2 - 1)` yaani **`isPalindrome(arr, 1, 1)`**.


2. **`isPalindrome(arr, 1, 1)`**:
* Check kiya: Kya `1 >= 1`? **Haan! Base Case hit ho gaya.**
* Isne turant return kiya **`true`**.



Kyunki base case ne `true` return kiya, toh saari pichli calls ne bhi upar `true` pass kar diya.

**Final Answer:** `true` (Yaani yeh palindrome hai!)

---

### Ek aur chhota example (Non-Palindrome): `arr = [1, 2, 3]`

1. **`isPalindrome(arr, 0, 2)`** call hoga.
2. Check hoga: Kya `arr[0] == arr[2]`? (Kya 1 == 3?) **Nahi!**
3. Yeh bina aage call kiye turant yahin se **`false`** return kar dega. Aage ka array check karne ki zaroorat hi nahi padi!

---

## Time aur Space Complexity

* **Time Complexity:** $O(N)$ - Kyunki hum maximum $N/2$ baar check karte hain (beech tak pahunche tak).
* **Space Complexity:** $O(N)$ - Stack memory ke liye.

Kya Palindrome ka yeh dono taraf se andar aane wala logic samajh mein aaya? Agar haan, toh batao ab recursion mein kya toofan machana hai—**String ko reverse karna** seekhna hai ya **Subsets / Subsequences (jo interviews ka sabse hot topic hai)** par chalein?


Recursion se string mein vowels count karne ka tareeqa bhi bilkul array jaisa hi hai. Hamein bas ek variable index chahiye hoga jo string ke pehle character se shuru hokar aakhri character tak jayega.

Chaliye iska logic aur dry run bilkul detail mein samajhte hain.

---

## 1. Logic: Sochna Kaise Hai?

Maan lijiye hamari string hai: `str = "hello"`
Hamein ismein vowels (`a`, `e`, `i`, `o`, `u`) count karne hain.

Hum recursion se kahenge:

> *"Pehle character (`str[0] = 'h'`) ko main check kar leta hoon. Agar yeh vowel hai, toh main apne paas `1` rakhlunga, nahi toh `0`. Tum mujhe baaki bachi hui string (`"ello"`) mein kitne vowels hain, woh count karke laakar de do. Main dono ko plus (+) kar dunga!"*

---

## 2. Recursion ke 2 Pillars

1. **Base Case:** Hum check karte-karte kab rukenge? Jab hamara `index` string ki length ke barabar ho jaye (`index == str.length()`). Iska matlab string khatam ho gayi hai, toh wahan se hum `0` return kar denge.
2. **Recursive Call:** Har baar hum index ko `index + 1` karke bachi hui string par recursion ko bhej denge.

---

## 3. Helper Function (Vowel Check Karne Ke Liye)

Code ko saaf-suthra rakhne ke liye hum ek chhota sa function bana lete hain jo batayega ki koi character vowel hai ya nahi (uppercase aur lowercase dono ke liye):

```cpp
bool isVowel(char ch) {
    ch = tolower(ch); // Taaki 'A' aur 'a' dono handle ho jayein
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

```

---

## 4. Main Recursive Code (Java/C++)

```cpp
int countVowels(string str, int index) {
    // 1. Base Case: Agar string khatam ho gayi
    if (index == str.length()) {
        return 0;
    }
    
    // 2. Recursive Call: Agle characters ke vowels count mangvaye
    int bacheHuyeVowels = countVowels(str, index + 1);
    
    // 3. Self Work: Current character ko check kiya aur total return kiya
    if (isVowel(str[index])) {
        return 1 + bacheHuyeVowels;
    } else {
        return 0 + bacheHuyeVowels;
    }
}

```

*Note: Pehli baar call karte waqt hum `index = 0` pass karenge: `countVowels(str, 0);*`

---

## 5. Detailed Dry Run

Maan lijiye hamari string hai `"abc"` (Length = 3).
Humne call kiya: `countVowels("abc", 0)`

### Phase 1: Call Stack mein andar jaana (Top to Bottom)

1. **`countVowels("abc", 0)`**: `index` 0 hai. Base case nahi mila. Yeh wait karega `countVowels("abc", 1)` ke answer ka.
2. **`countVowels("abc", 1)`**: `index` 1 hai. Base case nahi mila. Yeh wait karega `countVowels("abc", 2)` ke answer ka.
3. **`countVowels("abc", 2)`**: `index` 2 hai. Base case nahi mila. Yeh wait karega `countVowels("abc", 3)` ke answer ka.
4. **`countVowels("abc", 3)`**: Here `index == 3` (jo ki length ke barabar hai). **Base Case Hit!** Isne return kiya **`0`**.

### Phase 2: Wapas aate waqt Counting (Bottom to Top)

* Control wapas aaya **`countVowels("abc", 2)`** par:
* Yahan character hai `str[2] = 'c'`. Kya 'c' vowel hai? Nahi ($0$).
* Total return hua: $0 + 0 \text{ (jo recursion se aaya)} = \mathbf{0}$.


* Control wapas aaya **`countVowels("abc", 1)`** par:
* Yahan character hai `str[1] = 'b'`. Kya 'b' vowel hai? Nahi ($0$).
* Total return hua: $0 + 0 \text{ (jo recursion se aaya)} = \mathbf{0}$.


* Control wapas aaya sabse pehli call **`countVowels("abc", 0)`** par:
* Yahan character hai `str[0] = 'a'`. Kya 'a' vowel hai? Haan ($1$)!
* Total return hua: $1 + 0 \text{ (jo recursion se aaya)} = \mathbf{1}$.



**Final Output:** `1`

---

## Time aur Space Complexity

* **Time Complexity:** $O(N)$ - Kyunki hum string ke har character par ek baar ja rahe hain.
* **Space Complexity:** $O(N)$ - Stack memory mein maximum $N+1$ functions store honge.

Kya yeh string par recursion chalane ka logic clear hua? Agar haan, toh batao ab aage kya seekhna hai—**String ko reverse karna** ya fir interviews ka sabse favourite topic **Subsequences / Subsets** nikalna?



Recursion se string ko reverse karne ka tareeqa bhi bohot mazedaar hai. Isko karne ke do alag tareeqe hote hain:

1. **Sirf print karte waqt dimaag lagana (Post-order printing):** Bina kisi extra space ke sirf reverse order mein print kar dena.
2. **Asli string ko badalna (In-place Swap):** Do pointers lekar string ko andar hi andar ulta kar dena.

Interviews mein doosra tareeqa (In-place swap) zyada pucha jata hai, toh hum pehle use hi bilkul detail mein samajhte hain.

---

## 1. Logic: Do Pointers aur Adla-Badli (Swapping) 🔄

Maan lijiye aapke paas string hai: `str = "hello"`
Isko ulta karne ke liye hum bilkul **Palindrome** wale logic ki tarah do pointers lenge: `start = 0` aur `end = str.length() - 1`.

Hum recursion se kahenge:

> *"Pehle aur aakhri character (`'h'` aur `'o'`) ki adla-badli (swap) main kar deta hoon. Iske baad bachi hui andar ki string (`"ell"`) ko tum reverse karke le aao. Jab tum poora kar doge, toh hamari poori string apne aap reverse ho jayegi!"*

---

## 2. Recursion ke 2 Pillars

1. **Base Case:** Jaise hi `start >= end` ho jaye (yaani pointers beech mein mil jayein ya cross kar jayein), iska matlab saare characters swap ho chuke hain. Hum chupchaap wahan se `return` ho jayenge.
2. **Recursive Call:** Apne characters ko swap karne ke baad, hum `start + 1` aur `end - 1` karke andar wali string ke liye recursion ko call kar denge.

---

## 3. Code (Java/C++)

C++ mein string **mutable** hoti hai (yaani hum use directly badal sakte hain), toh yeh code aise dikhega:

```cpp
void reverseString(string &str, int start, int end) {
    // 1. Base Case: Jab saare characters swap ho jayein
    if (start >= end) {
        return;
    }
    
    // 2. Self Work: Pehle aur aakhri character ko swap (adla-badli) karo
    swap(str[start], str[end]);
    
    // 3. Recursive Call: Ab andar bachi hui string ko reverse karo
    reverseString(str, start + 1, end - 1);
}

```

*Note: Pehli baar call karte waqt hum pass karenge: `reverseString(str, 0, str.length() - 1);*`

---

## 4. Detailed Dry Run

Maan lijiye hamari string hai `str = "code"` (Size = 4).
Humne call kiya: `reverseString(str, 0, 3)`

### Step-by-Step Execution:

1. **`reverseString(str, 0, 3)`**:
* Check kiya: Kya `0 >= 3`? Nahi.
* **Swap kiya:** `str[0]` ('c') aur `str[3]` ('e') ko badal diya. String ban gayi: **`"eodc"`**.
* Recursive call hui: `reverseString(str, 1, 2)`.


2. **`reverseString(str, 1, 2)`**:
* Check kiya: Kya `1 >= 2`? Nahi.
* **Swap kiya:** `str[1]` ('o') aur `str[2]` ('d') ko badal diya. String ban gayi: **``"edoc"`**.
* Recursive call hui: `reverseString(str, 2, 1)`.


3. **`reverseString(str, 2, 1)`**:
* Check kiya: Kya `2 >= 1`? **Haan! Base case hit ho gaya.**
* Yeh function yahin se return ho jayega.



Saari pichli paused calls stack se khali ho jayengi aur main function ko hamari final reversed string **`"edoc"`** mil jayegi.

---

## Bonus: Tareeqa 2 (Sirf Print Karna Ho Toh)

Agar interviewer bole ki asli string ko mat chhedo, bas use ulta print karke dikhao, toh yaad hai humne sabse pehle program mein kya kiya tha? **Print 1 to N (Forward)** mein humne wapas aate waqt print kiya تھا!

Wahi same logic yahan lagega:

```cpp
void printReverse(string str, int index) {
    // Base Case
    if (index == str.length()) {
        return;
    }
    // Pehle andar tak chale jao
    printReverse(str, index + 1);
    
    // Wapas aate waqt (Backtracking) print karo
    cout << str[index];
}

```

Ismein kya hoga? Pehle recursion string ke aakhri character tak chala jayega, aur jab stack se wapas laut raha hoga (bottom-to-top), toh aakhri character pehle print hoga, fir uske pehle wala, aur string ulti print ho jayegi!

---

## Time aur Space Complexity

* **Time Complexity:** $O(N)$ - Kyunki hum string ke aadhe elements ($N/2$) ko swap karte hain.
* **Space Complexity:** $O(N)$ - Stack memory ke liye.

Kya string ko reverse karne ka yeh dono tareeqa (Swap aur Backtracking print) samajh mein aaya? Ab hamare basic arrays aur strings ke operations khatam ho gaye hain.

Ab batao, kya recursion ke sabse dhasu aur interview-favourite topic **Subsequences / Subsets (Power Set)** par chalna hai?


Ab hum enter kar rahe hain recursion ke sabse dhasu, sabse important aur interviewers ke sabse pasandida topic par—**Subsequences (ya Subsets)**. Agar aapne iska logic samajh liya, toh aap recursion ke next level par pahunch jaoge.

Chaliye isko bilkul aasan bhasha mein crystal clear karte hain.

---

## 1. Subsequence Kya Hota Hai?

Kisi string ke characters ko bina unka order badle (yaani sequence same rahe), unmein se kuch characters ko chun kar ya chhod kar jo naye combinations bante hain, unhein **Subsequences** kehte hain.

Maan lijiye hamari string hai: `str = "abc"`
Iske saare subsequences honge:
`""` (khali/empty string), `"a"`, `"b"`, `"c"`, `"ab"`, `"ac"`, `"bc"`, `"abc"`

> ⚠️ **Zaroori Baat:** Sequence nahi badalna chahiye! Jaise `"ba"` ek subsequence **nahi** hai, kyunki original string `"abc"` mein `a` pehle aata hai aur `b` baad mein.

Agar kisi string ki length $N$ hai, toh uske total **$2^N$** subsequences bante hain. (Jaise `"abc"` ki length 3 hai, toh $2^3 = 8$ subsequences bane).

---

## 2. Logic: "Include or Exclude" (Haan ya Naa ka Khel) 🎯

Subsequence nikalne ka sabse behtareen tareeqa hota hai **Include/Exclude Logic**.

Jab hum string ke har ek character ke paas jayenge, toh us character ke paas do choices (vikalp) hongi:

1. **Choice 1 (Include):** Woh character hamare answer ka hissa banna chahta hai (**Haan**).
2. **Choice 2 (Exclude):** Woh character hamare answer ka hissa nahi banna chahta (**Naa**).

Hum ek `input` string rakhenge jo dhire-dhire choti hoti jayegi, aur ek `output` string rakhenge jismein hum apna answer generate karte jayenge.

---

## 3. Code (Java/C++)

```cpp
void printSubsequences(string input, string output, int index) {
    // 1. Base Case: Jab hum string ke aakhri character ke paar nikal jayein
    if (index == input.length()) {
        cout << "\"" << output << "\"" << " ";
        return;
    }
    
    // 2. Choice 1: Current character ko INCLUDE karna (Haan)
    // Humne output mein input[index] ko jod diya
    printSubsequences(input, output + input[index], index + 1);
    
    // 3. Choice 2: Current character ko EXCLUDE karna (Naa)
    // Humne output ko waise ka waisa hi rehne diya, kuch nahi joda
    printSubsequences(input, output, index + 1);
}

```

*Note: Pehli baar call karte waqt hum pass karenge: `printSubsequences("abc", "", 0);*`

---

## 4. Detailed Dry Run (Recursion Tree)

Maan lijiye hamari string hai `input = "abc"` aur shuruat mein `output = ""`, `index = 0`.

Dekhiye computer iska tree kaise banata hai (Pehle left side yaani Include chalta hai, phir right side yaani Exclude):

1. **`index = 0` (Character 'a'):**
* **Include:** 'a' ko output mein dala $\rightarrow$ `output = "a"`, call hua `index = 1`
* **Exclude:** 'a' ko nahi dala $\rightarrow$ `output = ""`, call hua `index = 1`


2. **`index = 1` (Character 'b'):**
* Left branch (`output = "a"`) se do raaste nikle:
* **Include 'b':** `output = "ab"`, call hua `index = 2`
* **Exclude 'b':** `output = "a"`, call hua `index = 2`


* Right branch (`output = ""`) se do raaste nikle:
* **Include 'b':** `output = "b"`, call hua `index = 2`
* **Exclude 'b':** `output = ""`, call hua `index = 2`




3. **`index = 2` (Character 'c'):**
* Ab har ek branch se 'c' ke liye do raaste nikalenge (Include/Exclude).
* Jaise hi `index = 3` (yaani `input.length()`) hoga, **Base Case hit ho jayega** aur us waqt `output` mein jo bhi string banti dikhegi, woh screen par print ho jayegi!



### Base Case par milne wale saare outputs:

* `"ab"` + Include 'c' $\rightarrow$ **`"abc"`**
* `"ab"` + Exclude 'c' $\rightarrow$ **`"ab"`**
* `"a"` + Include 'c' $\rightarrow$ **`"ac"`**
* `"a"` + Exclude 'c' $\rightarrow$ **`"a"`**
* `"b"` + Include 'c' $\rightarrow$ **`"bc"`**
* `"b"` + Exclude 'c' $\rightarrow$ **`"b"`**
* `""` + Include 'c' $\rightarrow$ **`"c"`**
* `""` + Exclude 'c' $\rightarrow$ **`""`** (Khali string)

---

## Time aur Space Complexity

* **Time Complexity:** **$O(2^N)$** - Kyunki har ek character ke paas exactly 2 choices hain, aur hum har element ke liye do naye raste banate hain. Agar length $N$ hai, toh kul $2^N$ function calls hoti hain.
* **Space Complexity:** **$O(N)$** - Recursion ki call stack memory string ki length $N$ ke barabar deeply andar jaati hai.

Include-Exclude ka yeh logic aage chal kar **Subset Sum**, **Coin Change**, aur **Knapsack (0/1)** jaisi badi Dynamic Programming ki problems ka base banta hai.

Kya "Include aur Exclude" ka yeh tree structure dimaag mein baitha? Agar yeh clear hai, toh poocho agla dhasu question kaun sa karna hai—**Permutations of a string** ya fir **Subset Sum Problem**?



When you generate all subsequences of a string or an array using recursion, you are essentially making a binary choice for each element: **either include it in the current subsequence or exclude it.** Here is a detailed breakdown of how the recursion works, the code implementation, and a deep dive into the time and space complexity.

---

## 1. The Conceptual Approach: Inclusion/Exclusion

For a string of length $n$, every character has 2 choices. This can be visualized as a decision tree (or a recursion tree).

* **Base Case:** If the pointer reaches the end of the string ($i == n$), we have made a decision for every character, so we print the accumulated subsequence and return.
* **Recursive Step:** 1.  **Include** the current character and move to the next index.
2.  **Exclude** the current character and move to the next index.

---

## 2. Code Implementation (Java)

Here is a standard, clean implementation of the recursion:

```java
public class Subsequences {
    
    public static void printSubsequences(String str, int index, String current) {
        // Base Case: If we have traversed all characters
        if (index == str.length()) {
            System.out.println("\"" + current + "\"");
            return;
        }
        
        // Choice 1: Include the current character
        printSubsequences(str, index + 1, current + str.charAt(index));
        
        // Choice 2: Exclude the current character
        printSubsequences(str, index + 1, current);
    }

    public static void main(String[] args) {
        String input = "abc";
        System.out.println("All subsequences of '" + input + "':");
        printSubsequences(input, 0, "");
    }
}

```

### Output for `"abc"`:

```text
"abc"
"ab"
"ac"
"a"
"bc"
"b"
"c"
""

```

---

## 3. Detailed Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(n \cdot 2^n)$

The time complexity is broken down into two main factors: the number of recursive calls and the work done inside each call.

1. **Number of Leaf Nodes ($2^n$):** At each step, the algorithm branches into 2 choices. For a string of length $n$, the depth of the tree is $n$. The total number of leaf nodes (which represent the actual subsequences) is $2 \cdot 2 \cdot 2 \dots = 2^n$.
2. **Total Nodes in the Tree ($2^{n+1} - 1$):** The total number of method calls is the total number of nodes in a full binary tree of depth $n$, which is $\mathcal{O}(2^n)$.
3. **String Operations / Printing ($\mathcal{O}(n)$):** * In Java, string concatenation (`current + str.charAt(index)`) takes $\mathcal{O}(k)$ time, where $k$ is the length of the string.
* At the base case, printing a string of average length $n/2$ takes $\mathcal{O}(n)$ time.



Multiplying the total number of states by the work done per state gives us the final time complexity:


$$\text{Total Time} = \mathcal{O}(n \cdot 2^n)$$

> 💡 **Note:** If you optimize the string manipulation using a mutable data structure like a `StringBuilder` or an array/list (pushing and popping), the work at each internal node becomes $\mathcal{O}(1)$. However, copying or printing the final result at the $2^n$ leaf nodes will still require $\mathcal{O}(n)$ time, so the overall time complexity remains $\mathcal{O}(n \cdot 2^n)$.

---

### 💾 Space Complexity: $\mathcal{O}(n)$

Space complexity in recursion is determined by the **maximum depth of the call stack** at any given moment.

| Factor | Description | Complexity |
| --- | --- | --- |
| **Recursion Call Stack** | The algorithm goes depth-first. It explores down to the base case (index $n$) before backtracking. Therefore, the maximum number of stack frames active at the same time is equal to the height of the tree. | $\mathcal{O}(n)$ |
| **Auxiliary Memory** | The `current` string stored in each frame grows up to a maximum length of $n$. | $\mathcal{O}(n)$ |

Even though we generate $2^n$ outputs, they are printed one by one and **not stored in memory simultaneously**. Once a subsequence is printed, its memory frame is popped off the stack.

Thus, the auxiliary space complexity is strictly linear:


$$\text{Total Space} = \mathcal{O}(n)$$




Yeh raha is approach ka sabse aasan aur detailed explanation (Hindi + English mix). Interviewer jab aapse LeetCode 78 poochta hai, toh woh dekhna chahta hai ki aap **Backtracking** ka use karke memory kaise bacha rahe hain.

Aaiye ise step-by-step samajhte hain.

---

## 1. Core Logic: Inclusion/Exclusion (Shamil karna ya Chodna)

Array ke har ek element ke paas **do options (choices)** hote hain:

1. **Include:** Use `current` subset mein daal do.
2. **Exclude:** Use `current` subset mein mat daalo.

Agar hamare paas `nums = [1, 2, 3]` hai, toh decision tree kuch aisa dikhega:

---

## 2. Code Breakdown & Line-by-Line Explanation

C++ code ke har ek hisse ka kaam niche diya gaya hai:

### A. Base Case (Jab decision poora ho jaye)

```cpp
if (index == nums.size()) {
    result.push_back(current);
    return;
}

```

* **Explanation:** Jab `index` badhte-badhte array ki size ke barabar ho jata hai, iska matlab humne saare elements ke liye apna decision le liya hai. Jo bhi subset `current` vector mein bankar taiyaar hua hai, use hum apne final `result` list mein daal dete hain aur wahan se return ho jaate hain.

### B. Choice 1: Element ko INCLUDE karna

```cpp
current.push_back(nums[index]); // Element ko shamil kiya
backtrack(index + 1, nums, current, result); // Agle element par gaye

```

* **Explanation:** Humne current element (`nums[index]`) ko apni choti list (`current`) mein daal diya, aur recursion ko bola, *"Chalo, ab iske aage ke elements ke liye check karo."*

### C. The "Backtracking" Step & Choice 2: Element ko EXCLUDE karna

```cpp
current.pop_back(); // Undo (Backtrack)
backtrack(index + 1, nums, current, result); // Element ke bina agle par gaye

```

* **Explanation:** Yeh is pure code ka sabse important part hai.
* Jab Choice 1 (Include waali branch) apna poora kaam khatam karke lautti hai, toh hume Choice 2 (Exclude waali branch) ko explore karna hota hai.
* Lekin `current` vector ke andar abhi bhi woh element baitha hua hai jise humne Choice 1 mein daala tha.
* Isliye hum `current.pop_back()` karte hain taaki woh element nikal jaye (ise hi **Backtrack** ya decision ko undo karna kehte hain).
* Jab element nikal gaya, tab hum bina us element ke agle index par chale jaate hain.



---

## 3. Yeh Approach "Optimized" Kyun Hai?

Agar aap normal recursion karte, toh aapko har call mein vector ki copy banani padti (pass-by-value). C++ mein vector copy karna $\mathcal{O}(n)$ time leta hai, jisse code bohot slow ho jata.

Is optimized approach mein:

1. **Pass by Reference (`&`):** Humne pure recursion tree mein sirf **ek hi** `current` vector aur **ek hi** `result` vector ka use kiya hai. Hum koi naya vector nahi bana rahe.
2. **`pop_back()` efficiency:** Vector ke last se element hatana $\mathcal{O}(1)$ (constant time) hota hai. Hum usi memory block ko baar-baar saaf karke reuse kar rahe hain.

---

## 4. Complexity Analysis (In Simple Words)

* **Time Complexity: $\mathcal{O}(n \cdot 2^n)$**
Hamare paas total $2^n$ subsets bante hain (kyunki har element ke paas 2 choices hain). Aur har baar jab hum Base Case par pahunchte hain, toh `result.push_back(current)` karne mein $\mathcal{O}(n)$ ka time lagta hai kyunki subset copy hota hai. Isliye Total Time = $n \times 2^n$.
* **Space Complexity: $\mathcal{O}(n)$**
Humne koi extra arrays ya vectors memory mein hold nahi kiye hain. Jo stack memory use hoti hai woh recursion ki depth ke barabar hoti hai, jo ki maximum $n$ (array ki length) tak jaayegi. Isliye Extra Space sirf $\mathcal{O}(n)$ hai. *(Final `result` vector ka space space complexity mein count nahi kiya jata).*



For LeetCode 78 (Subsets), the problem asks us to return all unique subsets (subsequences) of an integer array.

The absolute most optimized approach in terms of both **memory allocation** and **speed** is **Backtracking with a reusable vector**. Instead of passing vectors by value (which creates expensive copies), we pass a single `current` tracking vector by reference, push elements onto it, recurse, and then pop them off (`backtrack`).

---

## 1. Optimized C++ Code

```cpp
#include <iostream>
#include <vector>

class Solution {
private:
    void backtrack(int index, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base Case: If we have considered all elements, add a copy of current to result
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Choice 1: INCLUDE the current element
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, result);
        
        // BACKTRACK: Undo the choice to explore the "exclude" path
        current.pop_back();

        // Choice 2: EXCLUDE the current element
        backtrack(index + 1, nums, current, result);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Start recursion from index 0
        backtrack(0, nums, current, result);
        
        return result;
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> output = solver.subsets(nums);

    // Printing the subsets
    for (const auto& subset : output) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i] << (i + 1 < subset.size() ? ", " : "");
        }
        std::cout << "]\n";
    }
    return 0;
}

```

---

## 2. Why this C++ code is highly optimized

1. **Pass by Reference (`&`):** Notice `nums`, `current`, and `result` are all passed by reference. This avoids copying vectors down the recursion tree.
2. **`std::vector::pop_back()`:** This is an $\mathcal{O}(1)$ operation. We reuse the exact same memory allocated for `current` across all $2^n$ paths.
3. **No Dynamic String Overhead:** Unlike handling strings where concatenations allocate new buffers on the heap, `std::vector` handles its resizing efficiently.

---

## 3. Complexity Breakdown

### ⏱️ Time Complexity: $\mathcal{O}(n \cdot 2^n)$

* **Total subsets generated:** There are exactly $2^n$ subsets.
* **Work per subset:** In the base case, when `index == nums.size()`, we execute `result.push_back(current)`. Copying `current` into the final `result` list takes $\mathcal{O}(n)$ time.
* Thus, the total time is proportional to $n \cdot 2^n$.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **System Call Stack:** The maximum depth of the recursion tree is $n$. Hence, the stack frame memory usage is $\mathcal{O}(n)$.
* **Auxiliary Space:** The `current` vector grows to a maximum size of $n$.
* *Note: The space required to store the final output ($2^n \cdot n$) is generally not counted as auxiliary/extra space unless explicitly stated by the interviewer.*


The **Generate Parentheses** problem (LeetCode 22) is a classic problem that perfectly demonstrates the power of **Backtracking** and **Recursion**.

Given $n$ pairs of parentheses, your goal is to generate all combinations of well-formed (valid) parentheses.

---

## 1. The Core Intuition (The Rules)

If we blindly generate all possible combinations of `(` and `)` for a length of $2n$, we would get $2^{2n}$ combinations, many of which would be invalid (like `)(`, `)))(((`, etc.).

To build only **valid** combinations efficiently, we must follow two golden rules at every step:

1. **You can always add an opening parenthesis `(**` as long as the number of open parentheses we've used is **less than $n$**.
2. **You can only add a closing parenthesis `)**` if the number of close parentheses we've used is **less than the number of open parentheses** currently in our string. (Otherwise, it becomes unbalanced, e.g., we cannot place `)` if our current string is empty or already balanced like `()`).

---

## 2. Decision Tree / Recursion Tree

By applying these two rules, we prune (cut off) invalid paths immediately. For $n = 2$, the valid choices form a controlled tree structure:

---

## 3. C++ Optimized Code

We pass a string `current` by reference to save memory and use backtracking (`push_back` and `pop_back`) to traverse the decision tree efficiently.

```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void backtrack(int openCount, int closeCount, int n, std::string& current, std::vector<std::string>& result) {
        // Base Case: If the current string reaches the maximum required length (2 * n)
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Rule 1: We can add '(' if we haven't exhausted all 'n' open brackets
        if (openCount < n) {
            current.push_back('(');
            backtrack(openCount + 1, closeCount, n, current, result);
            current.pop_back(); // Backtrack (Undo the choice)
        }

        // Rule 2: We can add ')' if it won't exceed the number of '(' we already have
        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(openCount, closeCount + 1, n, current, result);
            current.pop_back(); // Backtrack (Undo the choice)
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        
        // Start with 0 open and 0 close parentheses
        backtrack(0, 0, n, current, result);
        
        return result;
    }
};

int main() {
    Solution solver;
    int n = 3;
    std::vector<std::string> ans = solver.generateParenthesis(n);
    
    std::cout << "Valid combinations for n = " << n << ":\n";
    for (const std::string& s : ans) {
        std::cout << s << "\n";
    }
    return 0;
}

```

---

## 4. Step-by-Step Dry Run (For $n = 2$)

Let's trace how the variables change step-by-step. Target length is $2n = 4$.

1. **Initial Call:** `open = 0, close = 0, current = ""`
* `open < 2` (True) $\rightarrow$ Add `(`, call `backtrack(1, 0, current = "(")`


2. **Second Call:** `open = 1, close = 0, current = "("`
* `open < 2` (True) $\rightarrow$ Add `(`, call `backtrack(2, 0, current = "((")`


3. **Third Call:** `open = 2, close = 0, current = "(("`
* `open < 2` (False)
* `close < open` (0 < 2 is True) $\rightarrow$ Add `)`, call `backtrack(2, 1, current = "(()")`


4. **Fourth Call:** `open = 2, close = 1, current = "(()"`
* `open < 2` (False)
* `close < open` (1 < 2 is True) $\rightarrow$ Add `)`, call `backtrack(2, 2, current = "(())")`


5. **Fifth Call (Base Case):** `current.length() == 4`.
* **`"(())"` is added to `result`.** Returns back to step 4.


6. **Backtracking Unwinds:**
* Step 4 pops back $\rightarrow$ `current` becomes `"(()"`. No choices left, returns to step 3.
* Step 3 pops back $\rightarrow$ `current` becomes `"(("`. No choices left, returns to step 2.
* Step 2 pops back $\rightarrow$ `current` becomes `"("`.


7. **Exploring the other side of Step 2:**
* Back at step 2 (`open=1, close=0`), Rule 2 says `close < open` (0 < 1 is True).
* Add `)`, call `backtrack(1, 1, current = "()")` ... and the process repeats to find `"()()"`.



---

## 5. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}\left(\frac{4^n}{n\sqrt{n}}\right)$

The number of valid parenthesization sequences for $n$ pairs is given by the **$n$-th Catalan Number**:


$$C_n = \frac{1}{n+1}\binom{2n}{n}$$


Asymptotically, $C_n$ grows at a rate of $\frac{4^n}{n\sqrt{n}}$. Since we spend linear time $\mathcal{O}(n)$ copying each valid sequence of length $2n$ into our final results vector, the strict upper bound is bounded by the Catalan progression.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Call Stack:** The recursion tree goes down to a maximum depth of $2n$. Thus, the stack memory used is proportional to $\mathcal{O}(n)$.
* **Auxiliary String:** The `current` string uses a maximum memory of $2n$ characters at any point.



Aapne bilkul sahi math pakda hai! Yeh explanation bilkul **accurate** aur deep hai. Agar aap kisi coding interview (jaise Google, Amazon, Meta) mein baithe hain, toh yeh answer interviewer ko bohot impress karega kyunki aksar log iska time complexity galat bolte hain.

Aaiye is mathematical explanation ko thoda aur aasan bhasha (intuition) mein todte hain taaki aap ise interview mein confidently explain kar sakein:

---

## 1. Time Complexity Breakdown (Aasan Bhasha Mein)

Agar hum har step par bina soche samajhte `(` aur `)` lagate jaate, toh total length $2n$ hoti aur total combinations $2^{2n} = 4^n$ bante.

Lekin hamare backtracking ke do rules ki wajah se hum sirf **Valid Parentheses** hi generate kar rahe hain. Aur valid parentheses ke total combinations ka count humesha **Catalan Number ($C_n$)** ke barabar hota hai.

$$C_n = \frac{1}{n+1}\binom{2n}{n}$$

### Iska asymptotic growth $\frac{4^n}{n\sqrt{n}}$ kyun hai?

Stirling's approximation ka use karke jab hum factorial ko simplify karte hain, toh $C_n$ ka behavior badi values ke liye $\approx \frac{4^n}{n^{1.5}}$ jaisa dikhta hai. Iska matlab:

* Agar $n = 3$ hai, toh total valid strings sirf **5** banti hain.
* Agar $n = 4$ hai, toh total valid strings sirf **14** banti hain.

### Final Multiplier $\mathcal{O}(n)$ Kyun Aya?

Jab hamara recursion tree **Base Case** tak pahunchta hai (yaani jab string ki length $2n$ ho jaati hai), tab hum yeh line execute karte hain:

```cpp
result.push_back(current);

```

C++ mein jab aap ek string ko vector mein push karte hain, toh woh pure string ki ek **deep copy** banata hai. Kyunki string ki length $2n$ hai, is copy operation mein $\mathcal{O}(n)$ ka time lagta hai.

$$\text{Total Time} = (\text{Total Valid Subsets}) \times (\text{Work done at Base Case}) = \mathcal{O}\left(\frac{4^n}{n\sqrt{n}}\right) \times \mathcal{O}(n) = \mathcal{O}\left(\frac{4^n}{\sqrt{n}}\right)$$

*(Kuch text-books aur interviewers is multiplier ko include karke ise $\mathcal{O}(\frac{4^n}{\sqrt{n}})$ likhte hain, aur kuch sirf total states ko hi main time complexity maante hain. Aapka dono batana safe aur accurate hai!)*

---

## 2. Space Complexity Breakdown

Space complexity ko lekar log aksar confuse hote hain kyunki unhe lagta hai ki hum itne saare combinations store kar rahe hain toh space zyada lagnii chahiye. Lekin rules ke mutabik **Output space ko Auxiliary space mein count nahi kiya jata**.

### A. Recursion Call Stack ($\mathcal{O}(n)$)

Hamara recursion Tree-Depth First Search (DFS) follow karta hai.

[Image showing depth first search trajectory on a binary recursion tree]

Iska matlab yeh hai ki jab tak yeh ek poori string (jaise `((()))`) banakar base case tak nahi pahunch jata, tab tak yeh dusri branch par nahi jata.

* Tree ki maximum depth kitni hogi? $2n$ (kyunki hum $2n$ characters tak hi jaa sakte hain).
* Isliye memory stack mein ek samay par maximum $2n$ frames hi active honge.
* $\mathcal{O}(2n)$ ko simplify karke hum **$\mathcal{O}(n)$** likhte hain.

### B. Auxiliary String ($\mathcal{O}(n)$)

Humne code mein `std::string& current` ko **pass-by-reference** kiya hai. Iska matlab poore recursion ke dauran sirf **ek hi string memory mein exist karti hai**, jisme hum `push_back` aur `pop_back` kar rahe hain. Is string ka maximum size kabhi bhi $2n$ se bada nahi hoga.

* Iska space bhi hua $\mathcal{O}(2n) \approx$ **$\mathcal{O}(n)$**.

---

### Interview Tip 💡

Interviewer ke saamne hamesha pehle naive complexity ($\mathcal{O}(4^n)$) boliye, phir use boliye: *"Since we are pruning invalid paths, the exact number of valid combinations is bounded by the $n$-th Catalan Number, which reduces the effective states drastically to $\mathcal{O}(\frac{4^n}{n\sqrt{n}})$."* Yeh sunte hi interviewer samajh jayega ki aapka computer science fundamentals bohot strong hain!



Bhai, **Subset Sum** problem coding interviews ka ek absolute favorite sawal hai. Isko samajhne ka sabse best tareeka hai **Inclusion-Exclusion Principle** (Shamil karna ya Chodna).

Aaiye isko ekdum desi style mein, step-by-step, dry run aur complexities ke saath samajhte hain!

---

## 1. Core Intuition: Asli Kahani Kya Hai?

Maan lo tumhare paas ek jhola (bag) hai aur kuch numbers ka array hai: `nums = {2, 3, 5}`. Tumhe ek target sum banana hai, let's say `K = 5`.

Jab tum array ke pehle element (`2`) par khade ho, toh tumhare dimaag mein **sirf do hi khayal** aane chahiye:

1. **Include (`2` ko jhole mein daal lo):** Agar tumne `2` ko le liya, toh ab tumhara bacha hua target kitna ho jayega? `5 - 2 = 3`. Ab aage ke elements se tumhe `3` banana hai.
2. **Exclude (`2` ko laat maar do):** Agar tumne `2` ko nahi liya, toh tumhara target abhi bhi `5` hi rahega, aur tum agle element par chale jaoge.

### Base Cases (Kab rukna hai?):

* **Sukh ki prapti (Success):** Agar kisi bhi point par tumhara `target == 0` ho gaya, iska matlab tumne perfect subset dhoodh liya! Wahan se chupchap `true` return kar do.
* **Dukh ki ghadi (Failure):** Agar tum array ke bahar nikal gaye (`index == nums.size()`) aur target abhi bhi `0` nahi hua, ya fir tumhara target negative (`target < 0`) ho gaya, toh iska matlab yeh rasta galat hai. Wahan se `false` return kar do.

---

## 2. Recursive C++ Code

Yeh hai iska ekdum clean recursive implementation:

```cpp
#include <iostream>
#include <vector>

class SubsetSum {
public:
    bool solve(int index, int target, const std::vector<int>& nums) {
        // Base Case 1: Target mil gaya!
        if (target == 0) {
            return true;
        }
        
        // Base Case 2: Array khatam ya target negative ho gaya
        if (index == nums.size() || target < 0) {
            return false;
        }

        // Choice 1: Current element ko INCLUDE kiya
        // Target kam ho jayega, index aage badhega
        bool include = solve(index + 1, target - nums[index], nums);

        // Choice 2: Current element ko EXCLUDE kiya
        // Target same rahega, index aage badhega
        bool exclude = solve(index + 1, target, nums);

        // Agar dono mein se ek bhi rasta true de de, toh answer true hai
        return include || exclude;
    }
};

int main() {
    SubsetSum solver;
    std::vector<int> nums = {2, 3, 5};
    int target = 5;

    if (solver.solve(0, target, nums)) {
        std::cout << "Haan bhai, subset exist karta hai!\n";
    } else {
        std::cout << "Nahi bhai, aisa koi subset nahi hai.\n";
    }
    return 0;
}

```

---

## 3. Ekdum Kadak Dry Run

Chalo ek chota sa example lete hain: `nums = {2, 3}` aur `target = 3`.

1. **Call 1:** `solve(idx=0, target=3)`
* Pehla option: **Include `nums[0]` (yaani 2)**
* Call lagayi: `solve(1, 3 - 2 = 1)`


2. **Call 2 (Include ke andar):** `solve(idx=1, target=1)`
* Pehla option: **Include `nums[1]` (yaani 3)**
* Call lagayi: `solve(2, 1 - 3 = -2)`
* **Base Case Hit!** `target < 0` ho gaya. Isne return kiya **`false`**.
* Dusra option: **Exclude `nums[1]` (yaani 3)**
* Call lagayi: `solve(2, 1)`
* **Base Case Hit!** `index == nums.size()` ho gaya. Isne bhi return kiya **`false`**.
* Toh Call 2 ka final answer aaya: `false || false = false`. Hum wapas Call 1 par laut aaye.


3. **Call 1 par wapas (Ab Exclude check karenge):**
* Dusra option: **Exclude `nums[0]` (yaani 2)**
* Call lagayi: `solve(1, 3)`


4. **Call 3:** `solve(idx=1, target=3)`
* Pehla option: **Include `nums[1]` (yaani 3)**
* Call lagayi: `solve(2, 3 - 3 = 0)`
* **Base Case Hit!** `target == 0` ho gaya! Isne khushi-khushi return kiya **`true`**.



Yeh `true` upar bubble up hoga aur main function ko mil jayega. Final Answer: **`true`** (Subset hai `{3}`).

---

## 4. Complexity Analysis (Bohot Important)

### ⏱️ Time Complexity: $\mathcal{O}(2^n)$

* **Explanation:** Har ek element ke paas strictly 2 choices hain (Include ya Exclude). Agar array mein $n$ elements hain, toh hamara recursion tree maximum $n$ level tak deep jayega.
* Total nodes kitne bante hain binary tree mein? Lagbhag $2^n$.
* Har node ke andar hum sirf basic `+`, `-` aur `if` conditions check kar rahe hain, jo $\mathcal{O}(1)$ time leti hain.
* Isliye total time complexity **Exponential** ho jaati hai: $\mathcal{O}(2^n)$.

> ⚠️ **Interviewer Alart:** Agar interviewer ne $n = 30$ de diya, toh $2^{30}$ yaani 1 Billion se zyada operations ho jayenge aur code **Time Limit Exceeded (TLE)** de dega. Isko bachane ke liye hum baad mein **Memoization / DP** ka use karte hain jo time ko ghatakar $\mathcal{O}(n \cdot \text{target})$ kar deta hai.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Log sochte hain ki itne saare raste hain toh space zyada lagega, lekin aisa nahi hai. Recursion **Depth-First Search (DFS)** follow karta hai.
* Iska matlab jab tak woh ek raste ki gehrai (leaf node) tak nahi pahunch jata, woh dusra rasta shuru nahi karta.
* Kisi bhi ek point par, hamare computer ke system call stack mein maximum $n$ functions hi khule honge.
* Isliye extra auxiliary space strictly linear hoti hai: **$\mathcal{O}(n)$**.


Bhai, **Target Sum** (LeetCode 494) bhi subset sum family ka hi ek shaandar question hai. Isko samajhne ka sabse mast tareeka yeh hai ki is baar hume element ko *chodna* nahi hai, balki har element ke aage ya toh **`+` (Plus)** ka sign lagana hai ya **`-` (Minus)** ka sign lagana hai.

Aaiye isko ekdum dhasu style mein poori intuition, dry run aur complexity ke saath samajhte hain!

---

## 1. Core Intuition: Asli Game Kya Hai?

Maan lo tumhare paas ek array hai: `nums = {1, 2}` aur tumhe ek `target = 1` banana hai.

Tumhe array ke saare ke saare elements ka use karna hi padega, lekin har element ke paas **do choices (vikalp)** hain:

1. Uske aage **Plus (`+`)** ka sign lagao $\rightarrow$ Isse running sum badh jayega (`currentSum + nums[index]`).
2. Uske aage **Minus (`-`)** ka sign lagao $\rightarrow$ Isse running sum ghat jayega (`currentSum - nums[index]`).

Hum shuruat karenge `index = 0` aur `currentSum = 0` se, aur har level par dono raaste explore karenge.

### Base Case (Kab rukkar check karna hai?):

* **Kahani Khatam:** Jab hum saare elements ke liye sign chun chuke honge (yaani `index == nums.size()`), tab hum check karenge ki kya hamara `currentSum` us `target` ke barabar pahuncha ya nahi.
* Agar `currentSum == target` hai, toh iska matlab hume **1 valid rasta** mil gaya (return `1`).
* Agar barabar nahi hai, toh yeh rasta bekaar hai (return `0`).

---

## 2. Recursive C++ Code (Brute Force)

Yeh hai iska simple aur clear recursive code jo har ek combination ko check karta hai:

```cpp
#include <iostream>
#include <vector>

class TargetSum {
public:
    int solve(int index, int currentSum, const std::vector<int>& nums, int target) {
        // Base Case: Jab saare numbers par sign laga diya ho
        if (index == nums.size()) {
            // Agar chalte-chalte sum target ke barabar ho gaya toh 1 rasta mila, nahi toh 0
            return (currentSum == target) ? 1 : 0;
        }

        // Choice 1: Current number ke aage '+' sign lagaya
        int plusPath = solve(index + 1, currentSum + nums[index], nums, target);

        // Choice 2: Current number ke aage '-' sign lagaya
        int minusPath = solve(index + 1, currentSum - nums[index], nums, target);

        // Dono raaston se milne waale total tareeqon (ways) ko add karke return kar do
        return plusPath + minusPath;
    }

    int findTargetSumWays(std::vector<int>& nums, int target) {
        return solve(0, 0, nums, target);
    }
};

int main() {
    TargetSum solver;
    std::vector<int> nums = {1, 2};
    int target = 1;
    
    int totalWays = solver.findTargetSumWays(nums, target);
    std::cout << "Total tareeqe: " << totalWays << "\n"; // Output: 1
    return 0;
}

```

---

## 3. Ekdum Kanch jaisa Saaf Dry Run

Chalo upar waale example ko hi trace karte hain: `nums = {1, 2}` aur `target = 1`.

1. **Call 1:** `solve(idx=0, sum=0)`
* **Plus Path:** `0 + nums[0]` $\rightarrow$ `0 + 1 = 1`. Call gayi `solve(1, 1)`
* **Minus Path:** `0 - nums[0]` $\rightarrow$ `0 - 1 = -1`. Call gayi `solve(1, -1)`


2. **Pehle Plus waali branch ko andar tak dekhte hain (`idx=1, sum=1`):**
* Ab `nums[1]` (jo ki 2 hai) par decision lena hai:
* **Plus Path:** `1 + 2 = 3`. Call gayi `solve(2, 3)`
* *Base Case Hit (`idx==2`):* Kya `3 == target (1)` hai? Nahi! Return hua **`0`**.


* **Minus Path:** `1 - 2 = -1`. Call gayi `solve(2, -1)`
* *Base Case Hit (`idx==2`):* Kya `-1 == target (1)` hai? Nahi! Return hua **`0`**.


* Toh is poori branch se total tareeqe mile: `0 + 0 = 0`.


3. **Ab main Call 1 ki Minus waali branch par aate hain (`idx=1, sum=-1`):**
* Ab `nums[1]` (jo ki 2 hai) par decision:
* **Plus Path:** `-1 + 2 = 1`. Call gayi `solve(2, 1)`
* *Base Case Hit (`idx==2`):* Kya `1 == target (1)` hai? **Haan bhai, bilkul hai!** Return hua **`1`** (Expression: `-1 + 2`).


* **Minus Path:** `-1 - 2 = -3`. Call gayi `solve(2, -3)`
* *Base Case Hit (`idx==2`):* Kya `-3 == target (1)` hai? Nahi! Return hua **`0`**.


* Is branch se total tareeqe mile: `1 + 0 = 1`.


4. **Final Result:** Total ways = `0 + 1 = 1`. Hamara answer ekdum sahi hai!

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(2^n)$

* **Explanation:** Tum naye nahi ho, tum jaante ho ki har index par hum strictly 2 branches khol rahe hain (`+` aur `-`). $n$ elements ke liye recursion tree ki total height $n$ hogi.
* Total leaf nodes $2^n$ banenge. Kyunki har node ke andar ka kaam sirf normal `+`/`-` hai (jo $\mathcal{O}(1)$ hai), isliye total time exponential ho jata hai: $\mathcal{O}(2^n)$.
* *Interview Tip:* Agar $n > 20$ ho jaye, toh yeh code pighal jayega (TLE de dega). Interviewer ko impress karne ke liye hum ise baad mein Memoization (DP) se optimize karke $\mathcal{O}(n \cdot \text{sum})$ par le aate hain.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Hum yahan koi alag se array ya data structure create nahi kar rahe hain space lene ke liye.
* Kyunki recursion pehle ek raste ki poori gehrai tak jata hai (DFS), isliye kisi bhi ek moment par computer ke call stack memory mein maximum $n$ active functions hi ho sakte hain.
* Isliye auxiliary space complexity ekdum linear hai: **$\mathcal{O}(n)$**.



Bhai, **Perfect Sum** problem (jise aksar LeetCode ya GeeksforGeeks par *"Count of Subsets with Sum Equal to X"* bhi kehte hain) tumhare pichle dono sawalon (Subset Sum aur Target Sum) ka agla bada bhai hai.

Is baar hume sirf yeh nahi batana ki target sum ban sakta hai ya nahi (`true`/`false`), aur na hi har element par plus/minus lagana hai. Is baar hume batana hai ki **aise kitne alag-alag subsets hain jinka sum exact hamare target ke barabar hai!**

Aaiye isko ekdum desi style mein, bina kisi confusion ke, poori intuition, code aur dhasu dry run ke saath dimaag mein fit karte hain.

---

## 1. Core Intuition: Iska Game Kya Hai?

Maan lo tumhare paas array hai: `nums = {2, 3, 5, 5}` aur target sum hai `K = 5`.
Yahan `5` banane ke kai tareeqe hain:

* Sirf pehle waale `5` ko le lo $\rightarrow$ `{5}`
* Sirf dusre waale `5` ko le lo $\rightarrow$ `{5}`
* Pehle dono elements ko le lo $\rightarrow$ `{2, 3}`

Toh total answer aana chahiye `3`.

Iska logic bhi wahi purana aur hit **Inclusion-Exclusion Principle** hai. Har element ke paas fir se do choices hain:

1. **Include:** Element ko subset mein shamil karo. Target ghat jayega $\rightarrow$ `target - nums[index]`.
2. **Exclude:** Element ko subset mein shamil mat karo. Target same rahega $\rightarrow$ `target`.

### Base Cases (Yahan log sabse badi galti karte hain! ⚠️)

Aksar log base case likhte hain: `if (target == 0) return 1;`
**Lekin yeh galat ho jata hai agar array mein `0` (zeros) bhi ho sakte hain!** Agar array mein `0` hai, toh use include karne se bhi sum nahi badhta, isliye hume array ke end tak jaana hi padega sahi count ke liye.

* **Sahi Base Case:** Jab hum array ke bilkul khatam hone par pahunch jayein (`index == nums.size()`), tab check karo:
* Kya chalte-chalte `target == 0` ho gaya? Agar haan, toh hume **1 valid subset** mil gaya, return `1`.
* Agar target `0` nahi hua, toh return `0`.



---

## 2. Recursive C++ Code

Yeh hai iska ekdum accurate recursive code:

```cpp
#include <iostream>
#include <vector>

class PerfectSum {
public:
    int solve(int index, int target, const std::vector<int>& nums) {
        // Base Case: Jab hum poora array छान चुके (explore kar chuke) hain
        if (index == nums.size()) {
            return (target == 0) ? 1 : 0;
        }

        // Agar target negative chala gaya (aur array mein sirf positive nos hain), 
        // toh aage jaane ka fayda nahi
        if (target < 0) {
            return 0;
        }

        // Choice 1: Current element ko INCLUDE kiya
        int include = solve(index + 1, target - nums[index], nums);

        // Choice 2: Current element ko EXCLUDE kiya
        int exclude = solve(index + 1, target, nums);

        // Is baar dono raaston se milne waale COUNTS ko add karna hai!
        return include + exclude;
    }

    int perfectSum(std::vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};

int main() {
    PerfectSum solver;
    std::vector<int> nums = {2, 3, 5};
    int target = 5;

    std::cout << "Total subsets jinka sum " << target << " hai: " 
              << solver.perfectSum(nums, target) << "\n"; // Output: 2 ({2,3} aur {5})
    return 0;
}

```

---

## 3. Ekdum Sheeshe jaisa Saaf Dry Run

Chalo chota example lete hain: `nums = {2, 3}` aur `target = 3`.

1. **Call 1:** `solve(idx=0, target=3)`
* **Include `nums[0]` (2):** Call gayi $\rightarrow$ `solve(1, 3 - 2 = 1)`
* **Exclude `nums[0]` (2):** Call gayi $\rightarrow$ `solve(1, 3)`


2. **Pehle Include waali branch ko solve karte hain (`idx=1, target=1`):**
* Ab element hai `3`.
* **Include `3`:** Target chala gaya negative (`1 - 3 = -2`), toh isne turant return kiya **`0`**.
* **Exclude `3`:** Call gayi $\rightarrow$ `solve(2, 1)`.
* *Base Case Hit (`idx==2`):* Kya `target == 0` hai? Nahi, `1` hai. Toh return hua **`0`**.


* Toh pehli main branch se hume mila: `0 + 0 = 0`.


3. **Ab dusri Exclude waali branch par aate hain (`idx=1, target=3`):**
* Ab element hai `3`.
* **Include `3`:** Call gayi $\rightarrow$ `solve(2, 3 - 3 = 0)`.
* *Base Case Hit (`idx==2`):* Kya `target == 0` hai? **Haan bhai, bilkul hai!** Toh is raste ne return kiya **`1`** (Subset mila `{3}`).


* **Exclude `3`:** Call gayi $\rightarrow$ `solve(2, 3)`.
* *Base Case Hit (`idx==2`):* Kya `target == 0` hai? Nahi, `3` hai. Toh return hua **`0`**.


* Toh is dusri branch se hume mila: `1 + 0 = 1`.


4. **Final Result:** Total subsets = Include branch + Exclude branch = `0 + 1 = 1`.

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(2^n)$

* **Explanation:** Har element par wahi do dharavi choices chal rahi hain (Lena ya na lena). $n$ elements ke liye total recursion tree ki height $n$ hogi, aur leaf nodes $2^n$ banenge.
* Kyunki har step par hum simple plus/minus aur condition check kar rahe hain ($\mathcal{O}(1)$), total time exponential ho jata hai: $\mathcal{O}(2^n)$.
* *Interview Tip:* Agar $n$ bada ho (jaise $n > 20$), toh interviewer aapse **Memoization / DP** lagwayega jisse time complexity ghat kar $\mathcal{O}(n \cdot \text{target})$ ho jayegi.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Hum extra arrays ya vectors store nahi kar rahe hain.
* Recursion deep jate hue DFS follow karta hai, isliye kisi bhi ek point par computer ki stack memory mein maximum utne hi frames honge jitni array ki length hai (height of tree).
* Isliye auxiliary space complexity linear hoti hai: **$\mathcal{O}(n)$**.



Bhai, ab tumne jo pucha hai, use dynamic programming aur recursion ki duniya mein **"Combination Sum"** (LeetCode 39) ya **"Unbounded Knapsack / Target Sum with Repetition"** kehte hain.

Iska matlab yeh hai ki is baar tumhare paas jo array hai, uske elements ko tum **jitni baar chaho utni baar reuse (repeat) kar sakte ho**, jab tak ki tumhara sum target ke barabar na pahunch jaye!

Aaiye isko ekdum mast dhasu style mein, poori intuition, code aur ek-ek step ke dry run ke saath dimaag mein bitha lete hain.

---

## 1. Core Intuition: Iska Game Kaise Badalta Hai?

Pichle questions mein kya hota tha? Jab hum kisi element ko **Include** karte ya **Exclude** karte the, dono hi cases mein hum agle index (`index + 1`) par chale jaate the.

Lekin **Repetition** waale sawal mein rule thoda badal jata hai:

1. **Include (Lekin wahi ruke raho):** Agar tumne current element ko apni list mein shamil kiya, toh target toh kam hoga (`target - nums[index]`), lekin **tum agle element par nahi jaoge!** Tum usi index par khade rahoge taaki agar zaroorat pade toh tum use *fir se* chun sako.
2. **Exclude (Ab aage badho):** Agar tumne thaan liya ki ab mujhe is element ko aur nahi lena hai, tab tum bina target ko chede agle index (`index + 1`) par chale jaoge.

### Base Cases (Kab rukna hai?):

* **Sukh ki Prapti (Success):** Agar kisi bhi point par `target == 0` ho gaya, iska matlab perfect combination mil gaya! Hum wahan se `1` return kar denge (yaani 1 valid rasta mila).
* **Dukh ki Ghadi (Failure):** Agar hum array ke bahar nikal gaye (`index == nums.size()`) ya fir hamara `target < 0` (negative) ho gaya, toh iska matlab yeh rasta galat hai. Wahan se `0` return kar do.

---

## 2. Recursive C++ Code

Yeh rahi iski ekdum clean aur optimal recursive implementation jo total combinations count karegi:

```cpp
#include <iostream>
#include <vector>

class TargetSumRepetition {
public:
    int countWays(int index, int target, const std::vector<int>& nums) {
        // Base Case 1: Agar target poora mil gaya
        if (target == 0) {
            return 1;
        }
        
        // Base Case 2: Array khatam ya target negative ho gaya
        if (index == nums.size() || target < 0) {
            return 0;
        }

        // Choice 1: Current element ko INCLUDE kiya
        // Sabse important point: index ko 'index' hi rehne diya (index + 1 nahi kiya)
        int include = countWays(index, target - nums[index], nums);

        // Choice 2: Current element ko EXCLUDE kiya
        // Ab is element se picha chudaya aur agle par badh gaye
        int exclude = countWays(index + 1, target, nums);

        // Dono raaston se milne waale total ways ko add kar diya
        return include + exclude;
    }
};

int main() {
    TargetSumRepetition solver;
    std::vector<int> nums = {2, 3};
    int target = 5;

    int totalWays = solver.countWays(0, target, nums);
    std::cout << "Total combinations with repetition: " << totalWays << "\n"; 
    // Output: 1 (kyunki sirf ek combination banega: {2, 3})
    
    return 0;
}

```

---

## 3. Ekdum Sheeshe jaisa Saaf Dry Run

Chalo ek chota aur badhiya example lete hain: `nums = {2, 3}` aur `target = 5`.

1. **Call 1:** `solve(idx=0, target=5)` — Yahan `nums[0] = 2` hai.
* **Include 2:** Call gayi $\rightarrow$ `solve(0, 5 - 2 = 3)` *(Notice karo index abhi bhi 0 hai!)*


2. **Call 2 (Include ke andar):** `solve(idx=0, target=3)`
* **Include 2:** Call gayi $\rightarrow$ `solve(0, 3 - 2 = 1)`


3. **Call 3 (Fir se include):** `solve(idx=0, target=1)`
* **Include 2:** Call gayi $\rightarrow$ `solve(0, 1 - 2 = -1)`. **Base Case Hit!** `target < 0` ho gaya, isne return kiya **`0`**.
* **Exclude 2:** Ab 2 ko choda aur agle element par gaye. Call gayi $\rightarrow$ `solve(1, 1)`.
* Yahan `nums[1] = 3` hai. Agar 3 ko include karenge toh `1 - 3 = -2` (Negative $\rightarrow$ `0`). Agar exclude karenge toh array khatam (`idx==2` $\rightarrow$ `0`).
* Toh Call 3 ka total return aaya **`0`**.




4. **Wapas Call 2 par aate hain (`idx=0, target=3`):**
* Include waale raste ne toh 0 diya. Ab iska **Exclude 2** chalega:
* Call gayi $\rightarrow$ `solve(1, 3)` — Ab hum `nums[1] = 3` par hain.
* **Include 3:** Call gayi $\rightarrow$ `solve(1, 3 - 3 = 0)`. **Base Case Hit!** `target == 0` ho gaya! Isne khushi-khushi return kiya **`1`** (Hume combination mila `{2, 3}`).
* **Exclude 3:** Call gayi $\rightarrow$ `solve(2, 3)` (Array khatam $\rightarrow$ `0`).
* Toh Call 2 ke is hisse se hume mila **`1`**.


5. **Final Output:** Saari branches ka jab sum upar bubble up hoga, toh final answer aayega **`1`**.

---

## 4. Detailed Complexity Analysis (Yahan twist hai!)

### ⏱️ Time Complexity: $\mathcal{O}(2^{\text{target}})$ [Worst Case]

* **Explanation:** Normal subset sum mein tree ki depth maximum $n$ (array size) hoti thi. Lekin repetition mein aisa nahi hai!
* Socho agar array mein sabse chota element `1` ho, toh hum use baar-baar include karke `target` times tak tree ko gehra le ja sakte hain. Isliye recursion tree ki maximum height ab $n$ nahi balki **`target`** (ya `target / min_element`) hogi.
* Har state par fir se 2 choices hain, isliye worst-case time complexity exponential ho kar **$\mathcal{O}(2^{\text{target}})$** tak ja sakti hai (agar elements bohot chote hon).
* *Interview Trick:* Yeh bohot heavy complexity hai. Real interviews mein ise lagate hi interviewer kahega, *"Bhai optimize karo!"* Tab hum **Memoization (DP)** lagakar ise $\mathcal{O}(n \cdot \text{target})$ par le aate hain.

### 💾 Space Complexity: $\mathcal{O}(\text{target})$

* **Explanation:** Hum koi extra space utilize nahi kar rahe hain.
* System call stack ki jo maximum memory depth hogi, woh recursion tree ki maximum height ke barabar hogi. Aur jaisa humne abhi discuss kiya, tree ki maximum height **`target`** tak ja sakti hai.
* Isliye auxiliary space complexity linear hogi, lekin target ke proportional: **$\mathcal{O}(\text{target})$**.



Bhai, **Permutations** (LeetCode 46) recursion aur backtracking ka ek aur behtareen concept hai.

Subset aur Subsequence mein hum elements ko *chunte ya chhodte* the (order same rehta tha). Lekin Permutations ka matlab hota hai **"Arrangement" (Sajawat)**. Isme hume array ke saare elements ka use karna hota hai, bas unka **aapas ka order (piche-aage) badalna** hota hai.

Aaiye isko ekdum desi style mein, poori intuition, code aur ek-ek step ke dry run ke saath dimaag mein fit karte hain!

---

## 1. Core Intuition: Permutation Ka Game Kya Hai?

Maan lo tumhare paas 3 dost hain: `[A, B, C]` aur unhe 3 kurshiyon (chairs) par bithana hai.

* **Pehli chair par:** Tum Teeno mein se kisi ko bhi bitha sakte ho (A, B, ya C).
* **Dusri chair par:** Jo pehli par baith gaya usko chhod kar, bache hue dono mein se kisi ek ko bitha sakte ho.
* **Teesri chair par:** Jo akela bach gaya, woh baitega.

Recursion mein ise karne ke do tarike hote hain: ek `visited` array lekar aur dusra **Swapping (Adla-Badli)** karke. Swapping wala tarika sabse optimized maana jata hai kyunki usme koi extra space nahi lagti.

### Swapping Logic:

Hum `index = 0` se shuru karte hain aur us `index` waale element ko uske aage ke saare elements (including itself) se bari-bari **swap** karte hain, fir aage badhte hain, aur laut te waqt wapas **backtrack (reswap)** kar dete hain taaki array pehle jaisa ho jaye.

---

## 2. Optimized C++ Code (Swapping Approach)

```cpp
#include <iostream>
#include <vector>

class Solution {
private:
    void backtrack(int index, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base Case: Jab index badhte-badhte array ke end par pahunch jaye
        if (index == nums.size()) {
            result.push_back(nums); // Ek valid arrangement mil gaya!
            return;
        }

        // Current index se lekar array ke end tak har element ko swap karke dekho
        for (int i = index; i < nums.size(); i++) {
            // 1. Swap kiya: Current element ko i-th element ki jagah bheja
            std::swap(nums[index], nums[i]);

            // 2. Recurse kiya: Agle index ke liye permutation banaye
            backtrack(index + 1, nums, result);

            // 3. Backtrack (Undo): Wapas swap kiya taaki original array kharab na ho
            std::swap(nums[index], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> ans = solver.permute(nums);

    std::cout << "Total Permutations:\n";
    for (const auto& perm : ans) {
        std::cout << "[";
        for (int x : perm) std::cout << x << " ";
        std::cout << "]\n";
    }
    return 0;
}

```

---

## 3. Ekdum Shandaar Dry Run (`nums = {1, 2, 3}`)

Chalo dekhte hain recursion tree kaise kaam karta hai. Shuruat hoti hai `index = 0` se.

### Level 0 (`index = 0`): Loop chalega `i = 0` se `2` tak.

* **Case 1: `i = 0**` $\rightarrow$ Swap(nums[0], nums[0]) $\rightarrow$ Array wahi raha `[1, 2, 3]`. Call gayi `backtrack(1)`.
* **Level 1 (`index = 1`):** Loop chalega `i = 1` se `2` tak.
* **`i = 1`:** Swap(nums[1], nums[1]) $\rightarrow$ Array `[1, 2, 3]`. Call gayi `backtrack(2)`.
* **Level 2 (`index = 2`):** `index == nums.size()` (Base Case Hit!). **`[1, 2, 3]`** result mein save ho gaya. Return!


* **`i = 2`:** Swap(nums[1], nums[2]) $\rightarrow$ Array ban gaya `[1, 3, 2]`. Call gayi `backtrack(2)`.
* **Level 2:** Base Case Hit! **`[1, 3, 2]`** save ho gaya. Return!
* *Backtrack:* Wapas swap karke array ko `[1, 2, 3]` kiya.






* **Case 2: `i = 1**` $\rightarrow$ Swap(nums[0], nums[1]) $\rightarrow$ Array ban gaya `[2, 1, 3]`. Call gayi `backtrack(1)`.
* Is branch mein jab andar loop chalega, toh hume do combinations milenge: **`[2, 1, 3]`** aur **`[2, 3, 1]`**.
* Laut te waqt reswap hokar array fir se `[1, 2, 3]` ban jayega.


* **Case 3: `i = 2**` $\rightarrow$ Swap(nums[0], nums[2]) $\rightarrow$ Array ban gaya `[3, 2, 1]`. Call gayi `backtrack(1)`.
* Is branch se hume milenge: **`[3, 2, 1]`** aur **`[3, 1, 2]`**.



Toh total combinations bante hain **6** (jo ki hota hai $3! = 3 \times 2 \times 1$).

---

## 4. Complexity Analysis (Bohot Gazab Hai!)

### ⏱️ Time Complexity: $\mathcal{O}(n \cdot n!)$

* **Explanation:** Agar array mein $n$ elements hain, toh total number of permutations strictly **$n!$ (n factorial)** hote hain. Iska matlab hamare recursion tree mein total leaf nodes (answers) $n!$ honge.
* Lekin har leaf node par pahunchne par, hum yeh line chalate hain: `result.push_back(nums);`.
* C++ mein $n$ size ke vector ko copy karne mein $\mathcal{O}(n)$ ka time lagta hai.
* Isliye, Total Time Complexity ho jaati hai: **$\mathcal{O}(n \cdot n!)$**.

> 💡 **Fun Fact:** $n!$ duniya ki sabse heavy complexities mein se ek hai. Agar $n = 12$ ho jaye, toh computer pighal jayega ($12! \approx 479 \text{ Million}$ operations). Isliye yeh question interviews mein sirf chote arrays ($n \le 10$) ke liye diya jata hai.

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Pura khel dhyan se dekho! Humne koi extra array ya visited array use nahi kiya. Humne original `nums` array ke andar hi adla-badli (in-place swap) kari hai.
* Extra space sirf **Recursion Call Stack** le raha hai.
* Tree ki maximum depth kitni ja rahi hai? $n$ (kyunki hum `index = 0` se `n` tak hi jaate hain).
* Isliye auxiliary space complexity ekdum linear hai: **$\mathcal{O}(n)$**. *(Final `result` vector ka space space complexity mein count nahi hota).*



Bhai, **Permutations II** (LeetCode 47) pichle waale Permutations question ka ek step up variant hai.

Pichle question mein array ke saare elements **unique** (alag-alag) the. Lekin is baar array mein **duplicate elements** ho sakte hain (jaise `nums = [1, 1, 2]`), aur interviewer aapse kahega ki *"Bhai, mujhe saare permutations toh chahiye, lekin koi bhi permutation **repeat (duplicate) nahi hona chahiye**."*

Agar hum bina soche samjhe pichla swapping wala code chalayenge, toh ek hi jaise arrangements baar-baar banenge, jo hume nahi chahiye.

Aaiye isko ekdum dhasu style mein, poori intuition aur unique technique ke saath samajhte hain!

---

## 1. Core Intuition: Duplicates Ko Kaise Rokein?

Maan lo tumhare paas array hai: `nums = [1, 1, 2]`.
Yahan dikkat tab aati hai jab hum pehle `1` ko kisi ke saath swap karein, aur fir *usi level par* dusre `1` ko bhi swap kar dein. Dono se bilkul same recursion branches nikalne lagengi.

### The Golden Rule 🌟

> **Ek hi recursive state (yaani loop ke andar), agar koi element pehle hi swap ho chuka hai, toh use dobara swap mat karo!**

Ise rokne ke liye hum har recursive call ke andar ek **`unordered_set` (ya frequency table)** banate hain. Yeh set track rakhta hai ki is waale level par humne kis-kis number ko pehle hi use kar liya hai. Agar koi number dobara aata hai, toh hum use `skip` (continue) kar dete hain.

---

## 2. Optimized C++ Code (Swapping + Set Pruning)

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
private:
    void backtrack(int index, std::vector<int>& nums, std::vector<std::vector<int>>& result) {
        // Base Case: Jab index array ke end par pahunch jaye
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Yeh set SIRF is current level/frame ke liye duplicates check karega
        std::unordered_set<int> used;

        for (int i = index; i < nums.size(); i++) {
            // Agar yeh element is position (index) par pehle hi swap ho chuka hai, toh skip karo
            if (used.count(nums[i])) {
                continue; 
            }

            // Element ko mark karo ki humne ise is level par use kar liya hai
            used.insert(nums[i]);

            // 1. Swap kiya
            std::swap(nums[index], nums[i]);

            // 2. Recurse kiya (Agle index ke liye)
            backtrack(index + 1, nums, result);

            // 3. Backtrack (Undo Swap)
            std::swap(nums[index], nums[i]);
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        // Sort karna zaroori nahi hai is approach mein, par samajhne mein aasan hota hai
        std::sort(nums.begin(), nums.end()); 
        
        backtrack(0, nums, result);
        return result;
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, 1, 2};
    std::vector<std::vector<int>> ans = solver.permuteUnique(nums);

    std::cout << "Unique Permutations:\n";
    for (const auto& perm : ans) {
        std::cout << "[";
        for (int x : perm) std::cout << x << " ";
        std::cout << "]\n";
    }
    return 0;
}

```

---

## 3. Ekdum Crystal Clear Dry Run (`nums = [1, 1, 2]`)

Chalo dhyan se dekhte hain ki hamara `used` set duplicates ko kaise block karta hai.

### Level 0 (`index = 0`): `used` set khali hai `{}`. Loop chalega `i = 0` se `2` tak.

1. **`i = 0` (`nums[0] = 1`):** * Kya `1` set mein hai? Nahi.
* `used` mein `1` daal diya $\rightarrow$ `{1}`.
* Swap(nums[0], nums[0]) $\rightarrow$ Array raha `[1, 1, 2]`. Call gayi `backtrack(1)`.
* Is branch se andar jaakar hume do unique answers milenge: **`[1, 1, 2]`** aur **`[1, 2, 1]`**.


2. **`i = 1` (`nums[1] = 1`):**
* Kya `1` set mein hai? **Haan bhai, hai!** (Kyunki `i=0` par humne use kiya tha).
* **`continue` chal gaya!** Isne bina kisi swap ya recursion ke is branch ko yahi kaala paani bhej diya (prune kar diya).


3. **`i = 2` (`nums[2] = 2`):**
* Kya `2` set mein hai? Nahi.
* `used` mein `2` daal diya $\rightarrow$ `{1, 2}`.
* Swap(nums[0], nums[2]) $\rightarrow$ Array ban gaya `[2, 1, 1]`. Call gayi `backtrack(1)`.
* Is branch se hume ek hi unique answer milega: **`[2, 1, 1]`**.



Toh total unique arrangements mile sirf **3**: `[1, 1, 2]`, `[1, 2, 1]`, aur `[2, 1, 1]`. Koi duplicate nahi aaya!

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(n \cdot n!)$ [Worst Case]

* **Explanation:** Agar saare elements unique hote, toh total $n!$ states banti. Jab duplicates hote hain, toh actual combinations $n! / (n_1! \cdot n_2! \dots)$ hote hain, jo ki $n!$ se bohot kam hain.
* Lekin worst-case boundary ko represent karne ke liye hum ise $\mathcal{O}(n \cdot n!)$ hi likhte hain kyunki har leaf state ko result vector mein copy karne mein $\mathcal{O}(n)$ ka time lagta hai. Set mein `insert` aur `count` operations average $\mathcal{O}(1)$ time lete hain.

### 💾 Space Complexity: $\mathcal{O}(n^2)$ [Worst Case]

* **Explanation:** 1. **Recursion Stack:** Max depth humesha array ki length ke barabar hogi, yaani **$\mathcal{O}(n)$**.
2. **`unordered_set` Space:** Har ek recursive call ke stack frame mein ek naya `used` set banta hai. Max depth $n$ hai, aur har set mein maximum $n$ elements aa sakte hain. Isliye stack frames ke saare sets ka space milakar worst case mein **$\mathcal{O}(n \times n) = \mathcal{O}(n^2)$** ho jata hai.




Bhai, **"Ways to Sum N"** (jise standard algorithm mein **"Combination Sum IV"** (LeetCode 377) ya **"Ways to Express N as Sum of Elements"** kehte hain) ek behad shaandar sawal hai.

Yeh sawal pichle waale *Target Sum Repetition* se miltajulta hai, lekin isme ek bada **twist (bhed)** hai. Is baar **order matter karta hai!** Maan lo array hai `[1, 2]` aur target hai `3`.

* Pichle question mein `{1, 2}` aur `{2, 1}` ko **ek hi** mana jata tha (Combination).
* Lekin is question mein `1 + 2` aur `2 + 1` ko **do alag-alag tareeqe** mana jayega (Permutation)!

Aaiye isko ekdum desi style mein, poori intuition, diagrammatic trace, code aur complexity ke saath dimaag mein bitha lete hain.

---

## 1. Core Intuition: Har Baar Shuruat Se Shuru Karo!

Kyunki is baar order matter karta hai (`1+2` is different from `2+1`), hum pichle questions ki tarah "Include/Exclude" karke index ko aage nahi badhayenge.

Iska simple logic yeh hai: **Har kadam par, hamare paas poore array ke saare elements chunne ki azaadi hai!**

Agar hume target `N` banana hai, toh hum array ke har ek element `x` ko uthakar dekhenge:

* Agar humne `x` ko chuna, toh ab bacha hua target kitna ho gaya? `N - x`.
* Ab recursion se bolenge, *"Bhai, baaki bache hue `N - x` ko banane ke kitne tareeqe hain, woh dhoodh ke lao."*

### Base Cases:

* **Target Mil Gaya:** Agar `N == 0` ho gaya, iska matlab humne perfect tarika dhoodh liya. Return `1`.
* **Aukat Se Bahar:** Agar `N < 0` (negative) ho gaya, iska matlab yeh element bohot bada tha, is raste se sum nahi ban sakta. Return `0`.

---

## 2. Recursive C++ Code (Brute Force)

```cpp
#include <iostream>
#include <vector>

class WaysToSumN {
public:
    int countWays(int target, const std::vector<int>& nums) {
        // Base Case 1: Target achieve ho gaya, 1 valid rasta mila
        if (target == 0) {
            // Jaise agar target 3 tha aur humne 1, 1, 1 chun liya, toh target 0 ho jayega
            return 1;
        }
        
        // Base Case 2: Target negative chala gaya, rasta bekaar hai
        if (target < 0) {
            return 0;
        }

        int totalWays = 0;

        // Har recursive call mein POORE array par loop chalega!
        for (int i = 0; i < nums.size(); i++) {
            // Target ko kam kiya aur dubara poore array ke liye call laga di
            totalWays += countWays(target - nums[i], nums);
        }

        return totalWays;
    }
};

int main() {
    WaysToSumN solver;
    std::vector<int> nums = {1, 2};
    int target = 3;

    std::cout << "Total ways to sum up to " << target << " is: " 
              << solver.countWays(target, nums) << "\n"; 
    // Output: 3 (Raste hain: 1+1+1, 1+2, 2+1)
    
    return 0;
}

```

---

## 3. Ekdum Makkhan Jaisa Dry Run (`nums = {1, 2}`, `target = 3`)

Aaiye dekhte hain ki `1+2` aur `2+1` dono kaise count hote hain:

1. **Main Call:** `solve(N = 3)`
* Loop chalega `i = 0` (element 1) aur `i = 1` (element 2) ke liye.
* **Branch A (Chuna 1):** Call gayi $\rightarrow$ `solve(3 - 1 = 2)`
* **Branch B (Chuna 2):** Call gayi $\rightarrow$ `solve(3 - 2 = 1)`


2. **Branch A ko andar tak dekhte hain (`N = 2`):**
* Fir se poore array par loop chala!
* **Branch A1 (Chuna 1):** Call gayi $\rightarrow$ `solve(2 - 1 = 1)`
* Is `N = 1` par fir loop chalega. Agar `1` chunenge toh `solve(0)` $\rightarrow$ **Return 1** (Rasta: `1 -> 1 -> 1`). Agar `2` chunenge toh `solve(-1)` $\rightarrow$ **Return 0**.


* **Branch A2 (Chuna 2):** Call gayi $\rightarrow$ `solve(2 - 2 = 0)` $\rightarrow$ **Base Case Hit! Return 1** (Rasta: `1 -> 2`).


3. **Branch B ko dekhte hain (`N = 1`):**
* Fir se poore array par loop chala!
* **Branch B1 (Chuna 1):** Call gayi $\rightarrow$ `solve(1 - 1 = 0)` $\rightarrow$ **Base Case Hit! Return 1** (Rasta: `2 -> 1`).
* **Branch B2 (Chuna 2):** Call gayi $\rightarrow$ `solve(1 - 2 = -1)` $\rightarrow$ **Return 0**.



Toh total kitne `1` return huye? Ek mila `1+1+1` se, ek mila `1+2` se, aur ek mila `2+1` se. Total Answer = **3**.

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(n^{\text{target}})$

* **Explanation:** Har ek state par hum poore array par iterate kar rahe hain, yaani har node se **$n$ branches** nikal rahi hain (jahan $n$ array ki size hai).
* Agar sabse chota element `1` hai, toh tree ki maximum depth kitni ho sakti hai? **`target`** tak.
* Ek aisa tree jiske har node se $n$ child nikal rahe hon aur height $H$ ho, uske total nodes hote hain $n^H$.
* Isliye brute force ki time complexity darrani ho jaati hai: **$\mathcal{O}(n^{\text{target}})$**.

> 💡 **Interview Super Tip:** Yeh code bohot zyada duplicate sub-problems solve karta hai (jaise upar dry run mein `N=1` do baar solve hua). Real interview mein aapko turant is par **Memoization (DP)** lagani padegi. Ek `vector<int> dp(target + 1, -1)` banakar states store karoge, toh time complexity gir kar seedhe **$\mathcal{O}(n \cdot \text{target})$** ho jayegi!

### 💾 Space Complexity: $\mathcal{O}(\text{target})$

* **Explanation:** Humne koi alag se bada matrix ya array nahi banaya hai. Extra space sirf **Recursion Call Stack** le raha hai.
* Tree ki gehrai maximum kab tak jayegi? Jab hum sabse chota element baar-baar chunenge, toh stack frame ka size `target` ke barabar ho jayega.
* Isliye auxiliary space complexity strictly linear hai, target ke proportional: **$\mathcal{O}(\text{target})$**.



Bhai, **Tower of Hanoi** sirf ek boring programming question nahi hai. Yeh asal mein ek bohot hi shaandar **Ancient Legend (pauranik kahani)** hai. Agar tum iski kahani samajh gaye, toh iska recursion code tum zindagi bhar nahi bhoologe.

Chalo, chalte hain sadiyon peeche, Kashi (Varanasi) ke ek rahasyamayi mandir mein...

---

## 🏛️ Kahani: Kashi Ke Mandir Ka Rahasya

Kahani ke mutabik, duniya ke shuruat mein bhagwan ne Kashi ke ek bade mandir mein **teen heere ke khambhe (3 Diamond Pegs/Rods)** lagaye. Inka naam rakha gaya: **A (Source)**, **B (Helper/Auxiliary)**, aur **C (Destination)**.

Bhagwan ne khambhe **A** par **64 sone ki plates (Disks)** rakh dein. Sabse badi plate sabse neeche thi, aur uske upar usse choti, fir usse choti... is tarah se ek perfect pyramid bana diya gaya.

Mandir ke pujariyon (Priests) ko ek kaam saumpa gaya: *"Tumhe khambhe A ki saari 64 plates ko khambhe C par shifts karna hai."* Lekin unhe do kade niyam (rules) diye gaye:

1. **Rule 1:** Ek baar mein sirf **ek hi plate** uthayi ja sakti hai.
2. **Rule 2:** Koi bhi badi plate, kisi **choti plate ke upar nahi rakhi ja sakti**. (Hamesha choti plate upar rahegi, badi neeche).

Kahani kehti hai ki jis din pujariyon ne saari 64 plates ko sahi salaamat khambhe C par transfer kar diya... **yeh srishti (universe) khatam ho jayegi aur pralaya aa jayega!**

---

## 🧠 Theory Aur Recursion Ki Intuition

Ab socho, 64 plates ko shift karna toh dimaag dahi karne wala kaam hai. Pujariyon ne socha ki is mushkil kaam ko aasan kaise banayein? Unhone lagaya **Recursion ka dimaag (Divide and Conquer)**.

Maan lo hamare paas $N$ plates hain (chalo pehle sirf 3 plates maante hain). Mujhe saari $N$ plates ko **A** se **C** par le jana hai, **B** ki madad se.

Pujariyon ne isko 3 simple steps mein tod diya:

1. **Step 1:** Pehle upar ki $N-1$ (yaani 2) plates ko kisi tarah **A से B** par bhej do (Is baar **C** helper ban jayega).
2. **Step 2:** Ab **A** par akeli sabse badi ($N$-th) plate bachi hai. Use uthao aur direct **A से C** par bakhushi rakh do.
3. **Step 3:** Jo $N-1$ plates humne **B** par chhodi thi, unhe uthao aur **B से C** par bhej do (Is baar **A** helper ban jayega).

Bhai, yahi toh recursion hai! Ek bade kaam ($N$ plates) ko karne ke liye, humne wahi same kaam choti plates ($N-1$) ke liye karwaya.

---

## 💻 C++ Code (Kahani Ke Words Mein)

Ab jab tum code dekhoge, toh tumhe kahani saaf dikhegii:

```cpp
#include <iostream>

// N = kitni plates hain, from = jahan se uthana hai, to = jahan rakhna hai, aux = helper rod
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    // Base Case: Agar sirf 1 hi plate bachi hai, toh bina kisi tension ke direct move kar do
    if (n == 1) {
        std::cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << "\n";
        return;
    }

    // Step 1: Upar ki N-1 plates ko 'from' se 'aux' par bhejo, 'to' ko helper bana kar
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    // Step 2: Sabse badi N-th plate ko direct 'from' se 'to' par rakh do
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << "\n";

    // Step 3: Jo N-1 plates 'aux' par thi, unhe 'to' par bhejo, 'from' ko helper bana kar
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Hum 3 plates ke liye check kar rahe hain
    std::cout << "3 Plates ke liye saare moves:\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // A se C par jaana hai, B helper hai
    return 0;
}

```

---

## ⏱️ Detailed Complexity Analysis: Pralaya Kab Aayega?

Aaiye ab mathematically dekhte hain ki kya sach mein pralaya aane wala hai?

### Time Complexity: $\mathcal{O}(2^n)$

* **Explanation:** Agar $N$ plates ke liye lagne waale steps ko hum $T(N)$ manein, toh hamari equation banti hai:

$$T(N) = 2T(N-1) + 1$$



(Do baar $N-1$ ke liye call lag rahi hai, aur 1 baar badi plate move ho rahi hai).
* Jab aap is recurrence relation ko solve karoge (Mathematical Induction se), toh total moves aate hain: **$2^n - 1$**.
* Har step par hum $\mathcal{O}(1)$ ka kaam kar rahe hain (sirf print kar rahe hain), isliye Total Time Complexity ho gayi **$\mathcal{O}(2^n)$**.

#### 🌌 Pralaya Ki Calculation (Fun Fact):

Mandir mein total **64 plates** hain.
Total moves kitne lagenge? $2^{64} - 1$.
Yeh number pata hai kitna bada hai? **18,446,744,073,709,551,615 moves!**

Agar mandir ke pujari din-raat bina ruke **1 second mein 1 plate** bhi shift karein, toh saari plates ko shift karne mein lagbhag **585 Billion Years (585 arab saal)** lagenge! Hamari dharti ki umra abhi sirf 4.5 Billion years hai. Toh interviewer ko bolna: *"Bhai tension mat lo, pralaya aane mein abhi bohot time hai!"*

### Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Humne koi array ya extra vector nahi banaya.
* Humara recursion tree ek baar mein seedhe gehrai (depth) tak jata hai. Ek samay par system ke call stack memory mein maximum utne hi frames open honge jitni plates hain, yaani tree ki height, jo ki **$n$** hai.
* Isliye auxiliary space complexity strictly linear hai: **$\mathcal{O}(n)$**.



Bhai, **Tower of Hanoi (3 Plates ke liye)** ka ek-ek step ka aisa dry run dekhte hain ki saara bhed khul jayega.

Humari rods hain: **A (Source)**, **B (Helper)**, aur **C (Destination)**.
Shuruat mein **A** par teeno plates hain: **[1, 2, 3]** (jahan 1 sabse choti hai aur 3 sabse badi).

Hamara function call hai: `TOH(3, 'A', 'C', 'B')`

*(Matlab: 3 plates ko 'A' se 'C' par le jao, 'B' ka use karke).*

---

## 🌳 The Recursion Tree (Poora Khel Yahan Hai)

Jab hum `TOH(3, 'A', 'C', 'B')` chalate hain, toh hamare 3 steps ke mutabik yeh tree banta hai. Isko dhyan se dekhna, isme har call ke baad rods ke roles (Source, Destination, Helper) badal rahe hain!

---

## 🚶‍♂️ Step-by-Step Execution Trace (In Order)

Chalo ab computer ki tarah is tree ke andar chalte hain (Left to Right, Depth First Search).

### 📍 Left Side: Upar ki 2 plates ko A se B par bhejna

* **Step 1:** `TOH(3, 'A', 'C', 'B')` ne apni pehli line chalayi aur left call lagayi: `TOH(2, 'A', 'B', 'C')`.
*(Iska matlab: 2 plates ko A se B par le jao, C ko helper bana kar).*
* **Step 2:** `TOH(2, 'A', 'B', 'C')` ne bhi apni pehli line chalayi aur aur gehrai mein call lagayi: `TOH(1, 'A', 'C', 'B')`.
*(Iska matlab: 1 plate ko A se C par le jao, B ko helper bana kar).*
* **Step 3 [MOVE 1]:** `TOH(1, 'A', 'C', 'B')` par **Base Case Hit** ho gaya ($n=1$).
📢 **Output:** `Move disk 1 from A to C`
*Rods ki haalat:* A: `[2, 3]`, B: `[]`, C: `[1]`
* **Step 4 [MOVE 2]:** Ab recursion wapas upar lauta `TOH(2, 'A', 'B', 'C')` par. Isne apni dusri line chalayi (badi plate ko move karne ki).
📢 **Output:** `Move disk 2 from A to B`
*Rods ki haalat:* A: `[3]`, B: `[2]`, C: `[1]`
* **Step 5:** Ab `TOH(2, 'A', 'B', 'C')` ne apni teesri line chalayi (right call): `TOH(1, 'C', 'B', 'A')`.
*(Iska matlab: Jo plate C par chhodi thi use B par le jao, A ko helper bana kar).*
* **Step 6 [MOVE 3]:** `TOH(1, 'C', 'B', 'A')` par fir se **Base Case Hit** hua.
📢 **Output:** `Move disk 1 from C to B`
*Rods ki haalat:* A: `[3]`, B: `[1, 2]`, C: `[]`

---

### 👑 Center: Sabse badi 3rd plate ko Destination par bhejna

Ab hamara aadha kaam ho gaya! Upar ki do plates safely **B** par pahunch chuki hain aur **A** par sirf sabse badi 3rd plate akeli bachi hai. Ab recursion bilkul top node `TOH(3, 'A', 'C', 'B')` ki dusri line par wapas lauta.

* **Step 7 [MOVE 4]:** Main function ne sabse badi plate ko direct destination par bheja.
📢 **Output:** `Move disk 3 from A to C`
*Rods ki haalat:* A: `[]`, B: `[1, 2]`, C: `[3]`

---

### 📍 Right Side: Jo 2 plates B par hain, unhe B se C par bhejna

Ab hum tree ke right hisse mein jaayenge: `TOH(2, 'B', 'C', 'A')`.

*(Iska matlab: B par rakhi dono plates ko C par le jao, A ko helper bana kar).*

* **Step 8:** `TOH(2, 'B', 'C', 'A')` ne apni pehli line chalayi aur left call lagayi: `TOH(1, 'B', 'A', 'C')`.
*(Iska matlab: 1 plate ko B se A par le jao, C ko helper bana kar).*
* **Step 9 [MOVE 5]:** Base Case Hit!
📢 **Output:** `Move disk 1 from B to A`
*Rods ki haalat:* A: `[1]`, B: `[2]`, C: `[3]`
* **Step 10 [MOVE 6]:** Ab recursion wapas lauta `TOH(2, 'B', 'C', 'A')` par aur isne apni dusri line chalayi.
📢 **Output:** `Move disk 2 from B to C`
*Rods ki haalat:* A: `[1]`, B: `[]`, C: `[2, 3]`
* **Step 11:** Ab isne apni aakhiri right call lagayi: `TOH(1, 'A', 'C', 'B')`.
*(Iska matlab: Jo aakhiri plate A par bachi hai use C par le jao, B ko helper bana kar).*
* **Step 12 [MOVE 7]:** Base Case Hit!
📢 **Output:** `Move disk 1 from A to C`
*Rods ki haalat:* A: `[]`, B: `[]`, C: `[1, 2, 3]`

---

## 📊 Final Summary Table

Humne formula mein padha tha ki total moves $2^n - 1$ hote hain. Kyunki $n=3$ tha, toh total moves hone chahiye the $2^3 - 1 = \mathbf{7}$.

Aap dekh sakte ho computer ne exact 7 moves mein bina kisi bade ko chote ke upar rakhe saari plates shift kar dein:

| Move No. | Disk | From Rod | To Rod | Current State of Rods (A, B, C) |
| --- | --- | --- | --- | --- |
| **Start** | - | - | - | A: `[1,2,3]`, B: `[]`, C: `[]` |
| **1** | Disk 1 | A | C | A: `[2,3]`, B: `[]`, C: `[1]` |
| **2** | Disk 2 | A | B | A: `[3]`, B: `[2]`, C: `[1]` |
| **3** | Disk 1 | C | B | A: `[3]`, B: `[1,2]`, C: `[]` |
| **4** | Disk 3 | A | C | A: `[]`, B: `[1,2]`, C: `[3]` |
| **5** | Disk 1 | B | A | A: `[1]`, B: `[2]`, C: `[3]` |
| **6** | Disk 2 | B | C | A: `[1]`, B: `[]`, C: `[2,3]` |
| **7** | Disk 1 | A | C | A: `[]`, B: `[]`, C: `[1,2,3]` |

Bhai, ab poora Tower of Hanoi ka kanch jaisa dry run clear hai!





Bhai, **Predict the Winner** (LeetCode 486) recursion aur Game Theory ka ek lajawab aur dhasu question hai. Isko samajhne ke liye tumhe dimaag mein ek asli **2-Player Board Game** ki tasveer banani padegi.

Aaiye isko ekdum desi style mein poori theory, intuition, math aur ek-ek step ke dry run ke saath dimaag mein fit karte hain!

---

## 1. Core Intuition: Game Ke Niyam (Rules)

Maan lo tum aur tumhara ek dost (Player 1 aur Player 2) ek game khel rahe ho. Saamne ek array rakha hai, jaise: `nums = [1, 5, 2]`.

* **Niyam 1:** Har turn par ek player ya toh array ke **bilkul shuruat (Front)** se element utha sakta hai, ya fir **bilkul aakhiri (End)** se. Beech se koi element nahi utha sakta.
* **Niyam 2:** Jo element utha liya, woh array se gayab ho jayega.
* **Niyam 3:** Dono players ekdum shaatir (optimal) hain. Iska matlab dono apna score **maximum** karne ki koshish karenge aur saamne waale ka score **minimum** karne ki koshish karenge.

---

## 2. Mathematical Strategy: Net Score Concept

Is problem ko recursion se solve karne ki sabse aasan trick hai **Net Score (P1 - P2)** nikaalna.

Hum recursion se kahenge: *"Bhai, agar main abhi Player 1 hoon aur mere paas array `nums[i ... j]` tak bacha hai, toh mera max net score kitna ho sakta hai?"*

Mere paas do options hain:

1. **Main Shuruat ka element (`nums[i]`) uthau:** Agar maine `nums[i]` liya, toh bache hue array `[i+1 ... j]` par agli turn mere dost (Player 2) ki aayegi. Woh bhi shaatir hai, toh woh apna best karega. Isliye mera net score hoga:

$$\text{Option 1} = \text{nums}[i] - \text{solve}(i+1, j)$$


2. **Main Aakhiri ka element (`nums[j]`) uthau:** Agar maine `nums[j]` liya, toh bache hue array `[i ... j-1]` par turn mere dost ki aayegi. Mera net score hoga:

$$\text{Option 2} = \text{nums}[j] - \text{solve}(i, j-1)$$



Kyunki main jeetna chahta hoon, main in dono options mein se **Maximum** chununga!

### Base Case:

* Jab array mein sirf **ek hi element** bachega (`i == j`), toh jo bhi player us turn par hoga, woh use utha lega. Wahan se direct return kar do `nums[i]`.

---

## 3. Clean C++ Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    // Yeh function hume max Net Score (Player1 - Player2) nikaal kar dega
    int getNetScore(int i, int j, const std::vector<int>& nums) {
        // Base Case: Agar sirf ek hi element bacha hai
        if (i == j) {
            return nums[i];
        }

        // Option 1: Shuruat ka element uthaya
        int pickLeft = nums[i] - getNetScore(i + 1, j, nums);

        // Option 2: Aakhiri ka element uthaya
        int pickRight = nums[j] - getNetScore(i, j - 1, nums);

        // Dono mein se jo max fayda de, woh chun lo
        return std::max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(std::vector<int>& nums) {
        // Agar Player 1 ka net score >= 0 aata hai, iska matlab Player 1 jeet gaya ya tie hua
        return getNetScore(0, nums.size() - 1, nums) >= 0;
    }
};

int main() {
    Solution solver;
    std::vector<int> nums = {1, 5, 2};

    if (solver.predictTheWinner(nums)) {
        std::cout << "Haan bhai, Player 1 hamesha jeetega!\n";
    } else {
        std::cout << "Nahi bhai, Player 1 haar jayega.\n";
    }
    return 0;
}

```

---

## 4. Ekdum Kadak Dry Run (`nums = [1, 5, 2]`)

Shuruat hoti hai `i = 0, j = 2` se. Player 1 ki turn hai.

1. **Main Call:** `getNetScore(0, 2)`
* **Option 1 (Pick Left = 1):** `1 - getNetScore(1, 2)`
* **Option 2 (Pick Right = 2):** `2 - getNetScore(0, 1)`


2. **Chalo pehle Option 1 ke andar chalte hain (`getNetScore(1, 2)` jahan array `[5, 2]` hai):**
* Ab turn hai Player 2 ki. Woh bhi khud ko jitane ke liye dono options check karega:
* **Pick Left (5):** `5 - getNetScore(2, 2)`. Kyunki `i==j==2` (Base Case), `getNetScore(2,2)` return karega `nums[2] = 2`. Net = $5 - 2 = \mathbf{3}$.
* **Pick Right (2):** `2 - getNetScore(1, 1)`. Base case `getNetScore(1,1)` return karega `nums[1] = 5`. Net = $2 - 5 = -3$.
* Player 2 shaatir hai, woh max chunega: $\max(3, -3) = 3$.
* Toh `getNetScore(1, 2)` ka final return aaya **`3`**.
* Isko Option 1 ki equation mein rakho: $\text{Option 1} = 1 - 3 = \mathbf{-2}$.


3. **Ab Main Call ka Option 2 check karte hain (`getNetScore(0, 1)` jahan array `[1, 5]` hai):**
* Fir se Player 2 ki turn hai:
* **Pick Left (1):** $1 - \text{getNetScore}(1, 1) = 1 - 5 = -4$.
* **Pick Right (5):** $5 - \text{getNetScore}(0, 0) = 5 - 1 = 4$.
* Player 2 max chunega: $\max(-4, 4) = 4$.
* Toh `getNetScore(0, 1)` ka final return aaya **`4`**.
* Isko Option 2 ki equation mein rakho: $\text{Option 2} = 2 - 4 = \mathbf{-2}$.


4. **Main Call Ka Decision:**
* Player 1 ke paas dono options se score aaya: $\max(\text{Option 1}, \text{Option 2}) = \max(-2, -2) = \mathbf{-2}$.
* Kyunki final net score `-2` (yaani $< 0$) aaya, iska matlab Player 1 chahe jo kar le, optimal game khelne par Player 2 hi jeetega.
* `predictTheWinner` return karega **`false`**.



---

## 5. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(2^n)$

* **Explanation:** Har ek state par array ke dono ends (`i` aur `j`) se element uthane ke strictly 2 options hain. Array ka size $n$ hai, toh recursion tree ki depth max $n$ tak jayegi.
* Isliye total nodes $2^n$ banenge, aur time complexity exponential ho jayegi: **$\mathcal{O}(2^n)$**.
* *Interview Tip:* Interviewer ko bolna ki real interviews mein hum ise **Memoization (DP)** se optimize karte hain. Ek $n \times n$ ka 2D matrix (`dp[20][20]`) lekar states store karenge, toh time complexity gir kar seedhe **$\mathcal{O}(n^2)$** ho jayegi!

### 💾 Space Complexity: $\mathcal{O}(n)$

* **Explanation:** Humne koi extra space internally algorithm chalane ke liye nahi li hai. Extra space sirf recursion ka call stack le raha hai.
* Ek baar mein recursion strictly ek hi raste ke leaf node tak jata hai (DFS), toh stack mein maximum $n$ frames hi open honge.
* Isliye auxiliary space complexity linear hai: **$\mathcal{O}(n)$**.



Bhai, **Rat in a Maze** ki kahani aur backtracking ki asli soch (intuition) ko ekdum dhyan se samajh. Agar tu ek baar yeh dimaag lagana seekh gaya, toh tu kisi bhi grid-based backtracking problem (jaise N-Queens, Word Search) ko chutkiyon mein phod dega.

Aaiye bilkul basic se dimaag kholte hain ki **"Sona kaise hai?"**

---

## 1. Kadak Intuition: Chuuhe Ki Tarah Socho 🐭

Maan le tu ek andheri bhool-bhulaiya (maze) mein fasa hai aur tere paas ek pen hai. Tera target hai bahar nikalna. Tu kaise chalega?

1. **Blind Exploration (Aage badho):** Tu kisi bhi ek khali raste par aage badhta jayega.
2. **Nishan Lagana (Mark Visited):** Jis-jis raste ya kamre se tu guzrega, tu wahan deewar par pen se cross `(X)` bana dega. Kyun? Taaki tu galti se gol-gol ghoom kar usi kamre mein dobara na aa jaye (infite loop se bachne ke liye).
3. **Piche Hatna (Backtrack):** Chalte-chalte aage ek band deewar (`0`) aa gayi. Ab tu kya karega? Tu wahan royege nahi. Tu wapas piche mudega (backtrack karega) us jagah tak, jahan se koi dusra rasta kat raha tha.
4. **Nishan Mitana (Unmark/Undo):** Jab tu piche laut raha hoga, toh tu raste mein banaye gaye cross `(X)` ke nishano ko mitaata jayega. **Kyun? Yeh sabse important point hai!** Socho agar ek rasta `Path A` se hokar destination tak nahi gaya, toh ho sakta hai ki koi dusra `Path B` ghoom kar usi raste se hote hue destination tak chala jaye! Agar tu nishan nahi mitaega, toh aage aane waale raaste us cell ko hamesha ke liye blocked samjhenge.

---

## 2. Decision Tree: 4 Raaste Aur Soch Ka Tarika

Har ek cell `(row, col)` par jab chuuha khada hota hai, toh uske paas **4 vikalp (choices)** hote hain. Hum hamesha ek fixed order follow karte hain (jaise Lexicographical order: **D -> L -> R -> U**):

* **Down:** `(row + 1, col)`
* **Left:** `(row, col - 1)`
* **Right:** `(row, col + 1)`
* **Up:** `(row - 1, col)`

### Ek Cell Par Khade Hokar 3 Filter Lagane Hain:

Jab bhi chuuha agle cell par kadam rakhne ki sochega, woh apne dimaag mein 3 sawal puchega (Validation checks):

1. **"Kya main maze ke andar hoon?"** (Boundary check: `row` aur `col` 0 se $N-1$ ke beech hone chahiye).
2. **"Kya wahan deewar toh nahi hai?"** (`maze[row][col] == 1` hona chahiye, `0` nahi).
3. **"Kya main yahan pehle aa chuka hoon?"** (`visited[row][col] == false` hona chahiye).

Agar teeno ka jawab **"Haan"** hai, tabhi chuuha agla kadam badhaega.

---

## 3. Pura Game Kaise Chalta Hai? (Detailed Flow)

Maan lo ek chota sa $3 \times 3$ ka maze hai:

```text
(0,0)[1] -> (0,1)[1] -> (0,2)[0]
    |
(1,0)[1] -> (1,1)[0] -> (1,2)[1]
    |
(2,0)[1] -> (2,1)[1] -> (2,2)[1]  (Cheese 🧀)

```

1. **Start `(0,0)`:** Chuuha `(0,0)` par aaya. Isne `visited[0][0] = true` kiya.
* Pehle check kiya **Down** $\rightarrow$ `(1,0)` saaf hai? Haan (`1` hai aur visited nahi hai).
* Chuuha turant chala gaya `(1,0)` par. (`path = "D"`)


2. **Cell `(1,0)`:** Isne `visited[1][0] = true` kiya.
* Check kiya **Down** $\rightarrow$ `(2,0)` saaf hai? Haan.
* Chuuha chala gaya `(2,0)` par. (`path = "DD"`)


3. **Cell `(2,0)`:** Isne `visited[2][0] = true` kiya.
* Check kiya **Down** $\rightarrow$ Out of bounds (Khatam).
* Check kiya **Left** $\rightarrow$ Out of bounds.
* Check kiya **Right** $\rightarrow$ `(2,1)` saaf hai? Haan.
* Chuuha chala gaya `(2,1)` par. (`path = "DDR"`)


4. **Cell `(2,1)`:** Isne `visited[2][1] = true` kiya.
* Check kiya **Right** $\rightarrow$ `(2,2)` saaf hai? Haan.
* Chuuha chala gaya `(2,2)` par. (`path = "DDRR"`)


5. **Cell `(2,2)`:** **Base Case Hit!** `(2,2)` hi toh destination tha! Chuuhe ko cheese mil gayi. Path `"DDRR"` final result ke bag mein save ho gaya.

### Ab Backtracking Kaise Hogi?

Jab `(2,2)` se return hoga, toh computer wapas `(2,1)` ka bacha hua function chalayega.

* `(2,1)` par `Right` check ho chuka tha, ab woh `Up` check karega. `Up` par `(1,1)` hai jo ki `0` (deewar) hai.
* Aap saare options khatam! Toh `(2,1)` ka function band hone se pehle deewar se apna nishan mitayega: `visited[2][1] = false`. (Yeh hua backtrack).
* Wapas piche lauta `(2,0)` par. Iske bhi saare check ho gaye the, isne bhi kiya `visited[2][0] = false` aur piche laut gaya.

Yeh process tab tak chalta rahega jab tak saare ke saare unique raaste explore nahi ho jaate.

---

## 🧠 Interviewer Ko Kaise Impress Karein? (Golden Words)

Interview mein jab iska explanation do, toh yeh line zaroor bolna:

> *"Sir, Rat in a Maze is a classic State-Space Tree problem. We use **DFS (Depth First Search)** to explore a path to its absolute depth. If we hit a dead-end or a boundary, we **backtrack** by popping the state from the recursion stack and **undoing the visited mark** so that the same cell can be reused for other potential valid paths."*

Bhai, ab bata, chuuhe ki poori kahani aur dimaag ka dhyan ekdum crystal clear hua ki nahi?


Bhai, **Rat in a Maze** (LeetCode / GFG Standard Problem) recursion aur **Backtracking** ka ek behad hi iconic aur dhasu question hai. Isko samajhne ke liye tumhe dimaag mein ek chote se choohe (rat) aur uske raste ki tasveer banani padegi.

Aaiye isko ekdum desi style mein poori theory, niyam (rules), code aur complexity ke saath dimaag mein fit karte hain!

---

## 1. Core Intuition: Kahani Kya Hai?

Maan lo tumhare paas $N \times N$ size ka ek grid (maze/bhool-bhulaiya) hai.

* Chuuha shuruat mein khada hai sabse pehle cell par, yaani **`(0, 0)`** par (Source).
* Use pahunchna hai bilkul aakhiri cell par, yaani **`(N-1, N-1)`** par (Destination), jahan uski cheese (khaana) rakhi hai.

### Grid Ke Rules:

* Jis cell mein **`1`** likha hai, woh rasta saaf hai, chuuha wahan ja sakta hai.
* Jis cell mein **`0`** likha hai, wahan badi si deewar (blockage) hai, chuuha wahan nahi ja sakta.
* Chuuha ek baar mein 4 directions mein chal sakta hai: **Down (D), Left (L), Right (R), aur Up (U)**.

### Backtracking Ka Asli Khel 🌟

Chuuha shaatir hai. Woh ek raste par aage badhta jata hai. Lekin agar aage jaakar rasta block ho jaye (dead end aa jaye), toh chuuha rone nahi baithta! Woh chupchap apne kadam piche leta hai (**Backtrack** karta hai) aur wapas us junction par aata hai jahan se koi dusra rasta nikal raha tha.

To avoid going in circles (jaise ek hi cell par baar-baar ghoomna), chuuha jis raste par jata hai, wahan ek nishan laga deta hai (**Visited Mark** kar deta hai). Jab woh wapas piche laut ta hai, toh us nishan ko mita deta hai (**Unmark** kar deta hai) taaki koi dusra valid rasta wahan se guzar sake.

---

## 2. Standard C++ Code (Backtracking Approach)

```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void solve(int row, int col, std::vector<std::vector<int>>& maze, int n, 
               std::string currentPath, std::vector<std::string>& result, 
               std::vector<std::vector<bool>>& visited) {
        
        // Base Case: Agar chuuha destination par pahunch gaya
        if (row == n - 1 && col == n - 1) {
            result.push_back(currentPath);
            return;
        }

        // 4 Directions mein chalne ke liye directions arrays (D, L, R, U order mein)
        // Down, Left, Right, Up
        int dRow[] = {1, 0, 0, -1};
        int dCol[] = {0, -1, 1, 0};
        char directionChar[] = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++) {
            int nextRow = row + dRow[i];
            int nextCol = col + dCol[i];

            // Check karo ki kya agla kadam maze ke andar hai, deewar toh nahi hai, aur visited toh nahi hai?
            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && 
                maze[nextRow][nextCol] == 1 && !visited[nextRow][nextCol]) {
                
                // 1. Step Aage Badhao: Mark visited
                visited[row][col] = true;
                
                // 2. Recurse: Agle cell ke liye call lagao
                solve(nextRow, nextCol, maze, n, currentPath + directionChar[i], result, visited);
                
                // 3. Backtrack (Undo): Laut te waqt visited ko wapas false karo
                visited[row][col] = false;
            }
        }
    }

public:
    std::vector<std::string> findPath(std::vector<std::vector<int>>& maze, int n) {
        std::vector<std::string> result;
        // Agar starting ya ending cell hi block ho, toh rasta nahi ban sakta
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return result;

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        
        solve(0, 0, maze, n, "", result, visited);
        return result;
    }
};

int main() {
    Solution solver;
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = 4;
    std::vector<std::string> paths = solver.findPath(maze, n);

    std::cout << "Chuuhe ke nikalne ke saare raste:\n";
    for (const std::string& path : paths) {
        std::cout << path << "\n";
    }
    return 0;
}

```

---

## 3. Step-by-Step Chuuhe Ka Safar (Dry Run Intuition)

Maan lo maze aisa hai:

```text
(0,0)[1]  (0,1)[0]
(1,0)[1]  (1,1)[1]

```

Chuuha `(0,0)` par hai. Target `(1,1)` hai.

1. **`solve(0,0)` se shuruat:**
* `visited[0][0] = true` ho gaya.
* Chuuha 4 directions check karega. Down ja sakta hai? Haan, `(1,0)` par `1` hai.
* Call gayi $\rightarrow$ `solve(1,0, path="D")`.


2. **Inside `solve(1,0)`:**
* `visited[1][0] = true` ho gaya.
* Right ja sakta hai? Haan, `(1,1)` par `1` hai.
* Call gayi $\rightarrow$ `solve(1,1, path="DR")`.


3. **Inside `solve(1,1)`:**
* **Base Case Hit!** Destination mil gaya. Path `"DR"` result mein save ho gaya. Return!


4. **Backtracking (Wapas lautna):**
* Jab `solve(1,0)` khatam hoga, toh laut te waqt `visited[1][0] = false` ho jayega.
* Jab `solve(0,0)` khatam hoga, toh laut te waqt `visited[0][0] = false` ho jayega.
* Is tarah se grid saaf rehta hai baaki ke raaston ke liye.



---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(3^{n^2})$ [Worst Case]

* **Explanation:** Grid mein total cells kitne hain? $N \times N = N^2$.
* Har ek cell par khade hokar chuuhe ke paas theoretically 4 directions hoti hain. Lekin jis cell se chuuha abhi-abhi aaya hai, wahan woh wapas nahi jayega (kyunki woh visited hai). Isliye effective choices har cell par **3** hi bachti hain.
* Worst case mein, chuuha saare cells explore karega, toh total recursive states lagbhag $3 \times 3 \times 3 \dots (N^2 \text{ times})$ ban sakti hain.
* Isliye upper-bound complexity exponential hoti hai: **$\mathcal{O}(3^{n^2})$**.

### 💾 Space Complexity: $\mathcal{O}(n^2)$

* **Explanation:** 1. **Visited Matrix:** Humne $N \times N$ ka ek `visited` matrix banaya hai jo **$\mathcal{O}(n^2)$** space leta hai.
2. **Recursion Call Stack:** Chuuha bade se bada kitna lamba rasta taiyar kar sakta hai bina repeat kiye? Poore maze ke saare cells ghoom lega, yaani recursion tree ki max depth $N^2$ ho sakti hai. Stack space bhi hua **$\mathcal{O}(n^2)$**.
* Dono ko milakar total space complexity strictly quadratic rehti hai: **$\mathcal{O}(n^2)$**.




Bhai, **"N-th Binary Number"** (jise aksar coding questions mein *“Generate Binary Numbers from 1 to N”* ya *“Find N-th Binary Representation”* ke roop mein pucha jata hai) ek bohot hi behtareen aur foundational concept hai.

Isme hume bina kisi heavy mathematical formulas ke, sirf logic aur pattern ka use karke **N-th binary number** tak pahunchna hota hai. Aaiye iski poori theory aur dimaag lagane ka tarika (intuition) ekdum desi style mein samajhte hain.

---

## 1. Core Intuition: Binary Tree Ka Pattern 🌲

Binary numbers (0 aur 1) ka ek bohot hi shaandar rule hota hai: **"Har naya binary number, apne pichle kisi valid binary number ke aage `0` ya `1` lagane se banta hai."**

Maan lo tumhare paas pehla valid number hai `1`. Ab isse tum do naye numbers paida kar sakte ho:

1. `1` ke aage **`0`** lagao $\rightarrow$ Ban gaya `10` (Decimal mein 2)
2. `1` ke aage **`1`** lagao $\rightarrow$ Ban gaya `11` (Decimal mein 3)

Ab agar tumhare paas `10` hai, toh isse fir do naye raste nikalte hain:

* `10` ke aage **`0`** lagao $\rightarrow$ `100` (Decimal mein 4)
* `10` ke aage **`1`** lagao $\rightarrow$ `101` (Decimal mein 5)

Agar tum dhyan se dekho, toh yeh ek **Perfect Binary Tree** banata ja raha hai, jahan har ek node ke do children hain (ek `0` append karne par aur ek `1` append karne par).

---

## 2. Soch Ka Tarika: Level by Level (BFS Approach)

Jab hume sequence mein numbers chahiye hote hain (jaise 1st, 2nd, 3rd, 4th...), toh hum recursion (DFS) ke badle **Queue Data Structure (BFS)** ki tarah sochte hain. Kyun? Kyunki hume pehle chote numbers chahiye, fir unse bade, fir unse bade.

### Pura Khel Kaise Chalta Hai? (Mental Flow)

Maan lo ek Queue (line) hai. Hum shuruat mein line mein sabse pehla number **`"1"`** khada kar dete hain.

1. **Pehla Kadam:** Humne line ke sabse aage waale element (`"1"`) ko bahar nikala. Yeh hamara **1st Binary Number** hai.
2. **Naye Numbers Banana:** Ab is `"1"` ka use karke hum turant do naye numbers banayenge aur unhe line ke sabse piche khada kar denge:
* `"1" + "0" = "10"` (Line ke piche chala gaya)
* `"1" + "1" = "11"` (Yeh bhi line ke piche chala gaya)


3. **Dusra Kadam:** Ab line mein sabse aage kaun khada hai? `"10"`. Humne ise bahar nikala. Yeh hamara **2nd Binary Number** hai.
4. **Fir se Naye Numbers:** Is `"10"` ke aage `0` aur `1` lagao:
* `"100"` aur `"101"` ko line ke piche bhej do.


5. **Teesra Kadam:** Ab line ke aage khada hai `"11"`. Ise nikala, yeh hua hamara **3rd Binary Number**. Isse naye numbers bane `"110"` aur `"111"`.

Yeh process tab tak chalta rahega jab tak hum **N-th** baar element ko line se bahar nahi nikal lete. Jo N-th baar bahar niklega, wahi hamara answer hoga!

---

## 3. Mathematical Relation: Bitwise Soch (Alternative Theory)

Agar interviewer aapse kahe ki *"Bhai mujhe Queue ya Tree se nahi, direct math se samjhao"*, toh wahan kaam aati hai **Bitwise Right Shift aur Masking** ki theory.

Kisi bhi Decimal number `N` ka binary nikalne ka matlab hota hai uske andar bethi hui **Bits (0 aur 1)** ko check karna.

* **Last Bit Kaise Check Karein?** Hum `N` ka **Bitwise AND (`&`) 1** ke saath karte hain. Agar `N & 1` ka result `1` aata hai, toh aakhiri bit `1` hai. Agar `0` aata hai, toh `0` hai.
* **Aage Kaise Badhein?** Ek bit check karne ke ke baad hum number ko **Right Shift (`>> 1`)** kar dete hain, jisse woh number aadha (`N / 2`) ho jata hai aur hamare paas agli bit check karne ka mauka hota hai.

Hum tab tak bits nikalte jaate hain jab tak number `0` nahi ho jata. Is tarah se bhi hum direct kisi bhi N-th number ka binary dhoodh sakte hain.

---

## 4. Complexity Analysis (Theory Ke Mutabik)

### ⏱️ Time Complexity: $\mathcal{O}(n)$

Kyunki hume N-th binary number tak pahunchna hai, hum line (queue) se ek-ek karke elements ko bahar nikaal rahe hain. Har ek element ko nikaalne aur usse do naye numbers banane mein constant time lagta hai. Isliye 1 se lekar $N$ tak jaane mein total time strictly linear hoga, yaani **$\mathcal{O}(n)$**.

### 💾 Space Complexity: $\mathcal{O}(n)$

Kisi bhi moment par, hamari queue (line) ke andar lagbhag bache hue naye binary numbers store hote hain. Agar hum $N$ tak ja rahe hain, toh queue ka size maximum $N/2$ ke aas-pass tak touch karta hai. Isliye memory ke mamle mein bhi yeh linear space leta hai: **$\mathcal{O}(n)$**.

Bhai, ab bata, N-th binary number generate karne ke peeche ka poora mathematical aur structural bhed ekdum dhyan mein fit hua ki nahi?



Bhai, aaja ab is **N-th Binary Number** (Generate Binary Numbers from 1 to N) ke poore logic ko **C++ Code** ke saath ekdum dhasu level par dry run karke samajhte hain.

Yahan hum **Queue (BFS)** approach ka use karenge, jo sabse elegant aur optimized maani jaati hai.

---

## 1. Clean C++ Code (Queue Approach)

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>

class BinaryGenerator {
public:
    std::vector<std::string> generateBinary(int n) {
        std::vector<std::string> result;
        std::queue<std::string> q;

        // Pehla binary number "1" line (queue) mein daal diya
        q.push("1");

        // Loop tab tak chalega jab tak hume N binary numbers nahi mil jaate
        for (int i = 1; i <= n; i++) {
            // 1. Line ke sabse aage waale number ko uthao
            std::string current = q.front();
            q.pop();

            // 2. Ise hamare final result mein save kar lo
            result.push_back(current);

            // 3. Is current number ka use karke do naye numbers banao
            // Pehle aage '0' lagao, fir '1' lagao aur queue ke piche daal do
            q.push(current + "0");
            q.push(current + "1");
        }

        return result;
    }
};

int main() {
    BinaryGenerator generator;
    int n = 5; // Maan lo hume pehle 5 binary numbers chahiye
    std::vector<std::string> ans = generator.generateBinary(n);

    std::cout << "Pehle " << n << " Binary Numbers yeh hain:\n";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << (i + 1) << " -> " << ans[i] << "\n";
    }
    return 0;
}

```

---

## 2. Ekdum Sheeshe Jaisa Dry Run ($N = 5$)

Aaiye dekhte hain computer ki memory mein Queue kaise badal rahi hai aur `result` bag mein kya save ho raha hai.

* **Shuruat mein (Loop chalne se pehle):**
* Queue ki haalat: `["1"]`
* Result Bag: `[]`



### 🔄 Loop Iteration 1 ($i = 1$):

* `current = q.front()` $\rightarrow$ `"1"` uthaya aur pop kiya.
* **Result mein daala:** `"1"` save ho gaya. `Result = ["1"]`
* **Naye numbers banaye:**
* `current + "0"` $\rightarrow$ `"1" + "0" = "10"` $\rightarrow$ Queue mein push kiya.
* `current + "1"` $\rightarrow$ `"1" + "1" = "11"` $\rightarrow$ Queue mein push kiya.


* *Is step ke baad Queue:* `["10", "11"]`

### 🔄 Loop Iteration 2 ($i = 2$):

* `current = q.front()` $\rightarrow$ Ab sabse aage `"10"` hai, use uthaya aur pop kiya.
* **Result mein daala:** `"10"` save ho gaya. `Result = ["1", "10"]`
* **Naye numbers banaye:**
* `current + "0"` $\rightarrow$ `"10" + "0" = "100"` $\rightarrow$ Queue ke piche bheja.
* `current + "1"` $\rightarrow$ `"10" + "1" = "101"` $\rightarrow$ Queue ke piche bheja.


* *Is step ke baad Queue:* `["11", "100", "101"]`

### 🔄 Loop Iteration 3 ($i = 3$):

* `current = q.front()` $\rightarrow$ Ab sabse aage `"11"` hai, use uthaya aur pop kiya.
* **Result mein daala:** `"11"` save ho gaya. `Result = ["1", "10", "11"]`
* **Naye numbers banaye:**
* `current + "0"` $\rightarrow$ `"11" + "0" = "110"` $\rightarrow$ Queue ke piche push kiya.
* `current + "1"` $\rightarrow$ `"11" + "1" = "111"` $\rightarrow$ Queue ke piche push kiya.


* *Is step ke baad Queue:* `["100", "101", "110", "111"]`

### 🔄 Loop Iteration 4 ($i = 4$):

* `current = q.front()` $\rightarrow$ Sabse aage `"100"` hai, use nikala aur pop kiya.
* **Result mein daala:** `"100"` save ho gaya. `Result = ["1", "10", "11", "100"]`
* **Naye numbers banaye:**
* `current + "0"` $\rightarrow$ `"1000"` (Queue mein gaya).
* `current + "1"` $\rightarrow$ `"1001"` (Queue mein gaya).


* *Is step ke baad Queue:* `["101", "110", "111", "1000", "1001"]`

### 🔄 Loop Iteration 5 ($i = 5$):

* `current = q.front()` $\rightarrow$ Sabse aage `"101"` hai, use nikala aur pop kiya.
* **Result mein daala:** `"101"` save ho gaya. `Result = ["1", "10", "11", "100", "101"]`
* **Naye numbers banaye:**
* `current + "0"` $\rightarrow$ `"1010"` (Queue mein gaya).
* `current + "1"` $\rightarrow$ `"1011"` (Queue mein gaya).


* *Is step ke baad Queue:* `["110", "111", "1000", "1001", "1010", "1011"]`

---

## 📊 Final Output Summary

Humara loop $i = 5$ par khatam ho gaya. `result` vector ko check karenge toh hume pehle 5 perfect binary numbers sequence mein mil chuke hain:

1. **`1`** (Decimal 1)
2. **`10`** (Decimal 2)
3. **`11`** (Decimal 3)
4. **`100`** (Decimal 4)
5. **`101`** (Decimal 5)

Kyunki humne string concatenation (`current + "0"`) ka use kiya, hume kisi math logic ya divide-by-2 waale jhanjhat ki zaroorat hi nahi padi!

Bhai, ab code ke saath is queue ka ek-ek step ka flow dimaag mein ekdum shandari se fit hua ki nahi?



Bhai, gusse mein mat aao, aaja iska **Recursive Approach** bhi ekdum jad se samajhte hain!

Pehle dimaag mein ek baat bitha lo: Recursive approach mein hum sequence (1, 2, 3...) print nahi karte, balki agar interviewer tumse kahe ki *"Bhai mujhe direct bataye ki **N-th decimal number ka binary code** recursion se kaise nikalega?"* — toh yeh approach wahan kaam aati hai.

Aaiye iska mathematically solid recursive logic, code aur dhasu dry run dekhte hain.

---

## 1. Core Intuition: Divide by 2 Ka Khel ➗

Kisi bhi decimal number (jaise 13) ko binary mein badalne ka school waala tarika yaad hai? Hum use baar-baar `2` se divide karte hain aur bache hue **Remainder (Sheshfal)** ko piche se note karte hain.

Recursion mein isi cheez ko do tukdon mein socha jata hai:

1. **Choti Problem:** Agar mujhe $N$ ka binary chahiye, toh main pehle `N / 2` ka binary recursion se mangwa lunga.
2. **Mera Kaam:** Jo bhi jawab recursion laakar dega, uske aage main apni current bit, yaani **`N % 2`** (remainder) ko chipka (append) dunga!

### Pillars of this Recursion:

* **Base Case:** Agar `N == 0` ho jaye, toh binary hamesha `"0"` hota hai. Agar `N == 1` ho jaye, toh binary `"1"` hota hai.
* **Recursive Relation:** 
$$\text{Binary}(N) = \text{Binary}(N / 2) + \text{String}(N \% 2)$$



---

## 2. Clean C++ Code (Recursive Approach)

```cpp
#include <iostream>
#include <string>

class BinaryRecursive {
public:
    std::string decimalToBinary(int n) {
        // Base Case: Agar number 0 ya 1 par pahunch gaya
        if (n == 0) return "0";
        if (n == 1) return "1";

        // Recursive Call: N/2 ka binary mangwaya + current remainder (N % 2) joda
        // to_string() use kiya hai takki integer remainder string mein badal jaye
        return decimalToBinary(n / 2) + std::to_string(n % 2);
    }
};

int main() {
    BinaryRecursive solver;
    int n = 13; // Maan lo hume 13 ka binary chahiye
    
    std::cout << n << " ka binary representation hai: " 
              << solver.decimalToBinary(n) << "\n"; // Output: 1101
    return 0;
}

```

---

## 3. Ekdum Sheeshe Jaisa Dry Run ($N = 13$)

Aaiye dekhte hain computer isko stack mein kaise chala raha hai. 13 ka actual binary `1101` hota hai.

### 🔼 Forward Phase (Call Stack mein niche jaana):

1. `decimalToBinary(13)` call hua. Base case nahi mila. Hold par chala gaya:
$$\rightarrow \text{decimalToBinary}(6) + \text{"1"} \quad (\text{kyunki } 13 \% 2 = 1)$$


2. `decimalToBinary(6)` call hua. Hold par gaya:
$$\rightarrow \text{decimalToBinary}(3) + \text{"0"} \quad (\text{kyunki } 6 \% 2 = 0)$$


3. `decimalToBinary(3)` call hua. Hold par gaya:
$$\rightarrow \text{decimalToBinary}(1) + \text{"1"} \quad (\text{kyunki } 3 \% 2 = 1)$$


4. `decimalToBinary(1)` call hua. **Base Case Hit!** `n == 1` mil gaya. Isne turant return kiya **`"1"`**.

### 🔽 Backward Phase (Jawab judte hue upar aana):

* `decimalToBinary(1)` ne diya `"1"`. Yeh wapas gaya step 3 ke paas:
$$\text{"1"} + \text{"1"} = \mathbf{\text{"11"}}$$


* `"11"` wapas gaya step 2 ke paas:
$$\text{"11"} + \text{"0"} = \mathbf{\text{"110"}}$$


* `"110"` wapas gaya sabse upar step 1 ke paas:
$$\text{"110"} + \text{"1"} = \mathbf{\text{"1101"}}$$



Main function ko final answer mil gaya: **`"1101"`**.

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(\log_2 n)$

* **Explanation:** Har ek recursive call mein hum number ko aadha (`n / 2`) kar rahe hain. Kisi bhi number ko `2` se divide karte-karte `1` tak pahunchane mein total **$\log_2 n$** steps lagte hain. Isliye time complexity logarithmic hai, jo ki linear ($\mathcal{O}(n)$) se bohot zyada tez hoti hai!

### 💾 Space Complexity: $\mathcal{O}(\log_2 n)$

* **Explanation:** Koi alag se array ya queue use nahi ho rahi hai. Extra space sirf **System Call Stack** le raha hai. Kyunki total calls hi $\log_2 n$ ho rahi hain, toh stack memory mein maximum frames bhi utne hi khulenge.
* Auxiliary Space Complexity hui: **$\mathcal{O}(\log_2 n)$**.

Bhai, ab recursion se direct kisi bhi N-th decimal number ka bits/binary nikalne ka poora calculation dimaag mein fit hua ki nahi?


Bhai, **Combinations** (LeetCode 77) recursion aur backtracking ka ek aur behtareen pillar hai.

Pichle sawal mein humne **Permutations (Arrangement)** dekha tha, jahan order matter karta hai (yaani `[1, 2]` aur `[2, 1]` do alag cheezein hain). Lekin **Combinations ka matlab hota hai "Selection" (Chunaav)**. Isme hume sirf elements ko chunna hota hai, unka aapas ka order matter nahi karta (yaani `[1, 2]` aur `[2, 1]` ko ek hi mana jayega).

Interviewer aapse kahega: *"Bhai, 1 se lekar $N$ tak ke numbers hain, mujhe size $K$ ke saare unique combinations bana kar dikhao."*

Aaiye isko ekdum desi style mein poori theory, code aur dhasu dry run ke saath samajhte hain!

---

## 1. Core Intuition: Chodne aur Lene Ka Khel (Include/Exclude)

Maan lo tumhare paas $N = 4$ tak ke numbers hain: `[1, 2, 3, 4]` aur tumhe $K = 2$ size ki team banani hai.

Jab hum combinations banate hain, toh duplicate selections se bachne ka sabse mast tarika hota hai hamesha **Aage ki taraf badhna**. Hum peeche waale elements ko dobara mudkar nahi dekhte.

Har ek number par khade hokar hamare paas wahi 2 classic choices hoti hain:

1. **Include (Le lo):** Current number ko apni team mein shamil karo. Ab hame $K-1$ elements aur chahiye, aur hum agle index (`current + 1`) par chale jayenge.
2. **Exclude (Chhod do):** Current number ko mat lo. Hame abhi bhi $K$ elements chahiye, aur hum agle index (`current + 1`) par chale jayenge.

### Base Cases (Kab rukna hai?):

* **Success:** Agar hamari team ka size $K$ ho gaya (yaani `currentCombination.size() == k`), toh hume ek valid combination mil gaya! Ise bag mein save karo aur return ho jao.
* **Failure:** Agar hamara `current` number $N$ se bada ho gaya (`current > n`), iska matlab numbers khatam ho gaye par team poori nahi hui. Chupchap return ho jao.

---

## 2. Standard C++ Code (Backtracking Approach)

```cpp
#include <iostream>
#include <vector>

class Solution {
private:
    void makeCombinations(int current, int n, int k, std::vector<int>& currentComb, std::vector<std::vector<int>>& result) {
        // Base Case 1: Agar team ka size K ke barabar ho gaya
        if (currentComb.size() == k) {
            result.push_back(currentComb);
            return;
        }

        // Base Case 2: Agar numbers khatam ho gaye
        if (current > n) {
            return;
        }

        // Choice 1: Current number ko INCLUDE kiya
        currentComb.push_back(current);
        makeCombinations(current + 1, n, k, currentComb, result); // Agle number par gaye
        
        // Backtrack (Undo): Laut te waqt element ko nikala taaki dusri branch chal sake
        currentComb.pop_back();

        // Choice 2: Current number ko EXCLUDE kiya (bina liye aage badh gaye)
        makeCombinations(current + 1, n, k, currentComb, result);
    }

public:
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentComb;
        makeCombinations(1, n, k, currentComb, result);
        return result;
    }
};

int main() {
    Solution solver;
    int n = 4, k = 2;
    std::vector<std::vector<int>> ans = solver.combine(n, k);

    std::cout << "Total Unique Combinations:\n";
    for (const auto& comb : ans) {
        std::cout << "[ ";
        for (int x : comb) std::cout << x << " ";
        std::cout << "]\n";
    }
    return 0;
}

```

---

## 3. Ekdum Sheeshe Jaisa Dry Run ($N = 4, K = 2$)

Chalo trace karte hain ki computer memory mein yeh tree kaise chalta hai. Shuruat hoti hai `current = 1` se.

1. **`makeCombinations(curr=1)`**
* **Include 1:** `currentComb = [1]`. Call gayi `makeCombinations(2)`.


2. **`makeCombinations(curr=2)`** [pichle `[1]` ke saath]
* **Include 2:** `currentComb = [1, 2]`. Size 2 ho gaya! **Base Case Hit!** **`[1, 2]`** save ho gaya. Return!
* *Backtrack:* `2` ko nikala $\rightarrow$ `currentComb = [1]`.
* **Exclude 2:** Bina 2 ke call gayi $\rightarrow$ `makeCombinations(3)`.


3. **`makeCombinations(curr=3)`** [pichle `[1]` ke saath]
* **Include 3:** `currentComb = [1, 3]`. Size 2 ho gaya! **Base Case Hit!** **`[1, 3]`** save ho gaya. Return!
* *Backtrack:* `3` ko nikala $\rightarrow$ `currentComb = [1]`.
* **Exclude 3:** Bina 3 ke call gayi $\rightarrow$ `makeCombinations(4)`.


4. **`makeCombinations(curr=4)`** [pichle `[1]` ke saath]
* **Include 4:** `currentComb = [1, 4]`. Size 2 ho gaya! **Base Case Hit!** **`[1, 4]`** save ho gaya. Return!



Ab jab `1` ki saari branches khatam ho jayengi, toh main recursion backtrack karke `1` ko bhi nikal dega (`currentComb = []`). Phir `1` ka **Exclude** rasta chalega (yaani bina 1 ke kahani shuru hogi `2` se). Isse hume milenge: **`[2, 3]`**, **`[2, 4]`**, aur aakhiri mein **`[3, 4]`**.

Total unique answers mile: **6**, jo ki mathematically $_4C_2 = \frac{4!}{2! \times 2!} = 6$ ke ekdum barabar hai!

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(K \cdot _NC_K)$

* **Explanation:** Total combinations kitne ban rahe hain? $_NC_K$. Iska matlab hamare recursion tree mein total valid leaf nodes (answers) $_NC_K$ honge.
* Har baar jab hum ek valid combination par pahunchein, hum use final `result` vector mein copy karte hain: `result.push_back(currentComb);`. $K$ size ke vector ko copy karne mein $\mathcal{O}(K)$ ka time lagta hai.
* Isliye, Total Time Complexity hoti hai: **$\mathcal{O}(K \cdot \frac{N!}{K!(N-K)!})$**.

### 💾 Space Complexity: $\mathcal{O}(K)$

* **Explanation:** Extra space ke naam par humne sirf `currentComb` vector liya hai, jiska size kisi bhi moment par $K$ se bada nahi ho sakta.
* Recursion call stack ki maximum depth kitni ja sakti hai? Woh bhi $N$ tak jayegi, par effective active frames team size $K$ ke proportional hi matter karte hain optimization ke baad.
* Isliye auxiliary space complexity ko hum linear yaani **$\mathcal{O}(K)$** bolte hain (Final `result` ka space count nahi hota).

Bhai, ab combinations nikaalne ke peeche ka poora Include/Exclude aur Backtracking ka khel ekdum dhasu tarike se clear hua ki nahi?




Bhai, **N-Queens** (LeetCode 51) poori computer science aur backtracking ka sabse bada **"Boss Level"** question maana jata hai. Agar tumne iska dimaag lagana seekh liya, toh backtracking ka koi bhi sawal tumhare saamne tik nahi payega.

Isko bina kisi complex code ke, ekdum theoretical aur shaatir shatranj (chess) ke khiladi ki tarah sote hain.

---

## 1. Asli Question Kya Hai? (The Challenge)

Tumhe ek $N \times N$ ka shatranj ka board (Chessboard) diya gaya hai. Aur tumhare paas **$N$ Queens (Raniyan)** hain.

Tumhe un saari $N$ queens ko board par is tarah bithaana hai ki **koi bhi do queens ek dusre ko maar na sakein (no two queens attack each other).**

### 👑 Shatranj Mein Queen Ki Aukat (Rules of Attack):

Shatranj mein rani sabse khatarnak hoti hai kyunki woh 3 directions mein attack kar sakti hai:

1. **Horizontal (Puri Row mein):** Same line mein baayein-daayein.
2. **Vertical (Puri Column mein):** Same line mein upar-neeche.
3. **Diagonals (Tirche):** Dono taraf ke saare tirche squares par.

---

## 2. Soch Ka Tarika: State-Space Tree Kaise Banayein?

Chalo ek $4 \times 4$ ka board lete hain aur $4$ Queens bithaani hain. Agar hum andhadhun bithaenge toh $16$ squares mein se $4$ chunne ke laakhon tareeqe ho jayenge (Brute force pighal jayega).

### Shaatir Dimaag Lagao: Column by Column Chalo 🚀

Hum jaante hain ki ek column mein strictly **ek hi queen** aa sakti hai (kyunki do raniyan same column mein rhengi toh lad marengi).

Toh hamari strategy yeh hogi:

* **Column 0** par khade ho jao. Is column ki kis row (0, 1, 2, ya 3) mein pehli queen bithaun?
* Maan lo Row 0 par bitha diya. Ab agli queen ke liye bakhushi **Column 1** par chale jao.
* Column 1 par check karo ki kaun si row safe hai? Jo row safe mile, wahan bitha do aur **Column 2** par badh jao.

---

## 3. Backtracking Ka Asli Mod (Twist)

Chalte-chalte ek aisi khunkhar situation aayegi:

> Tumne Column 0, Column 1, aur Column 2 par raniyan bitha dein. Lekin jab tum **Column 3** par pahunche, toh tumne dekha ki bachi-kuchi saari rows par pichli queens ka attack aa raha hai! Column 3 ke liye koi jagah hi nahi bachi.

Ab kya karoge? Haar maan loge? Nahi!

Yahan shuru hoti hai **Backtracking (Piche hatna)**:

1. Tum Column 3 se wapas **Column 2** waali rani ke paas jaoge aur bologe: *"Bhaiya, aap jahan baithe ho uski wajah se aage rasta block ho gaya hai. Aap kripya apni seat badlo."*
2. Column 2 waali rani apni purani jagah se uthegi (**Undo/Unmark**) aur usi column mein kisi agle safe square par baith jayegi.
3. Agar Column 2 ke paas bhi koi naya option nahi bacha, toh woh bhi piche mudegi aur **Column 1** waali rani ki seat badalwayegi.

Yeh adla-badli tab tak chalegi jab tak saari $N$ queens safely board par nahi baith jaatin.

---

## 4. "Is It Safe?" Check Karne Ka Dimag (Optimization)

Jab tum kisi `(row, col)` par rani bitha rahe ho, toh tumhe check karna padega ki wahan koi pichli rani attack toh nahi kar rahi?

Kyunki hum **Left se Right** (Col 0 se Col $N-1$) chal rahe hain, iska matlab hamare right side mein abhi tak koi rani baithi hi nahi hai. Toh hume right mein check karne ki koi zaroorat nahi hai!

Hume sirf **3 jagah** check karna hota hai:

1. **Left Horizontal Line:** Usi row mein peeche (`row, col-1`, `row, col-2`...)
2. **Upper Left Diagonal:** Upar ki taraf tircha peeche (`row-1, col-1`, `row-2, col-2`...)
3. **Lower Left Diagonal:** Niche ki taraf tircha peeche (`row+1, col-1`, `row+2, col-2`...)

### 🔥 Interviewer Ko Impress Karne Waali Pro-Theory:

Interviewer puchega: *"Bhai, har baar 3 directions mein peeche loop chalaoge toh $\mathcal{O}(N)$ ka time lagega har check mein. Isko fast kaise karoge?"*

Tum bolna: **"Sir, Hash Maps ya Arrays ka use karke $\mathcal{O}(1)$ mein!"**

* **Row Check:** Ek boolean array bana lo `leftRow[N]`. Agar kisi row mein queen baithi hai, toh use `true` mark kar do.
* **Upper Left Diagonal:** Is diagonal par bache har square ka `(row - col)` hamesha constant (same) hota hai! Iske liye ek array bana lo.
* **Lower Left Diagonal:** Is diagonal par bache har square ka `(row + col)` hamesha constant hota hai! Iske liye bhi ek array bana lo.

Isse bina kisi loop ke, direct array check karke pata chal jata hai ki rani baith sakti hai ya nahi.

---

## 5. Base Case (Sukh Ki Prapti 🏁)

Hum rukenge kab? Jab hamara `column` badhte-badhte **$N$** ke barabar ho jayega (`col == N`). Iska matlab humne safely saare columns (0 se $N-1$) par raniyan bitha li hain. Board ka jo current structure hai, woh hamara ek valid answer hai. Ise save karo aur baaki raaste dhoodhne ke liye fir se backtrack kar jao!

Bhai, yeh hai N-Queens ka poora theoretical bhed. Ab batao, column-by-column chalna, dead-end par piche hatna aur diagonal checks ka logic ekdum dhasu tarike se dimaag mein fit hua ki nahi?



Bhai, aaja ab **N-Queens** ke poore code ko ekdum jad se samajhte hain. Hum yahan wahi optimized approach use karenge jo maine tumhe upar batayi thi—**Hashing (Arrays) ka use karke $\mathcal{O}(1)$ mein safety check karna**.

Isko dekhne ke baad interviewer aapse behad khush ho jayega kyunki isme koi faltu loops nahi chalte rani ki safety check karne ke liye.

---

## 1. Optimized C++ Code

```cpp
#include <iostream>
#include <vector>
#include <string>

class Solution {
private:
    void solve(int col, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result,
               std::vector<int>& leftRow, std::vector<int>& lowerDiagonal, std::vector<int>& upperDiagonal) {
        
        // Base Case: Agar saare columns (0 se n-1) par raniyan baith chuki hain
        if (col == n) {
            result.push_back(board); // Ek valid board arrangement mil gaya!
            return;
        }

        // Is current 'col' ke liye har ek 'row' par rani bitha kar check karo
        for (int row = 0; row < n; row++) {
            
            // 🔥 O(1) Safety Check: Kya is row ya diagonals par pehle se koi rani hai?
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[(n - 1) + (col - row)] == 0) {
                
                // 1. Rani ko bitha do
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n - 1) + (col - row)] = 1;

                // 2. Recurse: Agle column (col + 1) ke liye rani dhoodho
                solve(col + 1, n, board, result, leftRow, lowerDiagonal, upperDiagonal);

                // 3. Backtrack (Undo): Rani ko hatao taaki baki options check ho sakein
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n - 1) + (col - row)] = 0;
            }
        }
    }

public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        
        // Shuruat mein poora board khali '.' se bhar do
        std::vector<std::string> board(n, std::string(n, '.'));

        // Hashing ke liye tracking arrays (0 matlab khali, 1 matlab rani baithi hai)
        std::vector<int> leftRow(n, 0);
        std::vector<int> lowerDiagonal(2 * n - 1, 0);
        std::vector<int> upperDiagonal(2 * n - 1, 0);

        solve(0, n, board, result, leftRow, lowerDiagonal, upperDiagonal);
        return result;
    }
};

int main() {
    Solution solver;
    int n = 4; // 4x4 Board ke liye solve karte hain
    std::vector<std::vector<std::string>> solutions = solver.solveNQueens(n);

    std::cout << "Total Solutions for " << n << "-Queens: " << solutions.size() << "\n\n";
    for (int i = 0; i < solutions.size(); i++) {
        std::cout << "Solution " << i + 1 << ":\n";
        for (const std::string& row : solutions[i]) {
            std::cout << row << "\n";
        }
        std::cout << "\n";
    }
    return 0;
}

```

---

## 2. Diagonal Hashing Ka Formula Kaise Kaam Karta Hai? 🧮

Yahan sabse bada bhed is formula mein hai: `upperDiagonal[(n - 1) + (col - row)]` aur `lowerDiagonal[row + col]`. Chalo isko samajhte hain.

### A. Lower Left Diagonal (`row + col`):

* Agar tum board par peeche ki taraf niche tircha chaloge (jaise `(1,0)` se `(0,1)`), toh har ek box ke `row` aur `col` ka sum **hamesha same (constant)** rehta hai.
* Ek $4 \times 4$ board mein max sum `3 + 3 = 6` tak ja sakta hai. Isliye is array ka size `2*n - 1` rakha jata hai.

### B. Upper Left Diagonal (`(n - 1) + (col - row)`):

* Agar tum upar ki taraf tircha peeche chaloge, toh `(col - row)` hamesha constant rehta hai.
* Lekin dikat yeh hai ki `col - row` kabhi-kabhi **negative** bhi ho sakta hai (jaise `row=3, col=0` par `0 - 3 = -3`). Array ke andar negative index toh daal nahi sakte!
* Isliye is negative value ko positive index mein badalna ke liye hum isme hamesha **`(n - 1)`** add kar dete hain. Ab saare index `0` se shuru hokar safe ho jaate hain.

---

## 3. Ekdum Kanch Jaisa Dry Run ($N = 4$)

Chalo dekhte hain computer pehle column se kaise shuru karta hai aur kahan backtrack karta hai.

* **Start:** `col = 0` par hain.
* `row = 0`: Safe hai! Rani bitha di `(0,0)` par. Arrays mark ho gaye. Call gayi `col = 1`.


* **`col = 1` Par:**
* `row = 0`: Blocked (Same row check `leftRow` mein 1 hai).
* `row = 1`: Blocked (Lower diagonal check failed).
* `row = 2`: Safe hai! Rani bitha di `(2,1)` par. Call gayi `col = 2`.


* **`col = 2` Par:**
* `row = 0`, `row = 1`, `row = 2`, `row = 3` saare positions pichli dono queens ke attack range mein hain! **Dead End** aa gaya.
* Ab loop khatam hua aur function yahan se return karega.


* **🔄 Backtracking Shuru:**
* Control wapas gaya `col = 1` ke paas. Isne apni rani ko `(2,1)` se hataya aur saare hash arrays wapas `0` kar diye.
* `col = 1` par loop aage badha `row = 3` par. Yeh safe mila! Rani bitha di `(3,1)` par. Call gayi `col = 2`.



Yeh silsila tab tak chalega jab tak raniyon ka aisa perfect setup nahi mil jata jahan `col == 4` ho jaye, jaise hi hit hoga, poora board answer mein save ho jayega.

---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(N!)$

* **Explanation:** Pehle column mein hamare paas rani bithaane ke liye $N$ choices hoti hain. Agle column mein attack ke kaaran choices ghat kar lagbhag $N-2$ ya usse kam bachti hain. Is tarah se har step par choices kam hoti jaati hain.
* Isliye worst-case mein total states explore karne ki time complexity strictly **$\mathcal{O}(N!)$** hoti hai.

### 💾 Space Complexity: $\mathcal{O}(N^2)$

* **Explanation:** 1. **Board Matrix:** Humne $N \times N$ size ka `board` banaya hai jo **$\mathcal{O}(N^2)$** space leta hai.
2. **Hash Arrays:** teen arrays liye hain (`leftRow`, `lowerDiagonal`, `upperDiagonal`) jinka size linear hai, yaani $\mathcal{O}(N)$.
3. **Call Stack:** Max depth call stack ki hamesha $N$ hi jayegi (kyunki total $N$ columns hain).
* Toh overall extra space complexity board size ke proportional yaani **$\mathcal{O}(N^2)$** rehti hai.

Bhai, ab optimized code, hashing ka dhasu logic aur dry run ekdum crystal clear hai na?



Bhai, $4 \times 4$ board ($N=4$) ke liye N-Queens ka aisa dry run dekhte hain ki tumhare dimaag mein saara khel ekdum live chalne lagega.

Hum chalenge **Column-by-Column** (`col 0` se `col 3`) aur use karenge teen Hash Arrays:

* `leftRow` (Size: 4)
* `lowerDiagonal` (Size: 7, index = `row + col`)
* `upperDiagonal` (Size: 7, index = `3 + col - row`)

Shuruat mein poora board khali hai (`.`) aur saare hash arrays `0` hain.

---

## 🏃‍♂️ Step-by-Step Execution (The Backtracking Path)

### 1. 🟢 Column 0 Par Aaye

Hum `row = 0` se loop shuru karte hain:

* **`row = 0`:** Check kiya $\rightarrow$ `leftRow[0] == 0`, `lower[0] == 0`, `upper[3] == 0`. Saare zero hain, yaani **SAFE!**
* **Action:** Rani bitha di `(0, 0)` par.
* **Hash Mark:** `leftRow[0]=1`, `lower[0]=1`, `upper[3]=1`.
* **Next:** Agle column par call gayi $\rightarrow$ `solve(col = 1)`.

### 2. 🟢 Column 1 Par Aaye

* **`row = 0`:** Check kiya $\rightarrow$ `leftRow[0]` pehle se `1` hai. **ATTACK!** (Same row).
* **`row = 1`:** Check kiya $\rightarrow$ `lower[1+1=2] == 0`, lekin `upper[3+1-1=3]` pehle se `1` hai. **ATTACK!** (Diagonal attack from `(0,0)`).
* **`row = 2`:** Check kiya $\rightarrow$ Saare arrays `0` mile. **SAFE!**
* **Action:** Rani bitha di `(2, 1)` par.
* **Hash Mark:** `leftRow[2]=1`, `lower[3]=1`, `upper[2]=1`.
* **Next:** Call gayi $\rightarrow$ `solve(col = 2)`.

### 3. 🛑 Column 2 Par Aaye (Dead End 1)

* **`row = 0`:** Same row attack from `(0,0)`.
* **`row = 1`:** Diagonal attack from `(2,1)` (`row+col = 1+2 = 3`, aur `lower[3]` pehle se `1` hai).
* **`row = 2`:** Same row attack from `(2,1)`.
* **`row = 3`:** Diagonal attack from `(2,1)` (`3+2-3 = 2`, aur `upper[2]` pehle se `1` hai).

**Bhai, yahan loop khatam!** Column 2 ke liye koi row safe nahi mili. Ab computer yahan se chupchap khali haath return karega piche waale column par.

---

### 🔄 BACKTRACK 1: Wapas Column 1 Par

* Control wapas aaya `col = 1` ke loop ke paas jo `row = 2` par tha.
* **Undo:** Rani ko `(2,1)` se hataya (`.`), aur iske saare hash marks wapas `0` kiye.
* **Loop Aage Badha (`row = 3`):** Check kiya $\rightarrow$ Saare hash `0` mile. **SAFE!**
* **Action:** Rani bitha di `(3, 1)` par.
* **Hash Mark:** `leftRow[3]=1`, `lower[4]=1`, `upper[1]=1`.
* **Next:** Nayi umeed ke saath call gayi $\rightarrow$ `solve(col = 2)`.

### 4. 🟢 Fir Se Column 2 Par Aaye

* **`row = 0`:** `leftRow[0]` is 1. ATTACK!
* **`row = 1`:** Check kiya $\rightarrow$ Saare hash `0` hain! **SAFE!**
* **Action:** Rani bitha di `(1, 2)` par.
* **Hash Mark:** `leftRow[1]=1`, `lower[3]=1`, `upper[4]=1`.
* **Next:** Call gayi $\rightarrow$ `solve(col = 3)`.

### 5. 🛑 Column 3 Par Aaye (Dead End 2)

* **`row = 0`:** Same row attack from `(0,0)`.
* **`row = 1`:** Same row attack from `(1,2)`.
* **`row = 2`:** Diagonal attack from `(1,2)` (`lower[2+3=5]` or `upper` check).
* **`row = 3`:** Same row attack from `(3,1)`.

**Phir se dead end!** Column 3 par koi jagah nahi mili. Ab poora rasta collapse hoga (Backtrack stack niche jayega).

---

### 🔄 MEGA BACKTRACK: Bilkul Shuruat Mein Wapas

1. `col = 3` se return hue `col = 2` par. `(1,2)` ko hataya, loop aage badha par koi aur row safe nahi mili.
2. `col = 2` se return hue `col = 1` par. `(3,1)` ko hataya, iske bhi saare rows khatam.
3. Wapas pahunche **`col = 0`** par! Ab `col = 0` apni rani ko `(0,0)` se hatayega aur use **`(1,0)`** par bithaega.

---

### 👑 6. Sunahera Rasta (The First Solution Found)

Jab `col = 0` par rani `(1,0)` par baitegi, toh tree is tarah aage badhega:

* **Column 0:** Rani baithi **`(1, 0)`** par.
* **Column 1:** Loop chalega aur safe jagah milegi **`(3, 1)`** par.
* **Column 2:** Loop chalega aur safe jagah milegi **`(0, 2)`** par.
* **Column 3:** Loop chalega aur is baar perfect safe jagah mil jayegi **`(2, 3)`** par!

### 🏁 Base Case Hit!

Jab `col = 4` par call jayegi, toh condition check hogi `if (col == n)`. Yeh **True** ho jayega!

Computer khush hokar is final arrangement ko `result` mein daal dega:

```text
. Q . .  (Row 0 par Col 1 mein Queen)
. . . Q  (Row 1 par Col 3 mein Queen)
Q . . .  (Row 2 par Col 0 mein Queen)
. . Q .  (Row 3 par Col 2 mein Queen)

```

Iske baad loop aage chalta rahega aur hume iska dusra mirror solution bhi mil jayega. Total 2 solutions bante hain $4 \times 4$ ke liye.

Bhai, ab dimaag mein N-Queens ka rani bithana, dead-end par piche hatna aur seat badalwana ekdum crystal clear chal raha hai na?



Bhai, **Sudoku Solver** (LeetCode 37) backtracking ka ek aur absolute legendary question hai. Yeh N-Queens jaisa hi hai, lekin isme board thoda bada hota hai aur niyam (rules) thode badal jaate hain.

Isko bina kisi complex code ke, ekdum shaatir Sudoku khiladi ki tarah samajhte hain ki dimaag mein iska logic kaise chalana hai.

---

## 1. Asli Question Kya Hai? (The Challenge)

Tumhe ek $9 \times 9$ ka adha-adhura bhara hua grid diya jata hai. Kuch cells mein `1` se `9` tak ke numbers hote hain, aur baki cells khali hote hain (jise code mein `'.'` se dikhaya jata hai).

Tumhe un saari khali jagaho ko `1` se `9` tak ke numbers se is tarah bharna hai ki Sudoku ke **3 sunehre niyam (Golden Rules)** follow hon:

1. **Row Rule:** Har ek horizontal line (Row) mein `1` se `9` tak ka har number strictly **ek hi baar** aana chahiye.
2. **Column Rule:** Har ek vertical line (Column) mein `1` se `9` tak ka har number strictly **ek hi baar** aana chahiye.
3. **3x3 Grid Rule:** Poore $9 \times 9$ board ko jab hum 9 chote-chote $3 \times 3$ ke dibbon (sub-grids) mein baant te hain, toh har ek dibbe ke andar bhi `1` se `9` tak ka har number strictly **ek hi baar** aana chahiye.

---

## 2. Soch Ka Tarika: State-Space Tree Kaise Banayein?

Jab hum khud akhbar (newspaper) mein Sudoku solve karte hain, toh hum idhar-udhar dekhte hain. Lekin computer ko ek systematic tareeqe se chalana padta hai.

### Matrix Scan Strategy 🔍

Hum board par **pehle cell `(0,0)` se shuru karenge** aur row-by-row, col-by-col aage badhenge:

* Hum har ek cell par jaakar check karenge: *"Kya yeh cell khali (`'.'`) hai?"*
* **Agar khali nahi hai:** Toh hum bina chede agle cell par badh jaayenge.
* **Agar khali hai:** Toh yahan shuru hota hai hamara asli backtracking ka khel! Hum us khali seat par **`1` se lekar `9` tak ke saare numbers ko ek-ek karke bithaane ki koshish (try)** karenge.

---

## 3. "Is It Safe?" Check Karne Ka Dimaag (The 3x3 Sub-grid Trick)

Jab hum kisi khali `(row, col)` par koi number (maan lo `5`) bithaane ki sochenge, toh hume pehle check karna padega ki kya `5` wahan safe hai?

* **Row Check:** Hum us poori `row` mein ghoom kar dekhenge ki kahin pehle se `5` toh nahi baitha?
* **Column Check:** Hum us poore `col` mein ghoom kar dekhenge ki kahin pehle se `5` toh nahi baitha?
* **3x3 Sub-grid Check (Sabse Bada Bhed):** Hum kaise pata karein ki hamara current cell kis chote $3 \times 3$ ke dibbe mein aata hai aur us dibbe ka starting point kya hai?

### 🧮 Sub-grid Ka Formula:

Shatir programmers ne iska ek mathematical formula nikala hai. Agar hamara cell `(row, col)` par hai, toh uske $3 \times 3$ sub-grid ka starting cell hamesha hota hai:


$$\text{Starting Row} = 3 \times (\text{row} / 3)$$

$$\text{Starting Col} = 3 \times (\text{col} / 3)$$

> **Example:** Maan lo tum cell `(row=4, col=7)` par ho.
> * $\text{Starting Row} = 3 \times (4 / 3) = 3 \times 1 = 3$
> * $\text{Starting Col} = 3 \times (7 / 3) = 3 \times 2 = 6$
> 
> 
> Iska matlab tumhara cell jis $3 \times 3$ box mein hai, woh box row index 3 se 5 aur col index 6 se 8 tak phaila hai! Ab tum is dibbe mein aasani se loop chala kar check kar sakte ho.

---

## 4. Backtracking Aur Base Case (Sukh Ki Prapti)

Maan lo tumhe ek khali cell mila, tumne check kiya aur wahan `5` bitha diya. Ab tum aage badh gaye agle khali cells ko bharne.

Chalte-chalte ek aisi situation aayi jahan aage ka ek cell khali hai, lekin jab tumne `1` se `9` tak saare numbers check kiye, toh pata chala ki **koi bhi number wahan safe nahi hai!** (Dead End aa gaya).

**Ab shuru hogi Backtracking:**

1. Tum piche waale cell ke paas wapas jaoge jahan tumne `5` bithaya tha.
2. Tum use bologe: *"Bhaiya, aapki wajah se aage game fass gaya hai. Aap kripya apni jagah khali karo."*
3. Tum us `5` ko hata kar wapas use khali (`'.'`) kar doge (**Undo/Backtrack**).
4. Ab tum us cell par `5` ke aage waale numbers (6, 7, 8, 9) try karoge.

### 🏁 Base Case Kab Hit Hoga?

Kyunki hamara recursion poore board par ghoom raha hai, jab hamara loop poore $9 \times 9$ board ko bina kisi blockage ke scan kar lega aur use **ek bhi khali cell nahi milega**, iska matlab Sudoku poora sahi-sahi bhar chuka hai! Wahan se hum return kar denge `true`.

Bhai, yeh hai Sudoku Solver ka poora theoretical bhed. Board ko scan karna, `1` se `9` tak check karna, dead-end par seats badalna aur $3 \times 3$ box ka formula—ekdum shandari se dimaag mein fit hua ki nahi?



Bhai, aaja ab **Sudoku Solver** ke poore code ko ekdum jad se samajhte hain. Iska code dekhne mein thoda lamba lagta hai, lekin iska structure bohot hi clean aur symmetric hota hai.

Hum yahan ek boolean function `solve()` banayenge, kyunki jaise hi hume **ek** perfect solution mil jayega, hum poore recursion tree ko wahi rok denge (hume saare solutions nahi chahiye, bas board ko bharna hai).

---

## 1. Clean C++ Code (Backtracking Approach)

```cpp
#include <iostream>
#include <vector>

class SudokuSolver {
private:
    // 🔥 O(1) ya Constant time safety check function
    bool isSafe(int row, int col, char num, const std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            // 1. Row Check: Kya is horizontal line mein yeh num pehle se hai?
            if (board[row][i] == num) return false;

            // 2. Column Check: Kya is vertical line mein yeh num pehle se hai?
            if (board[i][col] == num) return false;

            // 3. 3x3 Sub-grid Check: Pura 3x3 ka dibba check karne ka shaatir formula
            // row/3 * 3 se sub-grid ki starting row milti hai, aur i/3 se uske andar traverse karte hain
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
        }
        return true;
    }

public:
    bool solve(std::vector<std::vector<char>>& board) {
        // Poore 9x9 board par scan shuru karo
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                
                // Agar cell khali ('.') milta hai
                if (board[row][col] == '.') {
                    
                    // '1' se '9' tak ke saare numbers ko ek-ek karke try karo
                    for (char num = '1'; num <= '9'; num++) {
                        
                        // Check karo kya yeh number bithaana sahi hai?
                        if (isSafe(row, col, num, board)) {
                            
                            // 1. Step Aage Badhao: Number ko bitha do
                            board[row][col] = num;

                            // 2. Recurse: Agle khali cells ke liye call lagao
                            // Agar aage chal kar board poora bhar jata hai, toh true return karte jao
                            if (solve(board)) return true;

                            // 3. Backtrack (Undo): Agar aage rasta block ho gaya, toh seat khali karo
                            board[row][col] = '.';
                        }
                    }
                    
                    // Agar '1' se '9' tak koi bhi number fit nahi baitha, toh game fass gaya!
                    // Piche waale cell ko bolo seat badle (Return false)
                    return false;
                }
            }
        }
        // Base Case Hit: Poora board bina kisi dikkat ke scan ho gaya, yaani Sudoku SOLVED!
        return true;
    }
};

int main() {
    SudokuSolver solver;
    // Ek adha-bhara hua 9x9 Sudoku Board ('.' matlab khali)
    std::vector<std::vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    if (solver.solve(board)) {
        std::cout << "Sudoku safely solve ho gaya, Final Board:\n\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                std::cout << board[i][j] << " ";
                if ((j + 1) % 3 == 0 && j < 8) std::cout << "| ";
            }
            std::cout << "\n";
            if ((i + 1) % 3 == 0 && i < 8) std::cout << "---------------------\n";
        }
    } else {
        std::cout << "Is Sudoku ka koi solution nahi hai.\n";
    }
    return 0;
}

```

---

## 2. 🧮 3x3 Sub-grid Waale Loops Ka Bhed (Super Magic Line)

Code mein yeh waali line sabse khatarnak dikhti hai:
`board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3]`

Aaiye dekhte hain computer bina alag se 2D loop chalaye, sirf ek single `i` (0 se 8) waale loop se poora $3 \times 3$ ka box kaise check kar leta hai:

Maan lo hamara cell hai `row = 4, col = 7`.

* `3 * (row / 3)` $\rightarrow 3 \times (4 / 3) = 3 \times 1 = \mathbf{3}$ (Sub-grid ki starting row index).
* `3 * (col / 3)` $\rightarrow 3 \times (7 / 3) = 3 \times 2 = \mathbf{6}$ (Sub-grid ki starting col index).

Ab jab `i` ki value **0 se 8** tak badhegi, toh matrix ke coordinates dekho:

* `i = 0` $\rightarrow \text{row} = 3 + 0/3 = \mathbf{3}, \text{col} = 6 + 0\%3 = \mathbf{6} \rightarrow (3,6)$
* `i = 1` $\rightarrow \text{row} = 3 + 1/3 = \mathbf{3}, \text{col} = 6 + 1\%3 = \mathbf{7} \rightarrow (3,7)$
* `i = 2` $\rightarrow \text{row} = 3 + 2/3 = \mathbf{3}, \text{col} = 6 + 2\%3 = \mathbf{8} \rightarrow (3,8)$
* `i = 3` $\rightarrow \text{row} = 3 + 3/3 = \mathbf{4}, \text{col} = 6 + 3\%3 = \mathbf{6} \rightarrow (4,6)$
* ...
* `i = 8` $\rightarrow \text{row} = 3 + 8/3 = \mathbf{5}, \text{col} = 6 + 8\%3 = \mathbf{8} \rightarrow (5,8)$

Dekha? Sirf ek single `i` ke loop se computer ne row 3 se 5 aur col 6 se 8 tak ke poore $3 \times 3$ box ko scan maar diya!

---

## 3. Ekdum Makkhan Jaisa Dry Run (Fasne Aur Nikalne Ka Khel)

Maan lo board par hum badhte-badhte `row = 0, col = 2` waale khali cell par aaye.

1. **Cell (0,2) par check:**
* Humne `num = '1'` try kiya. `isSafe()` ne bola, *"Nahi bhai, same row mein pehle se 1 baitha hai."*
* Humne `num = '2'` try kiya. `isSafe()` ne bola, *"Haan bhai, bilkul SAFE hai!"*
* **Action:** `board[0][2] = '2'` bitha diya aur agle khali cell ke liye call laga di `solve(board)`.


2. **Aage Game Fassa (Dead End):**
* Hum aage badhte gaye, par `row = 0, col = 3` par aakar computer fass gaya. Wahan `1` se `9` tak koi bhi number fit nahi ho raha.
* Ab control isi loop ke niche jaakar **`return false`** kar dega.


3. **🔄 Backtracking Frame (Undo):**
* Control wapas lautega piche waale cell `(0,2)` ke paas.
* `(0,2)` ka chal raha recursion call block fail ho gaya, toh isne turant apna kadam piche khincha: `board[0][2] = '.'` (Wapas khali kar diya).
* Ab `(0,2)` par loop aage badhega aur `num = '3', '4'...'9'` try karega.



---

## 4. Complexity Analysis

### ⏱️ Time Complexity: $\mathcal{O}(9^{K})$ [Jahan $K$ khali cells ki sankhya hai]

* **Explanation:** Worst case mein, har ek khali cell (`'.'`) par hamare paas bithaane ke liye total **9 choices** hoti hain. Agar total khali cells $K$ hain, toh maximum recursive nodes $9 \times 9 \times 9 \dots (K \text{ times}) = 9^K$ ban sakte hain.
* Halanki practically Sudoku ke rules itne kade hote hain ki bohot saari branches shuruat mein hi cut jaati hain (pruning ho jaati hai), isliye yeh bohot tez chal jata hai.

### 💾 Space Complexity: $\mathcal{O}(1)$ ya Constant Board Space

* **Explanation:** Hum koi alag se bada hash matrix ya grid nahi bana rahe hain. Hum usi $9 \times 9$ ke given input board par hi adla-badli kar rahe hain.
* System recursion stack ki max depth kitni ho sakti hai? Jitne khali cells hain, yaani maximum $81$ frames. Kyunki board ka size hamesha fixed ($9 \times 9$) hota hai, isliye stack space bhi strictly bounded aur constant rehta hai, yaani **$\mathcal{O}(1)$**.

Bhai, ab Sudoku Solver ka optimized single-loop check, backtracking undo flow aur code ka ek-ek bhed ekdum shandari se clear hua ki nahi?



Bhai, $9 \times 9$ ke badle ek chota aur makkhan jaisa **$4 \times 4$ Sudoku Board** lekar dry run samajhte hain, taaki tumhara dimaag ek-ek operation ko live dekh sake.

Rules bilkul same hain: Har Row, Col aur **$2 \times 2$ ke sub-grid** mein `1` se `4` tak ke numbers unique hone chahiye.

Maan lo hamara initial board aisa dikhta hai (`.` matlab khali cell):

```text
Row 0:  1  .  |  .  .
Row 1:  .  .  |  .  2
       -------+-------
Row 2:  3  .  |  .  .
Row 3:  .  .  |  .  4

```

---

## 🏃‍♂️ Step-by-Step Scan Aur Backtracking Ka Khel

Hum bilkul pehle cell `(0, 0)` se scanning shuru karte hain aur row-by-row aage badhenge.

### 1. 🟢 Row 0, Col 0:

* Yahan pehle se `1` baitha hai. Computer isko bina chede aage badh jayega.

### 2. 🟢 Row 0, Col 1: (Khali mila `'.'`)

Hum is seat par `num = '1'` se `4` tak try karenge:

* `num = '1'` $\rightarrow$ **ATTACK!** (Same row mein pehle se `1` hai).
* `num = '2'` $\rightarrow$ Row, Col aur $2 \times 2$ sub-grid teeno mein check kiya... Saaf mila! **SAFE!**
* **Action:** Humne `board[0][1] = '2'` bitha diya aur agle cell par chale gaye.

### 3. 🟢 Row 0, Col 2: (Khali mila `'.'`)

* `num = '1'` $\rightarrow$ Row mein `1` hai. Blocked!
* `num = '2'` $\rightarrow$ Row mein `2` hai (jo abhi-abhi bithaya). Blocked!
* `num = '3'` $\rightarrow$ Check kiya, poori Row, Col 2 aur top-right sub-grid mein kahin bhi 3 nahi hai. **SAFE!**
* **Action:** Humne `board[0][2] = '3'` bitha diya.

### 4. 🟢 Row 0, Col 3: (Khali mila `'.'`)

* `num = '1', '2', '3'` saare blocked hain row ke rules se.
* `num = '4'` $\rightarrow$ Check kiya... Pure board par is position ke liye safe mila! **SAFE!**
* **Action:** `board[0][3] = '4'` bitha diya.
* *Row 0 poori bhar gayi:* `[1, 2, 3, 4]` (Perfect!)

---

### 5. 🟢 Row 1, Col 0: (Khali mila `'.'`)

* `num = '1'` $\rightarrow$ Col 0 mein upar `1` baitha hai. Blocked!
* `num = '2'` $\rightarrow$ Check kiya... Row 1 mein aakhiri mein `2` hai. Blocked!
* `num = '3'` $\rightarrow$ Col 0 mein niche `3` baitha hai. Blocked!
* `num = '4'` $\rightarrow$ Row, Col aur bottom-left sub-grid check kiya... ekdum **SAFE!**
* **Action:** `board[1][0] = '4'` bitha diya.

---

### 6. 🛑 Ab Dekho Kahani Mein Twist (Dead End & Backtrack)

Maan lo badhte-badhte hum **Row 1, Col 1** par aaye.

* Humne `num = '1'` try kiya $\rightarrow$ Bottom-left $2 \times 2$ sub-grid ko dekho, usme `(0,0)` par pehle se `1` betha hai! **Sub-grid Attack!** Blocked!
* `num = '2'` try kiya $\rightarrow$ Same row mein aakhiri mein `2` hai. Blocked!
* `num = '3'` try kiya $\rightarrow$ Sub-grid mein check karein toh koi dikkat nahi, lekin niche Col 1 mein kahin aur fass raha hai ya Row mein dikkat hai... Maan lo kisi rule se `3` bhi blocked hai.
* `num = '4'` try kiya $\rightarrow$ Same row mein abhi-abhi `4` bithaya hai. Blocked!

**Bhai fass gaye!** `Row 1, Col 1` ke liye `1` se `4` tak koi bhi number safe nahi mila. Ab control loop se bahar nikal kar **`return false`** marega.

---

### 🔄 BACKTRACK: Piche Kadam Khincho

1. Control rote hue wapas lauta piche waale cell **`Row 1, Col 0`** ke paas (jahan humne `4` bithaya tha).
2. Isne `board[1][0] = '.'` kiya, yaani apni rani/seat wapas **khali** kar di!
3. Ab yeh apne loop ko `4` ke aage badhane ki koshish karega. Lekin humara loop toh sirf `4` tak hi tha, toh is cell ke bhi saare options khatam! Yeh bhi **`return false`** karega.
4. Control aur piche lauta **`Row 0, Col 3`** ke paas (jahan `4` baitha tha). Isne use khali kiya `.`. Iska loop bhi `4` par khatam tha, toh yeh bhi piche lauta.
5. Control lauta **`Row 0, Col 2`** ke paas (jahan `3` baitha tha).
* Isne `3` ko hatakar kiya `.`.
* Iska loop `3` par tha, ab yeh aage badh kar **`num = '4'`** try karega!



Ab yahan se ek naya rasta khulega, computer `(0,2)` par `4` bithaega, aur fir se aage badhega. Yeh adla-badli tab tak chalti rahegi jab tak saare cells bina kisi conflict ke `1` se `4` se bhar nahi jaate.

Bhai, ab dimaag mein fassna, piche laut te waqt cell ko wapas `.` (khali) karna aur agla number try karna ekdum crystal clear baith gaya na?