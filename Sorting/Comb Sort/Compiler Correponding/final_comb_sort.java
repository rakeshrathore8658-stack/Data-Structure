// comb sort

class Demo12
{
    static int c = 1;

    static void show(int x[], int n, int g)
    {
        if (g < 1) g = c--;
        if (g < 1) return;

        int i;
        int t;

        for (i = 0; i < n - g; i++)
        {
            if (x[i] > x[i + g])
            {
                t = x[i];
                x[i] = x[i + g];
                x[i + g] = t;
            }
        }

        show(x, n, (int)(g / 1.3));
    }

    public static void main(String ar[])
    {
        int i;
        int n = 13;

        int x[] = {5, 0, 6, 2, 7, 1, 8, 4, 9, 3, 12, 11, 5};

        show(x, n, (int)(n / 1.3));

        for (i = 0; i < n; i++)
        {
            System.out.println(x[i]);
        }
    }
}

/*
0
1
2
3
4
5
5
6
7
8
9
11
12

=== Code Execution Successful ===
*/