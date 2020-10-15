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
#define debug false

struct bandpass_t{
    uint8_t hpf;
    uint8_t lpf;
};

class VM301X {
private:
    TwoWire *_i2cPort;
    uint8_t _i2caddr;
    uint8_t printI2CError(uint8_t errorCode);
    Stream *_debugSerial;
    
public:
    VM301X() {

    }
    ~VM301X() {
    }
    bool _printDebug = true;
    boolean begin(TwoWire &wirePort = Wire, uint32_t i2cSpeed = I2C_SPEED_STANDARD, uint8_t i2caddr = DEFAULT_ADDRESS);
    void writeRegister(uint8_t location, uint8_t val);  
    uint8_t readRegister(uint8_t location);
    uint8_t readByte(uint8_t location);
    uint8_t testi2c();

    void setBP(bandpass_t bp);
    void setThresh(uint8_t thresh);
    void setMinWosGain(uint8_t gain);
    void setMaxWosGain(uint8_t gain);
    void setFastModeCnt(uint8_t fm);
    uint8_t readGain();
    bandpass_t readBP();
    uint8_t readThresh();
    uint8_t readMinWosGain();
    uint8_t readMaxWosGain();
    uint8_t readFastModeCnt();
    uint8_t fast_mode_cnt = 0;
    uint8_t wos_min_gain = 0;
    uint8_t wos_rms = 0;
    uint8_t wos_max_gain = 0;
    enum wos_rms_t:bool{
        wos_rms_1 = 0,
        wos_rms_0_5 = 1
    };
    //selectable gain values in dBSPL 


};

enum wos_gain_t: uint8_t {
    wos_gain_91_5 = 0,
    wos_gain_90,
    wos_gain_88_5,
    wos_gain_87,
    wos_gain_85_5,
    wos_gain_84,
    wos_gain_82_5,
    wos_gain_81,
    wos_gain_79_5,
    wos_gain_78,
    wos_gain_76_5,
    wos_gain_75,
    wos_gain_73_5,
    wos_gain_72,
    wos_gain_70_5,
    wos_gain_68,
    wos_gain_67_5,
    wos_gain_66,
    wos_gain_64_5,
    wos_gain_63,
    wos_gain_61_5,
    wos_gain_60,
    wos_gain_58_5,
    wos_gain_57,
    wos_gain_55_5,
    wos_gain_54,
    wos_gain_52_5,
    wos_gain_51,
    wos_gain_49_5,
    wos_gain_48,
    wos_gain_46_5,
    wos_gain_45
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
enum fast_mode_cnt_t : uint8_t {
    fast_mode_disable,
    fast_mode_2,
    fast_mode_4,
    fast_mode_6
};


#endif //_VM301X_H_