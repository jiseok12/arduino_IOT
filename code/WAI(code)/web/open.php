<!-- 웹에 멀티탭 제어의 저장되어 있는 상태를 출력한다 !-->
<h1>
    <?php echo file_get_contents('data/pin1'); ?>
</h1>

<h2>
<?php echo file_get_contents('data/pin2'); ?>
</h2>

<h3>
<?php echo file_get_contents('data/pin3'); ?>
</h3>

<h4>
<?php echo file_get_contents('data/pin4'); ?>
</h4>

<h5>
<?php echo file_get_contents('data/pin5'); ?>
</h5>

<hh>
<?php echo file_get_contents('data/hh'); ?>
</hh>

<mm>
<?php echo file_get_contents('data/mm'); ?>
</mm>

<hh2>
<?php echo file_get_contents('data/hh2'); ?>
</hh2>

<mm2>
<?php echo file_get_contents('data/mm2'); ?>
</mm2>

<AI>
<?php echo file_get_contents('data/AI'); ?>
</AI>

<?php
if(file_get_contents('data/hh')==date("H")&&file_get_contents('data/mm')==date("i")){
file_put_contents('data/pin2',"1");
}
else if(file_get_contents('data/hh2')==date("H")&&file_get_contents('data/mm2')==date("i")){
file_put_contents('data/pin2',"0");
}
?>
