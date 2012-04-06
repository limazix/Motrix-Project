/* 
 * File:   MediaPlayer.cpp
 * Author: bruno
 * 
 * Created on 17 de Fevereiro de 2012, 13:22
 */
#include <portaudio.h>

#include "MediaPlayer.h"

MediaPlayer::MediaPlayer() {

    int i;
    int totalFrames;
    int numBytes;

    this->err = paNoError;

    printf("patest_record.c\n");
    fflush(stdout);

    this->data.maxFrameIndex = totalFrames = NUM_SECONDS * SAMPLE_RATE; /* Record for a few seconds. */
    this->data.frameIndex = 0;
    this->numSamples = totalFrames * NUM_CHANNELS;
    numBytes = this->numSamples * sizeof (SAMPLE);
    this->data.recordedSamples = (SAMPLE *) malloc(numBytes); /* From now on, recordedSamples is initialised. */
    if (this->data.recordedSamples == NULL) {
        printf("Could not allocate record array.\n");
        done();
    }
    for (i = 0; i < this->numSamples; i++) this->data.recordedSamples[i] = 0;

    this->err = Pa_Initialize();
    if (this->err != paNoError) done();

    this->inputParameters.device = Pa_GetDefaultInputDevice(); /* default input device */
    if (this->inputParameters.device == paNoDevice) {
        fprintf(stderr, "Error: No default input device.\n");
        done();
    }
    this->inputParameters.channelCount = 2; /* stereo input */
    this->inputParameters.sampleFormat = PA_SAMPLE_TYPE;
    this->inputParameters.suggestedLatency = Pa_GetDeviceInfo(this->inputParameters.device)->defaultLowInputLatency;
    this->inputParameters.hostApiSpecificStreamInfo = NULL;
}

MediaPlayer::MediaPlayer(const MediaPlayer& orig) {
}

MediaPlayer::~MediaPlayer() {
}

/* Record some audio. -------------------------------------------- */
PaStream* MediaPlayer::record() {
    PaStream* stream;
    SAMPLE max, val;
    double average;
    int i;

    this->err = Pa_OpenStream(
            &stream,
            &this->inputParameters,
            NULL, /* &outputParameters, */
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff, /* we won't output out of range samples so don't bother clipping them */
            recordCallback,
            &this->data);
    if (this->err != paNoError) done();

    this->err = Pa_StartStream(stream);
    if (this->err != paNoError) done();
    printf("\n=== Now recording!! Please speak into the microphone. ===\n");
    fflush(stdout);

    while ((this->err = Pa_IsStreamActive(stream)) == 1) {
        Pa_Sleep(1000);
        printf("index = %d\n", this->data.frameIndex);
        fflush(stdout);
    }
    if (this->err < 0) done();

    this->err = Pa_CloseStream(stream);
    if (this->err != paNoError) done();

    /* Measure maximum peak amplitude. */
    max = 0;
    average = 0.0;
    for (i = 0; i < this->numSamples; i++) {
        val = this->data.recordedSamples[i];
        if (val < 0) val = -val; /* ABS */
        if (val > max) {
            max = val;
        }
        average += val;
    }

    average = average / (double) this->numSamples;

    printf("sample max amplitude = "PRINTF_S_FORMAT"\n", max);
    printf("sample average = %lf\n", average);

    return stream;
}

void MediaPlayer::playStream(PaStream* stream) {
    /* Playback recorded this->data.  -------------------------------------------- */
    PaStreamParameters outputParameters;
    this->data.frameIndex = 0;

    outputParameters.device = Pa_GetDefaultOutputDevice(); /* default output device */
    if (outputParameters.device == paNoDevice) {
        fprintf(stderr, "Error: No default output device.\n");
        done();
    }
    outputParameters.channelCount = 2; /* stereo output */
    outputParameters.sampleFormat = PA_SAMPLE_TYPE;
    outputParameters.suggestedLatency = Pa_GetDeviceInfo(outputParameters.device)->defaultLowOutputLatency;
    outputParameters.hostApiSpecificStreamInfo = NULL;

    printf("\n=== Now playing back. ===\n");
    fflush(stdout);
    this->err = Pa_OpenStream(
            &stream,
            NULL, /* no input */
            &outputParameters,
            SAMPLE_RATE,
            FRAMES_PER_BUFFER,
            paClipOff, /* we won't output out of range samples so don't bother clipping them */
            playCallback,
            &this->data);
    if (this->err != paNoError) done();

    if (stream) {
        this->err = Pa_StartStream(stream);
        if (this->err != paNoError) done();

        printf("Waiting for playback to finish.\n");
        fflush(stdout);

        while ((this->err = Pa_IsStreamActive(stream)) == 1) Pa_Sleep(100);
        if (this->err < 0) done();

        this->err = Pa_CloseStream(stream);
        if (this->err != paNoError) done();

        printf("Done.\n");
        fflush(stdout);
    }
}

PaError MediaPlayer::done() {
    Pa_Terminate();
    if (this->data.recordedSamples) /* Sure it is NULL or valid. */
        free(this->data.recordedSamples);
    if (this->err != paNoError) {
        fprintf(stderr, "An this->error occured while using the portaudio stream\n");
        fprintf(stderr, "Error number: %d\n", this->err);
        fprintf(stderr, "Error message: %s\n", Pa_GetErrorText(this->err));
        this->err = 1; /* Always return 0 or 1, but no other return codes. */
    }
    return this->err;
}