#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define pb emplace_back
#define p emplace
#define ii pair<long long,long long>
#define ll long long
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
ll qs[100005];
ll f[100005];
int t[100005];
int n,k;
map<int,ll> mp;
int find(ll x){
    ll l=0,r=n;
    ll ans=-1;
    while(l<=r){
        int m=(l+r)/2;
        if(f[m]<=x){
            ans=f[m];
            l=m+1;
        }
        else r=m-1;
    }
    return ans;
}
void update(int p,int v){
    for(int i=p;i<100005;i+=i&-i){
        t[i]+=v;
    }
}
ll query(int p){
    ll ans=0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
int main(){
    cin>>n>>k;
    mp[0]=1;
    FOR1(i,n){
        ll x;
        scanf("%lld",&x);
        qs[i]=qs[i-1]+x;
        f[i]=qs[i];
        mp[qs[i]]=1;
    }
    update(1,1);
    int ptr=1;
    for(auto &i:mp)i.s=ptr++;
    sort(f,f+n+1);
    ll l=-1e11,r=1e11;
    ll ans=-1;
    while(l<=r){
        ll m=(l+r)/2;
        ll cnt = 0;
        FOR1(i,n){
            ll pos = find(qs[i]-m);
            //printf("%lld %lld %lld %lld/",qs[i]-m,pos,mp[pos],query(1));
            if(pos!=-1){
                cnt+=query(mp[pos]);
            }
            update(mp[qs[i]],1);
        }
        FOR1(i,n){
            update(mp[qs[i]],-1);
        }
        //printf("%lld %lld\n",m,cnt);
        if(cnt>=k){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    printf("%lld",ans);
}
