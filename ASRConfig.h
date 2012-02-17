/* 
 * File:   ASRConfig.h
 * Author: bruno
 *
 * Created on 13 de Fevereiro de 2012, 15:41
 */

#ifndef ASRCONFIG_H
#define	ASRCONFIG_H

class ASRConfig {
public:
    ASRConfig();
    ASRConfig(const ASRConfig& orig);
    virtual ~ASRConfig();

    std::string getHmm_path() const;
    void setHmm_path(std::string hmm_path);
    std::string getLm_dic_path() const;
    void setLm_dic_path(std::string lm_dic_path);
    std::string getLm_dmp_path() const;
    void setLm_dmp_path(std::string lm_dmp_path);

private:
    std::string hmm_path;
    std::string lm_dmp_path;
    std::string lm_dic_path;

};

#endif	/* ASRCONFIG_H */

