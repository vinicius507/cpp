#!/usr/bin/env bash

setup() {
	echo "Compiling..."
	make 2>&1 >/dev/null
}

teardown() {
	echo "Cleaning up..."
	make fclean 2>&1 >/dev/null
}

test_PmergeMe() {
	NUMBERS=$@

	./PmergeMe ${NUMBERS[@]} 2>&1 | grep -q "Error" && echo "[KO] test ${NUMBERS[@]}" || echo "[OK] test ${NUMBERS[@]}"
}

test_PmergeMe_error() {
	NUMBERS=$@

	./PmergeMe ${NUMBERS[@]} 2>&1 | grep -q "Error" && echo "[OK] test_error ${NUMBERS[@]}" || echo "[KO] test ${NUMBERS[@]}"
}

test_PmergeMe_shuf() {
	CAP="$1"

	./PmergeMe $(shuf -i 1-"$CAP" -n "$CAP") 2>&1 | grep -q "Error" && echo "[KO] test_shuf cap=$CAP" || echo "[OK] test_shuf cap=$CAP"
}

setup

test_PmergeMe_error
test_PmergeMe_error 1 -2
test_PmergeMe_error a b
test_PmergeMe_error 0 1 2 10 4 250 32 26 12 a

test_PmergeMe 1
test_PmergeMe 1 2
test_PmergeMe 2 1

test_PmergeMe_shuf 100
test_PmergeMe_shuf 200
test_PmergeMe_shuf 1000
test_PmergeMe_shuf 3000

teardown
