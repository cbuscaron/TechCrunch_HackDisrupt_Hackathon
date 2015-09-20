#include <stdint.h>
#include <linux/types.h>
#include <sys/ioctl.h>
#include <stddef.h>


#ifndef MF_SENSOR_IFACE_H
#define MF_SENSOR_IFACE_H


#ifdef __cplusplus
    extern "C" {
#endif
    int init_gesture();
    int read_gesture();

    int init_rgb();
    int read_rgb(int *r, int *g, int *b);

    int init_light();
    long read_lux();

#ifdef __cplusplus
    }
#endif


#endif