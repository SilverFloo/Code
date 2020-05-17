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
#define ii pair<long long, long long>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
ll a[200005];
ii b[200005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n)scanf("%lld",&a[i]);
    FOR(j,m){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        b[j].f=x-y;
        b[j].s=x+y;
    }
    sort(a,a+n);
    sort(b,b+m);
    priority_queue<ll,vector<ll>,greater<ll>> q;
    int i=0,j=0;
    ll ans=0;
    while(i<n&&j<m){
        if(a[i]<b[j].f){
            while(!q.empty()&&q.top()<a[i])q.pop();
            if(!q.empty()){
                q.pop();
                ans++;
            }
            i++;
        }
        else{
            while(!q.empty()&&q.top()<b[j].f)q.pop();
            q.p(b[j].s);
            j++;
        }
    }
    while(i<n){
         while(!q.empty()&&q.top()<a[i])q.pop();
            if(!q.empty()){
                q.pop();
                ans++;
            }
            i++;
    }
    while(j<m){
        while(!q.empty()&&q.top()<b[j].f)q.pop();
            q.p(b[j].s);
            j++;
    }
    printf("%lld",ans);
}
