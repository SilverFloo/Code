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
#define rf() freopen("input.txt","r",stdin);
using namespace std;
const int INF=1e9;
ii tab[50005];
ll dp[50005];
pair<ll,ll> line[50005];
int st=0,ed=0;
vector<ii> t;
double cut(pair<ll,ll> a,pair<ll,ll> b){
    return (double)(b.s-a.s)/(double)(a.f-b.f);
}
void insert(ll m,ll c){
    while(ed-st>=2){
        if(cut(line[ed-1],line[ed-2])>=cut(line[ed-1],mp(m,c)))ed--;
        else break;
    }
    line[ed] = mp(m,c);
    ed++;
}
ll query(int x){
    while(ed-st>=2){
        if(line[st].f*(ll)x+line[st].s>=line[st+1].f*(ll)x+line[st+1].s)st++;
        else break;
    }
    return (ll)line[st].f*(ll)x+(ll)line[st].s;
}
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        int a;
        scanf("%d %d %d",&a,&tab[i].f,&tab[i].s);
        tab[i].f*=a;
    }
    sort(tab,tab+n,greater<ii>());
    int mx=0;
    FOR(i,n){
        if(tab[i].s>mx){
            t.pb(tab[i]);
            mx=tab[i].s;
        }
    }
    FOR(i,t.size()){
        insert(t[i].f,i>0?dp[i-1]:0);
        dp[i]=query(t[i].s);
       // printf("%lld(%d %d) ",dp[i],st,ed);
    }
    printf("%lld",dp[t.size()-1]);
}
