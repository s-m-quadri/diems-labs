// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated On : 12th December 2021


// #########################
//     Header Section
// #########################
#include <stdio.h>
// Order is important. "to use below, define above"
struct ofPersonal{
	char name[50];
	int id;
};
struct ofSalary{
	int amount_monthly;
	int attendance_monthly[12];
};
struct ofEmployee {
	struct ofPersonal personal;
	struct ofSalary salary;
};
void get_employee(struct ofEmployee *employee , int count);
void display_employee(struct ofEmployee *employee , int count);


// #########################
//       Main Section
// #########################
int main(){
	// Getting size << IMP
	printf("🔸️ How many employees are there in the company : ");
	int size = 0;
	scanf("%d" , &size);
	
	// Error checking  << Optional
	if (size <= 0) {
		printf("Sorry ! Not a single employee in the company !\n");
		return 0;
	}
	
	// Declaring employee(s) << IMP
	struct ofEmployee employee[size];
	
	// Getting Details from user << IMP
	get_employee(employee , size);
	
	// Displaying << IMP
	display_employee(employee , size);
	
	// Done !
	return 0;
}


// #########################
//   Definition Section
// #########################
void get_employee(struct ofEmployee *employee , int count){
	// Get details from user
	for (int i = 0 ; i < count ; i++){
		// Get personal details
		printf("🔸️ Enter the details of employee %02d \n",i+1);
		printf("\t🔹️ Full name      \t: ");
		scanf(" %[^\n]%*c" , employee[i].personal.name);
		printf("\t🔹️ ID number      \t: ");
		scanf("%d" , &employee[i].personal.id);
		// Get salary details
		printf("\t🔹️ Monthly salary \t: Rs. ");
		scanf("%d" , &employee[i].salary.amount_monthly);
		// Get attendance
		printf("\t🔹️ Monthly attendance \n");
		printf("\n");
		printf("\t                         |<-------write in sequence------->| \n");
		printf("\n");
		printf("\t                        Jan   Mar   May   Jul   Sep   Nov    \n");
		printf("\t                         | Feb | Apr | Jun | Aug | Oct | Dec \n");
		printf("\t                         |  |  |  |  |  |  |  |  |  |  |  |  \n");
		printf("\t                         v  v  v  v  v  v  v  v  v  v  v  v  \n");
		printf("\t           Maximum  :    31-28-31-30-31-30-31-31-30-31-30-31 \n");
		printf("\t        Attendance  :    ");
		scanf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-%d"
			, &employee[i].salary.attendance_monthly[0]
			, &employee[i].salary.attendance_monthly[1]
			, &employee[i].salary.attendance_monthly[2]
			, &employee[i].salary.attendance_monthly[3]
			, &employee[i].salary.attendance_monthly[4]
			, &employee[i].salary.attendance_monthly[5]
			, &employee[i].salary.attendance_monthly[6]
			, &employee[i].salary.attendance_monthly[7]
			, &employee[i].salary.attendance_monthly[8]
			, &employee[i].salary.attendance_monthly[9]
			, &employee[i].salary.attendance_monthly[10]
			, &employee[i].salary.attendance_monthly[11]
			);	
		printf("\n");
	}
}

void display_employee(struct ofEmployee *employee , int count){
	printf("\n Now ...\n Displaying The Details ... \n");
	for(int i = 0 ; i < count ; i++){
		// Calculations
		int max_salary = employee[i].salary.amount_monthly * 12;
		int max_attendance = 365;
		int your_attendace = 0;
		for (int j = 0 ; j < 12 ; j++) your_attendace += employee[i].salary.attendance_monthly[j];
		int your_salary = your_attendace * max_salary / max_attendance;
		
		// Displaying
		printf("\n🔸️%02d🔸️ %s (ID%d)\n" , i+1 , employee[i].personal.name , employee[i].personal.id);
		printf("\t       Maximum Annual Salary 🔹️ Rs. %d /-   \n" , max_salary);
		printf("\t      Number of Working Days 🔹️ %d out of %d\n" , your_attendace , max_attendance);
		printf("\t --------------------------------------------------- \n");
		printf("\t           Your total salary 🔸️ Rs. %d /-   \n" , your_salary);
		printf("\n");
	}
	
}
