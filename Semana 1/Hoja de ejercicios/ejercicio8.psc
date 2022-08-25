Algoritmo sumarSegundo
    Escribir "Ingrese el numero de horas: "
    Leer horas
    Escribir "Ingrese el numero de minutos: "
    Leer minutos	
    Escribir "Ingrese el numero de segundos: "
    Leer segundos

    segundos = segundos + 1
	
    Si segundos = 60 Entonces
        segundos = 0
        minutos = minutos + 1
        Si minutos = 60 Entonces
            minutos = 0
            horas = horas + 1
            Si horas = 24 Entonces
                horas = 0
            FinSi
        FinSi
    Fin Si
	
    Escribir horas, ":", minutos, ":", segundos	
	
FinAlgoritmo
