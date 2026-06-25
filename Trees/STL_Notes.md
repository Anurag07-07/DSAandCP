# C++ STL Notes

## 1. What is STL?
STL = Standard Template Library.
It provides reusable classes and functions for:
- Containers
- Iterators
- Algorithms
- Functions / Functors

## 2. Containers

### Sequence Containers
These store data in a linear order.

- vector<T>
  - Dynamic array
  - Fast random access
  - Good for push_back/pop_back

```cpp
#include <vector>
vector<int> v = {1, 2, 3};
v.push_back(4);
cout << v[0] << endl;
```

- list<T>
  - Doubly linked list
  - Fast insert/delete in middle

- deque<T>
  - Double-ended queue
  - Fast push/pop from both ends

### Associative Containers
These store data in sorted order.

- set<T>
  - Stores unique elements
  - Sorted ascending

```cpp
#include <set>
set<int> s;
s.insert(5);
s.insert(2);
s.insert(5); // ignored
```

- map<Key, Value>
  - Stores key-value pairs
  - Keys are unique and sorted

```cpp
map<string, int> mp;
mp["Aj"] = 21;
mp["Bj"] = 20;
```

### Unordered Containers
These use hashing.

- unordered_set<T>
- unordered_map<Key, Value>

They are faster on average for lookup but not sorted.

### Container Adapters
- stack<T>
- queue<T>
- priority_queue<T>

```cpp
priority_queue<int> pq;
pq.push(10);
pq.push(3);
pq.push(20);
cout << pq.top() << endl; // 20
```

## 3. Pair
Used to store two values.

```cpp
#include <utility>
pair<string, int> p = {"Aj", 21};
cout << p.first << " " << p.second << endl;
```

## 4. Iterators
Iterators are used to access elements in containers.

```cpp
vector<int> v = {10, 20, 30};
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

Common iterator functions:
- begin()
- end()
- rbegin()
- rend()

## 5. Algorithms
STL also provides many built-in algorithms.

### Common algorithms
- sort()
- reverse()
- binary_search()
- lower_bound()
- upper_bound()
- max()
- min()
- find()
- count()
- accumulate()

```cpp
#include <algorithm>
#include <vector>
vector<int> v = {4, 2, 7, 1};
sort(v.begin(), v.end());
```

## 6. Useful Header Files
- <vector>
- <list>
- <set>
- <map>
- <unordered_set>
- <unordered_map>
- <queue>
- <stack>
- <algorithm>
- <utility>
- <bits/stdc++.h>  // for competitive programming

## 7. Important Notes
- vector is best for dynamic arrays.
- set/map keep elements sorted.
- unordered_set/unordered_map are hash-based and faster for lookup.
- priority_queue gives highest element first by default.
- Always include the correct header for the container you use.

## 8. Quick Example
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {3, 1, 2};
    sort(v.begin(), v.end());

    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(5);

    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
}
```
