#include<bits/stdc++.h>
using namespace std;
int tab[1005][1005];
int main(){
int n,m;
int t=2;
while(t--){
cin>>n>>m;
int q;
cin>>q;
while(q--){
int a,b;
scanf("%d %d",&a,&b);
tab[a+1][b+1]=1;
}
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
tab[i][j]+=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
}
}
int mx=0;
int ch=0;
for(int k=min(n,m);k>=1;k--){
for(int i=k;i<=n;i++){
for(int j=k;j<=m;j++){
int aa=tab[i][j]-tab[i][j-k]-tab[i-k][j]+tab[i-k][j-k];
int bb=tab[i-1][j-1]-tab[i-1][j-k+1]-tab[i-k+1][j-1]+tab[i-k+1][j-k+1];
if(aa-bb==0){printf("%d\n",k);ch=1;break;
}

}
if(ch)break;
}
if(ch)break;
}
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
tab[i][j]=0;
}
}

}
}
/*
4 4
4
1 1
1 2
2 1
2 2*/
