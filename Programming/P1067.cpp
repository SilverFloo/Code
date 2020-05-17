#include<bits/stdc++.h>
using namespace std;
main(){
int n,m,k;
scanf("%d %d %d",&n,&m,&k);
int tab[m][n];
bool status[m][n];
for(int i=0;i<m;i++){
for(int j=0;j<n;j++)scanf("%d",&tab[i][j]);
}
while(k--){
for(int i=0;i<m;i++){
for(int j=0;j<n;j++)status[i][j]=0;
}
int i,j;
scanf("%d %d",&j,&i);i--;j--;

while(i<m&&i>=0&&j<n&&j>=0&&status[i][j]==0){
status[i][j]=1;
switch(tab[i][j]){
case 1:i--;break;
case 2:j++;break;
case 3:i++;break;
case 4:j--;break;
}
}

if(i<0)printf("N\n");
else if(j<0)printf("W\n");
else if(i>=m)printf("S\n");
else if(j>=n)printf("E\n");
else if(status[i][j])printf("NO\n");
}




}
