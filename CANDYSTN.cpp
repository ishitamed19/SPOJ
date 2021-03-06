#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define FOR(A,B,C) for(int A=B;A<C;A++)
#define EFOR(A,B,C) for(int A=B;A<=C;A++)
#define RFOR(A,B,C) for(int A=B;A>=C;A--)
#define MEM(A,B) memset(A,B,sizeof(A))

using namespace std;

inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0'||ch>'9') && ch!='-' && ch!=EOF)
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

int main()
{
	int T;
	Input(T);

	int N,M;
	while(T--){
		Input(N),Input(M);

		int colc=1,bag=N-1;
		int mnC=1,mnB=N-1;

		int prev,nxt;
		Input(prev);
		FOR(a,0,M-1){
			Input(nxt);

			int dif=nxt-prev;
			if(dif!=0)
				colc+=dif,bag-=dif;
			else
				colc-=1;

			mnC=min(mnC,colc);
			mnB=min(mnB,bag);

			prev=nxt;
		}

		if(mnC>0 && mnB>=0)
			printf("1\n");
		else if(mnB<=0)
			printf("-1\n");
		else {
			int use=2-mnC;
			int chng=mnB+mnC;

			if(use>N || chng<0)
				printf("-1\n");
			else
				printf("%d\n",use);
		}
	}

	return 0;
}
