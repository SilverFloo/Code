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
int main(){
    vector<ll> a,b,c;
    int n;
    ll ans=0;
    cin>>n;
    int ch=0;
    FOR(i,n){
    char x;ll y;
    scanf(" %c%lld",&x,&y);
    switch(x){
        case '+':a.pb(y);break;
        case '-':b.pb(y);break;
        case 'x':
        if(y==0)ch=1;
        else c.pb(y);
        break;
    }}
        for(auto i:a)ans+=i;
        for(auto i:c)ans*=i;
    if(!ch){
        for(auto i:b)ans-=i;
    }


    printf("%lld",ans);
}
