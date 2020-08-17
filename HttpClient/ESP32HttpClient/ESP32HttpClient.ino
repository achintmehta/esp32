#include <WiFi.h>
#include <esp_http_client.h>
#include <esp_log.h>

/* Config section */
// Include this file from the system library as described in README.
// secrets.h defined the WIFI_SSID and WIFI_PASSWORD macros.
// If you do not wish to create/include this file then enter the 
// Wireless network name/password in the following fields
#include "secrets.h"
const char* ssid = WIFI_SSID; // WiFi network name 
const char* password = WIFI_PASSWORD; // Wifi Network password
const char* requestUrl = "http://www.example.com";

esp_http_client_config_t config;
esp_http_client_handle_t client;

esp_err_t _http_event_handler(esp_http_client_event_t *evt)
{
    switch(evt->event_id) {
        case HTTP_EVENT_ERROR:
            ESP_LOGI(TAG, "HTTP_EVENT_ERROR");
            break;
        case HTTP_EVENT_ON_CONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_CONNECTED");
            break;
        case HTTP_EVENT_HEADER_SENT:
            ESP_LOGI(TAG, "HTTP_EVENT_HEADER_SENT");
            break;
        case HTTP_EVENT_ON_HEADER:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_HEADER");
            printf("%.*s", evt->data_len, (char*)evt->data);
            break;
        case HTTP_EVENT_ON_DATA:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
            if (!esp_http_client_is_chunked_response(evt->client)) {
                printf("%.*s", evt->data_len, (char*)evt->data);
            }

            break;
        case HTTP_EVENT_ON_FINISH:
            ESP_LOGI(TAG, "HTTP_EVENT_ON_FINISH");
            break;
        case HTTP_EVENT_DISCONNECTED:
            ESP_LOGI(TAG, "HTTP_EVENT_DISCONNECTED");
            break;
    }
    return ESP_OK;
}

/* This functions connects to the WiFI network using DHCP */
void setup() {
  Serial.begin(115200); 

  esp_log_level_set("wifi", ESP_LOG_WARN); 
  esp_log_level_set("dhcpc", ESP_LOG_INFO); 
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  delay(1500);

  config.url = requestUrl;
  config.event_handler = _http_event_handler;


}



/* Requests the web page every 10 seconds */
void loop() {
   if(WiFi.status()== WL_CONNECTED){
    client = esp_http_client_init(&config);
    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
      ESP_LOGI(TAG, "Status = %d, content_length = %d",
           esp_http_client_get_status_code(client),
           esp_http_client_get_content_length(client));
    }
    esp_http_client_cleanup(client);
    delay(10000);
  }

}
