/*
;    Project:       Open Vehicle Monitor System
;    Date:          14th March 2017
;
;    Changes:
;    1.0  Initial release
;
;    (C) 2011       Michael Stegen / Stegen Electronics
;    (C) 2011-2017  Mark Webb-Johnson
;    (C) 2011        Sonny Chen @ EPRO/DX
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#ifndef __PERIPHERALS_H__
#define __PERIPHERALS_H__

#include "pcp.h"
#include "spi.h"
#include "esp32system.h"

#ifdef CONFIG_OVMS_COMP_ADC
#include "esp32adc.h"
#endif // #ifdef CONFIG_OVMS_COMP_ADC

#ifdef CONFIG_OVMS_COMP_MCP2515
#include "mcp2515.h"
#endif // #ifdef CONFIG_OVMS_COMP_MCP2515

#ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN
#include "swcan.h"
#endif // #ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN

#ifdef CONFIG_OVMS_COMP_ESP32CAN
#include "esp32can.h"
#endif // #ifdef CONFIG_OVMS_COMP_ESP32CAN

#ifdef CONFIG_OVMS_COMP_MAX7317
#include "max7317.h"
#endif // #ifdef CONFIG_OVMS_COMP_MAX7317

#ifdef CONFIG_OVMS_COMP_BLUETOOTH
#include "esp32bluetooth.h"
#endif // #ifdef CONFIG_OVMS_COMP_BLUETOOTH

#ifdef CONFIG_OVMS_COMP_WIFI
#include "esp32wifi.h"
#endif // #ifdef CONFIG_OVMS_COMP_WIFI

#ifdef CONFIG_OVMS_COMP_SDCARD
#include "sdcard.h"
#endif // #ifdef CONFIG_OVMS_COMP_SDCARD

#ifdef CONFIG_OVMS_COMP_CELLULAR
#include "ovms_cellular.h"
#endif // #ifdef CONFIG_OVMS_COMP_CELLULAR

#ifdef CONFIG_OVMS_COMP_OBD2ECU
#include "obd2ecu.h"
#endif // #ifdef CONFIG_OVMS_COMP_OBD2ECU

#ifdef CONFIG_OVMS_COMP_EXT12V
#include "ext12v.h"
#endif // #ifdef CONFIG_OVMS_COMP_EXT12V


#define MODULE_GPIO_SW2           0       // SW2: firmware download / factory reset

// ------------------------------- Default GPIO mapping ------------------------------------------
#ifdef CONFIG_OVMS_HW_DEFAULT_GPIO_MAP

#define VSPI_PIN_MISO             19
#define VSPI_PIN_MOSI             23
#define VSPI_PIN_CLK              18

#define VSPI_PIN_MCP2515_1_CS     5
#define VSPI_PIN_MAX7317_CS       21
#define VSPI_PIN_MCP2515_2_CS     27
#define VSPI_PIN_MCP2515_1_INT    34
#define VSPI_PIN_MCP2515_2_INT    35

#define SDCARD_PIN_CLK            14
#define SDCARD_PIN_CMD            15
#define SDCARD_PIN_D0             2
#define SDCARD_PIN_CD             39

#define ESP32CAN_PIN_TX           25
#define ESP32CAN_PIN_RX           26

#define MAX7317_MDM_EN            0
#define MAX7317_SW_CTL            1
#define MAX7317_CAN1_EN           2
#define MAX7317_MDM_DTR           3
#define MAX7317_EGPIO_1           2
#define MAX7317_EGPIO_2           3
#define MAX7317_EGPIO_3           4
#define MAX7317_EGPIO_4           5
#define MAX7317_EGPIO_5           6
#define MAX7317_EGPIO_6           7
#define MAX7317_EGPIO_7           8
#define MAX7317_EGPIO_8           9

#ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN
#define MAX7317_SWCAN_MODE0         4   // EGPIO_3
#define MAX7317_SWCAN_MODE1         5   // EGPIO_4
#define VSPI_PIN_MCP2515_SWCAN_CS   33  // EXP2
#define VSPI_PIN_MCP2515_SWCAN_INT  32  // EXP1
#define MAX7317_SWCAN_STATUS_LED    7   // EGPIO_6
#define MAX7317_SWCAN_TX_LED        8   // EGPIO_7
#define MAX7317_SWCAN_RX_LED        9   // EGPIO_8
#endif // #ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN

#ifdef CONFIG_OVMS_HW_BASE_3_0
#define MODEM_GPIO_RX             16
#define MODEM_GPIO_TX             17
#endif // #ifdef CONFIG_OVMS_HW_BASE_3_0

#ifdef CONFIG_OVMS_HW_BASE_3_1
#define MODEM_GPIO_RX             13
#define MODEM_GPIO_TX             4
#endif // #ifdef CONFIG_OVMS_HW_BASE_3_1

#define MODEM_EGPIO_PWR           0
#define MODEM_EGPIO_DTR           3

#endif // CONFIG_HW_DEFAULT_GPIO_MAP

// ------------------------------ Alternative GPIO mapping ------------------------------------------
#ifdef CONFIG_OVMS_HW_REMAP_GPIO

#define VSPI_PIN_MISO             19
#define VSPI_PIN_MOSI             23
#define VSPI_PIN_CLK              18

#if defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10_A) || \
    defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10) || \
    defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V11)

// GPIO pin mapping for Lilygo T-Call A7670 V1.0 and V1.1 (modem interface)
//      Function   |   V1.0   |   V1.1
//      -----------+----------+----------
//      Modem TX   |   26     |   27
//      Modem RX   |   25     |   26
//      Modem DTR  |   14     |   32
//      Modem RING |   13     |   33
//      Modem PWR  |    4     |    4
//      Modem RESET|   27     |    5 

#ifdef CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10_A  // V1.0 on rev A board
    #define ESP32CAN_PIN_TX           32
    #define ESP32CAN_PIN_RX           34
    #define ESP32CAN_PIN_RS           33       // RS pin of CAN transceiver 
#endif // Rev A

#if defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10) || defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V11)  // V1.0 or V1.1 on rev B board
    #define ESP32CAN_PIN_TX            2     
    #define ESP32CAN_PIN_RX           34
    #define ESP32CAN_PIN_RS           21       // RS pin of CAN transceiver 
#endif // Rev B

#if defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10_A) || defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V10) // T-Call V1.0
    #define MODEM_GPIO_RX             25    
    #define MODEM_GPIO_TX             26   
    #define MODEM_GPIO_DTR            14   
    #define MODEM_GPIO_RING           13    // NOT USED
    #define MODEM_GPIO_RESET          27    //  NOT YET USED (active low)
#endif // V1.0

#if defined(CONFIG_OVMS_HW_GPIO_LILYGO_TC_V11)       // T-Call V1.1
    #define MODEM_GPIO_RX             26    
    #define MODEM_GPIO_TX             27   
    #define MODEM_GPIO_DTR            32   
    #define MODEM_GPIO_RING           33    // NOT USED
    #define MODEM_GPIO_RESET           5    // NOT YET USED (active low)
#endif // V1.1

// common for V1.0 and V1.1 and Rev A and B
    #define MODEM_GPIO_PWR             4    // switch POWERKEY of Modem (active high)
    #define VSPI_PIN_MCP2515_1_CS     22
    #define VSPI_PIN_MCP2515_1_INT    35
//    #define ADC_CHANNEL_12V            0    // Measure OBD 12V - GPIO36/SENSOR_VP
    #define MODEM_EGPIO_PWR           MODEM_GPIO_PWR // avoid problem with modem intialization
    #define MODEM_EGPIO_DTR           MODEM_GPIO_DTR
    #define VSPI_PIN_MCP2515_2_INT    -1    // dummy definition to avoid compiler error
    #define VSPI_PIN_MCP2515_2_CS     -1
#endif // Lilygo 

#endif  // CONFIG_OVMS_HW_REMAP_GPIO

class Peripherals : public InternalRamAllocated
  {
  public:
     Peripherals();
     ~Peripherals();

  public:
    esp32system* m_esp32;
    spi* m_spibus;

#ifdef CONFIG_OVMS_COMP_MAX7317
    max7317* m_max7317;
#endif // #ifdef CONFIG_OVMS_COMP_MAX7317

#ifdef CONFIG_OVMS_COMP_ESP32CAN
    esp32can* m_esp32can;
#endif // #ifdef CONFIG_OVMS_COMP_ESP32CAN

#ifdef CONFIG_OVMS_COMP_WIFI
    esp32wifi* m_esp32wifi;
#endif // #ifdef CONFIG_OVMS_COMP_WIFI

#ifdef CONFIG_OVMS_COMP_BLUETOOTH
    esp32bluetooth* m_esp32bluetooth;
#endif // #ifdef CONFIG_OVMS_COMP_BLUETOOTH

#ifdef CONFIG_OVMS_COMP_ADC
    esp32adc* m_esp32adc;
#endif // #ifdef CONFIG_OVMS_COMP_ADC

#ifdef CONFIG_OVMS_COMP_MCP2515
    mcp2515* m_mcp2515_1;
    mcp2515* m_mcp2515_2;
#endif // #ifdef CONFIG_OVMS_COMP_MCP2515

#ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN
    swcan* m_mcp2515_swcan;
#endif // #ifdef CONFIG_OVMS_COMP_EXTERNAL_SWCAN

#ifdef CONFIG_OVMS_COMP_SDCARD
    sdcard* m_sdcard;
#endif // #ifdef CONFIG_OVMS_COMP_SDCARD

#ifdef CONFIG_OVMS_COMP_CELLULAR
    modem* m_cellular_modem;
#endif // #ifdef CONFIG_OVMS_COMP_CELLULAR

#ifdef CONFIG_OVMS_COMP_OBD2ECU
    obd2ecu* m_obd2ecu;
#endif // #ifdef CONFIG_OVMS_COMP_OBD2ECU

#ifdef CONFIG_OVMS_COMP_EXT12V
    ext12v* m_ext12v;
#endif // #ifdef CONFIG_OVMS_COMP_EXT12V
  };

extern Peripherals* MyPeripherals;

#endif //#ifndef __PERIPHERALS_H__
