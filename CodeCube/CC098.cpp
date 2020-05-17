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
const int MAX=1e6+5;
int rose[MAX],pre[MAX];
int main(){
    int n,m;
    cin>>n>>m;
    FOR(i,n)scanf("%d",&rose[i]);
    int cnt=0;
    FOR1(i,m){
    int a;
    scanf("%d",&a);
    a--;
    //printf("%d %d",pre[a]+rose[a],i);
    if(pre[a]+rose[a]<=i){cnt++;pre[a]=i;}
    }
    printf("%d",cnt);
}
