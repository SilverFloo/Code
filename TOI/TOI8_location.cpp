#include<bits/stdc++.h>
using namespace std;
int tab[1005][1005];
int main(){
int n,m,k;
cin>>n>>m>>k;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){scanf("%d",&tab[i][j]);
tab[i][j]+=tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
}
}
int mx=0;
for(int i=k;i<=n;i++){
for(int j=k;j<=m;j++){
int aa=tab[i][j]-tab[i][j-k]-tab[i-k][j]+tab[i-k][j-k];
if(aa>mx)mx=aa;
}
}
printf("%d",mx);


}
