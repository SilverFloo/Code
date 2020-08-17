//#include "advisor.h"
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
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
void WriteAdvice(unsigned char a);
void ComputeAdvice(int *C, int N, int K, int M){
    queue<int> nxt[N];
    int t[N+K];
    int now[N];
    FOR(i,N){
        nxt[C[i]].p(i);
        now[i]=-1;
    }
    set<ii> s;
    FOR(i,N){
        if(i<K){
        now[i]=i;
        s.p(nxt[i].empty()?INF:nxt[i].front(),i);}
        if(!nxt[i].empty())nxt[i].pop();

    }
    FOR(i,N+K)t[i]=0;
    FOR(i,N){
        if(now[C[i]]!=-1){
            t[now[C[i]]]=1;
            now[C[i]]=i+K;
            s.erase(mp(i,C[i]));
            s.p(nxt[C[i]].empty()?INF:nxt[C[i]].front(),C[i]);
            if(!nxt[C[i]].empty())nxt[C[i]].pop();
            continue;
        }
        else{
           // printf("<%d>\n",i);
           // printf("erase %d nxt : %d\n",s.rbegin()->s,s.rbegin()->f);
            now[s.rbegin()->s]=-1;
            s.erase(*s.rbegin());
            now[C[i]]=i+K;
            s.p(nxt[C[i]].empty()?INF:nxt[C[i]].front(),C[i]);
          //  printf("insert %d at %d\n",C[i],nxt[C[i]].empty()?INF:nxt[C[i]].front());
            if(!nxt[C[i]].empty())nxt[C[i]].pop();
            continue;
        }
    }
    FOR(i,N+K){
        //printf("%d ",t[i]);
        WriteAdvice(t[i]?1:0);
    }
}