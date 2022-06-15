// called by clicking button
function clicked () {
    var input_text = document.getElementById("input").value;
    alert("Value inside input field is: "+ input_text);
    console.log("From input field: "+input_text);
}

// called when hovered on paragraph
function hoverOnParagraph() {
    document.getElementById('paragraph').style.color = 'chocolate';
}

// called when hovered away from paragraph
function hoverOffParagraph() {
    document.getElementById('paragraph').style.color = 'black';
}

// called by clicking 'change background' button
function changeBackground() {
    document.getElementById('wrapper').style.backgroundColor = 'AntiqueWhite'
}

// called when page is loaded
function onLoadFunction() {
    document.getElementById('wrapper').style.backgroundColor = 'gray'
}