#include<bits/stdc++.h>
using namespace std;
int t[20];
main(){
int mlie=300;
int n=3,q=3;
scanf("%d %d",&n,&q);
int ans[n][q];
for(int i=0;i<n;i++){
for(int j=0;j<q;j++){scanf(" %d",&ans[i][j]);}
}

while(t[q]!=1){
int lie=0,j;
for(int i=0;i<n;i++){
for(j=0;j<q;j++){
if(ans[i][j]!=0&&ans[i][j]!=(t[j]?1:-1))break;
}
if(j!=q)lie++;
}
if(lie<mlie)mlie=lie;
t[0]++;
int i=0;
while(t[i]==2){if(t[i]){t[i]=0;t[i+1]++;i++;}}
}
printf("%d",mlie);
}
