#!/bin/bash

while export ARG=$(./push_swap_checker/random_numbers 5 -10 100) && ./push_swap $ARG | ./push_swap_checker/checker_Mac $ARG | grep "OK"; do ;export | grep "ARG"; done
