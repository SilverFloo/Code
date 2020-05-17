#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
long long ans=22e8;
const int MAX=2e6+5;
long long cat[MAX];
long long n;

bool chk(long long m){
long long a=-1;
FOR(i,n){
if(cat[i]>m&&a==-1)a=cat[i];
else if(cat[i]>m&&cat[i]==a)a=-1;
else if(cat[i]>m){return 0;}
}

return 1;
}

void find(long long l,long long r){
if(l>r)return;
long long m=(l+r)/2;
if(chk(m)){ans=min(ans,m);find(l,m-1);}
else find(m+1,r);
}

int main(){
cin>>n;
FOR(i,n){
scanf("%lld",&cat[i]);
}
find(0,22e8);
printf("%lld",ans);
}
