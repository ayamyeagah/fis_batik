void f_ph() {
  static unsigned long ph_sampling_time = millis();
  static unsigned long ph_print_time = millis();

  // SAMPLING EVERY 20 MS
  if (millis() - ph_sampling_time > PH_SAMPLING_INTERVAL) {
    PH_ARRAY[PH_ARRAY_INDEX++] = analogRead(PH_PIN);
    if (PH_ARRAY_INDEX == PH_ARRAY_LENGTH) PH_ARRAY_INDEX = 0;
    ph_voltage = ph_average_array(PH_ARRAY, PH_ARRAY_LENGTH) * 5.0 / 1024;

    // PH CALCULATION
    ph_value = -6.61 * ph_voltage + 32.07;

    ph_sampling_time = millis();
  }

  // PRINT EVERY 800 MS
  if (millis() - ph_print_time > PH_PRINT_INTERVAL) {
    Serial.println(">>>---SENSOR---<<<");
    Serial.print("ph voltage: ");
    Serial.print(ph_voltage, 2);
    Serial.print(" | ph value: ");
    ph_value = ph_value - 0.58;  // TUNING MANUAL
    Serial.println(ph_value, 2);
    ph_print_time = millis();
  }
}

double ph_average_array(int* arr, int number) {
  int i;
  int max, min;
  double avg;
  long amount = 0;
  if (number <= 0) {
    Serial.println("Error number for the array of ph to averaging!");
    return 0;
  }
  if (number < 5) {
    for (i = 0; i < number; i++) {
      amount += arr[i];
    }
    avg = amount / number;
    return avg;
  } else {
    if (arr[0] < arr[1]) {
      min = arr[0];
      max = arr[1];
    } else {
      min = arr[1];
      max = arr[0];
    }
    for (i = 2; i < number; i++) {
      if (arr[i] < min) {
        amount += min;
        min = arr[i];
      } else if (arr[i] > max) {
        amount += max;
        max = arr[i];
      } else {
        amount += arr[i];
      }
    }
    avg = (double)amount / (number - 2);
  }
  return avg;
}