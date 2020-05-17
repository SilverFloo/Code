#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;
const int MAX=1e5+5;
int ans[MAX];
int visit[MAX];
vector<int> e[MAX];
queue<pair<int,int>> qq;

inline void built(int s,int l){
ans[s]=l;visit[s]=1;
for(auto i:e[s]){
if(!visit[i])built(i,l+1);
}
}

inline void update(int s,int l){
ans[s]=l;
for(auto i:e[s]){
if(l+1<ans[i])update(i,l+1);
}
}

int main(){
int n,q;
scanf("%d%d",&n,&q);
FOR(i,n-1){
int a,b;
scanf("%d %d",&a,&b);
a--;b--;
e[a].pb(b);
e[b].pb(a);
}
built(0,0);
FOR(i,q){
int a,b;
scanf("%d %d",&a,&b);
if(a==2){
while(!qq.empty()){
        int u=qq.front().f;
        int l=qq.front().s;
       if(l<ans[u]) ans[u]=l;
    for(auto j:e[u]){
        if(l+1<ans[j]){qq.p(j,l+1);}
    }
    qq.pop();
}
printf("%d\n",ans[b-1]);}
else{qq.p(b-1,0);}
}
}
