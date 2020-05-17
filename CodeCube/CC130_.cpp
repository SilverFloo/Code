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
int tab[100005],dp[100005];
int t[100005<<1];
int n,k;
void update(int v,int x,int p=1,int l=1,int r=n){
    if(l==r){
        t[p]=v;return;
    }
    int m=(l+r)/2;
    if(x<=m)update(v,x,p<<1,l,m);
    else update(v,x,p<<1|1,m+1,r);
    t[p]=max(t[p<<1],t[p<<1|1]);
}
int mx(int st,int ed,int p=1,int l=1,int r=n){
    if(st>r||ed<l)return -INF;
    if(st<=l&&r<=ed)return t[p];
    int m=(l+r)/2;
    return max(mx(st,ed,p<<1,l,m),mx(st,ed,p<<1|1,m+1,r));
}
int main(){
    cin>>n>>k;
    FOR1(i,n){scanf("%d",&tab[i]);update(tab[i],i);}
    deque<int> q;
    q.pb(0);
    FOR1(i,n){
    while(!q.empty()&&dp[q.back()]+mx(q.back()+1,i)>dp[i-1]+tab[i])q.pop_back();
    q.push_back(i-1);
    while(!q.empty()&&q.front()<i-k)q.pop_front();
    dp[i]=dp[q.front()]+mx(q.front()+1,i);
printf("%d ",dp[i]);
    }
    printf("%d",dp[n]);
}
/*


20
3
1 4 2 9 2 8 5 2 9 8 2 4 3 2 7 3 7 1 9 5 7

47
*/
