Algoritmo verificarCapicua
	
    Escribir "Ingrese un n�mero: "
    Leer num

    Si num >= 100 y num <= 999 Entonces
        // Verificar si es capicua
        // 123 no es capicua
        // 404 si es capicua
		
		// TODO: Obtener los d�gitos del n�mero
        //d3 = ...
        //d2 = ...
        //d1 = ...
		
        Si d1 = d3 Entonces
            Escribir "Es capicua"			
        SiNo
            Escribir "No es capicua"
		Fin Si
    SiNo
        Escribir "N�mero incorrecto"
    Fin Si
	
FinAlgoritmo
