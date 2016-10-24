#!/bin/csh
@ inicio = 100
@ fin = 30000100
@ incremento = 1000000
set ejecutable = mergesort
set salida = tiempos_mergesort_10.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
