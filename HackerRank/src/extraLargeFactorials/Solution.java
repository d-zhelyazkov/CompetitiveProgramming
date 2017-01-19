package extraLargeFactorials;
import java.math.BigInteger;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        final Scanner in = new Scanner(System.in);
		short n = in.nextShort();
        
		System.out.print(computeFactorial(n));

		in.close();
        
    }
    
	private static BigInteger computeFactorial(int i) {
		if (i <= 1)
    		return BigInteger.ONE;
    	
		return BigInteger.valueOf(i).multiply(computeFactorial(i - 1));
    }
}
