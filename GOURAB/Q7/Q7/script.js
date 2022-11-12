
// Using Ajax to load the information form pets.json to the browser
let request = new XMLHttpRequest();
request.open("GET", "pets.json", true);

$(document).ready(function () {
  request.send();

  //receive response
  request.onload = function () {
    if (request.status === 200) {
      console.log(request.responseText);
      const obj = JSON.parse(request.responseText);
      console.log(obj);
      const pets = obj["pets"];

      for (let i in pets) {
        const divEl = document.createElement("div");
        divEl.classList.add("pet-box");
        const olEl = document.createElement("ol");
        const h2El = document.createElement("h2");
        h2El.classList.add("heading-secondary");
        h2El.innerText = "Pet " + i;

        for (let j in pets[i]) {
          const liEl = document.createElement("li");
          liEl.innerText = pets[i][j];
          olEl.append(liEl);
        }

        divEl.append(h2El);
        divEl.append(olEl);
        $(".section-main").append(divEl);
      }
    }
  };
});
