# 42push_swap [![CodeFactor](https://www.codefactor.io/repository/github/xdec0de/42push_swap/badge)](https://www.codefactor.io/repository/github/xdec0de/42push_swap)
42 project "push_swap", code follows the norm used at 42.

## Testing the project

The `check.sh` script is provided to easily test push_swap with the
checker provided by 42 (**checker_linux**). This is **not** an actual tester,
but rather a tool generates a random string of non repeating numbers 
that is valid for push_swap to sort. **checker_linux** will then validate
if the output produced by push_swap is valid.

The script will only generate the numbers and execute the commands for you,
so you only have to execute it as follows: `./check.sh number_amount
max_number`. Arguments are optional, but this is what they do:
- number_amount: The amount of numbers to generate (Default: 10)
- max_number: The maximum number allowed on the random list (Default: 50000)

Lastly, the actual checker is and will not be provided on this repository.
You need to download it and put in on the root folder of the project for
this test script to work. The expected name is **checker_linux**. The reason
as of why the checker is not included is pretty obvious; it's not mine.
