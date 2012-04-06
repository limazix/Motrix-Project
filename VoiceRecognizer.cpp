#include "VoiceRecognizer.h"

VoiceRecognizer::VoiceRecognizer() {
    this->sampleRate = 16000;
    this->milliseconds = 500;
}

VoiceRecognizer::~VoiceRecognizer() {
}

int VoiceRecognizer::run() {
    try {
        recognitionLoop();
    } catch (const char * s) {
        std::cout << "ERRO" << std::endl;
    }

    std::cout << "Voice Recognizer is finishing!" << std::endl;
    return 0;
}

int VoiceRecognizer::recognitionLoop() {

    size_t nsamp = this->milliseconds * sampleRate / 1000;
    int rv;
    char const * hyp = NULL, *uttid;
    int32 score;
    std::string last_word;

    cmd_ln_t * config;
    config = cmd_ln_init(NULL, ps_args(), TRUE,
            "-hmm", "./models/hmm/en_US/hub4wsj_sc_8k",
            "-lm", "./models/lm/hub4.5000.DMP",
            "-dict", "./models/lm/hub4.5000.dic",
            NULL);
    if (config == NULL) throw "Could not create initializing parameters";

    ps_decoder_t * ps;
    ps = ps_init(config);
    if (ps == NULL) throw "Could not initialize";

    double delayAccum = 0.0;
    int numBufProcessed = 0;

    rv = ps_start_utt(ps, "goforward");
    if (rv < 0) throw "Could not start utterance";

    std::cout << "Recognizer is ready!" << std::endl;

    int counter = 0;

    while(!done()){
        
    }


}

bool VoiceRecognizer::done(){
    return true;
}