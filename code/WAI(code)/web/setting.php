<?php
if($_POST['data_hh']!="" && $_POST['data_mm']!="" && $_POST['data_hh2']!="" && $_POST['data_mm2']!=""){
   file_put_contents('data/hh', $_POST['data_hh']);
   file_put_contents('data/mm', $_POST['data_mm']);
   file_put_contents('data/hh2', $_POST['data_hh2']);
   file_put_contents('data/mm2', $_POST['data_mm2']); 
}

if($_GET['AI']=="ON"){
   file_put_contents('data/AI', "1");
}
else if($_GET['AI']=="OFF"){
   file_put_contents('data/AI', "0");
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
            width: 86%;
            margin: 1rem auto;
            color: black;
        }
        legend{
            border-radius: 10px;
            padding: 1.5% 2% 1.5% 2%;
            border: none;
            background-color: beige;
        }
        .time{
            height: 21%;
            position: relative;
        }
        .chadan{
            height: 16%;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        .ai{
            height: 19%;
            position: relative;
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
        #data_hh,#data_hh2,#data_mm,#data_mm2{
            width: 25%;
            background-color: beige;
            color: black;
            border: none;
            height: 18%;
        }
        label.off{
            position: absolute;
            left: 17%;
            top: 30%;
            width: 90%;
        }
        label.on{
            position: absolute;
            left: 17%;
            top: 60%;
            width: 90%;
        }
        label{
            font-size: 0.85rem;
        }
        .ONs{
            background-color: darkgreen;
            border-radius: 10px;
            width: 25%;
            height: 30%;
            position: absolute;
            top: 50%;
            left: 22%;
	    text-align:center;
        }
        .OFFs{
            background-color: darkgreen;
            border-radius: 10px;
            width: 25%;
            height: 30%;
            position: absolute;
            top: 50%;
            left: 53%;
            text-align:center; 		 
        }
        p{
            padding: 4%;
        }
	.psd{
	    margin:8% 0px 0px 0px;  
	}
.go{
text-align:center;
font-size:15pt;
text-decoration:none;
vertical-align:middle;
color:black;
}
a:visited{
color:black;
}
    </style>
</head>

<body>
    <span class="title">세부설정</span>
    <form method="POST" action="/setting.php">
        <fieldset class="time">
            <legend class="l1"><b>시간 설정</b></legend>
            <label for="odk" class="off">키는 시간
                <input id='data_hh' class="ok" type="text" name="data_hh"> <b>:</b>
                <input id='data_mm' class="ok" type="text" name="data_mm">
            </label>
            <br>
            <label for="odk" class="on">끄는 시간
                <input id='data_hh2' class="ok" type="text" name="data_hh2"> <b>:</b>
                <input id='data_mm2' class="ok" type="text" name="data_mm2">
            </label>
        </fieldset>
        <fieldset class="ai">
            <legend class="l3"><b>AI 자동모드</b></legend>
            <p>NWP 앱이 추천하는 전력량을 기준으로 전력이 자동으로 차단됩니다.</p>
           <a href="/setting.php?AI=ON" class="ONs go" style=""><p class="psd">ON</p></a>
            <a href="/setting.php?AI=OFF" class="OFFs go" style=""><p class="psd">OFF</p></a>
        </fieldset>
        <input type="submit" name="submit" class="bu">
    </form>
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
    <script>
        function timego() {
            let hh = document.getElementById('data_hh');
            let mm = document.getElementById('data_mm');
            let hh2 = document.getElementById('data_hh2');
            let mm2 = document.getElementById('data_mm2');
            location.href = 'http://192.168.0.21/save?hh=' + hh.value + '&mm=' + mm.value + '&hh2=' + hh2.value + '&mm2=' + mm2.value;
        }
    </script>
</body>

</html>
