Algoritmo ejemploParticion
    // Algoritmo que particione un número de ocho cifras en 3 números acorde a lo
    // siguiente AAABBBCC, donde AAA es el primer número, BBB es el segundo número
    // y CC es el tercer número

    // Entrada
    Escribir "Ingrese un número: "
    Leer num  //12345608

    // Proceso
    num3 = num mod 100 // 08 = 8 = 0008 = 8
    num = trunc(num / 100) // 123456

    num2 = num mod 1000 // 456
    num1 = trunc(num/1000) // 123

    // Salida
    Escribir "El primer número es ", num1
    Escribir "El segundo número es ", num2
    Escribir "El tercer número es ", num3

FinAlgoritmo
