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
int p[1000009];
int part[1000009];
vector<int> ans[1000009];
int main(){
    ans[0].pb(1);
    for(int i=2;i<=1000005;i++){
        if(p[i]!=0){
            part[i]=part[i/p[i]]+1;
            ans[part[i]].pb(i);
            //if(i<100)cout<<i<<' '<<part[i]<<endl;
            continue;
        }
        part[i]=1;
        ans[1].pb(i);
        for(int j=i+i;j<=1000005;j+=i)p[j]=i;
    }
    //cout<<mx;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=30;i>=0;i--){
        int ansa=-INF,ansb=-INF;
        for(auto j:ans[i]){
            if(j<=b&&j<=d){
                if((b/j)*j>=a&&(d/j)*j>=c){
                    int fi=(b/j)*j;
                    int se=(d/j)*j;
                    if(fi+se>ansa+ansb){
                        ansa=fi;
                        ansb=se;
                    }/*
                    else if(fi>ansa){
                        ansa=fi;
                        ansb=se;
                    }*/
                }
            }
        }
    if(ansa!=-INF){printf("%d %d",ansa,ansb);return 0;}
    }
}
