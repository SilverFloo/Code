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
int tab[105][105];
int main(){
    int t;
    cin>>t;
    FOR1(k,t){
        int n,m;
        cin>>n>>m;
        FOR(i,n){
            FOR(j,m)cin>>tab[i][j];
        }
        ll ans=0;
        int x=1;
        while(x!=0){
            x=0;
        stack<ii> s;
            FOR(i,n){
                FOR(j,m){
                   // printf("%d ",tab[i][j]);
                    if(tab[i][j]==0)continue;
                ans+=(ll)tab[i][j];
                int sum=0;
                int cnt=0;
                    for(int k=i-1;k>=0;k--){
                        if(tab[k][j]!=0){sum+=tab[k][j],cnt++;break;}
                    }
                    for(int k=i+1;k<n;k++){
                        if(tab[k][j]!=0){sum+=tab[k][j],cnt++;break;}
                    }
                    for(int k=j-1;k>=0;k--){
                        if(tab[i][k]!=0){sum+=tab[i][k],cnt++;break;}
                    }
                    for(int k=j+1;k<m;k++){
                        if(tab[i][k]!=0){sum+=tab[i][k],cnt++;break;}
                    }
                    if((double)tab[i][j]<(double)sum/(double)cnt){
                        s.p(i,j);x++;
                    }
                }//cout<<endl;
            }
            while(!s.empty()){
                tab[s.top().f][s.top().s]=0;
                s.pop();
            }

        }
        printf("Case #%d: %lld\n",k,ans);
    }
}
