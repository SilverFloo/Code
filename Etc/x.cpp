#include<bits/stdc++.h>
using namespace std;
int qs[33][33][33][33],dp[33][33][33][33];
int mk[33][33],pos[33][33];
main()
{
	int m,n,q;
    scanf("%d%d%d",&m,&n,&q);
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%d",&pos[i][j]);
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            int ck=-1e9,rmn=1e9,rmx=0,cmn=1e9,cmx=0;
            if(mk[i][j]==0)
            {
                ck=pos[i][j];
                for(int k = 1;k <= m;k++)
                {
                    for(int l = 1;l <= n;l++)
                    {
                        if(ck==pos[k][l])
                        {
                            rmn=min(rmn,k);
                            rmx=max(rmx,k);
                            cmn=min(cmn,l);
                            cmx=max(cmx,l);
                            mk[k][l]=1;
                        }
                    }
                }
				//printf("ck->> %d %d %d %d\n\n",rmn,rmx,cmn,cmx);
                if(rmn==rmx)
                {
                    for(int k = 1;k <= cmn;k++)
                    {
                        for(int l = cmx;l <= n;l++)
						{
							qs[rmn][k][rmx][l]++;
							//printf("--->%d %d %d %d\n",k,cmn,l,cmx);
						}
                        //printf("%d %d %d %d\n",rmn,cmn,rmx,cmx);
                    }
                }
                if(cmn==cmx)
                {
                    for(int k = 1;k <= rmn;k++)
                    {
                        for(int l = rmx;l <= m;l++)
						{
							qs[k][cmn][l][cmx]++;
							//printf("->%d %d %d %d\n",k,cmn,l,cmx);
						}
                    }
                }
				if(rmn==rmx && cmn==cmx)
				qs[rmn][cmn][rmx][cmx]--;
            }
        }
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k+i-1 <= m;k++)
            {
                for(int l = 1;l+j-1 <= n;l++)
                {
                    for(int rr=k;rr<k+i-1;rr++)
                    {
                        dp[k][l][k+i-1][l+j-1]=max(dp[k][l][k+i-1][l+j-1],dp[k][l][rr][l+j-1]+dp[rr+1][l][k+i-1][l+j-1]);
                    }
                    for(int cc=l;cc<l+j-1;cc++)
                    {
                        dp[k][l][k+i-1][l+j-1]=max(dp[k][l][k+i-1][l+j-1],dp[k][l][k+i-1][cc]+dp[k][cc+1][k+i-1][l+j-1]);
                    }
                    if(i>2)
                    {
                        dp[k][l][k+i-1][l+j-1]=max(dp[k][l][k+i-1][l+j-1],dp[k+1][l][k+i-2][l+j-1]+qs[k][l][k][l+j-1]+qs[k+i-1][l][k+i-1][l+j-1]);
                    }
                    if(j>2)
                    dp[k][l][k+i-1][l+j-1]=max(dp[k][l][k+i-1][l+j-1],dp[k][l+1][k+i-1][l+j-2]+qs[k][l][k+i-1][l]+qs[k][l+j-1][k+i-1][l+j-1]);
                    dp[k][l][k+i-1][l+j-1]=max(qs[k][l][k+i-1][l+j-1],dp[k][l][k+i-1][l+j-1]);
					//printf("%d %d %d %d %d\n",k,l,k+i-1,l+j-1,dp[k][l][k+i-1][l+j-1]);
                }
            }
        }
    }
    printf("%d",dp[1][1][m][n]);
}
