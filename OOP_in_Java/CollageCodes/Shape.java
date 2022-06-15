


class Shape
{
    void calArea(){ System.out.println("This is mehod overloading demo");}
	//method to calculate area of circle
	double calArea(float r){
	return Math.PI*r*r;}
		  //method to calculate area of triangle
    double calArea(double b,double h)
	{    return 0.5*b*h;
	}
	  //method to calculate area of rectangle
    float calArea(float b ,float w)
	{    return b*w;
	}
	
	public static void main(String ar[])
	{  
	       Shape s=new Shape();
		   s.calArea();
		  System.out.printf("Area of the circle is %.2f", s.calArea(10.5f));
	}
	}