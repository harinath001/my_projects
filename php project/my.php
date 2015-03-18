<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<title>variables</title>
<meta name="kanchu" content="harinath">
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
<style>
p
{
   font-size:40px;
   color:red;
}
body{
	
font-size:40px;
background-image:url(fb.jpg);
background-color:skyblue;
background-repeat:no-repeat;
background-position:650px;

}

</style>
</head>

<body>
<p>i am harinath </p>
<p>i am from vnit nagpur</p>

<?php 
  $a="harinath" ; 
  echo $a;
  echo "<br />";
 
  
 echo "<br />";
 $b=" kanchu";
  echo "i am $b" ;
  echo "<br />" ;
  $c = $a;
  $c .= $b;
  echo $c;
  echo "<br /> <br /> <br />" ;
  echo "<br />";
  $a=rand(1,100);
 // echo $a;
  echo "<br />";
  $a="kanchu";
  $k=array(1,"harinath","h",array("nath",$a,"nath"),5,"kill","ksadkf","sdf","sd","f","aaaa",0);
//  echo $k[1];
  $p=3.14;
  echo "$p" ;
   echo "<br />";
   echo $k[1];
    echo "<br />";
	echo $k[3][0];
 	print_r($k);  
	 echo "<br />";
	  echo "<br />";
	   echo "<br />"; 
	echo count($k);
	rsort($k);
	 echo "<br />";
	  echo "<br />";
	   echo "<br />";
	print_r($k);
	 echo "<br />";
	  echo "<br />";
	  echo max($k);
	  $a=array(100,10,20,50);
	   echo "<br />";
	   
	  echo min($a);
	   echo "<br />";
	   sort($a);
	 echo $string1=implode("loves",$a)  ;
	  echo "<br />";
	 print_r(explode("loves",$string1));
	 echo "<br />";
	echo $string1;
	 echo "<br />";
//	echo $a[1];
	 echo "<br />";
	echo in_array(1000,$a);
    $b1=TRUE;
	$b2=FALSE;
	//echo $b1;
	 echo "<br />";
	// echo $b1;
	 if($b1)
	 {
	 	
		echo "harinath i am there";
		echo "<br />";
		
	 }
	 else{
	 	echo "harinath i am hhhhhhhhhhhhhhhhhh";
		
	 }
	 
   ?>
 
 
</body>
<p>hai to all </p>
</html>