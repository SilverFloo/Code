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
const int INF=2e9;
int tab[100005];
int dp[100005];
int t[400005][2];
int lz[400005];
void uplz(int p,int v){
    t[p][0]=t[p][1]+v;
    lz[p]=v;
}
void dolz(int p){
    if(lz[p]==0)return;
    uplz(p<<1,lz[p]);
    uplz(p<<1|1,lz[p]);
    lz[p]=0;
}
void update_dp(int x,int v,int p=1,int l=0,int r=100000){
    if(l==r){
        t[p][1]=v;
        //printf("<%d %d %d-> %d %d>\n",p,l,r,t[p][0],t[p][1]);
        return;
    }
    dolz(p);
    int m=(l+r)/2;
    if(x<=m)update_dp(x,v,p<<1,l,m);
    else update_dp(x,v,p<<1|1,m+1,r);
    t[p][1]=min(t[p<<1][1],t[p<<1|1][1]);
}
void update(int st,int ed,int v,int p=1,int l=0,int r=100000){
    if(st>r||ed<l)return;
    if(st<=l&&r<=ed){
        uplz(p,v);
       // printf("<<%d>>",t[p][0]);
        return;
    }
    int m=(l+r)/2;
    dolz(p);
    update(st,ed,v,p<<1,l,m);
    update(st,ed,v,p<<1|1,m+1,r);
    t[p][0]=min(t[p<<1][0],t[p<<1|1][0]);
}
int query(int st,int ed,int p=1,int l=0,int r=100000){
    if(st>r||ed<l)return INF;
    if(st<=l&&r<=ed){
      //  printf("(%d %d -> %d)\n",l,r,t[p][0]);
        return t[p][0];
    }
    int m=(l+r)/2;
    dolz(p);
    return min(query(st,ed,p<<1,l,m),query(st,ed,p<<1|1,m+1,r));
}
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n)scanf("%d",&tab[i]);
    deque<int> q;
    for(int i=0;i<n;i++){
        while(!q.empty()&&tab[q.back()]<tab[i])q.pop_back();
        while(!q.empty()&&q.front()<=i-k)q.pop_front();
        if(q.empty())update(max(0,i-k+1),i,tab[i]);
        else update(q.back()+1,i,tab[i]);
        q.push_back(i);
        //printf("\"%d\"",query(1,1));
        dp[i]=query(max(0,i-k+1),i);
        update_dp(i+1,dp[i]);
        //printf("%d = %d\n",i,dp[i]);
    }
    printf("%d",dp[n-1]);
}
