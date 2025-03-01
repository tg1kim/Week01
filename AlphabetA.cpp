#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

#define N	26

void main()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			putchar('A' + (i + j) % N);
		putchar('\n');
	}
}