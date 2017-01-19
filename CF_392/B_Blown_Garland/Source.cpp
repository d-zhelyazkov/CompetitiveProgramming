#include <stdio.h>

char BUFF[101];

unsigned char COUNTS[4] = { 0 };
unsigned char Rix = 0;
unsigned char Gix = 0;
unsigned char Bix = 0;
unsigned char Yix = 0;

int main() {
	scanf("%s", BUFF);
	for (unsigned char i = 0; BUFF[i]; i++) {
		unsigned char x = i % 4;
		switch (BUFF[i])
		{
		case 'R':
			Rix = x;
			break;
		case 'G':
			Gix = x;
			break;
		case 'B':
			Bix = x;
			break;
		case 'Y':
			Yix = x;
			break;
		case '!':
			COUNTS[x] ++;
			break;
		default:
			break;
		}
	}

	printf("%hhu ", COUNTS[Rix]);
	printf("%hhu ", COUNTS[Bix]);
	printf("%hhu ", COUNTS[Yix]);
	printf("%hhu ", COUNTS[Gix]);

	return 0;
}