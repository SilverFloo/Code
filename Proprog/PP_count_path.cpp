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
int main(){
    int n;int ch=0;
    while(cin>>n){
        int deg[n];
        int path[n];
        vector<int> e[n];
        queue<int> q;
        FOR(i,n){
        scanf("%d",&deg[i]);
        path[i]=0;
        if(deg[i]==0)path[i]=1,q.p(i);
        FOR(j,deg[i]){
        int a;
        scanf("%d",&a);
        e[a].pb(i);
        }
        while(!q.empty()){
        for(auto i:e[q.front()]){
        path[i]+=path[q.front()];
        deg[i]--;
        if(deg[i]==0)q.p(i);
        }
        q.pop();
        }

        }
        if(ch==1)printf("\n");
        else ch=1;
        printf("%d",path[0]);

    }
}
