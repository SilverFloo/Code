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
vector<int> tab[2000];
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    FOR(j,n){
        int x;
        scanf("%d",&x);
        tab[i+j].pb(x);
    }
    }
    ll ans=0;
    priority_queue<int> q;
    for(int i=2*n-2;i>0;i--){
        for(auto j:tab[i])q.p(j);
        ans+=q.top();
        q.pop();
    }
    printf("%lld",ans);
}
