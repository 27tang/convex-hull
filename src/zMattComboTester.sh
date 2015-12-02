./point-set-generator 1000 30 -s > temp.in &&
  cat temp.in | ./matt-quick -g | ./grapher 31 > quickRes.out &&
  cat temp.in | ./quick-hull -g  | ./grapher 31 > bruteRes.out && 
  cat temp.in | ./matt-quick >> quickRes.out &&
  cat temp.in | ./quick-hull >> bruteRes.out && 
  diff -y quickRes.out bruteRes.out -W 180

