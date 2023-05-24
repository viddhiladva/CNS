
import java.util.Scanner;

public class DSA 
{
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);

        System.out.print("Enter p : ");
        int p = scan.nextInt();

        System.out.print("Enter q : ");
        int q = scan.nextInt();

        System.out.print("Enter g : ");
        int g = scan.nextInt();

        System.out.print("Alice private key a: ");
        int a = scan.nextInt();

        System.out.print("Message digest h ");
        int h = scan.nextInt();

        System.out.print("Enter k between 1 and " + (q-1) + " :");
        int k = scan.nextInt();

        int x = g;

        for(int i=2;i<=k;i++)
        {
            x = (x*g)%p;
        }

        int r = x%q;

        int s=0;

        if(r!=0)
        {
            int kinverse=EUA(q,k);

            s  = kinverse*(h + (a*r))%q;

            if(s!=0)
            {
                System.out.println("The Signature is " + r + " " + s);
            }

        }

        System.out.print("Enter Alice public key : ");
        int A = scan.nextInt();

        if(r<q && s<q)
        {
            int w = EUA(q,s);
            System.out.println("w " + w);
            int u1 = (h*w)%q;
            int u2 = (r*w)%q;

            int bx1 = g;

            for(int i=2;i<=u1;i++)
                bx1 = (bx1*g)%p;

            int bx2 = A;

            for(int i=2;i<=u2;i++)
                bx2 = ((bx2%p)*(A%p))%p;


            int bx = (bx1*bx2)%p;
            System.out.println(bx);
            int v = bx%q;
            System.out.println(v);
            if(v==r)
            {
                System.out.println("Verified");
            }
        }

    }

    public static int EUA(int fieN,int e)
    {
        int a1 = 1;
        int a2 = 0;
        int a3 = fieN;

        int b1 = 0;
        int b2 = 1;
        int b3 = e;

        int q = 0;
        int ans = b2;

        while(b3!=0 && b3!=1)
        {
            q = a3/b3;
            int t1 = a1;
            int t2 = a2;
            int t3 = a3;

            a1 = b1;
            a2 = b2;
            a3 = b3;

            b1 = t1 - q*b1;
            b2 = t2 - q*b2;
            b3 = t3 - q*b3;


            if(b3==1)
            {
                if(b2 < 0)
                {
                    b2 = fieN + b2;
                }

                ans = b2;
            }
            else
            {
                ans = 0;
            }
        }

        return ans;
    }
}






