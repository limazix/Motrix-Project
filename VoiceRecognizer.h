#ifndef VOICERECOGNIZER_H
#define	VOICERECOGNIZER_H

#include "default.h"
#include <pocketsphinx/pocketsphinx.h>

class VoiceRecognizer {
public:
    VoiceRecognizer();
    virtual ~VoiceRecognizer();
    int run();

private:
    //variables
    int sampleRate;
    int milliseconds;

    //methodes
    int recognitionLoop();
    bool done();

};

#endif	/* VOICERECOGNIZER_H */

