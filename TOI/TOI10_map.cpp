#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define ii pair<int,int>
using namespace std;
int n,m;
int mu=2e9,ml=2e9;
int up=0,le=0;

int g[4][40005];
int t=0;
void go(int u,int f){
t++;
//printf("%d %d>",up,le);
if(t>n*m)return;

if(up<mu)mu=up;
if(le<ml)ml=le;
FOR(i,4){
//printf("%d ",g[i][u]);
if(g[i][u]!=0&&((f+2)%2!=i||f==-100)){
if(i==0)up++;
if(i==1)le++;
if(i==2)up--;
if(i==3)le--;
go(g[i][u],(i+2)%2);
}
}
}
int tab[405][405];
void add(int u,int i,int j){
if(tab[i][j]!=0)return;
printf("%d %d->",i,j,u);
tab[i][j]=u;
if(g[0][u]!=0)add(g[0][u],i-1,j);
if(g[1][u]!=0)add(g[1][u],i,j+1);
if(g[2][u]!=0)add(g[2][u],i+1,j);
if(g[3][u]!=0)add(g[3][u],i,j-1);
}

int main(){
cin>>n>>m;
FOR(i,n*m-1){
int a,b;
char c;
scanf("%d %c %d",&a,&c,&b);
if(c=='U'){
g[0][b+1]=a+1;
g[2][a+1]=b+1;
}
else{
g[1][a+1]=b+1;
g[3][b+1]=a+1;
}
}
int s=-1;
FOR1(i,n*m){
int v=0;
if(g[0][i]!=0)v++;
if(g[1][i]!=0)v++;
if(g[2][i]!=0)v++;
if(g[3][i]!=0)v++;
if(v==1){s=i;break;}
}
go(s,-100);
ml=abs(ml);
mu=abs(mu);
//printf("%d %d",ml,mu);
add(s,mu,ml);
FOR(i,n){FOR(j,m)printf("%d ",tab[i][j]-1);printf("\n");}
}
/*
0 1 2
5 4 3
6 7 8

*/
