#include <iostream>
using namespace std;

/*
Tipos de preguntas
------------------
1. Sumatorias
2. Figuras
3. Estadísticas
4. Animaciones

El examen contendrá 3 preguntas, los tipos serán seleccionados de forma aleatoria
Duración de 3 horas
*/

/*
Validación de entradas
- Validar los casos extremos (i.e. a >= 3, tienen que probar a = 3)
- Usar do-while para cada entrada
- Condición tiene que ser casos inválidos o negar la condición válida
*/



/*
Problemas de sumatorias
-----------------------
1. Encontrar una formulación para el i-ésimo término
2. Implementar el numerador y denominador
2.1 Variable de signo (+ - + -) en caso sea necesario
3. El término será igual signo * numerador/denominador
4. Actualizar el signo en caso sea necesario
5. Acumular los términos
*/
double calcularSumatoria(int n){
    double termino, numerador, denominador, suma;
    suma = 0;
    // Usar el signo cuando tengan sumatorias con signos intercalados
    // a - b + c - d + e
    // - a + b - c + d - e
    // Si el primer término es positivo entonces signo=1, de otro modo signo=-1
    int signo = 1;
    int inicio = 1; // Inicio puede ser 0 o 1 o otro valor
    for (int i = inicio; i <= n; ++i) {
        numerador = ...;
        denominador = ...;
        termino = signo * numerador / denominador;
        suma += termino;
        // signo *= -1; // Usar cuando tengan signos intercalados
    }
    return suma;
}

/*
Problemas de figuras
--------------------
1. Descomponer el problema en partes de lo complejo a lo mas simple
2. Si tienen una figura donde la parte superior es la misma que la inferior pero
   invertida
   Ejemplo:
       A
      ABC
     ABCDE
      ABC
       A
   Entonces enfocarse en hallar la parte superior y luego reutilizar para la parte inferior
3. Iterar correctamente por el número de filas y columnas
4. Determinar el número de columnas por fila
5. Valores a imprimir en cada fila (números desde 1...n, n...1, caracteres A...Z, Z..A, a..z)
6. Recordar que las figuras se imprimem fila por fila
7. En figuras de este tipo
     A
    ABC
   ABCDE
   Usualmente el número de espacios a imprimir (no el centrado) es: n - i donde n
   es el número de filas e i es la fila actual
  
8. IMPORTANTE: CENTRADO
8.1 Si queremos que el centro de la figura este en el centro de la consola
    Ejemplo
    0 1 2 ...      40    ....  80
                   A
                  ABC
                 ABCDE
                  ABC
                   A
    Entonces el número de espacios es: 40 - ancho_de_figura/2
    Cuando n es el ancho entonces tenemos 40-n/2 pero n no siempre es el ancho
    por ello tienen que calcularlo

8.2 Si quieremos que la figura se imprimir apartir del centro de la consola
    Ejemplo
    0 1 2 ...      40    ....  80
                    3
                    32
                    3 1
                    32
                    3
                    
    Entonces el número de espacios es: 40
*/

/*
Ejemplos de variaciones a partir de un problema básico
1
12
123
1234
12345
123456
1234567
12345678
123456789


9
92
923
9234
92345
923456
9234567
92345678
923456789

1
12
1 3
1  4
1   5
1    6
1     7
1      8
123456789

cada 3 filas mostrar una linea de asteriscos
*************** 0
*             * 1
*************** 2
*             * 3
*************** 4
*             * 5
*************** 6

(fila % 2 == 0) muestran asteriscos

cada 5 filas mostrar una linea de asteriscos
*************** 0
*             * 1
*             * 2
*             * 3
*************** 4
*             * 5
*             * 6
*             * 7
*************** 8
*             * 9
*             * 10
*             * 11
*************** 12
(fila % 4 == 0) muestran asteriscos
general (fila % d == 0 )
*/

/*
Problema de estadísticas
------------------------
1. Implementar el ingreso y probarlo
2. Identificar el caracter de Fin ('X', 'F', -1, ...), este caracter será
   considerado válido pero con otra funcionalidad (terminar el ingreso)
3. Resolver el problema por partes
4. Tipos usuales dentro del while: conteos, hallar el mayor, menor, etc.
5. Resultados: promedio, porcentajes, mayor/menor de N variables, mostrar el conteo, etc. 
6. No olvidarse de problemas los casos extremos, por ejemplo que sucede si ingreso el 
   caracter de fin al inicio.
7. No olvidarse que la división entre enteros es un entero, deben hacer el typecasting
*/
void problemaEstadisticas() {
    int edad;
    int menor;
    int usuarios = 0;

    while (...) {
        usuarios++; // conteo
        edad = ingresarEdad();
        // hallar el menor a medida que ingresamos
        if (usuarios == 1) {
            menor = edad;
        }
        else if(edad < menor) {
            menor = edad;
        }
    }
    cout << "El menor es " << menor << endl;
}

/*
Problema de animaciones
-----------------------
1. Verificar el punto de partida (estado inicial)
1.1 Que caracteres se muestran en la pantalla y en que dirección
    Ejemplo:
    Tanque puede estar en dirección norte, este, oeste
    Mostrar solo asterisco en una determinada posición
2. Para las direccíones pueden usar la técnica de incrementos (x+dx, y+dy)
2.1 Dependiendo de los valores de (dx,dy) puede identificar la dirección del objeto
    Ejemplo
    Si el objeto esta en la posición (x,y) y queremos moverlo a la izquierda entonces
    los incrementos son (dx = 0, dy = -1)
    Para moverlo solo hacemos x += dx; y += dy;
2.2 Si se desea cambiar la dirección del objeto, solo basta con cambiar el valor de los
    incrementos
3. Usualmente el programa se itera de forma indefinida en algunas animaciones
3.1 Es posible que el programa sea terminado presionando una tecla en particular
    Para ello usar el método _khhit() para detectar que se presiono una tecla
    y _getch() para capturar la tecla, dependiendo del código de la tecla 
    realizar una determinada acción
    Ejemplo:
    while(1){
       if( _kbhit()){
          tecla = _getch();
          if( tecla == ESCAPE ) break;
       }
    }
4. Para problemas donde sea necesario mover el objeto de forma manual (usando teclas)
   Usar _kbhit() y getch()
   Ejemplo:
    while(1){
       if( _kbhit()){
          tecla = _getch();
          if( tecla == FLECHA_IZQUIERDA ){
             // Realizar acción
          }
          else if( tecla == FLECHA_DERECHA ){
             // Realizar otra acción
          }
       }
    }
5. Los métodos más usados son:
   - SetCursorPosition(columna, fila)
   - SetConsoleSize(ancho, alto)
*/



int main() {

    return 0;
}