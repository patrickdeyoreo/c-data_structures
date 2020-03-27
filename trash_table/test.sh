#!/usr/bin/env bash

set -o errexit

tmpdir="$(mktemp -d --tmpdir)"
trap 'rm -fr -- "${tmpdir}" 2> /dev/null' EXIT

CDPATH='' cd -- "${BASH_SOURCE[0]%/*}"

shopt -s globstar

gcc -g -Wall -Werror -Wextra -pedantic ./**/*.c -o "${tmpdir}/test"

shopt -u globstar

set +o errexit

printf -v beg '%d' "'a"
printf -v end '%d' "'z"
chars=( )
items=( )
# shellcheck disable=SC2059
for (( ord = beg; ord <= end; ++ord ))
do
  printf -v 'hex' '\\x%02x' "${ord}"
  printf -v "chars[${ord}]" "${hex}"

  for char in "${chars[@]}"
  do
    items+=("${chars[-1]}${char}=${RANDOM}")
  done
  
  readarray -t items < <(shuf --echo -- "${items[@]}")

  set -o verbose

  "${tmpdir}/test" "${items[@]}"

  set +o verbose
done
