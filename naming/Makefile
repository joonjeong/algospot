test: main
	./main < sample.txt

test2: main2
	./main2 < sample.txt

test2_kmp: main2_kmp
	./main2_kmp < sample.txt

%: %.cc
	g++ -g -std=c++11 -o $@ $^

kmp_test: kmp.cc kmp_test.cc
	g++ -g -std=c++11 -o $@ $^

main2_kmp: main2_kmp.cc kmp.cc
	g++ -g -std=c++11 -o $@ $^