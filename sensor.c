#include "sensor.h"

int is_temperature_valid(int temperature) {
    if (temperature >= -40 && temperature <= 125) {
        return 1;
    }
    return 0;
}

int is_voltage_valid(int voltage) {
    if (voltage >= 0 && voltage <= 5000) {
        return 1;
    }
    return 0;
}

SensorStatus classify_sensor_status(int temperature, int voltage) {
    if (!is_temperature_valid(temperature) || !is_voltage_valid(voltage)) {
        return SENSOR_ERROR;
    }

    if (temperature > 100 || voltage < 3000) {
        return SENSOR_WARNING;
    }

    return SENSOR_OK;
}

const char* status_to_string(SensorStatus status) {
    switch (status) {
        case SENSOR_OK:
            return "OK";
        case SENSOR_WARNING:
            return "WARNING";
        case SENSOR_ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}
