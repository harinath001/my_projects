

<body style="background-color:white;">
<?php
if(isset($_GET['id1']))
{
    
	 	$id1=$_GET['id1'];
        $id2=$_GET['id2'];
	 
	 
    require("connect.php");
	mysql_select_db("winter");
	
	
	$extract=mysql_query("SELECT * FROM table2 WHERE id='$id2'");
	$row=mysql_fetch_assoc($extract);
	$status=$row['status'];


if($status==1)
{
	

require("connect.php");
mysql_select_db("winter");
$extract=mysql_query("SELECT * FROM table2 WHERE id='$id1'");
$row = mysql_fetch_assoc($extract);
$name=$row['name'];
$branch=$row['branch'];
$qualification=$row['qualification'];
print "<b style=\"color:skyblue;font-size:50px;\">NAME:$name <br />QUALIFICATION: $qualification <br /> BRANCH: $branch <br \></b><br />";

echo "<br />";
echo "<br />";
echo "<br />";
echo "<b style=\"color:violet;font-size:40px;\">AND HIS DESCRIPTION ABOUT HIMSELF:</b><br />";
echo "<br />";
echo "<b style=\"color:red;font-size:30px;\">$row[description]</b><br />";
echo "<br />";
echo "<br />";
// echo "<p style=\"align:center;\"><button><a href=\"verify.php?key=$id2\"><b style=\"color:blue;font-size:25px;align:center;\">BACK</b> </a></button></p>" ;

 
 
 
	  echo "<form action=\"verify.php\" method=\"POST\">";
		  echo "<input type=\"hidden\" name=\"key\" value=\"$id2\"></input>";
		  
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK\" style=\"font-size:30px;align:\"left\"></input>";
		  echo "</form>";
		  
 
 
 
 
 
 


$extract = mysql_query("SELECT * FROM table2 WHERE id='$id2'");
	$row = mysql_fetch_assoc($extract);
$array = $row['array'];
	$array1=unserialize($array);
	$i=0;
	$flag=1;

while(($i < sizeof($array1)) && $flag==1)
{

	if($id1-$array1[$i]==0)
	{
		$flag=0;
		
	}
     
	$i++;
}

if($flag == 1)
{
	// echo "<p style=\"align:center;\"><button><a href=\"show.php?keyid=$id2&add=$id1\"><b style=\"color:blue;font-size:25px;align:center;\">ADD THIS PERSON TO YOUR LIST</b> </a></button></p>";///////////////////////////

             echo "<form action=\"show.php\" method=\"POST\">";
		  echo "<input type=\"hidden\" name=\"keyid\" value=\"$id2\"></input>";
		    echo "<input type=\"hidden\" name=\"add\" value=\"$id1\"></input>";
		  echo "<input type=\"submit\" name=\"submit\" value=\"ADD THIS PERSON TO YOUR CONTACT LIST\"></input>";
		  echo "</form>";
		  





}
else
{
	echo "<p style=\"font-size:40px;color:skyblue;\">THIS PERSON IS ALREADY IN YOUR CONTACT LIST</p><br />";
	echo "<a href=\"chat.php?id=$id2&to=$id1\"><p style=\"font-size:40px;color:orange;\"> START CHAT WITH THIS PERSON</p></a><br />";
}


}
}
if(isset($_POST['keyid']))
{
	$add=$_POST['add'];
	$key=$_POST['keyid'];
	require("connect.php");
mysql_select_db("winter");
	$extract = mysql_query("SELECT * FROM table2 WHERE id='$key'");
	$row = mysql_fetch_assoc($extract);
	$name= $row['name'];
	$papers= $row['papers'];
	$qualification=$row['qualification'];
	$branch = $row['branch'];
	$array = $row['array'];
	$array1=unserialize($array);
	if($array1 == "")
	{
		$array1[0]=$add;
	}
	else
	{
	     $i=0;
	    $flag=1;
         
        while(($i < sizeof($array1)) && $flag==1)
    {
	     
	     if($add-$array1[$i]==0)
	       {
		      $flag=0;
		
         	}
         
	     $i++;
     }
	    
	    if($flag==1)
		{
			$k=array_push($array1,$add);
		}
	
		
		
	}
	
	
	$array2=serialize($array1);
	$update = mysql_query("UPDATE table2 SET array='$array2' WHERE id='$key'");
	echo "<p style=\"font-size:40px;color:skyblue;\">THIS PERSON IS ADDED TO YOUR CONTACTS SUCCESSFULLY</p><br />";
	
	// print "<b style=\"color:skyblue;font-size:50px;\">NAME:$name <br />QUALIFICATION: $qualification <br /> BRANCH: $branch <br \></b><br />";
// echo "<p style=\"align:center;\"><button><a href=\"verify.php?key=$key\"><b style=\"color:blue;font-size:25px;align:center;\">BACK</b> </a></button></p>" ;
    
	  
	  echo "<form action=\"verify.php\" method=\"POST\">";
		  echo "<input type=\"hidden\" name=\"key\" value=\"$key\"></input>";
		  
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK\"></input>";
		  echo "</form>";
		  
	  
	  
	
	
/*	$l=0;
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
	
	
	
	}
	if(isset($_POST['keyid'])==0 && isset($_GET['id1'])==0 )
	{
		echo "YOUR ACCOUNT IS NOW IN LOG OFF STATE <br /> PLEASE ENTER INTO YOUR ACCOUNT THROUGH A SECURE METHOD OF LOGIN<br />";
	require("login.php");
	}












?>


</body>