/* 
 * Bagian ini digunakan sebagai pembentukan rumus min(minimal) pada metode fuzzy sugeno.
 * Fungsi ini akan dipanggil saat defuzifikasi.
*/

float Min(float x, float y) {
  if (x < y) {
    return x;
  } else if (y < x) {
    return y;
  } else {
    return x;
  }
}