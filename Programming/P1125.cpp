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
int main(){
    int n;
    cin>>n;
    int x[n],y[n];
    FOR(i,n)scanf("%d %d",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    ll ans=0;
    int c=-n+1;
    for(int i=0;i<n;i++){
    ans+=(ll)c*x[i];
    c+=2;
    }
    c=-n+1;
    for(int i=0;i<n;i++){
    ans+=(ll)c*y[i];
    c+=2;
    }
    printf("%lld",ans);
}
