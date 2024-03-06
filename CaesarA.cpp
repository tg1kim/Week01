#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable: 4996 4326 6031)

void main()
{
	char sMsg[80];
	int nKey = 3, nMore = true;
	while (nMore) {
		printf("? ");
		gets_s(sMsg);
		if (sMsg[0] == NULL)
			break;
		else if (sMsg[0] == '@') {
			printf("Key ? ");
			gets_s(sMsg);
			nKey = atoi(sMsg);
		}
		else {
			char Encrypt(char chr, int nKey);

			printf("  ");
			for (int i = 0; sMsg[i]; i++)
				putchar(Encrypt(sMsg[i], nKey));
			putchar(10);
		}
		putchar(10);
	}
	printf("Bye, ....\n");
}

char Encrypt(char chr, int nKey)
{
	// 대소문자만 암호화
	if (isalpha(chr)) {
		//char cBgn = isupper(chr) ? 'A' : 'a';
		char cBgn = (chr & 0x60) + 1;
		chr = (chr - cBgn + nKey + 26) % 26 + cBgn;
	}
	return chr;
}

/*****
? I Love You
  L Oryh Brx

? @
Key ? -3

? L Oryh Brx
  I Love You

?
Bye, ....
*****/