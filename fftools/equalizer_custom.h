#ifndef equalizer_h
#define equalizer_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <math.h>
#include "FilterTypes.h"

typedef struct
{
    MUInt16 type;
    MFloat fl;
}FILTERTYPE;  // �˲�������

typedef struct
{
    FILTERTYPE type;
    MUInt8 sampleSize;
    MUInt8 channels;
    MUInt16 enabled_channel_bit;
    MUInt32 freq; // ������
    MFloat dbgain; // ����
    MFloat q;  // Ʒ������
    MFloat amp; // ��ֵ
    MFloat a[3]; // a0,a1,a2
    MFloat b[3]; // b0,b1,b2
    MFloat x[3]; // x(n),x(n-1),x(n-2)
    MFloat y[2]; // y(n-1),y(n-2)
}FILTERINFO, *LPFILTERINFO;

MVoid Init_Filter(LPFILTERINFO pFilter);
MUInt32 FilterAudioData(LPFILTERINFO pFilter, MInt8* inData, MUInt32 inLen, MInt8* outData);
MFloat Limiter(LPFILTERINFO pFilter, MFloat inData);

#ifdef __cplusplus
}
#endif

#endif /* equalizer_h */
