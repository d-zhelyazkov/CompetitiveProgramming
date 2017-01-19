package investigatingPrimePattern;

import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {

	private static final byte A_C = 6;

	private static final SquareRootTool SQUARE_ROOT_TOOL = SquareRootTool.getInstance();
	private static final PrimesCollection PRIMES_COLLECTION = PrimesCollection.getInstance();

	public static void main(String[] args) {
		final Scanner in = new Scanner(new BufferedInputStream(System.in));
		final byte T = in.nextByte();
		for (byte i = 0; i < T; i++) {
			final long L = in.nextInt();
			final byte as[] = new byte[A_C];
			for (byte j = 0; j < A_C; j++)
				as[j] = in.nextByte();

			final long result = process(L, as);
			System.out.println(result);
		}

		in.close();
	}

	private static long process(long l, byte[] as) {
		if (!check(as))
			return 0;

		long sum = 0;
		final long lSquare = l * l;
		PRIMES_COLLECTION.computePrimes(lSquare + as[A_C - 1]);

		final List<Long> primes = PRIMES_COLLECTION.getPrimes();
		for (int i = 0; i < primes.size() - A_C; i++) {
			long num = 0;
			for (byte j = A_C - 1; 0 <= j; j--) {
				long curr = primes.get(i + j);
				curr -= as[j];
				if (!SQUARE_ROOT_TOOL.isPerfectSquare(curr)) {
					num = 0;
					break;
				}

				if (num == 0) {
					long tst = SQUARE_ROOT_TOOL.getTst();
					if (l <= tst){
						i = primes.size();
						break;
					}
						
					num = tst;
				} else if (num != SQUARE_ROOT_TOOL.getTst()) {
					num = 0;
					break;
				}
			}
			sum += num;
		}

		return sum;
	}

	private static boolean check(byte[] as) {
		byte isLOdd = (byte) (as[0] & 1);

		for (byte i = 1; i < A_C; i++)
			if (isLOdd != (as[i] & 1))
				return false;

		return true;
	}

}

final class PrimesCollection {
	private static final PrimesCollection INSTANCE = new PrimesCollection();

	public static PrimesCollection getInstance() {
		return INSTANCE;
	}

	private long lastCheck = 0;
	private final List<Long> primes;

	private PrimesCollection() {
		primes = new ArrayList<>();
		primes.add(2l);
		primes.add(3l);
		lastCheck = 3;
	}

	public void computePrimes(long max) {
		for (long i = lastCheck + 2; i <= max; i += 2) {
			boolean isPrime = true;

			for (long prime : primes) {
				if (i % prime == 0) {
					isPrime = false;
					break;
				}
				if (i < prime * prime)
					break;
			}

			if (isPrime)
				primes.add(i);
		}

		if (lastCheck < max)
			lastCheck = max;
	}

	public List<Long> getPrimes() {
		return primes;
	}

}

final class SquareRootTool {
	private static final SquareRootTool INSTANCE = new SquareRootTool();

	public static SquareRootTool getInstance() {
		return INSTANCE;
	}


	private long tst = 0;

	private SquareRootTool() {
	}

	public final boolean isPerfectSquare(long n) {
		tst = 0;
		if (n < 0)
			return false;

		switch ((int) (n & 0xF)) {
		case 0:
		case 1:
		case 4:
		case 9:
			tst = (long) Math.sqrt(n);
			return tst * tst == n;

		default:
			return false;
		}
	}

	public long getTst() {
		return tst;
	}

}