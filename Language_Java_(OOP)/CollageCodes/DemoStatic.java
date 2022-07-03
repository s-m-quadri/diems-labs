class DemoStatic
{static{
	   System.out.println("This is static block");
 }
 public static void main(String ar[])
   {  
       Student ob =new Student(26001);
	   Student ob1 =new Student(26002);
	   Student ob2 =new Student();
	    Student.getCountOfObject();
         System.out.println("Student roll no is "+ob.rollNo);
         System.out.println("Student college is "+ ob1.collegeName); 
		//YOU CAN CHANGE THE VALUE OF STATIC VARIABLE
		 ob1.collegeName ="DIEMS_AURANGABAD";
          System.out.println("Student college is "+ ob.collegeName); 
 // invoking static method with class name
           Student.calPercentage();
		  // Student.calMarks();
 }
 }
 
 class Student
 {    int rollNo;
      static int count= 0;
	static  String collegeName  ="diems";
	  Student(){
		   count++;
		  rollNo =12345;}
	  Student(int roll ){ 
	    count++;
		rollNo = roll; }
    //setter method and getter methods	 
	 void setRoll(int r){ rollNo=r;}
	  int getRoll(){return rollNo;}
	  double calMarks()	  { return 0.0;	  }
	  static double calPercentage()  {	
	  System.out.println("College Name"+collegeName); 
      // System.out.println("Roll"+rollNo);
	    return 0.0;
	  }
	  static void getCountOfObject(){
		   System.out.println(" Total objects created "+ count);
	  }
 }
 