var arr1 = ["A", 'a', 34, "58"];
var arr2 = ["B", 'a', 33, "58", 76, "A"];
var output = arr1;

// loop through the second array
for(var i =0; i < arr2.length; i++){
  // a boolean value to keep track of whether the element is already in the first array
  var flag = false;
  // loop through the first array
  for(var j = 0; j < arr1.length; j++){
    // if the elements of the 2 arrays are the same,
    if(arr2[i] === arr1[j]){
      // then set the flag to true
      flag = true;
    }
  }
  // after the loop, push the element if it wasn't repeated
  if(!flag){
    output.push(arr2[i]);
  }
}

// show the result to the screen
var result = "Final array is: ";
// loop through the elements of the output
for(var k = 0; k < output.length; k++){
  // add the current element to the result list
  result += output[k] + " ";
}

window.onload = function(){
  // change the html code
  document.getElementById("output").innerHTML = result;
}
