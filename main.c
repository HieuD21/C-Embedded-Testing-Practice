#include <stdio.h>
#include "sensor.h"

void run_test_case(int test_id, int temperature, int voltage, SensorStatus expected_status) {
    SensorStatus actual_status = classify_sensor_status(temperature, voltage);

    printf("Test Case %d\n", test_id);
    printf("Input: temperature = %d, voltage = %d\n", temperature, voltage);
    printf("Expected: %s\n", status_to_string(expected_status));
    printf("Actual:   %s\n", status_to_string(actual_status));

    if (actual_status == expected_status) {
        printf("Result: PASS\n\n");
    } else {
        printf("Result: FAIL\n\n");
    }
}

int main() {
    printf("C Embedded-style Testing Practice\n\n");

    run_test_case(1, 25, 5000, SENSOR_OK);
    run_test_case(2, 101, 5000, SENSOR_WARNING);
    run_test_case(3, 25, 2500, SENSOR_WARNING);
    run_test_case(4, -41, 5000, SENSOR_ERROR);
    run_test_case(5, 126, 5000, SENSOR_ERROR);
    run_test_case(6, 25, -1, SENSOR_ERROR);
    run_test_case(7, 25, 5001, SENSOR_ERROR);
    run_test_case(8, -40, 0, SENSOR_WARNING);
    run_test_case(9, 125, 5000, SENSOR_WARNING);

    return 0;
}
