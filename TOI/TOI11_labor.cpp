#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
using namespace std;
int main(){
int n;long long m;
long long aa=1e18;
cin>>n>>m;
int t[n];
FOR(i,n)scanf("%d",&t[i]);
long long l=0,r=1e18;
while(l<=r){
long long mid=(l+r)/2;
long long ans=0;
FOR(i,n)ans+=mid/t[i];
if(ans>=m){r=mid-1;aa=mid;}
else l=mid+1;
}
printf("%lld",aa);

}
