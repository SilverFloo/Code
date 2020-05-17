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
int pre[105],in[105];
int dp[105][105];
ll mod=1e9+7;
 int n;
ll find(int pst,int ped,int ist,int ied){
    if(pst<0||ped>=n||ist<0||ied>=n)return 1;
    if(pst>=ped||ist>=ied)return 1;
    if(dp[ist][ied]!=0)return dp[ist][ied];
    int inh=0;
    // printf(m"%d %d/",st,ed);
    for(int i=ist;i<=ied;i++){
        if(in[i]==pre[pst]){inh=i;break;}
    }
    ll left=0;
    left=find(ist,inh-1,pst+1,pst-ist+inh);
    int cr=0;/*
    for(int i=inh+1;i<=ed;i++){
        if(in[i]==pre[inh+1]){cr=i;break;}
    }*/
    ll right=1;
    if(inh<ied){
    right=(2*find(inh+1,ied,pst+inh-ist+1,ped))%mod;/*
   //printf("call : %d %d ,%d %d",inh+1,cr+1,cr+1,ed);

        for(int i=inh+1;i<=ed;i++){
            if(in[i]==pre[inh+1]){cr=i;
                if(ed-cr>1){right+=find(inh+1,cr+1)*find(cr+1,ed),right%=mod;break;}
            }
        }
        for(int i=cr+1;i<ed;i++){
            if(in[i]==pre[i])right+=find(inh+1,i+1)*find(i+1,ed),right%=mod;
        }
    right%=mod;
    */
    }
   // printf("..%d %d->%d..",st,ed,left*right);
   dp[ist][ied]=(left*right)%mod;
    return (left*right)%mod;
}
int main(){

    cin>>n;
    FOR(i,n)scanf("%d",&pre[i]);
    FOR(i,n)scanf("%d",&in[i]);
    printf("%lld",find(0,n-1,0,n-1));
}

