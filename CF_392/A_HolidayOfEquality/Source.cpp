#include <stdio.h>

int main() {

	unsigned char n;
	scanf("%hhu\n", &n);

	unsigned sum = 0;
	unsigned max = 0;
	for (unsigned char i = 0; i < n; i++) {
		unsigned num;
		scanf("%u", &num);
		sum += num;
		if (num > max) {
			max = num;
		}
	}

	printf("%u", (n * max) - sum);

	return 0;
}