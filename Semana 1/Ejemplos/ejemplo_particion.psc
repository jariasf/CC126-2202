Algoritmo ejemploParticion
    // Algoritmo que particione un n�mero de ocho cifras en 3 n�meros acorde a lo
    // siguiente AAABBBCC, donde AAA es el primer n�mero, BBB es el segundo n�mero
    // y CC es el tercer n�mero

    // Entrada
    Escribir "Ingrese un n�mero: "
    Leer num  //12345608

    // Proceso
    num3 = num mod 100 // 08 = 8 = 0008 = 8
    num = trunc(num / 100) // 123456

    num2 = num mod 1000 // 456
    num1 = trunc(num/1000) // 123

    // Salida
    Escribir "El primer n�mero es ", num1
    Escribir "El segundo n�mero es ", num2
    Escribir "El tercer n�mero es ", num3

FinAlgoritmo
