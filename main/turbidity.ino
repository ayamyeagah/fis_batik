void f_turbidity() {
  turbidity_value = analogRead(TURBIDITY_PIN);
  turbidity_voltage = 0;

  for (int i = 0; i < 800; i++) {
    turbidity_voltage += (turbidity_value / 1023) * 5;
  }

  turbidity_voltage = turbidity_voltage / 800;
  turbidity_voltage = round_to_dp(turbidity_voltage, 2);

  if (turbidity_voltage < 2.5) {
    turbidity_ntu = 3000;
  } else {
    turbidity_ntu = -1120.4 * square(turbidity_voltage) + 5742.3 * turbidity_voltage - 4353.8;
  }

  Serial.print("turbidity voltage: ");
  Serial.print(turbidity_voltage);
  Serial.print(" | ntu: ");
  Serial.println(turbidity_ntu);
}

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}