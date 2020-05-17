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
bool x[100005];
ii y[100005];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&y[i].f);
        y[i].s=i;
    }
    sort(y,y+n,greater<ii>());
    int pos=0;
    for(int i=0;i<m;i++){
        int h;
        scanf("%d",&h);
        queue<int> q;
        int cnt=0;
        while(pos<n&&y[pos].f>h){
            if(x[y[pos].s]==0){x[y[pos].s]=1;cnt++;
            q.p(y[pos].s-1);
            q.p(y[pos].s+1);
            }
            pos++;
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            if(a<0||a>=n)continue;
            if(x[a]==0)x[a]=1,cnt++;
        }
        printf("%d\n",cnt);
    }
}
