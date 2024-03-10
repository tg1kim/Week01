#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)
#define N	1000


void main()
{
	while (1) {
		printf("? ");
		int n;
		scanf("%d", &n);
		if (n <= 0 || n > N)
			break;
		int SkipEraser1(int n);
		int SkipEraser2(int n);
		printf("Simulation: %d\n",   SkipEraser1(n));
		printf(" Recursion: %d\n\n", SkipEraser2(n));
	}
	printf("Bye, ...\n");
}

int SkipEraser1(int n)
{
	int nNecklace[N];											// 목걸이를 배열로 정의한다(0에서 n-1까지)
	for (int i = 0; i < n; i++)									//목걸이  n개의 구슬을 1에서 n까지 초기화 한다
		nNecklace[i] = i + 1;
	while (n > 1) {
		while (nNecklace[nNdx = (nNdx + 1) % n] == 0);			// skip
		nNecklace[nNdx] = 0;									// erase
		while (nNecklace[nNdx = (nNdx + 1) % n] == 0);			// for skip
	}
	return nNecklace[0];
}

int SkipEraser2(int n)									// 순환 함수로 작성
{
	// [일반규칙] f(n) ::= 2f(n/2) +(-) 1 ;; n이 짝수 -, 홀수 +
	// [진행방향] n이 반으로 감소
	// [중단조건] n이 1이면 단순해 1
	return 0;
}
