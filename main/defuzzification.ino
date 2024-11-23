/* 
 * Bagian ini digunakan sebagai pembentukan rumus defuzifikasi pada metode fuzzy sugeno
*/

void deffuzification(float *out1, float *out2) {
  rule();
  X1 = 0;
  X2 = 0;
  Y = 0;

  for (int i = 1; i <= 18; i++) {
    X1 += Rule[i][0] * minr[i];
    X2 += Rule[i][1] * minr[i];
    Y += minr[i];
  }

  *out1 = X1 / Y;
  *out2 = X2 / Y;
}