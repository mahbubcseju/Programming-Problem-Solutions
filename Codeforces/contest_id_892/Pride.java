import java.io.*;
/*import java.util.Arrays;
import java.util.InputMismatchException;*/
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static int GCD(int a, int b) {
        if (b==0) return a;
        return GCD(b,a%b);
    }

    public static void main(String[] args) throws IOException {
        MyScanner sc = new MyScanner();
       // Scanner sc=new Scanner(System.in);

            int n;
            n=sc.nextInt();
            int ar[] =new int[n+2];
            for(int i=1;i<=n;i++)ar[i]=sc.nextInt();
            int koy=n;
            boolean fl=false;
            int cnt=0;
            for(int j=1;j<=n;j++)
            {
                int x=ar[j];
                if(x==1)cnt++;
                for(int k=j;k<=n;k++)
                {
                    x=GCD(x,ar[k]);
                    if(x==1)
                    {
                        koy=Math.min(koy,k-j+1);
                       fl= true;
                        break;
                    }
                }
            }
            if(fl==false)out.println("-1");
            else if(cnt>0)out.println(n-cnt);
            else
            {

                int ans=(koy-1)+(n-1);
                out.println(ans);
            }


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
