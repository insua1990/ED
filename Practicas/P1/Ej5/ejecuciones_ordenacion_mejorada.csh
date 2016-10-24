#!/bin/csh
@ inicio = 100
@ fin = 300000000
@ incremento = 5000000
set ejecutable = ordenacion_mejorada
set salida = tiempos_ordenacion_mejorada.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
