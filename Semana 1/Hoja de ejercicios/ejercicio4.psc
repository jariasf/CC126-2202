Algoritmo revertirNumero
	
    Escribir Sin Saltar "Ingrese un n�mero: "
    Leer num

    Si num >= 100 y num <= 999 Entonces
        // num = 123
        d3 = num mod 10     // num mod 10 = 3
        num = trunc(num/10) // num = 12
        d2 = num mod 10     // 2
        d1 = trunc(num/10)  // 1
        Escribir "El n�mero al rev�s es ", d3, d2, d1		
    SiNo
        Escribir "N�mero incorrecto"
    Fin Si
	
FinAlgoritmo
