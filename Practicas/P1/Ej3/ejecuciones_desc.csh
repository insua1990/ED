#!/bin/csh
@ inicio = 100
@ fin = 1000000000
@ incremento = 1000000
set ejecutable = ejercicio_desc
set salida = tiempos_desc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end
