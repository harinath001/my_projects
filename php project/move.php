<?php

$a[0]="harinath";
$a[1]="gangadhar is playing volleyball";
$b=serialize($a);
$c=unserialize($b);
echo $c[1];



?>