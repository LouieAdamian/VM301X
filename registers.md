feature| addresss| 7| 6 | 5 | 4 | 3 | 2 | 1 | 0 |Read/Write
------------ | ------------- | ------------- |------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- 
I2C Control | 0x0 |  |  |  | DOUT_Clear | RESURVED | WDT_DLY | WDT_DLY | WDT_EN | R/W
WOS_PGA_GAIN | 0x1 | | | | WOS_PGA_GAIN | WOS_PGA_GAIN | WOS_PGA_GAIN | WOS_PGA_GAIN | WOS_PGA_GAIN | R
WOS PGA MIN THR | 0x3 | | FAST_MODE_CNT | FAST_MODE_CNT | WOS_PGA_MIN_THR | WOS_PGA_MIN_THR| WOS_PGA_MIN_THR | WOS_PGA_MIN_THR | WOS_PGA_MIN_THR | R/W
WOS PGA MAX THR |0x4 | | | WOS_RMS| WOS_PGA_MAX_THR | WOS_PGA_MAX_THR| WOS_PGA_MAX_THR | WOS_PGA_MAX_THR | WOS_PGA_MAX_THR | R/W
WOS THRESH | 0x5 | | | | | | | | WOS_THRESH | R/W