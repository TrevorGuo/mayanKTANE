#include "Vault.h"
#include <stdlib.h>

Vault::Vault()
{
    m_potentiometerValue = 0;
    m_region = 0;
    initializeCombo();
}

void Vault::initializeCombo()
{
    // set values of combination
    int i1 = rand() % 8;
    int i2 = rand() % 7;
    if (i2 >= i1)
        i2++;
    int i3 = rand() % 6;
    if (i3 >= i1)
        i3++;
    if (i3 >= i2)
        i3++;
    m_regions[0] = regionToNumeralMap[i1];
    m_regions[1] = regionToNumeralMap[i2];
    m_regions[2] = regionToNumeralMap[i3];
    // Serial.print(m_regions[0]);
    // Serial.print(" , ");
    // Serial.print(m_regions[1]);
    // Serial.print(" , ");
    // Serial.println(m_regions[2]);

    // set values of ordered combination to -1
    for (int i = 0; i < VAULT_CODE_LENGTH; i++)
    {
        m_ordered_regions[i] = -1;
    }
}

void Vault::runVault()
{
    // read potentiometer
    m_potentiometerValue = ADCALPHAFILTER * analogRead(POTPIN) + (1 - ADCALPHAFILTER) * m_potentiometerValue;

    int newRegion = m_potentiometerValue * NUM_NUMERALS / ADC_RESOLUTION;

    // if new Region start buzz and record value if it is new
    if (newRegion != m_region)
    {
        m_region = newRegion;
        // Serial.print("Pos: ");
        // Serial.println(newRegion);
        // Serial.print(m_regions[0]);
        // Serial.print(" , ");
        // Serial.print(m_regions[1]);
        // Serial.print(" , ");
        // Serial.println(m_regions[2]);
        // Serial.print("order: ");
        // Serial.print(m_ordered_regions[0]);
        // Serial.print(" , ");
        // Serial.print(m_ordered_regions[1]);
        // Serial.print(" , ");
        // Serial.println(m_ordered_regions[2]);
        // Serial.print("order: ");
        // Serial.print(m_ordered_regions[0]);
        // Serial.print(" , ");
        // Serial.print(m_ordered_regions[1]);
        // Serial.print(" , ");
        // Serial.println(m_ordered_regions[2]);
        // start buzz if in correct area
        bool startBuzz = false;
        for (int i = 0; i < VAULT_CODE_LENGTH; i++)
        {

            if (m_region == m_regions[i])
            {
                startBuzz = true;
                // Serial.print("Buzz set to true: ");
                // Serial.println(startBuzz);
                bool found = false;
                for (int j = 0; j < VAULT_CODE_LENGTH; j++)
                {
                    if (m_ordered_regions[j] == m_region)
                        break;
                    else if (m_ordered_regions[j] == -1)
                    {
                        m_ordered_regions[j] = m_region;
                        break;
                    }
                }
            }

            // if the combo hasn't been found yet record it in order and break out of the loop
        }
        // Serial.println(startBuzz);

        if (startBuzz)
        {
            digitalWrite(VIBS_PIN, HIGH);
            // Serial.println("set High");
        }
        else
            digitalWrite(VIBS_PIN, LOW);

        // remember when symbol changed
        clockStart = millis();
    }

    // check if all values found and clock is active
    if (m_ordered_regions[VAULT_CODE_LENGTH - 1] >= 0)
    {
        if (!clockActive)
        {
            clockActive = true;
            calcFinalRegion();
        }
        if (millis() - clockStart > WAIT_TIME_SEC * 1000)
        {
            if (m_region == m_final_region)
                comboSuccess();
            else
                comboFail();
        }
    }
}

void Vault::comboSuccess()
{
    Serial.println("Suc");
    m_success = 1;
}

void Vault::comboFail()
{
    Serial.println("F");
    m_success = 0;
}

void Vault::calcFinalRegion()
{

    int n[3] = {
        regionToNumeralMap[m_ordered_regions[0]],
        regionToNumeralMap[m_ordered_regions[1]],
        regionToNumeralMap[m_ordered_regions[2]],
    };

    // If the first numeral was greater than 5 travel to the 8th numeral
    if (n[0] > 5)
        m_final_region = 7;
    // If the sum of all numerals is 20 travel to the 6th numeral
    else if (n[0] + n[1] + n[2] == 20)
        m_final_region = 5;
    // If the 3rd numeral is less than the first travel to the 2nd numeral
    else if (n[2] < n[0])
        m_final_region = 1;
    // If the 2nd numeral is greater than both the first and third travel to the 7th numeral
    else if (n[1] > n[0] && n[1] > n[2])
        m_final_region = 6;
    // Otherwise travel to the 1st numeral
    else
        m_final_region = 0;
    Serial.print("m_final_region: ");
    Serial.println(m_final_region);
}