#include <SPI.h>
#include <SD.h>

#define OK 0
#define NOK 1

#define NUMBER_OF_SENSORS 2
#define HIT_BOUNDARY 300

String fileTitle = "record";
String fileFormat = ".csv";

void setupSerial();
void setupSD();

void setup() {
	setupSerial();
	setupSD();
}

int readForce (int index) {
	int analogReading = analogRead(FORCE_SENSOR_PIN);
}

int getMaxRecodNumber() {
	// TODO
	return 0;
}

int initFile (String fileName) {
	File file = SD.open(fileName, FILE_WRITE);
	if (!file) {
		return NOK;
	}
	file.println("time;position;force");
	file.close();
	return OK;
}

int saveMeasurement (String fileName, unsigned long time, int position, int force) {
	File file = SD.open(fileName, FILE_WRITE);
	if (!file) {
		return NOK;
	}
	file.printf("%ld;%d;%d", time, position, force);
	file.close();
	return OK;
}

void recordMatch() {
	bool matchEnd = false;
	int force = -1;
	
	int fileNumber = getMaxRecodNumber() +1;
	String fileName = fileTitle + fileNumber + fileFormat;
	initFile(fileName);

	int position = 0;

	while (!matchEnd) {
		if (position >= NUMBER_OF_SENSORS) {
			position = 0;
		}
		force = readForce(position);
		if (force > HIT_BOUNDARY) {
			saveMeasurement(fileName, millis(), position, force);
		}
		position++;
	}
}

void loop() {
	// wait for serial port to connect. 
	while (!Serial) {
		; // Needed for native USB port only.
	}

	bool exit = false;
	while (!exit) {
		recordMatch();
	}

	Serial.println("Program ended!");
	while (1);
}

void setupSerial () {
  Serial.begin(9600);  
}

void setupSD () {
	Serial.println("Initializing SD card...");

	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		while (1);
	}
	Serial.println("initialization done.");
}

