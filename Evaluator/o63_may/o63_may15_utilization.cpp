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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int sum[100005];
queue<ii> q[100005];
int cnt[100005];
priority_queue<ii> pq;
int main(){
    rf();
    int n,m,k;
    cin>>m>>n>>k;
    FOR(i,n){
        int x;
        cin>>x;
        while(x--){
            int a,b;
            scanf("%d %d",&a,&b);
            if(a==0)continue;
            sum[i]+=b;
            q[i].p(a,b);
        }
        pq.p(sum[i],i);
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        ans+=(ll)pq.top().f;
        int x=pq.top().s;
        pq.pop();
        cnt[x]++;
        if(cnt[x]==q[x].front().f){
            sum[x]-=q[x].front().s;
            q[x].pop();
        }
        pq.p(sum[x],x);
    }
    printf("%f",(double)ans/k);

}