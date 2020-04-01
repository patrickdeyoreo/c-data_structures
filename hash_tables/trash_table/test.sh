#!/usr/bin/env bash
#
# Attempt to compile sources into an executable and invoke it across a range
# of arguments. If a template is specified, it will be used to generate the
# arguments supplied to the program. Otherwise, test arguments will consist
# simply of randomly-generated values. If called with no non-option arguments
# all source files found in the directory heierarchy rooted at the location
# of this script will be passed to gcc for compilation. If any non-option
# arguments are supplied, they and they alone will be passed to gcc.
# usage: test.sh [-v] [-t TEMPLATE] [--] [SOURCE] ...

# Requests a response from the user regarding a "yes-or-no" question
# Usage: confirm [PROMPT]
# Return Values:
# 0 if a "yes" or otherwise positive response was recieved.
# 1 if a "no" or otherwise negative response was received.
confirm_exit()
{
  local -
  set -o errexit
  local -u REPLY
  while read -r -N 1 -p 'Are you sure you want to exit? [Y/n] '
  do
    echo
    case ${REPLY} in
      Y) return 0 ;;
      N) return 1 ;;
    esac
  done
}

# If the shell is interactive, request confirmation before exiting upon
# receiveing Ctrl-C (SIGINT). Otherwise exit quieltly with the proper status.
trap 'echo
[[ -t 0 ]] && confirm_exit || {
  trap INT && kill -s INT "$$" || exit 130
}' INT

# Configure the environment and compile executable. Exit if this fails.
set -o errexit

# Initialize loop variables.
chars=( )
items=( )
printf -v beg '%d' "'a"
printf -v end '%d' "'z"

# Enter the directory in which this script resides
CDPATH='' cd -- "${BASH_SOURCE[0]%/*}"

# Make a directory for temporary files and set a trap to remove it upon exit.
tmpdir="$(mktemp -d --tmpdir)"
if ! trap 'rm -fr -- "${tmpdir}" 2> /dev/null' EXIT
then
  rm -fr "${tmpdir}"
  exit 1
fi

# Try to compile all non-hidden .c files from all non-hidden directories at
# or below the location of this script. Provide file or directory names as
# arguments to override this behavior.
if ! (( $# ))
then
  shopt -s globstar nullglob
  set -- ./**/*.c
  shopt -u globstar nullglob
fi
gcc -g -Wall -Werror -Wextra -pedantic -o "${tmpdir}/test" "$@"

# Environment configured. Compilation successful.
set +o errexit

# Execute program with randomly generated arguments.
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
