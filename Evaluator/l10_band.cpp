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
bool e[1005][1005];
ii edge[5005];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,m){
        scanf("%d %d",&edge[i].f,&edge[i].s);
        e[edge[i].f][edge[i].s]=1;
        e[edge[i].s][edge[i].f]=1;
    }
    int cnt=0;
    int ans=0;
    FOR(i,m){
        int u=edge[i].f,v=edge[i].s;
        vector<int> con;
        for(int j=1;j<=n;j++){
            if(j!=u&&j!=v){
                if(e[u][j]&&e[v][j])con.pb(j);
            }
        }

        for(int j=0;j<con.size();j++){
          //       printf("%d %d> ",con.size(),con[j]);
            for(int k=j+1;k<con.size();k++){
                if(e[con[j]][con[k]])cnt++;
            }
        }
   // printf("\n");
        ans+=con.size()*(con.size()-1);
    }
    printf("%d",ans/2-cnt+cnt/6);
}
