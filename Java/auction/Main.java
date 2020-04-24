import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){
        FastScanner sc = new FastScanner();
        int n, m; m = sc.nextInt(); n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        Arrays.sort(a); long maxv = 0; int res = 0;
        for (int i = 0; i < n / 2; i++){
            int temp = a[i]; a[i] = a[n - i - 1]; a[n - i - 1] = temp;
        }
        for (int i = 0; i < Math.min(m, n); i++){
            if (1L * (i + 1) * a[i] > maxv){
                maxv = 1L * (i + 1) * a[i]; res = a[i];
            }
        }
        System.out.print(res); System.out.print(" ");
        System.out.println(maxv);
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