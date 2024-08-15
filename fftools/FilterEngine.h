//
//  FilterEngine.h
//  AudioPlayer
//
//  Created by develop on 2024/3/1.
//

#ifndef FilterEngine_h
#define FilterEngine_h


#include "FilterTypes.h"

#define MAX_FILTER_SIZE 128

typedef enum
{
    Filter_Type_BYPASS = 0, // ���˲�
    Filter_Type_Gain,       // ��������
    Filter_Type_1ST_LP,     // 1�׵�ͨ
    Filter_Type_1ST_HP,     // 1�׸�ͨ
    Filter_Type_2ND_LP,     // 2�׵�ͨ
    Filter_Type_2ND_HP,     // 2�׸�ͨ
    Filter_Type_2ND_BP,     // 2�״�ͨ
    Filter_Type_2ND_AP,     // 2��ȫͨ
    Filter_Type_2ND_PEAK,   // 2�׷�ֵ�˲�
    Filter_Type_2ND_NOTCH,  // 2���ݲ��˲�
    Filter_Type_2ND_LS,     // 2�׵���
    Filter_Type_2ND_HS,     // 2�׸���
    Filter_Type_Delay       // ��ʱ�����֧��200ms
}Filter_Type;

typedef struct AudioParam
{
    MInt32  freq;           //  ������
    MUInt16 bitDepth;       //  λ�ֻ֧��16��32��
    MUInt16 samples;        //  һ����Ƶ���ݵĲ�������
    MUInt8  channels;       //  ������
}AudioParam;

typedef struct EqulizerParam
{
    Filter_Type type;                   // �˲�������
    MUInt32     centre_freq;            // �˲�����Ƶ��
    MFloat      dbgain;                 // ����
    MFloat      quality_factor;         // Ʒ������
    MUInt16     enabled_channel_bit;    /*  ��Ҫ�˲�������λ�ã����֧��16������
                                            ����0b1010101011100011��
                                            �ӵ�λ����λ���α�ʾ��1��2��3...16λ�������Ƿ���Ҫ�˲���
                                            ֵΪ1��ʾ��������Ҫ�˲���ֵΪ0��ʾ����������Ҫ�˲���
                                            ������������λ����������������Ϊ6����ֻ�账�����6λ��ֵ */
}EqulizerParam;

__declspec(dllexport)  MVoid CreateFilterEngine(MVoid** pEngine);
__declspec(dllexport)  MVoid DestroyFilterEngine(MVoid* pEngine);
__declspec(dllexport)  MVoid StartFilterEngine(MVoid* pEngine, AudioParam* aParam, MPCChar configFile);
__declspec(dllexport)  MVoid StopFilterEngine(MVoid* pEngine);
__declspec(dllexport)  MVoid AddChannelDelays(MVoid* pEngine, const MFloat* channel_delays_ms);
__declspec(dllexport)  MVoid AddFilter(MVoid* pEngine, EqulizerParam* eqParam);
__declspec(dllexport)  MVoid ResetFilter(MVoid* pEngine);

__declspec(dllexport)  MInt8* FilterAudio(MVoid* pEngine, MInt8* inData, MUInt32 inLen);

__declspec(dllexport)  MVoid StartDebug(MVoid* pEngine);
__declspec(dllexport)  MVoid StopDebug(MVoid* pEngine);


#endif /* FilterEngine_h */
