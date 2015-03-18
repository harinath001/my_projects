<?php

if(isset($_POST['id']))
{
	$id=$_POST['id'];
	$search=$_POST['search'];
	if($search != "")
{
		
	
	require("connect.php");
	mysql_select_db("winter");
	$extract=mysql_query("SELECT * FROM table2 WHERE id=$id");
	$row=mysql_fetch_assoc($extract);
	 $branch=$row['branch'];
	
	$extract=mysql_query("SELECT * FROM table2 WHERE id != '$id' AND branch='$branch'");
	$k=0;
	
	while($row=mysql_fetch_assoc($extract))
	{
	    
	    $flag=1;
		$description=$row['description'];
		$research =$row['research'];
		$id1=$row['id'];
		$split1=explode(" ",$description);
		// echo $split1;
		$i=0;
		if(sizeof($split1)>0)
		{
		    $size=sizeof($split1);
			while($i<$size)
		{
			if($search==$split1[$i] || $search==strtoupper($split1[$i]) || $search==strtolower($split1[$i]))
			{
			    $k++;
				$flag=0;
				echo "<h1>YOUR KEY WORD WAS FOUND IN THE DESCRIPTION OF A PERSON IN YOUR BRANCH LIKE THIS:</h1><br /> <br /> <br /> /";
				echo "$description<br /> <br />";
				
				echo "<a href=\"show.php?id1=$id1 & id2=$id\">SHOW DETAILS</a><br />";
			}
			
			    $i++;	
			
			
		}
		}
		
		
		if($research != "NO NEED TO DESSCRIBE" && $flag==1)
		{
			$split1=explode(" ",$research);
			$i=0;
			if(sizeof($split1)>0)
			{
				
				
				$size=sizeof($split1);
				while($i<$size)
	      	{
			if($search==$split1[$i] || $search==strtoupper($split1[$i]) || $search==strtolower($split1[$i]))
		     	{
				$k++;
				echo "<h1>YOUR KEY WORD WAS FOUND IN THE DESCRIPTION OF A PERSON'S RESEARCH PAPERS IN YOUR BRANCH LIKE THIS:</h1><br />";
				$len=sizeof($research);
			
			   $research2= str_replace($split1[$i],"$split1[$i]",$research);
				echo "$research2<br /> <br />";
				
				echo "<a href=\"show.php?id1=$id1 & id2=$id\">SHOW DETAILS</a><br />";
			    }
			$i++;
		     }
				
				
				
				
			}
			
		}
		
		
		
		
	}
	if($k==0)
{
	echo "NO PERSON MENTIONED THIS KEY WORD IN HIS RECORDS <br />";
}
	
}
else
{
	echo "PLEASE ENTER A VALID WORD TO SEARCH <br />";
}	
}


else
{
	echo "PLEASE LOGIN";
	require("login.php");
	
}





?>