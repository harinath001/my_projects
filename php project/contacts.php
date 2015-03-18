



<head>
<style>
k
{
color:skyblue;
	
	
}

</style>


</head>

<body style="background-color:white;">

<?php

if(isset($_GET['id']) || isset($_POST['id'])) 
{
	
if(isset($_POST['id']))
{
	$id1=$_POST['id'];
}
if(isset($_GET['id']))
{
	$id1=$_GET['id'];
}


require("connect.php");
mysql_select_db("winter");
$extract=mysql_query("SELECT * FROM table2 WHERE id='$id1'");
$row = mysql_fetch_assoc($extract);
$name=$row['name'];
$branch=$row['branch'];
$array=$row['array'];
$status=$row['status'];
$qualification=$row['qualification'];
if($status==1)
{
	

$array1=unserialize($array);
$i=0;
$k=0;
while($i<sizeof($array1))
{
$extract=mysql_query("SELECT * FROM table2 WHERE id='$array1[$i]' AND NOT id='$id1'");
$row = mysql_fetch_assoc($extract);
$name=$row['name'];
if(strlen($name)!=0)
{
$k=$k+1;	
$branch=$row['branch'];
$qualification=$row['qualification'];   
$description=$row['description'];  
$research=$row['research'];
$papers =$row['papers'];
echo "<p style=\"font-size:30px;color:violet;\">";
echo "NAME:<k>$name</k> <br />";
echo "BRANCH:<k>$branch</k> <br />";
echo "QUALIFICATION:<k>$qualification</k> <br />";
echo "NUMBER OF RESEARCH PAPERS PRODUCEED:<k>$papers </k><br />";
echo "ABOUT RESEARCH PAPERS:<k>$research</> <br />";

echo "<a href=\"email.php?id=$id1&sendto=$array1[$i]\"<button style=\"left-margin:600px;\">SEND MAIL TO THIS PERSON</button></a><br />";
echo "<a href=\"chat.php?id=$id1&to=$array1[$i]\"<button style=\"left-margin:600px;\">START CHAT WITH THIS PERSON</button></a><br />";

}

$i++;
}
if($k==0)
{
	echo "<p style=\"color:red;\">YOUR CONTACT LIST IS EMPTY<br /><br />JUST ADD ANY PERSON TO WHOM YOU FEEL USEFUL IN YOUR RESEARCH<p><br />";
}
 // echo "<p style=\"align:center;\"><button><a href=\"verify.php?key=$id1\"><b style=\"color:blue;font-size:25px;align:center;\">BACK</b> </a></button></p>" ;

      echo "<form action=\"verify.php\" method=\"POST\" style:\"align:center;\">";
		  echo "<input type=\"hidden\" name=\"key\" value=\"$id1\"></input>";
		    
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK\"></input>";
		  echo "</form>";
		  



}
else
{
	echo "YOUR ACCOUNT IS NOW IN LOG OFF STATE <br /> PLEASE ENTER INTO YOUR ACCOUNT THROUGH A SECURE METHOD OF LOGIN<br />";
	require("login.php");
}
	
}
else

{
	echo"PLEASE LOGIN AND SEE YOUR CONTACTS<br />";
}
?>


</body>

