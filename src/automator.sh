#!/bin/bash

numPoints=10

program=$1
numRuns=$2

echo ----------------------------------------------------------------
echo TESTING $program. EACH OUTPUT IS THE AVERAGE CYCLES OF TEN RUNS
echo ---------------------------------------------------------------- 

function run {
  for i in `seq 1 13`
  do
      cat temp.in | ./$program
  done
}

for j in `seq 1 $numRuns`
do
 ./point-set-generator $numPoints 100 -s > temp.in
  echo Running $program with $numPoints points...
  run $numPoints | ./averager
  numPoints=$(($numPoints*2))
  

done
