#include "VM301X.h"

bool VM301X::begin(TwoWire &wirePort, uint32_t i2cSpeed , uint8_t i2caddr){
    _i2cPort = &wirePort;
    _i2cPort->begin();
    _i2cPort->setClock(i2cSpeed);
    _i2caddr = i2caddr;
    return (true);    
}
/**
 * @brief reads from a specific register and returns the data
 * 
 * @param location the regester to read from
 * @return the data from the register
 * 
 */
uint8_t VM301X::readRegister(uint8_t location) {
    uint8_t result; //Return value

    _i2cPort->beginTransmission(_i2caddr);
    _i2cPort->write(location);

    result = _i2cPort->endTransmission();
    #if debug
    Serial.print("readRegister request: ");
    Serial.println(result);
    #endif
    if ( result != 0 ) {
        printI2CError(result); 
        return (255); //Error
    }
    #if debug
    Serial.println("read result");
    #endif
    _i2cPort->requestFrom((int)_i2caddr, 1); //Ask for one byte
    while ( _i2cPort->available() ) {// slave may send more than requested
        result = _i2cPort->read();
    }

    return result;
}

void VM301X::writeRegister(uint8_t location, uint8_t val) {
  _i2cPort->beginTransmission(_i2caddr);
  _i2cPort->write(location);
  _i2cPort->write(val);
  _i2cPort->endTransmission();
}

uint8_t VM301X::printI2CError(uint8_t errorCode) {
    #if debug
    Serial.println("printI2CError");
    switch (errorCode) { //From: https://www.arduino.cc/en/Reference/WireEndTransmission
        case 0:
            Serial.println(F("Success"));
        break;
        case 1:
            Serial.println(F("Data too long to fit in transmit buffer"));
        break;
        case 2:
            Serial.println(F("Received NACK on transmit of address"));
        break;
        case 3:
            Serial.println(F("Received NACK on transmit of data"));
        break;
        case 4:
            Serial.println(F("Unknown error"));
        break;
    }
    Serial.print("I2C error: ");
    Serial.println(errorCode);
    #endif
    return (errorCode); //No matter what pass the code back out
}

void VM301X::setGain(uint8_t select){
        uint8_t gain =  31 - select;
        writeRegister(gainReg, gain);
}
void VM301X::setBP(uint8_t hpf, uint8_t lpf){
    
}
/**
 * @brief sets the wake on sound (WOS) threshhold in dBSPL
 * 
 * @param thersh sets the threshold from preset values(must be less than 8)
 */
void VM301X::setThresh(uint8_t thresh){
    writeRegister(wosThreshReg, thresh);
}

uint8_t VM301X::readThresh(){
    #if debug
    uint8_t thresh = readRegister(wosThreshReg);
    Serial.print("readThresh = ");
    Serial.println(thresh);
    return thresh;
    #else
    return readRegister(wosThreshReg);
    #endif
}