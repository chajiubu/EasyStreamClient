
����̨Ӧ�ó���EasyStreamClient ��Ŀ���� 

EasyStreamClient��һ�׷ǳ��ȶ������á�֧��������StreamClient���ߣ���SDK��ʽ�ṩ�� �ӿڵ��÷ǳ��򵥣���������ʵս���������д��죬֧��RTMP���Ͷ������������λ��塢���ܶ�֡�� �����¼��ص�����Ҳ���������live555������������RTSP�ĸ������̣������ڴ��ͷŵ������ˡ� ȫƽ̨֧�֣�����Windows/Linux 32&64��ARM��ƽ̨��Android��iOS�����ӿڼ��ҳ����ȶ�

#����˵��

##Win
����EasyStreamClient.exe
64λ���̳���


	printf("EasyStreamClient.exe -m udp -d rtsp://srcAddr -s file/rtmp/mp4 -f rtmp://dstAddr\n");
	printf("-m: tcp or udp\n");
	printf("-d: rtsp��ַ��m3u8¼��Դ��ַ\n");
	//printf("-s: �����ʽ��fileΪH.264(H.265)��rtmpΪRTMP������mp4Ϊ¼��ϳ�\n");
	//printf("-f: �����ַ��h.264(H.265)��      rtmp��ַ��      mp4·��\n");

	printf("-s: �����ʽ��fileΪH.264(H.265)��rtmpΪRTMP����\n");
	printf("-f: �����ַ��h.264(H.265)��      rtmp��ַ\n");
	printf("-t: ��ʱʱ��(��)\n");

	printf("EasyStreamClient.exe -m tcp -d rtsp://192.168.1.100/ch1 -s file -f 1.h264");



	��������ʾ��: -m tcp -d rtsp://admin:12345@112.28.34.31:554/Streaming/Channels/102 -s rtmp -f rtmp://192.168.99.106:10085/hls/test?sign=zlaJjyhZg