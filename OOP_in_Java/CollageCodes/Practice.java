class Demo
{
  //class variable
   static  String name ="cse";  
       String Iname ; //INSTANCE VAR
   public static void main(String ar[])
     {
	     Demo ob=new Demo(); Demo ob1=new Demo(); Demo ob2=new Demo();
		 System.out.print(name);System.out.print(ob.name);
		 ob1.name="AIML";
		 System.out.print(ob.name);
	 }
}