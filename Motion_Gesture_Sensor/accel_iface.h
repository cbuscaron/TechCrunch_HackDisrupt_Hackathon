#include <stdint.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <stddef.h>


#ifndef MF_ACCEL_IFACE_H
#define MF_ACCEL_IFACE_H


#ifdef __cplusplus
    extern "C" {
#endif
    int init_adxl345();
#ifdef __cplusplus
    }
#endif


#ifdef __cplusplus
    extern "C" {
#endif
    int read_adxl345(int *x, int *y, int *z);
#ifdef __cplusplus
    }
#endif

#endif
