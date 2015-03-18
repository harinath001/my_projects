
<head>
<style>
k
{
color:skyblue;
	
	
}

</style>


</head>
<body style="background-color:green;">
<?php
require("connect.php");
mysql_select_db("winter");
if(isset($_POST['key'])==0)

{
	

$name1= $_POST['name'];
$password1= $_POST['password'];
$branch= strtoupper($_POST['branch']);
 $extract = mysql_query("SELECT * FROM table2 WHERE name='$name1'");
 
 $numrows = mysql_num_rows($extract);
 
 $row = mysql_fetch_assoc($extract);
 $id = $row['id'];
 
if($numrows==0)
{
   echo "PLEASE CHECK ONCE AGAIN !!!  <br /> YOUR USERNAME WAS NOT FOUND<br />";
}
else
{
   $password3=sha1($password1);
   if($row['password'] == $password3)
   {
   	 if($row['branch'] != $branch)
	 {
	 	
		echo "YOUR BRANCH SELECTION WAS WRONG <br />PLEASE SELECT THE CORRECT BRANCH <br />";
	 }
	 else{
	  
	 	$name1=strtoupper($name1);
	//	echo "<b style=\"color:orange;font-size:30px;margin-left:400px;\"> SUCCESSFUL LOGIN</b> <br />";
	
	  $update = mysql_query("UPDATE table2 SET status=1 WHERE id='$id'");
	
	echo	"<button style=\"font-size:30px;margin-left:600px;\"><a href=\"contacts.php?id=$id\">MY CONTACTS</a></button> <br />";
	
	
	echo" <form action=\"search.php\" method=\"POST\" style=\"margin-left:600px;font-size:40px;\">";
	echo "<input type=\"text\" name=\"search\"></input>";
	echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
	echo"<input type=\"submit\" name=\"submit\" style=\"font-size:30px;\" value=\"SEARCH\"></input>";
	echo "</form>";

	echo" <form action=\"inbox.php\" method=\"POST\" style=\"margin-left:600px;font-size:40px;\">";
	echo" <input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
	echo"<input type=\"submit\" name=\"submit\" style=\"font-size:30px;\" value=\"INBOX\"></input>";
	echo "</form>"; 
		echo " <b style=\"color:skyblue;font-size:30px;\"> WELCOME $name1</b> <br />";
		$extract = mysql_query("SELECT * FROM table2 WHERE branch='$branch' AND id!='$id'");
		echo "<br />";
		echo "<br />";
		
		echo "<b style=\"color:violet;font-size:30px;\">PEOPLE YOU MAY KNOW WHO ARE UNDER RESEARCH IN YOUR BRANCH</b><br />";
		echo "<br />";
		echo "<br />";
		echo "<br />";
		$k=0;
		while($row = mysql_fetch_assoc($extract))
		{
		
		    $k=$k+1;
               		
		
		    $id3 = $row['id'];
			
			$qualification = $row['qualification'];
			$name = $row['name'];
			$papers = $row['papers'];
			echo "<br />";
			echo "<br />";			
			echo "<a href=\"show.php?id1=$id3 & id2=$id\"><p style=\"color:red; font-size:40px; background-color:black;\"><k>NAME</k>:$name  <k>QUALIFICATION</k>:$qualification <k>NO. OF RESEARCH PAPERS PRODUCED:</k>$papers</p></a> <br />";
			
		}
		
		
		if($k==0)
		{
			echo "<p style=\"color:red;font-size:40px;\">THERE ARE NO MEMBERS REGISTERED WITH YOUR BRANCH<p><br />";
		}
		
	echo	"<button style=\"font-size:30px\"><a href=\"home.php?id=$id\">LOGOUT</a></button> <br />";
		
	 }
    	
   }
   else
   {
        echo "PLEASE CHECK YOUR PASSWORD<br /> YOUR PASSWORD WAS INCORRECT<br />";   	
   	
	
   }
} 
}
else
{
    $id = $_POST['key'];
//	$add = $_GET['add'];
//echo "<q margin-left:900px;> <button><a href=\"show2.php\"?key=$id>MY CONTACT LIST</a></button></q>";

echo" <form action=\"search.php\" method=\"POST\" style=\"margin-left:600px;font-size:40px;\">";
	echo "<input type=\"text\" name=\"search\"></input>";
	echo "<input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
	echo"<input type=\"submit\" name=\"submit\" style=\"font-size:30px;\" value=\"SEARCH\"></input>";
	echo "</form>";

echo	"<button style=\"font-size:30px;margin-left:600px;\"><a href=\"contacts.php?id=$id\">MY CONTACTS</a></button> <br />";
	
	
	
	echo" <form action=\"inbox.php\" method=\"POST\" style=\"margin-left:600px;font-size:40px;\">";
	echo" <input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
	echo"<input type=\"submit\" name=\"submit\" style=\"font-size:30px;\" value=\"INBOX\"></input>";
	echo "</form>"; 
	
	
	
	
	$extract = mysql_query("SELECT * FROM table2 WHERE id='$id'");
	$row = mysql_fetch_assoc($extract);
	$name= $row['name'];
	$papers= $row['papers'];
	$branch = $row['branch'];
	$array = $row['array'];
/*	$array1=unserialize($array);
	if($array1 == "")
	{
		$array1[0]=$id;
	}
	echo "this is array 1 which is unserialize of storage <br />"; 
	print_r($array1);
	echo "<br />";
	echo "<br />";
	echo "<br />";
	
	$l=0;
	while($array1[$l] != NULL)
	{
		$l++;
		echo "$array1[$l]<br />";
	}
	echo "the number of values in the array is $l <br />";
	if($array1[$l - 1]!=$add)
	{
		$k=array_push($array1,$add);
	}
	
	
	 // echo "the number of values in the array is $k <br />";

	$array2=serialize($array1);
	$update = mysql_query("UPDATE table2 SET array='$array2' WHERE id='$id'"); */
	
	echo "<script type=\"javascript/text\">alert(\"hi $name\")</script>";
	
	
	echo " <b style=\"color:skyblue;font-size:40px;\"> WELCOME \"$name\"</b> <br /> <br /> <br />";
	$extract = mysql_query("SELECT * FROM table2 WHERE branch='$branch' AND id!='$id'");
	echo "<b style=\"color:violet;font-size:30px;\">PEOPLE YOU MAY KNOW WHO ARE UNDER RESEARCH IN YOUR BRANCH :</br>";
	$k=0;
		while($row = mysql_fetch_assoc($extract))
		{
		    $k=$k+1;
		    $id3 = $row['id'];
			$qualification = $row['qualification'];
			$name = $row['name'];
			echo "<br />";
						
			//echo "<a href=\"show.php?id=$id2\"><p style=\"color:red; font-size:40px;\">$name $qualification</p></a> <br />";
			echo "<a href=\"show.php?id1=$id3 & id2=$id\"><p style=\"color:red; font-size:40px; background-color:black;\"><k>NAME:</k>$name <k>QUALIFICATION:</k>$qualification <k>NO.OF RESEARCH PAPERS PRODUCED:</k>$papers</p></a> <br />";
		}
		if($k==0)
		{
			echo "<p style=\"color:red;\">THERE ARE NO MEMBERS REGISTERED WITH YOUR BRANCH<p><br />";
		}
	
	echo	"<button style=\"font-size:30px\"><a href=\"home.php?id=$id\">LOGOUT</a></button> <br />";
	
}	
	

?>
</body>