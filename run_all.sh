#!/bin/bash -e

ROOT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)

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

function main() {
  cd "$ROOT_DIR"

  local src_file
  while read -r src_file; do
    if [[ "$src_file" =~ .*cc$ ]]; then
      method_cc "$src_file"
    fi
  done <<<"$(find . -name '*.cc' | sort)"
}

main
