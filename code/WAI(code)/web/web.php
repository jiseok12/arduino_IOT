<?php
if(file_get_contents('data/nsafe')==1 && file_get_contents('data/aram')==1 && file_get_contents('data/aram2')==1){
echo "1";
}
else{
echo "0";
echo file_get_contents('data/nsafe');
echo file_get_contents('data/aram');
echo file_get_contents('data/aram2');
}
if(file_get_contents('data/aram')==0){
file_put_contents('data/aram2',"1");
}
?>
