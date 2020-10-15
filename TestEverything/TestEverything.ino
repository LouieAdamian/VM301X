#include <Wire.h>
#include <VM301X.h>

VM301X vm;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  vm.begin();
    

  //test everything  
  Serial.println("Bandpass test ------------------");
//  vm.setBP(hpf_300, lpf_6000);
      uint8_t val = 0;
    val |= (hpf_300<<2) & 0b00001100; // 0x0C
    val |= (lpf_6000<<0) & 0b00000011;
    vm.writeRegister(wosFilterReg, val);
  Serial.println("set Bandpass with low of 300 and high of 6000");
  uint8_t* bp = vm.readBP();
  if(bp[0] != (uint8_t) hpf_300  ) {
    Serial.println("ERROR on Bandpass");
  }
  else if(bp[1] != (uint8_t) lpf_6000){
    Serial.println("ERROR on Bandpass");
  }
  else{
    Serial.println("Bandpass ok");
  }
  
  Serial.print("Highpass set at ");
  Serial.print((hpf_t)bp[0]);
  Serial.print(", and lowpass set at ");
  Serial.println((lpf_t)bp[1]);
  Serial.println("Wake os sound Min Gain test ----");
  vm.setMinWosGain(wos_gain_55_5);
  Serial.println("Set Wos Min gain to 55.5");
  uint8_t gain = vm.readMinWosGain();
}

void loop() {
}
