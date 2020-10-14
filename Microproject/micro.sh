#!/bin/sh
RESULT="./Result.csv"
INPUT_DIR="/home/ltts/99002686/Microproject/Input.csv"
printf "Name,Email_ID,Repo_link,clone,build\n" > $RESULT
TEMPIFS=$IFS
IFS=','
[ ! -f $INPUT_DIR ] && { echo "$INPUT_DIR not found!"; exit 99; }

while read Name Email_ID Repo_link;
do
    [ $Name != "Name" ] && printf "$Name," >> $RESULT 
    [ $Email_ID != "Email_ID" ] && printf "$Email_ID," >> $RESULT 
    if [ $Repo_link != "Repo_link" ] && printf "$Repo_link," >> $RESULT; then
        name=$Name 
        mail=$Email_ID 
        link=$Repo_link 
    fi
done < $INPUT_DIR
IFS=$TEMPIFS


echo $link
git clone $link && echo $?
[[ $? == 0 ]] && printf "clone success" >> $RESULT
[[ $? < 0 ]]  &&  printf "clone Failed" >> $RESULT 

<<note
[$? == 0]  && echo clone success

echo "Build"
make


echo "CPPCHECK"
cd ..
grep ^Checking$ cppcheck linuxAssignment1 > Result.csv 
#grep ^Checking$ Result.csv > error.csv


echo "Valgrind"
cd linuxAssignment1
valgrind ./ALLFUN.out 
note