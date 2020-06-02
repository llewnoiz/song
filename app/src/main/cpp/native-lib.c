#include <jni.h>
#include <pthread.h>

#include "usp_cli.h"
//#include "usp_log.h"


JNIEXPORT void JNICALL
Java_com_kaon_song_UspService_UspAgentStart(JNIEnv *env, jobject thiz) {
    pthread_t usp_pid;
    //USP_LOG_Debug("%s %d\n",__func__,__LINE__);
    pthread_create( &usp_pid, NULL, uspClient, 0 );

    pthread_exit(usp_pid);
}

JNIEXPORT void JNICALL
Java_com_kaon_song_UspService_UspAgentStop(JNIEnv *env, jobject thiz) {
    //USP_LOG_Debug("%s %d\n",__func__,__LINE__);
}