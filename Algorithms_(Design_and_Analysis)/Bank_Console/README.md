# Bank Console

Bank console is a console program build using procedural C programming - and a part of it using a Greedy approach to solving problems - as a project work conducted by Deogiri Institute of Engineering and Management Studies for 'Design and Analysis of Algorithm' subject.

                       **                         
                    ** ** **                      
                 ***        ***                   
              ***              ***                
           ***                    ***             
        ***                          ***          
     *** ** ************************ ** ***       
                                                  
        ****    ****         ****   ****          
         **      **           **     **           
         **      **           **     **           
         **      **           **     **           
         **      **           **     **           
         **      **           **     **        
        ****    ****         ****   ****          
                                                  
       **********************************         
     **************************************       

## 1. Getting Started

You can find [source code](https://github.com/s-m-quadri/DIEMS-Lab-Work/tree/main/Algorithms_(Design_and_Analysis)/Bank_Console) and the root [repository](https://github.com/s-m-quadri/DIEMS-Lab-Work) from which you can view as well as download the libraries and as project whole. You can clone it as,

    git clone https://github.com/s-m-quadri/DIEMS-Lab-Work.git

## 2. Usage

After cloning the project or source file navigate to,
[Algorithms_(Design_and_Analysis)](https://github.com/s-m-quadri/DIEMS-Lab-Work/tree/main/Algorithms_(Design_and_Analysis)/Bank_Console) > [Bank_Console](https://github.com/s-m-quadri/DIEMS-Lab-Work/tree/main/Algorithms_(Design_and_Analysis)/Bank_Console) > ...
making your current working directory. Now, Compile the code using

    gcc cs50.c bank.c token.c main.c

Now, simply run

    ./a.out 

can do (optionally) memory check using

    valgrind ./a.out 

or (optionally) time check using

    time ./a.out 

## 3. Documentation

    Command $: help

... to get the help

    Command $: login

... to proceed for login

    Command $: deposit (amount)
    e.g.    $: deposit 300

... will deposit 300 into the logged in account

    Command $: withdraw (amount)
    e.g.    $: withdraw 300

... will withdraw 300 from the logged in account

    Command $: withdraw cash (amount) (note-denom...) done
    e.g.    $: withdraw cash 300 100 50 done

... will withdraw 300 from the logged-in account in form of cash and will maximize the notes of denomination 100 then will maximize the notes of denomination 50. Afterwards, will calculate the optimal (here, minimum) number of notes to complete the withdrawn amount and give it to user.

    Command $: show

... to show the status of the logged in account

    Command $: logout

... to proceed for logout

    Command $: exit

... to terminate the console

## Thanks for visiting
