#include<bits/stdc++.h>
using namespace std;

class TwoSumIII{
public:
unordered_map<int,int> seen;
void add(int val){
    seen[val]++;
}
bool find(int val){
    for (auto i = seen.begin(); i != seen.end(); i++)
    {
        long long search = (long long)val - i->first;
        if (search!=i->first)
        {
            if (seen.count(search))
            {
                return true;
            }
            
        }else{
            if(i->second>1){
                return true;
            }
        }
        
    }
    return false;
}
};

int main()
{
  TwoSumIII t;
  t.add(1); 
  t.add(3); 
  t.add(5); 
  cout<<t.find(4)<<endl; 
  cout<<t.find(7)<<endl; 
  return 0;
}

