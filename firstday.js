let btn = document.getElementById("coloring");
let id1 = document.getElementById("separate1");
let id2 = document.getElementById("separate2");
let id3 = document.getElementById("separate3");
let id4 = document.getElementById("separate4");
let id5 = document.getElementById("separate5");
let id6 = document.getElementById("separate6");
let id7 = document.getElementById("separate7");
btn.addEventListener("click", function (event) {
  event.preventDefault();



  if (id1.value === "" || id2.value === "" || id3.value === "" || id4.value === "") {

    alert("please fill the requirements");
    return;
  }


  if (!id5.checked && !id6.checked && !id7.checked) {
    alert("please select one field");
    return;
  }


  else {

    alert("form is submitted");
  }

})