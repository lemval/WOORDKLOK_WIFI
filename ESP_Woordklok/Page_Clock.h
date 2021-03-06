#ifndef PAGE_CLOCK_H
#define PAGE_CLOCK_H

#include <TimeLib.h>

const char PAGE_Clock[] PROGMEM = R"=====(
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <a href="/"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>WOORDKLOK Settings</strong>     
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr><form action="" method="post">
  <td align="center" colspan="2">Geluid Klok</td><tr>
    <td align="center"><input type='radio' id="Sound_ON" name='Sound' " value='ON'> On</td>
    <td align="center"><input type='radio' id="Sound_OFF" name='Sound' " value='OFF'> Off</td>
  </tr></table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr>
    <td align="center" colspan="2">Notatie Hoekpunten</td>
  </tr><tr>
    <td align="center"><input type='radio' id="Notat_1" name='Notat' " value='1'> 1 Min</td>
    <td align="center"><input type='radio' id="Notat_5" name='Notat' " value='5'> 5 Min</td>
  </tr></table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr>
    <td align="center" colspan="2">Touch Bediening</td>
  </tr>
  <tr><td align="left" colspan="2"><input type="checkbox" id="Update_Touch" name="Update_Touch" value="True"> Update touch?</td></tr>
  <tr> 
  <td align="center"  colspan="2">Sterkte Filter <input type='number' id="Touch_Fil" name='Touch_Fil'  min="1" max="8" value='5' pattern="[0-9]*" > </td>
  </tr>
  <tr>
  <td align="center">Tres. Low <input type='number' id="Touch_Tr_Low" name='Touch_Tr_Low'  min="1" max="999" value='15' pattern="[0-9]*" > </td>
  <td align="center">Tres. High <input type='number' id="Touch_Tr_High" name='Touch_Tr_High'  min="1" max="999" value='30' pattern="[0-9]*" > </td>
  </tr>
    <tr>
  <td align="center">Ticks Short <input type='number' id="Touch_Ti_Short" name='Touch_Ti_Short'  min="1" max="999" value='10' pattern="[0-9]*" > </td>
  <td align="center">Ticks Long <input type='number' id="Touch_Ti_Long" name='Touch_Ti_Long'  min="1" max="999" value='100' pattern="[0-9]*" > </td>
  </tr>
  </table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr>
    <td align="center" colspan="2">Licht Intensiteit</td>
  </tr><tr>
  <td align="center">Min. <input type='number' id="Light_Min" name='Light_Min'  min="1" max="100" value='1' pattern="[0-9]*" > </td>
  <td align="center">Max. <input type='number' id="Light_Max" name='Light_Max'  min="1" max="100" value='1' pattern="[0-9]*" > </td>
  </tr>
 </table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr>
    <td align="center" colspan="2">Transitiesnelheid</td>
  </tr><tr>
  <td align="center">1 tot 1000 -- (hoger = trager) <input type='number' id="Transpd" name='Transpd'  min="1" max="1000" value='1' pattern="[0-9]*" > </td>
  </tr>
 </table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">  
  <tr><td align="center" colspan="3">Klok Tijd</td></tr>
 <tr><td align="left" colspan="3"><input type="checkbox" id="Update_Tijd" name="Update_Tijd" value="True"> Update tijd</td></tr><tr>
 <td align="right"><input type='number' id="Time_Hrs" name='Time_Hrs'  min="0" max="24" value='12' pattern="[0-9]*" > : </td>
  <td align="center"><input type='number' id="Time_Min" name='Time_Min'  min="0" max="60" value='0' pattern="[0-9]*" ></td>
  <td align="left"> : <input type='number' id="Time_Sec" name='Time_Sec'  min="0" max="60" value='0' pattern="[0-9]*" ></td></tr>
  </table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">
  <tr>
    <td align="center" colspan="2">Overgangs Modus</td>
  </tr><tr>
<td>Stel in op: </td>
<td>  
<select  id="Clock_Mode" name="Clock_Mode">
  <option value="110">110: UIT</option>
  <option value="120">120: WATERVAL</option>
  <option value="130">130: RECHTS->LINKS</option>
  <option value="140">140: LINKS->RECHTS</option>
  <option value="150">150: FADE OUT/IN</option>
  <option value="160">160: FADE WORD IN</option>
  <option value="170">170: RANDOM</option>
  </select></td></tr>
  </table>
  <hr>
  <table border="0"  cellspacing="0" cellpadding="3" style="width:300px">  
<tr><td align="center" colspan="2"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Update Clock"></td></tr>
</form>
  
  </table>
  <hr>
   
   
   <script>                
		window.onload = function ()
		{
			load("style.css","css", function() 
			{
				load("microajax.js","js", function() 
				{
						setValues("/admin/filldynamicdataClock");  //-- this function calls the function on the ESP      
				});
			});
		}
		function load(e,t,n){if("js"==t){var a=document.createElement("script");a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}else if("css"==t){var a=document.createElement("link");a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)}}

   </script>

)=====";
#endif

