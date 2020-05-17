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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
int e[1005][1005];
int dp[1005][1005][3];
vector<int> edge[1005];
int visit[1005];
pair<ii,ii> bf[1005][1005];

    int n,m;
void print(int i,int j,int z){
    if(i==j){
        return;
    }
            int x=i<j?j:j+n;
            for(int y=i;y<x;y++){
                int k=y%n;
                int kk=(y+1)%n;
                if(z==0&&dp[i][k][2]){
                    if(e[k][kk]&&dp[kk][j][0]){
                        print(i,k,2);print(kk,j,0);
                        edge[kk].pb(k);edge[k].pb(kk);
                        return;
                    }
                    if(e[k][j]&&dp[kk][j][1]){
                        print(kk,j,1);print(i,k,2);
                        edge[j].pb(k);
                        edge[k].pb(j);
                        return;
                    }
                }
                if(z==1&&dp[kk][j][2]){
                    if(e[kk][k]&&dp[i][k][1]){
                        print(kk,j,2);print(i,k,1);
                        edge[k].pb(kk);
                        edge[kk].pb(k);
                        return;
                    }
                    if(e[kk][i]&&dp[i][k][0]){
                        print(i,k,0);print(kk,j,2);
                        edge[kk].pb(i);
                        edge[i].pb(kk);
                        return;
                    }
                }
                if(z==2&&dp[i][k][2]&&dp[kk][j][2]){
                    if(e[k][kk]){
                        print(i,k,2);print(kk,j,2);
                        edge[k].pb(kk);
                        edge[kk].pb(k);
                        return;
                    }
                }
            if(y==i)y=x-2;
        }

}
void find(int x){
    visit[x]=1;
    printf("%d\n",x+1);
    for(auto j:edge[x])if(!visit[j])find(j);
}
int main(){
    cin>>n>>m;
    FOR(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;b--;
        e[a][b]=1;
        e[b][a]=1;
    }
    FOR(i,n)dp[i][i][0]=dp[i][i][1]=dp[i][i][2]=1;
    for(int l=1;l<n;l++){
        for(int i=0;i<n;i++){
            int x=i+l;
            int j=x%n;
            int y=i;
                int k=y%n;
                int kk=(y+1)%n;
                if(dp[i][k][2]){
                    if(e[k][kk]&&dp[kk][j][0])dp[i][j][0]=1;
                    if(e[k][j]&&dp[kk][j][1])dp[i][j][0]=1;
                }
                if(dp[kk][j][2]){
                    if(e[kk][k]&&dp[i][k][1])dp[i][j][1]=1;
                    if(e[kk][i]&&dp[i][k][0])dp[i][j][1]=1;
                }
                if(dp[i][k][2]&&dp[kk][j][2]){
                    if(e[k][kk])dp[i][j][2]=1;
                }
            y=x-1;
                k=y%n;
                kk=(y+1)%n;
                if(dp[i][k][2]){
                    if(e[k][kk]&&dp[kk][j][0])dp[i][j][0]=1;
                    if(e[k][j]&&dp[kk][j][1])dp[i][j][0]=1;
                }
                if(dp[kk][j][2]){
                    if(e[kk][k]&&dp[i][k][1])dp[i][j][1]=1;
                    if(e[kk][i]&&dp[i][k][0])dp[i][j][1]=1;
                }
                if(dp[i][k][2]&&dp[kk][j][2]){
                    if(e[k][kk])dp[i][j][2]=1;
                }
            if(l==n-1){
                if(dp[i][j][0]==1){print(i,j,0);find(i);return 0;}
                else if(dp[i][j][1]==1){print(i,j,1);find(j);return 0;}
                else if(dp[i][j][2]==1){print(i,j,2);find(i);return 0;}
            }
        }

    }
printf("-1");
}
