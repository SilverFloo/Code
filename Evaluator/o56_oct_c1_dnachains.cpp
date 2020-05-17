#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
using namespace std;
const int INF=1e9;
int con[2][100005];
int sw[100005];
int main(){
    int l,n;
    cin>>l>>n;
    int cnt=1;
    FOR(i,l){
        int x;
        scanf("%d",&x);
        if(x==1){cnt++;continue;}
        con[1][cnt]=cnt+1;
        cnt++;
        //printf("%d",cnt);
        for(;x>2;x--,cnt++){
            con[0][cnt]=cnt-1;
            con[1][cnt]=cnt+1;
        }
        con[0][cnt]=cnt-1;
        cnt++;
       // printf("%d/",cnt);
    }
   //printf("<%d>",con[0][4]);
    int pos=1;
    int st=0;
    FOR(i,n){
        char c;
       // printf("/%d",st);
        scanf(" %c",&c);
        if(c=='F'){
            if(con[!st][pos]){
                pos=con[!st][pos];
                if(sw[pos]==1)st=!st;
            }
        }
        else if(c=='B'){
            if(sw[pos]==1&&con[st][pos]){
                    st=!st;
                pos=con[!st][pos];
            }
            else if(con[st][pos]){
               // if(sw[pos]==1)st=!st;
               //printf("in");
                pos=con[st][pos];
            }
        }
        else{
            int x;
            scanf("%d",&x);
            if(con[0][x]==0){
                if(con[st][con[!st][pos]]==pos)con[st][con[!st][pos]]=0;
                else con[!st][con[!st][pos]]=0;
                sw[con[!st][pos]]=0;
                con[!st][pos]=x;
                con[0][x]=pos;
                pos=x;
                if(st){
                sw[x]=!sw[x];
                st=!st;}
            }
            else{
                   // printf("in");
                if(con[st][con[!st][pos]]==pos)con[st][con[!st][pos]]=0;
                else con[!st][con[!st][pos]]=0;
                sw[con[!st][pos]]=0;
                con[!st][pos]=x;
                con[1][x]=pos;

                pos=x;
                if(!st){
                sw[x]=!sw[x];
                st=!st;

                }
            }
        }
         printf("%d<-(%d)->%d ",con[st][pos],pos,con[!st][pos]);
       // printf("%d\n",pos);


    }
}
/*
4 1000
3
4
2
5
B
F
C 9
C 4
F
B
F
C 3
F
C 14 */

