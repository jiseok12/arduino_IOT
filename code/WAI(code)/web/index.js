function changname1() {
    document.querySelector('.changname1').style.display = 'block';
}
function changname2() {
    document.querySelector('.changname2').style.display = 'block';
}
function changname3() {
    document.querySelector('.changname3').style.display = 'block';
}
function changname4() {
    document.querySelector('.changname4').style.display = 'block';
}
function changname5() {
    document.querySelector('.changname5').style.display = 'block';
}
function changname6() {
    document.querySelector('.changname6').style.display = 'block';
}
function changname7() {
    document.querySelector('.changname7').style.display = 'block';
}
function back() {
    document.querySelector('.changname1').style.display = 'none';
    document.querySelector('.changname2').style.display = 'none';
    document.querySelector('.changname3').style.display = 'none';
    document.querySelector('.changname4').style.display = 'none';
    document.querySelector('.changname5').style.display = 'none';
    document.querySelector('.changname6').style.display = 'none';
    document.querySelector('.changname7').style.display = 'none';
    document.querySelector('.shere').style.display = 'none';
}




function init1() {
    let val = localStorage.getItem("myVal1");

    if (val == null || val == undefined) {
        val = '멀티탭1';
    }

    document.getElementById("txt1").value = val;
    document.getElementById("me1").textContent = val;
}

function save1() {
    localStorage.setItem("myVal1", document.getElementById("txt1").value)
    document.querySelector('.changname1').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt1").value;
    document.getElementById("me1").textContent = name;
}

init1();

function init2() {
    let val = localStorage.getItem("myVal2");

    if (val == null || val == undefined) {
        val = '멀티탭2';
    }

    document.getElementById("txt2").value = val;
    document.getElementById("me2").textContent = val;
}

function save2() {
    localStorage.setItem("myVal2", document.getElementById("txt2").value)
    document.querySelector('.changname2').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt2").value;
    document.getElementById("me2").textContent = name;
}

init2();

function init3() {
    let val = localStorage.getItem("myVal3");

    if (val == null || val == undefined) {
        val = '멀티탭3';
    }

    document.getElementById("txt3").value = val;
    document.getElementById("me3").textContent = val;
}

function save3() {
    localStorage.setItem("myVal3", document.getElementById("txt3").value)
    document.querySelector('.changname3').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt3").value;
    document.getElementById("me3").textContent = name;
}

init3();


function init4() {
    let val = localStorage.getItem("myVal4");

    if (val == null || val == undefined) {
        val = '콘센트4';
    }

    document.getElementById("txt4").value = val;
    document.getElementById("me4").textContent = val;
}

function save4() {
    localStorage.setItem("myVal4", document.getElementById("txt4").value)
    document.querySelector('.changname4').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt4").value;
    document.getElementById("me4").textContent = name;
}

init4();

function init5() {
    let val = localStorage.getItem("myVal5");

    if (val == null || val == undefined) {
        val = '콘센트5';
    }

    document.getElementById("txt5").value = val;
    document.getElementById("me5").textContent = val;
}

function save5() {
    localStorage.setItem("myVal5", document.getElementById("txt5").value)
    document.querySelector('.changname5').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt5").value;
    document.getElementById("me5").textContent = name;
}

init5();

function init6() {
    let val = localStorage.getItem("myVal6");

    if (val == null || val == undefined) {
        val = '콘센트6';
    }

    document.getElementById("txt6").value = val;
    document.getElementById("me6").textContent = val;
}

function save6() {
    localStorage.setItem("myVal6", document.getElementById("txt6").value)
    document.querySelector('.changname6').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt6").value;
    document.getElementById("me6").textContent = name;
}

init6();

function init7() {
    let val = localStorage.getItem("myVal7");

    if (val == null || val == undefined) {
        val = '콘센트7';
    }

    document.getElementById("txt7").value = val;
    document.getElementById("me7").textContent = val;
}

function save7() {
    localStorage.setItem("myVal7", document.getElementById("txt7").value)
    document.querySelector('.changname7').style.display = 'none';
    //self.location.reload(true);
    let name = document.getElementById("txt7").value;
    document.getElementById("me7").textContent = name;
}

init7();



function back2() {
    document.querySelector('.changname4').style.display = 'none';
    document.querySelector('.changname5').style.display = 'none';
    document.querySelector('.changname6').style.display = 'none';
    document.querySelector('.changname7').style.display = 'none';
}