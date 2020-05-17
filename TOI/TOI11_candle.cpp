#include<bits/stdc++.h>
using namespace std;
bool tab[2005][2005];
#define f q.emplace

queue<pair<int,int>> q;



void find(int i,int j){
q.emplace(i,j);
while(!q.empty()){
i=q.front().first;
j=q.front().second;
q.pop();
tab[i][j]=0;
if(tab[i+1][j]){tab[i+1][j]=0;f(i+1,j);}
if(tab[i-1][j]){tab[i-1][j]=0;f(i-1,j);}
if(tab[i][j-1]){tab[i][j-1]=0;f(i,j-1);}
if(tab[i][j+1]){tab[i][j+1]=0;f(i,j+1);}
if(tab[i+1][j+1]){tab[i+1][j+1]=0;f(i+1,j+1);}
if(tab[i+1][j-1]){tab[i+1][j-1]=0;f(i+1,j-1);}
if(tab[i-1][j+1]){tab[i-1][j+1]=0;f(i-1,j+1);}
if(tab[i-1][j-1]){tab[i-1][j-1]=0;f(i-1,j-1);}
}

}


int main(){
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
scanf("%1d",&tab[i][j]);
}
}
int c=0;
for(int i=1;i<=n;i++){
for(int j=1;j<=m;j++){
if(tab[i][j]){c++;find(i,j);}
}
}
printf("%d",c);
}
