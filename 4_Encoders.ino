#include <Bounce2.h> // Bounce library for the button
#include <Encoder.h>

const byte number_of_banks = 4; // Constants for banks and encoders
const byte number_of_encs = 4;

int current_value[16]; // Arrays for previous and current values
int previous_value[16];

byte current_bank = 0; // Variable for current bank

Encoder enc1(26, 25); // Create four encoders attached to pins 25 - 32
Encoder enc2(28, 27);
Encoder enc3(30, 29);
Encoder enc4(32, 31);

Bounce bank_button = Bounce(); // Create button object

void setup() {
  pinMode(13, OUTPUT); // Set LED as output

  pinMode(33, INPUT_PULLUP); // Set button pin as input

  bank_button.attach(33); // Attach digital pin to bounce object
  bank_button.interval(5); // Set interval of bounce object
}

void loop() {
  bank_button.update(); // Update button / read button state

  if (bank_button.fell() == true) { // If button is pressed, then update the bank selection
    current_bank = current_bank + 1;
    if (current_bank >= number_of_banks) {
      current_bank = 0;
    }

    for (int i = 0; i < (current_bank + 1); i ++) {
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }

    enc1.write(previous_value[(current_bank * number_of_encs) + 0]); // Retrieve current values and write to encs
    enc2.write(previous_value[(current_bank * number_of_encs) + 1]);
    enc3.write(previous_value[(current_bank * number_of_encs) + 2]);
    enc4.write(previous_value[(current_bank * number_of_encs) + 3]);
  }

  current_value[(number_of_encs * current_bank) + 0] = enc1.read(); // Read encs into current values
  current_value[(number_of_encs * current_bank) + 1] = enc2.read();
  current_value[(number_of_encs * current_bank) + 2] = enc3.read();
  current_value[(number_of_encs * current_bank) + 3] = enc4.read();



  if (current_value[(number_of_encs * current_bank) + 0] < 0) { // Constrain all four encs to 0 - 127... 
    current_value[(number_of_encs * current_bank) + 0] = 0;
    enc1.write(0);
  }

  else if (current_value[(number_of_encs * current_bank) + 0] > 127) {
    current_value[(number_of_encs * current_bank + 0)] = 127;
    enc1.write(127);
  }

  if (current_value[(number_of_encs * current_bank) + 1] < 0) {
    current_value[(number_of_encs * current_bank) + 1] = 0;
    enc2.write(0);
  }

  else if (current_value[(number_of_encs * current_bank) + 1] > 127) {
    current_value[(number_of_encs * current_bank) + 1] = 127;
    enc2.write(127);
  }

  if (current_value[(number_of_encs * current_bank) + 2] < 0) {
    current_value[(number_of_encs * current_bank) + 2] = 0;
    enc3.write(0);
  }

  else if (current_value[(number_of_encs * current_bank) + 2] > 127) {
    current_value[(number_of_encs * current_bank) + 2] = 127;
    enc3.write(127);
  }

  if (current_value[(number_of_encs * current_bank) + 3] < 0) {
    current_value[(number_of_encs * current_bank) + 3] = 0;
    enc4.write(0);
  }

  else if (current_value[(number_of_encs * current_bank) + 3] > 127) {
    current_value[(number_of_encs * current_bank) + 3] = 127;
    enc4.write(127);
  }

  for (int i = 0; i < number_of_encs; i ++) { // Compare previous to current readings, and send MIDI data if changed, take into consideration different banks
    if (current_value[(number_of_encs * current_bank) + i] != previous_value[(number_of_encs * current_bank) + i]) {
      previous_value[(number_of_encs * current_bank) + i] = current_value[(number_of_encs * current_bank) + i];
      usbMIDI.sendControlChange(1 + (number_of_encs * current_bank) + i, current_value[(number_of_encs * current_bank) + i], 1);
    }
  }

}
