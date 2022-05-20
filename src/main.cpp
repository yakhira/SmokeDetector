#include "setup/wifi.h"

const int SKETCH_VERSION = 1; 
const String IFTTT_WEBHOOK = "";

ESPWiFi espwifi("ESP12-F");
JSONVar result;
JSONVar data;

void setup() {
	Serial.begin(74880);
	espwifi.wifiConnect();
}

void loop() {
	if (WiFi.getMode() == WIFI_STA) {
		if (WiFi.status() != WL_CONNECTED) {
			WiFi.reconnect();
		}
	}

	espwifi.sendHTTPJsonData(IFTTT_WEBHOOK, data);
	delay(5000);
}
