/*************************************************************************
	> File Name: fibonacci.java
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 30 May 2015 07:11:36 PM CST
 ************************************************************************/

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
	public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		BigInteger f[] = new BigInteger[10005];
		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(1);
		for (int n = 3; n <= 10000; n++) {
			f[n] = f[n-1];
			f[n] = f[n].add(f[n-2]);
		}
		int n;
		while(cin.hasNextInt()) {
			n=cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
