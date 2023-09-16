<?php
if($_GET['LED']=="ON"){
 file_put_contents('data/pin2',"1");
file_put_contents('data/pin3',"1");
file_put_contents('data/pin4',"1");
file_put_contents('data/pin5',"1");
}
else if($_GET['LED']=="OFF"){
file_put_contents('data/pin2',"0");
file_put_contents('data/pin3',"0");
file_put_contents('data/pin4',"0");
file_put_contents('data/pin5',"0");
}
?>
<html lang="ko">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <link rel="stylesheet"
        href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <title>Document</title>
    <style>
        .ko {
            font-size: 2.2rem;
            position: absolute;
            left: 84%;
            top: 30%;
        }

        .s {
            font-size: 2.2rem;
            position: absolute;
            left: 50%;
            top: 50%;
            transform: translate(-50%, -50%);
        }

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

        #me1 {
            font-size: 1.2rem;
            position: absolute;
            left: 6%;
            top: 50%;
            transform: translate(0%, -150%);
            color: black;
        }
        .sals{
            margin-bottom: 10%;
        }
    </style>
</head>

<body>
    <div>
        <span class="title">우리집 전력 관리</span>
    </div>
    <div class="tab">
        <h2 id="me1" onclick="changname1()" class="k">멀티탭1</h2>
        <h4>
<?php
if(file_get_contents('data/pin2')=="1"&&file_get_contents('data/pin3')=="1" && file_get_contents('data/pin4')=="1" && file_get_contents('data/pin5')=="1"){
echo "on";
}
else{
echo "off";
}
?></h4>
        <button class="k ON3" onclick="location.href='http://leejiseok.iptime.org:50/?LED=ON'">ON</button>
        <button class="k OFF3" onclick ="location.href='http://leejiseok.iptime.org:50/?LED=OFF'">OFF</button>
        <span class="material-symbols-outlined ko" onclick="location.href='./one.php'">
            settings
        </span>
    </div>
    <div class="tab sals">
        <span class="material-symbols-outlined s">
            add
        </span>
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
    <div class="changname1">
        <input type="text" id="txt1" class="modal1" value="" autofocus="true" />
        <button type="button" class="modals" onclick="save1()">확인</button>
        <button class="commit" onclick="back()">취소</button>
    </div>
    <script src="index.js"></script>
    <script>
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

    </script>
</body>

</html>
