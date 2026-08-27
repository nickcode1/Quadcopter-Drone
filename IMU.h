#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>
#include <MPU9250.h>

class IMU
{
public:

    MPU9250 mpu;

   bool begin()
    {
    Wire.begin(21, 22);  // SDA, SCL
    delay(100);

    mpu.verbose(true);   // <-- add this line temporarily

    MPU9250Setting setting;
    setting.accel_fs_sel     = ACCEL_FS_SEL::A4G;
    setting.gyro_fs_sel      = GYRO_FS_SEL::G500DPS;
    setting.gyro_dlpf_cfg    = GYRO_DLPF_CFG::DLPF_41HZ;
    setting.accel_dlpf_cfg   = ACCEL_DLPF_CFG::DLPF_45HZ;
    setting.fifo_sample_rate = FIFO_SAMPLE_RATE::SMPL_1000HZ;

    return mpu.setup(0x68, setting);
    }

    bool update()
    {
        return mpu.update();
    }

    float getAccX() { return mpu.getAccX(); }
    float getAccY() { return mpu.getAccY(); }
    float getAccZ() { return mpu.getAccZ(); }

    float getGyroX() { return mpu.getGyroX(); }
    float getGyroY() { return mpu.getGyroY(); }
    float getGyroZ() { return mpu.getGyroZ(); }

    float getMagX() { return mpu.getMagX(); }
    float getMagY() { return mpu.getMagY(); }
    float getMagZ() { return mpu.getMagZ(); }
};

#endif