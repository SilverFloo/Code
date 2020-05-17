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
long long tab[n];
FOR(i,n)scanf("%lld",&tab[i]);
sort(tab,tab+n);
long long m=1e18+5;
FOR1(i,n){
if(tab[i]-tab[i-1]<m)m=tab[i]-tab[i-1];
}
printf("%lld",m);
}
