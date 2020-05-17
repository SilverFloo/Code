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
int pre[1005];
int pos[1005];
bool visit[1005];
int l[1005];
int r[1005];
map<int,int> m;
map<int,int> m2;
void dfs(int u){
    if(u==0)return;
   // printf("/%d<-%d->%d/ ",l[u],u,r[u]);
    dfs(l[u]);
    printf("%d\n",m2[u]);

    dfs(r[u]);
}
int main(){
    int n;
    cin>>n;

    FOR(i,n){
        int x;
        scanf("%d",&x);
        m[x]=i+1;
        m2[i+1]=x;
        pre[i]=i+1;
        }
    FOR(i,n){
        int x;
        scanf("%d",&x);
        pos[i]=m[x];
        //printf("%d ",pos[i]);
        }
    visit[pre[0]]=1;
    int i=0;
    int u=pre[0];
    while(++i){
        l[u]=pre[i];
        //printf("<%d>",pre[i]);
        visit[i]=1;
        u=pre[i];
        if(pre[i]==pos[0]){break;}

    }
    //printf("/%d/",i);
    while(++i){
            if(i==n)break;
        int st=0;
        //printf("xx%dxx",visit[2]);
        for(int j=0;j<n;j++){
            if(st){
                if(visit[pos[j]]){
                    if(l[pos[j]]==0){l[pos[j]]=pre[i];break;}
                    else {r[pos[j]]=pre[i];break;}
                }

            }
            if(pre[i]==pos[j])st=1;
        }
        visit[pre[i]]=1;
       // dfs(pre[0]);
       // printf("\n");
    }

    dfs(pre[0]);
}
/*


13
1 2 3 6 8 10 11 9 7 12 13 5 4
3 10 11 8 9 6 2 13 5 12 4 7 1

*/
