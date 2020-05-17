#include<bits/stdc++.h>
using namespace std;
int tab[1001][1001];
main(){
int n,m;
scanf("%d %d",&n,&m);
int a,b;
for(int i=0;i<n;i++){scanf("%d %d",&a,&b);tab[a][b]=1;}
for(int i=0;i<m;i++){
int ai,aj,r;int co=0;
scanf("%d %d %d",&ai,&aj,&r);
for(int j=ai-r<0?0:ai-r;j<=ai+r&&j<=1000;j++){
for(int k=aj-r<0?0:aj-r;k<=aj+r&&k<=1000;k++){
if(tab[j][k]==1){
co++;tab[j][k]=0;
}
}
}
printf("%d\n",co);
}
}
