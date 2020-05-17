#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> di;
typedef pair<int,di> tt;
vector<int> dp[2000005];
vector<int> num[2000005];
int main()
{
    int r,c,k,a;
    scanf("%d%d%d",&r,&c,&k);
    for(int i=1;i<=r;i++)
    {
        num[i].push_back(-2e9);
        dp[i].push_back(-2e9);
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&a);
            num[i].push_back(a);
            dp[i].push_back(-2e9);
        }
    }
    priority_queue<tt> q;
    int ans=0;
    for(int i=1;i<=c;i++) q.emplace(num[1][i],mp(mp(1,i),mp(0,0)));
    while(!q.empty())
    {
        tt tp=q.top();
        q.pop();
        int val=tp.x;
        int rr=tp.y.x.x,cc=tp.y.x.y;
        int how=tp.y.y.x,di=tp.y.y.y;
        //printf("%d %d %d\n",rr,cc,val);
        //if(dp[rr][cc]>val) continue;
        ans=max(ans,val); dp[rr][cc]=max(val,dp[rr][cc]);
        if(di==1){
            if(how<k&&cc>1) q.emplace(val+num[rr][cc-1],mp(mp(rr,cc-1),mp(how+1,1)));
            if(rr<r) q.emplace(val+num[rr+1][cc],mp(mp(rr+1,cc),mp(0,0)));
        }
        else if(di==2) {
            if(how<k&&cc<c) q.emplace(val+num[rr][cc+1],mp(mp(rr,cc+1),mp(how+1,2)));
            if(rr<r) q.emplace(val+num[rr+1][cc],mp(mp(rr+1,cc),mp(0,0)));
        }
        else if(di==0){
            if(cc>1) q.emplace(val+num[rr][cc-1],mp(mp(rr,cc-1),mp(how+1,1)));
            if(cc<c) q.emplace(val+num[rr][cc+1],mp(mp(rr,cc+1),mp(how+1,2)));
            if(rr<r) q.emplace(val+num[rr+1][cc],mp(mp(rr+1,cc),mp(0,0)));
        }
    }
    printf("%d",ans);
}
