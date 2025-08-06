#ifndef BSP_SPI_H
#define BSP_SPI_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include "struct_typedef.h"

extern void SPI1_DMA_init(uint32_t tx_buf, uint32_t rx_buf, uint16_t num);
extern void SPI1_DMA_enable(uint32_t tx_buf, uint32_t rx_buf, uint16_t ndtr);
#ifdef __cplusplus
}
#endif
#endif
