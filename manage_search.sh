#!/bin/sh
for i in "$@"
do
    z=$i
    z=${z:0:1}
    y="["
    if [ "$y" = "$z" ]
    then
        z=$i
        z=${z:1:-1}
        matchitem=$(grep -rn "\[$z\]" ./src --include \*.cpp | awk -F: 'BEGIN{ORS=" "}{print $1}')
    else
        matchitem=$(grep -rn "$i" ./src --include \*.cpp | awk -F: 'BEGIN{ORS=" "}{print $1}')
    fi
    for j in ${matchitem[@]}
    do
        allmatch[${#allmatch[*]}]=$j
    done
done
finalmatch=$(echo "${allmatch[*]}" | tr ' ' '\n'  | sort -  | uniq -c | awk "BEGIN{ORS=\" \"}\$1==$#{print \$2}" )
for i in ${finalmatch[@]}
do
    echo "$i"
    a=$(head -1 $i)
    a=${a:3}
    readarray -d / -t aa <<< "$a"
    for j in ${aa[@]}
    do
        echo " - $j"
    done
done