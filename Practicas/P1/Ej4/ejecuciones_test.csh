#!/bin/csh
@ inicio = 100
@ fin = 30000
@ incremento = 500
set ejecutable = test_ordenacion
set salida = tiempos_mejor.dat
set salida1 = tiempos_peor.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 0` >> $salida
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 1` >> $salida1
  @ i += $incremento
end
