/**
 *    @file utils.h
 *  @author
 *    @date 13 July 2021
 *   @brief general code functions that used in different application
 */
#ifndef __UTILS_H
#define __UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "library/cJSON/cJSON.h"
#include "usart.h"
#include "stdint.h"
#define READ_ARRAY_SIZE 6
#define WRITE_ARRAY_SIZE 6
/* function */
typedef struct {
    uint32_t uTimeMillis;
    char cProject[100];
    char cVersion[50];
    char cController[50];
    char cBoardNo[50];
    char cThread[50];
    char cDescription[150];
    uint8_t uLoglevel;
    int8_t sPingRate;
    int16_t uLine;
    char sFunctionCall[100];
    double dRead[READ_ARRAY_SIZE];
    double dWrite[WRITE_ARRAY_SIZE];
}xJsonMessageStruct;

typedef xJsonMessageStruct xJsonMessageStruct_t;

/**
 * @brief unsigned int 16-bit data type mapping function which return the map value for a particular variable
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return mapped value of the function
 */
uint16_t u16UtilsMap(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max);
/**
 * @brief int 16-bit data type mapping function which return the map value for a particular variable
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return mapped value of the function
 */
int16_t s16UtilsMap(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max);
/**
 * @brief unsigned int 32-bit data type mapping function which return the map value for a particular variable
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return mapped value of the function
 */
uint32_t u32UtilsMap(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min, uint32_t out_max);
/**
 * @brief int 32-bit data type mapping function which return the map value for a particular variable
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return mapped value of the function
 */
/**
 * @brief printf Implementation function : http://www.emcu.eu/how-to-implement-printf-for-send-message-via-usb-on-stm32-nucleo-boards-using-atollic/
 *
 * @param ch : return the length of character
 * @return
 */

int __io_putchar(int ch);
/**
 * @fn int32_t s32UtilsMap(int32_t, int32_t, int32_t, int32_t, int32_t)
 * @brief  https://www.st.com/resource/en/user_manual/um2609-stm32cubeide-user-guide-stmicroelectronics.pdf
 *
 * @pre
 * @post
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return
 */
int32_t s32UtilsMap(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max);
/**
 * @fn float f32UtilsMap(float, float, float, float, float)
 * @brief
 *
 * @pre
 * @post
 * @param x
 * @param in_min
 * @param in_max
 * @param out_min
 * @param out_max
 * @return
 */
float f32UtilsMap(float x, float in_min, float in_max, float out_min, float out_max);
/**
 * @brief scanf Implementation function try not to fill the buffer.Other wise system will go unstable.
 *          Reference :  https://shawnhymel.com/1873/how-to-use-printf-on-stm32/
 * @param fd
 * @param ptr
 * @param len
 * @return
 */
int _read(int fd, char* ptr, int len);
/**
 * @brief string to float or int conversion
 * @param s
 * @return
 */
double atof(const char *s);
/**
 * @fn int sUtilsPrint_preallocated(cJSON*)
 * @brief will print the JSON format on the UART line
 *
 * @pre
 * @post
 * @param root
 * @return
 */
int8_t sUtilsPrint_preallocated(cJSON *root);
#ifdef __cplusplus
}
#endif

#endif /* __UTILS_H */
