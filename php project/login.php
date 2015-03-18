<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<title></title>
<meta name="" content="">
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
<style>
p{

font-size:30px;

}

</style>
</head>

<body style="background-color:skyblue;">
<form action="verify.php" method="POST">
<fieldset> <legend align="center"> <p>ENTER YOUR DETAILS TO LOG IN</p></legend>
<p>USERNAME <input type="text" name="name"</p>
<p>PASSWORD <input type="password" name="password"</p>



<p>BRANCH: <select name="branch">
<option value="0">--SELECT--</option>
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

</fieldset>
<input type="submit" name="submit" value="submit" />
</form>

</body>
</html>