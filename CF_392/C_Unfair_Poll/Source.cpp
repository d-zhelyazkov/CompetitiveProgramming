#include <stdio.h>

enum Pointer{FIRST, LAST};

int main() {

	unsigned char n, m, x, y;
	unsigned long long k;
	scanf("%hhu %hhu %llu %hhu %hhu", &n, &m, &k, &x, &y);

	unsigned long long max, min, s;
	if (n == 1) {
		unsigned long long times = k / m;
		s = min = max = times;
		unsigned char left = k % m;
		if (left) {
			max++;
			if (y <= left)
				s++;
		}
	}
	else {
		unsigned short q = ((unsigned short)n - 1) * m;
		unsigned long long times = k / q;
		unsigned short left = k % q;
		unsigned long long middleRows;
		max = middleRows = times;
		unsigned long long firstRow, lastRow;
		firstRow = lastRow = times >> 1;

		Pointer ptr;
		if (times & 1) {
			ptr = LAST;
			firstRow++;
		}
		else {
			ptr = FIRST;
		}

		switch (x) {
		case 1:
			s = firstRow;
			break;
		default:
			if (x == n) {
				s = lastRow;
			}
			else {
				s = middleRows;
			}
		}

		unsigned short dist = 0;
		switch (ptr) {
		case FIRST:
			dist = (x - 1) * m + y;
			break;
		case LAST:
			dist = (n - x) * m + y;
			break;
		}
		if (dist <= left)
			s++;

		if (left / m) {
			switch (ptr) {
			case FIRST:
				firstRow++;
				break;
			case LAST:
				lastRow++;
				break;
			}

			if (left - m)
				max++;
		}


		min = lastRow;
	}
	printf("%I64d %I64d %I64d", max, min, s);

	return 0;
}