# esp32
This repo contains sample programs for ESP32.


# Tools used
1. Arduino IDE
1. ESP32 SDK v 1.0.4

# Setting up the ESP32 environment in Arduino IDE
If this is your first time compiling an ESP32 sketch in Arduino IDE then you would need to to import the board configuration for ESP32 by following these steps
1. Go to File > Preferences
1. In the textbox labeled "Additional Board Manager URLs" enter the value "https://dl.espressif.com/dl/package_esp32_index.json"
1. Click OK
1. Go to Tools > Board > Boards Manager
1. The Boards Manager window will update all te board configurations. Once the window is ready then search for "esp32". The result should show "esp32" SDK "by Espressif sytems"
1. Click on Install
1. Once the ESP32 DK is installed, you should have the ESP32 boards available in the Tools > Board menu.

# The ESP32 API calls fail to compile
It is possible that dpending upon the version of ESP32 SDK you are using the API calls might not compile. The API calls may change over time.
In this case the best way to find out what the correct API calls is you might want to open the header file of the SDK version that your compiler/Arduino IDE is trying to link with.
You can find the include path in the output of the compiler when you try to compile the project e.g.

```
xtensa-esp32-elf-g++ ... -IC:\\<home-directory>\\AppData\\Local\\Arduino15\\packages\\esp32\\hardware\\esp32\\1.0.4/tools/sdk/include/esp_http_client
```
The path should contain the header file the sketch is including. So you could open the file and look at the exact signature of the APIs.

# Where do I find the secrets.h file
Some of the skecthes include the secrets file that contains the wireless network credentials. 
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
