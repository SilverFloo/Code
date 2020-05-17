#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
#define p push_back
using namespace std;
const int MAX=3e5+5;
int x[MAX],y[MAX];
int scc[MAX];
int n,m,c=0;
stack<int> st;
vector<int> edge[MAX<<1],iedge[MAX<<1];
bool visit[MAX<<1],ivisit[MAX<<1];
void built(){
    FOR(i,n){
    int a=x[i],b=y[i];
        edge[n+a].p(b);
        edge[n+b].p(a);
        iedge[b].p(n+a);
        iedge[a].p(n+b);
    }
}

void DFS1(int s){
    if(!visit[s]){
        visit[s]=1;
        for(auto i:edge[s]){
            DFS1(i);
        }
    }
    st.push(s);
}

void DFS2(int s){
    if(!ivisit[s]){
        ivisit[s]=1;
        for(auto i:iedge[s]){
            DFS1(i);
        }
    }
    scc[s]=c;
}
int main(){
    cin>>m>>n;
    FOR(i,m+n/2){scanf("%d %d",&x[i],&y[i]);x[i]--;y[i]--;}
    built();
    FOR(i,n)if(visit[i]==0)DFS1(i);
    while(!st.empty()){
       int a=st.top();
       st.pop();
       if(!ivisit[a]){DFS2(a);c++;}
    }
    int c=1;
    FOR(i,n){
    if(scc[i]==scc[n+i]){printf("N");c=0;break;}
    }
    if(c)printf("Y");
}
