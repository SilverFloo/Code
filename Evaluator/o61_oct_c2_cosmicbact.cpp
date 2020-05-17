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
typedef struct node{
    ll p,t,x;
    node(ll p,ll t,ll x):p(p),t(t),x(x){}
    bool operator < (const node &ot)const{
        return p<ot.p;
    }
}node;
vector<node> a;
vector<node> b;
bool visit[100005];
ll ans[100005];
int main(){
    int n;ll l;
    scanf("%d %lld",&n,&l);
    FOR(i,n){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        a.pb(x,y+i,i);
    }
    sort(all(a));
    int bf=0;
    for(int i=1;i<n;i++){
        if(a[i].p-a[bf].p+a[bf].t<a[i].t)visit[i]=1;
        if(a[i].p-a[bf].p+a[bf].t==a[i].t)if(a[bf].x<a[i].x)visit[i]=1;
        if(!visit[i])bf=i;
       // printf("%lld %lld",a[i].p-a[bf].p,a[bf].t<a[i].t);
    }
    bf=n-1;
    for(int i=n-2;i>=0;i--){
            int xxx=0;
        if(a[bf].p-a[i].p+a[bf].t<a[i].t)xxx=1;
        if(a[bf].p-a[i].p+a[bf].t==a[i].t)if(a[bf].x<a[i].x)xxx=1;
        if(!xxx)bf=i;
        if(xxx)visit[i]=xxx;
    }
    FOR(i,n){
        if(!visit[i])b.pb(a[i]);
    }

    ans[b[0].x]+=b[0].p+1;

    ans[b[b.size()-1].x]+=l-b[b.size()-1].p;
    FOR(i,b.size()-1){
        ll l=b[i].p,r=b[i+1].p;
        ll xx;
        while(l<=r){
            ll m=(l+r)/2;
            if(m-b[i].p+b[i].t<=b[i+1].p-m+b[i+1].t){
                xx=m;
                l=m+1;
            }
            else r=m-1;
           // printf("%lld : %lld %lld/",m,m-b[i].p+b[i].t,b[i+1].p-m+b[i+1].t);
        }
        if(xx-b[i].p+b[i].t==b[i+1].p-xx+b[i+1].t){
            if(b[i].x>b[i+1].x)xx--;
        }
        //printf(">>%lld",xx);
        ans[b[i].x]+=xx-b[i].p;
        ans[b[i+1].x]+=b[i+1].p-xx;
    }
    FOR(i,n)printf("%lld\n",ans[i]);
}
/*

6 10
1 2
6 5
7 2
3 4
4 1
6 5

*/
