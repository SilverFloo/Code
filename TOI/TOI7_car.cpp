#include<bits/stdc++.h>
using namespace std;
bool visit[200][200];
int main(){
int n,m,s;
cin>>m>>s>>n;s--;
int tab[200][200];
for(int i=1;i<=n;i++)for(int j=0;j<m;j++){scanf("%d",&tab[i][j]);}

for(int j=0;j<m;j++)tab[0][j]=0;
visit[0][s]=1;

for(int i=1;i<=n;i++){
for(int j=0;j<m;j++){
if(tab[i][j]==0){
if(j!=0)if(visit[i-1][j-1])visit[i][j]=1;
if(j!=n-1)if(visit[i-1][j+1])visit[i][j]=1;
if(visit[i-1][j]||visit[i-1][j+1]||visit[i-1][j-1])visit[i][j]=1;

}
}
}
//for(int i=0;i<=n;i++){for(int j=0;j<m;j++){printf("%d",visit[i][j]);}printf("\n");}

int j;stack<int> ans;
for(int i=0;i<m;i++)if(visit[n][i])j=i;
int i=n;
while(i>0){
int ch=0;
if(j!=0)if(visit[i-1][j-1]){ans.push(2);j--;ch=1;}
if(j!=m&&ch==0)if(visit[i-1][j+1]){ans.push(1);j++;ch=1;}
if(visit[i-1][j]&&ch==0){ans.push(3);}
i--;//printf("%d",i);
}
while(!ans.empty()){printf("%d\n",ans.top());ans.pop();}
}
