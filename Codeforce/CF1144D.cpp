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
using namespace std;
const int INF=1e9;
int tab[200005];
int cnt[200005];
int x,p=0; int n;
void dfs(int u){
    if(u>0&&tab[u-1]!=x){
        if(tab[u-1]>x)printf("2 %d %d\n",u,u+1);
        else printf("1 %d %d\n",u,u+1);
        tab[u-1]=x;
        dfs(u-1);
    }
    if(u<n-1&&tab[u+1]!=x){
        if(tab[u+1]>x)printf("2 %d %d\n",u+2,u+1);
        else printf("1 %d %d\n",u+2,u+1);
        tab[u+1]=x;
        dfs(u+1);
    }
}
int main(){

    cin>>n;
    FOR(i,n){
        scanf("%d",&tab[i]);
        cnt[tab[i]]++;
    }

    FOR(i,200005){
        if(cnt[i]>p)p=cnt[i],x=i;
    } printf("%d\n",n-p);
    FOR(i,n){
        if(tab[i]==x)dfs(i);
    }

}
