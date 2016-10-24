#!/bin/csh
@ inicio = 2
@ fin = 750
@ incremento = 7
set ejecutable = matrices
set salida = tiempos_matrices.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
