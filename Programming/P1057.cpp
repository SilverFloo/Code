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
vector<int> e[1005];
int ch;
bool visit[1005];
void go(int i){

if(visit[i]||ch==0){ch=0;return;}
visit[i]=1;

for(auto j:e[i]){
    go(j);
}
}
int main(){
    int n;
    cin>>n;
    FOR(i,n){
    int m;
    scanf("%d",&m);
    FOR(j,m){
    int a;
    scanf("%d",&a);
    e[i].pb(a-1);
    }
    }
    FOR(i,n){
    FOR(j,n)visit[j]=0;
    ch=1;
    go(i);
    printf("%s\n",!ch?"YES":"NO");
    }
}
