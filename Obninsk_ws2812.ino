#include "FastLED.h"          

#define LED_COUNT 137          // число светодиодов в кольце/ленте  глобус-137
#define LED_DT 2             // пин, куда подключен DIN ленты
int max_bright = 20;         // максимальная яркость (0 - 255)
int ledMode = 0;
int bouncedirection = 0;
int ibright = 0;


// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------
struct CRGB leds[LED_COUNT];
int ledsX[LED_COUNT][3];     

// ---------------СЛУЖЕБНЫЕ ПЕРЕМЕННЫЕ-----------------

void one_color_all(int cred, int cgrn, int cblu) {       //-SET ALL LEDS TO ONE COLOR
  for (int i = 0 ; i < LED_COUNT; i++ ) {
    leds[i].setRGB( cred, cgrn, cblu);
  }
}

void pulse_one_color_all() {              //-m10-PULSE BRIGHTNESS ON ALL LEDS TO ONE COLOR
  if (bouncedirection == 0) {
    ibright += 5;
    if (ibright >= 255) {
      bouncedirection = 1;
    }
  }
  if (bouncedirection == 1) {
    ibright = ibright - 5;
    if (ibright <= 1) {
      bouncedirection = 0;
    }
  }
  for (int idex = 0 ; idex < LED_COUNT; idex++ ) {
    leds[idex] = CHSV(96, 255, ibright);
  }
  LEDS.show();
  //delay(1);
}

void setup()
{
  Serial.begin(9600);              // открыть порт для связи
  Serial.setTimeout(5);              // задержка между командами
  Serial.flush();
  LEDS.setBrightness(max_bright);  // ограничить максимальную яркость

  LEDS.addLeds<WS2812B, LED_DT, GRB>(leds, LED_COUNT);  // настрйоки для нашей ленты (ленты на WS2811, WS2812, WS2812B)
  //pulse_one_color_all();
  one_color_all(0, 255, 0);         // погасить все светодиоды
  LEDS.show();                     // отослать команду
}

