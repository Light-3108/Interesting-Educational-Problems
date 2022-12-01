#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  vector<long long> a(m);
  for(int i=0; i<n; i++) a[i] = 0;
  for(int i=n; i<m; i++) a[i] = 1;

  do{
    for(int i=0; i<m; i++){
        if(a[i]==0)cout<<i+1<<" ";
    }cout<<endl;
  }while(next_permutation(a.begin(),a.end()));
}
