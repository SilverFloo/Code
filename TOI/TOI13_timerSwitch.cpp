#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
const int INF=1e9;
using namespace std;
char tab[(int)5e6+5];
int main(){
int n;
cin>>n;
scanf("%s",tab);
vector<int> q;
for(int i=1;i*i<=n;i++){
    if(n%i==0)q.pb(i),q.pb(n/i);
}
sort(all(q));
for(auto i:q){
int ch=1;
for(int j=i;j<n;j++){if(tab[j]!=tab[j%i]){ch=0;break;}}
if(ch){printf("%d",i);return 0;}
}

}
