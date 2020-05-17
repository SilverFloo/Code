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
int tab[300005];
ll fac[300005];
int t[300005];
ll mod=1000000007;
void update(int p,int v){
    for(int i=p;i<300005;i+=i&-i){
        t[i]+=v;
    }
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i){
        ans+=t[i];
    }
    return ans;
}
void cal(){
    fac[1]=1;
    for(int i=2;i<300005;i++){
        fac[i]=(fac[i-1]*(ll)i)%mod;
    }
}
int main(){
    cal();
    ll ans=0;
    int n;
    cin>>n;
    map<int,int> m;
    FOR(i,n){
        scanf("%d",&tab[i]);
        m[tab[i]]=1;
        update(i+1,1);
    }


    int ptr=1;
    for(auto &i:m){
        i.s=ptr++;
    }
    FOR(i,n){
        update(m[tab[i]],-1);
        ans+=((ll)query(m[tab[i]])*fac[n-i-1])%mod;
        ans%=mod;
    }
    cout<<(ans+1)%mod;
}
