class DemoMethod
{
	//user defined non parameterised method
  public void methodOne()
  {     methodTwo(10);
	    System.out.println("Method One");
  }
  //user defined parameterised method
   private void methodTwo( int x)
   {
	     System.out.println("Method Two is taking parameter x :"+x);
   }
   /* java supports method overloading concept.where number of methods with same method name
   and different parameter list(types of parameter,count of parameter) withi in 
   a same class is known as METHOD OVERLOADING.
   IT IS ALSO KNOWN AS COMPILE TIME  OR STATIC POLYMORPHISM*/
      void methodAdd( int x,int y)
   {
	     System.out.printf("Addition of number %d and %d is %d",x,y,x+y);
   }
    void methodAdd( double x,double y)
   {
	     System.out.printf("Addition of number %f and %f is %f",x,y,x+y);
   }
   public static void main(String ar[])
   {   DemoMethod ob=new DemoMethod();
	      ob.methodOne();
		  ob. methodTwo(30);
		  ob.methodAdd(11,12); ob.methodAdd(11.6,12.4);
   }
 }