#include "mgos.h"

static void wifi_scan_cb(int n, struct mgos_wifi_scan_result *res, void *arg) {
  LOG(LL_INFO, ("WiFi scan result: SSIDs %d, arg %p, results:", n, arg));
  for (int i = 0; i < n; i++) {
    LOG(LL_INFO,
        ("  SSID: %-32s, BSSID: %02x:%02x:%02x:%02x:%02x:%02x "
         "auth: %d, channel: %3d, RSSI: %2d",
         res[i].ssid, res[i].bssid[0], res[i].bssid[1], res[i].bssid[2],
         res[i].bssid[3], res[i].bssid[4], res[i].bssid[5], res[i].auth_mode,
         res[i].channel, res[i].rssi));
  }
  LOG(LL_INFO, ("WiFi scan done."));
}

static void button_cb(int pin, void *arg) {
  char buf[8];
  LOG(LL_INFO, ("Button press on pin %s, arg %p. Starting WiFi scan.",
                mgos_gpio_str(pin, buf), arg));
  mgos_wifi_scan(wifi_scan_cb, NULL);
}

static void wifi_cb(int ev, void *evd, void *arg) {
  const struct mgos_net_event_data *ev_data =
      (const struct mgos_net_event_data *) evd;
  if (ev_data->if_type != MGOS_NET_IF_TYPE_WIFI) return;
  LOG(LL_INFO, ("WiFi change event: %d, arg %p", (int) ev, arg));
}

enum mgos_app_init_result mgos_app_init(void) {
  char buf[8];
  int btn_pin = mgos_sys_config_get_board_btn1_pin();
  mgos_gpio_set_button_handler(btn_pin, MGOS_GPIO_PULL_UP,
                               MGOS_GPIO_INT_EDGE_POS, 200, button_cb, NULL);
  mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, wifi_cb, NULL);
  LOG(LL_INFO,
      ("Button is configured on pin %s.", mgos_gpio_str(btn_pin, buf)));
  LOG(LL_INFO, ("Click on a button to initialise WiFi scan."));
  return MGOS_APP_INIT_SUCCESS;
}
