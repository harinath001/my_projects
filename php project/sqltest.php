<?php

$connect=mysql_connect("localhost","root","");
// $create=mysql_query("CREATE DATABASE test");
if($connect)
{
    echo 'connected';
    $connect=mysql_select_db("test");
    
}

/* $create=mysql_query("CREATE TABLE table2

(
id int,
name varchar(20),
lastname varchar(30),

) 

")
$alter=mysql_query("ALTER table1 INSERT COLUMN  firstname varchar(30) AFTER id");
if($alter==NULL)
{
	echo "fail";
}
else
{
	echo "success"; 
}*/
// $k=mysql_query("INSERT INTO table1 (id,name)  VALUES ('15','kanchu')");



//$extract=mysql_query("SELECT  * FROM table1");


// $extract=mysql_query("SELECT * FROM table2 WHERE id != '$id' AND branch='$branch'");

/*while($row=mysql_fetch_assoc($extract))
{
    $name=$row['id'];
	echo "$name <br />";
}*/






?>