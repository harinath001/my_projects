<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">

<html>

<head>

<title></title>

<meta name="" content="">

<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">

</head>

<body>


<p>


<?php

if(isset($_POST['papers'])==0)
{
	$papers="";
	
}
else
{
	$papers = $_POST['papers'];
}

?>





<fieldset> <legend align="center">REASERCH PAPERS PRODUCED BY YOU </legend>


<p>
YOU HAVE SELECTED THE NUMBER OF RESEARCH PAPERS YOU HAVE SUBMITTED
<br>
NOW CONTINUE WITH THE REST OF THE REGISTRATION <br>
IF YOU HAVE SELECTED WRONG NUMBER YOU CAN GO BACK USING <u>BACK BUTTON</u><br>

<?php

/*echo "<select name=\"papers\"> ";
 echo " <option value=-1>--select--</option>";

for($i = 0;$i<=50;$i++)
{
	
	echo "<option value=\"$i\">$i</option>";
	
}
echo "</select>"; */
?>

<a href="register.php"><button>BACK</button></a>

</p>

</fieldset>



<form action="new.php" method="post">
<fieldset> <legend align="center">REGISTRATION </legend>

<p>NAME: <input type="text" name="name" \></p>
<p>GENDER: <input type="radio" name="gender" value="M" \>MALE <input type="radio" name="gender" value="F" /> FEMALE </p>
<p>BRANCH: <select name="branch">
<option value="">--SELECT--</option>
<option value="cse">COMPUTER SCIENCE AND ENGINEERING</option>
<option value="ece">ELECTRONICS AND COMMUNICATION ENGINEERING</option>
<option value="eee">ELECTRICAL AND ELECTRONICS ENGINEERING</option>
<option value="mech">MECHANICAL ENGINEERING</option>
<option value="civil">CIVIL ENGINEERING</option>
<option value="chem">CHEMICAL ENGINEERING</option>
<option value="meta"> METALLURGICAL AND MATERIALS ENGINEERING</option>
<option value="mining">MINING ENGINEERING</option>
</select>
</p>
<p>QUALIFICATION: <input type="radio" name="qualification" value="b.tech" />B.TECH
                  <input type="radio" name="qualification" value="m.tech" />M.TECH
				  <input type="radio" name="qualification" value="phd" />PHD
</p>
<p>
NEW PASSWORD: <input type="password" name="password1">
RETYPE PASSWORD: <input type="password" name="password2">

</p>
<p>EMAIL: <input type="text" name="email"</p>


<p>
DESCRIBE YOURSELF:<textarea name="info" rows="5" cols="50">PLEASE DESCRIBE YOURSELF</textarea>
</p>
<p>

DESCRIPTION OF YOUR RESEARCH PAPERS:<br>


<textarea name="research" rows="10" cols="100">
<?php
if($papers >0)
{
	for($i=1;$i<=$papers;$i++)

{
	echo "ABOUT RESEARCH PAPER $i :\n \n \n ";
}

}
else
{
	echo " \n \n \n \n \t \t \t \t NO NEED TO DESCRIBE \n \n ";
}

?>
</textarea>




TOTAL NUMBER OF RESEARCH PAPERS:
<?php
if($papers < 0)
{
	echo "INVALID NUMBER<br />";
	$papers="invalid number";
	
}
else
{
echo	"<select name=\"papers\">";
echo	"<option value=\"$papers\">$papers</option>";
echo	"</select>";
}

?>

</p>


			  
</fieldset>

<p align="center"><input type="submit" name="submit" value="SUBMIT"></p>

</form>

</p>

</body> 

</html>