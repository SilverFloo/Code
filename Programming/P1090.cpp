#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int a[(int)2e5+5];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    int x;
    scanf("%d",&x);
    a[x]++;
    }
    int k;cin>>k;
    int l=0,r=k;
    ll ans=0;
    while(l<r){
    ans+=(ll)a[l]*a[r];
    l++;r--;
    }
    if(l==r)ans+=(ll)a[l]*(a[l]-1)/2;
    printf("%lld",ans);
}
