<?php
// $key=$_GET['key'];
// echo "this is key $key <br />";
if(isset($_GET['key']))
{
	$id= $_GET['key'];
	require("connect.php");
	mysql_select_db("winter");
	$extract = mysql_query("SELECT * FROM table2 WHERE id='$id'");
	$row=mysql_fetch_assoc($extract);
	$array=$row['array'];
	$array1=unserialize($array);
	$i=0;
	while($array1[$i]!=NULL)
	{
		$extract = mysql_query("SELECT * FROM table2 WHERE id='$array[$i]' AND NOT id=$id");
		$row = mysql_fetch_assoc($extract);
		$name1=$row['name'];
		$branch1=$row['branch'];
		$qualification1=$row['qualification'];
		$description1=$row['description'];
		$papers1=$row['papers'];
		$research1=$row['research'];
		
		echo "NAME   :$name1<br /> ";
		echo "BRANCH   :$branch1<br /> ";
		echo "QUALIFICATION   :$qualification1<br /> ";
		echo "DESCRIPTION ABOUT THAT PERSON   :$description1<br /> ";
		if($papers1 !=0)
		{
			echo "NUMBER OF RESEARCH PAPERS PRODUCED  :$papers1<br /> ";
			echo "DESCRIPTION OF RESEARCH PAPERS  :$research1<br /> ";
		}
		else
		{
			echo"NO RESEARCH PAPERS PRODUCED <br />";
		}
		
	
	}
	
}
else
{
	echo "id was not set<br />";
}

?>