./point-set-generator 20 20 -s > temp.in &&
  cat temp.in | ./quick-hull -g | ./grapher 20 > quickRes.out &&
  cat temp.in | ./brute-force -g  | ./grapher 20 > bruteRes.out && 
  cat temp.in | ./quick-hull >> quickRes.out &&
  cat temp.in | ./brute-force >> bruteRes.out && 
  diff -y quickRes.out bruteRes.out -W 250

