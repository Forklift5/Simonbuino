void melodyPlaying() {
  //MELODY DELAY
  if (melody_timer == 0) {
    sound_play = melody[melody_currentnote];//update the value storing the value to play. //4;
    playSound();//play the right sound.
    buttonHide();//hide the right button
    melody_currentnote ++; //update for next playable note.
    melody_timer ++; //update delay
  }

  if (melody_timer > 0) { //start delay in-between notes
    melody_timer ++;
  }
  if (melody_timer > timer_max) { //end delay in-between notes = check if there are other notes to play...

    if (melody_currentnote >= melody_step) {// = no more notes to play = player turn.
      melody_currentnote = 0; //reinitialize current playing note for the player.
      melody_timer = 0; // reinitialize the timer for the next time the CPU will play the extended melody.
      buttonsShow(); //show all the buttons again.
      melody_playing = false; // = player turn
    }
    else {// = there are MORE notes to play until the currentnote hit the step limit.
      melody_timer = 0;// loop.
      buttonsShow();
    }
  } //delay after notes played by CPU.
}
