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
const int INF=1e9;/*
int main(){
    int n,m;
    cin>>n>>m;
    ii card[n];
    FOR(i,n)scanf("%d %d",&card[i].f,&card[i].s);
    int s[m];
    FOR(i,m){
    scanf("%d",&s[i]);
    }
    int ans[n];
    sort(s,s+m);
    int bf=n-1;
    int st=1;
    for(int i=m-1;i>=0;i--){
        for(int j=bf;j>s[i];j--){
        ans[j]=st?card[j].f:card[j].s;
        }
    if(st)st=0;
    else st=1;
    bf=s[i];
    }
    for(int j=bf;j>=0;j--){
         ans[j]=st?card[j].f:card[j].s;
    }
    FOR(i,n)printf("%d\n",ans[i]);
}*/
