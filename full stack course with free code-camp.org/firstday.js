let access = document.getElementById("access");
let button = document.getElementById("access2");

button.addEventListener("click", () => {
  if (access.value === "happy") {
    alert("stay similing 😍..");
    document.body.style.backgroundColor = "yellow";

  }
  else if (access.value === "sad") {
    alert("it's okay to feel sad 😥..");
    document.body.style.backgroundColor = "blue";
  }
  else if (access.value === "angry") {
    alert("take a deep breath 😣...");
    document.body.style.backgroundColor = "red";
  }
  else if (access.value === "tired") {
    alert("rest is important 🤢..");
    document.body.style.backgroundColor = "gray";
  }
});


