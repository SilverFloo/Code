#include<bits/stdc++.h>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;
set<ii> s;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        s.insert(make_pair(a,b));
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(s.find(make_pair(i,j))!=s.end())continue;
                if(s.find(make_pair(j,k))!=s.end())continue;
                if(s.find(make_pair(i,k))!=s.end())continue;
                cnt++;
            }
        }
    }
    printf("%d",cnt);
}