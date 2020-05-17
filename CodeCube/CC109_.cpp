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
const int MAX=1e5+5;
int val[MAX];
bool visit[MAX];
priority_queue<ii,vector<ii>,greater<ii>> q;
int main(){
    int n,k;
    cin>>n>>k;
    FOR(i,n){
    scanf("%d",&val[i]);
    q.p(0,i);
    }
    int d=0;
    while(!q.empty()&&q.top().f<=d){
    ii now=q.top();
    if(!visit[now.s]){visit[now.f]=1;}
    else if(k>0){k--;}
    else d--;
    q.pop();
    q.p(d+val[now.s],now.s);
    d++;
    }
    printf("%d",d);
}
