#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define PB(A,B) A.push_back(B);
#define SORT(A) sort( A.begin(),A.end() )
#define ALL(A) A.begin(),A.end()
#define VI vector<int>
#define VS vector<string>
#define VD vector<double>
#define VB vector<bool>
#define SZ(A) int(A.size())
#define LL long long

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();

	if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;

	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');

	N*=sign;
	return;
}

int N,C;
int pos[100001];

int main()
{
	int T;
	Input(T);
	while(T--){
		Input(N),Input(C);
		FOR(inp,0,N){
			int tmp;
			Input(tmp);
			pos[inp]=tmp;
		}
		if(C<=1){
			printf("0\n");
			continue;
		}
		sort(pos,pos+N);

		int low=0,high=pos[N-1]-pos[0];

		while(low<high){
			int mid=low+(high-low+1)/2;

			int tot=1;
			LL sum=0;
			FOR(all,1,N){
				int dif=pos[all]-pos[all-1];
				if(sum+dif<mid)
					sum+=dif;
				else
					tot+=1,sum=0;
			}

			if(tot>=C)
				low=mid;
			else
				high=mid-1;
		}
		printf("%d\n",low);
	}

	return 0;
}
