all: averager point-line-tester brute-force quick-hull point-set-generator matt-quick grapher brook-brute brook-quick

point-line-tester: point-line-tester.cpp point-line.cpp
	g++ point-line-tester.cpp point-line.cpp -o point-line-tester -g

brute-force: point-line.cpp brute-force.cpp
	g++ -O3 point-line.cpp brute-force.cpp -o brute-force -g

quick-hull: point-line.cpp quick-hull.cpp
	g++ -O3 point-line.cpp quick-hull.cpp -o quick-hull -g

point-set-generator: point-set-generator.cpp point-line.cpp
	g++ point-set-generator.cpp point-line.cpp -o point-set-generator -g

grapher: grapher.cpp point-line.cpp
	g++ grapher.cpp point-line.cpp -o grapher -g

matt-quick: point-line.cpp matt-quick-hull.cpp
	g++ -O3 point-line.cpp matt-quick-hull.cpp -o matt-quick -g
	
averager: averager.cpp
	g++ averager.cpp -o averager -g 

brook-brute: brook-line.cpp brook-brute.cpp
	g++ -O3 brook-line.cpp brook-brute.cpp -o brook-brute -g

brook-quick: brook-line.cpp brook-quick.cpp
	g++ -O3 brook-line.cpp brook-quick.cpp -o brook-quick -g
