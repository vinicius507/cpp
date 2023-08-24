#!/usr/bin/env bash

setup() {
  clear
  echo "Compiling..."
  make 2>&1 >/dev/null
  echo
}

teardown() {
  echo "Cleaning up..."
  make fclean 2>&1 >/dev/null
}

rpn() {
  EXPR="$1"

  ./RPN "$EXPR"
}

test() {
  EXPR="$1"
  EXPECT="$2"

  ACTUAL=$(rpn "$EXPR" 2>&1)

  if [ "$ACTUAL" = "$EXPECT" ]; then
    echo "[OK] test: rpn expr='$EXPR'"
  else
    echo "[KO] test: rpn expr='$EXPR'"
  fi
  echo "Got: '$ACTUAL'"
  echo "Expected: '$EXPECT'"
  echo
}

setup

test "2 2 +" "4"
test "3 5 +" "8"
test "6 3 -" "3"
test "4 2 /" "2"
test "2 3 *" "6"
test "8 2 /" "4"
test "9 3 - 2 / 7 +" "10"
test "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" "42"

test "a b +" "Error: Invalid token: 'a'"
test "3 4 c +" "Error: Invalid token: 'c'"
test "2" "Error: Unterminated expression"
test "5 0 /" "Error: Division by zero"
test "3 +" "Error: Insufficient operands"
test "1 2 + +" "Error: Insufficient operands"
test "" "Error: Empty expression"
test "4 2 / /" "Error: Insufficient operands"
test "2 0 /" "Error: Division by zero"
test "9 3 - 2 / +" "Error: Insufficient operands"
test "1 0 /" "Error: Division by zero"
test "7 2 * -" "Error: Insufficient operands"
test "5 0 /" "Error: Division by zero"
test "6 3 - 0 /" "Error: Division by zero"
test "4 2 / +" "Error: Insufficient operands"

teardown
