//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h> 
double lt;
void setup() {
Serial.begin(115200);
}

void loop() {

  lt=analogRead(A0);     //*5.0/1023;
// lt= (-1*((1398.7*lt)-(2361.2)))/10.00;
//lt=(lt*lt*21.998)-(157.73*lt)+(235.55);
//xlt=(lt*lt*(0.00008))+(0.1873*lt)+(46.131);2
//lt=((lt-94.882)/(-0.276));//CONST VALUES


//lt=(-1*((lt-2.3538)/(0.0001)))/100.0;
//lt=(0.9893*lt)-747.9;
//lt=0.0799*lt-564.9;
//lt=(-0.3203*lt)+109.94; //CONST without convert //naaaah
//double avg = x / 20.0;
//lt=((lt-0.8633)/(0.00185))/1000;//const without convert
//x=(lt-46)*100;

Serial.println("adc= ");
Serial.println(lt);
  
delay(1000);
//lt=(-0.9791*lt)+200.67; //-55 
//lt=(-0.9791*lt)+145.67;//+20
//lt=(-0.9791*lt)+165.67;
//lt=(-0.0548*lt*lt)+(4.3738*lt)+83.909;
//lt=(-1.0169*lt)+(195.14);
//lt=-0.025*lt*lt+1.3094*lt+147.21;
lt=(-1.4792*lt)+(206.59);
Serial.println("GL= ");
Serial.println(lt);
delay(1000);


}
