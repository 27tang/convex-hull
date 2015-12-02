all: point-line-tester brute-force quick-hull point-set-generator matt-quick grapher

point-line-tester: point-line-tester.cpp point-line.cpp
	g++ point-line-tester.cpp point-line.cpp -o point-line-tester -g

brute-force: point-line.cpp brute-force.cpp
	g++ point-line.cpp brute-force.cpp -o brute-force -g

quick-hull: point-line.cpp quick-hull.cpp
	g++ point-line.cpp quick-hull.cpp -o quick-hull -g

point-set-generator: point-set-generator.cpp point-line.cpp
	g++ point-set-generator.cpp point-line.cpp -o point-set-generator -g

grapher: grapher.cpp point-line.cpp
	g++ grapher.cpp point-line.cpp -o grapher -g

matt-quick: point-line.cpp matt-quick-hull.cpp
	g++ point-line.cpp matt-quick-hull.cpp -o matt-quick -g
