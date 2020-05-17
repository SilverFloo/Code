#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
int tab[105][10005];
int main(){
for(int i=0;i<=100;i++){
int val=i*i;
for(int j=0;j<=10000;j++){

if(j==0)tab[i][j]=0;
else if(i==0)tab[i][j]=INF;
else if(j-val<0)tab[i][j]=tab[i-1][j];
else tab[i][j]=min(tab[i-1][j],tab[i][j-val]+1);
}
}
int n;
scanf("%d",&n);
while(n--){
int t=0;
scanf("%d",&t);
printf("%d",tab[100][t]);
}

}
