# Soluciones de Ejercicios en Lenguaje C (Windows)

Este repositorio contiene la solución a los siguientes ejercicios implementados en C, pensados para compilarse en un entorno Windows (usando un IDE como Visual Studio, Code::Blocks o similar):

1. **Ejercicio 1: Validación de notación FEN**  
   - **Archivo:** ejercicio1.c  
   - **Descripción:** Programa que valida si una cadena de texto cumple con el formato FEN, utilizado para representar posiciones de ajedrez.  
   - **Instrucciones de compilación en un IDE:**  
     1. Abra su IDE de C (por ejemplo, Visual Studio o Code::Blocks).  
     2. Cree un nuevo proyecto de aplicación de consola en C.  
     3. Agregue el archivo `ejercicio1.c` al proyecto.  
     4. Compile y ejecute el proyecto desde el IDE.

2. **Ejercicio 2: Generación y evaluación del polinomio (x+1)^n mediante el Triángulo de Pascal**  
   - **Archivo:** ejercicio2.c  
   - **Descripción:** Programa que genera los coeficientes del polinomio (x+1)^n utilizando el Triángulo de Pascal, muestra el polinomio en forma expandida y lo evalúa para un valor ingresado de x, mostrando el cálculo paso a paso.  
   - **Instrucciones de compilación en un IDE:**  
     1. Abra su IDE de C.  
     2. Cree un nuevo proyecto de consola en C.  
     3. Agregue el archivo `ejercicio2.c` al proyecto.  
     4. Compile y ejecute el proyecto desde el IDE.

3. **Ejercicio 3: Evaluación de expresiones aritméticas con notación científica**  
   - **Archivo:** ejercicio3.c  
   - **Descripción:** Programa que evalúa expresiones aritméticas que soportan los operadores +, -, *, / y números escritos en notación científica (por ejemplo, 125E10 o 5e-8).  
   - **Instrucciones de compilación en un IDE:**  
     1. Abra su IDE de C.  
     2. Cree un nuevo proyecto de aplicación de consola.  
     3. Agregue el archivo `ejercicio3.c` al proyecto.  
     4. Compile y ejecute el proyecto desde el IDE.

4. **Ejercicio 4: Contar y mostrar ocurrencias de una palabra en una cadena**  
   - **Archivo:** ejercicio4.c  
   - **Descripción:** Programa que cuenta cuántas veces aparece una palabra específica en una cadena de texto y muestra las posiciones donde se encuentra cada ocurrencia.  
   - **Instrucciones de compilación en un IDE:**  
     1. Abra su IDE de C.  
     2. Cree un nuevo proyecto de consola en C.  
     3. Agregue el archivo `ejercicio4.c` al proyecto.  
     4. Compile y ejecute el proyecto desde el IDE.

---

## Instalación y Configuración

Para trabajar en Windows, siga estos pasos generales:

1. **Instalar un IDE para C:**  
   - **Visual Studio:** Descargue e instale [Visual Studio Community](https://visualstudio.microsoft.com/es/vs/community/) y asegúrese de incluir la carga de trabajo "Desarrollo de escritorio con C++" (aunque el proyecto sea en C, esta carga de trabajo incluye el compilador de C).  
   - **Code::Blocks:** Descargue e instale [Code::Blocks](http://www.codeblocks.org/downloads) (la versión que incluye MinGW).

2. **Crear y Configurar Proyectos:**  
   - Abra el IDE elegido y cree un nuevo proyecto de consola en C.  
   - Agregue el archivo fuente correspondiente (ejercicio1.c, ejercicio2.c, etc.) al proyecto.  
   - Configure las opciones de compilación si es necesario (en Visual Studio, usualmente no se requiere configuración adicional para programas simples en C).

3. **Compilación y Ejecución:**  
   - Compile el proyecto desde el menú del IDE (normalmente usando la opción "Build" o "Compilar").  
   - Ejecute el programa desde el IDE (usualmente con "Start" o "Iniciar").

---

## Requisitos

- **Sistema Operativo:** Windows (7, 8, 10 o superior).  
- **IDE para C:** Visual Studio, Code::Blocks o similar.  
- **Compilador:** El compilador provisto por el IDE (por ejemplo, cl.exe en Visual Studio o gcc/MinGW en Code::Blocks).

---

## Conclusión

Este repositorio contiene programas en C que abordan diversos problemas:
- Validación de la notación FEN para ajedrez.
- Generación y evaluación del polinomio (x+1)^n usando el Triángulo de Pascal.
- Evaluación de expresiones aritméticas con números en notación científica.
- Búsqueda y conteo de ocurrencias de una palabra en una cadena de texto.

Cada ejercicio está diseñado para compilar y ejecutarse de forma independiente mediante un IDE en Windows. ¡Siéntase libre de modificar o ampliar estos ejercicios según sus necesidades!
