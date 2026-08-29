#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>
#include <MPU6500_WE.h> 

class IMU {
public:
    MPU6500_WE mpu = MPU6500_WE(0x68);

    bool begin() {
        Wire.begin(21, 22); 
        delay(100);

        if (!mpu.init()) {
            return false;
        }

        // Calibrate offsets and apply your previous configuration ranges
        mpu.autoOffsets();
        mpu.setAccRange(MPU6500_ACC_RANGE_4G);
        mpu.setGyrRange(MPU6500_GYRO_RANGE_500);
        
        // Enable Digital Low Pass Filter (~41Hz)
        mpu.enableGyrDLPF();
        mpu.setGyrDLPF(MPU6500_DLPF_3); 
        
        return true;
    }

    bool update() {
        // Data is fetched on demand by the get functions below
        return true; 
    }

    float getAccX() { return mpu.getGValues().x; }
    float getAccY() { return mpu.getGValues().y; }
    float getAccZ() { return mpu.getGValues().z; }

    float getGyroX() { return mpu.getGyrValues().x; }
    float getGyroY() { return mpu.getGyrValues().y; }
    float getGyroZ() { return mpu.getGyrValues().z; }

    // Stubbed magnetometer functions to prevent breaking references in main_v2.ino
    float getMagX() { return 0.0f; }
    float getMagY() { return 0.0f; }
    float getMagZ() { return 0.0f; }
};

#endif
