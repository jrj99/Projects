var Celc = document.getElementById('Celc'); // Save element to a variable, so you don't have to look for it again
var Far = document.getElementById('Far');
var Rank = document.getElementById('Rank');



function calcFunction()
{
    var temp = parseFloat(document.getElementById('box').value)
    var kelvinValue;
    if(Celc.checked)  //If it's checked
    {
         kelvinValue =  temp + 273.15;
    }
    else if(Far.checked) 
    {
        kelvinValue =  temp +  459.67;
        kelvinValue = (kelvinValue * 5) / 9;
    }
    else if(Rank.checked)
   {
      kelvinValue = (temp * 5)/9
   }
      alert("The value in kelvin is: " + kelvinValue);
}

