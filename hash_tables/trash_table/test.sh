#!/usr/bin/env bash
#
# Attempt to compile sources into an executable and invoke it across
# a variety of arguments. If this script is called without arguments,
# all source files in the directory heierarchy rooted at the location
# of this file will be passed to gcc for compilation. If called with
# arguments, they and they alone will be passed to gcc.
# usage: test.sh [SOURCE] ...


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


# Configure the environment and compile the executable. If this fails, exit.
set -o errexit

# If the shell is interactive, request confirmation before exiting upon
# receiveing Ctrl-C (SIGINT). Otherwise exit quieltly with the proper status.
trap 'echo
[[ -t 0 ]] && confirm_exit || {
  trap INT && kill -s INT "$$" || exit 130
}' INT

# Initialize loop variables.
chars=( )
items=( )
printf -v beg '%d' "'a"
printf -v end '%d' "'z"

# Enter the directory in which this script resides
CDPATH='' cd -- "${BASH_SOURCE[0]%/*}"

# Make a directory for temporary files and set a trap to remove it upon exit.
unset tmpdir
trap 'rm -fr -- "${tmpdir}" 2> /dev/null' EXIT
tmpdir="$(mktemp -d --tmpdir)"

# Try to compile all non-hidden .c files from all non-hidden directories at
# or below the location of this script. Provide file or directory names as
# arguments to override this behavior.
if ! (( $# ))
then
  shopt -s globstar nullglob
  set -- ./**/*.c
  shopt -u globstar nullglob
fi
gcc -g -Wall -Werror -Wextra -pedantic -o "${tmpdir}/exe" "$@"

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

  if IFS=$'\n' read -a items -d '' -r
  then
    "${tmpdir}/exe" "${items[@]}"
  fi < <(shuf -e -- "${items[@]}" && printf '\0')

  if (( ord != end ))
  then
    read -r -t 0.8
    echo
    echo '****************'
    echo
  fi <> <(:)
done
