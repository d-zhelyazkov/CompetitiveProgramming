#include <stdio.h>
//#include <iostream>
#include <stdint.h>

//using namespace std;

enum Pointer{FIRST, LAST};

int main() {

	uint16_t n, m, x, y;
	uint64_t k;
	scanf("%hu %hu %I64d %hu %hu", &n, &m, &k, &x, &y);
	//cin >> n >> m >> k >> x >> y;
	//cout << n << ' ' << m << ' ' << k << ' ' << x << ' ' << y << endl;

	uint64_t max, min, s;
	if (n == 1) {
		uint64_t times = k / m;
		s = min = max = times;
		uint16_t left = k % m;
		if (left) {
			max++;
			if (y <= left)
				s++;
		}
	}
	else {
		uint16_t q = ((uint16_t)n - 1) * m;
		uint64_t times = k / q;
		uint16_t left = k % q;
		uint64_t middleRows;
		max = middleRows = times;
		uint64_t firstRow, lastRow;
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

		uint16_t dist = 0;
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
	//cout << max << ' ' << min << ' ' << s;

	return 0;
}