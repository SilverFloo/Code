#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
int main(){
int n;
cin>>n;
int a[n],b[n];
FOR(i,n)scanf("%d",&a[i]);
FOR(i,n)scanf("%d",&b[i]);
sort(a,a+n);
sort(b,b+n);
long ans=0;
FOR(i,n)ans+=abs(a[i]-b[i]);
printf("%lld",ans);
}
