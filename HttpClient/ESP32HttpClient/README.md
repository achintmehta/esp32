# ESP32 HTTP client
This is a simple HTTP client that does the following
1. Connect to Wireless network and obtain netowrk configuration
1. Download and print the contents of website www.example.com every 10 seconds

# Tools used
1. Arduino IDE
1. ESP32 SDK v 1.0.4

# Where do I find the secrets.h file
This project includes the secrets file that contains the wireless network credentials. 
The secrets.h file should look like this

```
#define WIFI_SSID "my_wifi_network_name"
#define WIFI_PASSWORD "my_wifi_network_password"
```

In order to be for Arduino IDE to find this file this file needs to be included in one of the following ways
## Adding the file to the sketch
You can add the secrets.h file to the sketch itself by following two ways
1. In the Arduino IDE click on the little dropdown button at the right (below the magnifying glass) or press Ctrl + Shift + N.THe IDE will prompt you tospecify the name of the file. Enter the name as secrets.h. The Arduino IDE will open the new file in a tab. Enter the above mentioned contents in the file and save.
1. If you have already created the file on the disk then you can include the file in Arduino IDE via Sketch > Add File option.

## Keeping the secrets file outside the sketch
Keeping the secrets file outside the sketch would make sense if you wantto share te file amon different sketches or if you intend to share the sketch and don't want the your network secrets to be included  in the sketch (they are secrets after all). In order to do so keep the secrets.h file in the <Arduino-Installation-Folder>\hardware\libraries path. You can also create a folder in this path and place the secrets.h in this folder. 
