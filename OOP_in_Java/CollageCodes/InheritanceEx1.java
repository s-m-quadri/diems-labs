/*
''Where subclass(Child class) inherits properties from 
superclass (parent class).
In OOP properties means data members
(variables or attributes of super class)and behviour
 (method of superclass).
 .... In java parent class is known as super class and 
 child class is sub class when any two class establish relation
 through inheritance.
 .... Inheritance can be implemented using keyword extends.
 Example to create inheritance between two class.
 ... Define class Child with 
 datamember(childName:String,parentName:String),setter method.
 Also define class Parent with datamember(parentName:String,
 income:double)and setter method
 ...THE INHERITANCE WHERE CHILD CLASS (SUB CLASS)IS ALLOWED 
 TO INHERIT PROPERTIES FROM MORE THAN ONE PARENTCLASS(SUPER CLASS)
 IS KNOWN AS MULTIPLE INHERITANCE.
 THIS TYPE OF INHERITANCE IS NOT SUPPOTED BY JAVA TO AVOID
 DIAMOND PROBLEM (AMBUIGUITY OF THE DATA) IN SUPER AND 
 SUBCLASSES
 ... HYBRID INHERITANCE: COMBINATION OF HIERARCHICAL
 AND MULTIPLE  INHERITANCE IS KNOWN AS HYBRID INH.
 IMP NOTE: IN JAVA A CHILD CLASS CAN INHERIT ONLY (ONE)PARENT PROPERTIS.
 qUES :  DOES CONSTRUCTOR GETS INHERITED FROM PARENT TO CHILD???
 */
//Example on implicite invocation of parent class constructor in
//child class constructor
class Parent{
	 String pName;
	 double income;
	 Parent(){
		 pName="parent";
	     income=33333.3;
		 }
		 //parametrised constructor
	 Parent( String pName,double income)
	 {
		   this.pName=pName;
		   this.income=income;
	 }
	 void setPname(String p){pName=p;	 }
	  void setIncome(double income){ this.income=income;}
}
class Child extends Parent{
	String cName;
	/*parent class Constructor does not get inherited but 
	it get implicitely invoked as a first statement in child 
	class constructor*/
	Child(){ 
	//implicitely parent class constructor gets invoked
	cName="child";}
	Child( String cName)
	{       super();  //explicit call to no argument parent constructor
		    this.cName=cName;
	}
	Child(String cName,String pName,double income)
	{ // super(pName,income);  //explicit call to parametrised parent constructor
	      this.cName=cName;
	}
	void setCname(String p){cName=p;	 }
	public static void main(String a[])
	{	  //Create object of child class and 
		 // try to acces parent and child propertied
		 Child ob=new Child("SYCSE","cse",12345.67);
		 System.out.println("Parent Name:"+ob.pName);
		  System.out.println("Child Name:"+ob.cName);
		   System.out.println("Parent Income:"+ob.income);
		/* ob.setCname("VVV");
		 ob.setIncome(12222.0);
		 ob.setPname("BBB");
*/	}
}