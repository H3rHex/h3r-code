#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of KEYWORDS
typedef struct {
    char clave[50];
    char valor[50];
} KEYWORDS;

char *out_file_name = "app.c";

// SEARCH VALUE ON A LIST
char* searchValue(KEYWORDS keys[], int size, const char* key) {
    for(int i = 0; i < size; i++){
        // If the searched key is in KEYWORDS LIST
        if(strcmp(keys[i].clave, key) == 0){
            return keys[i].valor;
        }
    }
    return NULL; // IF WORD IS NOT A KEYWORD
}

void translateToC(char * word){
    /* This funtion create a file if the file dosnt exist and write a line*/
    FILE *file = fopen(out_file_name, "a");
    
    // Check if file is empty
    fseek(file, 0 ,SEEK_END); // Move the pointer to the final
    long size = ftell(file); // Get pointer position

    if(size == 0) {
        fprintf(file, "#include <stdio.h> \n");
        fprintf(file, "#include <stdlib.h> \n");
        fprintf(file, "#include <unistd.h> \n");
        fprintf(file, "\nint main(){\n");
    } else {
        fprintf(file, "%s\n", word);
    }

    fclose(file);
}


int processFile(char* filePath){
    FILE *file = fopen(filePath, "r");
    
    size_t buffer_size = 256;
    char *buffer = (char *)malloc(buffer_size * sizeof(char));

    if (buffer == NULL) {  
        perror("Error al asignar memoria");
        fclose(file);
        return 1;
    }

    // Define keywords
    KEYWORDS keys[] = {
        {"imprime", "printf"},
        {"obtener", "scanf"},
        {"espera", "sleep"},
        {"si", "if"},
        {"si_no", "else"},
        {"entero", "int "},
        {"igual", "== "}
    };

    // Size of KEYWORDS List 
    int size = sizeof(keys) / sizeof(keys[0]);

    while (fgets(buffer, buffer_size, file) != NULL){

        // IF THE LINE IS BIGGER THAN BUFFER, ASSING MORE MEMORY
        if(strlen(buffer) == buffer_size -1 && buffer[buffer_size -2] != '\n'){
            /*
                strlen(buffer) == buffer_size -1 check if the size of readed 
                the equal to buffer size -1 (the last caracter is null '\0')

                buffer[buffer_size -2] != '\n' check if the last charcter is not an
                line break, if the last character is not an line break it means that the
                buffer size is smaller than line
            */ 

           buffer_size *= 2; // Duplicate buffer size
            char *temp = (char *)realloc(buffer, buffer_size * sizeof(char)); // Realloc assigned memory

            if(buffer == NULL) {
                perror("Error realloc process failed (code buffer_realloc)");
                free(buffer);
                fclose(file);
                return 1;
            }
            buffer = temp;
        }

        char *word = strtok(buffer, " \t\n"); // Split by spaces, tabs, or newlines
        
        size_t line_size = buffer_size *2;
        char *line = (char *)malloc(line_size * sizeof(char));

         if (line == NULL) {
            perror("Error allocating memory for line");
            free(line);
            free(buffer);
            fclose(file);
            return 1;
        }
        line[0] = '\0'; // Initialize the line to empty to avoid garbage values
        
        while (word != NULL){
            if (strlen(line) + strlen(word) + 1 >= line_size) {
                line_size *= 2;
                char *temp = (char *)realloc(line, line_size * sizeof(char));
                if (temp == NULL) {
                    perror("Error reallocating line");
                    free(line);
                    free(buffer);
                    fclose(file);
                    return 1;
                }
                line = temp;
            }

            // Search for the translated value
            char* translated = searchValue(keys, size, word);
            if (translated != NULL) {
                strcat(line, translated);
            } else {
                strcat(line, word);
                strcat(line, " "); // Add space after word
            }
            
            word = strtok(NULL, " \t\n"); // Get the next token
        }
        translateToC(line);
        free(line);
    }
    translateToC("\n return 0; \n}");
    free(buffer);
    fclose(file);
}

// SEARCH IN THE PATH THE LAS '.' AND COMPARE IF THE EXTENSION IS h3rc
int checkExtension(const char *file, const char *extension){
    // Check the last '.'
    const char *punto = strrchr(file, '.');
    if (!punto || punto == file){
        return 0;
    }
    return strcmp(punto + 1, extension) == 0;
}

int fileExist(const char *filename) {
    FILE *file = fopen(filename, "r"); // Open file in read mode
    if(file) {
        fclose(file); // Close the file
        return 1;
    }
    return 0; // File does not exist
}

int main(int argc, char *argv[]){
    if (argc < 2) { // Minimun one argument
        printf("Usage: %s -h | -f <your/path/file.h3rc>\n", argv[0]);
        return 1;
    }

    // Check the argument
    if (strcmp(argv[1], "-h") == 0) {
        printf("-f <your/path/file.h3rc>\n");
        exit(0);
    } else if (strcmp(argv[1], "-f") == 0) {
        if (argc < 3) {
            printf("Error: Missing file path after -f\n");
            return 1;
        }

        if (!fileExist(argv[2])) {
            printf("Error: The file '%s' does not exist\n", argv[2]);
            exit(EXIT_FAILURE);
        }

        if (checkExtension(argv[2], "h3rc")) {
            if (strcmp(argv[4], "-o")){
                if(argc > 4){
                    out_file_name = argv[4];
                } else {
                    out_file_name = "app.c";
                }
            }
            processFile(argv[2]);
        } else {
            printf("Error: The file '%s' does not have the .h3rc extension\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        
    } else {
        printf("Incorrect argument: %s\n", argv[1]);
    }

    return 0;
}
