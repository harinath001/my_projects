<?php

if(isset($_GET['id'])&& isset($_GET['to']))
{
	
	$id=$_GET['id'];
	$to=$_GET['to'];
}	

if(isset($_POST['id']) && isset($_POST['to']))
	{
		$id=$_POST['id'];
	$to=$_POST['to'];

	}
	require("connect.php");
mysql_select_db("winter");
$extract=mysql_query("SELECT * FROM table2 WHERE id='$id'");
$row = mysql_fetch_assoc($extract);
$status=$row['status'];
if($status==1)
{
	

	
	if(isset($_GET['id'])&& isset($_GET['to']))
{
	echo "<form action=\"chat.php\" method=\"POST\">";
       echo "<fieldset><legend align=\"center\"><p style=\"color:skyblue;\">mesage</p></legend>" ;		
	echo"	<p>  YOUR MESSAGE:<textarea name=\"message\" rows=\"5\" cols=\"50\"></textarea></p><br />";
		echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
		echo "<input type=\"hidden\" name=\"to\" value=\"$to\"></input>";
		echo "<p><input type=\"submit\" name=\"submit\" value=\"submit\"></input>";
        echo "</fieldset>";
		echo "</form>";
	
}	

	   
	   
		
		
	
	if(isset($_POST['message']))
	{
		$message=$_POST['message'];
		$id=$_POST['id'];
		$to=$_POST['to'];
		
		if(strlen($message)==0)
		{
			echo "EMPTY MESSAGES ARE NOT ALLOWED<br />";
			echo "<form action=\"chat.php\" method=\"GET\">";
		  echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
		    echo "<input type=\"hidden\" name=\"to\" value=\"$to\"></input>";
		  echo "<input type=\"submit\" name=\"submit\" value=\"MESSAGE AGAIN\"></input>";
		  echo "</form>";
		  
		  
		  
		  
		  echo "<form action=\"contacts.php\" method=\"POST\">";
		  echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK TO THE CONTACTS\"></input>";
		  echo "</form>";
		  
		  
			
		}
		else
		{
			
		 
		   
		   require("connect.php");
         	mysql_select_db("winter");
		   $chat="chat".$to;
		   if($extract=mysql_query("SELECT $chat FROM table2 WHERE id=$id"))
        	{
	    	$flag=1;
		
         	}
	      
        	else{
	        	mysql_query("ALTER TABLE table2 ADD $chat LONGTEXT NOT NULL AFTER ID");
	         	$flag=1;
		
	          }
	
	if($flag==1)
	{
		$extract=mysql_query("SELECT * FROM table2 WHERE id=$id");
		$row=mysql_fetch_assoc($extract);
		
		$array=$row[$chat];
	
		$array1=unserialize($array);
	   $size=sizeof($array1);
	  
	   if($array1=="")
	   {
	   	$array1[0]=$message;
	   }
	   else
	   {
	
	   $k=array_push($array1,"$message");
	   }
	
	   $array2=serialize($array1);
	   $array3=unserialize($array2);
	   print_r($array3);
	   $update = mysql_query("UPDATE table2 SET $chat='$array2' WHERE id='$id'");
	   
		  echo "YOUR MESSAGE WAS SUCEESSFULLY SENT<br />";	
		  echo "<form action=\"contacts.php\" method=\"POST\">";
		  echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK TO THE CONTACTS\"></input>";
		  echo "</form>";
		  
		  
		   echo "<form action=\"chat.php\" method=\"GET\">";
		  echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
		    echo "<input type=\"hidden\" name=\"to\" value=\"$to\"></input>";
		  echo "<input type=\"submit\" name=\"submit\" value=\"MESSAGE AGAIN\"></input>";
		  echo "</form>";
		} 
	
    }
	
	
 }	
 }
 else
 {
 	echo "YOUR ACCOUNT IS NOW IN LOG OFF STATE <br /> PLEASE ENTER INTO YOUR ACCOUNT THROUGH A SECURE METHOD OF LOGIN<br />";
	require("login.php");
 }
			

	

	



?>