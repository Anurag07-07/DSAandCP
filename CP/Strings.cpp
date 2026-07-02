// string -> a set of characters you can change the characters
// string literals -> a set of characters it is not editable 

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     void solve() {

//         string s;cin>>s;

//         // logic here
//         if (s.length()<10)
//         {
//           cout<<s<<endl;
//           return;
//         }
        
//         int length = s.length()-2;
//         char first = s[0];
//         char last = s[s.length()-1];
//         cout<<first<<length<<last<<endl;
//     }
// };

// int main() {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);

//     int t;
//     cin >> t;

//     Solution s;
//     while (t--) {
//         s.solve();
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     void solve() {
//       string s1;cin>>s1;
//       string s2;cin>>s2;


//       for (int i = 0; i < s1.length(); i++)
//       {
//         s1[i] = tolower(s1[i]);
//       }

//       for (int i = 0; i < s2.length(); i++)
//       {
//         s2[i] = tolower(s2[i]);
//       }
      
//         if ((s1)==(s2))
//         {
//           cout<<0<<endl;
//         }else if ((s1)>(s2))
//         {
//           cout<<1<<endl;
//         }else{
//           cout<<-1<<endl;
//         }
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     Solution s;
//     while (t--) {
//         s.solve();
//     }

//     return 0;
// }



// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     void solve() {
//       string t;cin>>t;
//       //Way 1 
//       vector<int> nums;
//       for(char c:t){
//         if (c!='+')
//         {
//           nums.push_back(c-'0');
//         }
        
//       }

//       sort(nums.begin(),nums.end());

//       string s;
//       s.push_back(nums[0]+'0');
//       s.push_back('+');
//       for (int i = 1; i < nums.size(); i++)
//       {
//         s+=to_string(nums[i])+'+';
//       }
      
//       s.pop_back();

//       cout<<s<<endl;
//       //Way 2 Count 1 2 and 3 using counting sort solve it
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     Solution s;
//     while (t--) {
//         s.solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     void solve() {
//       string s;
//       cin>>s;
//       s[0] = toupper(s[0]);
//       cout<<s<<endl;      
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     Solution s;
//     while (t--) {
//         s.solve();
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// class Solution {
// public:
//     void solve() {
//       string s;cin>>s;
//       string t;cin>>t;

//       reverse(s.begin(),s.end());

//       cout<<((s==t) ? ("YES"):( "NO"))<<endl;
//     }
// };

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t;
//     cin >> t;

//     Solution s;
//     while (t--) {
//         s.solve();
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

class Solution {
public:

    bool isVowel(char c){

      if (c=='a' || c=='A')
      {
        return true;
      }else if (c=='e' || c=='E')
      {
        return true;
      } else if (c=='i' || c=='I')
      {
        return true;
      }else if (c=='o' || c=='O')
      {
        return true;
      }else if (c=='U' || c=='u')
      {
        return true;
      }else if (c=='y' || c=='Y')
      {
        return true;
      }
      
      return false;
    }
    void solve() {
      string s;cin>>s;
      string t="";

      // Convert string to lower case
      // transform(s.begin(),s.end(),s.begin(),::tolower);

      for (int i = 0; i < s.length(); i++)
      {
        char c = s[i];
        if (isVowel(c))
        {
          continue;
        }
        t+=".";
        t+=tolower(c);
      }

      cout<<t<<endl;

      
    }
};

int main() {
    Solution s;
    s.solve();
    return 0;
}