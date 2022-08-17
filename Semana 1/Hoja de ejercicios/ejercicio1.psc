Algoritmo calcularArea

    // Entrada
    Escribir "Ingrese el radio: "
    Leer R
    Escribir "Ingrese el lado del triangulo: "
    Leer H

    // Proceso 
    area_circunferencia = PI * R * R
    altura = raiz(H*H - R*R)
    area_triangulo = R * altura
    area_total = area_circunferencia/2 + area_triangulo

    // Salida
    Escribir "El area de la figura es ", area_total

FinAlgoritmo
