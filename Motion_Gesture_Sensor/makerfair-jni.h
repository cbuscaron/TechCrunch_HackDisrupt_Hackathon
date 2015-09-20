

#include <jni.h>
#include "common/header.h"


#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------
//  JNI Interface
//------------------------------------------------------------------------------

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_newServiceJNI(JNIEnv * env, jobject obj);

JNIEXPORT jboolean JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_initSensorJNI(JNIEnv * env, jobject obj, jint sensorType);

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readRGBJNI(JNIEnv * env,
      jobject obj);

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readJoystickJNI(JNIEnv * env,
      jobject obj);

JNIEXPORT jint JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readGestureJNI(JNIEnv * env,
      jobject obj);

JNIEXPORT jlong JNICALL
Java_com_qualcomm_esg_makerfairdemo_service_SensorManager_readLightJNI(JNIEnv * env,
      jobject obj);

#ifdef __cplusplus
}
#endif


