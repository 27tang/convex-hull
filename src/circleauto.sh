

for j in `seq $1 $2`
do
  echo NUMBER IS $(($j-2))
./point-set-generator 150 $j -c | ./brute-force -g | ./grapher $j
done
