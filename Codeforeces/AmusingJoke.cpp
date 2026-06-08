#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;cin>>s;
  string t;cin>>t;
  string st;cin>>st;

  vector<int> freq(26,0);

  for (int i = 0; i < st.length(); i++)
  {
    freq[st[i]-'A']++;
  }

  for (int i = 0; i < t.length(); i++)
  {
    freq[t[i]-'A']--;
  }

  for (int i = 0; i < s.length(); i++)
  {
    freq[s[i]-'A']--;
  }

  bool flag = false;
  for(int x:freq){
    if (x!=0)
    {
      flag = true;
      break;
    }
    
  }

  if (flag)
  {
    cout<<"NO";
  }else{
    cout<<"YES";
  }

  return 0;
}
