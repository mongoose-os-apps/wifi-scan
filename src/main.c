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

static void timer_cb(void *arg) {
  LOG(LL_INFO, ("Starting WiFi scan"));
  mgos_wifi_scan(wifi_scan_cb, NULL);
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  if (mgos_sys_config_get_scan_interval_ms() > 0) {
    mgos_set_timer(mgos_sys_config_get_scan_interval_ms(),
                   MGOS_TIMER_REPEAT | MGOS_TIMER_RUN_NOW, timer_cb, NULL);
  }
  return MGOS_APP_INIT_SUCCESS;
}
