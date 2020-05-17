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
vector<int> shop[250000];
vector<int> c[250000];
int vals[250000];
int valc[250000];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
        FOR1(i,m){
            int a;
            scanf("%d",&a);
            while(a--){
                int b;
                scanf("%d",&b);
                shop[i].pb(b);
            }
            if(shop[i].size()>=500){
                for(auto b:shop[i]){
                    c[b].pb(i);
                }
            }
        }
    while(q--){
        int t;
        scanf("%d",&t);
        if(t==1){
            int a,b;
            scanf("%d %d",&a,&b);
            if(shop[a].size()<500){
                for(auto i:shop[a])valc[i]+=b-vals[a];
            }
            vals[a]=b;
        }
        else{
            int a;
            scanf("%d",&a);
            int x=valc[a];
            for(auto i:c[a])x+=vals[i];
            printf("%d\n",x);
        }
    }
}
