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
pair<ii,ii> tab[1005];
vector<pair<ii,ii>> v,pl,mi;
int main(){
    int n;
    cin>>n;
    FOR(i,n)scanf("%d %d %d %d",&tab[i].f.f,&tab[i].s.s,&tab[i].f.s,&tab[i].s.f);
    sort(tab,tab+n);
    FOR(i,n){
        pl.pb(tab[i]);
        for(int j=i+1;j<n;j++){
            if(tab[j].f.f>=tab[i].f.s)break;
            if(tab[j].s.f<tab[i].s.s||tab[j].s.s>tab[i].s.f){
                v.pb(mp(max(tab[i].f.f,tab[j].f.f),min(tab[i].f.s,tab[j].f.s)),mp(max(tab[i].s.f,tab[j].s.f),min(tab[i].s.s,tab[j].s.s)));
            }
        }
    }
    for(auto i:v){
        int cnt=0;
        FOR(j,n){
            if(tab[j].f.f<=i.f.f&&tab[j].f.s>=i.f.s&&tab[j].s.f<=i.s.f&&tab[j].s.s>=i.s.s)cnt++;
        }
        if(cnt%2)pl.pb(i);
        else mi.pb(i);
    }
    ll ans=0;
    for(auto i:pl){
        ans+=(ll)(i.f.s-i.f.f)*(ll)(i.s.s-i.s.f);
    }
    for(auto i:mi){
        ans-=(ll)(i.f.s-i.f.f)*(ll)(i.s.s-i.s.f);
    }
    printf("%lld",ans);

}
