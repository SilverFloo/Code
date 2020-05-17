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
const int INF=2e9+5;
int tab[(int)1e6+5];
int ans[(int)1e6+5];
int main(){
    int n;
    cin>>n;
    tab[0]=INF;tab[n+1]=INF;
    FOR1(i,n)scanf("%d",&tab[i]);
    deque<int> q,qq;
    q.pb(0);
    FOR1(i,n){
    while(!q.empty()&&tab[i]>=tab[q.back()])q.pop_back();
    ans[i]+=i-q.back();
    q.pb(i);
    }

    qq.pb(n+1);
    for(int i=n;i>0;i--){
    while(!qq.empty()&&tab[i]>=tab[qq.back()])qq.pop_back();
    ans[i]+=qq.back()-i;
    qq.pb(i);
    }
    FOR1(i,n)printf("%d ",ans[i]-1);
}
