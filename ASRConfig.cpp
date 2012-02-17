/* 
 * File:   ASRConfig.cpp
 * Author: bruno
 * 
 * Created on 13 de Fevereiro de 2012, 15:41
 */

#include "ASRConfig.h"

ASRConfig::ASRConfig() {
}

ASRConfig::ASRConfig(const ASRConfig& orig) {
}

ASRConfig::~ASRConfig() {
}


ASRConfig::getHmm_path() const {
    return hmm_path;
}

ASRConfig::setHmm_path(std::string hmm_path) {
    this->hmm_path = hmm_path;
}

ASRConfig::getLm_dic_path() const {
    return lm_dic_path;
}

ASRConfig::setLm_dic_path(std::string lm_dic_path) {
    this->lm_dic_path = lm_dic_path;
}

ASRConfig::getLm_dmp_path() const {
    return lm_dmp_path;
}

ASRConfig::setLm_dmp_path(std::string lm_dmp_path) {
    this->lm_dmp_path = lm_dmp_path;
}