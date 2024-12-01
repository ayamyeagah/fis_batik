void fuzzy_output_rounding(float r_out1, float r_out2, float r_out3) {
  // LOGIC FOR ROUNDING AND TRIGGER SOLENOID (OUTPUT 1)
  if (r_out1 > 0.5) {
    OUT_SOLENOID = true;
    INDICATOR_SOLENOID = "ON";
  } else if (r_out1 < 0.5) {
    OUT_SOLENOID = false;
    INDICATOR_SOLENOID = "OFF";
  }

  // LOGIC FOR ROUNDING AND TRIGGER PUMP (OUTPUT 2)
  if (r_out2 > 0.5) {
    OUT_PUMP = true;
    INDICATOR_PUMP = "ON";
  } else if (r_out2 < 0.5) {
    OUT_PUMP = false;
    INDICATOR_PUMP = "OFF";
  }

  // LOGIC FOR ROUNDING IF OUTPUT1 & OUTPUT2 HAVE SAME VALUE
  if ((r_out1 == 0.5) && (r_out2 == 0.5)) {
    OUT_PUMP = true;
    INDICATOR_PUMP = "ON";
    OUT_SOLENOID = false;
    INDICATOR_SOLENOID = "OFF";
  }

  // LOGIC FOR ROUNDING STATE (OUTPUT 3)
  if (r_out3 <= 0.5) {
    INDICATOR_STATE = "TIDAK LAYAK";
  } else if ((r_out3 > 0.5) && (r_out3 <= 1.5)) {
    INDICATOR_STATE = "KURANG LAYAK";
  } else if ((r_out3 > 1.5) && (r_out3 <= 2.5)) {
    INDICATOR_STATE = "LAYAK";
  }
}