#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
using namespace std;
int tab[26][26];
int deg[26];
int x;
void go(int u){
x=u;
printf("%c ",u+'A');
int ch=-1;
FOR(i,26){
if(tab[u][i]&&deg[i]==1)ch=i;
if(tab[u][i]>0&&deg[i]>1){
deg[i]--;
deg[u]--;
tab[u][i]--;
tab[i][u]--;
go(i);
return;
}
}
if(ch!=-1){
deg[u]--;
deg[ch]--;
tab[ch][u]--;
tab[u][ch]--;
go(ch);}
}
int main(){
int n;
scanf(" %d ",&n);

FOR(i,n){
char a,b;
cin>>a>>b;
tab[a-'A'][b-'A']++;
tab[b-'A'][a-'A']++;
deg[a-'A']++;
deg[b-'A']++;
}
int s=0;
FOR(i,26){
if(deg[i]%2){s=i;break;}
}
go(s);/*
FOR(i,26){
if(deg[i]&&i!=x){printf("%c",i+'A');break;}
}*/
}
