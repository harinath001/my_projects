<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<title>login page</title>
<meta name="" content="">
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
<style>
p
{
font-size:40px;
color:blue;

}
</style>
</head>
<?php

$flag=1;


require("connect.php");
	echo "<br />";
	mysql_select_db("winter");

$name=strtoupper($_POST['name']);

$branch=strtoupper($_POST['branch']);

$password1=$_POST['password1'];
$password2=$_POST['password2'];

if(isset($_POST['gender']))
{
	

 $gender=$_POST['gender'];
}
else
{
	echo "PLEASE SELECT YOUR GENDER<br />";
	$flag=0;
}


if(isset($_POST['qualification']))
{
	$qualification=$_POST['qualification'];
}
else
{
	
	echo "PLEASE SELECT YOUR QUALIFICATION <br />";
}


if($name=="")
{
	
	echo "PLEASE ENTER YOUR NAME <br />";
	$flag=0;
}

if( $branch=="")
{
	
	echo "PLEASE ENTER YOUR BRANCH <br />";
	$flag=0;
}

if( isset($_POST['gender'])==0)
{
	
	echo "PLEASE ENTER YOUR GENDER <br />";
	$flag=0;
}
if( isset($_POST['email'])==0)
{
	
	echo "PLEASE ENTER YOUR EMAIIL ID <br /> WHEN A PERSON CONTACTS YOU YOU RECEIVE A EMAIL FROM THAT PERSON<br />";
	$flag=0;
}
else{
	
	$email=$_POST['email'];
}
if((isset($_POST['qualfification']))==0)
{
	
	echo "PLEASE SELECT YOUR QUALIFICATION<br />";
	$flag=0;
}




if( $password1 != $password2 )
{
	
	echo "PLEASE CHECK THE PASSWORD <br /> PASSWORD CONFIRMATION FAILED <br />";
	$flag=0;
}
else
{
	if(strlen($password1)<5)
	{
		
		echo "PLEASE CHOOSE A STRONG PASSWORD";
		$flag=0;
	}
	if(strtoupper($password1)==$name)
	{
		
		echo "YOUR PASSWORD IS EASY TO GUESS <br /> PLEASE SELECT ANOTHER PASSWORD<br />";
		$flag=0;
	}
}


 $extract = mysql_query("SELECT * FROM table2 WHERE name='$name'");
 
 $numrows = mysql_num_rows($extract);
 
if($numrows!=0)
{
   echo "THIS USERNAME IS ALREADY IN USE PLEASE TAKE ANOTHER AND TRY<br />";
   $flag=0;
}

if($flag == 1)
{
	echo "PLEASE CONFIRM THE DETAILS:<br />";
	echo "NAME: $name <br />";
	echo "BRANCH: $branch <br />";
	echo "GENDER: $gender <br />";
	echo "QUALIFICATION: $qualification<br />";
	
 
	$passwords=sha1($password1);//password encription

	$write = mysql_query("INSERT INTO table2 VALUES('','$name','$name','$gender','$branch','$qualification','$passwords','$_POST[info]','$email','$research,'$papaers')");
	

	echo "<br />";
	echo "<br />";
	echo "<br />";
	echo "ACCOUNT CREATED SUCCESSFULLY<br /> <br /> <br />";
	echo "IF YOU WANT YOU CAN LOGIN NOW<br /><br />";
	require("login.php");
}
else{
	
	echo "<br />ACCOUNT WAS NOT CREATED <br />";
}

?>
<a href="login.php"><button name="continue" value="continue">LOGIN PAGE</button></a>
<a href="register.php"><button name="back" value="back" >BACK TO REGISTRATION</button></a>
<body>

</body>
</html>




