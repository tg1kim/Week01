#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define N	26

void main()
{
	// 알파벳을 순환적으로 출력한다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			putchar('A' + (i + j) % N);
		putchar('\n');
	}
}