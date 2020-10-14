

#ifndef _VM301X_H_
#define _VM301X_H_
#include "Arduino.h"
#include <Wire.h>

#define i2cControlReg 0
#define gainReg 1
#define wosFilterReg 2
#define minThreshReg 3
#define maxThershReg 4
#define wosThreshReg 5

#define I2C_SPEED_STANDARD 100000
#define DEFAULT_ADDRESS 0x60
#define debug true
class VM301X {
private:
    TwoWire *_i2cPort;
    uint8_t _i2caddr;
    uint8_t printI2CError(uint8_t errorCode);
    Stream *_debugSerial;
    
public:
    VM301X( ) {

    }
    ~VM301X() {

    }
    bool _printDebug = true;
    boolean begin(TwoWire &wirePort = Wire, uint32_t i2cSpeed = I2C_SPEED_STANDARD, uint8_t i2caddr = DEFAULT_ADDRESS);
    void writeRegister(uint8_t location, uint8_t val);  
    uint8_t readRegister(uint8_t location);

    void setGain(uint8_t select);
    void setBP(uint8_t hpf, uint8_t lpf);
    void setThresh(uint8_t thresh);
    void setMinPgaGain(uint8_t gain);
    void setMaxPgaGain(uint8_t gain);
    uint8_t readGain();
    uint8_t* readBP();
    uint8_t readThresh();
    uint8_t readMinPgaGain();
    uint8_t readMaxPgaGain();

    uint8_t fast_mode_cnt;
    uint8_t pga_min_thr;
    bool wos_rms = false;
    uint8_t pga_max_thr;

    enum wos_rms_t:bool{
        wos_rms_1 = 0,
        wos_rms_0_5 = 1
    };
    //selectable gain values in dBSPL 
    enum pga_gain_t: uint8_t {
        pga_gain_91_5 = 0,
        pga_gain_90,
        pga_gain_88_5,
        pga_gain_87,
        pga_gain_85_5,
        pga_gain_84,
        pga_gain_82_5,
        pga_gain_81,
        pga_gain_79_5,
        pga_gain_78,
        pga_gain_76_5,
        pga_gain_75,
        pga_gain_73_5,
        pga_gain_72,
        pga_gain_70_5,
        pga_gain_68,
        pga_gain_67_5,
        pga_gain_66,
        pga_gain_64_5,
        pga_gain_63,
        pga_gain_61_5,
        pga_gain_60,
        pga_gain_58_5,
        pga_gain_57,
        pga_gain_55_5,
        pga_gain_54,
        pga_gain_52_5,
        pga_gain_51,
        pga_gain_49_5,
        pga_gain_48,
        pga_gain_46_5,
        pga_gain_45
    };

    // lowpass filter frequency in hz
    enum lpf_t: uint8_t {
        lpf_2000 = 0,
        lpf_4000,
        lpf_6000,
        lpf_8000
    };

    // highpass filter frequency in hz
    enum hpf_t : uint8_t{
        hpf_200 = 0,
        hpf_300,
        hpf_400,
        hpf_800,
    };

    // wake on sound threshhold in dBSPL
    enum wos_thresh_t : uint8_t{
        wos_thresh_6 = 1,
        wos_thresh_9_5,
        wos_thresh_12,
        wos_thresh_14,
        wos_thresh_15_5,
        wos_thresh_16_9,
        wos_thresh_18
    };

};

#endif //_VM301X_H_