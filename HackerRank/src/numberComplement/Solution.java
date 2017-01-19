package numberComplement;

import java.util.Scanner;

public class Solution {
	/*
	 * Complete the function below.
	 */

	static int getIntegerComplement(int n) {
		byte valuableBits = (byte) (32 - Integer.numberOfLeadingZeros(n));
		n = ~n;
		int mask = (1 << valuableBits) - 1;
		n &= mask;
		return n;
	}

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		int res;
		int _n;
		_n = Integer.parseInt(in.nextLine());

		res = getIntegerComplement(_n);
		System.out.println(res);
		in.close();
	}
}
