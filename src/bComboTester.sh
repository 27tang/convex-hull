
numPoints=$1
range=$2
screenSize=$(($range * 10 ))

echo $screenSize

./point-set-generator $numPoints $range -s > temp.in &&
  cat temp.in | ./brook-quick | ./grapher $range > quickRes.out &&
  cat temp.in | ./matt-quick -g  | ./grapher $range > bruteRes.out && 
  diff -y quickRes.out bruteRes.out -W "$screenSize"

