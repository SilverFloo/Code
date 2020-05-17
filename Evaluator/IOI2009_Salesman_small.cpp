#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
struct node{
    int t,l;
    ll p;
};
bool cmp(node a,node b){
    return a.t<b.t;
}
node tab[500005];
ll dp[500005];
int n,u,d,s;
ll cost(int s,int e){
    if(s>e)return (s-e)*u;
    else return (e-s)*d;
}
int main(){
    rf();
    cin>>n>>u>>d>>s;
    FOR(i,n){
        scanf("%d %d %lld",&tab[i].t,&tab[i].l,&tab[i].p);
    }
    sort(tab,tab+n,cmp);
    FOR(i,n){
            dp[i]=tab[i].p-cost(s,tab[i].l);
        FOR(j,i){
            dp[i]=max(dp[i],dp[j]+tab[i].p-cost(tab[j].l,tab[i].l));
        }
        //printf("%lld\n",dp[i]);
    }
    ll ans=0;
    FOR(i,n){
        ans = max(ans,dp[i]-cost(tab[i].l,s));
    }
    printf("%lld",ans);
}
/*
10 10 5 129
43 277 3757
186 473 344
219 238 1792
244 258 2816
154 58 2477
415 103 1746
448 124 699
98 143 71
407 464 3563
245 272 3102
*/
