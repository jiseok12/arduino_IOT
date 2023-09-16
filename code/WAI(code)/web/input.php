<?php
file_put_contents('data/get', $_POST['apikey']);
file_put_contents('data/get2', $_POST['apikey2']);
echo $_POST['apikey'];
if($_POST['LED']!=""){
file_put_contents('data/pin2', $_POST['LED']);
}
if($_POST['aram']!=""){
file_put_contents('data/aram', $_POST['aram']);
}
?>
