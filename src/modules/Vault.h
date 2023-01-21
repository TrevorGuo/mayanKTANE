#ifndef VAULT_H
#define VAULT_H

#include <stdlib.h>

#define CODE_LENGTH 4

class Vault {
    public:
        Vault();
    private:
        int values[CODE_LENGTH]; 
};

#endif