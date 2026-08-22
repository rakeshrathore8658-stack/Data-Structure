//Growable Nature Array

class A
{
	int size;
	int capacity;
	int x[];

	A()
	{
		this(10);
	}

	A(int capacity)
	{
		this.capacity = capacity;
		x = new int[capacity];
	}

	void add(int v)
	{
		resize();
		x[size++] = v;
	}

	void resize()
	{
		if(size == capacity)
		{
			capacity = 2 * capacity;

			int y[] = new int[capacity];
			int i;

			for(i = 0; i < size; i++)
			{
				y[i] = x[i];
			}

			x = y;
		}
	}
}


class Collect
{
	public static void main(String ar[])
	{
		int i;

		A a1 = new A();

		System.out.println(a1.size);
		System.out.println(a1.capacity);

		for(i = 1; i <= 10; i++)
		{
			a1.add(i);
		}

		System.out.println(a1.size);
		System.out.println(a1.capacity);

		a1.add(15);

		System.out.println(a1.size);
		System.out.println(a1.capacity);
	}
}

