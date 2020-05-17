#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
map<int,int> ma;
int main() {
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){
    int a;
    scanf("%d",&a);
    if(ma.find(a)==ma.end())ma[a]=1;
    else ma[a]++;
}
int f;
if(ma.begin()->y!=next(ma.begin())->y)f=next(next(ma.begin()))->y;
else f=ma.begin()->y;

for (auto i: ma){
  if(i.y!=f){printf("%d",i.x);exit(0);}
}

}
