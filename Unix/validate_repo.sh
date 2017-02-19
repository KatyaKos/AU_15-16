#! /bin/bash

BRANCH_NAME='unix/cw1'
DIR_NAME='unix/cw1'
NUMBER_OF_TASKS=15

if [ "$#" != 1 ]
then
    printf "Usage: $0 REPO\n"
    exit 1
fi

cd -- "$1" || exit 1

if [ ! -d .git ]
then
    printf ".git directory is not found\n"
fi

if git checkout "$BRANCH_NAME" &>/dev/null && \
        [[ "$(git rev-parse --abbrev-ref HEAD)" == "$BRANCH_NAME" ]]
then
    printf "Branch '$BRANCH_NAME' is found\n"
else
    printf "Branch '$BRANCH_NAME' is not found\n"
fi

if [ -d "$DIR_NAME" ]
then
    printf "Directory '$DIR_NAME' is found\n"
else
    printf "Directory '$DIR_NAME' is not found\n"
fi

check_task() {
    solution_file="$DIR_NAME/$1/$1.sh"
    if [ -f "$solution_file" ]
    then
        printf "Task $1 is found\n"
    else
        printf "Task $1 is not found\n"
    fi
}

for t in $(seq $NUMBER_OF_TASKS)
do
    check_task "$t"
done
