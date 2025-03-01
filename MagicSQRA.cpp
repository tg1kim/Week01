#include <stdio.h>

#pragma warning(disable: 4996 4326 6031 6385 6386)

#define	N	40

void main()
{
	void MakeMagicSquare(int nMagicSqr[][N], int nN);
	void ShowMagicSquare(int nMagicSqr[][N], int nN);
	void CheckMagicSquare(int nMagicSqr[][N], int nN);

	int nN;
	int nMagicSqr[N][N];
	while (1) {
		printf("? ");
		scanf("%d", &nN);
		if (nN % 2 == 0 || nN > N)
			break;
		MakeMagicSquare(nMagicSqr, nN);
		ShowMagicSquare(nMagicSqr, nN);
		CheckMagicSquare(nMagicSqr, nN);
		printf("\n");
	}
	printf("Bye, ....\n");
}

void InitMagicSquare(int nMagicSqr[][N], int nN)
{
	for (int nRow = 0; nRow < nN; nRow++)
		for (int nCol = 0; nCol < nN; nCol++)
			nMagicSqr[nRow][nCol] = 0;
}

void MakeMagicSquare(int nMagicSqr[][N], int nN)
{
	InitMagicSquare(nMagicSqr, nN)
	int nRow = 0, nCol = nN / 2, nSqr = nN * nN;
	nMagicSqr[nRow][nCol] = 1;
	for (int nCell = 2; nCell <= nSqr; nCell++) {
		int nPrvRow = nRow, nPrvCol = nCol;
		nRow = (nRow - 1 + nN) % nN;
		nCol = (nCol + 1) % nN;
		if (nMagicSqr[nRow][nCol]) {
			nRow = (nPrvRow + 1) % nN;
			nCol = nPrvCol;
		}
		nMagicSqr[nRow][nCol] = nCell;
	}
}

void ShowMagicSquare(int nMagicSqr[][N], int nN)
{
	printf("\n[마방진]\n");
	for (int nRow = 0; nRow < nN; nRow++) {
		for (int nCol = 0; nCol < nN; nCol++)
			printf("%2d ", nMagicSqr[nRow][nCol]);
		putchar('\n');
	}
}

void CheckMagicSquare(int nMagicSqr[][N], int nN)
{
	void CheckMagicSquareRow(int nMagicSqr[][N], int nN);
	void CheckMagicSquareCol(int nMagicSqr[][N], int nN);
	void CheckMagicSquareDgl(int nMagicSqr[][N], int nN, int nDir);

	CheckMagicSquareRow(nMagicSqr, nN);
	CheckMagicSquareCol(nMagicSqr, nN);
	printf("\n[대각선 검사]\n");
	CheckMagicSquareDgl(nMagicSqr, nN, '\\');
	CheckMagicSquareDgl(nMagicSqr, nN, '/');
}

void CheckMagicSquareRow(int nMagicSqr[][N], int nN)
{
	printf("\n[행 검사]\n");
	for (int nRow = 0; nRow < nN; nRow++) {
		printf("행%2d", nRow);
		int nSum = 0;
		for (int nCol = 0; nCol < nN; nCol++) {
			printf("%c ", nCol ? '+' : ':');
			printf("%2d ", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
		}
		printf("= %d\n", nSum);
	}
}

void CheckMagicSquareCol(int nMagicSqr[][N], int nN)
{
	printf("\n[열 검사]\n");
	for (int nCol = 0; nCol < nN; nCol++) {
		printf("열%2d", nRow);
		int nSum = 0;
		for (int nRow = 0; nRow < nN; nRow++) {
			printf("%c ", nRow ? '+' : ':');
			printf("%2d ", nMagicSqr[nRow][nCol]);
			nSum += nMagicSqr[nRow][nCol];
		}
		printf("= %d\n", nSum);
	}
}

void CheckMagicSquareDgl(int nMagicSqr[][N], int nN, int nDir)
{
	int nSum = 0, nDgnl = nDir == '/';
	int nCol = nDgnl * (nN - 1), nDelta = 1 - nDgnl * 2;
	printf("대 %c", nDir);
	for (int nRow = 0; nRow < nN; nRow++, nCol += nDelta) {
		printf("%c ", nRow ? '+' : ':');
		printf("%2d ", nMagicSqr[nRow][nCol]);
		nSum += nMagicSqr[nRow][nCol];
	}
	printf("= %d\n", nSum);
}

/*****
? 5

[      ]
17  24   1   8  15
23   5   7  14  16
 4   6  13  20  22
10  12  19  21   3
11  18  25   2   9

[    ? ]
   0: 17 + 24 +  1 +  8 + 15 = 65
   1: 23 +  5 +  7 + 14 + 16 = 65
   2:  4 +  6 + 13 + 20 + 22 = 65
   3: 10 + 12 + 19 + 21 +  3 = 65
   4: 11 + 18 + 25 +  2 +  9 = 65

[    ? ]
   0: 17 + 23 +  4 + 10 + 11 = 65
   1: 24 +  5 +  6 + 12 + 18 = 65
   2:  1 +  7 + 13 + 19 + 25 = 65
   3:  8 + 14 + 20 + 21 +  2 = 65
   4: 15 + 16 + 22 +  3 +  9 = 65

[ 밢    ? ]
   \: 17 +  5 + 13 + 21 +  9 = 65
   /: 15 + 14 + 13 + 12 + 11 = 65

? 0
Bye, ....
*****/