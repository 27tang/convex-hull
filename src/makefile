all: point-line-tester brute-force quick-hull

point-line-tester: point-line-tester.cpp point-line.cpp
	g++ point-line-tester.cpp point-line.cpp -o point-line-tester -g

brute-force: point-line.cpp brute-force.cpp
	g++ point-line.cpp brute-force.cpp -o brute-force -g

quick-hull: point-line.cpp quick-hull.cpp
	g++ point-line.cpp quick-hull.cpp -o quick-hull -g
