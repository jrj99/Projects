 <!DOCTYPE html>
<html>
<body>

<?php

$Temp = $_POST['Temp'];
$answer = $_POST['temperature'];


if($answer == "Celsius"){
   $kelvinValue = $Temp + 273.15;

}
else if($answer == "Fahrenheit"){
      $kelvinValue =  $Temp +  459.67;
      $kelvinValue = ($kelvinValue * 5) / 9;
}
else if($answer == "Rankine")
   $kelvinValue = ($Temp * 5)/9;

echo "The value in kelvin is: "; 
echo $kelvinValue;
?>

</body>
</html> 
