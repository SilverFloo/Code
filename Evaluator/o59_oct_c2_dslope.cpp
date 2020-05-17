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
ll t[50][100005];
int pos[100005];
int n,k;
ll mod = 1e9-1;
void update(int x,int p,ll v){
    v+=mod;
    v%=mod;
    for(int i=p;i<=n;i+=i&-i){
        t[x][i]+=v;
        t[x][i]%=mod;
    }
}
ll query(int x,int p){
    if(p==0)return 0;
    ll ans=0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[x][i];
    }
    return ans%mod;
}
int main(){
    cin>>n>>k;
    FOR1(i,n){
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    for(int i=n;i>0;i--){
        update(1,pos[i],1);
        for(int j=2;j<=k;j++){
            update(j,pos[i],query(j-1,pos[i]-1));
        }
    }
    printf("%lld",query(k,n));
}
