#include<bits/stdc++.h>
using namespace std;
class Person{
  public:
  int age;
  string name;
  bool operator < (const Person &other) const{
    return age<other.age;
  }
};

int main(int argc, char const *argv[])
{
  // pair<string,int> user;
  // user = make_pair("AJ",21);
  // user.first = "BJ";
  // user.second = 20;
  // cout<<user.first<<" "<<user.second<<endl;

  // pair<string,pair<int,int>> p;
  // p.first = "Bj";
  // p.second.first = 45;
  // p.second.second = 89;


  // list<int> dll;
  // dll.push_back(30);
  // dll.push_back(50);
  // dll.push_back(70);
  // dll.push_back(80);

  // dll.push_front(90);

  // // cout<<dll.front()<<endl;

  // for (auto i = dll.begin(); i != dll.end(); i++)
  // {
  //   cout<<*i<<" ";
  // }

  // cout<<endl;

  // //Reverse Print
  // for (auto i = dll.rbegin(); i != dll.rend(); i++)
  // {
  //   cout<<*i<<" ";
  // }
  

  // set<int> s; // Store data in sorted order
  // unordered_set<int> s;  //Store in unsorted order
  // set<int,greater<int>> s;  //Store in sorted order descending order
  // s.insert(2);
  // s.insert(4);
  // s.insert(5);
  // s.insert(8);
  // s.insert(10);

  // for(int x:s){
  //   cout<<x<<" ";
  // }

  // if (s.count(5))
  // {
  //   cout<<"Present"<<endl;
  // }
  
  // s.erase(8);

  // if (s.count(8))
  // {
  //   cout<<"Present"<<endl;
  // }else{
  //   cout<<"Not Present"<<endl;
  // }


  // Person p1,p2,p3;

  // p1.age = 5;
  // p1.name = "AJ";
  // p2.age = 10;
  // p2.name = "BJ";
  // p3.age = 15;
  // p3.name = "CJ";

  // set<Person> p;
  // p.insert(p1);
  // p.insert(p2);
  // p.insert(p3);

  // for(const auto &i:p){
  //   cout<<i.age<<" "<<i.name<<endl;
  // }

  // map<int,int> mp;
  // mp[0] = 21;
  // cout<<mp[0]<<endl;

  unordered_map<int,int> mp;
  mp.insert({10,20});


  //Dont Overwrite
  // mp.emplace(10,50);
  // mp.insert({10,60});

  //Overwrite
  mp[10] = 50;

  cout<<mp[10]<<"\n";
  return 0;
}