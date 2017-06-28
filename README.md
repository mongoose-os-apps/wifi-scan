# Scan WiFi networks on button press

## Overview

This app demonstrates how to scan for available WiFi networks. WiFi scan
is triggered by a button press.

On NodeMCU and DevKitC, a button pin is already configured to pin 0,
which is a "Flash" button.
If you have your button on another GPIO pin, go to the configuration,
expert view, and change the pin number:

```
  "my_app": {
    "button_pin": 0
  }
```

Press on a button. You should see WiFi network list appearing on
your console:

```
[Jun 28 12:43:12.282] mgos_init            Init done, RAM: 257584 total, 182832 free, 182832 min free
[Jun 28 12:43:17.625] button_cb            Click on pin 0, arg 0x0. Starting WiFi scan.
[Jun 28 12:43:17.631] mgos_wifi_set_mode   WiFi mode: AP+STA
[Jun 28 12:43:17.641] I (10037) wifi: mode : sta (24:0a:c4:05:e8:f0) + softAP (24:0a:c4:05:e8:f1)
[Jun 28 12:43:17.646] event_handler        event: 2
[Jun 28 12:43:17.852] mongoose_poll        New heap free LWM: 182108
[Jun 28 12:43:18.008] esp32_wifi_ev        WiFi scan done: status 0, 14 APs
[Jun 28 12:43:18.013] event_handler        event: 1
[Jun 28 12:43:18.021] wifi_scan_cb         WiFi scan result: SSIDs 14, arg 0x0, results:
[Jun 28 12:43:18.030] wifi_scan_cb           ssid: DICT-D3C1860 Series , auth:  3, channel:  1, rssi: -54
[Jun 28 12:43:18.040] wifi_scan_cb           ssid: Cesanta             , auth:  3, channel:  1, rssi: -58
[Jun 28 12:43:18.078] wifi_scan_cb           ssid: Mongoose_0039F8     , auth:  3, channel:  6, rssi: -68
[Jun 28 12:43:18.116] wifi_scan_cb           ssid: FDFE        2.4G    , auth:  3, channel:  4, rssi: -78
[Jun 28 12:43:18.160] wifi_scan_cb         WiFi scan done.
```

## How to install this app

- Install and start [mos tool](https://mongoose-os.com/software.html)
- Switch to the Project page, find and import this app, build and flash it:

<p align="center">
  <img src="https://mongoose-os.com/images/app1.gif" width="75%">
</p>
