

  
  int lengthImperialMarch = 55;
  String notesImperialMarch[] = {"G4","G4", "G4", "D#4/Eb4", "A#4/Bb4", "G4", "D#4/Eb4","A#4/Bb4", "G4", "D5", "D5", "D5", "D#5/Eb5", "A#4/Bb4", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4", "G5","G4","G4","G5","F#5/Gb5", "F5","E5","D#5/Eb5","E5", "rest", "G4", "rest","C#5/Db5","C5","B4","A#4/Bb4","A4","A#4/Bb4", "rest", "D#4/Eb4", "rest", "F#4/Gb4", "D#4/Eb4","A#4/Bb4", "G4" ,"D#4/Eb4","A#4/Bb4", "G4"}; 
  int beatsImperialMarch[] = { 8, 8, 8, 6, 2, 8, 6 , 2 ,16 , 8, 8, 8, 6, 2, 8, 6, 2, 16,8,6,2,8,6,2,2, 2, 2,6,2,2,8,6,2,2,2,2,6,2,2,9,6,2,8,6,2,16  };
  int tempoImperialMarch = 50;

  
// bottone e Led Jignle Bells
int buttonJingleBells= 11;
int ledJingleBells = 12;

//bottone e Led Imperial March

int buttonImperialMarch = 10;
int ledImperialMarch = 5;


// speaker
int speakerPin = 6;



// JignleBellls
int lengthJingleBells = 26;
char notesJingleBells[] = "eeeeeeegcde fffffeeeeddedg";
int beatsJingleBells[] = { 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2};

int tempoJingleBells = 300;
void playToneJingleBells(int tone, int durationJingleBells) {
  for (long i = 0; i < durationJingleBells * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNoteJingleBells(char noteJingleBells, int durationJingleBells) {
  char namesJingleBells[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tonesJingleBells[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (namesJingleBells[i] == noteJingleBells) {
      playToneJingleBells(tonesJingleBells[i], durationJingleBells);
    }
  }
}

  
  void playToneImperialMarch(int tone, int durationImperialMarch) {
    for (long i = 0; i < durationImperialMarch * 1000L; i += tone * 2) {
      digitalWrite(speakerPin, HIGH);
      delayMicroseconds(tone);
      digitalWrite(speakerPin, LOW);
      delayMicroseconds(tone);      
    }
  }
  
  void playNoteImperialMarch(String noteImperialMarch, int durationImperialMarch) {
    String noteNamesImperialMarch[] = { "D#4/Eb4", "E4", "F4", "F#4/Gb4", "G4", "G#4/Ab4", "A4", "A#4/Bb4", "B4", "C5", "C#5/Db5", "D5", "D#5/Eb5", "E5", "F5", "F#5/Gb5", "G5", "G#5/Ab5", "A5", "A#5/Bb5", "B5", "C6", "C#6/Db6", "D6", "D#6/Eb6", "E6", "F6", "F#6/Gb6", "G6" };
    int tonesImperialMarch[] = { 1607, 1516, 1431, 1351, 1275, 1203, 1136, 1072, 1012, 955, 901, 851, 803, 758, 715, 675, 637, 601, 568, 536, 506, 477, 450, 425, 401, 379, 357, 337, 318 };
    for (int i = 0; i < 29; i++) {
      if (noteNamesImperialMarch[i] == noteImperialMarch) {
        playToneImperialMarch(tonesImperialMarch[i], durationImperialMarch);
      }
    }
  }





void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonJingleBells, INPUT);
  pinMode(ledJingleBells, OUTPUT);
  pinMode(buttonImperialMarch, INPUT);
  pinMode(ledImperialMarch, OUTPUT);
}
void loop() {

  int buttonStateJingleBells = digitalRead(buttonJingleBells);
  int buttonStateImperialMarch = digitalRead(buttonImperialMarch);

 if (buttonStateImperialMarch == 1) {
   for (int i = 0; i < lengthImperialMarch; i++) {
      if (notesImperialMarch[i] == "rest") {
        delay(beatsImperialMarch[i] * tempoImperialMarch);
          
          
      } else {
          digitalWrite(ledImperialMarch, HIGH);
        playNoteImperialMarch(notesImperialMarch[i], beatsImperialMarch[i] * tempoImperialMarch);      
          digitalWrite(ledImperialMarch, LOW);
      }
      delay(tempoImperialMarch / 2);
      
    }

 }
    
  //if the button is pressed
  if (buttonStateJingleBells == 1){
    
    for (int i = 0; i < lengthJingleBells; i++) {
    if (notesJingleBells[i] == ' ') {
    
      delay(beatsJingleBells[i] * tempoJingleBells); // rest
    
    } else {
       digitalWrite(ledJingleBells, HIGH);
     
      playNoteJingleBells(notesJingleBells[i], beatsJingleBells[i] * tempoJingleBells);
       digitalWrite(ledJingleBells, LOW);
    }
    
    // pause between notes
    delay(tempoJingleBells / 2); 
  }


  }




}
