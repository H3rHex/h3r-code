# h3rcode (h3rc)

# ENGLISH (INGLES)
**MAY NOT WORK WITH WINDOWS

### Description:

**h3rcode** (also known as **h3rc**) is a simplified dialect of the **C** programming language. Its goal is to replace the standard C keywords with custom keywords that are more user-friendly and easier to understand, especially for beginners. Although it is a dialect with modified keywords, its base is still **C**, so anyone familiar with C should be able to work with **h3rcode** without difficulty.

The **h3rcode** compiler translates files with a `.h3rc` extension into standard C, and then the generated C code can be compiled using tools such as **GCC**. However, for the time being, **h3rcode** is quite limited and does not support advanced features such as the creation of functions or complex structures. All code must be written inside the `main()` function.

### Current features:

- **Simplified syntax**: Uses custom keywords to make it more accessible.
- .h3rc files**: Programs are written in files with this extension.
- C compilation**: The compiler converts `.h3rc` code into standard **C** code, which can then be compiled with GCC or another compiler.
- **Supported keywords**:
| **h3rcode** | **C standard** |
|-----------------------------------------|-----------------------------|
| | `printf(‘Hello World’);` | `printf(‘Hello World’);` | | `printf(‘Hello World’);` |
| ``get (‘%d’, &num);` | `scanf(‘%d’, &num);` | |
| `standby(5);` | `sleep(5);` *(LINUX ONLY)* | |
| `if` | `if` |
| `if_not` | `else` | |
| | ``integer num1 = 1;` | `int num1 = 1;` | |
| | `equal` | `==` |



1. **Write the program** in a file with extension `.h3rc`.
2. **Compile the file** `.h3rc` using the **h3rcode** compiler with the following command:
   
   `
   ./compiler -f <your/path/file.h3rc> -or<output_name.c>
  `
### EXAMPLE:
**h3rcode**
``` 
print (‘Enter a number:’``);
integer number;
get (‘%d’, &number);
print (‘The number is: %d’, number);

```
**C (compiled by the h3rcode compiler)**; ````C (compiled by the h3rcode compiler)
``` 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> #include <unistd.h> #include <unistd.h> 

int main(){
int number; 
scanf(‘%d’, &number); 
printf(‘The number is: %d’, number); 

 return 0; 
}

```

### SUGGESTIONS WELCOME
**h3rhex - 2025 **h3rhex - 2025**


# ESPAÑOL (SPANISH)

**ES POSIBLE QUE NO FUNCIONE CON WINDOWS**

### Descripción:

**h3rcode** (también conocido como **h3rc**) es un dialecto simplificado del lenguaje de programación **C**. Su objetivo es reemplazar las palabras clave estándar de C por otras personalizadas, más amigables y fáciles de entender, especialmente para los principiantes. A pesar de ser un dialecto con palabras clave modificadas, su base sigue siendo **C**, por lo que cualquier persona familiarizada con C debería poder trabajar con **h3rcode** sin dificultades.

El compilador de **h3rcode** traduce los archivos con extensión `.h3rc` a C estándar, y luego el código C generado puede ser compilado utilizando herramientas como **GCC**. Sin embargo, por el momento, **h3rcode** es bastante limitado y no soporta características avanzadas como la creación de funciones o estructuras complejas. Todo el código debe escribirse dentro de la función `main()`.

### Características actuales:

- **Sintaxis simplificada**: Utiliza palabras clave personalizadas para hacerlo más accesible.
- **Archivos `.h3rc`**: Los programas se escriben en archivos con esta extensión.
- **Compilación en C**: El compilador convierte el código `.h3rc` en código **C** estándar, que luego puede ser compilado con GCC u otro compilador.
- **Palabras clave soportadas**:

| **h3rcode**                             | **C estándar**               |
|-----------------------------------------|-----------------------------|
| `imprime ("Hello World");`              | `printf("Hello World");`    |
| `obtener ("%d", &num);`                 | `scanf("%d", &num);`        |
| `espera (5);`                           | `sleep(5);` *(SOLO LINUX)*  |
| `si`                                    | `if`                        |
| `si_no`                                 | `else`                      |
| `entero num1 = 1;`                      | `int num1 = 1;`             |
| `igual`                                 | `==`                        |

### Uso del compilador:

1. **Escribir el programa** en un archivo con extensión `.h3rc`.
2. **Compilar el archivo** `.h3rc` usando el compilador **h3rcode** con el siguiente comando:
   
   `
   ./compiler -f <your/path/file.h3rc> -o <nombre_de_salida.c>
  `
### EJEMPLO:
**h3rcode**
``` 
imprime ("Introduce un numero: "\n);
entero numero;
obtener ("%d", &numero);
imprime ("El numero es: %d\n", numero);

```
**C (compilado por el compilador de h3rcode)**
``` 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main(){
int numero; 
scanf("%d", &numero); 
printf("El numero es: %d\n", numero); 

 return 0; 
}

```

### SE ACEPTAN SUGERENCIAS
**h3rhex - 2025**