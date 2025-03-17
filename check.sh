#!/bin/bash

NUM_COUNT=${1:-10}

# Check if NUM_COUNT is a numeric string with regex.
if ! [[ "$NUM_COUNT" =~ ^[0-9]+$ ]]; then
	echo "Error: Number count must be a positive integer."
	exit 1
fi

MAX_NUM=${2:-50000}

if ! [[ "$NUM_COUNT" =~ ^[0-9]+$ ]]; then
	echo "Error: Max number must be a positive integer."
	exit 2
fi

numbers=()

# Function to check if the numbers array is sorted
is_sorted() {
	for ((i = 1; i < ${#numbers[@]}; i++)); do
		if (( ${numbers[i]} < ${numbers[i-1]} )); then
			return 1
		fi
	done
	return 0
}

while true; do

	numbers=()

	while [ ${#numbers[@]} -lt $NUM_COUNT ]; do
		num=$((RANDOM % (MAX_NUM + 1)))

		# Randomly decide to make the number negative or not
		if ((RANDOM % 2)); then
			num=$(( -num ))
		fi

		# Avoid duplicates
		if [[ ! " ${numbers[@]} " =~ " ${num} " ]]; then
			numbers+=($num)
		fi
	done

	if ! is_sorted; then
		break
	fi
done

ARG=$(IFS=" "; echo "${numbers[*]}")
OPERATIONS=$(./push_swap $ARG 2>/dev/null)
MOVEMENTS=$(echo "$OPERATIONS" | wc -l)
CHECKER_RESULT=$(echo "$OPERATIONS" | ./checker_linux $ARG)

printf "\e[1;34mNumber amount\e[0;30m: \e[1;35m$NUM_COUNT\e[0m\n"

# Checker result logic
if [ "$CHECKER_RESULT" == "OK" ]; then
	printf "\e[1;34mChecker result\e[0;30m: \e[1;32m$CHECKER_RESULT\e[0m\n"
elif [ "$CHECKER_RESULT" == "KO" ]; then
	printf "\e[1;34mChecker result\e[0;30m: \e[1;31m$CHECKER_RESULT\e[0m\n"
else
	printf "\e[1;34mChecker result\e[0;30m: \e[1;31mERROR\e[0m\n"
fi

# Generate files for the online visualizator
mkdir -p check
echo "$ARG" > check/numbers
echo "$OPERATIONS" > check/operations

# Call valgrind, generate log & print
if echo $* | grep -e "-vg" -q; then
	printf "\e[1;34mValgrind check\e[0;30m: "
	valgrind ./push_swap $ARG 1>/dev/null 2>check/valgrind
	if cat check/valgrind | grep -q 'no leaks are possible'; then
		printf "\e[1;32mOK\e[0m\n"
	else
		printf "\e[1;31mKO \e[1;30m(\e[1;33mSee check/valgrind\e[1;30m)\e[0m\n"
	fi
fi

# Set maximum amount of numbers as per subject requirements
MAX_MOVEMENTS=0
if ((NUM_COUNT == 5)); then
	MAX_MOVEMENTS=12
elif ((NUM_COUNT == 100)); then
	MAX_MOVEMENTS=700
elif ((NUM_COUNT == 500)); then
	MAX_MOVEMENTS=5500
fi

# Print movements done, optionally checking if max is satisfied
printf "\e[1;34mMovements\e[0;30m: "
if ((MAX_MOVEMENTS != 0)); then
	if ((MOVEMENTS <= MAX_MOVEMENTS)); then
		printf "\e[1;32mOK \e[1;30m[\e[1;33m$MOVEMENTS\e[1;30m/\e[1;39m$MAX_MOVEMENTS\e[1;30m]\e[0m\n"
	else
		printf "\e[1;31mKO \e[1;30m[\e[1;33m$MOVEMENTS\e[1;30m/\e[1;39m$MAX_MOVEMENTS\e[1;30m]\e[0m\n"
	fi
else
	printf "\e[1;33m$MOVEMENTS\e[0m\n"
fi
