#include "vault.h"

Vault::Vault() {
    // Randomize input code at first
    // for (int i = 0; i < CODE_LENGTH - 1; i++) {
    //     int num = rand() % 8 + 1;
    //     while (true) {
    //         for (int i = 0; )
    //     }
    //     values[i] = rand() % 8 + 1;
    // }
    values[0] = 7;
    values[1] = 5;
    values[2] = 3;
    //RULE: 
    //  IF THE SECOND NUMBER IS 5,
    //  THE FINAL NUMBER IS 6
    values[3] = 6;
}