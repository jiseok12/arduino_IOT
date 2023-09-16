<?php
if($_GET['ar']!=""){
file_put_contents('data/web',$_GET['ar']);
}
if($_GET['aram']!=""){
file_put_contents('data/aram2',$_GET['aram']);
}
?>