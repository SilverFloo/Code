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
bool visit[60005];
int main(){
    int n;
    cin>>n;
    visit[0]=1;
    FOR(i,n){
        int x;
        queue<int> q;
        scanf("%d", &x);
        FOR(i,60000){
            if(visit[i]){
                int val=i<=30000?i:-(i-30000);
                val += x;
                if(val>30000)val-=60001;
                if(val<-30000)val+=60001;
               // printf("%d\n",val);
                if(val<0)val=-val+30000;
                q.p(val);
            }
        }
        while(!q.empty()){visit[q.front()]=1;q.pop();}
    }
    for(int i = 30000; i >= 0; i--) if(visit[i]) {printf("%d",i); break; }
}
