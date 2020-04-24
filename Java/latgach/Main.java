import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main{
    static BigInteger[] fibo = new BigInteger[1005];

    public static BigInteger calc(int n){
        if (fibo[n] != null) return fibo[n];
        int k = n / 2; 
        BigInteger x = calc(k - 1), y = calc(k);
        if ((n & 1) == 1)
            return fibo[n] = x.multiply(y).multiply(new BigInteger("2")).add(y.multiply(y));
        else return fibo[n] = x.multiply(x).add(y.multiply(y));
    }

    public static void main(String[] args){
        fibo[0] = fibo[1] = new BigInteger("1");
        FastScanner sc = new FastScanner();
        int t = sc.nextInt(), n;
        for (int tt = 0; tt < t; tt++){
            n = sc.nextInt();
            System.out.println(calc(n));
        }
    }

    public static class FastScanner{
        BufferedReader br; StringTokenizer st;
    
        public FastScanner(){
            br = new BufferedReader(new InputStreamReader(System.in));
        }
    
        String nextToken(){
            while (st == null || !st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e){
                    e.printStackTrace();
                }
            return st.nextToken();
        }
    
        int nextInt(){
            return Integer.parseInt(nextToken());
        }
    
        long nextLong(){
            return Long.parseLong(nextToken());
        }
    
        double nextDouble(){
            return Double.parseDouble(nextToken());
        }
    
        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }

}