
#ifndef __EasyIPCamera_H__
#define __EasyIPCamera_H__

#include "EasyTypes.h"

#define RTSP_SERVER_NAME	"EasyIPCamera v1.3.16.1206"


typedef enum _AUTHENTICATION_TYPE_ENUM
{
	AUTHENTICATION_TYPE_BASIC		=	0x00,
	AUTHENTICATION_TYPE_DIGEST,
}AUTHENTICATION_TYPE_ENUM;

typedef struct __LIVE_CHANNEL_INFO_T
{
	int		id;
	char	name[64];
}LIVE_CHANNEL_INFO_T;

typedef struct __EASY_AV_Frame
{
    Easy_U32    u32AVFrameFlag;		/* ֡��־  ��Ƶ or ��Ƶ */
    Easy_U32    u32AVFrameLen;		/* ֡�ĳ��� */
    Easy_U32    u32VFrameType;		/* ��Ƶ�����ͣ�I֡��P֡ */
    Easy_U8     *pBuffer;			/* ���� */
	Easy_U32	u32TimestampSec;	/* ʱ���(��)*/
	Easy_U32	u32TimestampUsec;	/* ʱ���(΢��) */
}EASY_AV_Frame;


typedef enum __EASY_IPCAMERA_STATE_T
{
	EASY_IPCAMERA_STATE_ERROR						=		-1,		//�ڲ�����
    EASY_IPCAMERA_STATE_REQUEST_MEDIA_INFO			=		1,		//������,����media info
	EASY_IPCAMERA_STATE_REQUEST_PLAY_STREAM,						//��ʼ������
	EASY_IPCAMERA_STATE_REQUEST_STOP_STREAM,						//ֹͣ��
	EASY_IPCAMERA_STATE_PLAY_CONTROL,
}EASY_IPCAMERA_STATE_T;

/* �ص��������� userptr��ʾ�û��Զ������� */
typedef Easy_I32 (*EasyIPCamera_Callback)(Easy_I32 channelId, EASY_IPCAMERA_STATE_T channelState, EASY_MEDIA_INFO_T *mediaInfo, EASY_PLAY_CONTROL_INFO_T *playCtrlInfo, void *userPtr);

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef ANDROID
	Easy_API int Easy_APICALL EasyIPCamera_Activate(char *license, char* userPtr);
#else
	Easy_API int Easy_APICALL EasyIPCamera_Activate(char *license);
#endif
	/* ���� Rtsp Server */
	/*���ü����˿�, �ص��������Զ������� */
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_Startup(Easy_U16 listenport, AUTHENTICATION_TYPE_ENUM authType, 
															char *realm, Easy_U8 *username, Easy_U8 *password, EasyIPCamera_Callback callback, void *userptr, 
															LIVE_CHANNEL_INFO_T *channelInfo, Easy_U32 channelNum);
	
	/* ��ֹ Rtsp Server */
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_Shutdown();

	//����û�  ��    �����û����޸��û�����
	//�����ӵ��û���������,��Ϊ����, ���Ѵ���,��Ϊ�޸�����
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_AddUser(const Easy_U8 *username, const Easy_U8 *password);
	//ɾ���û�
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_DelUser(const Easy_U8 *username);

	/* frame:  ���巢�͵�֡���� */
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_PushFrame(Easy_I32 channelId, EASY_AV_Frame* frame );

	//�ֱ��ʱ仯 ֻҪ��Ƶ����Ƶ�����仯ʱ, ���� EasyIPCamera_ResetChannel
	Easy_API Easy_I32 Easy_APICALL EasyIPCamera_ResetChannel(Easy_I32 channelId);
#ifdef __cplusplus
}
#endif


/*
����:
1. ���� EasyIPCamera_Startup ���ü����˿ڡ��ص��������Զ�������ָ��
2. �����󣬳���������״̬
	2.1		���յ��ͻ�������, �ص� ״̬:EASY_IPCAMERA_STATE_REQUEST_MEDIA_INFO          �ϲ�����������mediainfo�󣬷���0, ��EasyIpCamera��Ӧ�ͻ���ok
	2.2		EasyIPCamera�ص�״̬ EASY_IPCAMERA_STATE_REQUEST_PLAY_STREAM , ���ʾrtsp�������, ��ʼ������, �ϲ�������EasyIpCamera_PushFrame ����֡����
	2.3		EasyIPCamera�ص�״̬ EASY_IPCAMERA_STATE_REQUEST_STOP_STREAM , ���ʾ�ͻ����ѷ���teaardown, Ҫ��ֹͣ����֡����
3.	���� EasyIpCamera_Shutdown(), �ر�EasyIPCamera���ͷ������Դ

*/


#endif
