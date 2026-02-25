 class Demo
 {
    static void show(int x[], int n) 
    {
        int t;
        int g = (int)(n / 1.3); // type cast Double to int 
        
        while (g >= 1) 
        {
            for (int i = 0; i < n - g; i++) 
            {
                if (x[i] > x[i + g]) 
                {
                    t = x[i];
                    x[i] = x[i + g];
                    x[i + g] = t;
                }
            }
            g = (int)(g / 1.3);   // type cast Double to int 
        }
    }

    public static void main(String[] args) 
    {
        int n = 13;
        int x[] = {4,0,3,2,7,1,8,5,9,6,12,11,5};

        show(x, n);

        for (int i = 0; i < n; i++) 
        {
            System.out.println(x[i]);
        }
    }
}


/*
output :-
0
1
2
3
4
5
5
7
6
8
9
11
12



*/
