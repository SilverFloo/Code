#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<(a);i++)

int n,m;int si,sj,ei,ej;
using namespace std;
char in[305][305];
int tab[305][305][4];
bool visit[305][305][4];
queue<int> qi,qj,ql;
void push(int i,int j,int l){
qi.push(i);
qj.push(j);
ql.push(l);
}
void laser (int i,int j,int st,int type){

    if(type==0){
        for(int f=i-1;f>=0&&in[f][j]=='.';f--)tab[f][j][st]=-1;
        for(int f=i+1;f<n&&in[f][j]=='.';f++)tab[f][j][st]=-1;
    }
    if(type==1){
        for(int f=i-1,s=j+1;f>=0&&s<m&&in[f][s]=='.';f--,s++)tab[f][s][st]=-1;
        for(int f=i+1,s=j-1;f<n&&s>=0&&in[f][s]=='.';f++,s--)tab[f][s][st]=-1;
    }
    if(type==2){
        for(int f=j-1;f>=0&&in[i][f]=='.';f--)tab[i][f][st]=-1;
        for(int f=j+1;f<m&&in[i][f]=='.';f++)tab[i][f][st]=-1;
    }
    if(type==3){
        for(int f=i-1,s=j-1;f>=0&&s>=0&&in[f][s]=='.';f--,s--)tab[f][s][st]=-1;
        for(int f=i+1,s=j+1;f<n&&s<m&&in[f][s]=='.';f++,s++)tab[f][s][st]=-1;
    }
}
void intl(){
    FOR(i,n)FOR(j,m){
    int st=0;
    switch(in[i][j]){
    case '|' : st=0; break;
    case '/' : st=1; break;
    case '-' : st=2; break;
    case '\\': st=3; break;
    case '#' :st=-1; break;
    default :st=-2;
    }
    if(st!=-2)for(int k=0;k<4;k++)tab[i][j][k]=-1;
    if(st>=0)for(int k=0;k<4;k++)laser(i,j,k,(st+k)%4);
    }

}
void find(){
    push(si,sj,0);
    while(!qi.empty()){
        int i=qi.front();
        int j=qj.front();
        int l=ql.front();
        qi.pop();
        qj.pop();
        ql.pop();
        if(!visit[i][j][l%4]){
            if(i==ei&j==ej){printf("%d",l);exit(0);}
            visit[i][j][l%4]=1;
            if(i>0){if(!visit[i-1][j][(l+1)%4]&&tab[i-1][j][(l+1)%4]!=-1)push(i-1,j,l+1);}
            if(j>0){if(!visit[i][j-1][(l+1)%4]&&tab[i][j-1][(l+1)%4]!=-1)push(i,j-1,l+1);}
            if(i<n-1){if(!visit[i+1][j][(l+1)%4]&&tab[i+1][j][(l+1)%4]!=-1)push(i+1,j,l+1);}
            if(j<m-1){if(!visit[i][j+1][(l+1)%4]&&tab[i][j+1][(l+1)%4]!=-1)push(i,j+1,l+1);}
        }
    }
}
int main(){
    cin>>n>>m;
    FOR(i,n)FOR(j,m){scanf(" %c",&in[i][j]);
        if(in[i][j]=='S'){si=i;sj=j;}
        if(in[i][j]=='E'){ei=i;ej=j;}
        }
    intl();
    //FOR(x,4){FOR(i,n){FOR(j,m)printf("%2d ",tab[i][j][x]);printf("\n");}printf("\n");}
    find();
    printf("-1");
}
/*
3 3
...
.|.
...
*/
