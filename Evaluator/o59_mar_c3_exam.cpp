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
map<int,int> x;
vector<ii> e;
vector<pair<ii,int>> q;
int t[50005];
void update(int p){
    for(int i=p;i<50005;i+=i&-i)t[i]++;
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i)ans+=t[i];
    return ans;
}
int main(){
    int n;
    cin>>n;
    FOR1(i,n){
        int a;
        scanf("%d",&a);
        if(x.find(a)==x.end())x[a]=i;
        else e.pb(x[a],i),x[a]=i;
    }
    sort(all(e));
    int m;
    cin>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        q.pb(mp(a+1,b+1),i);
    }
    sort(all(q),greater<pair<ii,int>>());
    int ans[m];
    int ptr=e.size()-1;
    for(auto i:q){
         //printf("%d %d %d/",i.f.f,i.f.s,e[ptr].f);
        while(ptr>=0&&e[ptr].f>=i.f.f){

            update(e[ptr].s);
            ptr--;
        }
        ans[i.s]=query(i.f.s);
    }
    FOR(i,m)printf("%d\n",ans[i]);
}
