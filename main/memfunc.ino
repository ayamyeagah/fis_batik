/* 
 * Bagian ini digunakan sebagai pembentukan rumus fungsi keanggotan (membership function).
 * Terdapat 8 fungsi yg dibuat,
 * Untuk ph: fungsi asam, fungsi netral, fungsi basa
 * Untuk turbidity: fungsi tidak keruh, keruh, sangat keruh
 * Untuk color: fungsi colored (berwarna), dan colorless (tidak berwarna)
*/

// logic ph
float fuasam() {
  if (ph < uasam[0]) {
    return 1;
  } else if (ph >= uasam[0] && ph <= uasam[1]) {
    return (ph - uasam[0]) / (uasam[1] - uasam[0]);
  } else if (ph >= uasam[1] && ph <= uasam[2]) {
    return (uasam[2] - ph) / (uasam[2] - uasam[1]);
  } else if (ph > uasam[2]) {
    return 0;
  }
}

float funetral() {
  if (ph < unetral[0]) {
    return 0;
  } else if (ph >= unetral[0] && ph <= unetral[1]) {
    return (ph - unetral[0]) / (unetral[1] - unetral[0]);
  } else if (ph >= unetral[1] && ph <= unetral[2]) {
    return (unetral[2] - ph) / (unetral[2] - unetral[1]);
  } else if (ph > unetral[2]) {
    return 0;
  }
}

float fubasa() {
  if (ph < ubasa[0]) {
    return 0;
  } else if (ph >= ubasa[0] && ph <= ubasa[1]) {
    return (ph - ubasa[0]) / (ubasa[1] - ubasa[0]);
  } else if (ph >= ubasa[1] && ph <= ubasa[2]) {
    return (ubasa[2] - ph) / (ubasa[2] - ubasa[1]);
  } else if (ph > ubasa[2]) {
    return 1;
  }
}

// logic turbidity
float futidakkeruh() {
  if (turbidity < utidakkeruh[0]) {
    return 1;
  } else if (turbidity >= utidakkeruh[0] && turbidity <= utidakkeruh[1]) {
    return (turbidity - utidakkeruh[0]) / (utidakkeruh[1] - utidakkeruh[0]);
  } else if (turbidity >= utidakkeruh[1] && turbidity <= utidakkeruh[2]) {
    return (utidakkeruh[2] - turbidity) / (utidakkeruh[2] - utidakkeruh[1]);
  } else if (turbidity > utidakkeruh[2]) {
    return 0;
  }
}

float fukeruh() {
  if (turbidity < ukeruh[0]) {
    return 0;
  } else if (turbidity >= ukeruh[0] && turbidity <= ukeruh[1]) {
    return (turbidity - ukeruh[0]) / (ukeruh[1] - ukeruh[0]);
  } else if (turbidity >= ukeruh[1] && turbidity <= ukeruh[2]) {
    return (ukeruh[2] - turbidity) / (ukeruh[2] - ukeruh[1]);
  } else if (turbidity > ukeruh[2]) {
    return 0;
  }
}

float fusangatkeruh() {
  if (turbidity < usangatkeruh[0]) {
    return 0;
  } else if (turbidity >= usangatkeruh[0] && turbidity <= usangatkeruh[1]) {
    return (turbidity - usangatkeruh[0]) / (usangatkeruh[1] - usangatkeruh[0]);
  } else if (turbidity >= usangatkeruh[1] && turbidity <= usangatkeruh[2]) {
    return (usangatkeruh[2] - turbidity) / (usangatkeruh[2] - usangatkeruh[1]);
  } else if (turbidity > usangatkeruh[2]) {
    return 1;
  }
}

// logic color
float fucolorless() {
  if (color < ucolorless[0]) {
    return 1;
  } else if (color >= ucolorless[0] && color <= ucolorless[1]) {
    return (color - ucolorless[0]) / (ucolorless[1] - ucolorless[0]);
  } else if (color >= ucolorless[1] && color <= ucolorless[2]) {
    return (ucolorless[2] - color) / (ucolorless[2] - ucolorless[1]);
  } else if (color > ucolorless[2]) {
    return 0;
  }
}

float fucolored() {
  if (color < ucolored[0]) {
    return 0;
  } else if (color >= ucolored[0] && color <= ucolored[1]) {
    return (color - ucolored[0]) / (ucolored[1] - ucolored[0]);
  } else if (color >= ucolored[1] && color <= ucolored[2]) {
    return (ucolored[2] - color) / (ucolored[2] - ucolored[1]);
  } else if (color > ucolored[2]) {
    return 1;
  }
}