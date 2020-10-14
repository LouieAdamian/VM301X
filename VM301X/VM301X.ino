#include <Wire.h>
#include "esp_log.h"
#include <VM301X.h>
#define TRIG_pin 21
#define sda_pin 23
#define scl_pin 22
uint8_t thresh;
VM301X vm;

void setup() {
  esp_log_level_set("*", ESP_LOG_ERROR); 
   
  gpio_set_drive_capability((gpio_num_t)sda_pin, GPIO_DRIVE_CAP_3);
  gpio_set_drive_capability((gpio_num_t)scl_pin, GPIO_DRIVE_CAP_3);
  Serial.begin(115200);
  Serial.println("VM301x Example");
  pinMode(TRIG_pin,OUTPUT);
  delay(10);
  Wire.begin();
  Serial.println("Wire Begin");
  Serial.print("vm.begin returned: ");
  bool vmO = vm.begin();
  Serial.println(vmO);
  while(!vmO){
    
  }
   
}

void loop() {
  Serial.println("\n loop");
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_pin, 1);
  thresh = vm.readThresh();
  digitalWrite(TRIG_pin, 0);
  if(thresh != 0x7){
    Serial.print("thresh not returned correctly expected 0x7, got 0x");
    Serial.println(thresh,HEX);
  }
//  Serial.println(thresh);
  delayMicroseconds(100);
}
