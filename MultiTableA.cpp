#include <stdio.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	// 아래의 함수들을 사용하여 구구단을 출력하라
	void MultiTbl();
	MultiTbl();
}

void MultiTbl()
{
	// 2단부터 9단까지 구구단을 출력한다.
	void MultiTblDan(int nDan);
	for (int nDan = 2; nDan <= 9; nDan++) {
		MultiTblDan(nDan);
		putchar(10);
	}
}

void MultiTblDan(int nDan)
{
	// 구구단의 한 단(nDan)을 출력한다
	void MultiTblRow(int nDan, int nRow);
	for (int nRow = 2; nRow <= 9; nRow++)
		MultiTblRow(nDan, nRow);
}

void MultiTblRow(int nDan, int nRow)
{
	// 구구단의 한 행(nDan의 nRow행)을 출력한다.
	printf("%d x %d = %2d\n", nDan, nRow, nDan * nRow);
}


/*****
2 x 2 =  4
2 x 3 =  6
2 x 4 =  8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18

3 x 2 =  6
3 x 3 =  9
3 x 4 = 12
3 x 5 = 15
3 x 6 = 18
3 x 7 = 21
3 x 8 = 24
3 x 9 = 27

4 x 2 =  8
4 x 3 = 12
4 x 4 = 16
4 x 5 = 20
4 x 6 = 24
4 x 7 = 28
4 x 8 = 32
4 x 9 = 36

5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45

6 x 2 = 12
6 x 3 = 18
6 x 4 = 24
6 x 5 = 30
6 x 6 = 36
6 x 7 = 42
6 x 8 = 48
6 x 9 = 54

7 x 2 = 14
7 x 3 = 21
7 x 4 = 28
7 x 5 = 35
7 x 6 = 42
7 x 7 = 49
7 x 8 = 56
7 x 9 = 63

8 x 2 = 16
8 x 3 = 24
8 x 4 = 32
8 x 5 = 40
8 x 6 = 48
8 x 7 = 56
8 x 8 = 64
8 x 9 = 72

9 x 2 = 18
9 x 3 = 27
9 x 4 = 36
9 x 5 = 45
9 x 6 = 54
9 x 7 = 63
9 x 8 = 72
9 x 9 = 81
*****/