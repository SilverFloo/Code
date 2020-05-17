#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define pb emplace_back
#define p emplace
#define all(x) x.begin(),x.end()
#define ii pair<int,int>
#define ll long long
#define f first
#define s second
using namespace std;
int h[100005];
int d[100005];
int t[100005];
int tmp[100005];
int ans[100005];
vector<int> x[100005];
void update(int p){
    for(int i=p;i<100005;i+=i&-i)t[i]++;
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i)ans+=t[i];
    return ans;
}
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        scanf("%d",&h[i]);
    }
    FOR(i,n)scanf("%d",&d[i]);
    FOR(i,n)x[max(0,i-d[i])].pb(i);
    FOR1(i,n-1){
        update(h[i-1]);
        for(auto j:x[i]){
            tmp[j]=i-query(h[j]);
        }
        ans[i]=i-query(h[i])-tmp[i];
    }

    FOR1(i,n)t[i]=0;
    FOR(i,n+1)x[i].clear();
    FOR(i,n)tmp[i]=0;
    FOR(i,n)x[min(n-1,i+d[i])].pb(i);
    for(int i=n-2;i>=0;i--){
            //printf("\n%d : ",i);
        update(h[i+1]);
        for(auto j:x[i]){//printf("%d ",j);
            tmp[j]=query(h[j]);
        }
        ans[i]+=query(h[i])-tmp[i];
    }
    ll aa=0;
    FOR(i,n)aa+=(ll)ans[i];
    printf("%lld",aa);
    //FOR(i,n)printf("%d ",ans[i]);
}/*
15 min 0%
10 min 100%
-> fix line 43 n to n+1
-> add line 44 clear tmp
*/
