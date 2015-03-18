<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<title>HOME</title>
<meta name="" content="">
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
</head>

<body style="background-image:url(vnit1.jpg);background-repeat:no-repeat;background-position-left;background-color:skyblue; ">

<p style="margin-left:950px;color:orange;font-size:45px;"><big>TECHNOLOGY</big></p>;
<p style="margin-left:1020px;color:white;font-size:45px;margin-top:-60px;"><big>REVIEW</big></p>;
<p style="margin-left:1010px;color:green;font-size:45px;margin-top:-60px;"><big>AT VNIT</big></p>;

<p style="margin-left:1020px;color:violet;font-size:45px;"><a href="about.php"><dfn>ABOUT</dfn></a></p>
<p style="margin-left:1020px;color:violet;font-size:45px;"><a href="register.php"><dfn>REGISTRATION </dfn></a></p>
<p style="margin-left:1020px;color:violet;font-size:45px;"><a href="login.php"><dfn> LOGIN</dfn></a></p>
</body>
</html>
<?php
if(isset($_GET['id']))
{
    $id=$_GET['id'];
	require("connect.php");
	mysql_select_db("winter");
	$update=mysql_query("UPDATE table2 SET status=0 WHERE id='$id'" );
	
	
	
	
}




?>