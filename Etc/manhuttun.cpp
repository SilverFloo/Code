#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x[n],y[n];
for(int i=0;i<n;i++){scanf("%d",&x[i]);}
for(int i=0;i<n;i++){scanf("%d",&y[i]);}
sort(x,x+n);
sort(y,y+n);
long long ans=0;
for(int i=0;i<n;i++){
ans+=(long long)(x[i]+y[i])*(long long)(2*i-n+1);
}
printf("%lld",ans);
}
