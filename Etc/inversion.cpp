#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
long long dat[500005];
vector<long long> merge(int l,int r){
if(l==r) {
vector<long long> x;
x.push_back(dat[l]);
return x;
}
int m=(l+r)/2;
vector<long long> a,b,c;
b=merge(l,m);
c=merge(m+1,r);
int ib=0,ic=0;int bo=b.size();
while(ib!=b.size()&&ic!=c.size()){
if(b[ib]<=c[ic]){a.push_back(b[ib]);ib++;bo--;}
else {a.push_back(c[ic]);ic++;ans+=bo;}
}
while(ib!=b.size()){a.push_back(b[ib]);ib++;}
while(ic!=c.size()){a.push_back(c[ic]);ic++;}
return a;
}
int main(){
int n;
scanf("%d",&n);
while(n!=0){

for(int i=0;i<n;i++){scanf("%lld",&dat[i]);}
vector<long long> answer = merge(0,n-1);
printf("%llu\n",ans);
ans=0;
scanf("%d",&n);
}

}
