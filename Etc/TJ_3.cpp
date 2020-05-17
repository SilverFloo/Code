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
const int INF=2e9;
int x[2000005];
int ans[2][200005];
int note[2000005];
int main(){
    int rans=0;
    int n,m,k;
    cin>>n>>m>>k;
    int bf=0,now=1;
    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++)scanf("%d",&x[j]);
        for(int j=0;j<m;j++)ans[now][j]=-INF;
        deque<int> q;
        int tmp=0;
        for(int j=0;j<m;j++){
            note[j]=ans[bf][j]-tmp;
            tmp+=x[j];
            while(!q.empty()&&note[q.back()]<note[j])q.pop_back();
            q.pb(j);
            while(!q.empty()&&q.front()<j-k)q.pop_front();
            ans[now][j]=max(ans[now][j],note[q.front()]+tmp);
        }
        while(!q.empty())q.pop_back();
        tmp=0;

        for(int j=m-1;j>=0;j--){
            note[j]=ans[bf][j]-tmp;
            tmp+=x[j];
            while(!q.empty()&&note[q.back()]<note[j])q.pop_back();
            q.pb(j);
            while(!q.empty()&&q.front()>j+k)q.pop_front();
            ans[now][j]=max(ans[now][j],note[q.front()]+tmp);
        }
        for(int j=0;j<m;j++)rans=max(rans,ans[now][j]);
        swap(bf,now);

    }


    printf("%d",rans);
}
