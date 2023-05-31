#include "esphome.h"

class A02YYUW: public PollingComponent, public Sensor, public UARTDevice {
 public:
  A02YYUW(UARTComponent *parent) : PollingComponent(500), UARTDevice(parent) {}

  void setup() override {
    // nothing to do here
  }
  void update() override {
    while (available() >= 4) {
      char h = read();
      if (h != 0xFF)
	      continue;
      char d_h = read();
      char d_l = read();
      char sum = read();
      char check_sum = ((int)(h+d_h+d_l)) & 0x00FF;
      if (check_sum == sum) {
	float meters = ((float)d_h*256+d_l)/1000.0;
	publish_state(meters);
      }
    }
    // etc
  }
};
