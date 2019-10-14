/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _EASY_STREAM_CLIENT_API_H
#define _EASY_STREAM_CLIENT_API_H

#include "EasyTypes.h"

/* �����¼����Ͷ��� */
typedef enum __EASY_STREAM_CLIENT_STATE_T
{
	EASY_STREAM_CLIENT_STATE_CONNECTING = 1,		 /* ������ */
	EASY_STREAM_CLIENT_STATE_CONNECTED,              /* ���ӳɹ� */
	EASY_STREAM_CLIENT_STATE_CONNECT_FAILED,         /* ����ʧ�� */
	EASY_STREAM_CLIENT_STATE_CONNECT_ABORT,          /* �����ж� */
	EASY_STREAM_CLIENT_STATE_PUSHING,                /* ������ */
	EASY_STREAM_CLIENT_STATE_DISCONNECTED,           /* �Ͽ����� */
	EASY_STREAM_CLIENT_STATE_EXIT,					 /* �˳����� */
	EASY_STREAM_CLIENT_STATE_ERROR
} EASY_STREAM_CLIENT_STATE_T;

/*
_channelPtr:	ͨ����Ӧ����,��ʱ����
_frameType:		EASY_SDK_VIDEO_FRAME_FLAG/EASY_SDK_AUDIO_FRAME_FLAG/EASY_SDK_EVENT_FRAME_FLAG/...
_pBuf:			�ص������ݲ��֣������÷���Demo
_frameInfo:		֡�ṹ����
*/
typedef int (Easy_APICALL *EasyStreamClientCallBack)(void *_channelPtr, int _frameType, void *pBuf, EASY_FRAME_INFO* _frameInfo);
typedef int (Easy_APICALL *EasyDownloadCallBack)(void *userptr, const char* path);

#ifdef __cplusplus
extern "C" 
{
#endif
#ifdef ANDROID
	Easy_API Easy_I32 Easy_APICALL EasyStreamClient_Activate(char *license, char* userPtr);
#else
	Easy_API Easy_I32 Easy_APICALL EasyStreamClient_Activate(char *license);
#endif

	/* ����EasyStreamClient���  ����0��ʾ�ɹ������ط�0��ʾʧ�� ;  loglevel : 0 - quiet  1 - debug*/
	Easy_API int Easy_APICALL EasyStreamClient_Init(Easy_Handle *handle, int loglevel);

	/* �ͷ�EasyStreamClient ����ΪEasyStreamClient��� */
	Easy_API int Easy_APICALL EasyStreamClient_Deinit(Easy_Handle handle);

	/* �������ݻص� */
	Easy_API int Easy_APICALL EasyStreamClient_SetCallback(Easy_Handle handle, EasyStreamClientCallBack callback);

	/* �������� */
	Easy_API int Easy_APICALL EasyStreamClient_OpenStream(Easy_Handle handle, char *url, EASY_RTP_CONNECT_TYPE connType, void *userPtr, int reconn, int timeout, int useExtraData);

	/* ��ȡ��������context */
	Easy_API int Easy_APICALL EasyStreamClient_GetStreamContext(Easy_Handle handle, void** avFormatContext, void** avCodecContext);

	/* ��ȡ���� */
	Easy_API int Easy_APICALL EasyStreamClient_GetSnap(Easy_Handle handle);

	/* ������Ƶ�Ƿ����� */
	Easy_API int Easy_APICALL EasyStreamClient_SetAudioEnable(Easy_Handle handle, int enable);

	/* ��ȡ��Ƶ�Ƿ����� */
	Easy_API int Easy_APICALL EasyStreamClient_GetAudioEnable(Easy_Handle handle);

	/*¼������*/
	Easy_API int Easy_APICALL EasyStreamClient_SetDownloadCallback(EasyDownloadCallBack callback);
	Easy_API int Easy_APICALL EasyStreamClient_DownloadOneRecord(const char* rootPath, const char* streamName, const char* startTime, void* userPtr);
	Easy_API int Easy_APICALL EasyStreamClient_DownloadPeriod(const char* rootPath, const char* streamName, const char* startTime, const char* endTime, void* userPtr);
#ifdef __cplusplus
};
#endif

#endif