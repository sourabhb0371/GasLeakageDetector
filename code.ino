int lpg;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "nojNbv4Y3eHgI_J2VUHdUjDjBRpjk-8Q";

//Your WiFi credentials.
//Set Password to "" for open networks.
char ssid[] = "Rohan s";
char pass[] = "rohan2002";

voi setup() {
	//put your setup code here, to run once;
	Serial.begin(9600);
	Blynk.begin(auth, ssid, pass);
	pinMode(D1, OUTPUT);
	pinMode(D2, OUTPUT);
	pinMode(D7, OUTPUT);
	digitalWrite(D7, LOW);
}

void loop() {
	Blynk.run();
	//put your main code here, to run repeatedly;
	lpg = analogRead(A0);
	Serial.println(lpg);
	delay(200);
	if(lpg > 500) {
		digitalWrite(D1, HIGH);
		digitalWrite(D2, HIGH);
		Blynk.notify("GAS LEAKAGE ALERT");
		delay(5000);
	}
	else {
		digitalWrite(D1, LOW);
		digitalWrite(D2, LOW);
		digitalWrite(D7, LOW);
	}
}
