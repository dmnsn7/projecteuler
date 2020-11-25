#!/bin/bash -e

ROOT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

CONCURRENCY=10

tmpfile="/tmp/$$.fifo"
mkfifo $tmpfile
exec 6<>$tmpfile
rm $tmpfile

for ((i = 0; i < CONCURRENCY; i++)); do
  echo >&6
done

function get_prob_id() {
  echo "$1" | awk -F '/' '{print $NF}' | awk -F '.' '{print $1}'
}

function method_cc() {
  pushd "$(dirname "$1")" >/dev/null 2>&1
  local prob_id ans_file data_file
  prob_id=$(get_prob_id "$1")
  cc_file=./$prob_id.cc
  ans_file=./$prob_id.ans
  bin_file=./$prob_id.bin
  data_file=./$prob_id.data
  if [[ ! -f $ans_file ]]; then
    g++-9 "$cc_file" -o "$bin_file"
    if [[ ! -f $data_file ]]; then
      $bin_file >"$ans_file"
    else
      $bin_file <"$data_file" >"$ans_file"
    fi
    rm "$bin_file"
  fi
  echo "Problem $prob_id: $(cat "$ans_file")"
  popd >/dev/null 2>&1
}

function method_py() {
  pushd "$(dirname "$1")" >/dev/null 2>&1
  local prob_id ans_file data_file
  prob_id=$(get_prob_id "$1")
  py_file=./$prob_id.py
  ans_file=./$prob_id.ans
  data_file=./$prob_id.data
  chmod +x "$py_file"
  if [[ ! -f $ans_file ]]; then
    if [[ ! -f $data_file ]]; then
      $py_file >"$ans_file"
    else
      $py_file <"$data_file" >"$ans_file"
    fi
  fi
  echo "Problem $prob_id: $(cat "$ans_file")"
  popd >/dev/null 2>&1
}

function main() {
  cd "$ROOT_DIR"

  local src_file
  while read -r src_file; do
    read -r <&6
    {
      if [[ $src_file =~ ^.*cc$ ]]; then
        method_cc "$src_file"
      fi
      if [[ $src_file =~ ^.*py$ ]]; then
        method_py "$src_file"
      fi
      echo >&6
    } &
  done <<<"$(find . | grep -E '^.*(cc|py)$' | grep -v 'templates' | sort)"
}

main | sort

wait
exec 6>&-
