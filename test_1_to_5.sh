#!/bin/bash

limit_2=5
limit_3=5
limit_4=12
limit_5=12

green="\e[32m"
red="\e[31m"
reset="\e[0m"

combinations_2=(
	"0 1"
	"1 0"
)

combinations_3=(
	"0 1 2"
    "0 2 1"
    "1 0 2"
    "1 2 0"
    "2 0 1"
    "2 1 0"
)

combinations_4=(
    "0 1 2 3"
    "0 1 3 2"
    "0 2 1 3"
    "0 2 3 1"
    "0 3 1 2"
    "0 3 2 1"
    "1 0 2 3"
    "1 0 3 2"
    "1 2 0 3"
    "1 2 3 0"
    "1 3 0 2"
    "1 3 2 0"
    "2 0 1 3"
    "2 0 3 1"
    "2 1 0 3"
    "2 1 3 0"
    "2 3 0 1"
    "2 3 1 0"
    "3 0 1 2"
    "3 0 2 1"
    "3 1 0 2"
    "3 1 2 0"
    "3 2 0 1"
    "3 2 1 0"
)

combinations_5=(
    "0 1 2 3 4"
    "0 1 2 4 3"
    "0 1 3 2 4"
    "0 1 3 4 2"
    "0 1 4 2 3"
    "0 1 4 3 2"
    "0 2 1 3 4"
    "0 2 1 4 3"
    "0 2 3 1 4"
    "0 2 3 4 1"
    "0 2 4 1 3"
    "0 2 4 3 1"
    "0 3 1 2 4"
    "0 3 1 4 2"
    "0 3 2 1 4"
    "0 3 2 4 1"
    "0 3 4 1 2"
    "0 3 4 2 1"
    "0 4 1 2 3"
    "0 4 1 3 2"
    "0 4 2 1 3"
    "0 4 2 3 1"
    "0 4 3 1 2"
    "0 4 3 2 1"
    "1 0 2 3 4"
    "1 0 2 4 3"
    "1 0 3 2 4"
    "1 0 3 4 2"
    "1 0 4 2 3"
    "1 0 4 3 2"
    "1 2 0 3 4"
    "1 2 0 4 3"
    "1 2 3 0 4"
    "1 2 3 4 0"
    "1 2 4 0 3"
    "1 2 4 3 0"
    "1 3 0 2 4"
    "1 3 0 4 2"
    "1 3 2 0 4"
    "1 3 2 4 0"
    "1 3 4 0 2"
    "1 3 4 2 0"
    "1 4 0 2 3"
    "1 4 0 3 2"
    "1 4 2 0 3"
    "1 4 2 3 0"
    "1 4 3 0 2"
    "1 4 3 2 0"
    "2 0 1 3 4"
    "2 0 1 4 3"
    "2 0 3 1 4"
    "2 0 3 4 1"
    "2 0 4 1 3"
    "2 0 4 3 1"
    "2 1 0 3 4"
    "2 1 0 4 3"
    "2 1 3 0 4"
    "2 1 3 4 0"
    "2 1 4 0 3"
    "2 1 4 3 0"
    "2 3 0 1 4"
    "2 3 0 4 1"
    "2 3 1 0 4"
    "2 3 1 4 0"
    "2 3 4 0 1"
    "2 3 4 1 0"
    "2 4 0 1 3"
    "2 4 0 3 1"
    "2 4 1 0 3"
    "2 4 1 3 0"
    "2 4 3 0 1"
    "2 4 3 1 0"
    "3 0 1 2 4"
    "3 0 1 4 2"
    "3 0 2 1 4"
    "3 0 2 4 1"
    "3 0 4 1 2"
    "3 0 4 2 1"
    "3 1 0 2 4"
    "3 1 0 4 2"
    "3 1 2 0 4"
    "3 1 2 4 0"
    "3 1 4 0 2"
    "3 1 4 2 0"
    "3 2 0 1 4"
    "3 2 0 4 1"
    "3 2 1 0 4"
    "3 2 1 4 0"
    "3 2 4 0 1"
    "3 2 4 1 0"
    "3 4 0 1 2"
    "3 4 0 2 1"
    "3 4 1 0 2"
    "3 4 1 2 0"
    "3 4 2 0 1"
    "3 4 2 1 0"
    "4 0 1 2 3"
    "4 0 1 3 2"
    "4 0 2 1 3"
    "4 0 2 3 1"
    "4 0 3 1 2"
    "4 0 3 2 1"
    "4 1 0 2 3"
    "4 1 0 3 2"
    "4 1 2 0 3"
    "4 1 2 3 0"
    "4 1 3 0 2"
    "4 1 3 2 0"
    "4 2 0 1 3"
    "4 2 0 3 1"
    "4 2 1 0 3"
    "4 2 1 3 0"
    "4 2 3 0 1"
    "4 2 3 1 0"
    "4 3 0 1 2"
    "4 3 0 2 1"
    "4 3 1 0 2"
    "4 3 1 2 0"
    "4 3 2 0 1"
    "4 3 2 1 0"
)

