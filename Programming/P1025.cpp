#include<bits/stdc++.h>
using namespace std;

int gcd(int u, int v) {
return (v != 0)?gcd(v, u%v):u;
}

int lcm(int m, int n){
return m / gcd(m, n) * n;
}

main(){
int n;
scanf("%d",&n);
queue<int> l;
for(int i=0;i<n;i++){
int y;
scanf("%d",&y);
l.push(y);
}
while(l.size()>1){
int i=0;
int m,n;
m=l.front();
l.pop();
n=l.front();
l.pop();
l.push(lcm(m,n));
}printf("%d",l.front());
}
