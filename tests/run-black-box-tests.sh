#!/bin/bash

tests_run=0
tests_succeeded=0
tests_failed=0

examples_dir="examples"

files=`ls "$examples_dir/in"`

for file in $files;
do
    tests_run=$((tests_run+1))

    in_file="$examples_dir/in/$file"
    out_file="$examples_dir/out/$file"
    swap_file="$examples_dir/$file.swp"
    
    cat $in_file > $swap_file

    ../build/FileStringsSorting $swap_file

    if cmp -s $swap_file $out_file;
    then
        tests_succeeded=$((tests_succeeded+1))
    else
        tests_failed=$((tests_failed+1))
        echo "FAIL: $in_file"
    fi

    rm -rf $swap_file
done

err_files=`ls "$examples_dir/err_in"`

for file in $err_files;
do
    tests_run=$((tests_run+1))

    in_file="$examples_dir/err_in/$file"

    result=`../build/FileStringsSorting $file`
    if [[ $result == "Incorrect file" ]]
    then
        tests_succeeded=$((tests_succeeded+1))
    else
        tests_failed=$((tests_failed+1))
        echo "FAIL: $in_file"
    fi
done

echo "$tests_run tests run: $tests_succeeded succeeded, $tests_failed failed"
