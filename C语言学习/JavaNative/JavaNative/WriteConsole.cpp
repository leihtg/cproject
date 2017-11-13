#include "cn_com_webutil_WriteConsole.h"

jstring JNICALL Java_cn_com_webutil_WriteConsole_getDate
(JNIEnv *env, jobject obj){
	jclass clazz = env->FindClass("java/lang/String");
	jmethodID init_id = env->GetMethodID(clazz, "<init>", "(Ljava/lang/String;)V");
	jstring arg = env->NewStringUTF("hello cjp");
	jobject str = env->NewObject(clazz, init_id, arg);

	return env->NewStringUTF("hello cjp");
}

JNIEXPORT void JNICALL Java_cn_com_webutil_WriteConsole_sayHello
(JNIEnv *env, jobject obj, jstring name){
	jclass clazz = env->GetObjectClass(obj);
	jfieldID fId = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
	env->SetObjectField(obj, fId, name);
	printf("set name done");
}


JNIEXPORT jstring JNICALL Java_cn_com_webutil_WriteConsole_sayGoodye
(JNIEnv *env, jobject _this, jobject obj){
	jclass clazz = env->GetObjectClass(_this);
	jfieldID fId = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
	jstring jstr = (jstring)env->GetObjectField(_this, fId);
	return jstr;
}