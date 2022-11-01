#! /usr/bin/bash

read -p "Enter Date 1 :- " date1
read -p "Enter Date 2 :- " date2
today_date_year=`date "+%Y"`
today_date_month=`date "+%m"`
today_date_day=`date "+%d"`

#evaluating the first day
day=${date1%%/*} 
year=${date1##*/}
month=${date1#*/}
month=${month%/*}
_year_1=$(date --date="$month/$day/$year" '+%Y')

age_1=$(($today_date_year - $_year_1))

_dow1=$(date --date="$month/$day/$year" '+%A')

#evaluating the second day
day=${date2%%/*}
year=${date2##*/}
month=${date2#*/}
month=${month%/*}
_year_2=$(date --date="$month/$day/$year" '+%Y')

age_2=$(($today_date_year - $_year_2))

_dow2=$(date --date="$month/$day/$year" '+%A')

if [ $_dow1 == $_dow2 ]; then
	echo "Days are equal"
else
	echo "Days are not equal"
fi

echo "Age of first guy: $age_1"
echo "Age of second guy: $age_2"

