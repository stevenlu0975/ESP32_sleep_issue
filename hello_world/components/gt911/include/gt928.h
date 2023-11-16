#ifndef __GT928_H
#define __GT928_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define GT928_I2C_SLAVE_ADDR   0x5D

#define GT928_PRODUCT_ID_LEN   4

/* Register Map of GT928 */
#define GT928_PRODUCT_ID1             0x8140
#define GT928_PRODUCT_ID2             0x8141
#define GT928_PRODUCT_ID3             0x8142
#define GT928_PRODUCT_ID4             0x8143

#define GT928_FIRMWARE_VER_L          0x8144
#define GT928_FIRMWARE_VER_H          0x8145

#define GT928_X_COORD_RES_L           0x8146
#define GT928_X_COORD_RES_H           0x8147
#define GT928_Y_COORD_RES_L           0x8148
#define GT928_Y_COORD_RES_H           0x8149

#define GT928_VENDOR_ID               0x814A

#define GT928_STATUS_REG              0x814E
#define   GT928_STATUS_REG_BUF        0x80
#define   GT928_STATUS_REG_LARGE      0x40
#define   GT928_STATUS_REG_RESERVED   0x20
#define   GT928_STATUS_REG_HAVEKEY    0x10
#define   GT928_STATUS_REG_PT_MASK    0x0F

#define GT928_TRACK_ID1               0x814F
#define GT928_PT1_X_COORD_L           0x8150
#define GT928_PT1_X_COORD_H           0x8151
#define GT928_PT1_Y_COORD_L           0x8152
#define GT928_PT1_Y_COORD_H           0x8153
#define GT928_PT1_X_SIZE_L            0x8154
#define GT928_PT1_X_SIZE_H            0x8155

typedef struct {
    bool inited;
    char product_id[GT928_PRODUCT_ID_LEN];
    uint16_t max_x_coord;
    uint16_t max_y_coord;
    uint8_t i2c_dev_addr;
} GT928_status_t;

void GT928_init(int8_t sda, int8_t scl, int8_t intr_pin, uint8_t dev_addr);

void GT928_read_status(uint16_t* x, uint16_t* y, uint8_t* touched);

#ifdef __cplusplus
}
#endif
#endif /* __GT928_H */


