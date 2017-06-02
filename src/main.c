#include "fw/src/mgos.h"

static void wifi_scan_cb(const char **ssids, void *arg) {
  LOG(LL_INFO, ("WiFi scan: SSIDs %p, arg %p, results:", ssids, arg));
  while (ssids != NULL && *ssids != NULL) {
    LOG(LL_INFO, ("Got SSID [%s]", *ssids));
    ssids++;
  }
  LOG(LL_INFO, ("WiFi scan done."));
}

static void button_cb(int pin, void *arg) {
  LOG(LL_INFO, ("Click on pin %d, arg %p", pin, arg));
  mgos_wifi_scan(wifi_scan_cb, NULL);
}

static void wifi_cb(enum mgos_wifi_status event, void *arg) {
  LOG(LL_INFO, ("WiFi change event: %d, arg %p", (int) event, arg));
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_gpio_set_button_handler(get_cfg()->my_app.button_pin,
                               MGOS_GPIO_PULL_UP, MGOS_GPIO_INT_EDGE_POS, 200,
                               button_cb, NULL);
  mgos_wifi_add_on_change_cb(wifi_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
