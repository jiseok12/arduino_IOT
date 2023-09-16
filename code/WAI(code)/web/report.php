<html lang="ko">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet"
        href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
    <link rel="stylesheet" href="style.css">
    <script src="./index.js"></script>
    <title>Document</title>
    <style>
        .nkd {
            position: absolute;
            top: 58%;
            left: 50%;
            transform: translate(-50%, 0%);
            width: 50%;
            height: 12%;
            font-weight: 600;
            font-size: 1.2rem;
            background-color: darkcyan;
            border-radius: 10px;
            border: none;
        }

        .nkd1 {
            position: absolute;
            top: 77.5%;
            left: 50%;
            transform: translate(-50%, 0%);
            width: 50%;
            height: 12%;
            font-weight: 600;
            font-size: 1.2rem;
            background-color: darkcyan;
            border-radius: 10px;
            border: none;
        }

        .al {
            position: relative;
            margin-left: 50%;
            transform: translate(-49.5%, 0%);
            margin-top: 1.2rem;
            font-size: 30px;
            width: 87%;
            height: 80%;
            border-radius: 10px;
            background-color: darkgreen;
        }

        .money {
            position: absolute;
            top: 10%;
            line-height: 2.3rem;
            width: 100%;
            text-align: center;
            font-size: 0.8em;
        }

        .ik {
            position: absolute;
            top: 35%;
            line-height: 2.3rem;
            text-align: center;
            width: 100%;
            font-size: 0.8em;
        }

        .shere {
            display: none;
            width: 65%;
            height: 30%;
            border-color: aqua;
            border-radius: 15px;
            background-color: lightgreen;
            position: absolute;
            left: 50%;
            top: 35%;
            transform: translate(-50%, -50%);
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

        h4 {
            font-size: 1rem;
            position: absolute;
            left: 50%;
            top: 40%;
            transform: translate(-50%, -50%);
            width: 100%;
            text-align: center;
        }
    </style>
</head>

<body>
    <span class="title">전력 사용 리포트</span>
    <div class="al">
        <b class="money">오늘은 총 ~~~원을 <br>
            절약하였습니다.</b>
        <b class="ik">절약 대기전력 : ~~W</b>
        <button class="nkd" onclick="clip();">
            <span>공유하기</span>
        </button>
        <button class="nkd1" onclick="location.href='./jasehi.php'">
            <span>자세히보기</span>
        </button>
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
    <div class="shere">
        <h4>URL이 복사되었습니다.</h4>
        <button class="commit" onclick="back()">취소</button>
    </div>
    <script>

        function clip() {
            var url;
            var textarea = document.createElement("textarea");
            document.body.appendChild(textarea);
            url = window.document.location.href;
            textarea.value = url;
            textarea.select();
            document.execCommand("copy");
            document.body.removeChild(textarea);
            document.querySelector('.shere').style.display = 'block';
        }
        function back() {
            document.querySelector('.shere').style.display = 'none';
        }
    </script>
</body>

</html>
