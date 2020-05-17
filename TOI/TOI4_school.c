#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=b-1;i>=a;i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
using namespace std;
const int INF=1e9;

int main(){
vector<pair<int,int>> a;
int n,m;
cin>>n>>m;
char tab[n][m];
int dp[n][m];
FOR(i,n){
FOR(j,m){
scanf(" %c",&tab[i][j]);
dp[i][j]=tab[i][j]=='T'?0:1;
}
}
int mx=0;
FOR(i,n){
FOR(j,m){
if(tab[i][j]==1)if(i>0&&j>0)tab[i][j]=min(tab[i-1][j],min(tab[i][j-1],tab[i-1][j-1]))+1;
if(tab[i][j]>mx){a.resize(0);mx=tab[i][j];a.eb(i,j);}
else if(tab[i][j]==mx)a.eb(i,j);
}
}

}
