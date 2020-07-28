#include<bits/stdc++.h>
#define FOR(i,a) for(int i=0;i<a;i++)
#define FOR1(i,a) for(int i=1;i<=a;i++)
#define db(a) printf("<%d> ",a)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb emplace_back
#define p emplace
#define ii pair<int,int>
#define ll long long
#define rf() freopen("_working/input.in","r",stdin)
#define pf() freopen("_working/output.out","w+",stdout)
using namespace std;
const int INF=1e9;
int st[5005];
int sw[5005];
int fix[5005];
int tryCombination(int S[]);
void exploreCave(int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!fix[j])st[j]=1;
        }
        int x = tryCombination(st);
        if(x==i)x=0;
        else x=1;
        int l=0,r=N-1;
        while(l<r){
            //printf("%d %d\n",l,r);
            int m = (l+r)/2;
            for(int j=0;j<N;j++){
                if(!fix[j])st[j]=!x;
            }
            for(int j=l;j<=m;j++){
                if(!fix[j])st[j]=x;
            }
            int a = tryCombination(st);
            if(a!=i){r=m;}
            else l=m+1;
        }
        sw[l]=i;
        st[l]=x;
        fix[l]=1;
    }
    for(int i=0;i<N;i++)printf("%d ",st[i]);
    cout<<endl;
    for(int i=0;i<N;i++)printf("%d ",sw[i]);
    //answer(st,sw);
}
int tryCombination(int S[]){
    int st[] = {1,1,0,1,0,0,0};
    int sw[] = {3,6,4,1,5,0,2};
    int ans=INF;
    for(int i=0;i<7;i++){
        if(S[i]!=st[i])ans=min(ans,sw[i]);
    }
    if(ans==INF)ans=-1;
    return ans;
}
int main(){
    exploreCave(7);
}