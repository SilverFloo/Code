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
ll tab[(int)1e6+5],dp[(int)1e6+5];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n+1;i++)scanf("%lld",&tab[i]),tab[i]+=tab[i-1];
    deque<int> q;
    q.pb(0);q.pb(1);
    for(int i=2;i<=n+1;i++){
               // printf(">%d<",q.front());
            while(!q.empty()&&tab[i]-tab[q.front()+1]>m)q.pop_front();
            if(q.empty())dp[i]=0;
            else dp[i]=tab[i]-tab[q.front()+1]+dp[q.front()];
            //printf("%lld ",dp[i]);
       while(!q.empty()&&dp[i]>dp[q.back()]+tab[i+1]-tab[q.back()+1])q.pop_back();
        q.pb(i);
    }
    printf("%lld",dp[n+1]);
}
