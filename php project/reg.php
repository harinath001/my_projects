<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<title>login page</title>
<meta name="" content="">
<meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
<style>
p
{
font-size:40px;
color:blue;

}
</style>
</head>
<?php
echo "WELCOME \t";

$name=strtoupper($_POST['name']);
echo "<p>$name</p> </ br>";
$branch=$_POST['branch'];
 $branch=strtoupper($branch);
echo "  <p>YOUR BRANCH IS  $branch </p>";
?>
<a href="winter.php"><button name="log out" value="log out">log out</button></a>
<body>

</body>
</html>