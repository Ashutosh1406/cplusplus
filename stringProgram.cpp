#include <bits/stdc++.h>

using namespace std;
int main() {
  string s;
  int t;
  cout<<"enter a string"<<"\t"<<endl;
  getline(cin,s);
  if(s.empty()){
    cout<<"string is empty"<<endl;
  }
  cout<<"string is not empty"<<s<<endl;
  cout<<"enter a number"<<"\t"<<endl;
  cin>>t;
  if(t>9){
    for(auto it:s)
    {
      if(it%2==0)
      {
          cout<<s[it];
      }
    }
  }
  cout<<"invalid input"<<endl;
   return 0;
}