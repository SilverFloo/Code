#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define pb emplace_back
#define all(a) a.begin(),a.end()
using namespace std;
const int MAX=1e7;
bool prime[MAX];
int main(){
prime[0]=1;prime[1]=1;
for(int i=2;i<MAX;i++){
if(!prime[i]){//printf("in");
for(int j=i<<1;j<MAX;j+=i){
if(j%i==0){prime[j]=1;}
}
}
}
int n;
cin>>n;
int c=0;
int i;
for(i=2;i<MAX;i++){
if(!prime[i])c++;
if(c==n)break;
}

if(c<n)exit(1);
printf("%d",i);
}
