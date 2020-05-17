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
vector<ii> edge[100];
int main(){
    map<char,int> m;
    int cnt=0;
    FOR(i,26)m['A'+i]=cnt++;
    for(int i=26;i<26+26;i++)m['a'+i-26]=cnt++;
    //printf("%d %d %d",m['a'],m['e'],m['d']);
    int n;
    cin>>n;
    FOR(i,n){
        char a,b;
        int c;
        scanf(" %c %c %d",&a,&b,&c);
        edge[m[a]].pb(m[b],c);
        edge[m[b]].pb(m[a],c);
    }
    priority_queue<ii,vector<ii>,greater<ii>> q;
    int dist[100];
    FOR(i,100)dist[i]=INF;
    dist[m['Z']]=0;
    q.p(0,m['Z']);
    while(!q.empty()){
        int u=q.top().s,l=q.top().f;
        q.pop();
        if(l!=dist[u])continue;
        //printf("%d %d/",u,l);
        for(auto v:edge[u]){
             //   printf("<%d %d>",v.f,v.s);
            if(dist[v.f]>dist[u]+v.s){
                dist[v.f]=dist[u]+v.s;
                q.p(dist[v.f],v.f);
            }
        }
    }
    int ans=INF;
    int p;
    FOR(i,25){if(dist[i]<ans)ans=dist[i],p=i;
   // printf("%c %d",'A'+i,dist[i]);
    }
    printf("%c %d",p+'A',ans);

}
