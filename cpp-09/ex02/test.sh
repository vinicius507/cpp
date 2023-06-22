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

test_PmergeMe 1 2

test_PmergeMe 2 1

test_PmergeMe_error 1

test_PmergeMe_error 1 -2

for n in $(seq 3 3000); do
	test_PmergeMe_shuf $n
done

teardown
