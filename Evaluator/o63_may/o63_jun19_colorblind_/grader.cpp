#include "colorblind.cpp"
#include <iostream>
std::string S;
		int N; 
int NUMBER_OF_MONKEYS, NUMBER_OF_CALLS;
int use_device(int a, int b) {
	
	if(a < 0 || NUMBER_OF_MONKEYS <= a || b < 0 || NUMBER_OF_MONKEYS <= b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	if(a == b) {
		printf("Wrong Answer: illegal call\n");
		exit(0);
	}

	NUMBER_OF_CALLS++;
	swap(S[a],S[b]);
	int res = getdist(N,S);
	swap(S[a],S[b]);
	printf("<%d>",res);
	return res;
}

int main() {

	//////////// run multiple tests ////////////
freopen("_working/input.in","r",stdin);
	int T; scanf("%d",&T);

	while(T--) {

		//////////////// get input ////////////////

		std::cin >> N >> S;

		NUMBER_OF_MONKEYS = 2 * N;

		////////////////// solve //////////////////

		NUMBER_OF_CALLS = 0;
		std::string ret = investivate_colors(N);
		cout<<ret;
		if(ret != S) {
			printf("Wrong Answer: incorrect\n");
			exit(0);
		}
		
		printf("Accepted: %d\n",NUMBER_OF_CALLS);
	}

	return 0;
}