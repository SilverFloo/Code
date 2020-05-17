#include<bits/stdc++.h>
using namespace std;
char x[300005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",x);
    for(int i=1;i<=m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==0) for(int j=0;j<(n-a-1)/2;j++) swap(x[j+a+1],x[n-1-j]);
        else {
        for(int j=0;j<=(a-1)/2;j++) swap(x[j],x[a-j-1]);
        for(int j=0;j<(n-a-1)/2;j++) swap(x[j+a+1],x[n-1-j]);
        }
    }
    printf("%s",x);
}
