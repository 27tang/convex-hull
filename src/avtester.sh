#!/bin/bash

numPoints=$1


#for j in `seq 1 5`
#do

  for i in `seq 1 13`
  do
    ./point-set-generator $numPoints 100 -s > temp.in &&
      cat temp.in | ./matt-quick
  done
  
  #numPoints=$(($numPoints*10))
  

#done
