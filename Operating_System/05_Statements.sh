#!/bin/sh


# Bash script for illustration of if..then..elif..then...fi, 
# if..then..fi, if..then..else..then..fi,
# for...do...done etc...

 
# Get the input
echo "Enter your name please : ";
read NAME;
echo "Hello $NAME, nice to meet you!";

# Know the choice
echo "Do you like tables? (yes/no)"
read CH;

# Proceed for choice
case "$CH" in
"yes")
    # If yes get the input
    echo "Nice, I'll print one, any favorite number? (enter natural number)"
    read NUM;
    
    # Check for input
    if (( $NUM < 0 ))
    then
        echo "Sorry! can't work for it."
        echo "We'll meet later. Thank you!"
        exit
    elif (( $NUM == 0 ))
    then
        echo "Hmmm! it's zero, Every calculation yeild in zero"
        echo "We'll meet later. Thank you!"
        exit
    fi
    
    # Print the table
    for i in {1..10}
    do
        echo "$NUM x $i = $(( $NUM * $i ))"
    done
;;
*)
    echo "What about hometown city? (enter name of city)"
    read CITY
    case "$CITY" in
    "aurangabad")
        echo "Oh! same hometown"
    ;;
    "parbhani")
        echo "Oh! Near... near to my hometown"
    ;;
    *)
        echo "Hmm! some other city"
    ;;
    esac
    # If no prompt and done
    echo "Okay! we'll meet later. Thank you!"
;;
esac
 


