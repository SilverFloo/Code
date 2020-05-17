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
using namespace std;
const int INF=1e9;
const int MAX=10005;
int t[MAX][MAX];
void update(int a,int b){
    if(a<1)a=1;
    if(b>=MAX)b=MAX-1;
    for(int i=a;i<MAX;i+=i&-i){
        for(int j=b;j<MAX;j+=j&-j)t[i][j]++;
    }
}

int query(int a,int b){
    if(a<1)a=1;
    if(b>=MAX)b=MAX-1;
    int sum=0;
    for(int i=a;i>0;i-=i&-i){
        for(int j=b;j>0;j-=j&-j)sum+=t[i][j];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    FOR(i,n){
        int p,h;
        scanf("%d %d",&p,&h);
        h--;
        printf("%d\n",query(p-h+5001,MAX-1)-query(p-h+5001,p+h-1));
        update(p-h+5001,p+h);
    }
}
