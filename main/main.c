/* Hello World Example


   This example code is in the Public Domain (or CC0 licensed, at your option.)


   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "ps3.h"
#include "nvs_flash.h"


void controller_event_cb( ps3_t ps3, ps3_event_t event )
{
    // Event handling here...
    if ( event.button_down.cross )
        printf("The user started pressing the X button\r\n");
    if ( event.button_up.cross )
        printf("The user released the X button\r\n");


    if ( event.button_down.square )
        printf("The user started pressing the square button\r\n");
    if ( event.button_up.square )
        printf("The user released the square button\r\n");


    if ( event.button_down.triangle )
        printf("The user started pressing the triangle button\r\n");
    if ( event.button_up.triangle )
        printf("The user released the triangle button\r\n");


    if ( event.button_down.circle )
        printf("The user started pressing the circle button\r\n");
    if ( event.button_up.circle )
        printf("The user released the circle button\r\n");


    if ( event.button_down.up )
        printf("The user started pressing the up button\r\n");
    if ( event.button_up.up )
        printf("The user released the up button\r\n");


    if ( event.button_down.down )
        printf("The user started pressing the down button\r\n");
    if ( event.button_up.down )
        printf("The user released the down button\r\n");


    if ( event.button_down.left )
        printf("The user started pressing the left button\r\n");
    if ( event.button_up.left )
        printf("The user released the left button\r\n");


    if ( event.button_down.right )
        printf("The user started pressing the right button\r\n");
    if ( event.button_up.right )
        printf("The user released the right button\r\n");


    if ( event.button_down.l1 )
        printf("The user started pressing the l1 button\r\n");
    if ( event.button_up.l1 )
        printf("The user released the l1 button\r\n");


    if ( event.button_down.l2 )
        printf("The user started pressing the l2 button\r\n");
    if ( event.button_up.l2 )
        printf("The user released the l2 button\r\n");


    if ( event.button_down.r1 )
        printf("The user started pressing the r1 button\r\n");
    if ( event.button_up.r1 )
        printf("The user released the r1 button\r\n");

    if ( event.button_down.r2 )
        printf("The user started pressing the r2 button\r\n");
    if ( event.button_up.r2 )
        printf("The user released the r2 button\r\n");

    // left stick
    if ( ps3.analog.stick.lx < 0 )
        printf("LEFT stick  ←←, value=%d\n",ps3.analog.stick.lx);
    
    if ( ps3.analog.stick.lx > 0 )
        printf("LEFT stick  →→, value=%d\n",ps3.analog.stick.lx);

    if ( ps3.analog.stick.ly < 0 )
        printf("LEFT stick  ↑↑, value=%d\n",ps3.analog.stick.ly);
    
    if ( ps3.analog.stick.ly > 0 )
        printf("LEFT stick  ↓↓, value=%d\n",ps3.analog.stick.ly);
    
    // right stick
    if ( ps3.analog.stick.rx < 0 )
        printf("RIGHT stick  ←←, value=%d\n",ps3.analog.stick.rx);
    
    if ( ps3.analog.stick.rx > 0 )
        printf("RIGHT stick  →→, value=%d\n",ps3.analog.stick.rx);

    if ( ps3.analog.stick.ry < 0 )
        printf("RIGHT stick  ↑↑, value=%d\n",ps3.analog.stick.ry);
    
    if ( ps3.analog.stick.ry > 0 )
        printf("RIGHT stick  ↓↓, value=%d\n",ps3.analog.stick.ry);
    /*
    printf("Accelerometer (x,y,z) and gyroscope (z):(%d,%d,%d)/(%d) \n",\
            ps3.sensor.accelerometer.x, ps3.sensor.accelerometer.y, \
            ps3.sensor.accelerometer.z, ps3.sensor.gyroscope.z); //gyroscope.z只有两个值：511/-12，其余正常
    */
}


void app_main()
{
    printf("Hello world!\n");
    esp_err_t ret;
    ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );
    ps3SetEventCallback(controller_event_cb);
    // uint8_t new_mac[8] = {0x11,0x22,0x33,0x44,0x55,0x66};
    // ps3SetBluetoothMacAddress(new_mac);
    ps3Init();


    while (!ps3IsConnected()){
        // Prevent the Task Watchdog from triggering
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    printf ("connected\r\n");
    while(1){
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    esp_restart();
}