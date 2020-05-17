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
const ll INF=1e12+5;
int main(){
    int n,t;
    cin>>n>>t;
    int v[n];
    ll mx=0;
    FOR(i,n){scanf("%d",&v[i]);if(v[i]>mx)mx=v[i];}
    ll up=-1,low=-1,l=mx,r=INF;
    while(l<=r){
        ll mid=(l+r)/2;
        int cnt=1;ll val=mid;
        FOR(i,n){
           // printf("%lld ",mid);
            if(v[i]>val){val=mid;cnt++;if(cnt>t)break;}
            val-=v[i];
        }
        if(cnt==t)low=mid;
        if(cnt>t)l=mid+1;
        if(cnt<=t)r=mid-1;

        }
    l=mx;r=INF;
    while(l<=r){
        ll mid=(l+r)/2;
        ll cnt=1,val=mid;
        FOR(i,n){
            if(v[i]>val){val=mid;cnt++;if(cnt>t)break;}
            val-=v[i];
        }
        if(cnt==t)up=mid;
        if(cnt>=t)l=mid+1;
        if(cnt<t)r=mid-1;
    }
    if(up==INF)printf("-1");
    else if(up==-1)printf("0");
    else printf("%lld",up-low+1);
}
