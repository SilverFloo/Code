#include<bits/stdc++.h>
using namespace std;
int tab[260][260];
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){for(int j=0;j<n;j++)scanf("%d",&tab[i][j]);}
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
for(int k=0;k<n;k++){
tab[i][j]=min(tab[i][k]+tab[k][j],tab[i][j]);
}
}
}
int q;
scanf("%d",&q);
while(q--){
int a,b,c;
scanf("%d %d %d",&a,&b,&c);
printf("%d %d\n",tab[a][b]+tab[b][c],tab[a][b]+tab[b][c]-tab[a][c]);
}

}
