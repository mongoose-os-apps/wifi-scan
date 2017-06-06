# Scan WiFi networks on button press

## How to install this app

- Install and start [mos tool](https://mongoose-os.com/software.html)
- Switch to the Project page, find and import this app, build and flash it:

<p align="center">
  <img src="https://mongoose-os.com/images/app1.gif" width="75%">
</p>

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
button_cb            Click on pin 0, arg 0x0
mongoose_poll        New heap free LWM: 43120
mongoose_poll        New heap free LWM: 43008
scandone
wifi_scan_cb         WiFi scan: SSIDs 0x3fff1804, arg 0x0, results:
wifi_scan_cb         Got SSID [DIRECT-FD31860 Series]
wifi_scan_cb         Got SSID [eduroamboard]
wifi_scan_cb         Got SSID [Mongoose_A5930F]
wifi_scan_cb         Got SSID [IFTR Staff 2.4G]
wifi_scan_cb         Got SSID [Amethyst Guru WiFi]
wifi_scan_cb         Got SSID [NETs 3012 Staff]
wifi_scan_cb         WiFi scan done.
```
