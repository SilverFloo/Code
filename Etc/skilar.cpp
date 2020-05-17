#include<bits/stdc++.h>
using namespace std;
char tab[500][500];

int m,n;
queue<int> wi,wj;
queue<int> qi,qj,qa;
int flow(int w){    int co=0;
while(w--){

int i=wi.front();wi.pop();
int j=wj.front();wj.pop();
if(i>0){if(tab[i-1][j]=='.'){tab[i-1][j]='*';wi.push(i-1);wj.push(j);co++;}}
if(i<n-1){if(tab[i+1][j]=='.'){tab[i+1][j]='*';wi.push(i+1);wj.push(j);co++;}}
if(j>0){if(tab[i][j-1]=='.'){tab[i][j-1]='*';wi.push(i);wj.push(j-1);co++;}}
if(j<m-1){if(tab[i][j+1]=='.'){tab[i][j+1]='*';wi.push(i);wj.push(j+1);co++;}}
}
return co;
}
int main(){
int water=0;

scanf("%d %d",&n,&m);
for(int i=0;i<n;i++){scanf("%s",tab[i]);}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(tab[i][j]=='*'){wi.push(i);wj.push(j);water++;}
if(tab[i][j]=='S'){qi.push(i);qj.push(j);qa.push(0);}}
}
int t=-1;
while(!qi.empty()){
int i=qi.front();qi.pop();
int j=qj.front();qj.pop();
int a=qa.front();qa.pop();
//printf("%d %d",i,j);
if(t!=a){water=flow(water);t++;}
if(i>0){if(tab[i-1][j]=='.'){qi.push(i-1);qj.push(j);qa.push(a+1);}}
if(i<n-1){if(tab[i+1][j]=='.'){qi.push(i+1);qj.push(j);qa.push(a+1);}}
if(j>0){if(tab[i][j-1]=='.'){qi.push(i);qj.push(j-1);qa.push(a+1);}}
if(j<m-1){if(tab[i][j+1]=='.'){qi.push(i);qj.push(j+1);qa.push(a+1);}}

if(i>0){if(tab[i-1][j]=='D'){printf("%d",a+1);exit(0);}}
if(i<n-1){if(tab[i+1][j]=='D'){printf("%d",a+1);exit(0);}}
if(j>0){if(tab[i][j-1]=='D'){printf("%d",a+1);exit(0);}}
if(j<m-1){if(tab[i][j+1]=='D'){printf("%d",a+1);exit(0);}}

}
printf("KAKTUS");
}
