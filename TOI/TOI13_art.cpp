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
const int MAX=1e6+5;
vector<ii> u[(int)4e6+5];
int fenwick[MAX];
void update(int v,int p){
    for(int i=1;i<MAX;i+=i&-i){
        fenwick[i]+=v;
    }
    for(int i=p;i<MAX;i+=i&-i){
        fenwick[i]-=v;
    }
}



int query(int p){
    int sum=0;
    for(int i=p;i>0;i-=i&-i){
        sum+=fenwick[i];
    }
    return sum;
}

int main(){
    int n,t;
    cin>>n>>t;
    FOR(i,n){
        int s,h,w,o;
        scanf("%d %d %d %d",&s,&h,&w,&o);
        u[s].pb(h+1,o);


        u[s+w].pb(h+1,-o);
    }
    ll ans=0;
    int pre=0;
    int bf=0;
    FOR1(i,4e6){
        if(u[i].empty())continue;
       // printf("<%d>",i);
    for(auto j:u[i])update(j.s,j.f);
    //FOR1(i,10)printf("%d ",query(i));printf("\n");
    int l=1,r=MAX-1;
    int low=-1;
    while(l<=r){
        int m=(l+r)/2;
        int a=query(m);
        if(a==t)low=m;
        if(a<=t)r=m-1;
        else l=m+1;
    }
    l=1;r=MAX-1;
    int up=-1;
    while(l<=r){
        int m=(l+r)/2;
        int a=query(m);
        if(a==t)up=m;
        if(a<t)r=m-1;
        else l=m+1;
    }
    ans+=pre*(i-bf);
    if(low==-1){
        bf=i;
        pre=0;
    }
    else {
        bf=i;
        pre=up-low+1;
    }
    //printf("%d %d",up,low);
    }
    printf("%lld",ans);
}
