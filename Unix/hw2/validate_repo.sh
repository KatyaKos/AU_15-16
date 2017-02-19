#! /bin/bash

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

if git checkout unix/hw2 &>/dev/null
then
    printf "Branch 'unix/hw2' is found\n"
else
    printf "Branch 'unix/hw2' is not found\n"
fi

check_task() {
    solution_file="unix/hw2/$1/$1.sh"
    if [ -f "$solution_file" ]
    then
        printf "Task $1 is found\n"
    else
        printf "Task $1 is not found\n"
    fi
}

for t in $(seq 5)
do
    check_task "$t"
done
