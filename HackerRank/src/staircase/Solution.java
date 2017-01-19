package staircase;

import java.util.Arrays;
import java.util.Scanner;

public class Solution {

	/*
	 * Complete the function below.
	 */

	static void StairCase(int n) {

		final StringBuilder string = new StringBuilder();
		boolean firstLine = true;
		for (int i = 1; i <= n; i++) {
			if (firstLine) {
				firstLine = false;
			} else {
				string.append('\n');
			}

			char[] spaces = new char[n - i];
			Arrays.fill(spaces, ' ');
			string.append(spaces);

			char[] symbols = new char[i];
			Arrays.fill(symbols, '#');
			string.append(symbols);
		}

		System.out.print(string);
	}

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int _n;
		_n = Integer.parseInt(in.nextLine().trim());

		StairCase(_n);
		in.close();
	}
}