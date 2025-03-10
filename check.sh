# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 20:02:31 by daniema3          #+#    #+#              #
#    Updated: 2025/03/10 16:54:17 by daniema3         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

ARG=$(IFS=" "; echo "${numbers[*]}")
OPERATIONS=$(./push_swap $ARG 2>/dev/null)
MOVEMENTS=$(echo "$OPERATIONS" | wc -l)
CHECKER_RESULT=$(echo "$OPERATIONS" | ./checker_linux $ARG)

printf "\e[1;34mNumber amount\e[0;30m: \e[1;35m$NUM_COUNT\e[0m\n"

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

MAX_MOVEMENTS=0

if ((NUM_COUNT == 100)); then
	MAX_MOVEMENTS=700
elif ((NUM_COUNT == 500)); then
	MAX_MOVEMENTS=5500
fi

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
