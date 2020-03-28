#!/usr/bin/env bash
#
# Compile the program and run the executable

interactive_exit()
{
  local REPLY
  read -r -N 1 -p 'Are you sure you want to exit?'
  echo
  [[ ${REPLY^} = Y ]] || return 1
}

set -o errexit

tmpdir="$(mktemp -d --tmpdir)"

trap 'rm -fr -- "${tmpdir}" 2> /dev/null' EXIT

CDPATH='' cd -- "${BASH_SOURCE[0]%/*}"

shopt -s globstar

gcc -g -Wall -Werror -Wextra -pedantic ./**/*.c -o "${tmpdir}/test"

shopt -u globstar

trap '
[[ -t 0 ]] && interactive_exit || {
  trap SIGINT 
  kill -s INT "$$"
}' SIGINT

set +o errexit

beg=-5
end=5
items=()
line=''
while (( ${#line} < $(tput cols) ))
do
  line="${line}#"
done

# shellcheck disable=SC2059
for (( ord = beg; ord <= end; ++ord ))
do
  readarray -t items < <(shuf --echo -- "${items[@]}")
 
  printf '%s\n' "${line}"

  set -o verbose

  "${tmpdir}/test" "${items[@]}"

  set +o verbose

  items+=("${ord}")
done
