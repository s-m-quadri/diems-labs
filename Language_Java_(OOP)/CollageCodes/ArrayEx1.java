/*Define a method createArray() which takes user
 input for an array and returns created array.
 Define method showArray() which display passed
 array element.
 Define method which return an array created from
 different integer variables.
 */
 import java.util.Scanner;
 class ArrayEx1
 {
    public static void main(String []ar)
	 {    
	    int x=1,x1=2,x3=3;
		int arr[]={x,x1,x3};
		int arr1[]={11,111,1111};
		int arr2[]={22,222,2222};
int[][] twoD={{1,2,3},{11,111,1111},{22,222,2222}};
	for(int row=0;row<twoD.length;row++)
	{for(int col=0;col<twoD[0].length;col++){
		 System.out.print(twoD[row][col]+"\t");
	}
	System.out.println();
	}
       		
	 
	 
	 
	 
	 /*int arr[]=createArray();
	        new ArrayEx1().showArray(arr);
		  int a[]= new int[-3];
		  a[0]=3;a[1]=11;*/
		  
	 }
	 public static int[] createArray()
	  {  Scanner sc=new Scanner(System.in);
	      int size;
		  System.out.println("Enter how many elements (size of an array)you want to store in an array");
		  size=sc.nextInt();
		  int arr[]=new int[size];
		   System.out.println("Enter integer element to store into an array :");
		  for(int i=0;i<size;i++)
			  arr[i]=sc.nextInt();
		   return arr;
	  }
	static int[] returnArray()
	    {  int x=23,y=11,z=24;
			 return new int[]{x,y,z};
		}
	  void showArray(int arr[])
	    {
			 for(int i:arr)
				   System.out.println(i);
		}
	}
