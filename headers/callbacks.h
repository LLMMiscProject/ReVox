#ifndef CALLBACKS_H
#define CALLBACKS_H

#endif // CALLBACKS_H

#include <string.h>
#include <iostream>
#include <chrono>
#include <map>
#include "portaudio.h"
#include "sndfile.h"
#include "revmodel.h"
#include "pitchshift.h"
#include "frequency.h"

typedef struct{
    SNDFILE *file;
    SF_INFO info;
    bool pad;
    float timeStamp;
    bool inUse;
} recordData;

typedef struct{
    std::map<SNDFILE*, int> *files;
    std::vector<SNDFILE*> *queue;
    SF_INFO info;
    float maxFileLength;
    float *buf;
} playData;

typedef struct{
    recordData *rData;
    int nChannels;
    revmodel *reverb;
    PitchShift *autotune;
    PitchShift *pitchShift;
    float *buf;
} passthroughData;

typedef struct{
    recordData *rData;
    bool monitorMic;
    float *inputBuffer;
    bool monitorSamples;
    float *playbackBuffer;
    float *streamBuffer;
} monitorData;

int recordCallback(const void* inputBuffer, void* outputBuffer,
                   unsigned long framesPerBuffer,
                   const PaStreamCallbackTimeInfo* timeInfo,
                   PaStreamCallbackFlags statusFlags,
                   void* data);

int playCallback(const void* inputBuffer, void* outputBuffer,
                 unsigned long framesPerBuffer,
                 const PaStreamCallbackTimeInfo* timeInfo,
                 PaStreamCallbackFlags statusFlags,
                 void* data);

int passthroughCallback(const void* inputBuffer, void* outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void* data);

int monitorCallback(const void* inputBuffer, void* outputBuffer,
                        unsigned long framesPerBuffer,
                        const PaStreamCallbackTimeInfo* timeInfo,
                        PaStreamCallbackFlags statusFlags,
                        void* data);

