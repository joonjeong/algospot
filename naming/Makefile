test: main
	./main < sample.txt

test2: main2
	./main2 < sample.txt

test2_kmp: main2_kmp
	./main2_kmp < sample.txt

test_kmp: main_kmp_test
	./main_kmp_test partial alala
	echo
	./main_kmp_test partial alalapartialalala
	echo
	./main_kmp_test kmp alala al
	echo
	./main_kmp_test kmp alalapartialalala partial
	echo
	./main_kmp_test kmp alalapartialalala ala
	echo
	./main_kmp_test kmp alalapartialalala alala

%: %.cc
	g++ -g -std=c++11 -o $@ $^

main_kmp_test: kmp.cc kmp_test.cc
	g++ -g -std=c++11 -o $@ $^

main2_kmp: main2_kmp.cc kmp.cc
	g++ -g -std=c++11 -o $@ $^