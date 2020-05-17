#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
using namespace std;
int tab[105][105];
int ch[105];
int main(){
    int t;
    cin>>t;
    FOR(k,t){
        int n;
        cin>>n;
        int sum=0;
        FOR(i,n){
            FOR(j,n){
                scanf("%d",&tab[i][j]);
                if(i==j)sum+=tab[i][j];
            }
        }



        int r=0,c=0,x=0;

        FOR(i,n){
            FOR(j,n){
                if(ch[tab[i][j]]==1){
                    x=1;
                }
                else ch[tab[i][j]]=1;
            }
            if(x==1)r++;
            x=0;
            FOR1(j,n)ch[j]=0;
        }

        FOR(j,n){
            FOR(i,n){
                if(ch[tab[i][j]]==1){
                    x=1;
                }
                else ch[tab[i][j]]=1;
            }
            if(x==1)c++;
            x=0;
            FOR1(i,n)ch[i]=0;
        }
        printf("Case #%d: %d %d %d\n",k+1,sum,r,c);
    }
}
