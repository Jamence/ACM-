package acm;
import java.util.*;
import java.math.*;
public class hdu1261 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin=new Scanner(System.in);
		while(cin.hasNext()) {
			int n=cin.nextInt();
			if(n==0)break;
			int []mon=new int[n];
			int sum=0;
			for(int i=0;i<n;i++) {
				mon[i]=cin.nextInt();
				sum+=mon[i];
			}
			BigInteger ans_up,temp;
			ans_up=BigInteger.valueOf(1);
			for(int i=1;i<=sum;i++) {
				ans_up=ans_up.multiply(BigInteger.valueOf(i));
			}
//			ans=BigInteger.valueOf(1);
			for(int i=0;i<n;i++) {
				temp=BigInteger.valueOf(1);
				for(int j=1;j<=mon[i];j++)
					temp=temp.multiply(BigInteger.valueOf(j));
				ans_up=ans_up.divide(temp);
			}
			System.out.println(ans_up);
		}
	}

}
