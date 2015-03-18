<head>
<style>
p{
	color:skyblue;
	font-size:30px;
}
q
{
	color:red;
	font-size:40px;
}

</style>

</head>


<body style="background-color:brown;">
<?php


if(isset($_POST['id']))
{

    
	require("connect.php");
	mysql_select_db("winter");
	
	$id=$_POST['id'];
	$extract=mysql_query("SELECT * FROM table2 WHERE id='$id'");
	$row=mysql_fetch_assoc($extract);
	$status=$row['status'];
	if($status==1)
	{
		
	
	$chat="chat".$id;
	
	
	
	echo" <form action=\"inbox.php\" method=\"POST\" style=\"margin-left:600px;font-size:40px;\">";
	echo" <input type=\"hidden\" name=\"id\" value=\"$id\"></input>";
	echo "<select name=\"till\" style=\"margin-left:400px;\">";
	echo "<option value=\"10\"/>RECENT 10 MESSAGES</option>";
	echo "<option value=\"0\"/>SHOW FROM STARTING</option>";
	echo "</select>";
	echo"<input type=\"submit\" name=\"submit\" style=\"font-size:30px;\" value=\"OK\"></input>";
	echo "</form>"; 
	
	if($extract=mysql_query("SELECT $chat FROM table2 WHERE id!=$id"))
	{
		$flag=1;
	}
	else
	{
		$flag=0;
	}
	

	$extract=mysql_query("SELECT * FROM table2 WHERE id!=$id");
	$k=0;
	
	while(($row=mysql_fetch_assoc($extract))&& $flag==1)
	{
	    $k++;
		$name=$row['name'];
		$array=$row[$chat];
		$array1=unserialize($array);
		$flag=1;
		$size=sizeof($array1);
		
		
         if(isset($_POST['till']))
	        {
	              $till=$_POST['till'];	
				 
				 
				  if($till==0)
				  {
				  	$till=$size;
				  }
		          $i=$size-$till;
				  if($i<0)
				  {
				  	$i=0;
				  }
	        }
          else{
		  	$i=0;
		  }
		
		
		
		if($array1[0]!="")
		{
		     echo "<q>FROM $name:</q><br />";
			while($i <$size)
		{
		     $message=$array1[$i];
		     if($message!="")
	     	{
			   
		    	echo "<p>$message</p><br />";
		    }
			
		
		    $i++;
		}
		}
		
		
		
		
		
	}
	if($k==0)
	{
		echo"<p style=\"color:red;font-size:40px;\">YOUR INBOX IS EMPTY<br /> TILL NOW NO ONE POSTED YOU ANYTHING<br /></p><br />";
	}
	 echo "<form action=\"verify.php\" method=\"POST\" style:\"align:center;\">";
		  echo "<input type=\"hidden\" name=\"key\" value=\"$id\"></input>";
		    
		  echo "<input type=\"submit\" name=\"submit\" value=\"BACK\"></input>";
		  echo "</form>";
		  
   }
   else
   {
   	echo "YOUR ACCOUNT IS NOW IN LOG OFF STATE <br /> PLEASE ENTER INTO YOUR ACCOUNT THROUGH A SECURE METHOD OF LOGIN<br />";
	require("login.php");
   }		  
	
}




?>
</body>