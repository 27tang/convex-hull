all: point-line-tester brute-force quick-hull point-set-generator brute-force-matt

point-line-tester: point-line-tester.cpp point-line.cpp
	g++ point-line-tester.cpp point-line.cpp -o point-line-tester -g

brute-force: point-line.cpp brute-force.cpp
	g++ point-line.cpp brute-force.cpp -o brute-force -g

quick-hull: point-line.cpp quick-hull.cpp
	g++ point-line.cpp quick-hull.cpp -o quick-hull -g

point-set-generator: point-set-generator.cpp
	g++ point-set-generator.cpp -o point-set-generator -g

brute-force-matt: point-line.cpp brute-force-matt.cpp
	g++ point-line.cpp brute-force-matt.cpp -o brute-force-matt -g
