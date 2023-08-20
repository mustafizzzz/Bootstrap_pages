// Sepcial Count

let dayItem = document.querySelector("#days");
let hoursItem = document.querySelector("#hours");
let minItem = document.querySelector("#min");
let secItem = document.querySelector("#sec");

//Scrolltop To Top
const scrollTop = () => {
  let scrollTopButton = document.querySelector("#scrollup");
  window.onscroll = () => {
    var scroll = document.documentElement.scrollTop;
    if (scroll >= 250) {
      scrollTopButton.classList.add('scrollActive');

    } else {
      scrollTopButton.classList.remove('.scrollActive');

    }
  }
}

scrollTop();

let countDown = () => {
  let futureDate = new Date('23 July 2023');
  let currentDate = new Date();
  let myDate = futureDate - currentDate;

  let days = Math.floor(myDate / 1000 / 60 / 60 / 24);
  let hours = Math.floor(myDate / 1000 / 60 / 60) % 24;
  let min = Math.floor(myDate / 1000 / 60) % 60;
  let sec = Math.floor(myDate / 1000) % 60;


  dayItem.innerHTML = days;
  hoursItem.innerHTML = hours;
  minItem.innerHTML = min;
  secItem.innerHTML = sec;

}

countDown();

setInterval(countDown, 1000)