void filldynamicdataClock() {
	String values = "";
	if (config.SoundOnOff == true)
		values += "Sound_ON| checked |chk\n";
	else
		values += "Sound_OFF| checked |chk\n";
	if (config.Notat == 1)
		values += "Notat_1| checked |chk\n";
	else
		values += "Notat_5| checked |chk\n";
	values += "Light_Min|" + String(config.LMin) + "|input\n";
	values += "Light_Max|" + String(config.LMax) + "|input\n";
	values += "Time_Hrs|" + (String) hour() + "|input\n"; //(String) DateTime.hour + "|input\n";
	values += "Time_Min|" + (String) minute() + "|input\n"; //(String) DateTime.minute + "|input\n";
	values += "Time_Sec|" + (String) second() + "|input\n"; //(String) DateTime.second + "|input\n";
	values += "Clock_Mode|" + String(config.ClockMode) + "|input\n";
  values += "Transpd|" +  String(config.Transpd) + "|input\n";
	values += "Touch_Fil|" + (String) config.TouchFil + "|input\n";
	values += "Touch_Tr_High|" + (String) config.TouchTrH + "|input\n";
	values += "Touch_Tr_Low|" + (String) config.TouchTrL + "|input\n";
	values += "Touch_Ti_Short|" + (String) config.TouchTiS + "|input\n";
	values += "Touch_Ti_Long|" + (String) config.TouchTiL + "|input\n";
	server.send(200, "text/plain", values);
}

void processClock() {
	int delaytijd = 100;
	// Are there any POST/GET Fields ?
	if (server.args() > 0) {
		for (uint8_t i = 0; i < server.args(); i++) { // Iterate through the fields
			if (server.argName(i) == "Notat") {
				// Your processing for the transmitted form-variable CLCOK NOTATIE
				config.Notat = server.arg(i).toInt();
				Clock::setNotation(server.arg(i).toInt());
			}
			if (server.argName(i) == "Light_Min") {
				// Your processing for the transmitted form-variable MINIMALE LICHT INTENSITEIT
				config.LMin = server.arg(i).toInt();
				delay(delaytijd);
				Clock::setLMin(config.LMin);
			}
			if (server.argName(i) == "Light_Max") {
				// Your processing for the transmitted form-variable MAXIMALE LICHT INTENSITEIT
				config.LMax = server.arg(i).toInt();
				delay(delaytijd);
				Clock::setLMax(config.LMax);
			}
      if (server.argName(i) == "Transpd") {
        // Your processing for the transmitted form-variable TRANSITIE SNELHEID
        config.Transpd = server.arg(i).toInt();
        delay(delaytijd);
        Clock::Transpd(config.Transpd);;
      }
			if (server.argName(i) == "Sound") {
				// Your processing for the transmitted form-variable GELUID AAN / UIT
				config.SoundOnOff = server.arg(i) == "ON";
				delay(delaytijd);
				Clock::enableSound(config.SoundOnOff);
			}
			if (server.argName(i) == "Touch") {
				// Your processing for the transmitted form-variable TOUCH AAN / UIT
				config.TouchOnOff = server.arg(i) == "1";
				delay(delaytijd);
				Clock::enableTouch(config.TouchOnOff);
			}
			if (server.argName(i) == "Update_Touch") {
				if (server.arg(i) == "True") {
					delay(delaytijd);
					config.TouchFil = server.arg("Touch_Fil").toInt();
					config.TouchTrH = server.arg("Touch_Tr_High").toInt();
					config.TouchTrL = server.arg("Touch_Tr_Low").toInt();
					config.TouchTiS = server.arg("Touch_Ti_Short").toInt();
					config.TouchTiL = server.arg("Touch_Ti_Long").toInt();
					Clock::setTouch(config.TouchFil, config.TouchTrH, config.TouchTrL, config.TouchTiS, config.TouchTiL);
				}
			}

			if (server.argName(i) == "Update_Tijd") {
				// Your processing for the transmitted form-variable TIJDSINSTELLING
				if (server.arg(i) == "True") {
					delay(delaytijd);
					int hour = server.arg("Time_Hrs").toInt();
					int minute = server.arg("Time_Min").toInt();
					int second = server.arg("Time_Sec").toInt();
					Clock::setTime(hour, minute, second);
				}
			}
			if (server.argName(i) == "Clock_Mode") {
				// Your processing for the transmitted form-variable OVERGANGSMODUS
				config.ClockMode = server.arg(i).toInt();
				delay(delaytijd);
				Clock::setMode(config.ClockMode);
			}
		}
		WriteClockConfig();
	}
	server.send_P(200, CONTENT_Html, PAGE_Clock);
}

