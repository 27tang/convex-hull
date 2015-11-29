./point-set-generator 10 10 -s > temp.in &&
  cat temp.in | ./quick-hull -g | ./grapher 15 > quickRes.out &&
  cat temp.in | ./brute-force -g  | ./grapher 15 > bruteRes.out && 
  cat temp.in | ./quick-hull >> quickRes.out &&
  cat temp.in | ./brute-force >> bruteRes.out && 
  diff -y quickRes.out bruteRes.out -W 180

