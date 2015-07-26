////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: netcan
////Nickname: Netcan
////Run ID: 
////Submit time: 2015-05-30 20:40:15
////Compiler: Java
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:624MS
////Run memory:25784KB
//////////////////System Comment End//////////////////
/*************************************************************************
	> File Name: j1002.java
	  > Author: Netcan
	  > Blog: http://www.netcan.xyz
	  > Mail: 1469709759@qq.com
	  > Created Time: Sat 30 May 2015 08:21:08 PM CST
 ************************************************************************/

import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class Main {
    public static void main(String[] args) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int T;
		T=cin.nextInt();
		BigInteger a, b;
		int Case = 1;
		for(int T_T=0; T_T<T; ++T_T) {
			a = cin.nextBigInteger();
			b = cin.nextBigInteger();
			System.out.println("Case " + (Case++) + ":");
			System.out.println(a+" + "+b+" = "+a.add(b));
			if(T_T!=T-1)
				System.out.println();
		}

	}
}
