#include "colorblind.h"
#include<bits/stdc++.h>
using namespace std;
int getdist(int N,string s){

			queue<int> R,B;
			int dist = 0;
			for(int i=0;i<2*N;i++){
				if(s[i]=='B'){
					if(!R.empty()){
						dist+=i-R.front();
						R.pop();
					}
					else B.push(i);
				}	
				else {
					if(!B.empty()){
						dist+=i-B.front();
						B.pop();
					}
					else R.push(i);
				}
			}
			return dist;

}
std::string investivate_colors(int N) {
	if(N==1)return "RB";
	vector<int> tab[550];
	int val[550];
	map<int,int> m;
	string s;
	for(int i=0;i<2*N;i++)s+='U';
	s[0]='R';
	int ptr=0;
	int tmp = -1;
	queue<int> R;
	queue<int> B;
	int cntB=0,cntR=1;
	for(int i=1;i<2*N;i++){
		int x = use_device(0,i);
		if(tmp==-1)tmp=x;
		if(x!=tmp){
			s[i]='B';
			B.push(i),cntB++;
		}
	}
	if(!B.empty()){for(int i=1;i<2*N;i++){
		if(s[i]=='B')continue;
		int x = use_device(B.front(),i);
		if(x!=tmp)s[i]='R',R.push(i),cntR++;
	}
	B.pop();}
	if(!R.empty())for(int i=1;i<2*N;i++){
		if(s[i]=='B'||s[i]=='R')continue;
		int x = use_device(R.front(),i);
		if(x!=tmp)s[i]='B',cntB++;
	}
	if(!B.empty())for(int i=1;i<2*N;i++){
		if(s[i]=='B'||s[i]=='R')continue;
		int x = use_device(B.front(),i);
	
		if(x!=tmp)s[i]='R',cntR++;
	}
	if(cntB==N){
		for(int i=1;i<2*N;i++){
			if(s[i]=='U')s[i]='R';
		}
	}
	if(cntR==N){
		for(int i=1;i<2*N;i++){
			if(s[i]=='U')s[i]='B',cntB++;
		}
	}
	if(cntB==N-1&&cntR==N-1){
		int a=-1,b=-1;
		for(int i=0;i<2*N;i++){
		if(s[i]=='U'){
			if(a==-1)a=i;
			else b=i;
		}
	}
	s[a]='R';s[b]='B';
	if(getdist(N,s)==tmp)return s;
	swap(s[a],s[b]);

	}
	
	return s;
}