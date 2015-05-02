void playerPlaying() {
  //KEYS
  if (wait_timer == 0) {
    if (gb.buttons.pressed(BTN_UP)) {
      wait_timer = 1;
      sound_play = 1;
      playSound(); //soundUp();
    }
    if (gb.buttons.pressed(BTN_RIGHT)) {
      wait_timer = 1;
      sound_play = 2;
      playSound(); //soundRight();
    }
    if (gb.buttons.pressed(BTN_DOWN)) {
      wait_timer = 1;
      sound_play = 3;
      playSound(); //soundDown();
    }
    if (gb.buttons.pressed(BTN_LEFT)) {
      wait_timer = 1;
      sound_play = 4;
      playSound(); //soundLeft();
    }
  }//end keys

  //DELAY after the player has played...
  if (wait_timer > 0) {
    wait_timer ++;
    buttonHide();
    if (wait_timer > (timer_max >> 1)) { //delay ended...
      //if key still pressed... continue the waiting... only at key.released??
      buttonsShow();//show all big buttons again.
      //if FAILED = RESET
      if (sound_play != melody[melody_currentnote] ) {
        melody_fail = true;
        player_fail();
      }
      else//WIN : more notes to play? end & back to the melody?
      {
        melody_currentnote ++;
        melody_timer = 1;//relaunch the melody
        wait_timer = 0;//end the delay
        if (melody_currentnote >= melody_step) { // = no more notes to match = CPU turn.
          melody_currentnote = 0; //reinitialize current playing note for the CPU.
          melody_timer = 0; // reinitialize the timer.
          buttonsShow(); //show all the buttons again.
          melody_playing = true; // = player turn
          melody_step ++; //increase the step limit;
          delay_timer = 1; //start the delay timer before the CPU plays its turn.
        }//end player turn.
      }//end win checking.
    }//end final frame of the delay...
  }//end delay between each player notes.
}//end PLAYR PLAYING TURN.

//RESET KEY
void key_reset() {
  if ((gb.buttons.pressed(BTN_C))) { //|| (melody_fail == true)) {
    initGame();
    melody_fail = false;
  }
}

//FAIL = END animation.
void player_fail() {
  fail_timer ++;
  sound_play = 5;//gb.sound.playCancel(); //sfx
  if (fail_timer <= 1) playSound(); //play sfx soundFail();
  buttonHide();
  if (fail_timer > timer_max) { //delay ended...
    initGame();
    sound_play = 0;
  }
}
