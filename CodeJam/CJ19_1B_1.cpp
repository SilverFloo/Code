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
int t[100005];
void update(int p,int v){
    if(p==0)return;
    for(int i=p;i<100005;i+=i&-i)t[i]+=v;
}
int query(int p){
    int ans=0;
    for(int i=p;i>0;i-=i&-i)ans+=t[i];
    return ans;
}
vector<int> N[100005];
vector<int> S[100005];
vector<int> E[100005];
vector<int> W[100005];
int main(){
    int T;
    cin>>T;
    FOR(k,T){
        FOR(i,100005){
        N[i].clear();
        S[i].clear();
        E[i].clear();
        W[i].clear();
        t[i]=0;}
        int n,q;
        cin>>n>>q;
        FOR(i,n){
            int a,b;
            char c;
            scanf("%d %d %c",&a,&b,&c);
            a++;b++;
            switch(c){
                case 'N':N[a].pb(b);break;
                case 'S':S[a].pb(b);break;
                case 'E':E[a].pb(b);break;
                case 'W':W[a].pb(b);break;
            }
        }
        int mx=0;
        ii ans={1,1};
        FOR(i,100005)for(auto j:N[i])update(j+1,1);
        FOR(i,100005)for(auto j:S[i])update(1,1),update(j,-1);
        FOR(i,100005)for(auto j:W[i])update(1,1);
        FOR(i,100005)if(query(i)>mx){mx=query(i);ans.s=i;}
        //printf("%d %d",mx,ans.s);
        FOR1(i,100004){
            for(auto j:W[i])update(1,-1);
            if(query(ans.s)>mx){
                mx=query(ans.s);
                ans.f=i;
            }
            for(auto j:E[i])update(1,1);

        }
        printf("CASE #%d: %d %d\n",k+1,ans.f-1,ans.s-1);
    }
}
