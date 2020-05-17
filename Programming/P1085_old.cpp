#include<bits/stdc++.h>
bool reached[500005];
using namespace std;
main(){
int n,m,k;
scanf("%d %d %d",&n,&m,&k);
vector<int> warp[n];
for(int i=0;i<m;i++){
int a,b;
scanf("%d %d",&a,&b);
warp[a-1].push_back(b-1);
}
bool rock[n];
reached[0]=1;
for(int i=0;i<k;i++){int a;scanf("%d",&a);rock[a-1]=1;}
for(int i=0;i<n;i++){
    if(reached[i]){
if(!rock[i])reached[i+1]=1;
for(int j=0;j<warp[i].size();j++){reached[warp[i][j]]=1;}}
}
int x=n;
if(reached[n-1])printf("1");
else {printf("0");
for(int i=n-2;i>=0;i--){if(reached[i]){printf(" %d",i+1);break;}}
}

}

