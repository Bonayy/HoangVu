import java.io.*;
import java.util.*;

public class Main {
    static Map <Integer, Long> fibo = new TreeMap <Integer, Long>();
    static Integer mod = 111539786;

    public static Long calc(Integer n){
        if (fibo.containsKey(n)) return fibo.get(n); 
        Integer k = n >> 1; Long x = calc(k - 1), y = calc(k);
        if ((n & 1) == 1){
            fibo.put(n, (x * y * 2 + y * y) % mod);
            return fibo.get(n);
        }
        else {
            fibo.put(n, (x * x + y * y) % mod);
            return fibo.get(n);
        }
    }
    public static void main(String[] args){
        FastScanner sc = new FastScanner();
        Integer t = sc.nextInt(), n;
        fibo.put(0, 1L); fibo.put(1, 1L);
        for (int i = 0; i < t; i++){
            n = sc.nextInt(); System.out.println(calc(n));
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
    
        Integer nextInt(){
            return Integer.parseInt(nextToken());
        }
    
        Long nextLong(){
            return Long.parseLong(nextToken());
        }
    
        Double nextDouble(){
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