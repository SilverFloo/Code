#include<bits/stdc++.h>
using namespace std;
int tab[(int)1e5+5];
int main(){
int n,k;
cin>>n>>k;
for(int i=0;i<n;i++){
string a;
cin>>a;
if(a=="UR"){tab[i]=1;}
}
int xx=0;
for(int i=0;i<k;i++)xx+=tab[i];
int ans=xx;
for(int i=k;i<n;i++){
xx-=tab[i-k];
xx+=tab[i];
ans=max(ans,xx);
}
printf("%d",ans);
}
