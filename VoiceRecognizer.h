#ifndef VOICERECOGNIZER_H
#define	VOICERECOGNIZER_H

#include "../local/include/pocketsphinx/pocketsphinx.h"
#include "ASRConfig.h"
#include <iostream>

class VoiceRecognizer {
public:
    VoiceRecognizer();
    virtual ~VoiceRecognizer();
    int run();

private:
    //variables
    int sampleRate = 16000;
    int milliseconds = 500;
    ASRConfig config;

    //methodes
    int recognitionLoop();

};

#endif	/* VOICERECOGNIZER_H */

