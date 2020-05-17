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
ii a[50005];
ii mn[50005],mx[50005];
int main(){
    int n;
    cin>>n;
    ii c,d;
    c.f=0;
    c.s=INF;
    d.f=0;
    d.s=INF;
    FOR(i,n){
        scanf("%d %d",&a[i].f,&a[i].s);
        c.f=max(c.f,a[i].f);
        c.s=min(c.s,a[i].f);
        d.f=max(d.f,a[i].s);
        d.s=min(d.s,a[i].s);
    }
    ll area = (ll)(c.f-c.s)*(ll)(d.f-d.s);
    sort(a,a+n);
    mn[n-1].f=a[n-1].f;
    mn[n-1].s=a[n-1].s;
    mx[n-1].f=a[n-1].f;
    mx[n-1].s=a[n-1].s;
    for(int i=n-2;i>=0;i--){
        mn[i].f=min(mn[i+1].f,a[i].f);
        mn[i].s=min(mn[i+1].s,a[i].s);
        mx[i].f=max(mx[i+1].f,a[i].f);
        mx[i].s=max(mx[i+1].s,a[i].s);
    }
    ll ans=1e18+5;
    c.f=a[0].f,c.s=a[0].s,d.f=a[0].f,d.s=a[0].s;
    for(int i=0;i<n-1;i++){
        c.f=max(a[i].f,c.f);
        c.s=max(a[i].s,c.s);
        d.f=min(a[i].f,d.f);
        d.s=min(a[i].s,d.s);
        //cout<<'a'<<(ll)(mx[i+1].f-mn[i+1].f)*(ll)(mx[i+1].s-mn[i+1].s)<<' '<<(ll)(c.f-d.f)*(ll)(c.s-d.s)<<endl;
        ans=min(ans,(ll)(mx[i+1].f-mn[i+1].f)*(ll)(mx[i+1].s-mn[i+1].s)+(ll)(c.f-d.f)*(ll)(c.s-d.s));
    }

    FOR(i,n)swap(a[i].f,a[i].s);
    sort(a,a+n);

    mn[n-1].f=a[n-1].f;
    mn[n-1].s=a[n-1].s;
    mx[n-1].f=a[n-1].f;
    mx[n-1].s=a[n-1].s;
    for(int i=n-2;i>=0;i--){
        mn[i].f=min(mn[i+1].f,a[i].f);
        mn[i].s=min(mn[i+1].s,a[i].s);
        mx[i].f=max(mx[i+1].f,a[i].f);
        mx[i].s=max(mx[i+1].s,a[i].s);
    }
    c.f=a[0].f,c.s=a[0].s,d.f=a[0].f,d.s=a[0].s;
    for(int i=0;i<n-1;i++){
        c.f=max(a[i].f,c.f);
        c.s=max(a[i].s,c.s);
        d.f=min(a[i].f,d.f);
        d.s=min(a[i].s,d.s);
        ans=min(ans,(ll)(mx[i+1].f-mn[i+1].f)*(ll)(mx[i+1].s-mn[i+1].s)+(ll)(c.f-d.f)*(ll)(c.s-d.s));
    }
    printf("%lld",area-ans);
}
