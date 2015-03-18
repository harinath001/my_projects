<?php
 
if(isset($_GET['id']) && isset($_GET['sendto']) && isset($_GET['success'])==0)
{   
    $id=$_GET['id'];
	$sendto=$_GET['sendto'];
	require("connect.php");
	mysql_select_db("winter");
	$extract=mysql_query("SELECT * FROM table2 WHERE id=$id");
	$row=mysql_fetch_assoc($extract);
	$name1=$row['name'];
	$from=$row['email'];
	
	$extract=mysql_query("SELECT * FROM table2 WHERE id=$sendto");
	$row=mysql_fetch_assoc($extract);
	$name=$row['name'];
	$to=$row['email'];
   echo " FROM : $name1 <br />";
	echo "TO : $name ($to) <br />";
	echo "<form action=\"email.php?id=$id &sendto=$sendto\" method=\"GET\">";
	echo "<fieldset><legend align=\"center\"><p style=\"color:skyblue;\">SUBJECT</p></legend>" ;
	echo "SUBJECT:<br />";
	echo "<textarea name=\"subject\" rows=\"5\" cols=\"50\"></textarea> <br />";
	
	

	echo "MESSAGE:<br />";
	echo "<textarea name=\"success\" rows=\"10\" cols=\"100\"></textarea>";
	echo "</fieldset>";
	echo "<input type=\"submit\" name=\"submit\" value=\"SEND MAIL\"></input>";
	
	echo "</form>";
}
if(isset($_POST['success']))
{   



   $id=$_GET['id'];
	$sendto=$_GET['sendto'];
	require("connect.php");
	mysql_select_db("winter");
	$extract=mysql_query("SELECT * FROM table2 WHERE id=$id");
	$row=mysql_fetch_assoc($extract);
	$name1=$row['name'];
	$from=$row['email'];
	
	$extract=mysql_query("SELECT * FROM table2 WHERE id=$sendto");
	$row=mysql_fetch_assoc($extract);
	$name=$row['name'];
	$to=$row['email'];








  	$mail=$_GET['success'];
	$subject=$_GET['subject'];
	if(strlen($mail) ==0)
	{
		echo "EMPTY MAILS ARE NOT PERMITTED <br />";
	}
	
}

?>