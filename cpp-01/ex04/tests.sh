#!/usr/bin/env bash

TEST_FILE="test"

setup() {
  echo "Compiling..."
  make all 2>&1 >/dev/null

  cat << EOF > "$TEST_FILE"
Lorem ipsum dolor sit amet, officia excepteur ex fugiat reprehenderit enim
labore culpa sint ad nisi Lorem pariatur mollit ex esse exercitation amet. Nisi
anim cupidatat excepteur officia. Reprehenderit nostrud nostrud ipsum Lorem est
aliquip amet voluptate voluptate dolor minim nulla est proident. Nostrud
officia pariatur ut officia. Sit irure elit esse ea nulla sunt ex occaecat
reprehenderit commodo officia dolor Lorem duis laboris cupidatat officia
voluptate. Culpa proident adipisicing id nulla nisi laboris ex in Lorem sunt
duis officia eiusmod. Aliqua reprehenderit commodo ex non excepteur duis sunt
velit enim. Voluptate laboris sint cupidatat ullamco ut ea consectetur et est
culpa et culpa duis.
EOF
}

test_empty() {
  SEARCH=""
  REPLACE="$1"

  ./fed "$TEST_FILE" "$SEARCH" "$REPLACE"

  if cmp "${TEST_FILE}.replace" "${TEST_FILE}"; then
    echo "[OK] search=<empty_string> replace=$REPLACE"
  else
    echo "[KO] search=<empty_string> replace=$REPLACE"
  fi
}

test_replace() {
  SEARCH="$1"
  REPLACE="$2"

  ./fed "$TEST_FILE" "$SEARCH" "$REPLACE"
  sed "s/$SEARCH/$REPLACE/g" "$TEST_FILE" > "${TEST_FILE}.expected"

  if cmp "$TEST_FILE.replace" "$TEST_FILE.expected"; then
    echo "[OK] search=$SEARCH replace=$REPLACE"
  else
    echo "[KO] search=$SEARCH replace=$REPLACE"
    diff "$TEST_FILE.replace" "$TEST_FILE.expected"
  fi
}

teardown() {
  make fclean 2>&1 >/dev/null

  if [[ -f "$TEST_FILE" ]]; then
    rm "$TEST_FILE"
  fi

  if [[ -f "$TEST_FILE.replace" ]]; then
    rm "$TEST_FILE.replace"
  fi

  if [[ -f "$TEST_FILE.expected" ]]; then
    rm "$TEST_FILE.expected"
  fi
}

setup

echo "Running tests:"

test_empty "Lorem ✋"

test_replace "Lorem" "Lorem ✋"
test_replace "dol" "DOL"
test_replace "a" "A"
test_replace "b" "B"
test_replace "não-existe" "blahblah"

teardown
