/* 
 * Bagian ini adalah deklarasi rules base pada metode fuzzy.
 * Terdapat total 18 rules yg mengacu pada tabel.
*/

void rule() {
  // r1
  minr[1] = Min(fuasam(), Min(futidakkeruh(), fucolored()));
  Rule[1][0] = OFF; // solenoid
  Rule[1][1] = ON; // pompa
  Rule[1][2] = CONDITION[0];
  // r2
  minr[2] = Min(fuasam(), Min(fukeruh(), fucolored()));
  Rule[2][0] = OFF;
  Rule[2][1] = ON;
  Rule[2][2] = CONDITION[0];
  // r3
  minr[3] = Min(fuasam(), Min(fusangatkeruh(), fucolored()));
  Rule[3][0] = OFF;
  Rule[3][1] = ON;
  Rule[3][2] = CONDITION[0];
  // r4
  minr[4] = Min(fuasam(), Min(futidakkeruh(), fucolorless()));
  Rule[4][0] = OFF;
  Rule[4][1] = ON;
  Rule[4][2] = CONDITION[0];
  // r5
  minr[5] = Min(fuasam(), Min(fukeruh(), fucolorless()));
  Rule[5][0] = OFF;
  Rule[5][1] = ON;
  Rule[5][2] = CONDITION[0];
  // r6
  minr[6] = Min(fuasam(), Min(fusangatkeruh(), fucolorless()));
  Rule[6][0] = OFF;
  Rule[6][1] = ON;
  Rule[6][2] = CONDITION[0];
  // r7
  minr[7] = Min(funetral(), Min(futidakkeruh(), fucolored()));
  Rule[7][0] = OFF;
  Rule[7][1] = ON;
  Rule[7][2] = CONDITION[1];
  // r8
  minr[8] = Min(funetral(), Min(fukeruh(), fucolored()));
  Rule[8][0] = OFF;
  Rule[8][1] = ON;
  Rule[8][2] = CONDITION[1];
  // r9
  minr[9] = Min(funetral(), Min(fusangatkeruh(), fucolored()));
  Rule[9][0] = OFF;
  Rule[9][1] = ON;
  Rule[9][2] = CONDITION[1];
  // r10
  minr[10] = Min(funetral(), Min(futidakkeruh(), fucolorless()));
  Rule[10][0] = ON;
  Rule[10][1] = OFF;
  Rule[10][2] = CONDITION[2];
  // r11
  minr[11] = Min(funetral(), Min(fukeruh(), fucolorless()));
  Rule[11][0] = OFF;
  Rule[11][1] = ON;
  Rule[11][2] = CONDITION[1];
  // r12
  minr[12] = Min(funetral(), Min(fusangatkeruh(), fucolorless()));
  Rule[12][0] = OFF;
  Rule[12][1] = ON;
  Rule[12][2] = CONDITION[1];
  // r13
  minr[13] = Min(fubasa(), Min(futidakkeruh(), fucolored()));
  Rule[13][0] = OFF;
  Rule[13][1] = ON;
  Rule[13][2] = CONDITION[0];
  // r14
  minr[14] = Min(fubasa(), Min(fukeruh(), fucolored()));
  Rule[14][0] = OFF;
  Rule[14][1] = ON;
  Rule[14][2] = CONDITION[0];
  // r15
  minr[15] = Min(fubasa(), Min(fusangatkeruh(), fucolored()));
  Rule[15][0] = OFF;
  Rule[15][1] = ON;
  Rule[15][2] = CONDITION[0];
  // r16
  minr[16] = Min(fubasa(), Min(futidakkeruh(), fucolorless()));
  Rule[16][0] = OFF;
  Rule[16][1] = ON;
  Rule[16][2] = CONDITION[0];
  // r17
  minr[17] = Min(fubasa(), Min(fukeruh(), fucolorless()));
  Rule[17][0] = OFF;
  Rule[17][1] = ON;
  Rule[17][2] = CONDITION[0];
  // r18
  minr[18] = Min(fubasa(), Min(fusangatkeruh(), fucolorless()));
  Rule[18][0] = OFF;
  Rule[18][1] = ON;
  Rule[18][2] = CONDITION[0];
};