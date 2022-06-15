class ExStatic 
 {  /*final is the non access modifier
    used with variable,method and class 
	if the variable declared as final then value of 
	the variable cant be changed.*/
	static final int total=100;
	final int t=22;
    static public int x;
	/*static block.It is used to initialize static
	variale.Any logic which you want to load before 
	main method.*/
	static{
	    x=34;
		System.out.print("HI,I AM STATIC BLOCK");
	}
	public static void main(String ar[])
	{
		System.out.print("HI,I AM main method BLOCK");
	}
 }