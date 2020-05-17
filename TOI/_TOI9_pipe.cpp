#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)
using namespace std;
const int MAX = 305;
int tab[MAX][MAX];
int n,m;
vector<int> ans;
void go(int i,int j,int l,int f){
if(i<0||j<0||i>=n||j>=m){ans.push_back(l);

//FOR(i,n){FOR(j,m)printf("%d",tab[i][j]);printf("\n");}

return;}
if(tab[i][j]==11){
    if(f==1)go(i,j-1,l+1,2);
    else if(f==4) go(i-1,j,l+1,3);
}
else if(tab[i][j]==12){
    if(f==1)go(i,j+1,l+1,4);
    else if(f==2)go(i-1,j,l+1,3);
}
else if(tab[i][j]==13){
    if(f==3)go(i,j-1,l+1,2);
    else if(f==4)go(i+1,j,l+1,1);
}
else if(tab[i][j]==14){
    if(f==3)go(i,j+1,l+1,4);
    else if(f==2)go(i+1,j,l+1,1);
}
else if(tab[i][j]==21){
    if(f==1)go(i+1,j,l+1,1);
    else if(f==3)go(i-1,j,l+1,3);
}
else if(tab[i][j]==22){
    if(f==4)go(i,j+1,l+1,4);
    else if(f==2)go(i,j-1,l+1,2);
}
else if(tab[i][j]==31){
    if(f==1)go(i+1,j,l+1,1);
    else if(f==3) go(i-1,j,l+1,3);
    else if(f==4)go(i,j+1,l+1,4);
    else if(f==2)go(i,j-1,l+1,2);
}
if(tab[i][j]==31){
if(f==1||f==3)tab[i][j]=22;
else tab[i][j]=21;
}
else tab[i][j]=0;
}
int main(){

scanf("%d %d",&n,&m);
FOR(i,n){
FOR(j,m)scanf("%d",&tab[i][j]);
}
FOR(j,m){
if(tab[0][j]==11||tab[0][j]==12||tab[0][j]==21||tab[0][j]==31){go(0,j,0,1);}
if(tab[n-1][j]==13||tab[n-1][j]==14||tab[n-1][j]==21||tab[n-1][j]==31){go(n-1,j,0,3);}
}

FOR(i,n){
if(tab[i][0]==11||tab[i][0]==13||tab[i][0]==22||tab[i][0]==31){go(i,0,0,4);}
if(tab[i][m-1]==12||tab[i][m-1]==14||tab[i][m-1]==22||tab[i][m-1]==31){go(i,0,0,2);}
}

printf("%d\n",ans.size());
for(auto i:ans){printf("%d ",i);}
}
