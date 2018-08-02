 
 //                           S.Selvabharathi   B.Tech IT  Rajalakshmi Engineering College
 //                           AIR MONITORING SYSTEM VIA IOT
 //                           this project is developed by Selvabharathi,Vasanthan,Purushothaman,Anirudhkrishnan for I-Quest18 and INNOVATION18 conducted by rajalakshmi engineering college.
 
 #include <ESP8266WiFi.h>  
#include "MQ135.h"
#include <LiquidCrystal.h>
#include<Servo.h>

const char* ssid = "username";
const char* password = "password";

int airquality;
MQ135 gasSensor=MQ135(A0);

const int ledPin=5;//d1
const int fanpin=16;//d0
//int state=1;
 double latt=13.009408;
 double logg=80.004551;

Servo servo;

WiFiServer server(80);

void setup() 
{
  Serial.begin(115200);
  delay(10);
   pinMode(fanpin,OUTPUT);
   pinMode(ledPin,OUTPUT);
  servo.attach(13);//d7
  servo.write(0);
  delay(2000);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED)
 {
    delay(500);
    Serial.print(".");
 }
  Serial.println("");
  Serial.println("WiFi connected");
   server.begin();
  Serial.println("Server started");
  delay(1000);
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
void loop() 
{
  delay(500);
  float airquality=gasSensor.getPPM();
  Serial.println( airquality);
  if(airquality<=35)
  {
    digitalWrite(fanpin,LOW);
    digitalWrite(ledPin,LOW);
  }
  else 
  {
    digitalWrite(fanpin,HIGH);
    digitalWrite(ledPin,HIGH);
  }
  
  
  WiFiClient client = server.available();
  if (!client)
  {
    return;
  }
 
 
  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }
 
  
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
 
 
  int value = HIGH;
  
  if (request.indexOf("/LED=ON") != -1) 
  {

    servo.write(0);
    delay(1000);
  }
  if (request.indexOf("/LED=OFF") != -1) 
  {

    servo.write(90);
    delay(1000);
  }

/*   if (request.indexOf("/L=ON") != -1) 
  {
    digitalWrite(fanpin, HIGH);
    value = HIGH;
    state=0;
  }
  if (request.indexOf("/L=OFF") != -1) 
  {
    digitalWrite(fanpin, LOW);
    value = LOW;
    state=1;
  }   */
 

 
 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<meta http-equiv=\"refresh\" content=\"8\">");
  client.println("<html>");
  client.println("<head><title>CONTROL ROOM</title><style>#grad1{background:linear-gradient(orange,white,green);}</style></head>");
  client.println("<body>");
  client.println("<div id=grad1>");
  client.println("<center><b><i><u>");
  client.println("<font face=DigifaceWide size=35 color=red>HEALTH CARE</font>");
  client.println("</b></i></u></center>");
  client.println("<br>");
  client.println("<br>");
  client.println("<ul>");
  client.println("<li><b><font face=arial size=5 color=dark_red>VEHICLE NUMBER <font color=red> :  </font></b></font>TN12F0258");
  client.println("<br>");
  client.println("<br>");
  client.println("<perserve>");
  client.println("<li><b><font face=arial size=5 color=dark_red>  DATE/TIME <font color=red> :  </font></font></b> ");
  client.println("<script language=javascript>");
  client.println("var today = new Date();");
  client.println("document.write(today);");
  client.println("</script>");
  client.println("</perserve>");
  client.println("<br>");
  client.println("<br>");  
  client.println("<li><b><font face=arial size=5 color=dark_red>vehicle atmosphere status<font color=red> :  </font></font><font color=teal size=4>Pure_air / contaminated_air  </font> </b> ");
  client.println("</ul>");
  client.println("<br>");
  
  
  if(airquality>35)
  {
  client.println("<center><h1><font color=green>CONTAMINATED  AIR  FOUND</font></h1></center>");
  client.println("<marquee direction=left bgcolor=yellow><font color=red size=5>ALERT !!! ALERT !!! ALERT</marquee></font>");
    client.println("<br>");
  client.println("<br>");
   }


  client.println("<pre>");
  client.println("<ul>");
  client.println("<li><b><font face=arial size=5 color=dark_red>OPEN CAR WINDOW<font color=red> : </font></b></font>");
  client.println("<br>");
  client.println("<a href=\"/LED=ON\"\"><button>OPEN</button></a><br>");
  client.println("<a href=\"/LED=OFF\"\"><button>CLOSE</button></a><br>"); 
  client.println("<li><b><font face=arial size=5 color=dark_red>RUN EXHAUST FAN<font color=red> : </font></b></font>"); 
  client.println("<a href=\"/L=ON\"\"><button>ON</button></a><br>");
  client.println("<a href=\"/L=OFF\"\"><button>OFF</button></a><br>"); 
  client.println("</ul>");
  client.println("</pre>");
  client.println("</div>");
  client.println("<pre>");
  client.println("<li><b><font face=arial size=5 color=dark_red>VEHICLE POSITION <font color=red>");
  client.println("<li><b><font face=arial size=5 color=dark_red>lattitude<font color=red> :  </font></b></font>");client.println(latt);client.println("<li><b><font face=arial size=5 color=dark_red>longitude<font color=red> :  </font></b></font>");client.println(logg);
  client.println("</pre>");
  client.println("</body>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}



