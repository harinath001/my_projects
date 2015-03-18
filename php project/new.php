<?php
$flag=1;
$name=strtoupper($_POST['name']);
$password1=$_POST['password1'];
$password2=$_POST['password2'];
$email=$_POST['email'];
$description=$_POST['info']; 
$research=$_POST['research'];

if(isset($_POST['papers']))
{
	

 $papers=$_POST['papers'];
}
else
{
	echo "PLEASE SELECT NUMBER OF RESEARCH PAPERS PRODUCED<br />";
	$flag=0;
}


/* if(isset($_POST['papers'])==0)
{
	echo "papers was not selected <br />";
	$papers = -1;
	$flag=0;
	
} */

require("connect.php");
	
	mysql_select_db("winter");

if(strlen($name)==0)
{
	echo "PLEASE ENTER YOUR NAME<br /> THIS WILL BE YOUR USERNAME<br />";
	$flag=0;
}


if(isset($_POST['gender']))
{
	

 $gender=$_POST['gender'];
}
else
{
	echo "PLEASE SELECT YOUR GENDER<br />";
	$flag=0;
}

	

 
if(isset($_POST['branch']))
{
	

 $branch=strtoupper($_POST['branch']);
}
else
{
	echo "PLEASE SELECT YOUR BRANCH<br />";
	$flag=0;
}
if(isset($_POST['qualification']))
{
	

 $qualification=$_POST['qualification'];
}
else
{
	echo "PLEASE SELECT YOUR QUALIFICATION<br />";
	$flag=0;
}


if(strlen($email)==0)
{
	
	echo "PLEASE ENTER YOUR EMAIL ID <br /> IF ANY PERSON WANT TO CONTACT YOU INFORMATION IS GIVEN TO THE EMAIL ID<br />";
	$flag=0;
	
}


/* if($papers==-1)
{
	
	echo "PLESE SELECT THE NUMBER OF RESEARCH PAPERS PRODUCED <br />";
	echo "IF YOU DIDN\'T SUBMIT ANY OF THEM JUST SELECT 0 IN THE OPTIONS<br />";
	$flag=0;
} */



if(strlen($description)<10 )
{
	
	echo "PLEASE GIVE INFORMATION ABOUT YOURSELF. SO THAT OTHERS COME TO ABOUT YOU<br />";
	$flag=0;
}
if($password1 != $password2)
{
	
	echo "PLEASE ENTER YOUR PASSWORD CAREFULLY <br /> PASSWORD CONFIRMATION FAILED<br />";
	$flag=0;
}
else
{
	if(strlen($password1)<5 || $password1 == $name)
	{
		
		echo "PLEASE SELECT STRONG PASSWORD <br /> YOUR PASSWORD STRENGTH IS WEEK AND EASILY PREDICTABLE<br />";
		$flag=0;
	}

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*if(strlen($research)< $papers*11)
{
	
	echo "PLEASE DESCRIBE ABOUT EACH RESEARCH PAPER IN ATLESAT 10 WORDS <br />";
	$flag=0;
} */

$extract = mysql_query("SELECT * FROM table2 WHERE name='$name'");//checking username availability
 
 $numrows = mysql_num_rows($extract);
 
if($numrows != 0)
{
   echo "THIS USERNAME IS ALREADY IN USE PLEASE TAKE ANOTHER AND TRY<br />";
   $flag=0;
}  


// $row=mysql_fetch_assoc($extract);
// echo "name: $row['name'] <br />";
// echo "id: $row['id']<br />";

if($flag != 0)
{
	
	echo "PLEASE CONFIRM THE DETAILS:<br />";
	echo "NAME: $name <br />";
	echo "BRANCH: $branch <br />";
	echo "GENDER: $gender <br />";
	echo "QUALIFICATION: $qualification<br />";
	
 
	$passwords=sha1($password1);//password encription
    
	$write = mysql_query("INSERT INTO table2 (id,name,username,gender,branch,qualification,password,description,email,papers,research)VALUES('','$name','$name','$gender','$branch','$qualification','$passwords','$_POST[info]','$email','$papers','$research')");
	

	echo "<br />";
	echo "<br />";
	echo "<br />";
	echo "ACCOUNT CREATED SUCCESSFULLY<br />";
	
}
else{
	echo "SO , <u>ACCOUNT WAS NOT CREATED</u>";
}

?>
<a href="login.php"><button name="continue" value="continue">LOGIN PAGE</button></a>
<a href="register.php"><button name="back" value="back" >BACK TO REGISTRATION</button></a>






