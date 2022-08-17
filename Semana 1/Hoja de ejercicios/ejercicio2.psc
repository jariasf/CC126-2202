Algoritmo pagoEmpleado
    // Entrada
    Escribir "Ingrese el total de horas trabajadas: "
    Leer horas_trabajadas
    Escribir "Ingrese la tarifa horaria: "
    Leer tarifa_horaria

    // Proceso
	sueldo_basico = horas_trabajadas * tarifa_horaria
    bonificacion = 0.18 * sueldo_basico
    sueldo_bruto = sueldo_basico + bonificacion
    //TODO: Calcular el sueldo neto
	
    // Salida
    Escribir "El sueldo basico es ", sueldo_basico
    Escribir "El sueldo bruto es ", sueldo_bruto
	
FinAlgoritmo
