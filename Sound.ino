void playsoundfx(int fxno, int channel) { //FX Synth script
  gb.sound.command(0, soundfx[fxno][6], 0, channel); // set volume
  gb.sound.command(1, soundfx[fxno][0], 0, channel); // set waveform
  gb.sound.command(2, soundfx[fxno][5], -soundfx[fxno][4], channel); // set volume slide
  gb.sound.command(3, soundfx[fxno][3], soundfx[fxno][2] - 58, channel); // set pitch slide
  gb.sound.playNote(soundfx[fxno][1], soundfx[fxno][7], channel); // play note
}

void playSound() {
  switch (sound_play) {
    case 1:
      playsoundfx(0, 0);
      break;
    case 2:
      playsoundfx(1, 0);
      break;
    case 3:
      playsoundfx(2, 0);
      break;
    case 4:
      playsoundfx(3, 0);
      break;
    case 5://=fail
      playsoundfx(4, 0);
      break;
  }
}
