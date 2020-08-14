#!/bin/bash

g++ $1

if [[ $? = 0 ]]
then
	./a.out
fi
