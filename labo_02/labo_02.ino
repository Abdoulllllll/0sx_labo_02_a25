unsigned long currentTime = 0;

void setup() {
  
  // Ton code ici
Serial.begin(9600);
 pinMode(boutonPin, INPUT_PULLUP); 
    for (int i = 0; i < 4; i++) {
        pinMode(leds[i], OUTPUT);
        digitalWrite(leds[i], LOW);
    }


  Serial.println("Setup completed");
}

void loop() {
  currentTime = millis();
unsigned long currentMillis = millis();

    
    int valeurPot = analogRead(potPin);
    int progression = map(valeurPot, 0, 1023, 0, 20);

    
    bool etatBouton = digitalRead(boutonPin);
    if (etatBouton == LOW and dernierEtatBouton == HIGH) { 
        boutonAppuye = !boutonAppuye; 
        afficherBarreProgression(progression);
    }
    dernierEtatBouton = etatBouton; 

    
    if (boutonAppuye and (currentMillis - previousMillis >= interval)) {
        previousMillis = currentMillis;
    }

    allumerLEDs(progression);
}





void afficherBarreProgression(int progression) {
  

    char affichage = '@'; 

    
    if (progression < 5) Serial.print(" 25% ");
    else if (progression < 10) Serial.print(" 50% ");
    else if (progression < 15) Serial.print(" 75% ");
    else Serial.print("100% ");

    Serial.print("[");

   
    for (int i = 0; i < 20; i++) {
        if (i < progression) Serial.print(affichage);
        else Serial.print(".");
    }

    Serial.println("]");
}


void allumerLEDs(int progression) {
    for (int i = 0; i < 4; i++) {
        digitalWrite(leds[i], LOW);
    }

    
    if (progression >= 0 and progression < 5) digitalWrite(leds[0], HIGH);
    if (progression >= 5 and progression < 10) {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
    }
    if (progression >= 10 and progression < 15) {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
    }
    if (progression >= 15) {
        digitalWrite(leds[0], HIGH);
        digitalWrite(leds[1], HIGH);
        digitalWrite(leds[2], HIGH);
        digitalWrite(leds[3], HIGH);
    }
}






