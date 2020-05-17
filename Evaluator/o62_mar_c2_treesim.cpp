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
int deg[200005];
int visit[200005];
vector<int> e[200005];
vector<int> lv[3][200005];
void dfs(int u,int l,int x){
//printf("%d->%d ",u,l);
    if(deg[u]==1){lv[x][l].pb(u); }
    for(auto v:e[u])if(!visit[v])visit[v]=1,dfs(v,l+1,x);
}
int main(){
    int n;
    cin>>n;
    int st;
    n=2*n-3;
    FOR(i,n){
        int a,b;
        scanf("%d %d",&a,&b);
        deg[a]++;
        deg[b]++;
        e[a].pb(b);
        e[b].pb(a);
    }
    FOR1(i,n){
        int cnt=0;
        if(deg[i]==3)for(auto v:e[i])if(deg[v]==1)cnt++;
        if(cnt==2){st=i;break;}
    }
    visit[st]=1;
    dfs(st,0,0);
    FOR1(i,n+1)e[i].clear();
    FOR1(i,n+1)deg[i]=0;
    FOR(i,n){
        int a,b;
        scanf("%d %d",&a,&b);
        deg[a]++;
        deg[b]++;
        e[a].pb(b);
        e[b].pb(a);
    }
    int tmp;
    FOR1(i,n){
        int cnt=0;
        if(deg[i]==3)for(auto v:e[i])if(deg[v]==1)cnt++;
        if(cnt==2){st=i;tmp=i+1;break;}
    }
    FOR1(i,n+1)visit[i]=0;
    visit[st]=1;
    dfs(st,0,1);

    //cout<<endl;
    int ans0=0,ans1=0;
    for(int i=tmp;i<=n+1;i++){
        int cnt=0;
        if(deg[i]==3)for(auto v:e[i])if(deg[v]==1)cnt++;
        if(cnt==2){st=i;tmp=i+1;break;}
    }
    FOR1(i,n+1)visit[i]=0;
    visit[st]=1;
    dfs(st,0,2);//cout<<endl;
    set<int> s1,s2;
    for(int i=0;i<n;i++){
        if(!lv[0][i].empty()){
            for(auto u:lv[0][i]){
                   // printf("%d ",u);
                if(s1.find(u)!=s1.end())s1.erase(u);
                else s1.insert(u);
                if(s2.find(u)!=s2.end())s2.erase(u);
                else s2.insert(u);
            }//printf("/");
            for(auto u:lv[1][i]){ //printf("%d ",u);
                if(s1.find(u)!=s1.end())s1.erase(u);
                else s1.insert(u);
            }//printf("/");
            for(auto u:lv[2][i]){ //printf("%d ",u);
                if(s2.find(u)!=s2.end())s2.erase(u);
                else s2.insert(u);
            }//printf("/ %d %d ",s1.size(),s2.size());
           // cout<<endl;

            if(!s1.empty())ans0++;
            if(!s2.empty())ans1++;
        }
    }
    printf("%d",min(ans0,ans1));
}
/*
40 min 0% (subtask 2)
1 min 31%
-> expand size of array 100005 to 200005
*/
