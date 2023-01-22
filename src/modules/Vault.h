#ifndef VAULT_H
#define VAULT_H

#include <stdlib.h>
#include <Arduino.h>

#define POTPIN 4
#define VAULT_CODE_LENGTH 3
#define ADCALPHAFILTER 0.3
#define ADC_RESOLUTION 4032
#define NUM_NUMERALS 8
#define WAIT_TIME_SEC 10
#define VIBS_PIN 18

const int regionToNumeralMap[NUM_NUMERALS] = {1, 2, 3, 4, 5, 6, 7, 8};

class Bomb;

class Vault
{
public:
    Vault();
    void runVault();
    void initializeCombo();
    int m_success = -1;

private:
    void comboSuccess();
    void comboFail();
    void calcFinalRegion();
    // void StartBuzz();
    // void StopBuzz();

    int m_regions[VAULT_CODE_LENGTH];
    int m_ordered_regions[VAULT_CODE_LENGTH];
    int m_final_region;
    int m_potentiometerValue;
    int m_next = 0;
    int m_region;
    bool clockActive;
    long clockStart;
};

#endif