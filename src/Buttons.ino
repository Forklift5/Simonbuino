//HIDE BUTTONS each one OR ALL 4.
void buttonHide() {
  switch (sound_play) {
    case 1:
      display_top = false;
      break;
    case 2:
      display_right = false;
      break;
    case 3:
      display_bottom = false;
      break;
    case 4:
      display_left = false;
      break;
    case 5: // hide ALL 4.
      buttonsAllHide();
      break;
  }
}
void buttonsAllHide() {
  display_top = false;
  display_right = false;
  display_bottom = false;
  display_left = false;
}

//SHOW ALL 4 BUTTONS
void buttonsShow() {
  display_top = true;
  display_right = true;
  display_bottom = true;
  display_left = true;
}

//DRAW EACH BUTTONS.
void drawButtons() {
  //gb.display.setColor(WHITE);
  if (display_top == true) {
    gb.display.setColor(GRAY);
    gb.display.drawBitmap(30, 4 - 4, buttonMaskBitmap, ROTCCW, NOFLIP);
    gb.display.setColor(BLACK);
    gb.display.drawBitmap(30, 4 - 4, topBitmap, ROTCCW, NOFLIP);
  }
  if (display_right == true) {
    gb.display.setColor(GRAY);
    gb.display.drawBitmap(50, 12, buttonMaskBitmap);
    gb.display.setColor(BLACK);
    gb.display.drawBitmap(50, 12, rightBitmap);
  }
  if (display_bottom == true) {
    gb.display.setColor(GRAY);
    gb.display.drawBitmap(30, 32, buttonMaskBitmap, ROTCW, NOFLIP);
    gb.display.setColor(BLACK);
    gb.display.drawBitmap(30, 32, bottomBitmap, ROTCW, NOFLIP);
  }
  if (display_left == true) {
    gb.display.setColor(GRAY);
    gb.display.drawBitmap((22 - 4), 12, buttonMaskBitmap, NOROT, FLIPH);
    gb.display.setColor(BLACK);
    gb.display.drawBitmap((22 - 4), 12, leftBitmap, NOROT, FLIPH);
  }
  //display menu buttons
  if (melody_playing == true) {
    //Melody button
    gb.display.setColor(BLACK);
    gb.display.fillRect(37, 25, 2, 2);
  }
  else
  {
    buttonsShow();//show all buttons
    //Player button
    gb.display.setColor(BLACK);
    gb.display.fillRect(45, 25, 2, 2);
  }
  //Difficulty button
  if (game_difficulty == true) {
    gb.display.setColor(BLACK);
    gb.display.fillRect(41, 28, 2, 2);
  }
  //CURRENT RECORD
  gb.display.cursorX = 39;
  gb.display.cursorY = 18;
  gb.display.print(melody_step - 1);//draw current record.
}
