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
1. 
