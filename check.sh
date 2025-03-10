# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniema3 <daniema3@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 20:02:31 by daniema3          #+#    #+#              #
#    Updated: 2025/03/10 16:08:01 by daniema3         ###   ########.fr        #
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

echo "Numbers: $ARG"
echo "Made $MOVEMENTS movement(s) to sort $NUM_COUNT numbers"
echo "Checker result: $CHECKER_RESULT"

# Generate files for the online visualizator
mkdir -p check
echo "$ARG" > check/numbers
echo "$OPERATIONS" > check/operations

# Check movement amount if number count is 100 (Subject requirements)
if ((NUM_COUNT == 100)); then
	if ((MOVEMENTS > 700)); then
		echo "Movement amount: KO"
	else
		echo "Movement amount: OK"
	fi
fi

# Check movement amount if number count is 500 (Subject requirements)
if ((NUM_COUNT == 500)); then
	if ((MOVEMENTS > 5500)); then
		echo "Movement amount: KO"
	else
		echo "Movement amount: OK"
	fi
fi
