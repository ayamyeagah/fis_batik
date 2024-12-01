void f_turbidity() {
  turbidity_voltage_raw = 0;

  for (int i = 0; i < 800; i++) {
    read_sensor_turbidity = analogRead(TURBIDITY_PIN);
    raw_volt = ((((read_sensor_turbidity / 1023.0) * 5.0) * 4000.0) / 2048.0);
    turbidity_voltage_raw += raw_volt;
  }

  turbidity_voltage_raw = turbidity_voltage_raw / 800;
  turbidity_voltage_raw *= 10.0;
  map_volt = map(turbidity_voltage_raw, 22, 36, 25, 40);

  turbidity_voltage_result = map_volt / 22.0; // ganti pembagi untuk tuning manual
  turbidity_voltage_result = round_to_dp(turbidity_voltage_result, 3);

  if (turbidity_voltage_result < 2.5) {
    turbidity_ntu = 3000;
  } else {
    turbidity_ntu = -1120.4 * square(turbidity_voltage_result) + 5742.3 * turbidity_voltage_result - 4353.8;
  }

  turbidity_ntu = turbidity_ntu / 100;
  
  Serial.print("turbidity voltage: ");
  Serial.print(turbidity_voltage_result);
  Serial.print(" | ntu: ");
  Serial.println(turbidity_ntu);
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}