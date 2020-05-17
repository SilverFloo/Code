#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
if(a%b==0)return b;
return gcd(b,a%b);
}
queue<int> q;
int main(){
int t;
scanf("%d",&t);
while(t--){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++){int a;scanf("%d",&a);q.push(a);}
while(q.size()!=1){
    int a=q.front();q.pop();
    int b=q.front();q.pop();
q.push(gcd(a,b));
}
printf("%d\n",q.front()==1?-1:q.front());
}

}
