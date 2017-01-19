import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;


public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int x = sc.nextInt();
        
        Map<Integer, Integer> pool = new HashMap<>(n);
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int count = 1;
            if (pool.containsKey(a)) {
                count += pool.get(a);
            }
            pool.put(a, count);
        }
        
        long sum = 0;
        while (!pool.isEmpty()) {
            Entry<Integer, Integer> elemIt = pool.entrySet().iterator().next();
            int elemCount = elemIt.getValue();
            if (x == 0) {
                if (elemCount > 1) {
                    elemCount --;
                    sum += arithmeticProgressionSum(1, elemCount, elemCount);
                }
            } else {
                int elem2 = x ^ elemIt.getKey();
                Integer elem2Count = pool.get(elem2);
                if (elem2Count != null) {
                    sum += elemCount * elem2Count;
                    pool.remove(elem2);
                }
            }
            pool.remove(elemIt.getKey());
        }
        System.out.print(sum);

        sc.close();

    }

    static double arithmeticProgressionSum(double a1, double an, int n) {
        return n * (a1 + an) / 2;

    }

}
