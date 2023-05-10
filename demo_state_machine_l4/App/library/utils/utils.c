/**
 *    @file utils.c
 *  @author pranav Kumar(pranav083)
 *    @date 13 july 2021
 *   @brief general code functions that used in different application
 */
#include "main.h"
#include "string.h"
#include "stdio.h"
//#include "appConfig.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "library/cJSON/cJSON.h"
//#include "usart.h"

#define isdigit(c) (c >= '0' && c <= '9')

/**
 * @brief look for the header file for the different function working
 *   @def don't make function made of long as in a 32-bit system as both the int
 *        and long are of same size in a 32-bit system.
 */
uint16_t u16UtilsMap(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min,
        uint16_t out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int16_t s16UtilsMap(int16_t x, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
uint32_t u32UtilsMap(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min,
        uint32_t out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int32_t s32UtilsMap(int32_t x, int32_t in_min, int32_t in_max, int32_t out_min, int32_t out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
float f32UtilsMap(float x, float in_min, float in_max, float out_min, float out_max){
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/**
 * @brief printf Implementation function : http://www.emcu.eu/how-to-implement-printf-for-send-message-via-usb-on-stm32-nucleo-boards-using-atollic/
 *
 * @param ch : return the length of character
 * @return
 */
int __io_putchar(int ch)
{
 uint8_t c[1];
 c[0] = ch & 0x00FF;
 HAL_UART_Transmit(&huart2, &*c, 1, 10);
 return ch;
}

int _write(int file,char *ptr, int len)
{
 int DataIdx;
 for(DataIdx= 0; DataIdx< len; DataIdx++)
 {
 __io_putchar(*ptr++);
 }
return len;
}

#define STDIN_FILENO  0
/**
 * @brief scanf Implementation function try not to fill the buffer.Other wise system will go unstable.
 *          Reference :  https://shawnhymel.com/1873/how-to-use-printf-on-stm32/
 *          TODO: check for FreeRTOS implementation also and put timeout also in the function
 * @param fd
 * @param ptr
 * @param len
 * @return
 */
int _read(int fd, char* ptr, int len) {
  HAL_StatusTypeDef hstatus;

  if (fd == STDIN_FILENO) {
    hstatus = HAL_UART_Receive(&huart2, (uint8_t *) ptr, 1, HAL_MAX_DELAY);
    if (hstatus == HAL_OK)
      return 1;
    else
      return EIO;
  }
  errno = EBADF;
  return -1;
}

/**
 * @brief Reference : https://github.com/GaloisInc/minlibc
 * @copyright (C) 2014, Galois, Inc.
 * This software is distributed under a standard, three-clause BSD license.
 * Please see the file LICENSE, distributed with this software, for specific
 * terms and conditions.
 */

double atof(const char *s)
{
/*   This function stolen from either Rolf Neugebauer or Andrew Tolmach Probably Rolf.*/
  double a = 0.0;
  int e = 0;
  int c;
  while ((c = *s++) != '\0' && isdigit(c)) {
    a = a*10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  if (c == 'e' || c == 'E') {
    int sign = 1;
    int i = 0;
    c = *s++;
    if (c == '+')
      c = *s++;
    else if (c == '-') {
      c = *s++;
      sign = -1;
    }
    while (isdigit(c)) {
      i = i*10 + (c - '0');
      c = *s++;
    }
    e += i*sign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}


/* Create a bunch of objects as demonstration. */
int8_t sUtilsPrint_preallocated(cJSON *root){
    /* declarations */
    char *out = NULL;
    char *buf = NULL;
    char *buf_fail = NULL;
    size_t len = 0;
    size_t len_fail = 0;

    /* formatted print */
    out = cJSON_Print(root);

    /* create buffer to succeed */
    /* the extra 5 bytes are because of inaccuracies when reserving memory */
    len = strlen(out) + 5;
    buf = (char*) malloc(len);
    if (buf == NULL){
        printf("Failed to allocate memory.\n");
        return (1);
    }

    /* create buffer to fail */
    len_fail = strlen(out);
    buf_fail = (char*) malloc(len_fail);
    if (buf_fail == NULL){
        printf("Failed to allocate memory.\n");
        return (1);
    }

    /* Print to buffer */
    if (!cJSON_PrintPreallocated(root, buf, (int) len, 1)){
        printf("cJSON_PrintPreallocated failed!\n");
        if (strcmp(out, buf) != 0){
            printf("cJSON_PrintPreallocated not the same as cJSON_Print!\n");
            printf("cJSON_Print result:\n%s\n", out);
            printf("cJSON_PrintPreallocated result:\n%s\n", buf);
        }
        free(out);
        free(buf_fail);
        free(buf);
        return -1;
    }

    /* success */
    printf("%s\n#\n", buf);   // "#" can be added for end of the string

    /* force it to fail */
    if (cJSON_PrintPreallocated(root, buf_fail, (int) len_fail, 1)){
        printf("cJSON_PrintPreallocated failed to show error with insufficient memory!\n");
        printf("cJSON_Print result:\n%s\n", out);
        printf("cJSON_PrintPreallocated result:\n%s\n", buf_fail);
        free(out);
        free(buf_fail);
        free(buf);
        return -1;
    }

    free(out);
    free(buf_fail);
    free(buf);
    return 0;
}
