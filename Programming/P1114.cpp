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
int e[605][605];
int dist[605];
int main(){
    int n;
    cin>>n;
    n*=2;
    FOR1(i,n){
    FOR1(j,n)scanf("%d",&e[i][j]);
    }
    FOR1(i,n)dist[i]=INF;
    dist[n]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.p(0,n);
    while(!q.empty()){
    int l=q.top().f;
    int u=q.top().s;
    q.pop();
    if(l==dist[u]){
    for(int v=2;v<u;v++){
    if(dist[v]>dist[u]+e[u][v]){
          //  printf("in");
    dist[v]=dist[u]+e[u][v];
    q.p(dist[v],v);
    }
    }
    }

    }
    printf("%d",dist[2]);
}
