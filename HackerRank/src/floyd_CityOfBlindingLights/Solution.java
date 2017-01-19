package floyd_CityOfBlindingLights;

import java.io.BufferedInputStream;
import java.util.Scanner;

public class Solution {


    private static final int MAX_VALUE = (1 << 28);

    public static void main(String[] args) {

		final Scanner sc = new Scanner(new BufferedInputStream(System.in));

		short N = sc.nextShort();
        int[][] matrix = create((short) (N + 1));

        int M = sc.nextInt();
        for (int i = 0; i < M; i++) {
            short x = sc.nextShort();
            short y = sc.nextShort();
            short r = sc.nextShort();
            matrix[x][y] = r;
        }

        FloydMarshallAlgorithm(matrix);

        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++) {
            short x = sc.nextShort();
            short y = sc.nextShort();
            int path = matrix[x][y];
            if (MAX_VALUE <= path)
                path = -1;
            System.out.println(path);
        }

		sc.close();

	}

    private static int[][] create(short n) {
        int[][] matrix = new int[n][];
        for (short i = 0; i < n; i++) {
            matrix[i] = new int[n];
            for (short j = 0; j < n; j++) {
                matrix[i][j] = (i == j) ? 0 : MAX_VALUE;
            }
        }

        return matrix;
    }

    private static void FloydMarshallAlgorithm(int[][] matrix) {
		int V = matrix.length;
		for (int k = 0; k < V; k++) {
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {
					int candidate = matrix[i][k] + matrix[k][j];
					if (candidate < matrix[i][j])
						matrix[i][j] = candidate;
				}
			}
		}
	}

}
