import java.io.*;
import java.util.*;

import javax.swing.SwingContainer;

public class CF1343D{
    public static FastScanner sc = new FastScanner();
    public static void main(String[] args){
        Integer t; t = sc.nextInt();
        for (int i = 0; i < t; i++) 
            System.out.println(Solve());
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

    public static Integer Solve(){
        Integer n = sc.nextInt();
        Integer k = sc.nextInt();
        Integer[] a = new Integer [n];
        Integer[] evt = new Integer [2 * k + 2];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        for (int i = 0; i < 2 * k + 2; i++) evt[i] = 0;
        for (int i = 0; i < n / 2; i++){
            Integer mi = Math.min(a[i], a[n - i - 1]);
            Integer ma = Math.max(a[i], a[n - i - 1]);
            evt[1] += 2; evt[mi + 1]--;
            evt[mi + ma]--; evt[mi + ma + 1]++;
            evt[ma + k + 1]++;
        }
        Integer sum = 0, res = Integer.MAX_VALUE;
        for (int i = 1; i < 2 * k + 2; i++){
            sum += evt[i]; res = Math.min(sum, res);
        }
        return res;
    }
}