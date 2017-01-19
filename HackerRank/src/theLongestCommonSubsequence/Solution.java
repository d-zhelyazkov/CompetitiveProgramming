package theLongestCommonSubsequence;

import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		/*
		 * Enter your code here. Read input from STDIN. Print output to STDOUT.
		 * Your class should be named Solution.
		 */

		final Scanner sc = new Scanner(new BufferedInputStream(System.in));

		short n = sc.nextShort();
		short m = sc.nextShort();

		short[] A = new short[n];
		for (short i = 0; i < n; i++)
			A[i] = sc.nextShort();

		short[] B = new short[m];
		for (short i = 0; i < m; i++)
			B[i] = sc.nextShort();

		final List<Short> resultList = process(A, B);
		final StringBuilder result = new StringBuilder();
		boolean first = true;
		for (Short number : resultList) {
			if (first) {
				first = false;
			} else {
				result.append(' ');
			}
			result.append(number);
		}
		System.out.print(result);
		sc.close();
	}

	private static List<Short> process(short[] A, short[] B) {
		short maxLength = (short) Math.min(A.length, B.length);

		short[][] C = new short[A.length][B.length];
		boolean done = false;
		List<List<IXPair>> cache = new ArrayList<List<IXPair>>(maxLength + 1);
		cache.add(null);
		for (short i = 0; !done && i < A.length; i++) {
			for (short j = 0; j < B.length && !done; j++) {
				if (A[i] == B[j]) {
					C[i][j] = 1;
					if (i > 0 && j > 0)
						C[i][j] += C[i - 1][j - 1];

					if (cache.size() == C[i][j])
						cache.add(new ArrayList<IXPair>());
					cache.get(C[i][j]).add(new IXPair(i, j));

					if (C[i][j] == maxLength)
						done = true;

				} else {
					if (i > 0) {
						C[i][j] = C[i - 1][j];
					}
					if (j > 0) {
						C[i][j] = (short) Math.max(C[i][j], C[i][j - 1]);
					}
				}
			}
		}

		final LinkedList<Short> result = new LinkedList<>();
		IXPair lastPair = new IXPair((short) (A.length + 1), (short) (B.length + 1));
		for (short length = (short) (cache.size() - 1); length > 0; length--) {
			for (IXPair pair : cache.get(length))
			{
				if (pair.compareTo(lastPair) < 0) {
					result.addFirst(A[pair.i]);
					lastPair = pair;
					break;
				}
			}
		}
		
		return result;
	}

}

class IXPair implements Comparable<IXPair> {
	short i;
	short j;

	public IXPair(short i, short j) {
		super();
		this.i = i;
		this.j = j;
	}

	@Override
	public int compareTo(IXPair o) {

		return (i < o.i && j < o.j) ? -1 : 1;
	}

}
