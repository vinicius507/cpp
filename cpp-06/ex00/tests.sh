#!/usr/bin/env bash

setup() {
	echo "Compiling..."
	make 2>&1 1>/dev/null
}

teardown() {
	echo "Cleaning up..."
	make fclean 2>&1 1>/dev/null
}

test() {
	KIND="$1"
	LITERAL="$2"

	echo "[test] kind=$KIND literal=$LITERAL"
	./convert "$LITERAL"
	echo "--------------------------------"
}

test_convert_char() {
	test "char" "'$1'"
}

test_convert_int() {
	test "int" "$1"
}

test_convert_float() {
	test "float" "$1"
}

test_convert_double() {
	test "double" "$1"
}

setup

test_convert_char "a"
test_convert_char "A"
test_convert_char "0"
test_convert_char "9"

test_convert_int "0"
test_convert_int "10"
test_convert_int "2147483647"
test_convert_int "-2147483648"

test_convert_float "0.f"
test_convert_float "0.0f"
test_convert_float "10.0f"
test_convert_float "256.42f"
test_convert_float "-1024.3f"
test_convert_float "2147483647.9f"
test_convert_float "2147483648.0f"
test_convert_float "-2147483648.9f"
test_convert_float "nanf"
test_convert_float "-nanf"
test_convert_float "inff"
test_convert_float "-inff"

test_convert_double "0."
test_convert_double "0.0"
test_convert_double "10.0"
test_convert_double "256.42"
test_convert_double "-1024.3"
test_convert_double "2147483647.9"
test_convert_double "2147483648.0"
test_convert_double "-2147483648.9"
test_convert_double "nan"
test_convert_double "-nan"
test_convert_double "inf"
test_convert_double "-inf"

teardown
