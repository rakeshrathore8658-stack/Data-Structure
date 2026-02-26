// Comb sort step 3
/*
ye program step 2 ka hi hai. 
Lekin is Wale program me dikkat ye hai array pura sort nhi ho raha hai dusri values ke liye 
*/
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

        int x[] = {5,0,6,2,7,1,8,4,9,3,12,11,5};

        show(x, n, (int)(n / 1.3));

        for(i = 0; i < n; i++)
        {
            System.out.printf("%d \n", x[i]);
        }
    }
}


/*
output :- 

0 
1 
2 
3 
5 
4 
5 
6 
7 
8 
9 
11 
12 


*/
