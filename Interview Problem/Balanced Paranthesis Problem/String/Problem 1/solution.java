import java.util.*;
class Demo
{
public static void main(String ar[])
{
	int t=0;
	System.out.println("Enter Any No.");
	
	Scanner sc =new Scanner(System.in);
	String s = sc.next();
	
	String s1="";
	
	StringTokenizer st=new StringTokenizer(s,",");
	while(st.hasMoreTokens())
	{
		String s2=st.nextToken();
		
		if(Integer.parseInt(s2)!=5)
		{
			t=t+Integer.parseInt(s2);
		}
		if(s2.equals("5"))
		{ 
			s1=s1+s2;
			while(st.hasMoreTokens())
			{
				String s3=st.nextToken();
				 s1=s1+s3;
				
				if(s3.equals("8"))
				{
				 break;}
			}
			break;
		}

	}
	while(st.hasMoreTokens())
	{
		String s4=st.nextToken();
		t=t+Integer.parseInt(s4);
	}       
	
	System.out.println("Num1= "+t);
	System.out.println("Num2= "+s1);
	
	int x=Integer.parseInt(s1);
	System.out.println("Sum (Num1 + Num2) Output = "+(x+t));

}
}



/*
outut :- 
        Enter Any No.
        3,2,6,5,1,4,8,9
        Num1= 20
        Num2= 5148
        Sum (Num1 + Num2) Output = 5168
*/
