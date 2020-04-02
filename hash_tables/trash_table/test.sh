#!/usr/bin/env bash
#
# Attempt to compile sources into an executable and invoke it across
# a variety of arguments. If this script is called without arguments,
# all source files in the directory heierarchy rooted at the location
# of this file will be passed to gcc for compilation. If called with
# arguments, they and they alone will be passed to gcc.
#
# Usage: test.sh [SOURCE] ...
######################################################################

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
  echo
  while read -r -N 1 -p 'Are you sure you want to exit? [Y/n] '
  do
    case ${REPLY/$'\n'} in
      Y) return 0 ;;
      N) return 1 ;;
      ?) echo     ;;
    esac
  done
}

# Configure the environment and compile the executable. If this fails, exit.
set -o errexit

# Initialize loop variables.
unset ascii
unset index
unset input
chars=( )
items=( )
printf -v lower '%d' "'A"
printf -v upper '%d' "'z"

# If the shell is interactive, request confirmation before exiting upon
# receiveing Ctrl-C (SIGINT). Otherwise exit quieltly with the proper status.
trap '
echo
if ! [[ -t 0 ]] || confirm_exit
then
  exec {input}>&-
  trap INT && kill -INT "$$" || exit 130
fi
' INT

# Make a directory for temporary files and set a trap to remove it upon exit.
unset tmpdir
trap '
rm -fr -- "${tmpdir}" 2> /dev/null
' EXIT
tmpdir="$(mktemp -d --tmpdir)"

# Enter the directory in which this script resides
CDPATH='' cd -- "${BASH_SOURCE[0]%/*}"

# Try to compile all non-hidden .c files from all non-hidden directories at
# or below the location of this script. Provide file or directory names as
# arguments to override this behavior.
if ! (( $# ))
then
  shopt -s globstar nullglob
  set -- ./**/*.c
  shopt -u globstar nullglob
fi
gcc -g -Wall -Werror -Wextra -pedantic -o "${tmpdir}/main" "$@"

# Environment configured. Compilation successful.
set +o errexit

# Execute program with randomly generated arguments.
for (( ascii = lower; ascii <= upper; ascii = (16#${ascii}) + 1 ))
do
  printf -v 'ascii' '%02x' "${ascii}"

  printf -v "chars[$((16#${ascii}))]" '%b' "\x${ascii}"

  for index in "${!chars[@]}"
  do
    items+=("$((16#${ascii}+index))=${chars[16#${ascii}]}+${chars[index]}")
  done
  if wait "$!" && IFS=$'\n' read -a items  -d '' -r -u "$((input))"
  then
    "${tmpdir}/main" "${items[@]}"
  fi {input}< <(shuf --echo -- "${items[@]}" && printf '\0')

  if (( 16#${ascii} != upper ))
  then
    sleep 1
    echo
    echo '****************'
    echo
  fi {input}>&-
done
