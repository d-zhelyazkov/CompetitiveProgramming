package makingPolygons;

import java.io.BufferedInputStream;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		final Scanner sc = new Scanner(new BufferedInputStream(System.in));
		
		short n = sc.nextShort();
		final PriorityQueue<Short> pq = new PriorityQueue<>(n, new Comparator<Short>() {

			@Override
			public int compare(Short o1, Short o2) {
				// TODO Auto-generated method stub
				return Short.compare(o2, o1);
			}
			
		});

		short sum = 0;
		for (short i = 0; i < n; i++) {
			short a = sc.nextShort();
			sum += a;
			pq.add(a);
		}

		short halfSum = (short) (sum >> 1);

		int cracks = 0;
		while (true) {
			short a = pq.poll();
			if (a < halfSum)
				break;
			a >>= 1;
			pq.add(a);
			pq.add(a);
			cracks++;
		}

		System.out.println(cracks);

		sc.close();

	}

}
