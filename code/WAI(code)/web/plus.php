<?php
if($_GET['nsafe']!=""){
if($_GET['nsafe']=="ON"){
file_put_contents('data/nsafe',"1");
file_put_contents('data/aram2',"1");
}
else{
file_put_contents('data/nsafe',"0");
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
        fieldset{
            background-color: greenyellow;
            border: none;
            border-radius: 10px;
            width: 90%;
            margin: 1rem auto;
            color: black;
            position: relative;
        }
        legend{
            border-radius: 10px;
            padding: 1.5% 2% 1.5% 2%;
            border: none;
            background-color: beige;
        }
        p.safe{
            font-size: 1.3em;
            margin: 2% 2% 1.5% 3%;
        }
        p{
            font-size: 1.55em;
            line-height: 1.2rem;
        }
        .bu{
            border-radius: 10px;
            position: absolute;
            top: 85.5%;
            left: 50%;
            transform: translate(-50%,-50%);
            width: 30%;
            height: 7%;
        }
        .noin{
            width: 85%;
            height: 30%;
        }
        .safe{
            width: 85%;
            height: 30%;
        }
        .ONs{
            background-color: darkgreen;
            border-radius: 10px;
            width: 20%;
            height: 20%;
            position: absolute;
            top: 65%;
            left: 22%;
        }
        .OFFs{
            background-color: darkgreen;
            border-radius: 10px;
            width: 20%;
            height: 20%;
            position: absolute;
            top: 65%;
            left: 53%;
        }
        p{
            padding: 4% 4% 4% 7%;
        }
        label[for="odk"]{
            font-size: 0.85rem;
            position: absolute;
            left: 17%;
            top: 40%;
        }
        input{
            width: 85%;
            color: black;
            border: none;
            height: 18%;
            margin-top: 2px;
        }
    </style>
</head>

<body>
    <span class="title">부가기능</span>
    <form>
        <fieldset class="noin">
            <legend><b>독거인 안심 모드</b></legend>
            <p>일정 시간 동안 정상적인 전력사용이 감지되지 않을 경우 보호자에게 알림을 보냅니다.</p>
            <a href="/plus.php?nsafe=ON"><button class="ONs">ON</button></a>
            <a href="/plus.php?nsafe=OFF"><button class="OFFs">OFF</button></a>
        </fieldset>
    </form>
    <form>
        <fieldset class="safe">
            <legend><b>세이프홈 모드</b></legend>
            <p class="safe">지정된 시간 동안 비정상적인 전력 사용이 감지될 경우 관리자에게 알림을 보냅니다.</p>
            <a href=""><button class="ONs">ON</button></a>
            <a href=""><button class="OFFs">OFF</button></a>
        </fieldset>
    </form>
    <a href=""><button class="bu">완료</button></a>
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
</body>

</html>
