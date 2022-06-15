/* wHEN METHOD DEFINED IN CLASS AS A PRIVATE THEN THAT METHOD CAN BE INVOKE ONLY BY
MEMBERS OF PARTICULAR CLASS.vISIBILTY OF A PRIVATE METHOD IS RESTRICTED OUT OF CLASS..
IT THROWS AN ERROR :C:\Users\Lab-3\Desktop\javacode>javac Main.java
Main.java:7: error: methodTwo(int) has private access in DemoMethod
                  ob. methodTwo(30);
				  */
				  /*tHEN HOW TO ACCESS PRIVATE MEMBERS(METHODS AND VARIABLE) IN OTHER CLASS*/
class Main
{
 public static void main(String ar[])
   {  
        DemoMethod ob=new DemoMethod();
	      ob.methodOne();
		  ob. methodTwo(30);
   }
 }