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
using namespace std;
const int INF=1e9;

const int MAX=100005;
int T1[MAX<<1],T2[MAX<<1];
void update(int x,int v,int T[],int p=1,int l=1,int r=MAX){
    if(l==r){
        T[p]=v;
        return;
    }
    int m=(l+r)/2;
    if(x<=m)update(x,v,T,p<<1,l,m);
    else update(x,v,T,(p<<1)|1,m+1,r);
    T[p]=max(T[p<<1],T[(p<<1)|1]);
}
int query(int st,int ed,int T[],int p=1,int l=1,int r=MAX){
    if(r<st||l>ed)return 0;
    if(st<=l&&r<=ed)return T[p];
    int m=(l+r)/2;
    return max(query(st,ed,T,p<<1,l,m),query(st,ed,T,(p<<1)|1,m+1,r));
}
int tab[MAX];
int main(){
    int T;
    cin>>T;
    FOR1(x,T){
        FOR(i,MAX<<1)T1[i]=0,T2[i]=0;
        deque<int> c,d;
        int n,k;
        cin>>n>>k;
        FOR(i,n){
            int x;
            scanf("%d",&x);
            tab[i]=x;
            update(i+1,x,T1);
        }
        FOR(i,n){
            int x;
            scanf("%d",&x);
            update(i+1,x,T2);
        }
        ll ans=0;
        FOR1(i,n){
            for(int j=i;j<=n;j++){
                if(abs(query(i,j,T1)-query(i,j,T2))<=k)ans++;
            }
        }
        printf("Case #%d: %lld\n",x,ans);
    }
}
