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
bool visit[1005][2000];
vector<ii> edge[1005];
int main(){
    int n,m;
    cin>>n>>m;
    int x;
    cin>>x;
    while(x--){
        int a,b;
        scanf("%d %d",&a,&b);
        edge[a].pb(b,0);
    }
    cin>>x;
    while(x--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge[a].pb(b,c);
    }
    int st,b;
    cin>>st>>b;
    int ans=INF;
    queue<ii> q;
    q.p(st,b);
    visit[st][b]=1;
    while(!q.empty()){
        int st=q.front().s;
        int u=q.front().f;
        q.pop();
        //printf("%d %d>",u,st);
        for(auto v:edge[u]){
            if(st-v.s>=0&&!visit[v.f][st-v.s]){
                if(st-v.f==0&&v.f<=m){printf("0");return 0;}
                if(v.f<=m)ans=min(ans,st-v.f);
                visit[v.f][st-v.s]=1;
                q.p(v.f,st-v.s);
            }
        }
    }

    printf("%d",ans);

}
