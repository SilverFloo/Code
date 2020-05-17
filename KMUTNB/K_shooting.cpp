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
ii pos[1005];
bool kil[1005][1005];
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d %d",&pos[i].f,&pos[i].s);
    FOR(i,n){
        int c;
        scanf("%d",&c);
        while(c--){
            int a;
            scanf("%d",&a);
            kil[i][a-1]=1;
        }
    }
    vector<ll> a,b;
    FOR(i,n){
        FOR(j,n){
            ll xx=(ll)(pos[i].f-pos[j].f)*(pos[i].f-pos[j].f)+(ll)(pos[i].s-pos[j].s)*(pos[i].s-pos[j].s);
            if(kil[i][j])a.pb(xx);
            else b.pb(xx);
        }
    }
    sort(all(a));sort(all(b));
    //FOR(i,a.size())printf("%lld ",a[i]);
    int l=0;
    int F=1e9;
    ll ans=1e18+5;
    FOR(i,a.size()){
        while(b[l]<=a[i]&&l<b.size())l++;
        //printf("%lld %d %d\n",a[i],l,l+a.size()-i);
        if(l+a.size()-i<F){
            F=l+a.size()-i;
            ans=a[i];
        }
    }
    printf("%lld %d",ans,F-1);
}

/*
4
2 3
3 2
4 5
5 4
2 1 2
3 2 1 3
2 3 4
2 4 3*/
