#include<bits/stdc++.h>
using namespace std;
bool visit[1024];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<1024;i++)visit[i]=0;
		visit[0]=1;
		for(int i=0;i<n;i++){
		int x;
		cin>>x;
		for(int j=0;j<1024;j++){
		if(visit[j])visit[x^j]=1;
	}
		}
	int ans=0;
	for(int i=0;i<1024;i++){
		if(visit[i]==1)
		if(i^k>ans)ans=i^k;
	}
	printf("%d\n",ans);
	}
}
