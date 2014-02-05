#!/bin/bash 

#===============================================================================
#
#          FILE: insert.sh
# 
#         USAGE: ./insert.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: ---
#  ORGANIZATION: ---
#       CREATED: 02/05/2014 10:29
#      REVISION:  ---
#===============================================================================

# load array from file
filename="/home/username/unsorted.txt"

# change \n to space
array1=( `cat "$filename" | tr '\n' ' '`)

# set size of array
nElems=${#array1[@]}

#--------------------------------------------------------------

# print the contents of the array

display() {

	echo ${array1[@]}

} # end display

#--------------------------------------------------------------

# sort the contents of the array

insertSort() {

	for (( out=1; out<nElems; out++ ))

	do

		temp=${array1[out]}

		in=$out

		while [ $in -gt 0 ] && [ ${array1[in-1]} -ge $temp ]

		do
			array1[in]=${array1[in-1]}

			let in-=1

		done # end while

		array1[in]=$temp

	done # end for

} # end sort

#-------------------------------------------------------------

# search the array for $key

binarySearch() {

	read -p "Enter the element you want to search for: " key

	echo -e "\n"

	lower=0

	let upper=$nElems-1

	while [ $lower -le $upper ]

	do

		let num=$upper+$lower

		try=`echo "scale=0;$num/2" | bc`

		# if found
		if [ ${array1[try]} -eq $key ]; then

			echo "Found at position: $(( $try+1 ))"

			exit 0

		# if in upper
		elif [ ${array1[try]} -lt $key ]; then

			let lower=$try+1 

		# if in lower
		elif [ ${array1[try]} -gt $key ]; then

			let upper=$try-1

		fi # end if

	done # end while

	# not found
	if [ $lower -gt $upper ]; then

		echo "Item not found in array."

		echo -e "\n"

	fi # end if

} # end search

#-------------------------------------------------------------

# main program

echo -e "\n"

echo "size of array: " $nElems

echo -e "\n"

echo "unsorted array: "

echo -e "\n"

display

echo -e "\n"

echo "sorted array: "

echo -e "\n"

insertSort

display

echo -e "\n"

binarySearch
