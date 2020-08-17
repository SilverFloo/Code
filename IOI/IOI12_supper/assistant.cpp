//#include "assistant.h"
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
//const int INF=1e9;
void PutBack(int T);
int GetRequest();

void Assist(unsigned char *A, int N, int K, int R){
    queue<int> erase;
    set<int> sca;
    FOR(i,K){
        if(A[i]==0){
            erase.p(i);
        }
        sca.insert(i);
    }
    FOR(i,N){
        int a = GetRequest();
        if(sca.find(a)==sca.end()){
            sca.erase(erase.front());
            PutBack(erase.front());
            erase.pop();
        }
        if(A[i+K]==0)erase.push(a);
        sca.insert(a);
    }
}