void Russia(int cred, int cgrn, int cblu) {
  for (int c = 0; c <= 12; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
  leds[54].setRGB( cred, cgrn, cblu);
}

void Finland(int cred, int cgrn, int cblu) {
  for (int c = 13; c <= 15; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Sweden(int cred, int cgrn, int cblu) {
  for (int c = 16; c <= 18; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Germany(int cred, int cgrn, int cblu) {
  for (int c = 19; c <= 23; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Switzerland(int cred, int cgrn, int cblu) {
  for (int c = 24; c <= 24; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void France(int cred, int cgrn, int cblu) {
  for (int c = 25; c <= 35; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Belgium(int cred, int cgrn, int cblu) {
  for (int c = 36; c <= 36; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Netherlands(int cred, int cgrn, int cblu) {
  for (int c = 37; c <= 37; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void UK(int cred, int cgrn, int cblu) {
  for (int c = 38; c <= 43; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Spain(int cred, int cgrn, int cblu) {
  for (int c = 44; c <= 47; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Slovenia(int cred, int cgrn, int cblu) {
  for (int c = 48; c <= 48; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Hungary(int cred, int cgrn, int cblu) {
  for (int c = 49; c <= 49; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Slovakia(int cred, int cgrn, int cblu) {
  for (int c = 50; c <= 50; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Czech(int cred, int cgrn, int cblu) {
  for (int c = 51; c <= 51; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Belorussia(int cred, int cgrn, int cblu) {
  for (int c = 52; c <= 52; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Litva(int cred, int cgrn, int cblu) {
  for (int c = 53; c <= 53; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Ukraine(int cred, int cgrn, int cblu) {
  for (int c = 55; c <= 58; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Romania(int cred, int cgrn, int cblu) {
  for (int c = 59; c <= 59; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Bulgaria(int cred, int cgrn, int cblu) {
  for (int c = 60; c <= 60; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Turkey(int cred, int cgrn, int cblu) {
  for (int c = 61; c <= 61; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Iordania(int cred, int cgrn, int cblu) {
  for (int c = 62; c <= 62; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Armenia(int cred, int cgrn, int cblu) {
  for (int c = 63; c <= 63; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Kazahstan(int cred, int cgrn, int cblu) {
  for (int c = 64; c <= 64; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void UAE(int cred, int cgrn, int cblu) {
  for (int c = 65; c <= 65; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Iran(int cred, int cgrn, int cblu) {
  for (int c = 66; c <= 66; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Pakistan(int cred, int cgrn, int cblu) {
  for (int c = 67; c <= 68; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void India(int cred, int cgrn, int cblu) {
  for (int c = 69; c <= 75; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Bangladesh(int cred, int cgrn, int cblu) {
  for (int c = 76; c <= 76; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void China(int cred, int cgrn, int cblu) {
  for (int c = 77; c <= 88; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Taiwan(int cred, int cgrn, int cblu) {
  for (int c = 89; c <= 90; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Vietnam(int cred, int cgrn, int cblu) {
  for (int c = 91; c <= 91; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Korea(int cred, int cgrn, int cblu) {
  for (int c = 92; c <= 94; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void KNDR(int cred, int cgrn, int cblu) {
  for (int c = 95; c <= 95; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Japan(int cred, int cgrn, int cblu) {
  for (int c = 96; c <= 106; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Canada(int cred, int cgrn, int cblu) {
  for (int c = 107; c <= 108; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void USA(int cred, int cgrn, int cblu) {
  for (int c = 109; c <= 130; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Mexico(int cred, int cgrn, int cblu) {
  for (int c = 131; c <= 131; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Argentina(int cred, int cgrn, int cblu) {
  for (int c = 132; c <= 133; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Brazil(int cred, int cgrn, int cblu) {
  for (int c = 134; c <= 134; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

void Africa(int cred, int cgrn, int cblu) {
  for (int c = 135; c <= 135; c++){
    leds[c].setRGB( cred, cgrn, cblu);
  }
}

// количество стран 33, зажигаем как по одной станции, так и по стране.

void change_mode(int newmode) {
  one_color_all(0, 0, 0);
  LEDS.show();
  bouncedirection = 0;
  ledMode = newmode;
}

void loop() {
  if (Serial.available() > 0) {     // если что то прислали
    //ledMode = Serial.parseInt();    // парсим в тип данных int
    ledMode = Serial.read();
    change_mode(ledMode);
    Serial.println(ledMode);// меняем режим через change_mode
    switch (ledMode) {
      case 0: leds[0] = CRGB::Green; LEDS.show(); break;
      case 1: leds[1] = CRGB::Green; LEDS.show(); break;
      case 2: leds[2] = CRGB::Green; LEDS.show(); break;
      case 3: leds[3] = CRGB::Green; LEDS.show(); break;
      case 4: leds[4] = CRGB::Green; LEDS.show(); break;
      case 5: leds[5] = CRGB::Green; LEDS.show(); break;
      case 6: leds[6] = CRGB::Green; LEDS.show(); break;
      case 7: leds[7] = CRGB::Green; LEDS.show(); break;
      case 8: leds[8] = CRGB::Green; LEDS.show(); break;
      case 9: leds[9] = CRGB::Green; LEDS.show(); break;
      case 10: leds[10] = CRGB::Green; LEDS.show(); break;
      case 11: leds[11] = CRGB::Green; LEDS.show(); break;
      case 12: leds[12] = CRGB::Green; LEDS.show(); break;
      case 13: leds[13] = CRGB::Green; LEDS.show(); break;
      case 14: leds[14] = CRGB::Green; LEDS.show(); break;
      case 15: leds[15] = CRGB::Green; LEDS.show(); break;
      case 16: leds[16] = CRGB::Green; LEDS.show(); break;
      case 17: leds[17] = CRGB::Green; LEDS.show(); break;
      case 18: leds[18] = CRGB::Green; LEDS.show(); break;
      case 19: leds[19] = CRGB::Green; LEDS.show(); break;
      case 20: leds[20] = CRGB::Green; LEDS.show(); break;
      case 21: leds[21] = CRGB::Green; LEDS.show(); break;
      case 22: leds[22] = CRGB::Green; LEDS.show(); break;
      case 23: leds[23] = CRGB::Green; LEDS.show(); break;
      case 24: leds[24] = CRGB::Green; LEDS.show(); break;
      case 25: leds[25] = CRGB::Green; LEDS.show(); break;
      case 26: leds[26] = CRGB::Green; LEDS.show(); break;
      case 27: leds[27] = CRGB::Green; LEDS.show(); break;
      case 28: leds[28] = CRGB::Green; LEDS.show(); break;
      case 29: leds[29] = CRGB::Green; LEDS.show(); break;
      case 30: leds[30] = CRGB::Green; LEDS.show(); break;
      case 31: leds[31] = CRGB::Green; LEDS.show(); break;
      case 32: leds[32] = CRGB::Green; LEDS.show(); break;
      case 33: leds[33] = CRGB::Green; LEDS.show(); break;
      case 34: leds[34] = CRGB::Green; LEDS.show(); break;
      case 35: leds[35] = CRGB::Green; LEDS.show(); break;
      case 36: leds[36] = CRGB::Green; LEDS.show(); break;
      case 37: leds[37] = CRGB::Green; LEDS.show(); break;
      case 38: leds[38] = CRGB::Green; LEDS.show(); break;
      case 39: leds[39] = CRGB::Green; LEDS.show(); break;
      case 40: leds[40] = CRGB::Green; LEDS.show(); break;
      case 41: leds[41] = CRGB::Green; LEDS.show(); break;
      case 42: leds[42] = CRGB::Green; LEDS.show(); break;
      case 43: leds[43] = CRGB::Green; LEDS.show(); break;
      case 44: leds[44] = CRGB::Green; LEDS.show(); break;
      case 45: leds[45] = CRGB::Green; LEDS.show(); break;
      case 46: leds[46] = CRGB::Green; LEDS.show(); break;
      case 47: leds[47] = CRGB::Green; LEDS.show(); break;
      case 48: leds[48] = CRGB::Green; LEDS.show(); break;
      case 49: leds[49] = CRGB::Green; LEDS.show(); break;
      case 50: leds[50] = CRGB::Green; LEDS.show(); break;
      case 51: leds[51] = CRGB::Green; LEDS.show(); break;
      case 52: leds[52] = CRGB::Green; LEDS.show(); break;
      case 53: leds[53] = CRGB::Green; LEDS.show(); break;
      case 54: leds[54] = CRGB::Green; LEDS.show(); break;
      case 55: leds[55] = CRGB::Green; LEDS.show(); break;
      case 56: leds[56] = CRGB::Green; LEDS.show(); break;
      case 57: leds[57] = CRGB::Green; LEDS.show(); break;
      case 58: leds[58] = CRGB::Green; LEDS.show(); break;
      case 59: leds[59] = CRGB::Green; LEDS.show(); break;
      case 60: leds[60] = CRGB::Green; LEDS.show(); break;
      case 61: leds[61] = CRGB::Green; LEDS.show(); break;
      case 62: leds[62] = CRGB::Green; LEDS.show(); break;
      case 63: leds[63] = CRGB::Green; LEDS.show(); break;
      case 64: leds[64] = CRGB::Green; LEDS.show(); break;
      case 65: leds[65] = CRGB::Green; LEDS.show(); break;
      case 66: leds[66] = CRGB::Green; LEDS.show(); break;
      case 67: leds[67] = CRGB::Green; LEDS.show(); break;
      case 68: leds[68] = CRGB::Green; LEDS.show(); break;
      case 69: leds[69] = CRGB::Green; LEDS.show(); break;
      case 70: leds[70] = CRGB::Green; LEDS.show(); break;
      case 71: leds[71] = CRGB::Green; LEDS.show(); break;
      case 72: leds[72] = CRGB::Green; LEDS.show(); break;
      case 73: leds[73] = CRGB::Green; LEDS.show(); break;
      case 74: leds[74] = CRGB::Green; LEDS.show(); break;
      case 75: leds[75] = CRGB::Green; LEDS.show(); break;
      case 76: leds[76] = CRGB::Green; LEDS.show(); break;
      case 77: leds[77] = CRGB::Green; LEDS.show(); break;
      case 78: leds[78] = CRGB::Green; LEDS.show(); break;
      case 79: leds[79] = CRGB::Green; LEDS.show(); break;
      case 80: leds[80] = CRGB::Green; LEDS.show(); break;
      case 81: leds[81] = CRGB::Green; LEDS.show(); break;
      case 82: leds[82] = CRGB::Green; LEDS.show(); break;
      case 83: leds[83] = CRGB::Green; LEDS.show(); break;
      case 84: leds[84] = CRGB::Green; LEDS.show(); break;
      case 85: leds[85] = CRGB::Green; LEDS.show(); break;
      case 86: leds[86] = CRGB::Green; LEDS.show(); break;
      case 87: leds[87] = CRGB::Green; LEDS.show(); break;
      case 88: leds[88] = CRGB::Green; LEDS.show(); break;
      case 89: leds[89] = CRGB::Green; LEDS.show(); break;
      case 90: leds[90] = CRGB::Green; LEDS.show(); break;
      case 91: leds[91] = CRGB::Green; LEDS.show(); break;
      case 92: leds[92] = CRGB::Green; LEDS.show(); break;
      case 93: leds[93] = CRGB::Green; LEDS.show(); break;
      case 94: leds[94] = CRGB::Green; LEDS.show(); break;
      case 95: leds[95] = CRGB::Green; LEDS.show(); break;
      case 96: leds[96] = CRGB::Green; LEDS.show(); break;
      case 97: leds[97] = CRGB::Green; LEDS.show(); break;
      case 98: leds[98] = CRGB::Green; LEDS.show(); break;
      case 99: leds[99] = CRGB::Green; LEDS.show(); break;
      case 100: leds[100] = CRGB::Green; LEDS.show(); break;
      case 101: leds[101] = CRGB::Green; LEDS.show(); break;
      case 102: leds[102] = CRGB::Green; LEDS.show(); break;
      case 103: leds[103] = CRGB::Green; LEDS.show(); break;
      case 104: leds[104] = CRGB::Green; LEDS.show(); break;
      case 105: leds[105] = CRGB::Green; LEDS.show(); break;
      case 106: leds[106] = CRGB::Green; LEDS.show(); break;
      case 107: leds[107] = CRGB::Green; LEDS.show(); break;
      case 108: leds[108] = CRGB::Green; LEDS.show(); break;
      case 109: leds[109] = CRGB::Green; LEDS.show(); break;
      case 110: leds[110] = CRGB::Green; LEDS.show(); break;
      case 111: leds[111] = CRGB::Green; LEDS.show(); break;
      case 112: leds[112] = CRGB::Green; LEDS.show(); break;
      case 113: leds[113] = CRGB::Green; LEDS.show(); break;
      case 114: leds[114] = CRGB::Green; LEDS.show(); break;
      case 115: leds[115] = CRGB::Green; LEDS.show(); break;
      case 116: leds[116] = CRGB::Green; LEDS.show(); break;
      case 117: leds[117] = CRGB::Green; LEDS.show(); break;
      case 118: leds[118] = CRGB::Green; LEDS.show(); break;
      case 119: leds[119] = CRGB::Green; LEDS.show(); break;
      case 120: leds[120] = CRGB::Green; LEDS.show(); break;
      case 121: leds[121] = CRGB::Green; LEDS.show(); break;
      case 122: leds[122] = CRGB::Green; LEDS.show(); break;
      case 123: leds[123] = CRGB::Green; LEDS.show(); break;
      case 124: leds[124] = CRGB::Green; LEDS.show(); break;
      case 125: leds[125] = CRGB::Green; LEDS.show(); break;
      case 126: leds[126] = CRGB::Green; LEDS.show(); break;
      case 127: leds[127] = CRGB::Green; LEDS.show(); break;
      case 128: leds[128] = CRGB::Green; LEDS.show(); break;
      case 129: leds[129] = CRGB::Green; LEDS.show(); break;
      case 130: leds[130] = CRGB::Green; LEDS.show(); break;
      case 131: leds[131] = CRGB::Green; LEDS.show(); break;
      case 132: leds[132] = CRGB::Green; LEDS.show(); break;
      case 133: leds[133] = CRGB::Green; LEDS.show(); break;
      case 134: leds[134] = CRGB::Green; LEDS.show(); break;
      case 135: leds[135] = CRGB::Green; LEDS.show(); break;
      case 136: Russia(0, 255, 0); LEDS.show(); break;
      case 137: Finland(0, 255, 0); LEDS.show(); break;
      case 138: Sweden(0, 255, 0); LEDS.show(); break;
      case 139: Germany(0, 255, 0); LEDS.show(); break;
      case 140: Switzerland(0, 255, 0); LEDS.show(); break;
      case 141: France(0, 255, 0); LEDS.show(); break;
      case 142: Belgium(0, 255, 0); LEDS.show(); break;
      case 143: Netherlands(0, 255, 0); LEDS.show(); break;
      case 144: UK(0, 255, 0); LEDS.show(); break;
      case 145: Spain(0, 255, 0); LEDS.show(); break;
      case 146: Slovenia(0, 255, 0); LEDS.show(); break;
      case 147: Hungary(0, 255, 0); LEDS.show(); break;
      case 148: Slovakia(0, 255, 0); LEDS.show(); break;
      case 149: Czech(0, 255, 0); LEDS.show(); break;
      case 150: Belorussia(0, 255, 0); LEDS.show(); break;
      case 151: Litva(0, 255, 0); LEDS.show(); break;
      case 152: Ukraine(0, 255, 0); LEDS.show(); break;
      case 153: Romania(0, 255, 0); LEDS.show(); break;
      case 154: Bulgaria(0, 255, 0); LEDS.show(); break;
      case 155: Turkey(0, 255, 0); LEDS.show(); break;
      case 156: Iordania(0, 255, 0); LEDS.show(); break;
      case 157: Armenia(0, 255, 0); LEDS.show(); break;
      case 158: Kazahstan(0, 255, 0); LEDS.show(); break;
      case 159: UAE(0, 255, 0); LEDS.show(); break;
      case 160: Iran(0, 255, 0); LEDS.show(); break;
      case 161: Africa(0, 255, 0); LEDS.show(); break;
      case 162: Pakistan(0, 255, 0); LEDS.show(); break;
      case 163: India(0, 255, 0); LEDS.show(); break;
      case 164: Bangladesh(0, 255, 0); LEDS.show(); break;
      case 165: China(0, 255, 0); LEDS.show(); break;
      case 166: Taiwan(0, 255, 0); LEDS.show(); break;
      case 167: Vietnam(0, 255, 0); LEDS.show(); break;
      case 168: Korea(0, 255, 0); LEDS.show(); break;
      case 169: KNDR(0, 255, 0); LEDS.show(); break;
      case 170: Japan(0, 255, 0); LEDS.show(); break;
      case 171: Mexico(0, 255, 0); LEDS.show(); break;
      case 172: Argentina(0, 255, 0); LEDS.show(); break;
      case 173: Brazil(0, 255, 0); LEDS.show(); break;
      case 174: Canada(0, 255, 0); LEDS.show(); break;
      case 175: USA(0, 255, 0); LEDS.show(); break;
      case 255: pulse_one_color_all(); LEDS.show(); break;
      default: pulse_one_color_all(); LEDS.show(); break;
    }
  }
}
