#include<bits/stdc++.h>
#define _1 first
#define _2 second
using namespace std;
main(){
vector<pair<int,int> > M;
int n,x,y,mx=0,my=0;
cin>>n;
for(int i=0;i<n;i++){cin>>x>>y;M.push_back(make_pair(x-1,y));if(x-1+2*y>mx)mx=x-1+2*y;if(y>my)my=y;}
char tab[my][mx];
for(int i=0;i<my;i++){
for(int j=0;j<mx;j++){tab[i][j]='.';}}
for(int k=0;k<n;k++){
for(int i=0;i<M[k]._2;i++){
if(tab[my-i-1][M[k]._1+i]=='\\')tab[my-i-1][M[k]._1+i]='v';
else
tab[my-i-1][M[k]._1+i]='/';
if(tab[my-i-1][M[k]._1+2*M[k]._2-i-1]=='/')tab[my-i-1][M[k]._1+2*M[k]._2-i-1]='v';
else
tab[my-i-1][M[k]._1+2*M[k]._2-i-1]='\\';
}
for(int i=0;i<my;i++){
    int x=0;
for(int j=0;j<mx;j++){
       if(tab[i][j]=='/')x++;
    if(tab[i][j]=='\\')x--;
    if(x>1&&tab[i][j]!='v')tab[i][j]='X';
    if(x==1&&tab[i][j]!='/'&&tab[i][j]!='v')tab[i][j]='X';
    }

}
}
for(int i=0;i<my;i++){
for(int j=0;j<mx;j++){printf("%c",tab[i][j]);}printf("\n");}
}


