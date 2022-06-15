
// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 11th December 2021 - 2:25 PM
// Version : 1.0.1

import java.util.Scanner;

class Main{
	public static void main(String arguments[]){
		Main s1 = new Main();
		s1.main_menu();
	}

	// No-arguments Constructor
	Main(){
		roll_no=0;
		name="unknown";
		m1=0;
		m2=0;
		m3=0;
		m4=0;
		m5=0;
	}	
	
	// Instance and Object Variables
	int roll_no;
	String name;
	int m1, m2, m3, m4, m5;
	Scanner scan = new Scanner(System.in);
	
	// Getter Methods (not used) just for reference
	int get_roll(){return roll_no; }
	String get_name(){return name; }
	int get_marks(){return (m1 + m2 + m3 + m4 + m5); }
	int get_percentage(){return get_marks()/5; }
	
	// Setter Methods (not used) just for reference
	void set_roll(int input){roll_no = input;}
	void set_name(String input){name = input; }
	void set_m1(int input){m1 = input;}
	void set_m2(int input){m2 = input;}
	void set_m3(int input){m3 = input;}
	void set_m4(int input){m4 = input;}
	void set_m5(int input){m5 = input;}
	
	// Main Menu
	void main_menu(){
		boolean repeat = true; 
		do {
		// First display
		display_main_menu();
		// Then get the choice
		switch (scan.nextInt()){
			case 1: display_enroll();
				break;
			case 2: display_details();
				break;
			case 3: display_marks();
				break;
			case 4: display_percentage();
				break;

			default:System.out.printf("\nSorry ! we didn't understand ... \n");
			case 5: // Exit with conformation
				System.out.printf("\nProgram is about to exit !");
				repeat = false;
				pause();
				// Clear the screen
				System.out.print("\033[H\033[2J"); 
				break;
		}
		} while (repeat == true);
	}
	
	
	// Pause Method
	void pause(){
		System.out.println("\n Press Enter to continue . . . ");
		scan.nextLine(); // Clearing the buffer if any
		scan.nextLine();
	}
	
	// Five Display Methods
	// 1. Main Menu
	void display_main_menu(){
		// Clear the screen
		System.out.print("\033[H\033[2J");
		// Display main menu
		System.out.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
		System.out.println("@===============@ MAIN MENU @==================@");
		System.out.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
		System.out.println("1. Enter the details of student");
		System.out.println("2. Display the details of student");
		System.out.println("3. Display the total marks of student");
		System.out.println("4. Display the overall percentage");
		System.out.println("5. Exit");
		System.out.println("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
	}
	
	// 2. Enroll Menu
	void display_enroll(){
		// Clear the screen
		System.out.print("\033[H\033[2J");
		
		// Display enroll student menu
		System.out.printf("************************************************\n");
		System.out.printf("**************** ENROLL STUDENT ****************\n");
		System.out.printf("************************************************\n");
		System.out.printf("Enter the details :\n");
		
		// Get name and convert to uppercase
		System.out.printf(" 1. Name : ");
		scan.nextLine(); // Clearing the buffer
		name = scan.nextLine().toUpperCase();
		
		// Get Roll
		System.out.printf(" 2. Roll no. : ");
		roll_no = scan.nextInt();
		
		// Get Marks and check error
		System.out.printf(" 3. Marks (between 1 to 100) :\n");
		System.out.printf("\t 1st subject \t: ");
		while ( m1 <= 0 || m1 > 100) m1 = scan.nextInt();
		System.out.printf("\t 2nd subject \t: ");
		while ( m2 <= 0 || m2 > 100) m2 = scan.nextInt();
		System.out.printf("\t 3rd subject \t: ");
		while ( m3 <= 0 || m3 > 100) m3 = scan.nextInt();
		System.out.printf("\t 4th subject \t: ");
		while ( m4 <= 0 || m4 > 100) m4 = scan.nextInt();
		System.out.printf("\t 5th subject \t: ");
		while ( m5 <= 0 || m5 > 100) m5 = scan.nextInt();

		// Pause Screen		
		System.out.printf("************************************************\n");
		pause();	
	}
	
	// 3. Details Menu
	void display_details(){
		// Clear the screen
		System.out.print("\033[H\033[2J");
		
		// Display students details menu
		System.out.printf("************************************************\n");
		System.out.printf("************** STUDENT'S DETAILS ***************\n");
		System.out.printf("************************************************\n");
		System.out.printf("Name of the student is %s,\n" , name);
		System.out.printf("Having roll number %d\n" , roll_no);
		
		// Pause Screen
		System.out.printf("************************************************\n");
		pause();	
	}
	
	// 4. Marks Menu
	void display_marks(){
		// Clear the screen
		System.out.print("\033[H\033[2J");
		
		// Display marks
		System.out.printf("************************************************\n");
		System.out.printf("***************** TOTAL MARKS ******************\n");
		System.out.printf("************************************************\n");
		System.out.printf("ROLL (%d) %s,  \n" , roll_no , name);
		System.out.printf("\t1. Subject First \t: %d\n" , m1);
		System.out.printf("\t2. Subject Second \t: %d\n" , m2);
		System.out.printf("\t3. Subject Third \t: %d\n" , m3);
		System.out.printf("\t4. Subject Fourth \t: %d\n" , m4);
		System.out.printf("\t5. Subject Fifth \t: %d\n" , m5);
		System.out.printf("\t----------------------------------------\n");
		System.out.printf("\t\t TOTAL MARKS \t: %d\n" , (m1 + m2 + m3 + m4 + m5) );
		
		// Pause Screen
		System.out.printf("************************************************\n");
		pause();
	}
	
	// 5. Percentage Menu
	void display_percentage(){
		// Clear the screen
		System.out.print("\033[H\033[2J");
		
		// Display marks
		System.out.printf("************************************************\n");
		System.out.printf("***************** PERCENTAGE *******************\n");
		System.out.printf("************************************************\n");
		System.out.printf("ROLL (%d) %s,  \n" , roll_no , name);
		System.out.printf("\t1. Subject First \t: %2.2f%%\n" , (float) m1);
		System.out.printf("\t2. Subject Second \t: %2.2f%%\n" , (float) m2);
		System.out.printf("\t3. Subject Third \t: %2.2f%%\n" , (float) m3);
		System.out.printf("\t4. Subject Fourth \t: %2.2f%%\n" , (float) m4);
		System.out.printf("\t5. Subject Fifth \t: %2.2f%%\n" , (float) m5);
		System.out.printf("\t----------------------------------------\n");
		System.out.printf("\t TOTAL PERCENTAGE \t: %2.2f%%\n" , (float) (m1 + m2 + m3 + m4 + m5) / 500 * 100 );
		
		// Pause Screen
		System.out.printf("************************************************\n");
		pause();
	}
};


