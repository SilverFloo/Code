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
#define rf() freopen("input.txt","r",stdin)
using namespace std;
const int INF=1e9;
vector<int> d[10005],r[10005];
int state[10005];
int main(){
    int n,m,x;
    cin>>n>>m>>x;
    FOR(i,x){
        int a,b;
        scanf("%d %d",&a,&b);
        r[a].pb(b);
        d[b].pb(a);
    }
    int mm=0,mn=0;
    for(int i=n;i>0;i--){
        if(r[i].size()==m)mm++;
        else break;
    }
    for(int i=m;i>0;i--){
        if(d[i].size()==n)mn++;
        else break;
    }
    n-=mn;
    m-=mn;
    for(int i=1;i<=n;i++){
        int x=0,y=0;
        if(find(all(r[i]),1)==r[i].end())x=1;
        if(find(all(r[i]),n)==r[i].end())y=1;
        if(r[i].size()-mm==0)state[i]=3;
        else if(x==1&&y==1&&r[i].size()-mm+2==m)state[i]=0;
        else if(x==1&&r[i].size()-mm+1==m)state[i]=1;
        else if(y==1&&r[i].size()-mm+1==m)state[i]=2;
        else state[i]=-1;
    }

    if(n==1){
        if(state[1]==3||state[1]==1){printf("Yes");return 0;}
        printf("No");return 0;
    }
    if(n==2){
        if(state[1]==3&&state[2]==2&&mn==0){printf("Yes");return 0;}
        if(state[1]==3&&state[2]==3){printf("Yes");return 0;}
        if(state[1]==1&&state[2]==1){printf("Yes");return 0;}
         printf("No");return 0;
    }

    int st=state[2];
    for(int i=2;i<n;i++){
        if(state[i]!=st){printf("No");return 0;}
    }
    if(state[1]==3&&st==0&&state[n]==3){printf("Yes");return 0;}
    if(state[1]==3&&st==2&&(state[n]==3||(state[n]==2&&mn==0))){printf("Yes");return 0;}
    if(state[1]==1&&st==1&&(state[n]==1||state[n]==3)){printf("Yes");return 0;}
    printf("No");

}
