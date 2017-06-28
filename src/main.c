#include "fw/src/mgos.h"

static void wifi_scan_cb(int n, struct mgos_wifi_scan_result *res, void *arg) {
  LOG(LL_INFO, ("WiFi scan result: SSIDs %d, arg %p, results:", n, arg));
  for (int i = 0; i < n; i++) {
    LOG(LL_INFO, ("  SSID: %-32s, auth: %2d, channel: %2d, RSSI: %2d",
                  res[i].ssid, res[i].auth_mode, res[i].channel, res[i].rssi));
  }
  LOG(LL_INFO, ("WiFi scan done."));
}

static void button_cb(int pin, void *arg) {
  LOG(LL_INFO, ("Click on pin %d, arg %p. Starting WiFi scan.", pin, arg));
  mgos_wifi_scan(wifi_scan_cb, NULL);
}

static void wifi_cb(enum mgos_wifi_status event, void *arg) {
  LOG(LL_INFO, ("WiFi change event: %d, arg %p", (int) event, arg));
}

enum mgos_app_init_result mgos_app_init(void) {
  int pin = get_cfg()->my_app.button_pin;
  mgos_gpio_set_button_handler(pin, MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_POS,
                               200, button_cb, NULL);
  mgos_wifi_add_on_change_cb(wifi_cb, NULL);
  LOG(LL_INFO, ("Button is configured on GPIO %d.", pin));
  LOG(LL_INFO, ("Click on a button to initialise WiFi scan."));
  return MGOS_APP_INIT_SUCCESS;
}
