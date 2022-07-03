/* 1.Wap to define method which takes 
sequence of string as a parameter which display 
passed argument and lenth of argument at 
indices 0 and 1.
2.Write a method which takes varaible argument 
of type character or sequnce of characters,
concatenates passed character 
and return it as a String.









/*Write program to add two integer values,
three integer values
four integer values.*/

class VargEx
{	public static  void arg(String...name){
		System.out.printf("length = &d\n" , name[0].length() );
		System.out.printf("length = &d\n" , name[1].length() );
		for(String  i : name ) System.out.println(i);
	}	
	static String conCat(char...name){
		String str = "";
		for (char temp : name) str += temp;
		return str;
	}
	
	
	
	
	/*main methods takes String array as an argument
because string can hold any type of data
int the form of String.To convert passed string 
in required primitive data thre are some 
parsing methods available in java under 
Wrapper classes.
HOW TO PASS PARAMETERS TO MAIN METHOD
1.USING COMMAND LINE
2.IN IDE there are options to pass cmd argument.
*/  public static void main(String []ar)	 {  
  System.out.println( conCat('a','b','c'));
	   System.out.println(ar[0]);
	/*   int x=Integer.parseInt(ar[0]);
		 int x1=Integer.parseInt(ar[1]);
		 System.out.println(x+x1);*/
		 
		 
		//System.out.println(add(11,11));
	 }
	public static  int add(int ...x)
	{    int sum=0;
		 for(int i=0;i<x.length;i++)
			 sum+=x[i];
		 return sum;
	}
}