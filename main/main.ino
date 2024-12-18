/* 
 * Bagian ini digunakan untuk mendeklarasikan semua variabel dan pin pada arduino. 
 * Pada void loop dipanggil 3 fungsi f_ph, f_turbidity, dan f_color utk membaca nilai masing-masing sensor
 * Selanjutnya dilakukan defuzifikasi untuk sensor yang terbaca untuk dapat memberikan respon berupa output,
 * output 1 yaitu motor, dan output 2 adalah solenoid valve.
 * Dilakukan juga rounding atau pembulatan dari hasil output fuzzy utk memberikan respon kepada motor dan solenoid.
 * Ditampilkan nilai dari hasil pembacaan sensor, membership function fuzzy, dan output fuzzy di serial monitor dan LCD.
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define PH_PIN A1
#define TURBIDITY_PIN A0
#define COLOR_S0 4
#define COLOR_S1 5
#define COLOR_S2 6
#define COLOR_S3 7
#define COLOR_OUT 8
#define SOLENOID_PIN 9
#define PUMP_PIN 10
#define PH_SAMPLING_INTERVAL 20
#define PH_ARRAY_LENGTH 40
#define COLOR_INTERVAL 100
#define LOOP_INTERVAL 5000

int lcd_state = 0;

int color_red_freq = 0;
int color_green_freq = 0;
int color_blue_freq = 0;

int read_sensor_turbidity, map_volt;
float turbidity_voltage_raw, raw_volt;
float turbidity_voltage_result, turbidity_ntu;

int PH_ARRAY[PH_ARRAY_LENGTH];
int PH_ARRAY_INDEX = 0;
static float ph_value, ph_voltage;

float ph, turbidity, color;
float X1, X2, X3, Y;
bool OUT_PUMP, OUT_SOLENOID;

String INDICATOR_PUMP, INDICATOR_SOLENOID, INDICATOR_STATE;
String INDICATOR_COLOR;

// fuzzy set ph
float uasam[] = { 0, 3.5, 7 };
float unetral[] = { 6.5, 7.5, 8.5 };
float ubasa[] = { 8, 11, 14 };

// fuzzy set turbidity
float utidakkeruh[] = { 0, 60, 120 };
float ukeruh[] = { 100, 160, 220 };
float usangatkeruh[] = { 200, 250, 300 };

// fuzzy set color
float ucolorless[] = { 0, 0, 0 };
float ucolored[] = { 1, 1, 1 };

// fuzzy set output
float ON = 1;
float OFF = 0;
float CONDITION[3] = { 0, 1, 2 }; // 0 = TIDAK LAYAK; 1 = KURANG LAYAK; 2 = LAYAK


// fuzzy rule
float minr[19];
float Rule[19][3];

void setup() {
  Serial.begin(9600);
  pinMode(COLOR_S0, OUTPUT);
  pinMode(COLOR_S1, OUTPUT);
  pinMode(COLOR_S2, OUTPUT);
  pinMode(COLOR_S3, OUTPUT);
  pinMode(COLOR_OUT, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(SOLENOID_PIN, OUTPUT);

  // COLOR FREQ SCALING TO 20%
  digitalWrite(COLOR_S0, HIGH);
  digitalWrite(COLOR_S1, LOW);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // MILLIS
  static unsigned long looping_interval = millis();
  if (millis() - looping_interval > LOOP_INTERVAL) {
    // READ SENSORS
    f_ph();
    f_turbidity();
    f_color();

    // FUZZY INPUT
    turbidity = turbidity_ntu;
    ph = ph_value;
    color = color;

    // DUMMY TEST FUZZY
    // turbidity = 110;
    // ph = 7;
    // color = 0;

    // FUZZY
    float output1, output2, output3;
    deffuzification(&output1, &output2, &output3);

    // ROUNDING OUTPUT
    fuzzy_output_rounding(output1, output2, output3);

    // RUN PUMP & SOLENOID
    digitalWrite(PUMP_PIN, OUT_PUMP);
    digitalWrite(SOLENOID_PIN, OUT_SOLENOID);

    // PRINT MEMBERSHIP FUNCTION
    Serial.println("------MEMBERSHIP FUNCTION");
    Serial.print("asam: ");
    Serial.println(fuasam());
    Serial.print("netral: ");
    Serial.println(funetral());
    Serial.print("basa: ");
    Serial.println(fubasa());
    Serial.print("tidak keruh: ");
    Serial.println(futidakkeruh());
    Serial.print("keruh: ");
    Serial.println(fukeruh());
    Serial.print("sangat keruh: ");
    Serial.println(futidakkeruh());

    // PRINT FUZZY OUTPUT
    Serial.println("------FUZZY OUTPUT");
    Serial.print("pump: ");
    Serial.println(output2);
    Serial.print("solenoid: ");
    Serial.println(output1);
    Serial.print("state: ");
    Serial.println(output3);
    Serial.println("------------------");
    Serial.println();

    // SWITCH LCD DISPLAY
    if (lcd_state == 1) {
      lcd_state = 0;
    } else {
      lcd_state = 1;
    }

    looping_interval = millis();
  }

  // SWITCH DISPLAY LCD
  switch (lcd_state) {
    case 0:
      // MONITORING SENSOR AND FUZZY
      lcd.clear();
      lcd.setCursor(0, 0);  // line 1
      lcd.print("PH     : ");
      lcd.setCursor(8, 0);
      lcd.print(ph);
      lcd.setCursor(0, 1);  // line 2
      lcd.print("NTU    : ");
      lcd.setCursor(8, 1);
      lcd.print(turbidity);
      lcd.setCursor(0, 2);  // line 3
      lcd.print("COLOUR : ");
      lcd.setCursor(8, 2);
      lcd.print(INDICATOR_COLOR);
      lcd.setCursor(0, 3);  // line 4
      lcd.print("PUMP: ");
      lcd.setCursor(6, 3);
      lcd.print(INDICATOR_PUMP);
      lcd.setCursor(10, 3);  // line 4
      lcd.print("SV: ");
      lcd.setCursor(14, 3);
      lcd.print(INDICATOR_SOLENOID);
      lcd_state = 0;
      break;

    case 1:
      // PROCESS STATE
      lcd.clear();
      lcd.setCursor(3, 1);  // line 2
      lcd.print("KONDISI AIR");
      lcd.setCursor(3, 2);  // line 3
      lcd.print(INDICATOR_STATE);
      lcd_state = 1;
      break;
  }
}
