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
int n,m;
char tab[1005][1005];
void del(int i,int j){
if(i>=0&&j>=0&&i<n&&j<m){
if(tab[i][j]=='A')tab[i][j]='.';
}
}
int main(){
cin>>n>>m;
FOR(i,n)FOR(j,m)scanf(" %c",&tab[i][j]);
FOR(i,n)FOR(j,m){
if(tab[i][j]=='+'){
    del(i-1,j);
    del(i+1,j);
    del(i,j-1);
    del(i,j+1);
    tab[i][j]='.';
    }
if(tab[i][j]=='x'){
FOR1(x,2){
    del(i-x,j-x);
    del(i-x,j+x);
    del(i+x,j+x);
    del(i+x,j-x);
    }
    tab[i][j]='.';
}
}
int cnt=0;
FOR(i,n)FOR(j,m)if(tab[i][j]=='A')cnt++;
printf("%d\n",cnt);
FOR(i,n){FOR(j,m)printf("%c",tab[i][j]);printf("\n");}
}
