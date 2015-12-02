
numPoints=$1
range=$2
screenSize=$(($range * 10 ))

echo $screenSize

./point-set-generator $numPoints $range -s > temp.in &&
  cat temp.in | ./quick-hull -g | ./grapher $range > quickRes.out &&
  cat temp.in | ./brute-force -g  | ./grapher $range > bruteRes.out && 
  cat temp.in | ./quick-hull >> quickRes.out &&
  cat temp.in | ./brute-force >> bruteRes.out && 
  diff -y quickRes.out bruteRes.out -W "$screenSize"

