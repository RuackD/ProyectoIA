Por ahora el codigo no se ejecuta, hace falta la implementación en el main para que llame a las funciones y haga el archivo.
Por ahora si se ejecuta lo único que hace es abrir la instancia y guardar los parametros de cada avión en un vector de structs
de tipo Avion. 

Para compilar utilizar en la terminal:
make compile
Para borrar los archivos compilados:
make clean 

Cambios a implementar:
Hacer el greedy para la primera solucion, en los resets ocupar aleatorias. 
Hacer una listas auxiliar para guardar las pos de los aviones, sortear la solucion de menor a mayor
para no tener que iterar con dos for y poder comprobar las separaciones mas rapidos 