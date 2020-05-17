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
vector<int> pr;
bool win[500005];
bool prime[500005];
int main(){
    FILE *f=fopen("primegame.txt","w");
    prime[0]=1;
    prime[1]=1;
    prime[2]=0;
    for(int i=2;i<=500000;i++){
            if(prime[i]==0){
                    pr.pb(i);
        for(int j=i+i;j<=500000;j+=i)prime[j]=1;
            }
    }
    int prs=pr.size();
    win[0]=1;
    win[1]=0;
    for(int i=2;i<=500000;i++){
    vector<int> x;
        for(int j=0;j<prs&&pr[j]<i;j++)if(i%pr[j]==0)x.pb(pr[j]);

        if(x.size()==0)win[i]=0;
        else{
            int sum=0;
            for(auto j:x){sum+=j;}
            for(auto j:x){if(win[sum-j]==0)win[i]=1;}
        }
        fprintf(f,"%d,",win[i]);
    }



}
