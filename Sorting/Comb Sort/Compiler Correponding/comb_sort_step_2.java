// Comb sort step 2
class Demo12
{
    static void show(int x[], int n, int g)
    {
        if(g == 9 || g == 10)
            g = 11;

        if(g < 1)
            return;

        int i;
        int t;

        for(i = 0; i < n - g; i++)
        {
            if(x[i] > x[i + g])
            {
                t = x[i];
                x[i] = x[i + g];
                x[i + g] = t;
            }
        }

        show(x, n, (int)(g / 1.3));   // type cast
    }

    public static void main(String ar[])
    {
        int i;
        int n = 13;

        int x[] = {4, 0, 3, 2, 7, 1, 8, 5, 9, 6, 12, 11, 5};

        show(x, n, (int)(n / 1.3));

        for(i = 0; i < n; i++)
        {
            System.out.printf("%d \n", x[i]);
        }
    }
}