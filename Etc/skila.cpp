#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;int x,y;
scanf("%d %d",&n,&m);
int tab[n][m];
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
char a;

scanf(" %c",&a);
if(a=='X')tab[i][j]=-1;
if(a=='*')tab[i][j]=-2;
if(a=='.')tab[i][j]=0;
if(a=='S')tab[i][j]=2;
if(a=='D'){tab[i][j]=1;x=i;y=j;}
//printf("%d %d",i,j);
}
}
int cc=0;
if(x<n-1)if(tab[x+1][y]==2)cc=1;
if(y<m-1)if(tab[x][y+1]==2)cc=1;
if(x>0)if(tab[x-1][y]==2)cc=1;
if(y>0)if(tab[x][y-1]==2)cc=1;
if(cc){printf("1");exit(0);}
int k=2;
int ch=1;
while(ch){
    ch=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(tab[i][j]!=-1&&tab[i][j]!=0){
if(i>0){
if(tab[i][j]==-k){if(fabs(tab[i-1][j]!=1)&&tab[i-1][j]>=0)tab[i-1][j]=tab[i][j]-1;}
if(tab[i][j]==k){if(tab[i-1][j]>=0&&(tab[i-1][j]<tab[i][j]||tab[i+1][j]==1)){tab[i-1][j]=tab[i][j]+1;ch=1;}}
}
if(i<n-1){
if(tab[i][j]==-k){if(fabs(tab[i+1][j]!=1)&&tab[i+1][j]>=0)tab[i+1][j]=tab[i][j]-1;}
if(tab[i][j]==k){if(tab[i+1][j]>=0&&(tab[i+1][j]<tab[i][j]||tab[i+1][j]==1)){tab[i+1][j]=tab[i][j]+1;ch=1;}}
}
if(j>0){
if(tab[i][j]==-k){if(fabs(tab[i][j-1]!=1)&&tab[i][j-1]>=0)tab[i][j-1]=tab[i][j]-1;}
if(tab[i][j]==k){if(tab[i][j-1]>=0&&(tab[i][j-1]<tab[i][j]||tab[i][j-1]==1)){tab[i][j-1]=tab[i][j]+1;ch=1;}}
}
if(j<m-1){
if(tab[i][j]==-k){if(fabs(tab[i][j+1]!=1)&&tab[i][j+1]>=0)tab[i][j+1]=tab[i][j]-1;}
if(tab[i][j]==k){if(tab[i][j+1]>=0&&(tab[i][j+1]<tab[i][j]||tab[i][j+1]==1)){tab[i][j+1]=tab[i][j]+1;ch=1;}}
}
}
}
}k++;

if(tab[x][y]!=1){printf("%d",tab[x][y]-2);exit(0);}
}

printf("KAKTUS");
}
