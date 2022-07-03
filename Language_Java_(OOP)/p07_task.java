// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 7th January 2022

class Main{
	public static void main(String args[]){
		Car obj;
		
		obj = new ElectricCar();
		obj.drive();
		
		obj = new PatrolCar();
		obj.drive();
		
	}
};

abstract class Car{
	String make; 
	String model;
	
	abstract void drive();

};

class ElectricCar extends Car{
	double batteryLevel;

	void charge(){
		System.out.println("Your electric car is charged !");
	}

	void drive(){
		System.out.println("Your are driving an electric car !");
	}

}

class PatrolCar extends Car{
	double fuelLevel;
	
	void drive(){
		System.out.println("Your are driving an patrol car !");
	}

	void fillUp(){
		System.out.println("Your patrol car is filled !");
	}
}







