#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
scanf("%d",&n);
for(int i=0;i<(n<<1);i++){
for(int j=0;j<n;j++){
if(((i|(j<<1))!=i))printf("%d %d\n",i,i|(j<<1));
}
}


}
