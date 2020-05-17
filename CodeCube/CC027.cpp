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
bool visit[1<<20+5];
int main(){
    int n;
    cin>>n;
    int x=0;
    FOR(i,n){
    int a;
    scanf("%d",&a);
    x<<=1;
    x|=a;
    }
    queue<ii> q;
    q.p(x,0);
    visit[x]=1;
    while(!q.empty()){
    int a=q.front().f;
    int t=q.front().s;
    if(a==0)printf("%d",t),exit(0);
    //printf("\n");
    q.pop();
    FOR(i,n){
    int now=a;
    now^=1<<i;
    if(i>0)now^=1<<(i-1);
    if(i<n-1)now^=1<<(i+1);
    if(!visit[now]){q.p(now,t+1);visit[now]=1;}
   // printf("%d >",now);
    }
    }
    printf("-1");
}
