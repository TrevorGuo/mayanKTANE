#include "vault.h"

Vault::Vault() {
    m_potentiometerValue = 0;
    m_region = 0;
    initializeCombo();
}

void initializeCombo(){
    //set values of combination

    //set values of ordered combination to -1
}

void Vault::runVault() {
    //read potentiometer
    m_potentiometerValue = ADCALPHAFILTER*analogRead(POTPIN) + (1-ADCALPHAFILTER)*m_potentiometerValue;

    //determine what region potentiometer is in
    float adcToRegionConverter = NUM_NUMERALS/ADC_RESOLUTION;
    int newRegion = adcToRegionConverter*m_potentiometerValue;
    
    //if new Region start buzz and record value if it is new
    if (newRegion != m_region) {
        m_region = newRegion;
        
        //start buzz if in correct area
        bool startBuzz = false;
        for (int i = 0; i < CODE_LENGTH; i++) {
            if (m_region == m_regions[i]) startBuzz == true;

            //if the combo hasn't been found yet record it in order and break out of the loop
            if (-1 == m_ordered_regions[i]){
                m_ordered_regions[i] = m_region;
                break;
            } 
        }
        if (startBuzz) StartBuzz();
        else StopBuzz();

        //remember when symbol changed
        clockStart = millis();
    } 

    //check if all values found and clock is active
    else if (m_ordered_regions[CODE_LENGTH] > 0){
        if (!clockActive) {
            clockActive = true;
            calcFinalRegion();
        }
        if (millis()-clockStart > WAIT_TIME_SEC*1000){
            if(m_region == m_final_region) comboSuccess();
            else comboFail();
        }
    }
}

void Vault::StartBuzz(){

}

void Vault::StopBuzz(){

}

void Vault::comboSuccess(){

}

void Vault::comboFail(){
    
}

void Vault::calcFinalRegion(){
    
    int n[3] = {
        regionToNumeralMap[m_ordered_regions[0]],
        regionToNumeralMap[m_ordered_regions[1]],
        regionToNumeralMap[m_ordered_regions[2]],
        };
    
    //If the first numeral was greater than 5 travel to the 8th numeral
    if(n[0]>5) m_final_region = 7;
    //If the sum of all numerals is 20 travel to the 6th numeral
    else if(n[0]+n[1]+n[2] == 20) m_final_region = 5;
    //If the 3rd numeral is less than the first travel to the 2nd numeral
    else if(n[2]<n[0]) m_final_region = 1;
    //If the 2nd numeral is greater than both the first and third travel to the 7th numeral
    else if(n[1]>n[0] && n[1]>n[2]) m_final_region = 6;
    //Otherwise travel to the 1st numeral
    else m_final_region = 0;
}