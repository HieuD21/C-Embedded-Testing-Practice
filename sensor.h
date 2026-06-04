#ifndef SENSOR_H
#define SENSOR_H

typedef enum {
    SENSOR_OK = 0,
    SENSOR_WARNING = 1,
    SENSOR_ERROR = 2
} SensorStatus;

typedef struct {
    int temperature;
    int voltage;
    SensorStatus status;
} SensorData;

int is_temperature_valid(int temperature);
int is_voltage_valid(int voltage);
SensorStatus classify_sensor_status(int temperature, int voltage);
const char* status_to_string(SensorStatus status);

#endif
