// By 5MQuadr! (s-m-quadri@github , 26107@diems2020-24)
// Last Updated on : 1st February 2022


	///////////////////////////////////////////////////////////////////////////////////////
	///                                   Override                                      ///
	///////////////////////////////////////////////////////////////////////////////////////


/*
	When a subclass inherits from a superclass, it also inherits its methods; however, it can
	also override the superclass methods (as well as declare and implement new ones). Consider the
	following Sports class:
		class Sports{ 
			String getName(){
				return "Generic Sports";
			}
			void getNumberOfTeamMembers(){
				System.out.println( "Each team has n players in " + getName() );
			}
		}
	Next, we create a Soccer class that inherits from the Sports class. We can override
	the getName method and return a different, subclass-specific string:
		class Soccer extends Sports{
			@Override
			String getName(){
				return "Soccer Class";
			}
		}
	Note: When overriding a method, you should precede it with the @Override annotation. The
	parameter(s) and return type of an overridden method must be exactly the same as those of the
	method inherited from the supertype.
	
	Task
		Complete the code in your editor by writing an overridden getNumberOfTeamMembers method
		that prints the same statement as the superclass' getNumberOfTeamMembers method, except
		that it replaces with (the number of players on a Soccer team).
		 Output Format
		    When executed, your completed code should print the following:
			 Generic Sports
			 Each team has n players in Generic Sports
			 Soccer Class
			 Each team has 11 players in Soccer Class
*/

import java.util.*;

class Main{
	///////////////////////////////////////////////////////////////////////////////////////
	///                             Solution Section                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	private static void solve(){
		Sports obj;
		obj = new Soccer();
		obj.getNumberOfTeamMembers();
	}
	
	private static class Sports{
		String getName(){
			return "Generic Sports";
		}
		void getNumberOfTeamMembers(){
			System.out.println( "Each team has n players in " + getName() );
		}
	}

	private static class Soccer extends Sports{
		@Override
		String getName(){
			return "Soccer Class";
		}
	}
	
	///////////////////////////////////////////////////////////////////////////////////////
	///                              Driver Function                                    ///
	///////////////////////////////////////////////////////////////////////////////////////
	public static void main(String args[]){
		try {
			solve();
		}
		catch(InputMismatchException e){
			System.out.println("Sorry! Input is not correct.");
		}
		catch(ArithmeticException e){
			System.out.println("Sorry! Something wrong with calculations.");
		}
		catch(ArrayIndexOutOfBoundsException e){
			System.out.println("Sorry! You have reached where you shouldn't.");
		}
		catch(Exception e){
			System.out.println("Sorry! Something went wrong.");
		}
		finally{
			System.out.println("The program is about to exit ! ");
		}
	}
}


