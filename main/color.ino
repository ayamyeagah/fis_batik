void f_color() {
  static unsigned long color_read_interval = millis();
  if (millis() - color_read_interval > COLOR_INTERVAL) {
    // RED FREQUENCY
    digitalWrite(COLOR_S2, LOW);
    digitalWrite(COLOR_S3, LOW);
    color_red_freq = pulseIn(COLOR_OUT, LOW);
    color_red_freq = map(color_red_freq, 27, 143, 255, 0);

    // GREEN FREQUENCY
    digitalWrite(COLOR_S2, HIGH);
    digitalWrite(COLOR_S3, HIGH);
    color_green_freq = pulseIn(COLOR_OUT, LOW);
    color_green_freq = map(color_green_freq, 38, 180, 255, 0);

    // BLUE FREQUENCY
    digitalWrite(COLOR_S2, LOW);
    digitalWrite(COLOR_S3, HIGH);
    color_blue_freq = pulseIn(COLOR_OUT, LOW);
    color_blue_freq = map(color_blue_freq, 40, 170, 255, 0);

    color_read_interval = millis();
  }

  Serial.print("R= ");
  Serial.print(color_red_freq);
  Serial.print(" G= ");
  Serial.print(color_green_freq);
  Serial.print(" B= ");
  Serial.print(color_blue_freq);
  Serial.print("   ");

  classifyColor(color_red_freq, color_green_freq, color_blue_freq);
}

void classifyColor(int r, int g, int b) {
  // WHITE THRESHOLD
  int white_threshold = 220;

  if (r > white_threshold && g > white_threshold && b > white_threshold) {
    Serial.println(" | color: WHITE");
    color = 1;
    INDICATOR_COLOR = "CLEAN";
  } else if (r > g && r > b) {
    Serial.println(" | color: RED");
    color = 0;
    INDICATOR_COLOR = "DIRTY";
  } else if (g > r && g > b) {
    Serial.println(" | color: GREEN");
    color = 0;
    INDICATOR_COLOR = "DIRTY";
  } else if (b > r && b > g) {
    Serial.println("| color: BLUE");
    color = 0;
    INDICATOR_COLOR = "DIRTY";
  } else {
    Serial.println(" | Color is mixed");
    color = 0;
    INDICATOR_COLOR = "DIRTY";
  }
}