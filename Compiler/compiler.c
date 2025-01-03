#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of KEYWORDS
typedef struct {
    char clave[50];
    char valor[50];
} KEYWORDS;


const char* searchValue(KEYWORDS keys[], int size, const char* key) {
    for(int i = 0; i < size; i++){
        // If the searched key is in KEYWORDS LIST
        if(strcmp(keys[i].clave, key) == 0){
            return keys[i].valor;
        } else {
            return NULL;
        }
    }
}


int main(){
    // Define keywords
    KEYWORDS keys[] = {
        {"imprime", "prinnf"},
        {"input", "scanf"},
        {"espera", "sleep"}
    };

    // Size of KEYWORDS List 
    int size = sizeof(keys) / sizeof(keys[0]);

    const char* searchedKey = "imprime";
    const char* returnedValue = searchValue(keys, size, searchedKey); // Call to the function that returns the value

    // Handle if the serchedValue dsn't exist or is not in KEYWORDS LIST
    if(returnedValue != NULL){
        printf("The transalte of '%s' is '%s'\n", searchedKey, returnedValue);
    } else {
        printf("There is not a transalte for '%s'\n", searchedKey);
    }

    return 0;
}
