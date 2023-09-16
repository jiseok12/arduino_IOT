<?php
$on=$_GET['LED'];
if($on!=""){
if($on=="LEDON"){
file_put_contents('data/pin2',"1");
file_put_contents('data/pin3',"1");
file_put_contents('data/pin4',"1");
file_put_contents('data/pin5',"1");

}
else if($on=="LEDOFF"){
file_put_contents('data/pin2',"0");
file_put_contents('data/pin3',"0");
file_put_contents('data/pin4',"0");
file_put_contents('data/pin5',"0");
}
else if($on=="LED1ON"){
file_put_contents('data/pin2',"1");
}
else if($on=="LED1OFF"){
file_put_contents('data/pin2',"0");
}
else if($on=="LED2ON"){
file_put_contents('data/pin3',"1");
}
else if($on=="LED2OFF"){
file_put_contents('data/pin3',"0");
}
else if($on=="LED3ON"){
file_put_contents('data/pin4',"1");
}
else if($on=="LED3OFF"){
file_put_contents('data/pin4',"0");
}
else if($on=="LED4ON"){
file_put_contents('data/pin5',"1");
}
else if($on=="LED4OFF"){
file_put_contents('data/pin5',"0");
}
}
?>
<html lang="ko">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet"
        href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <link rel="stylesheet" href="style.css">
    <title>Document</title>
    <style>
  .changname1 {
            border: 10px black;
        }

        button.modals {
            width: 30%;
            height: 25px;
            position: absolute;
            left: 36.5%;
            top: 50%;
            border-radius: 10px;
            background-color: green;
        }

        input.modal {
            width: 75%;
            height: 25px;
            position: absolute;
            left: 13.5%;
            top: 25%;
            border: 0;
            border-radius: 10px;
            background-color: green;
            height: 10%;
            font-size: 1.5em;
        }

        .commit {
            width: 30%;
            height: 25px;
            position: absolute;
            left: 36.5%;
            top: 65%;
            border-radius: 10px;
            background-color: green;
        }

        .ON1,
        .OFF1 {
            border-radius: 10px;
            width: 30%;
            background-color: chartreuse;
            height: 5%;
        }

        .ON1 {
            position: absolute;
            left: 15%;
            margin-top: 5%;
        }

        .OFF1 {
            position: absolute;
            left: 55%;
            margin-top: 5%;
        }

        .s {
            font-size: 2.2rem;
            position: absolute;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
        }

        .sals {
            margin-bottom: 10%;
        }
    </style>
</head>

<body>
    <div>
        <span class="title">전체 온오프</span>
        <a href="one.php?LED=LEDON"><button class="ON1">ON</button></a>
        <a href="one.php?LED=LEDOFF"><button class="OFF1">OFF</button></a>
    </div>
    <div class="tab yu">
        <h2 id="me4" onclick="changname4()" class="k">콘센트1</h2>
        <h4>
<?php
if(file_get_contents('data/pin2')=="1"){
echo "on";
}
else{
echo "off";
}
?>
</h4>
        <button onclick="location.href='one.php?LED=LED1ON'" class="k ON3">ON</button>
        <button class="k OFF3" onclick="location.href='one.php?LED=LED1OFF'">OFF</button>
        <span class="material-symbols-outlined ko" onclick="location.href='./setting.php'">
            settings
        </span>
    </div>
    <div class="tab t">
        <h2 id="me5" onclick="changname5()" class="k">콘센트2</h2>
        <h4><?php
	if(file_get_contents('data/pin3')=="1"){
	echo "on";
	}
	else{
	echo "off";
	}?>
	</h4>
        <button onclick="location.href='one.php?LED=LED2ON'" class="k ON3">ON</button>
        <button class="k OFF3" onclick="location.href='one.php?LED=LED2OFF'">OFF</button>
        <span class="material-symbols-outlined ko" onclick="location.href='./setting.php'">
            settings
        </span>
    </div>
    <div class="tab t">
        <h2 id="me6" onclick="changname6()" class="k">콘센트3</h2>
        <h4><?php
if(file_get_contents('data/pin4')=="1"){
echo "on";
}
else{
echo "off";
}
?>
</h4>
        <button type="button"onclick= "location.href='one.php?LED=LED3ON'" class="k ON3">ON</button>
        <button class="k OFF3" onclick="location.href='one.php?LED=LED3OFF'">OFF</button>
        <span class="material-symbols-outlined ko" onclick="location.href='./setting.php'">
            settings
        </span>
    </div>
   <div class="tab t sals">
        <h2 id="me7" onclick="changname7()" class="k">콘센트4</h2>
        <h4><?php
             if(file_get_contents('data/pin5')=="1"){
             echo "on";
             }
             else{
             echo "off";
             }
             ?></h4>
        <button type="button" onclick="location.href='one.php?LED=LED4ON'" class="k ON3">ON</button>
        <button class="k OFF3" onclick="location.href='one.php?LED=LED4OFF'">OFF</button>
        <span class="material-symbols-outlined ko" onclick="location.href='./setting.php'">
            settings
        </span>
    </div>
    <div class="changname4">
        <input type="text" id="txt4" class="modal1" value="" autofocus="true" />
        <button type="button" class="modals" onclick="save4()">확인</button>
        <button class="commit" onclick="back2()">취소</button>
    </div>
    <div class="changname5">
        <input type="text" id="txt5" class="modal1" value="" autofocus="true" />
        <button type="button" class="modals" onclick="save5()">확인</button>
        <button class="commit" onclick="back2()">취소</button>
    </div>
    <div class="changname6">
        <input type="text" id="txt6" class="modal1" value="" autofocus="true" />
        <button type="button" class="modals" onclick="save6()">확인</button>
        <button class="commit" onclick="back2()">취소</button>
    </div>
    <div class="changname7">
        <input type="text" id="txt7" class="modal1" value="" autofocus="true" />
        <button type="button" class="modals" onclick="save7()">확인</button>
        <button class="commit" onclick="back2()">취소</button>
    </div>
    <div id="head-menu" role="navigation" style="height: 50px;">
        <div class="material-symbols-outlined a" onclick="location.href ='./index.php'">
            home
        </div>
        <div class="material-symbols-outlined a" onclick="location.href ='./plus.php'">
            add
        </div>
        <div class="material-symbols-outlined a" onclick="location.href ='./report.php'">
            compost
        </div>
        <div class="material-symbols-outlined a" onclick="location.href ='./setting_two.php'">
            settings
        </div>
    </div>
    <script src="index.js"></script>
    <script>
        function init4() {
            let val = localStorage.getItem("myVal4");

            if (val == null || val == undefined) {
                val = '콘센트1';
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
                val = '콘센트2';
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
                val = '콘센트3';
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
                val = '콘센트4';
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
    </script>
</body>

</html>
