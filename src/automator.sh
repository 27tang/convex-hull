#!/bin/bash

numPoints=$3

program=$1
numRuns=$2
iterations=$4

echo ----------------------------------------------------------------
echo TESTING $program. EACH OUTPUT IS THE AVERAGE CYCLES OF $numRuns RUNS
echo ---------------------------------------------------------------- 

function run {
  for i in `seq 1 13`
  do
      cat temp.in | ./$program -m $numRuns
  done
}

for j in `seq 1 $iterations`
do
 ./point-set-generator $numPoints 100 -s > temp.in
  echo Running $program with $numPoints points...
  cat temp.in | ./$program -m $numRuns  
  #run $numPoints | ./averager
  numPoints=$(($numPoints + 10))
  

done
