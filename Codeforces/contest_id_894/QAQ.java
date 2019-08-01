import java.io.*;
/*import java.util.Arrays;
import java.util.InputMismatchException;*/
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {



    public static void main(String[] args) throws IOException {
        MyScanner sc = new MyScanner();

        String s=sc.next();

        int l=s.length();
        int res=0;
        for(int i=0;i<l;i++) {
            int ko = 0;

            if (s.charAt(i) == 'A') {
                for (int j = 0; j < i; j++) {
                    if(s.charAt(j)=='Q')ko++;

                }
                for(int j=i+1;j<l;j++)
                {
                    if(s.charAt(j)=='Q')res+=ko;

                }
            }
        }
        out.print(res);

              out.close();

    }

    // http://codeforces.com/blog/entry/7018
    //-----------PrintWriter for faster output---------------------------------
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));//When THere is no File

    //-----------MyScanner class for faster input----------

    static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        public MyScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
        public boolean ready() throws IOException {return br.ready();}

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}
