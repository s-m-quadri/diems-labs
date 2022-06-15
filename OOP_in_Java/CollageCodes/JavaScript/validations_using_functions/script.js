var name1 = document.getElementById("Name1");
var email = document.getElementById("Email");
var number = document.getElementById("Number");


function validateForm(event) {
    event.preventDefault();

    // this form validation is very basic exmaple just so you get idea 
    // we can use HTML5 validation or JavaScript validation using built-in utilities
    
    // --------- name validation -----------
    if(name1.value == null || name1.value === "")
        alert("Please Enter your name")
    else
        var validatedName = name1.value;
        

    // --------- email validation -----------
    // if(email.value == null || email.value === "" || (!email.value.endsWith("@gmail.com")))
    if (email.validity.typeMismatch)
    alert("Please Enter Valid Email")
    else 
    var validatedEmail = email.value;
    
        
    // --------- phone number validation -----------
    // we are assuming user will put only numbers here 
    //because to validate the phone number Regex will be much helpful
    if(number.value.length !== 10)
        alert("Please Enter Valid Phone Number of Size 10");
    else
        var validatedPhoneNumber = number.value;

    if(validatedName && validatedEmail && validatedPhoneNumber)
        alert("Form Validated!!")
        
}