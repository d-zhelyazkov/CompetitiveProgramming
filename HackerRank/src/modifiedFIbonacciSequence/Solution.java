package modifiedFIbonacciSequence;

import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT.
		 * Your class should be named Solution.
		 */

		final Scanner sc = new Scanner(new BufferedInputStream(System.in));

		short t1 = sc.nextShort();
		short t2 = sc.nextShort();
		short n = sc.nextShort();

		final ModifiedFibonacciSequence sequence = new ModifiedFibonacciSequence(BigInteger.valueOf(t1),
				BigInteger.valueOf(t2));
		System.out.print(sequence.get(n));
		sc.close();
	}
}

class ModifiedFibonacciSequence {
	private static final short MAX = 20;
	
	private boolean zero = false;
	private final BigInteger[] numbers = new BigInteger[MAX + 1];

	public ModifiedFibonacciSequence(BigInteger t1, BigInteger t2) {
		if (t1 == BigInteger.ZERO && t2 == BigInteger.ZERO) {
			zero = true;
			return;
		}
		numbers[1] = t1;
		numbers[2] = t2;
	}

	public BigInteger get(short i) {
		if (zero)
			return BigInteger.ZERO;

		if (numbers[i] == null)
			// t(i) = t(i-1)^2 + t(i-2)
			numbers[i] = get((short) (i - 1)).pow(2).add(get((short) (i - 2)));

		return numbers[i];
	}

}
