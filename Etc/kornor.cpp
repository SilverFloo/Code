#include<bits/stdc++.h>
using namespace std;
long long x[100000000];
const int MAX=1e9+7;
int main(){
x[1]=1;
int t=0;
int m=2;
scanf("%d",&t);
while(t--){
int n;scanf("%d",&n);
if(m<=n)for(m;m<=n;m++){x[m]=(x[m-1]*2+1)%MAX;}
printf("%lld\n",x[n]);
}
}