echo -e "\ntest 2 digits | limit: $limit_2\n-------------------------------------"
for comb in "${combinations_2[@]}"; do
    result=$(./push_swap $comb | wc -l)
	output=$(./push_swap $comb | ./checker_linux $comb)
		if [[ $result -le $limit_2 ]]; then
			echo -ne "${green}$comb -> $result${reset}"
		else
			echo -ne "${red}$comb -> $result${reset}"
		fi
		if [[ $output == "OK" ]]; then
			echo -e " | checker: ${green}OK${reset}"
		else
			echo -e " | checker: ${red}KO${reset}"
		fi
    
done

echo -e "\ntest 3 digits | limit: $limit_3\n-------------------------------------"
for comb in "${combinations_3[@]}"; do
    result=$(./push_swap $comb | wc -l)
	output=$(./push_swap $comb | ./checker_linux $comb)
		if [[ $result -le $limit_3 ]]; then
			echo -ne "${green}$comb -> $result${reset}"
		else
			echo -ne "${red}$comb -> $result${reset}"
		fi
		if [[ $output == "OK" ]]; then
			echo -e " | checker: ${green}OK${reset}"
		else
			echo -e " | checker: ${red}KO${reset}"
		fi
    
done

echo -e "\ntest 4 digits | limit: $limit_4\n-------------------------------------"
for comb in "${combinations_4[@]}"; do
    result=$(./push_swap $comb | wc -l)
	output=$(./push_swap $comb | ./checker_linux $comb)
		if [[ $result -le $limit_4 ]]; then
			echo -ne "${green}$comb -> $result${reset}"
		else
			echo -ne "${red}$comb -> $result${reset}"
		fi
		if [[ $output == "OK" ]]; then
			echo -e " | checker: ${green}OK${reset}"
		else
			echo -e " | checker: ${red}KO${reset}"
		fi
    
done

echo -e "\ntest 5 digits | limit: $limit_5\n-------------------------------------"
for comb in "${combinations_5[@]}"; do
    result=$(./push_swap $comb | wc -l)
	output=$(./push_swap $comb | ./checker_linux $comb)
		if [[ $result -le $limit_5 ]]; then
			echo -ne "${green}$comb -> $result${reset}"
		else
			echo -ne "${red}$comb -> $result${reset}"
		fi
		if [[ $output == "OK" ]]; then
			echo -e " | checker: ${green}OK${reset}"
		else
			echo -e " | checker: ${red}KO${reset}"
			echo -e $(./push_swap $comb)
		fi
    
done
#echo -e "\ntest 2 digits | limit: $limit_2\n-------------------------------------"
#for comb in "${combinations_2[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -le $limit_2 ]]; then
#        echo -e "${green}$comb -> $result${reset}"
#		
#    fi
#done
#echo -e "\ntest 3 digits | limit: $limit_3\n-------------------------------------"
#for comb in "${combinations_3[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -le $limit_3 ]]; then
#        echo -e "${green}$comb -> $result${reset}"
#    fi
#done
#echo -e "\ntest 4 digits | limit: $limit_4\n-------------------------------------"
#for comb in "${combinations_4[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -le $limit_4 ]]; then
#        echo -e "${green}$comb -> $result${reset}"
#    fi
#done
#echo -e "\ntest 5 digits | limit: $limit_5\n-------------------------------------"
#for comb in "${combinations_5[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -le $limit_5 ]]; then
#		output=$(./push_swap $comb | ./checker_linux $comb)
#		if [[ $output == "OK" ]]; then
#    	    echo -ne "${green}$comb -> $result${reset}"
#			echo -e " | checker: ${green}OK${reset}"
#		fi
#    fi
#done
#
#echo ""
#echo -e "${red}=========\n   KO\n=========\n${reset}"
#echo -e "\ntest 2 digits | limit: $limit_2\n-------------------------------------"
#for comb in "${combinations_2[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -gt $limit_2 ]]; then
#        echo -e "${red}$comb -> $result${reset}"
#    fi
#done
#echo -e "\ntest 3 digits | limit: $limit_3\n-------------------------------------"
#for comb in "${combinations_3[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -gt $limit_3 ]]; then
#        echo -e "${red}$comb -> $result${reset}"
#    fi
#done
#echo -e "\ntest 4 digits | limit: $limit_4\n-------------------------------------"
#for comb in "${combinations_4[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#    if [[ $result -gt $limit_4 ]]; then
#        echo -e "${red}$comb -> $result${reset}"
#    fi
#done
#echo -e "\ntest 5 digits | limit: $limit_5\n-------------------------------------"
#for comb in "${combinations_5[@]}"; do
#    result=$(./push_swap $comb | wc -l)
#	output=$(./push_swap $comb | ./checker_linux $comb)
#		if [[ $result -le $limit_5 ]]; then
#			echo -ne "${green}$comb -> $result${reset}"
#		else
#			echo -ne "${red}$comb -> $result${reset}"
#		fi
#		if [[ $output == "OK" ]]; then
#			echo -e " | checker: ${green}OK${reset}"
#		else
#			echo -e " | checker: ${red}KO${reset}"
#		fi
#    
#done
