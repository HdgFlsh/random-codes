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
echo "${allmatch[*]}" | tr ' ' '\n'  | sort -  | uniq -c | awk "\$1==$#{print \$2}"