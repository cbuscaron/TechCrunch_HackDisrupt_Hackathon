#define JNI_TAG "MF_JNI"

#include <jni.h>
#include <stddef.h>
#include <stdlib.h>
#include "makerfair-jni.h"

extern "C"
{
    #include "accel_iface.h"
    #include "sensor_iface.h"
}

enum {
    COLOR_POS = 0,
    LIGHT_POS = 1,
    JOYSTICK_POS = 2,
    GESTURE_POS = 3
};

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_newServiceJNI(JNIEnv * env, jobject obj)
{
    int result = 0;

    int colorPresent = init_rgb();
    LOGD(JNI_TAG, "color present %d", colorPresent);
    result += (1 & colorPresent) << COLOR_POS;

    int lightPresent = init_light();
    LOGD(JNI_TAG, "light present %d", lightPresent);
    result += (1 & lightPresent) << LIGHT_POS;

   /* int joystickPresent = init_adxl345();
    LOGD(JNI_TAG, "joystick present %d", joystickPresent);
    result += (1 & joystickPresent)<< JOYSTICK_POS;*/

    int gesturePresent = init_gesture();
    LOGD(JNI_TAG, "gesture present %d", gesturePresent);
    result += (1 & gesturePresent) << GESTURE_POS;

	return result;
}

JNIEXPORT jboolean JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_initSensorJNI(JNIEnv * env, jobject obj, jint sensorType) {
    int isPresent = 0;
    switch(sensorType) {
        case COLOR_POS:
           isPresent = init_rgb();
           LOGD(JNI_TAG, "color present %d", isPresent);
           break;

        case LIGHT_POS:
           isPresent = init_light();
           LOGD(JNI_TAG, "light present %d", isPresent);
           break;

        case JOYSTICK_POS:
           //isPresent = init_rgb();
           LOGD(JNI_TAG, "joystick present %d", isPresent);
           break;

        case GESTURE_POS:
           isPresent = init_gesture();
           LOGD(JNI_TAG, "gesture present %d", isPresent);
           break;
    }

    return (isPresent == 0) ? false : true;
}

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readRGBJNI(JNIEnv * env,
      jobject obj)
{

    int r, g, b;
    int error = read_rgb(&r, &g, &b);
    return (error == 0) ? ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff) : -1;
}

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readJoystickJNI(JNIEnv * env,
      jobject obj)
{
    int x, y, z;
    //read_adxl345(&x, &y, &z);
    //LOGD(JNI_TAG, "ACCL %d %d %d", x, y, z);
    return rand() % 4;
}

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readGestureJNI(JNIEnv * env,
      jobject obj)
{
    int gesture = read_gesture();
    return gesture;
}

JNIEXPORT jlong JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readLightJNI(JNIEnv * env,
      jobject obj)
{
    long lux = read_lux();
  //  LOGD(JNI_TAG, "read light is %d ", lux );
    return lux;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGD(JNI_TAG, "JNI_OnLoad." );
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
    	LOGE(JNI_TAG, "Error getting JNIEnv." );
        return -1;
    }


	return JNI_VERSION_1_6;
}






